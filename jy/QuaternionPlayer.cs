using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using TMPro;
using SimpleJSON; // SimpleJSON 패키지가 프로젝트에 추가되어 있어야 합니다.

public class QuaternionPlayer : MonoBehaviour
{
    [Header("Target Joint Transforms (총 24개)")]
    public Transform[] targetObjects;

    [Header("JSON File Settings")]
    public string rootPath = "C:/Users/USER/Desktop/SMPLX/SMPLX/Assets/SMPLX/Scripts";
    public string jsonFileName = "0_a_person_kicks_with_his_right_leg_L200.json";

    [Header("Playback Settings")]
    public float playbackSpeed = 1.0f; // 속도 조절 (기본 1.0, 30fps 기준)
    public TextMeshProUGUI frameText;
    
    // JSON 기본 데이터 (추후 참고용)
    private string label;
    private string quaternionOrder;
    private float guidanceScale;

    // 파싱한 쿼터니언 프레임 데이터.
    // 각 프레임은 key가 "00", "01", ... "23" 인 24개 관절의 쿼터니언 float[4] 배열을 갖는 Dictionary입니다.
    private List<Dictionary<string, float[]>> smplQuatFrames = new List<Dictionary<string, float[]>>();

    private bool isPlaying = false;
    private int currentFrameIndex = 0;
    private float startTime;
    private int totalFrames = 0;

    void Start()
    {
        LoadQuaternionJSON();
    }

    void Update()
    {
        // Q 키를 눌러 재생 시작
        if (Input.GetKeyDown(KeyCode.Q) && !isPlaying)
        {
            StartCoroutine(PlayQuaternionData());
        }
    }

    void FixedUpdate()
    {
        if (frameText != null)
        {
            frameText.text = "NOW PLAYING: " + currentFrameIndex.ToString();
        }
    }

    // JSON 파일에서 SMPL 쿼터니언 데이터를 로드합니다.
    // rotation_quat은 각 프레임마다 "00","01",... "23" 키를 가진 Dictionary 형식입니다.
    void LoadQuaternionJSON()
    {
        string filePath = Path.Combine(rootPath, jsonFileName);
        if (!File.Exists(filePath))
        {
            Debug.LogError($"❌ JSON 파일을 찾을 수 없음: {filePath}");
            return;
        }

        string jsonString = File.ReadAllText(filePath);
        var json = JSON.Parse(jsonString);

        label = json["label"];
        quaternionOrder = json["quaternion_order"];
        guidanceScale = json["guidance_scale"].AsFloat;

        // rotation_quat 데이터를 배열로 처리
        if (json["rotation_quat"] == null || json["rotation_quat"].IsNull)
        {
            Debug.LogError("❌ JSON 파일 내에 rotation_quat 데이터가 없습니다.");
            return;
        }

        var rotArray = json["rotation_quat"].AsArray;
        // 각 프레임은 배열이며, 각 프레임의 24개 관절 데이터는 배열 형식입니다.
        foreach (JSONNode frameValue in rotArray)
        {
            var frameArray = frameValue.AsArray;
            if (frameArray == null)
            {
                Debug.LogWarning("⚠️ 프레임 데이터 형식 오류");
                continue;
            }

            Dictionary<string, float[]> frameData = new Dictionary<string, float[]>();

            // 각 프레임의 관절 데이터를 처리 (예상: 24개)
            for (int i = 0; i < frameArray.Count; i++)
            {
                var jointData = frameArray[i].AsArray;
                if (jointData == null || jointData.Count < 4)
                {
                    Debug.LogWarning($"⚠️ 프레임 {smplQuatFrames.Count}의 관절 {i.ToString("D2")} 쿼터니언 데이터 형식 오류");
                    continue;
                }
                float[] qValues = new float[4];
                for (int j = 0; j < 4; j++)
                {
                    qValues[j] = jointData[j].AsFloat;
                }
                frameData[i.ToString("D2")] = qValues;
            }
            smplQuatFrames.Add(frameData);
        }

        totalFrames = smplQuatFrames.Count;
        Debug.Log($"✅ SMPL 쿼터니언 데이터 로드 완료: {totalFrames} 프레임, label: {label}");
    }

    // JSON 쿼터니언 데이터를 30fps 기준으로 재생하는 코루틴
    IEnumerator PlayQuaternionData()
    {
        if (smplQuatFrames == null || totalFrames == 0)
        {
            Debug.LogError("❌ 재생할 SMPL 쿼터니언 데이터가 없습니다.");
            yield break;
        }

        isPlaying = true;
        startTime = Time.time;
        currentFrameIndex = 0;
        float frameDuration = 1f / 30f; // 30fps 기준

        while (currentFrameIndex < totalFrames)
        {
            float elapsedTime = (Time.time - startTime) * playbackSpeed;
            if (elapsedTime >= currentFrameIndex * frameDuration)
            {
                ApplyQuaternionFrame(smplQuatFrames[currentFrameIndex]);
                currentFrameIndex++;
            }
            yield return null;
        }

        Debug.Log("⏹ 쿼터니언 재생 완료!");
        isPlaying = false;
    }

    // ApplyQuaternionFrame 메서드 수정
    void ApplyQuaternionFrame(Dictionary<string, float[]> frameQuat)
    {
        // X축 기준으로 90도 회전하는 글로벌 보정 쿼터니언
        Quaternion globalCorrection = Quaternion.Euler(-90, 0, 0);
        
        // 프레임 데이터에 포함된 모든 조인트에 대해 반복
        foreach (var jointEntry in frameQuat)
        {
            // 키에서 조인트 인덱스 파싱
            if (int.TryParse(jointEntry.Key, out int jointIndex) && jointIndex < targetObjects.Length)
            {
                // 마지막 두 조인트는 건너뛰기 (24개 중 인덱스 22, 23 건너뛰기)
                if (jointIndex >= 22) continue;
                
                // 쿼터니언 성분 추출
                float[] quatValues = jointEntry.Value;
                
                // 모든 쿼터니언 성분(w, x, y, z)이 있는지 확인
                if (quatValues.Length >= 4)
                {
                    // 오른손 좌표계에서 Unity의 왼손 좌표계로 변환
                    Quaternion rotation = new Quaternion(
                        quatValues[1],     // x
                        -quatValues[2],    // y (부호 반전)
                        -quatValues[3],    // z (부호 반전)
                        quatValues[0]      // w
                    );
                    
                    // 루트 조인트(인덱스 0)에만 글로벌 보정 회전 적용
                    if (jointIndex == 0)
                    {
                        targetObjects[jointIndex].localRotation = globalCorrection * rotation;
                    }
                    else
                    {
                        targetObjects[jointIndex].localRotation = rotation;
                    }
                }
                else
                {
                    Debug.LogWarning($"조인트 {jointEntry.Key}의 쿼터니언 데이터가 불완전합니다.");
                }
            }
        }

        // 현재 프레임 정보 디버그 출력
        if (frameText != null)
        {
            frameText.text = $"PLAYING FRAME: {currentFrameIndex}/{totalFrames}";
        }
    }
}