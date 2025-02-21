using System.Collections.Generic;
using System.IO;
using UnityEngine;
using TMPro;
using ChartAndGraph;

public class JointAngleController : MonoBehaviour
{
    public GraphChart chart;

    [Header("UI Settings")]
    // Dropdown
    public TMP_Dropdown jointDropdown;
    public TMP_Dropdown axisDropdown;

    // Button
    public UnityEngine.UI.Button increaseButton; // +0.1 버튼
    public UnityEngine.UI.Button decreaseButton; // -0.1 버튼
    public UnityEngine.UI.Button shiftLeftButton; // Shift Left 버튼
    public UnityEngine.UI.Button shiftRightButton; // Shift Right 버튼
    public UnityEngine.UI.Button saveCSVButton; // Save CSV 버튼

    [Header("Graph Settings")]
    //public float yAxisMin = -3f;  // Default Y-axis minimum value
    //public float yAxisMax = 3f;   // Default Y-axis maximum value

    [Header("File Path")]
    public string RootFilePath;
    public string FileName;

    private List<List<Vector3>> jointPositions;  // 각 관절의 위치 데이터를 저장
    private List<float> times; // 각 프레임의 시간을 저장
    private Dictionary<string, int> jointNameToIndex; // 조인트 이름 -> 인덱스 매핑
    public int startFrame;
    public int endFrame;
    public string selectedJoint;       // 선택된 조인트 이름

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
        // 0) 시간 리스트 초기화
        times = new List<float>();

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

        // 3) Dropdown 초기화
        InitializeDropdown(); // SMPL 조인트 목록
        InitializeAxisDropdown(); // 편집할 축 목록

        // 4) 기본 선택 조인트 설정 (인덱스 0: "pelvis")
        selectedJoint = _bodyJointNames[0];

        // 5) 버튼 이벤트 연결
        increaseButton.onClick.AddListener(() => OnValueChangeButtonClicked(0.1f));
        decreaseButton.onClick.AddListener(() => OnValueChangeButtonClicked(-0.1f));
        shiftLeftButton.onClick.AddListener(() => OnFrameShiftButtonClicked(-1));
        shiftRightButton.onClick.AddListener(() => OnFrameShiftButtonClicked(1));
        saveCSVButton.onClick.AddListener(OnSaveCSVButtonClicked);
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
            times.Add(float.Parse(values[1]));
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
    /// Dropdown (조인트 목록 추가)
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
                //Debug.Log($"Frame {frame}: {frameValue}");
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
    /// Dropdown (Axis Angle 목록 추가)
    /// </summary>
    void InitializeAxisDropdown()
    {
        if (axisDropdown == null)
        {
            Debug.LogWarning("Axis TMP_Dropdown is not assigned in the Inspector!");
            return;
        }

        // 기존 옵션 초기화
        axisDropdown.ClearOptions();
        // 축 옵션 추가
        List<string> options = new List<string> { "X", "Y", "Z" };
        axisDropdown.AddOptions(options);

        // 초기값 설정(인덱스 1: "Y")
        axisDropdown.value = 1;
    }

    /// <summary>
    /// Button (y value increase/decrease)
    /// </summary>
    private void OnValueChangeButtonClicked(float increment)
    {
        if (string.IsNullOrEmpty(selectedJoint)) return;
        
        int jointIndex = jointNameToIndex[selectedJoint];
        int selectedAxis = axisDropdown.value; // 0: X, 1: Y, 2: Z

        // 선택된 범위 내의 모든 프레임 Y값을 increment만큼 변경
        for (int frame = startFrame; frame <= endFrame && frame < jointPositions.Count; frame++)
        {
            Vector3 currentPos = jointPositions[frame][jointIndex];
            switch (selectedAxis)
            {
                case 0: // X
                    jointPositions[frame][jointIndex] = new Vector3(currentPos.x + increment, currentPos.y, currentPos.z);
                    break;
                case 1: // Y
                    jointPositions[frame][jointIndex] = new Vector3(currentPos.x, currentPos.y + increment, currentPos.z);
                    break;
                case 2: // Z
                    jointPositions[frame][jointIndex] = new Vector3(currentPos.x, currentPos.y, currentPos.z + increment);
                    break;
            }
        }

        // 그래프 업데이트
        PlotJoint(selectedJoint);
        Debug.Log($"Applied {increment:F1} increment to {selectedJoint} from frame {startFrame} to {endFrame}");
    }

