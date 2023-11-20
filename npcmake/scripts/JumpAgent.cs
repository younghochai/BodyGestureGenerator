//Put this script on your blue cube.

using System.Collections;
using UnityEngine;
using Unity.MLAgents;
using Unity.Barracuda;
using Unity.MLAgents.Actuators;
using Unity.MLAgents.Sensors;
using Unity.MLAgentsExamples;
using JKress.AITrainer;

public class JumpAgent : Agent
{
    [Header("Body Parts")]
    [SerializeField] Transform hips;
    [SerializeField] Transform spine;
    [SerializeField] Transform head;
    [SerializeField] Transform thighL;
    [SerializeField] Transform shinL;
    [SerializeField] Transform footL;
    [SerializeField] Transform thighR;
    [SerializeField] Transform shinR;
    [SerializeField] Transform footR;
    [SerializeField] Transform armL;
    [SerializeField] Transform forearmL;
    [SerializeField] Transform armR;
    [SerializeField] Transform forearmR;

    [Header("Stabilizer")]
    [Range(1000, 4000)][SerializeField] float m_stabilizerTorque = 4000f;
    float m_minStabilizerTorque = 1000;
    float m_maxStabilizerTorque = 4000;
    [SerializeField] Stabilizer hipsStabilizer;
    [SerializeField] Stabilizer spineStabilizer;

    [Header("Walk Speed")] //The walking speed to try and achieve
    [Range(0.1f, 4)][SerializeField] float m_TargetWalkingSpeed = 2;
   

    public float MStabilizerTorque
    {
        get { return m_stabilizerTorque; }
        set { m_stabilizerTorque = Mathf.Clamp(value, m_minStabilizerTorque, m_maxStabilizerTorque); }
    }
    float m_minWalkingSpeed = 0.1f;
    float m_maxWalkingSpeed = 4;
    // Depending on this value, the wall will have different height
    int m_Configuration;
    // Brain to use when no wall is present
    public NNModel noWallBrain;
    // Brain to use when a jumpable wall is present
   

    public GameObject ground;
   
    Bounds m_SpawnAreaBounds;


   
    public GameObject wall;
    Rigidbody m_ShortBlockRb;
    Rigidbody m_AgentRb;
    Material m_GroundMaterial;
    Renderer m_GroundRenderer;
    WallJumpSettings m_WallJumpSettings;

    public float jumpingTime;
    public float jumpTime;
    // This is a downward force applied when falling to make jumps look
    // less floaty
    public float fallingForce;
    // Use to check the coliding objects
    public Collider[] hitGroundColliders = new Collider[3];
    Vector3 m_JumpTargetPos;
    Vector3 m_JumpStartingPos;

    string m_NoWallBehaviorName = "SmallWallJump";
    string m_SmallWallBehaviorName = "SmallWallJump";
    string m_BigWallBehaviorName = "BigWallJump";

    EnvironmentParameters m_ResetParams;
    JointDriveController m_JdController;
    public override void Initialize()
    {

        //Setup each body part
        m_JdController = GetComponent<JointDriveController>();

        m_JdController.SetupBodyPart(hips);
        m_JdController.SetupBodyPart(spine);
        m_JdController.SetupBodyPart(head);
        m_JdController.SetupBodyPart(thighL);
        m_JdController.SetupBodyPart(shinL);
        m_JdController.SetupBodyPart(footL);
        m_JdController.SetupBodyPart(thighR);
        m_JdController.SetupBodyPart(shinR);
        m_JdController.SetupBodyPart(footR);
        m_JdController.SetupBodyPart(armL);
        m_JdController.SetupBodyPart(forearmL);
        m_JdController.SetupBodyPart(armR);
        m_JdController.SetupBodyPart(forearmR);

        hipsStabilizer.uprightTorque = m_stabilizerTorque;
        spineStabilizer.uprightTorque = m_stabilizerTorque;

        m_WallJumpSettings = FindObjectOfType<WallJumpSettings>();
        m_Configuration = Random.Range(0, 5);

        m_AgentRb = GetComponent<Rigidbody>();
     
        m_GroundRenderer = ground.GetComponent<Renderer>();
        m_GroundMaterial = m_GroundRenderer.material;

  

        m_ResetParams = Academy.Instance.EnvironmentParameters;

    }

    // Begin the jump sequence
    public void Jump()
    {
        jumpingTime = 0.2f;
        m_JumpStartingPos = m_AgentRb.position;
    }

