using System.Collections;
using System.Collections.Generic;
using System.ComponentModel.Design.Serialization;
using System.IO;
using UnityEngine;
using TMPro;
using UnityEngine.SocialPlatforms.Impl;
using UnityEngine.Playables;

public class AxisanglePlayer : MonoBehaviour
{
    public Transform[] targetObjects;
    public string rootpath = "C:/Users/USER/Desktop/SMPLX/SMPLX/Assets/SMPLX/Scripts/ExponentialMapData.csv";
    public string fileName = "ExponentialMapData.csv"; // 파일 이름
    public JointAngleController jointAngleController;
    public float playbackSpeed = 1.0f;
    public bool isCsvMode = false;
    public int fixedFrame = -1;
    public TextMeshProUGUI frameText;
    public int Pstartframe;
    public int Pendframe;

    private List<List<Vector3>> jointPositions;

    private List<string[]> recordedFrames = new List<string[]>();
    private string[] headers;
    private bool isPlaying = false;
    private int currentFrameIndex = 1;
    private float startTime;

    void Start()
    {
        LoadCSV();
        

        if (Input.GetKeyDown(KeyCode.T))
        {
            if (jointAngleController != null)
            {
                StartCoroutine(PlayExponentialMapData());
            }
            else
            {
                Debug.LogError("❌ JointAngleController를 찾을 수 없습니다.");
            }
        }

        FixedUpdate();
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.R) && !isPlaying)
        {
            StartCoroutine(PlayExponentialMapData());
        }

        if (Input.GetKeyDown(KeyCode.T) && !isPlaying)
        {
            if (jointAngleController != null)
            {
                fixedFrame = -1; // 고정된 프레임 해제
                StartCoroutine(PlayExponentialMapDataT());
            }
            else
            {
                Debug.LogError("❌ JointAngleController를 찾을 수 없습니다.");
            }
        }

        if (Input.GetKeyDown(KeyCode.F)) // 특정 프레임 고정
        {
            if (jointAngleController != null)
            {
                List<List<Vector3>> jointPositions = jointAngleController.GetJointPositions();
                if (fixedFrame >= 0 && fixedFrame < jointPositions.Count)
                {
                    ApplyExponentialMapDataT(jointAngleController.GetJointPositions()[fixedFrame]); // 최신 값 반영
                    Debug.Log($"🔒 Frame {fixedFrame}으로 고정됨 (최신 데이터 반영)");
                }
                else
                {
                    Debug.LogWarning("⚠️ 유효하지 않은 프레임 값");
                }
            }
        }

        if (fixedFrame >= 0)
            PlotFixedFrameMarker(fixedFrame); // mark fixedFrame on the chart

        if (Input.GetKeyDown(KeyCode.Y) && !isPlaying)
        {
            if (jointAngleController != null)
            {
                fixedFrame = -1; // 고정된 프레임 해제
                StartCoroutine(PlayExponentialMapDataY());
            }
            else
            {
                Debug.LogError("❌ JointAngleController를 찾을 수 없습니다.");
            }
        }

    }

    private void FixedUpdate()
    {
        frameText.text = "NOW PLAYING: " + currentFrameIndex.ToString();
    }


    void LoadCSV()
    {
        string filePath = Path.Combine(rootpath, fileName);

        if (!File.Exists(filePath))
        {
            Debug.LogError($"❌ CSV 파일을 찾을 수 없음: {filePath}");
            return;
        }

        string[] lines = File.ReadAllLines(filePath);
        if (lines.Length < 2) return;

        headers = lines[0].Split(',');
        for (int i = 1; i < lines.Length; i++)
        {
            recordedFrames.Add(lines[i].Split(','));
        }

        //Debug.Log($"✅ CSV 데이터 로드 완료: {recordedFrames.Count} 프레임");
    }

    IEnumerator PlayExponentialMapDataY()
    {
        if (recordedFrames.Count == 0)
        {
            Debug.LogError("❌ 저장된 데이터가 없습니다.");
            yield break;
        }

        // ✅ jointPositions을 최신 데이터로 가져오기
        jointPositions = jointAngleController.GetJointPositions();
        if (jointPositions == null || jointPositions.Count == 0)
        {
            Debug.LogError("❌ jointPositions 데이터가 없습니다.");
            yield break;
        }

        isPlaying = true;
        startTime = Time.time;
        currentFrameIndex = 0;

        while (currentFrameIndex < recordedFrames.Count)
        {
            float elapsedTime = (Time.time - startTime) * playbackSpeed;

            while (currentFrameIndex < recordedFrames.Count &&
                   float.Parse(recordedFrames[currentFrameIndex][1]) <= elapsedTime)
            {
                // ✅ 회전 데이터는 jointPositions에서 가져옴
                if (currentFrameIndex < jointPositions.Count)
                {
                    ApplyExponentialMapDataY(recordedFrames[currentFrameIndex], jointPositions[currentFrameIndex]);
                }
                else
                {
                    Debug.LogWarning($"⚠️ jointPositions 데이터 부족: {currentFrameIndex}/{jointPositions.Count}");
                }

                currentFrameIndex++;
            }

            yield return null;
        }

        Debug.Log("⏹ 재생 완료!");
        isPlaying = false;
    }


    IEnumerator PlayExponentialMapData()
    {
        if (recordedFrames.Count == 0)
        {
            Debug.LogError("❌ 저장된 데이터가 없습니다.");
            yield break;
        }

        isPlaying = true;
        startTime = Time.time;
        currentFrameIndex = 0;

        while (currentFrameIndex < recordedFrames.Count)
        {
            Debug.Log(currentFrameIndex);
            float elapsedTime = (Time.time - startTime) * playbackSpeed;

            while (currentFrameIndex < recordedFrames.Count && float.Parse(recordedFrames[currentFrameIndex][1]) <= elapsedTime)
            {
                ApplyExponentialMapData(recordedFrames[currentFrameIndex]);
                Debug.Log(currentFrameIndex);
                currentFrameIndex++;
            }

            yield return null;
        }

        Debug.Log("⏹ 재생 완료!");
        isPlaying = false;
    }

    void ApplyExponentialMapData(string[] frameData)
    {
        for (int i = 0; i < targetObjects.Length; i++)
        {
            if (targetObjects[i] == null) continue;

            string jointName = targetObjects[i].name.ToLower(); // 오브젝트 이름을 소문자로 변환

            // 🔹 rotation (wx, wy, wz) 컬럼 찾기
            int wxIndex = System.Array.IndexOf(headers, $"{jointName}_wx");
            int wyIndex = System.Array.IndexOf(headers, $"{jointName}_wy");
            int wzIndex = System.Array.IndexOf(headers, $"{jointName}_wz");

            if (wxIndex >= 0 && wyIndex >= 0 && wzIndex >= 0 && wxIndex < frameData.Length)
            {
                float wx = float.Parse(frameData[wxIndex]);
                float wy = float.Parse(frameData[wyIndex]);
                float wz = float.Parse(frameData[wzIndex]);

                Vector3 expMap = new Vector3(wx, wy, wz);
                float angle = expMap.magnitude;
                Vector3 axis = angle > 0 ? expMap / angle : Vector3.zero;

                float sinHalfAngle = Mathf.Sin(angle / 2.0f);
                float cosHalfAngle = Mathf.Cos(angle / 2.0f);

                Quaternion q = new Quaternion(axis.x * sinHalfAngle, axis.y * sinHalfAngle, axis.z * sinHalfAngle, cosHalfAngle);
                targetObjects[i].rotation = q;
            }
            else
            {
                Debug.LogWarning($"⚠️ {jointName}의 rotation 데이터를 찾을 수 없음.");
            }

            if (jointName != "pelvis") continue; // ✅ pelvis가 아니면 position 업데이트 건너뛰기

            // 🔹 position (px, py, pz) 컬럼 찾기
            int pxIndex = System.Array.IndexOf(headers, $"{jointName}_px");
            int pyIndex = System.Array.IndexOf(headers, $"{jointName}_py");
            int pzIndex = System.Array.IndexOf(headers, $"{jointName}_pz");

            if (pxIndex >= 0 && pyIndex >= 0 && pzIndex >= 0 && pxIndex < frameData.Length)
            {
                targetObjects[i].position = new Vector3(float.Parse(frameData[pxIndex]),
                                                        float.Parse(frameData[pyIndex]),
                                                        float.Parse(frameData[pzIndex]));
            }
            else
            {
                Debug.LogWarning($"⚠️ {jointName}의 position 데이터를 찾을 수 없음.");
            }
        }
    }

    void ApplyExponentialMapDataY(string[] frameData2, List<Vector3> frameData)
    {
        for (int i = 0; i < targetObjects.Length; i++)
        {
            if (targetObjects[i] == null) continue;
            if (i >= frameData.Count) continue; // ✅ frameData가 부족하면 넘어가기

            string jointName = targetObjects[i].name.ToLower();

            // ✅ rotation (wx, wy, wz) 적용
            Vector3 expMap = frameData[i];
            float angle = expMap.magnitude;
            Vector3 axis = angle > 0 ? expMap / angle : Vector3.zero;

            float sinHalfAngle = Mathf.Sin(angle / 2.0f);
            float cosHalfAngle = Mathf.Cos(angle / 2.0f);

            Quaternion q = new Quaternion(axis.x * sinHalfAngle, axis.y * sinHalfAngle, axis.z * sinHalfAngle, cosHalfAngle);
            targetObjects[i].rotation = q;

            if (jointName != "pelvis") continue; // ✅ pelvis가 아니면 position 업데이트 건너뛰기
            
            // ✅ position (px, py, pz) CSV에서 가져오기
            int pxIndex = System.Array.IndexOf(headers, $"{jointName}_px");
            int pyIndex = System.Array.IndexOf(headers, $"{jointName}_py");
            int pzIndex = System.Array.IndexOf(headers, $"{jointName}_pz");

            if (pxIndex >= 0 && pyIndex >= 0 && pzIndex >= 0 && pxIndex < frameData2.Length)
            {
                targetObjects[i].position = new Vector3(float.Parse(frameData2[pxIndex]),
                                                        float.Parse(frameData2[pyIndex]),
                                                        float.Parse(frameData2[pzIndex]));
            }
            else
            {
                Debug.LogWarning($"⚠️ {jointName}의 position 데이터를 찾을 수 없음.");
            }
        }
    }


    IEnumerator PlayExponentialMapDataT()
    {
        List<List<Vector3>> jointPositions = jointAngleController.GetJointPositions(); // 최신 데이터 가져오기

        if (jointPositions == null || jointPositions.Count == 0)
        {
            Debug.LogError("❌ 저장된 데이터가 없습니다.");
            yield break;
        }

        isPlaying = true;
        startTime = Time.time;
        currentFrameIndex = Pstartframe;

        float frameDuration = 0.066f; // 기본적으로 15 FPS (1초 / 15프레임)
        float accumulatedTime = 0f;   // 경과한 시간을 누적하여 관리

        while (currentFrameIndex < Pendframe)
        {
            if (fixedFrame == -1)
            {
                // ✅ 실제 경과 시간에 배속을 적용하여 누적
                accumulatedTime += Time.deltaTime * playbackSpeed;

                // ✅ 경과 시간이 프레임 지속 시간보다 길면 여러 프레임을 한 번에 실행
                while (accumulatedTime >= frameDuration)
                {
                    ApplyExponentialMapDataT(jointPositions[currentFrameIndex]);
                    currentFrameIndex++;
                    accumulatedTime -= frameDuration; // ✅ 실행한 프레임의 시간만큼 차감

                    if (currentFrameIndex >= Pendframe) // 프레임 끝나면 종료
                    {
                        break;
                    }
                }
            }
            else
            {
                ApplyExponentialMapDataT(jointAngleController.GetJointPositions()[fixedFrame]); // 최신 값 반영
            }

            yield return null; // ✅ 매 프레임마다 실행 (FPS 제한 없음)
        }

        Debug.Log("⏹ 재생 완료!");
        isPlaying = false;
    }
    void ApplyExponentialMapDataT(List<Vector3> frameData)
    {
        for (int i = 0; i < targetObjects.Length; i++)
        {
            if (targetObjects[i] == null || i >= frameData.Count) continue;

            string jointName = targetObjects[i].name.ToLower();

            // 🔹 rotation (wx, wy, wz) 적용
            Vector3 expMap = frameData[i];
            float angle = expMap.magnitude;
            Vector3 axis = angle > 0 ? expMap / angle : Vector3.zero;

            float sinHalfAngle = Mathf.Sin(angle / 2.0f);
            float cosHalfAngle = Mathf.Cos(angle / 2.0f);

            Quaternion q = new Quaternion(axis.x * sinHalfAngle, axis.y * sinHalfAngle, axis.z * sinHalfAngle, cosHalfAngle);
            targetObjects[i].rotation = q;
        }
    }

    /// <summary>
    /// Plot the fixed frame marker on the chart
    /// </summary>
    private void PlotFixedFrameMarker(int markerFrame)
    {
        if (jointAngleController == null || jointAngleController.chart == null)
        {
            Debug.LogWarning("Chart reference not set in JointAngleController!");
            return;
        }

        // Using the same pattern as PlotVerticalMarker in JointAngleController
        jointAngleController.chart.DataSource.StartBatch();
        jointAngleController.chart.DataSource.ClearCategory("FixedFrameMarker");
        jointAngleController.chart.DataSource.AddPointToCategory("FixedFrameMarker", markerFrame, -10);
        jointAngleController.chart.DataSource.AddPointToCategory("FixedFrameMarker", markerFrame, 10);
        jointAngleController.chart.DataSource.EndBatch();
    }
}