    /// <summary>
    /// Button (X value shift)
    /// </summary>
    private void OnFrameShiftButtonClicked(int shiftAmount)
    {
        int range = endFrame - startFrame + 1; // 현재 프레임 범위 (startFrame ~ endFrame)
        int totalFrames = jointPositions.Count; // 전체 프레임 수
        int newRange; // 새로운 프레임 범위

        // Decrease (Scaling down)
        if (shiftAmount == -1)
        {
            newRange = Mathf.Max(1, range / 2); // 새로운 프레임 범위 = 현재 프레임 범위의 절반 (최소값은 1)

            // 1) startFrame ~ endFrame scaling down
            for (int i = 0; i < newRange; i++)
            {
                jointPositions[startFrame + i] = jointPositions[startFrame + (i * 2)];
            }

            // 2) endFrame ~ totalFrame translate left
            jointPositions.RemoveRange(startFrame + newRange, range - newRange);

            // 3) Update the frame range (startFrame ~ endFrame)
            endFrame = startFrame + newRange;

            // 4) Update the graph
            PlotJoint(selectedJoint);
            Debug.Log($"Scaled down frames from {startFrame} to {endFrame}. New range: {startFrame} to {endFrame}");
        }

        // Increase (Scaling up)
        else if (shiftAmount == 1)
        {
            newRange = Mathf.Min(totalFrames - startFrame, range * 2); // 새로운 프레임 범위는 현재 프레임 범위의 2배
            List<List<Vector3>> interpolatedFrames = new List<List<Vector3>>();
            List<List<Vector3>> preservedFrames = new List<List<Vector3>>();

            // 1) endFrame ~ totalFrame 보존
            for (int i = endFrame + 1; i < totalFrames; i++)
            {
                preservedFrames.Add(jointPositions[i]);
                Debug.Log($"Preserved frame {i}");
            }
            Debug.Log("Preserved frames: " + preservedFrames.Count);

            // 2) startFrame ~ endFrame scaling up -> Linear interpolation
            for (int i = 0; i < range; i++)
            {
                interpolatedFrames.Add(jointPositions[startFrame + i]);
                if (i < range - 1)
                {
                    List<Vector3> interpolatedFrame = new List<Vector3>();
                    for (int j = 0; j < jointPositions[startFrame + i].Count; j++)
                    {
                        Vector3 start = jointPositions[startFrame + i][j];
                        Vector3 end = jointPositions[startFrame + i + 1][j];
                        Vector3 mid = Vector3.Lerp(start, end, 0.5f); // Linear interpolation Coeff = 0.5
                        interpolatedFrame.Add(mid);
                    }
                    interpolatedFrames.Add(interpolatedFrame);
                }
            }

            // 3) Update the frame range (startFrame ~ endFrame)
            for (int i = 0; i < interpolatedFrames.Count; i++)
            {
                if (startFrame + i < jointPositions.Count)
                {
                    jointPositions[startFrame + i] = interpolatedFrames[i];
                }
                else
                {
                    jointPositions.Add(interpolatedFrames[i]);
                }
            }
            endFrame = startFrame + newRange;

            // 4) 보존해놓은 endFrame ~ totalFrame을 덮어쓰기
            for (int i = 0; i < preservedFrames.Count; i++)
            {
                if (startFrame + interpolatedFrames.Count + i < jointPositions.Count)
                {
                    jointPositions[startFrame + interpolatedFrames.Count + i] = preservedFrames[i];
                }
                else
                {
                    jointPositions.Add(preservedFrames[i]);
                }
            }

            // 5) Update the graph
            PlotJoint(selectedJoint);
            Debug.Log($"Scaled up frames from {startFrame} to {endFrame}. New range: {startFrame} to {endFrame}");
        }

        // Regularize the frame range
        startFrame = Mathf.Max(0, startFrame);
        endFrame = Mathf.Min(totalFrames - 1, endFrame);
    }

    /// <summary>
    /// Plot the selected joint on the graph
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
        chart.DataSource.ClearCategory("X Angle");
        chart.DataSource.ClearCategory("Y Angle");
        chart.DataSource.ClearCategory("Z Angle");

        // 3) 프레임 반복하며 (x축=프레임, y축=pos.y) 형태로 Plot
        for (int frame = 0; frame < jointPositions.Count; frame++)
        {
            Vector3 pos = jointPositions[frame][jIndex];
            chart.DataSource.AddPointToCategory("X Angle", frame, pos.x);
            chart.DataSource.AddPointToCategory("Y Angle", frame, pos.y);
            chart.DataSource.AddPointToCategory("Z Angle", frame, pos.z);
        }

        chart.DataSource.EndBatch();
    }

    /// <summary>
    /// Save Button
    /// </summary>
    private void OnSaveCSVButtonClicked()
    {
        string savePath = Path.Combine(RootFilePath, "Edited_" + FileName);
        SaveCSV(savePath);
    }

    private void SaveCSV(string filePath)
    {
        List<string> lines = new List<string>();

        // Add header
        string header = "Frame,Time";
        foreach (var jointName in _bodyJointNames)
        {
            header += $",{jointName}_wx,{jointName}_wy,{jointName}_wz";
        }
        lines.Add(header);

        // Ensure times list matches jointPositions list size
    while (times.Count < jointPositions.Count)
    {
        times.Add(times.Count > 0 ? times[times.Count - 1] + (times[1] - times[0]) : 0f);
    }

        // Add data
        for (int i = 0; i < jointPositions.Count; i++)
        {
            //string line = $"{i},{i * 0.00581}"; // Assuming 172 FPS, adjust as necessary
            string line = $"{i},{times[i]}"; // 저장된 시간 값을 사용
            foreach (var pos in jointPositions[i])
            {
                line += $",{pos.x},{pos.y},{pos.z}";
            }
            lines.Add(line);
        }

        File.WriteAllLines(filePath, lines);
        Debug.Log($"CSV saved to {filePath}");
    }
}