    /// <summary>
    /// Does the ground check.
    /// </summary>
    /// <returns><c>true</c>, if the agent is on the ground,
    /// <c>false</c> otherwise.</returns>
    /// <param name="smallCheck"></param>
 

   
   

 
    IEnumerator GoalScoredSwapGroundMaterial(Material mat, float time)
    {
        m_GroundRenderer.material = mat;
        yield return new WaitForSeconds(time); //wait for 2 sec
        m_GroundRenderer.material = m_GroundMaterial;
    }

    public bool DoGroundCheck(Transform bodyPart, bool smallCheck)
    {
        if (!smallCheck)
        {
            hitGroundColliders = new Collider[3];
            var o = bodyPart.gameObject;
            Physics.OverlapBoxNonAlloc(
                o.transform.position + new Vector3(0, -0.05f, 0),
                new Vector3(0.95f / 2f, 0.5f, 0.95f / 2f),
                hitGroundColliders,
                o.transform.rotation);
            var grounded = false;
            foreach (var col in hitGroundColliders)
            {
                if (col != null && col.transform != bodyPart &&
                    (col.CompareTag("walkableSurface") ||
                     col.CompareTag("block") ||
                     col.CompareTag("wall")))
                {
                    grounded = true;
                    break;
                }
            }
            return grounded;
        }
        else
        {
            RaycastHit hit;
            Physics.Raycast(bodyPart.position + new Vector3(0, -0.05f, 0), -Vector3.up, out hit, 1f);

            if (hit.collider != null &&
                (hit.collider.CompareTag("walkableSurface") ||
                 hit.collider.CompareTag("block") ||
                 hit.collider.CompareTag("wall"))
                && hit.normal.y > 0.95f)
            {
                return true;
            }

            return false;
        }
    }


    public override void OnActionReceived(ActionBuffers actionBuffers)

    {
        var bpDict = m_JdController.bodyPartsDict;
        float jumpAction = actionBuffers.ContinuousActions[actionBuffers.ContinuousActions.Length - 1];
        var continuousActions = actionBuffers.ContinuousActions;
        var i = -1;

        bpDict[spine].SetJointTargetRotation(continuousActions[++i], continuousActions[++i], continuousActions[++i]);
        bpDict[thighL].SetJointTargetRotation(continuousActions[++i], 0, continuousActions[++i]);
        bpDict[thighR].SetJointTargetRotation(continuousActions[++i], 0, continuousActions[++i]);
        bpDict[shinL].SetJointTargetRotation(continuousActions[++i], 0, 0);
        bpDict[shinR].SetJointTargetRotation(continuousActions[++i], 0, 0);
        bpDict[footR].SetJointTargetRotation(continuousActions[++i], continuousActions[++i], continuousActions[++i]);
        bpDict[footL].SetJointTargetRotation(continuousActions[++i], continuousActions[++i], continuousActions[++i]);
        bpDict[armL].SetJointTargetRotation(continuousActions[++i], 0, continuousActions[++i]);
        bpDict[armR].SetJointTargetRotation(continuousActions[++i], 0, continuousActions[++i]);
        bpDict[forearmL].SetJointTargetRotation(continuousActions[++i], 0, 0);
        bpDict[forearmR].SetJointTargetRotation(continuousActions[++i], 0, 0);
        bpDict[head].SetJointTargetRotation(continuousActions[++i], continuousActions[++i], 0);

        //update joint strength settings
        bpDict[spine].SetJointStrength(continuousActions[++i]);
        bpDict[head].SetJointStrength(continuousActions[++i]);
        bpDict[thighL].SetJointStrength(continuousActions[++i]);
        bpDict[shinL].SetJointStrength(continuousActions[++i]);
        bpDict[footL].SetJointStrength(continuousActions[++i]);
        bpDict[thighR].SetJointStrength(continuousActions[++i]);
        bpDict[shinR].SetJointStrength(continuousActions[++i]);
        bpDict[footR].SetJointStrength(continuousActions[++i]);
        bpDict[armL].SetJointStrength(continuousActions[++i]);
        bpDict[forearmL].SetJointStrength(continuousActions[++i]);
        bpDict[armR].SetJointStrength(continuousActions[++i]);
        bpDict[forearmR].SetJointStrength(continuousActions[++i]);
        bpDict[thighL].SetJointStrength(jumpAction);
        bpDict[shinL].SetJointStrength(jumpAction);
        bpDict[footL].SetJointStrength(jumpAction);
        bpDict[thighR].SetJointStrength(jumpAction);
        bpDict[shinR].SetJointStrength(jumpAction);
        bpDict[footR].SetJointStrength(jumpAction);

    }
    public void CollectObservationBodyPart(BodyPart bp, VectorSensor sensor)
    {
        //Interaction Objects Contact Check
        sensor.AddObservation(bp.objectContact.touchingGround); // Is this bp touching the ground
        sensor.AddObservation(bp.objectContact.touchingWall); // Is this bp touching the wall

    
        //Get local rotations (including hips)
        sensor.AddObservation(bp.rb.transform.localRotation);

        //Skip body parts without a joint drive
        if (bp.rb.transform != hips) sensor.AddObservation(bp.currentStrength / m_JdController.maxJointForceLimit);
    }

