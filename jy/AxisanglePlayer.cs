using System.Collections;
using System.Collections.Generic;
using System.ComponentModel.Design.Serialization;
using System.IO;
using UnityEngine;
using TMPro;
using UnityEngine.SocialPlatforms.Impl;

public class AxisanglePlayer : MonoBehaviour
{
    public Transform[] targetObjects;
    public string rootpath;
    public string fileName;
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
        if (isCsvMode == true)
        {
            LoadCSV();
        }

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
            if (i * 3 + 2 < frameData.Length && targetObjects[i] != null)
            {
                float wx = float.Parse(frameData[i * 3 + 2]);
                float wy = float.Parse(frameData[i * 3 + 3]);
                float wz = float.Parse(frameData[i * 3 + 4]);

                Vector3 expMap = new Vector3(wx, wy, wz);
                float angle = expMap.magnitude; // 회전 크기
                Vector3 axis = angle > 0 ? expMap / angle : Vector3.zero;

                float sinHalfAngle = Mathf.Sin(angle / 2.0f);
                float cosHalfAngle = Mathf.Cos(angle / 2.0f);

                Quaternion q = new Quaternion(axis.x * sinHalfAngle, axis.y * sinHalfAngle, axis.z * sinHalfAngle, cosHalfAngle);
                targetObjects[i].rotation = q;
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
            if (i < frameData.Count && targetObjects[i] != null)
            {
                Vector3 expMap = frameData[i];
                float angle = expMap.magnitude;
                Vector3 axis = angle > 0 ? expMap / angle : Vector3.zero;

                float sinHalfAngle = Mathf.Sin(angle / 2.0f);
                float cosHalfAngle = Mathf.Cos(angle / 2.0f);

                Quaternion q = new Quaternion(axis.x * sinHalfAngle, axis.y * sinHalfAngle, axis.z * sinHalfAngle, cosHalfAngle);
                targetObjects[i].rotation = q;
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

