using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public class AxisanglePlayer : MonoBehaviour
{
    public Transform[] targetObjects;
    public string fileName = "ExponentialMapData.csv"; // 파일 이름
    public float playbackSpeed = 1.0f;

    private List<string[]> recordedFrames = new List<string[]>();
    private string[] headers;
    private bool isPlaying = false;
    private int currentFrameIndex = 1;
    private float startTime;

    void Start()
    {
        LoadCSV();
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.R) && !isPlaying)
        {
            StartCoroutine(PlayExponentialMapData());
        }
    }

    void LoadCSV()
    {
        string filePath = Path.Combine(Application.persistentDataPath, fileName);

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
            float elapsedTime = (Time.time - startTime) * playbackSpeed;

            while (currentFrameIndex < recordedFrames.Count && float.Parse(recordedFrames[currentFrameIndex][1]) <= elapsedTime)
            {
                ApplyExponentialMapData(recordedFrames[currentFrameIndex]);
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
}