    public override void Heuristic(in ActionBuffers actionBuffers)
    {
        float x = Input.GetAxis("Vertical");
        float y = Input.GetAxis("Horizontal");
        float force = Input.GetKey(KeyCode.Space) ? 1.0f : 0.0f;

        var continuousActions = actionBuffers.ContinuousActions;
        var i = -1;

        //SetJointTargetRotation
        continuousActions[++i] = -x; continuousActions[++i] = y; continuousActions[++i] = y;
        continuousActions[++i] = x; continuousActions[++i] = y;
        continuousActions[++i] = x; continuousActions[++i] = y;
        continuousActions[++i] = x;
        continuousActions[++i] = x;
        continuousActions[++i] = x; continuousActions[++i] = y; continuousActions[++i] = y;
        continuousActions[++i] = x; continuousActions[++i] = y; continuousActions[++i] = y;
        continuousActions[++i] = x; continuousActions[++i] = y;
        continuousActions[++i] = x; continuousActions[++i] = y;
        continuousActions[++i] = x;
        continuousActions[++i] = x;
        continuousActions[++i] = x; continuousActions[++i] = y;

        //SetJointStrength 
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
        continuousActions[++i] = force;
    }

    // Detect when the agent hits the goal
    void OnTriggerStay(Collider col)
    {
        if (col.gameObject.CompareTag("ground") && DoJumpCheck())
        {
        SetReward(1f);
        EndEpisode();
        }
    }
    public bool DoGroundCheck(Transform bodyPart)
    {
        RaycastHit hit;
        Physics.Raycast(bodyPart.position, -Vector3.up, out hit, 1f);

        if (hit.collider != null &&
            (hit.collider.CompareTag("walkableSurface") ||
             hit.collider.CompareTag("block") ||
             hit.collider.CompareTag("wall"))
            && hit.normal.y > 0.95f)
        {
            return true;
        }

        return false;
    }
    bool DoJumpCheck()
    {
        // Check if the agent has jumped
        if (jumpingTime > 0)
        {
            // Check if both feet are touching the ground
            if (DoGroundCheck(footL) && DoGroundCheck(footR))
            {
                // Check if other parts are not touching the ground
                if (!DoGroundCheck(thighL) && !DoGroundCheck(shinL) &&
                    !DoGroundCheck(thighR) && !DoGroundCheck(shinR) &&
                    !DoGroundCheck(armL) && !DoGroundCheck(forearmL) &&
                    !DoGroundCheck(armR) && !DoGroundCheck(forearmR) &&
                    !DoGroundCheck(spine) && !DoGroundCheck(head))
                {
                    return true;
                }
            }
        }
        return false;
    }
    //Reset the orange block position


    public override void OnEpisodeBegin()
    {
       
        transform.localPosition = new Vector3(
            18 * (Random.value - 0.5f), 1, -12);
        m_Configuration = Random.Range(0, 5);
        m_AgentRb.velocity = default(Vector3);
    }

    void FixedUpdate()
    {
        var bpDict = m_JdController.bodyPartsDict;
        if (m_Configuration != -1)
        {
            ConfigureAgent(m_Configuration);
            m_Configuration = -1;
        }
        float jumpReward = hips.position.y - 1.0f; // Reward is proportional to the height of the hips above the ground
        AddReward(jumpReward);

        // Add a reward for landing
        if (bpDict[footL].rb.position.y < 0.5f && bpDict[footR].rb.position.y < 0.5f) // If both feet are close to the ground
        {
            AddReward(1.0f); // Add a large reward for landing
        }
    }

    void ConfigureAgent(int config)
    {
        var localScale = wall.transform.localScale;
        if (config == 0)
        {
            localScale = new Vector3(
                localScale.x,
                m_ResetParams.GetWithDefault("no_wall_height", 0),
                localScale.z);
            wall.transform.localScale = localScale;
            SetModel(m_NoWallBehaviorName, noWallBrain);
        }
       
    }
}
