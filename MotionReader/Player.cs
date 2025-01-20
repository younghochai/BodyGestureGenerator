using System.Collections;
using System.Collections.Generic;
using System.IO;
using TMPro;
using UnityEngine;

/// <summary>
/// AMASS data animation player for SMPL-X
/// </summary>
public class Player : MonoBehaviour
{
    // 이벤트 핸들러 선언
    public delegate void OnDataLoaded();
    public event OnDataLoaded DataLoadedEvent;

    [Header("Recording Mode")]
    public bool RecordMode;

    [Header("Reader Mode")]
    public bool CSVMode;
    public bool TXTMode;

    [Header("File Path")]
    public string RootFilePath;
    public string FileName;

    [Header("Position")]
    [Tooltip("기본값은 0")]
    public float pelvisHeight;

    [Header("Animation Delay")]
    public float seconds;

    [HideInInspector]
    public bool xDown;
    [HideInInspector]
    public bool cDown;

    public List<List<List<Quaternion>>> load_quat_list = new List<List<List<Quaternion>>>();
    public List<List<List<Vector3>>> load_axis_list = new List<List<List<Vector3>>>();

    SMPLX smpl_module;
    private bool isInitialRotationApplied = false; // 초기 회전 적용 여부를 추적하는 플래그

    string[] _bodyJointNames = new string[] {"global_pos","pelvis", "left_hip", "right_hip", "spine1", "left_knee",
                                             "right_knee", "spine2", "left_ankle", "right_ankle", "spine3",
                                             "left_foot", "right_foot", "neck", "left_collar", "right_collar",
                                             "head", "left_shoulder", "right_shoulder", "left_elbow", "right_elbow",
                                             "left_wrist", "right_wrist" };

    string[] _bodyCustomJointNames = new string[] { "pelvis","spine2","right_shoulder","right_elbow", "left_shoulder",
                                                    "left_elbow","right_hip","right_knee","left_hip","left_knee"};

    Transform pelvis;

    void Start()
    {
        //현재 스크립트가 붙어있는 SMPL 모델 정보를 가져옴
        smpl_module = this.GetComponent<SMPLX>();
        // smpl 모델에서 pelvis를 정보를 가져옴. smplx-male - root - pelvis
        pelvis = transform.GetChild(0).GetChild(0).GetChild(0);

        // RecordMode가 활성화된 경우 곧바로 파일을 읽고 애니메이션 실행
        if (RecordMode)
        {
            LoadAnimationData();
            StartAnimation();
        }
    }

    // Update is called once per frame
    void Update()
    {
        GetInput();

        // RecordMode가 아닌 경우에만 X, C 키로 파일 읽기 및 애니메이션
        if (!RecordMode)
        {
            fileRead();
            _Animation();
        }
    }

    /// <summary>
    /// X키로 CSV를 읽어온 뒤 C키로 코루틴 실행
    /// </summary>
    void GetInput()
    {
        xDown = Input.GetKeyDown(KeyCode.X);
        cDown = Input.GetKeyDown(KeyCode.C);
    }

    /// <summary>
    /// 읽고자하는 CSV or txt 파일의 전체 경로를 CSVReader(" ")의 문자열 매개변수로 입력
    /// 
    /// EX)   CSVReader("C:/Users/{username}/filepath.../" + "fileName")
    /// 
    /// </summary>
    void LoadAnimationData()
    {
        if (CSVMode)
        {
            CSVReader(RootFilePath + FileName);
            Debug.Log("CSV file load done");
            //Debug.Log($"total frame : {load_axis_list[0][0].Count}");
        }
        if (TXTMode)
        {
            TXTReader(RootFilePath + FileName);
            Debug.Log("TXT file load done");
        }

        // 데이터 로드 완료 이벤트 호출(Recording Mode를 위한 옵션)
        if (DataLoadedEvent != null)
        {
            DataLoadedEvent();
        }
    }

    void fileRead()
    {
        if(xDown)
        {
            LoadAnimationData();
        }
    }

    /// <summary>
    /// 읽어들인 CSV 파일(or TXT 파일)을 Update() 콜백 메소드에서 코루틴으로 순차적으로 재생하기 위한 함수
    /// CSVMode가 켜져 있을 땐 txt를 읽을 수 없고 반대의 경우 csv를 읽을 수 없음.
    /// </summary>
    void StartAnimation()
    {
        if (CSVMode)
        {
            StartCoroutine(avatar_play());
        }
        if (TXTMode)
        {
            StartCoroutine(avator_play_custom());
        }
    }

    
    void _Animation()
    {
        if(cDown)
        {
            StartAnimation();
        }
    }

    /// <summary>
    /// AMASS 데이터를 애니메이션하기 위한 코루틴
    /// </summary>
    /// <returns></returns>
    IEnumerator avatar_play()
    {
        // 이 코드가 주석처리 되면 아래로 누운 상태로 재생됨
        // 처음 코루틴이 실행될 때만 회전을 적용
        if (!isInitialRotationApplied)
        {
            transform.rotation *= Quaternion.Euler(-90.0f, 0.0f, 0.0f);
            isInitialRotationApplied = true; // 회전이 적용되었음을 표시
        }

        for (int frame_cnt = 0; frame_cnt < load_axis_list[0][0].Count; frame_cnt++)
        {

            for (int i = 0; i < _bodyJointNames.Length; i++)
            {
                if (i == 0)
                {
                    //Translation
                    Vector3 pos_ = new Vector3(load_axis_list[0][i][frame_cnt].x, load_axis_list[0][i][frame_cnt].z, load_axis_list[0][i][frame_cnt].y);

                    pelvis.position = pos_ + new Vector3(0f, pelvisHeight, 0f);
                }
                else if (i != 0)
                {
                    smpl_module.SetLocalJointRotation(_bodyJointNames[i], QuatFromRodrigues(load_axis_list[0][i][frame_cnt].x, load_axis_list[0][i][frame_cnt].y, load_axis_list[0][i][frame_cnt].z));
                }

                
            }
            smpl_module.UpdateJointPositions(false);
            yield return new WaitForSeconds(seconds); // origin 0.008f / Ragdoll 0.000f 레그돌 환경일 때 지연 시간이 없는게 더 좋음
        }
        yield break;
    }

