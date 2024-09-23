using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using Unity.MLAgents;
using UnityEngine;
using static Player;

/// <summary>
/// ML-Agents 환경에서 Player 스크립트를 통하여 Demo 파일을 녹화할 때 쓰이는 보조 스크립트
/// </summary>
public class MocapDemonstrationController : MonoBehaviour
{
    Player playerScript; // Player 스크립트 참조
    Agent m_agent; // ML-Agents의 에이전트 참조
    public int totalFrames; // 전체 프레임 수 (CSV 파일의 총 프레임)
    public int currentFrame = 0; // 현재 프레임

    // 대충 몇번 반복 할 건지 기입할 수 있는 변수

    void Start()
    {
        playerScript = GetComponent<Player>();
        m_agent = GetComponent<Agent>();

        // Player 스크립트가 제대로 연결되었는지 확인
        if (playerScript == null)
        {
            Debug.LogError("Player script is not assigned!");
            return;
        }

        if (m_agent == null)
        {
            Debug.LogError("Agent script is not assigned!");
            return;
        }

        // RecordMode가 true일 때는 데이터가 로드된 후 자동으로 애니메이션 실행
        if (playerScript.RecordMode)
        {
            // Player에서 데이터 로드 완료 이벤트 구독
            playerScript.DataLoadedEvent += new Player.OnDataLoaded(OnDataLoaded);

            Debug.Log("RecordMode 활성화됨, 데이터 로드를 대기 중...");
        }
    }

    void OnDataLoaded()
    {
        // 데이터가 로드된 후 호출되는 메서드
        if (playerScript.load_axis_list != null && playerScript.load_axis_list.Count > 0 && playerScript.load_axis_list[0].Count > 0 && playerScript.load_axis_list[0][0].Count > 0)
        {
            totalFrames = playerScript.load_axis_list[0][0].Count;
            Debug.Log("totalFrames 계산 완료 (RecordMode)");

            // 애니메이션 실행
            StartCoroutine(RecordAnimation());
        }
        else
        {
            Debug.LogError("Animation data is not loaded properly.");
        }
    }

    private void Update()
    {
        if (playerScript.load_axis_list != null && playerScript.xDown)
        {
            totalFrames = playerScript.load_axis_list[0][0].Count;
        }

        if (playerScript.cDown)
        {
            // 전체 프레임 수를 기반으로 코루틴 실행
            StartCoroutine(RecordAnimation());
        }

    }

    IEnumerator RecordAnimation()
    {
        // 애니메이션 시작 전에 필요한 초기화 작업
        playerScript.CSVMode = true;
        playerScript.TXTMode = false;

        while (currentFrame < totalFrames)
        {
            currentFrame++;
            yield return null; // 한 프레임 대기
        }

        // 전체 애니메이션이 끝나면 에피소드 종료
        if(currentFrame == totalFrames)
        {
            m_agent.EndEpisode();
            // 레코딩 모드 시 애니메이션이 종료되면 에디터 종료
            if (playerScript.RecordMode)
            {
#if UNITY_EDITOR
                UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
            }
            currentFrame = 0;
        }
    }
}
