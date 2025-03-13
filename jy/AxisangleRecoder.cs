using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public class AxisangleRecoder : MonoBehaviour
{
    public Transform[] targetObjects; // 저장할 오브젝트 배열
    private List<string> logData = new List<string>(); // 로그 데이터 저장 리스트
    private bool isRecording = false;
    private float startTime;

    void Start()
    {
        // CSV 헤더 만들기 (Frame, Time, 오브젝트별 Exponential Map 값)
        string header = "Frame,Time";

        // 먼저 rotation 데이터를 저장
        foreach (Transform obj in targetObjects)
        {
            header += $",{obj.name}_wx,{obj.name}_wy,{obj.name}_wz"; // Exponential Map (Axis * Angle)
        }

        // 그 다음에 position 데이터를 저장
        foreach (Transform obj in targetObjects)
        {
            header += $",{obj.name}_px,{obj.name}_py,{obj.name}_pz"; // Position
        }

        logData.Add(header);
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.A))
        {
            isRecording = true;
            startTime = Time.time;
            logData.Clear();
            string header = "Frame,Time";

            // 먼저 rotation 데이터를 저장
            foreach (Transform obj in targetObjects)
            {
                header += $",{obj.name}_wx,{obj.name}_wy,{obj.name}_wz";
            }

            // 그 다음에 position 데이터를 저장
            foreach (Transform obj in targetObjects)
            {
                header += $",{obj.name}_px,{obj.name}_py,{obj.name}_pz";
            }
            logData.Add(header);
            Debug.Log("🎥 Exponential Map 저장 시작!");
        }

        if (Input.GetKeyDown(KeyCode.Z) && isRecording)
        {
            isRecording = false;
            SaveToCSV();
            Debug.Log("✅ Exponential Map 저장 완료!");
        }

        if (isRecording)
        {
            RecordExponentialMapData();
        }
    }

    void RecordExponentialMapData()
    {
        float currentTime = Time.time - startTime;
        int currentFrame = Time.frameCount;

        string logEntry = $"{currentFrame},{currentTime:F6}";

        // 먼저 rotation 데이터를 저장
        foreach (Transform obj in targetObjects)
        {
            if (obj != null)
            {
                Quaternion rot = obj.rotation;
                float angle = 2.0f * Mathf.Acos(rot.w); // Radian 단위
                float sinHalfAngle = Mathf.Sin(angle / 2.0f);

                Vector3 axis = (sinHalfAngle > 0.0001f) ? new Vector3(rot.x / sinHalfAngle, rot.y / sinHalfAngle, rot.z / sinHalfAngle) : Vector3.zero;
                Vector3 expMap = axis * angle; // Exponential Map 변환

                logEntry += $",{expMap.x:F6},{expMap.y:F6},{expMap.z:F6}";
            }
            else
            {
                logEntry += ",0,0,0"; // 기본값
            }
        }

        // 그 다음에 position 데이터를 저장
        foreach (Transform obj in targetObjects)
        {
            if (obj != null)
            {   
                Vector3 pos = obj.position;
                logEntry += $",{pos.x:F6},{pos.y:F6},{pos.z:F6}";
            }
            else
            {
                logEntry += ",0,0,0"; // 기본값
            }
        }

        logData.Add(logEntry);
    }

    void SaveToCSV()
    {
        string fileName = "ExponentialMapData_" + DateTime.Now.ToString("yyyy-MM-dd_HH-mm-ss") + ".csv";
        string filePath = Path.Combine(Application.persistentDataPath, fileName);
        File.WriteAllLines(filePath, logData);
        Debug.Log($"✅ Exponential Map data saved to: {filePath}");
    }
}