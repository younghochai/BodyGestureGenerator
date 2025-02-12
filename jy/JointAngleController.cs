using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using TMPro;
using ChartAndGraph;
using UnityEngine.UI;
using UnityEngine.UIElements;

public class JointAngleController : MonoBehaviour
{
    public GraphChart chart;

    [Header("UI Settings")]
    public TMP_Dropdown jointDropdown; // Inspector에서 드롭다운(오브젝트)을 연결
    public UnityEngine.UI.Button updateButton; // 업데이트 버튼
    public int startFrame;
    public int endFrame;
    public string selectedJoint;       // 선택된 조인트 이름

    [Header("File Path")]
    public string RootFilePath;
    public string FileName;

    [Header("Joint Selection")]
    SMPLX smpl_module;

    private List<List<Vector3>> jointPositions;  // 각 관절의 위치 데이터를 저장
    private Dictionary<string, int> jointNameToIndex; // 조인트 이름 -> 인덱스 매핑

    // SMPL 또는 SMPLX에서 사용하는 조인트 목록
    string[] _bodyJointNames = new string[]
    {
        "pelvis", "left_hip", "right_hip", "spine1", "left_knee",
        "right_knee", "spine2", "left_ankle", "right_ankle", "spine3",
        "left_foot", "right_foot", "neck", "left_collar", "right_collar",
        "head", "left_shoulder", "right_shoulder", "left_elbow", "right_elbow",
        "left_wrist", "right_wrist"
    };

    void Start()
    {
        // 1) SMPL 조인트 데이터 구조 초기화
        jointPositions = new List<List<Vector3>>();
        jointNameToIndex = new Dictionary<string, int>();
        for (int i = 0; i < _bodyJointNames.Length; i++)
        {
            jointNameToIndex[_bodyJointNames[i]] = i;
        }

        // 2) CSV 파일 로드 -> jointPositions에 프레임별 (x,y,z) 좌표들 저장
        string fullPath = Path.Combine(RootFilePath, FileName);
        LoadCSV(fullPath);

        // 3) Dropdown 초기화 (SMPL 조인트 목록 연결)
        InitializeDropdown();

        // 4) 기본 선택 조인트 설정 (인덱스 0: "pelvis")
        selectedJoint = _bodyJointNames[0];

        // 5) 버튼 클릭 이벤트 연결
        updateButton.onClick.AddListener(OnUpdateButtonClicked);
    }

    void Update()
    {

    }

    void LoadCSV(string filePath)
    {
        if (string.IsNullOrEmpty(filePath))
        {
            Debug.LogWarning("CSV file path not set!");
            return;
        }
        if (!File.Exists(filePath))
        {
            Debug.LogWarning("CSV file does not exist: " + filePath);
            return;
        }

        string[] lines = File.ReadAllLines(filePath);

        // 첫 번째 줄은 헤더
        string[] headers = lines[0].Split(',');

        // 헤더에서 조인트 이름 추출
        for (int i = 2; i < headers.Length; i += 3)
        {
            string jointName = headers[i].Replace("_wx", "");
            jointNameToIndex[jointName] = (i - 2) / 3;
        }

        // 데이터 읽기
        for (int i = 1; i < lines.Length; i++)
        {
            string[] values = lines[i].Split(',');
            List<Vector3> framePositions = new List<Vector3>();

            for (int j = 2; j < values.Length; j += 3)
            {
                float x = float.Parse(values[j]);
                float y = float.Parse(values[j + 1]);
                float z = float.Parse(values[j + 2]);
                framePositions.Add(new Vector3(x, y, z));
            }
            jointPositions.Add(framePositions);
        }
        Debug.Log($"CSV Load 완료. 총 프레임 수: {jointPositions.Count}");
    }

    /// <summary>
    /// Dropdown 초기화(조인트 목록 추가)
    /// </summary>
    void InitializeDropdown()
    {
        if (jointDropdown == null)
        {
            Debug.LogWarning("TMP_Dropdown is not assigned in the Inspector!");
            return;
        }

        // 기존 옵션 초기화
        jointDropdown.ClearOptions();
        // bodyJointNames -> 리스트 변환
        List<string> options = new List<string>(_bodyJointNames);
        // 드롭다운에 옵션 추가
        jointDropdown.AddOptions(options);

        // 이벤트 연결
        jointDropdown.onValueChanged.AddListener(OnJointSelected);

        // 초기값 설정(인덱스 0)
        jointDropdown.value = 0;
        OnJointSelected(0);
    }

    /// <summary>
    /// 드롭다운에서 선택한 조인트를 처리
    /// </summary>
    /// <param name="index">드롭다운에서 선택된 옵션의 인덱스</param>
    void OnJointSelected(int index)
    {
        selectedJoint = _bodyJointNames[index];
        Debug.Log($"[JointAngleController] 조인트 선택: {selectedJoint}");

        // 조인트의 첫 프레임 값 찍어보기
        if (jointPositions.Count > 0)
        {
            int jointIndex = jointNameToIndex[selectedJoint];
            Vector3 firstFrameValue = jointPositions[0][jointIndex];
            //Debug.Log($"조인트 '{selectedJoint}' 첫 프레임값 = {firstFrameValue}");

            // Print joint data values within the specified frame range
            for (int frame = startFrame; frame <= endFrame && frame < jointPositions.Count; frame++)
            {
                Vector3 frameValue = jointPositions[frame][jointIndex];
                Debug.Log($"Frame {frame}: {frameValue}");
            }
        }
        else
        {
            Debug.LogWarning("jointPositions is empty. CSV not loaded?");
        }

        // 만약 차트에 해당 조인트를 Plot하고 싶다면 아래처럼 호출:
        PlotJoint(selectedJoint);
    }

    /// <summary>
    /// 업데이트 버튼 클릭 시 호출되는 메서드
    /// </summary>
    void OnUpdateButtonClicked()
    {
        if (jointPositions.Count > 0)
        {
            int jointIndex = jointNameToIndex[selectedJoint];

            // Print joint data values within the specified frame range
            for (int frame = startFrame; frame <= endFrame && frame < jointPositions.Count; frame++)
            {
                Vector3 frameValue = jointPositions[frame][jointIndex];
                Debug.Log($"Frame {frame}: {frameValue}");
            }

            // Update the graph
            PlotJoint(selectedJoint);
        }
        else
        {
            Debug.LogWarning("jointPositions is empty. CSV not loaded?");
        }
    }

    /// <summary>
    /// 예: 선택된 조인트를 JointPlot 카테고리에 표시
    /// </summary>
    void PlotJoint(string jointName)
    {
        if (chart == null)
        {
            Debug.LogWarning("Chart reference not set!");
            return;
        }

        // 1) jointName -> jointIndex
        int jIndex = jointNameToIndex[jointName];

        // 2) 카테고리 준비
        chart.DataSource.StartBatch();

        chart.DataSource.ClearCategory("JointPlot");

        // 3) 프레임 반복하며 (x축=프레임, y축=pos.y) 형태로 Plot
        for (int frame = 0; frame < jointPositions.Count; frame++)
        {
            Vector3 pos = jointPositions[frame][jIndex];
            chart.DataSource.AddPointToCategory("JointPlot", frame, pos.y);
        }

        chart.DataSource.EndBatch();
    }
}