    /// <summary>
    /// 센서를 통해 취득한 데이터를 플레이하기 위한 코루틴
    /// </summary>
    /// <returns></returns>
    IEnumerator avator_play_custom()
    {
        for (int frame_cnt = 0; frame_cnt < load_quat_list[0][0].Count; frame_cnt++)
        {

            for (int i = 0; i < _bodyCustomJointNames.Length; i++)
            {
                //smpl_module.SetWorldJointRotation(_bodyCustomJointNames[i], load_quat_list[0][i][frame_cnt]);
                //smpl_module.SetLocalJointRotation(_bodyCustomJointNames[i], load_quat_list[0][i][frame_cnt]);
                smpl_module.SetWorld2LocalJointRotation(_bodyCustomJointNames[i], load_quat_list[0][i][frame_cnt]);
            }
            smpl_module.UpdateJointPositions(false);
            yield return new WaitForSeconds(.025f);
        }
        yield break;
    }

    /// <summary>
    /// 콤마(,)로 각 값을, 개행(\n)으로 하나의 프레임을 구분함
    /// 최초 작성자 - 류재영 , 인용 - 김현범
    /// </summary>
    /// <param name="file_path">파일 경로</param>
    void CSVReader(string file_path)
    {
        FileStream quatStream = new FileStream(file_path, FileMode.Open);

        StreamReader sr = new StreamReader(quatStream);
        string[] fields;
        string[] records = sr.ReadToEnd().Split('\n');

        List<List<Vector3>> load_axis_buf = new List<List<Vector3>>();

        for (int i = 0; i < _bodyJointNames.Length; i++)
        {
            load_axis_buf.Add(new List<Vector3>());
        }

        float[] data_val = new float[3];

        for (int line = 0; line < records.Length; line++)
        {
            fields = records[line].Split(',');

            int fields_cnt = 0;

            for (int device_idx = 0; device_idx < (fields.Length / 3); device_idx++)
            {
                for (int val_idx = 0; val_idx < 3; val_idx++)
                {
                    data_val[val_idx] = float.Parse(fields[fields_cnt]);
                    //Debug.Log("loaded " + fields[fields_cnt]);
                    fields_cnt++;
                }
                //Debug.Log(new Quaternion(data_val[0], data_val[1], data_val[2], data_val[3]));
                load_axis_buf[device_idx].Add(new Vector3(data_val[0], data_val[1], data_val[2]));
            }
        }
        Debug.Log("Axis reading done");
        sr.Close();
        quatStream.Close();

        load_axis_list.Add(load_axis_buf);

        return;
    }

    void TXTReader(string file_path)
    {
        FileStream quatStream = new FileStream(file_path, FileMode.Open);

        StreamReader sr = new StreamReader(quatStream);
        string[] fields;
        string[] records = sr.ReadToEnd().Split('\n');

        List<List<Quaternion>> load_quat_buf = new List<List<Quaternion>>();

        for (int i = 0; i < _bodyJointNames.Length; i++)
        {
            load_quat_buf.Add(new List<Quaternion>());
        }

        float[] data_val = new float[4];

        for (int line = 0; line < records.Length; line++)
        {
            fields = records[line].Split('\t');

            int fields_cnt = 0;

            for (int device_idx = 0; device_idx < (fields.Length / 4); device_idx++)
            {
                for (int val_idx = 0; val_idx < 4; val_idx++)
                {
                    data_val[val_idx] = float.Parse(fields[fields_cnt]);
                    //Debug.Log("loaded " + fields[fields_cnt]);
                    fields_cnt++;
                }
                //Debug.Log(new Quaternion(data_val[0], data_val[1], data_val[2], data_val[3]));
                load_quat_buf[device_idx].Add(new Quaternion(-data_val[1], data_val[3], data_val[2], data_val[0]));
                //load_quat_buf[device_idx].Add(new Quaternion(data_val[1], data_val[2], data_val[3], data_val[0]));
            }
        }
        Debug.Log("quaternion reading done");
        sr.Close();
        quatStream.Close();

        load_quat_list.Add(load_quat_buf);

        return;
    }

    public static Quaternion QuatFromRodrigues(float rodX, float rodY, float rodZ)
    {
        // Local joint coordinate systems
        //   SMPL-X: X-Right, Y-Up, Z-Back, Right-handed
        //   Unity:  X-Left,  Y-Up, Z-Back, Left-handed
        Vector3 axis = new Vector3(-rodX, rodY, rodZ);
        float angle_deg = -axis.magnitude * Mathf.Rad2Deg;
        Vector3.Normalize(axis);

        Quaternion quat = Quaternion.AngleAxis(angle_deg, axis);

        return quat;
    }
}
