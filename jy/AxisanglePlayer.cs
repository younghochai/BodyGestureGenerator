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

    private bool isInitPelvisSet = false;

    private float initPelvisY;

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
                    ApplyExponentialMapDataT(recordedFrames[fixedFrame], jointPositions[fixedFrame]); // 최신 값 반영
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

    IEnumerator PlayExponentialMapDataT()
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
        currentFrameIndex = Pstartframe;

        while (currentFrameIndex < Pendframe)
        {
            float elapsedTime = (Time.time - startTime) * playbackSpeed;

            while (currentFrameIndex < recordedFrames.Count &&
                   float.Parse(recordedFrames[currentFrameIndex][1]) <= elapsedTime)
            {
                // ✅ 회전 데이터는 jointPositions에서 가져옴
                if (currentFrameIndex < jointPositions.Count)
                {
                    ApplyExponentialMapDataT(recordedFrames[currentFrameIndex], jointPositions[currentFrameIndex]);
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

            string jointName = targetObjects[i].name.ToLower();

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

            // 🔹 position (px, py, pz) 컬럼은 pelvis(joint 0)만 반영
            if (i == 0)
            {
                int pxIndex = System.Array.IndexOf(headers, $"{jointName}_px");
                int pyIndex = System.Array.IndexOf(headers, $"{jointName}_py");
                int pzIndex = System.Array.IndexOf(headers, $"{jointName}_pz");

                if (i == 0 && !isInitPelvisSet)
                {
                    initPelvisY = float.Parse(frameData[pyIndex]);
                    isInitPelvisSet = true;
                    Debug.Log("Initial pelvis Y: " + initPelvisY);

                }

                if (pxIndex >= 0 && pyIndex >= 0 && pzIndex >= 0 && pxIndex < frameData.Length)
                {
                    // 오프셋을 빼서 적용 (다른 joint는 그대로 적용되어야 한다면 조건문 추가)
                    float newY = float.Parse(frameData[pyIndex]);
                    if (i == 0)
                        newY = newY - initPelvisY;

                    targetObjects[i].position = new Vector3(
                        float.Parse(frameData[pxIndex]),
                        newY,
                        float.Parse(frameData[pzIndex])
                    );
                }
                else
                {
                    Debug.LogWarning($"⚠️ {jointName}의 position 데이터를 찾을 수 없음.");
                }
            }
            // pelvis가 아닌 다른 joint는 position을 업데이트하지 않음
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

            // ✅ position (px, py, pz) CSV에서 가져오기
            if (i == 0)
            {
                int pxIndex = System.Array.IndexOf(headers, $"{jointName}_px");
                int pyIndex = System.Array.IndexOf(headers, $"{jointName}_py");
                int pzIndex = System.Array.IndexOf(headers, $"{jointName}_pz");

                if (i == 0 && !isInitPelvisSet)
                {
                    initPelvisY = float.Parse(frameData2[pyIndex]);
                    isInitPelvisSet = true;
                    Debug.Log("Initial pelvis Y: " + initPelvisY);

                }

                if (pxIndex >= 0 && pyIndex >= 0 && pzIndex >= 0 && pxIndex < frameData2.Length)
                {
                    // 오프셋을 빼서 적용 (다른 joint는 그대로 적용되어야 한다면 조건문 추가)
                    float newY = float.Parse(frameData2[pyIndex]);
                    if (i == 0)
                        newY = newY - initPelvisY;

                    targetObjects[i].position = new Vector3(
                        float.Parse(frameData2[pxIndex]),
                        newY,
                        float.Parse(frameData2[pzIndex])
                    );
                }
                else
                {
                    Debug.LogWarning($"⚠️ {jointName}의 position 데이터를 찾을 수 없음.");
                }
            }
        }
    }



    void ApplyExponentialMapDataT(string[] frameData2, List<Vector3> frameData)
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

            // ✅ position (px, py, pz) CSV에서 가져오기
            if (i == 0)
            {
                int pxIndex = System.Array.IndexOf(headers, $"{jointName}_px");
                int pyIndex = System.Array.IndexOf(headers, $"{jointName}_py");
                int pzIndex = System.Array.IndexOf(headers, $"{jointName}_pz");

                if (i == 0 && !isInitPelvisSet)
                {
                    initPelvisY = float.Parse(frameData2[pyIndex]);
                    isInitPelvisSet = true;
                    Debug.Log("Initial pelvis Y: " + initPelvisY);

                }

                if (pxIndex >= 0 && pyIndex >= 0 && pzIndex >= 0 && pxIndex < frameData2.Length)
                {
                    // 오프셋을 빼서 적용 (다른 joint는 그대로 적용되어야 한다면 조건문 추가)
                    float newY = float.Parse(frameData2[pyIndex]);
                    if (i == 0)
                        newY = newY - initPelvisY;

                    targetObjects[i].position = new Vector3(
                        float.Parse(frameData2[pxIndex]),
                        newY,
                        float.Parse(frameData2[pzIndex])
                    );
                }
                else
                {
                    Debug.LogWarning($"⚠️ {jointName}의 position 데이터를 찾을 수 없음.");
                }
            }
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

