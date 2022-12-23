#include <MainWindow.h>
#include <iostream>
#include "ui_MainWindow.h"

#include <vtkSphere.h>
#include "allHeaders.h"
#include <vtkConeSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSampleFunction.h>
#include <vtkContourFilter.h>
#include <vtkIdFilter.h>
#include <vtkBox.h>
#include <vtkClipPolyData.h>
#include <vtkCellArray.h>
#include <vtkLine.h>
#include <cmath>
#include <io.h>

using namespace std;



struct EulerAngles {
	double x_roll, y_pitch, z_yaw;
};

std::vector< EulerAngles> readSensingAngles;
std::vector< EulerAngles> readSensingAngles_RL;
std::vector< EulerAngles> readSensingAngles_LU;
std::vector< EulerAngles> readSensingAngles_LL;


bool b_saveImage = false;
bool b_drawTrajectory = false;

float global_theta = 0;
float global_phi = 0;

std::vector<vtkSmartPointer<vtkActor>> actors;
vtkNew<vtkActor> sphere2Actor;




//Humanoid Model Color Setting
string COLOR_PlconeActor = "Moccasin";
string COLOR_CUconeActor = "DarkTurquoise";
string COLOR_CUconeActor_upper = "DarkTurquoise";
string COLOR_Head_objActor = "Moccasin";

string COLOR_LeftHand_objActor = "Crimson";
string COLOR_RightHand_objActor = "Crimson";
string COLOR_LF_objActor = "Crimson";
string COLOR_RF_objActor = "Crimson";

string COLOR_RarmActor = "Crimson";
string COLOR_RforearmActor = "Crimson";
string COLOR_LarmActor = "Crimson";
string COLOR_LforearmActor = "Crimson";
string COLOR_RlulegActor = "Crimson";
string COLOR_RllegActor = "Crimson";
string COLOR_LlulegActor = "Crimson";
string COLOR_LllegActor = "Crimson";

string COLOR_ConstraintProp_sphere_actor = "Lime";
string COLOR_ConstraintProp_line_actor = "Cornsilk";
string COLOR_ConstraintProp_plane_actor = "Cornsilk";
string COLOR_ConstraintProp_cube_actor = "Cornsilk";

string COLOR_TConstraintProp_sphere_actor = "Red";
string COLOR_TConstraintProp_sphere_actor2 = "DeepSkyBlue";
string COLOR_TConstraintProp_sphere_actor3 = "Indigo";
string COLOR_ConstraintProp_line_actor1 = "SandyBrown";


string COLOR_TConstraintProp_line_actor1 = "SandyBrown";
string COLOR_TConstraintProp_line_actor2 = "SandyBrown";
string COLOR_TConstraintProp_line_actor3 = "SandyBrown";



//Inverse Kinematices Calculations
void calculate3Angle(int p1, int p2, int p3);


void colorSetting(int flag, string color)
{

	if (flag == 0)
	{
		COLOR_PlconeActor = "Moccasin";
		COLOR_CUconeActor = "DarkTurquoise";
		COLOR_Head_objActor = "Moccasin";
		COLOR_RarmActor = "Crimson";
		COLOR_RforearmActor = "Crimson";
		COLOR_ConstraintProp_sphere_actor = "Lime";

		COLOR_TConstraintProp_sphere_actor = "Red";
		COLOR_TConstraintProp_sphere_actor2 = "DeepSkyBlue";
		COLOR_TConstraintProp_sphere_actor3 = "Indigo";
		COLOR_ConstraintProp_line_actor1 = "SandyBrown";


		COLOR_TConstraintProp_line_actor1 = "SandyBrown";
		COLOR_TConstraintProp_line_actor2 = "SandyBrown";
		COLOR_TConstraintProp_line_actor3 = "SandyBrown";
		COLOR_RightHand_objActor = "Moccasin";
		COLOR_LarmActor = "Crimson";
		COLOR_LforearmActor = "Crimson";
		COLOR_LeftHand_objActor = "Moccasin";
		COLOR_RlulegActor = "Crimson";
		COLOR_RllegActor = "Crimson";
		COLOR_RF_objActor = "Moccasin";
		COLOR_LlulegActor = "Crimson";
		COLOR_LllegActor = "Crimson";
		COLOR_LF_objActor = "Moccasin";

	}
	else
	{
		COLOR_PlconeActor = color;
		COLOR_CUconeActor = color;
		COLOR_Head_objActor = color;
		COLOR_RarmActor = color;
		COLOR_RforearmActor = color;
		COLOR_ConstraintProp_sphere_actor = color;

		COLOR_TConstraintProp_sphere_actor = color;
		COLOR_TConstraintProp_sphere_actor2 = color;
		COLOR_TConstraintProp_sphere_actor3 = color;
		COLOR_ConstraintProp_line_actor1 = color;


		COLOR_TConstraintProp_line_actor1 = color;
		COLOR_TConstraintProp_line_actor2 = color;
		COLOR_TConstraintProp_line_actor3 = color;
		COLOR_RightHand_objActor = color;
		COLOR_LarmActor = color;
		COLOR_LforearmActor = color;
		COLOR_LeftHand_objActor = color;
		COLOR_RlulegActor = color;
		COLOR_RllegActor = color;
		COLOR_RF_objActor = color;
		COLOR_LlulegActor = color;
		COLOR_LllegActor = color;
		COLOR_LF_objActor = color;
	}

}


class vtkTimerCallback_Animation : public vtkCommand
{
public:
	vtkTimerCallback_Animation() = default;
	~vtkTimerCallback_Animation() = default;

	int timerId = 0;
	static vtkTimerCallback_Animation* New()
	{
		vtkTimerCallback_Animation* cb = new vtkTimerCallback_Animation;
		cb->TimerCount = 0;
		return cb;
	}

	virtual void Execute(vtkObject* caller, unsigned long eventId,
		void* vtkNotUsed(callData))
	{
		vtkRenderWindowInteractor* iren =
			dynamic_cast<vtkRenderWindowInteractor*>(caller);
		if (vtkCommand::TimerEvent == eventId)
		{
			++this->TimerCount;
		}
		if (TimerCount < frameCnt)
		{

			string savedName = "Frame/";
			savedName += std::to_string(currntIdx);
			savedName += "_";
			savedName += std::to_string(TimerCount);
			savedName += ".png";

			float theta = -90;
			float phi = 88;
			float radius = 40;

			if (first)
			{
				if (currntIdx > 0)
				{
					//Grid View
					// Create a sphere
					//vtkNew<vtkSphereSource> sphereSource;
					//sphereSource->SetCenter(-11.5, -2.5, -77.0);
					//sphereSource->SetRadius(40.0);
					//// Make the surface smooth.
					//sphereSource->SetPhiResolution(18);
					//sphereSource->SetThetaResolution(18);

					//vtkNew<vtkPolyDataMapper> mapper;
					//mapper->SetInputConnection(sphereSource->GetOutputPort());

					//vtkNew<vtkActor> actor;
					//actor->SetMapper(mapper);
					//actor->RotateX(90);
					//actor->GetProperty()->SetInterpolationToFlat();
					//actor->GetProperty()->SetOpacity(0.5);
					//actor->GetProperty()->SetRepresentationToWireframe();
					//actor->GetProperty()->SetColor(colors->GetColor3d("Azure").GetData());
					//mRenderer->AddActor(actor);


//					vtkNew<vtkNamedColors> colors;
//
//					// colors->SetColor("Bkg", 0.2, 0.3, 0.4);
//
//					vtkNew<vtkSphereSource> sphereSource;
//					sphereSource->SetCenter(.5, 0, 0);
//
//					unsigned int res = 18;
//					sphereSource->SetThetaResolution(res * 2);
//					sphereSource->SetPhiResolution(res);
//					sphereSource->Update();
//
//					vtkNew<vtkIdFilter> cellIdFilter;
//					cellIdFilter->SetInputConnection(sphereSource->GetOutputPort());
//					cellIdFilter->SetCellIds(true);
//					cellIdFilter->SetPointIds(false);
//#if VTK890
//					cellIdFilter->SetCellIdsArrayName("CellIds");
//#else
//					cellIdFilter->SetIdsArrayName("CellIds");
//#endif
//					cellIdFilter->Update();
//
//					//WriteDataSet(cellIdFilter->GetOutput(), "CellIdFilter.vtp");
//
//					vtkNew<vtkIdFilter> pointIdFilter;
//					pointIdFilter->SetInputConnection(cellIdFilter->GetOutputPort());
//					pointIdFilter->SetCellIds(false);
//					pointIdFilter->SetPointIds(true);
//#if VTK890
//					pointIdFilter->SetPointIdsArrayName("PointIds");
//#else
//					pointIdFilter->SetIdsArrayName("PointIds");
//#endif
//					pointIdFilter->Update();
//
//					vtkDataSet* sphereWithIds = pointIdFilter->GetOutput();
//
//					//WriteDataSet(sphereWithIds, "BothIdFilter.vtp");
//
//					vtkNew<vtkCubeSource> cubeSource;
//					cubeSource->Update();
//
//					vtkNew<vtkBox> implicitCube;
//					implicitCube->SetBounds(cubeSource->GetOutput()->GetBounds());
//
//					vtkNew<vtkClipPolyData> clipper;
//					clipper->SetClipFunction(implicitCube);
//					clipper->SetInputData(sphereWithIds);
//					clipper->InsideOutOn();
//					clipper->Update();
//
//					//WriteDataSet(clipper->GetOutput(), "clipper.vtp");
//
//					// Get the clipped cell ids
//					vtkPolyData* clipped = clipper->GetOutput();
//
//					std::cout << "There are " << clipped->GetNumberOfPoints()
//						<< " clipped points." << std::endl;
//					std::cout << "There are " << clipped->GetNumberOfCells() << " clipped cells."
//						<< std::endl;
//
//					//vtkIdTypeArray* clippedCellIds = dynamic_cast<vtkIdTypeArray*>(clipped->GetNumberOfCells()->GetArray("CellIds"));
//
//					//for (vtkIdType i = 0; i < clippedCellIds->GetNumberOfTuples(); i++)
//					//{
//					//	std::cout << "Clipped cell id " << i << " : " << clippedCellIds->GetValue(i)
//					//		<< std::endl;
//					//}
//
//					// Create a mapper and actor for clipped sphere
//
//					vtkSmartPointer<vtkTransform> translation = vtkSmartPointer<vtkTransform>::New();
//					translation->Translate(-12.0, 70.0, +20.0);
//
//					vtkNew<vtkPolyDataMapper> clippedMapper;
//					clippedMapper->SetInputConnection(clipper->GetOutputPort());
//					clippedMapper->ScalarVisibilityOff();
//
//
//					vtkNew<vtkActor> clippedActor;
//					clippedActor->SetMapper(clippedMapper);
//					clippedActor->RotateZ(90);
//					clippedActor->RotateY(90);
//					clippedActor->SetScale(60);
//					clippedActor->SetUserTransform(translation);
//					clippedActor->GetProperty()->SetOpacity(0.5);
//					clippedActor->GetProperty()->SetRepresentationToWireframe();
//					clippedActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//					// Create a mapper and actor for cube
//					vtkNew<vtkPolyDataMapper> cubeMapper;
//					cubeMapper->SetInputConnection(cubeSource->GetOutputPort());
//
//					vtkNew<vtkActor> cubeActor;
//					cubeActor->SetMapper(cubeMapper);
//
//					cubeActor->GetProperty()->SetRepresentationToWireframe();
//					cubeActor->GetProperty()->SetOpacity(0.5);
//					cubeActor->GetProperty()->SetColor(colors->GetColor3d("Blue").GetData());
//
//					mRenderer->UseHiddenLineRemovalOn();
//					mRenderer->AddActor(clippedActor);



					CHEST(poses[currntIdx - 1].chest[0], -1, 0, 0);
					CHEST(poses[currntIdx - 1].chest[1], 0, -1, 0);
					CHEST(poses[currntIdx - 1].chest[2], 0, 0, 1);

					lla(poses[currntIdx - 1].lla[0], -1, 0, 0);
					lla(poses[currntIdx - 1].lla[1], 0, 1, 0); 
					lla(poses[currntIdx - 1].lla[2], 0, 0, 1);

					rla(poses[currntIdx - 1].rla[0], -1, 0, 0);
					rla(poses[currntIdx - 1].rla[1], 0, 1, 0);
					rla(poses[currntIdx - 1].rla[2], 0, 0, -1);

					rua(poses[currntIdx - 1].rua[0], -1, 0, 0);
					rua(poses[currntIdx - 1].rua[1], 0, 1, 0);
					rua(poses[currntIdx - 1].rua[2], 0, 0, -1);

					lua(poses[currntIdx - 1].lua[0], -1, 0, 0);
					lua(poses[currntIdx - 1].lua[1], 0, 1, 0);
					lua(poses[currntIdx - 1].lua[2], 0, 0, 1);

					lll(poses[currntIdx - 1].lll[0], -1, 0, 0);
					lll(poses[currntIdx - 1].lll[1], 0, 1, 0);
					lll(poses[currntIdx - 1].lll[2], 0, 0, 1);

					lul(poses[currntIdx - 1].lul[0], -1, 0, 0);
					lul(poses[currntIdx - 1].lul[1], 0, 1, 0);
					lul(poses[currntIdx - 1].lul[2], 0, 0, 1);


					rll(poses[currntIdx - 1].rll[0], -1, 0, 0);
					rll(poses[currntIdx - 1].rll[1], 0, 1, 0);
					rll(poses[currntIdx - 1].rll[2], 0, 0, -1);

					rul(poses[currntIdx - 1].rul[0], -1, 0, 0);
					rul(poses[currntIdx - 1].rul[1], 0, 1, 0);
					rul(poses[currntIdx - 1].rul[2], 0, 0, -1);


					//if (poses[currntIdx - 1].chest[0] > 0) {
					//	currentMove.chest[0] = poses[currntIdx].chest[0] - poses[currntIdx - 1].chest[0];
					//}
					//else
					//{
					//	currentMove.chest[0] = poses[currntIdx].chest[0] + poses[currntIdx - 1].chest[0];
					//}

					currentMove.chest[0] = poses[currntIdx].chest[0] - poses[currntIdx - 1].chest[0];
					currentMove.chest[1] = poses[currntIdx].chest[1] - poses[currntIdx - 1].chest[1];
					currentMove.chest[2] = poses[currntIdx].chest[2] - poses[currntIdx - 1].chest[2];


					currentMove.rua[0] = poses[currntIdx].rua[0] - poses[currntIdx - 1].rua[0];
					currentMove.rua[1] = poses[currntIdx].rua[1] - poses[currntIdx - 1].rua[1];
					currentMove.rua[2] = poses[currntIdx].rua[2] - poses[currntIdx - 1].rua[2];

					currentMove.rla[0] = poses[currntIdx].rla[0] - poses[currntIdx - 1].rla[0];
					currentMove.rla[1] = poses[currntIdx].rla[1] - poses[currntIdx - 1].rla[1];
					currentMove.rla[2] = poses[currntIdx].rla[2] - poses[currntIdx - 1].rla[2];


					currentMove.lua[0] = poses[currntIdx].lua[0] - poses[currntIdx - 1].lua[0];
					currentMove.lua[1] = poses[currntIdx].lua[1] - poses[currntIdx - 1].lua[1];
					currentMove.lua[2] = poses[currntIdx].lua[2] - poses[currntIdx - 1].lua[2];

					currentMove.lla[0] = poses[currntIdx].lla[0] - poses[currntIdx - 1].lla[0];
					currentMove.lla[1] = poses[currntIdx].lla[1] - poses[currntIdx - 1].lla[1];
					currentMove.lla[2] = poses[currntIdx].lla[2] - poses[currntIdx - 1].lla[2];

					currentMove.rul[0] = poses[currntIdx].rul[0] - poses[currntIdx - 1].rul[0];
					currentMove.rul[1] = poses[currntIdx].rul[1] - poses[currntIdx - 1].rul[1];
					currentMove.rul[2] = poses[currntIdx].rul[2] - poses[currntIdx - 1].rul[2];

					currentMove.rll[0] = poses[currntIdx].rll[0] - poses[currntIdx - 1].rll[0];
					currentMove.rll[1] = poses[currntIdx].rll[1] - poses[currntIdx - 1].rll[1];
					currentMove.rll[2] = poses[currntIdx].rll[2] - poses[currntIdx - 1].rll[2];

				}
				
				//CHST
				if (currentMove.chest[0] != 0)
				{
					COLOR_CUconeActor = "Yellow";
					jointIncrease.chest[0] = currentMove.chest[0] / frameCnt;	 //증가값 지정 
				}

				if (currentMove.chest[1] != 0)
				{
					COLOR_CUconeActor = "Yellow";
					jointIncrease.chest[1] = currentMove.chest[1] / frameCnt;
				}

				if (currentMove.chest[2] != 0)
				{
					COLOR_CUconeActor = "Yellow";
					jointIncrease.chest[2] = currentMove.chest[2] / frameCnt;
				}

				//Right Upper Arm
				if (currentMove.rua[0] != 0)
				{
					COLOR_RarmActor = "Yellow";
					jointIncrease.rua[0] = currentMove.rua[0] / frameCnt;
				}

				if (currentMove.rua[1] != 0)
				{
					COLOR_RarmActor = "Yellow";
					jointIncrease.rua[1] = currentMove.rua[1] / frameCnt;
				}

				if (currentMove.rua[2] != 0)
				{
					COLOR_RarmActor = "Yellow";
					jointIncrease.rua[2] = currentMove.rua[2] / frameCnt;
				}

				//Right Lower Arm
				if (currentMove.rla[0] != 0)
				{
					COLOR_RforearmActor = "Yellow";
					jointIncrease.rla[0] = currentMove.rla[0] / frameCnt;
				}

				if (currentMove.rla[1] != 0)
				{
					COLOR_RforearmActor = "Yellow";
					jointIncrease.rla[1] = currentMove.rla[1] / frameCnt;
				}

				if (currentMove.rla[2] != 0)
				{
					COLOR_RforearmActor = "Yellow";
					jointIncrease.rla[2] = currentMove.rla[2] / frameCnt;
				}

				//Left upper Arm
				if (currentMove.lua[0] != 0)
				{
					COLOR_LarmActor = "Yellow";
					jointIncrease.lua[0] = currentMove.lua[0] / frameCnt;
				}

				if (currentMove.lua[1] != 0)
				{
					COLOR_LarmActor = "Yellow";
					jointIncrease.lua[1] = currentMove.lua[1] / frameCnt;
				}

				if (currentMove.lua[2] != 0)
				{
					COLOR_LarmActor = "Yellow";
					jointIncrease.lua[2] = currentMove.lua[2] / frameCnt;
				}

				
				//Left lower Arm
				if (currentMove.lla[0] != 0)
				{
					COLOR_LforearmActor = "Yellow";
					jointIncrease.lla[0] = currentMove.lla[0] / frameCnt;
				}

				if (currentMove.lla[1] != 0)
				{
					COLOR_LforearmActor = "Yellow";
					jointIncrease.lla[1] = currentMove.lla[1] / frameCnt;
				}

				if (currentMove.lla[2] != 0)
				{
					COLOR_LforearmActor = "Yellow";
					jointIncrease.lla[2] = currentMove.lla[2] / frameCnt;
				}
				

				//Right upper Leg
				if (currentMove.rul[0] != 0)
				{
					COLOR_RlulegActor = "Yellow";
					jointIncrease.rul[0] = currentMove.rul[0] / frameCnt;
				}

				if (currentMove.rul[1] != 0)
				{
					COLOR_RlulegActor = "Yellow";
					jointIncrease.rul[1] = currentMove.rul[1] / frameCnt;
				}

				if (currentMove.rul[2] != 0)
				{
					COLOR_RlulegActor = "Yellow";
					jointIncrease.rul[2] = currentMove.rul[2] / frameCnt;
				}

				//Right lower Leg
				if (currentMove.rll[0] != 0)
				{
					COLOR_RllegActor = "Yellow";
					jointIncrease.rll[0] = currentMove.rll[0] / frameCnt;
				}

				if (currentMove.rll[1] != 0)
				{
					COLOR_RllegActor = "Yellow";
					jointIncrease.rll[1] = currentMove.rll[1] / frameCnt;
				}

				if (currentMove.rll[2] != 0)
				{
					COLOR_RllegActor = "Yellow";
					jointIncrease.rll[2] = currentMove.rll[2] / frameCnt;
				}

				//left upper Leg
				if (currentMove.lul[0] != 0)
				{
					COLOR_LlulegActor = "Yellow";
					jointIncrease.lul[0] = currentMove.lul[0] / frameCnt;
				}

				if (currentMove.lul[1] != 0)
				{
					COLOR_LlulegActor = "Yellow";
					jointIncrease.lul[1] = currentMove.lul[1] / frameCnt;
				}

				if (currentMove.lul[2] != 0)
				{
					COLOR_LlulegActor = "Yellow";
					jointIncrease.lul[2] = currentMove.lul[2] / frameCnt;
				}

				//left lower Leg
				if (currentMove.lll[0] != 0)
				{
					COLOR_LllegActor = "Yellow";
					jointIncrease.lll[0] = currentMove.lll[0] / frameCnt;
				}

				if (currentMove.lll[1] != 0)
				{
					COLOR_LllegActor = "Yellow";
					jointIncrease.lll[1] = currentMove.lll[1] / frameCnt;
				}

				if (currentMove.lll[2] != 0)
				{
					COLOR_LllegActor = "Yellow";
					jointIncrease.lll[2] = currentMove.lll[2] / frameCnt;
				}

				first = false;

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());

			
			}


			////////////  CHEST
			if (currentMove.chest[0] != 0)
			{
				increaseAngle = abs(jointIncrease.chest[0]);
				decreseAngle = abs(jointIncrease.chest[0]) * -1;

				if (currentMove.chest[0] > 0)
				{
					CUconeTransform->RotateWXYZ(increaseAngle, -1, 0, 0);
					currentMove.chest[0] -= increaseAngle;
				}
				else
				{
					CUconeTransform->RotateWXYZ(decreseAngle, -1, 0, 0);
					currentMove.chest[0] += abs(decreseAngle);
				}
			}

			if (currentMove.chest[1] != 0)
			{
				increaseAngle = abs(jointIncrease.chest[1]);
				decreseAngle = abs(jointIncrease.chest[1]) * -1;

				if (currentMove.chest[1] > 0)
				{
					CUconeTransform->RotateWXYZ(increaseAngle, 0, -1, 0);
					currentMove.chest[1] -= increaseAngle;
				}
				else
				{
					CUconeTransform->RotateWXYZ(decreseAngle, 0, -1, 0);
					currentMove.chest[1] += abs(decreseAngle);
				}
			}
			if (currentMove.chest[2] != 0)
			{
				increaseAngle = abs(jointIncrease.chest[2]);
				decreseAngle = abs(jointIncrease.chest[2]) * -1;

				if (currentMove.chest[2] > 0)
				{
					CUconeTransform->RotateWXYZ(increaseAngle, 0, 0, 1);
					currentMove.chest[2] -= increaseAngle;
				}
				else
				{
					CUconeTransform->RotateWXYZ(decreseAngle, 0, 0, 1);
					currentMove.chest[2] += abs(decreseAngle);
				}

			}

			////////////  Right Upper Arm
			if (currentMove.rua[0] != 0)
			{
				increaseAngle = abs(jointIncrease.rua[0]);
				decreseAngle = abs(jointIncrease.rua[0]) * -1;
				if (currentMove.rua[0] > 0)
				{
					RarmTransform->RotateWXYZ(increaseAngle, -1, 0, 0);
					currentMove.rua[0] -= increaseAngle;
				}
				else
				{
					RarmTransform->RotateWXYZ(decreseAngle, -1, 0, 0);
					currentMove.rua[0] += abs(decreseAngle);
				}
			}
			if (currentMove.rua[1] != 0)
			{
				increaseAngle = abs(jointIncrease.rua[1]);
				decreseAngle = abs(jointIncrease.rua[1]) * -1;

				if (currentMove.rua[1] > 0)
				{
					RarmTransform->RotateWXYZ(increaseAngle, 0, -1, 0);
					currentMove.rua[1] -= increaseAngle;
				}
				else
				{
					RarmTransform->RotateWXYZ(decreseAngle, 0, -1, 0);
					currentMove.rua[1] += abs(decreseAngle);
				}

			}

			if (currentMove.rua[2] != 0)
			{
				increaseAngle = abs(jointIncrease.rua[2]);
				decreseAngle = abs(jointIncrease.rua[2]) * -1;

				if (currentMove.rua[2] > 0)
				{
					RarmTransform->RotateWXYZ(increaseAngle, 0, 0, -1);
					currentMove.rua[2] -= increaseAngle;
				}
				else
				{
					RarmTransform->RotateWXYZ(decreseAngle, 0, 0, -1);
					currentMove.rua[2] += abs(decreseAngle);
				}
			}

			////////////  Right Lower Arm
			if (currentMove.rla[0] != 0)
			{

				increaseAngle = abs(jointIncrease.rla[0]);
				decreseAngle = abs(jointIncrease.rla[0]) * -1;


				if (currentMove.rla[0] > 0)
				{
					RforearmTransform->RotateWXYZ(increaseAngle, -1, 0, 0);
					currentMove.rla[0] -= increaseAngle;
				}
				else
				{
					RforearmTransform->RotateWXYZ(decreseAngle, -1, 0, 0);
					currentMove.rla[0] += abs(decreseAngle);
				}
			}
			if (currentMove.rla[1] != 0)
			{
				increaseAngle = abs(jointIncrease.rla[1]);
				decreseAngle = abs(jointIncrease.rla[1]) * -1;

				if (currentMove.rla[1] > 0)
				{
					RforearmTransform->RotateWXYZ(increaseAngle, 0, -1, 0);
					currentMove.rla[1] -= increaseAngle;
				}
				else
				{
					RforearmTransform->RotateWXYZ(decreseAngle, 0, -1, 0);
					currentMove.rla[1] += abs(decreseAngle);
				}

			}
			if (currentMove.rla[2] != 0)
			{
				increaseAngle = abs(jointIncrease.rla[2]);
				decreseAngle = abs(jointIncrease.rla[2]) * -1;

				if (currentMove.rla[2] > 0)
				{
					RforearmTransform->RotateWXYZ(increaseAngle, 0, 0, -1);
					currentMove.rla[2] -= increaseAngle;
				}
				else
				{
					RforearmTransform->RotateWXYZ(decreseAngle, 0, 0, -1);
					currentMove.rla[2] += abs(decreseAngle);
				}
			}

			////////////  Left upper Arm
			if (currentMove.lua[0] != 0)
			{
				increaseAngle = abs(jointIncrease.lua[0]);
				decreseAngle = abs(jointIncrease.lua[0]) * -1;

				if (currentMove.lua[0] > 0)
				{
					LarmTransform->RotateWXYZ(increaseAngle, -1, 0, 0);
					currentMove.lua[0] -= increaseAngle;
				}
				else
				{
					LarmTransform->RotateWXYZ(decreseAngle, -1, 0, 0);
					currentMove.lua[0] += abs(decreseAngle);
				}
			}
			if (currentMove.lua[1] != 0)
			{
				increaseAngle = abs(jointIncrease.lua[1]);
				decreseAngle = abs(jointIncrease.lua[1]) * -1;

				if (currentMove.lua[1] > 0)
				{
					LarmTransform->RotateWXYZ(increaseAngle, 0, -1, 0);
					currentMove.lua[1] -= increaseAngle;
				}
				else
				{
					LarmTransform->RotateWXYZ(decreseAngle, 0, -1, 0);
					currentMove.lua[1] += abs(decreseAngle);
				}

			}
			if (currentMove.lua[2] != 0)
			{
				increaseAngle = abs(jointIncrease.lua[2]);
				decreseAngle = abs(jointIncrease.lua[2]) * -1;

				if (currentMove.lua[2] > 0)
				{
					LarmTransform->RotateWXYZ(increaseAngle, 0, 0, 1);
					currentMove.lua[2] -= increaseAngle;
				}
				else
				{
					LarmTransform->RotateWXYZ(decreseAngle, 0, 0, 1);
					currentMove.lua[2] += abs(decreseAngle);
				}
			}

			////////////  Left Lower Arm
			if (currentMove.lla[0] != 0)
			{
				increaseAngle = abs(jointIncrease.lla[0]);
				decreseAngle = abs(jointIncrease.lla[0]) * -1;

				if (currentMove.lla[0] > 0)
				{
					LforearmTransform->RotateWXYZ(increaseAngle, -1, 0, 0);
					currentMove.lla[0] -= increaseAngle;
				}
				else
				{
					LforearmTransform->RotateWXYZ(decreseAngle, -1, 0, 0);
					currentMove.lla[0] += abs(decreseAngle);
				}
			}
			if (currentMove.lla[1] != 0)
			{
				increaseAngle = abs(jointIncrease.lla[1]);
				decreseAngle = abs(jointIncrease.lla[1]) * -1;

				if (currentMove.lla[1] > 0)
				{
					LforearmTransform->RotateWXYZ(increaseAngle, 0, -1, 0);
					currentMove.lla[1] -= increaseAngle;
				}
				else
				{
					LforearmTransform->RotateWXYZ(decreseAngle, 0, -1, 0);
					currentMove.lla[1] += abs(decreseAngle);
				}

			}
			if (currentMove.lla[2] != 0)
			{
				increaseAngle = abs(jointIncrease.lla[2]);
				decreseAngle = abs(jointIncrease.lla[2]) * -1;

				if (currentMove.lla[2] > 0)
				{
					LforearmTransform->RotateWXYZ(increaseAngle, 0, 0, 1);
					currentMove.lla[2] -= increaseAngle;
				}
				else
				{
					LforearmTransform->RotateWXYZ(decreseAngle, 0, 0, 1);
					currentMove.lla[2] += abs(decreseAngle);
				}
			}

			////////////  Right Upper Leg
			if (currentMove.rul[0] != 0)
			{
				increaseAngle = abs(jointIncrease.rul[0]);
				decreseAngle = abs(jointIncrease.rul[0]) * -1;

				if (currentMove.rul[0] > 0)
				{
					RlulegTransform->RotateWXYZ(increaseAngle, -1, 0, 0);
					currentMove.rul[0] -= increaseAngle;
				}
				else
				{
					RlulegTransform->RotateWXYZ(decreseAngle, -1, 0, 0);
					currentMove.rul[0] += abs(decreseAngle);
				}
			}
			if (currentMove.rul[1] != 0)
			{
				increaseAngle = abs(jointIncrease.rul[1]);
				decreseAngle = abs(jointIncrease.rul[1]) * -1;

				if (currentMove.rul[1] > 0)
				{
					RlulegTransform->RotateWXYZ(increaseAngle, 0, -1, 0);
					currentMove.rul[1] -= increaseAngle;
				}
				else
				{
					RlulegTransform->RotateWXYZ(decreseAngle, 0, -1, 0);
					currentMove.rul[1] += abs(decreseAngle);
				}

			}
			if (currentMove.rul[2] != 0)
			{
				increaseAngle = abs(jointIncrease.rul[2]);
				decreseAngle = abs(jointIncrease.rul[2]) * -1;

				if (currentMove.rul[2] > 0)
				{
					RlulegTransform->RotateWXYZ(increaseAngle, 0, 0, -1);
					currentMove.rul[2] -= increaseAngle;
				}
				else
				{
					RlulegTransform->RotateWXYZ(decreseAngle, 0, 0, -1);
					currentMove.rul[2] += abs(decreseAngle);
				}
			}

			////////////  Right Lower Leg
			if (currentMove.rll[0] != 0)
			{
				increaseAngle = abs(jointIncrease.rll[0]);
				decreseAngle = abs(jointIncrease.rll[0]) * -1;

				if (currentMove.rll[0] > 0)
				{
					RllegTransform->RotateWXYZ(increaseAngle, -1, 0, 0);
					currentMove.rll[0] -= increaseAngle;
				}
				else
				{
					RllegTransform->RotateWXYZ(decreseAngle, -1, 0, 0);
					currentMove.rll[0] += abs(decreseAngle);
				}
			}
			if (currentMove.rll[1] != 0)
			{
				increaseAngle = abs(jointIncrease.rll[1]);
				decreseAngle = abs(jointIncrease.rll[1]) * -1;

				if (currentMove.rll[1] > 0)
				{
					RllegTransform->RotateWXYZ(increaseAngle, 0, -1, 0);
					currentMove.rll[1] -= increaseAngle;
				}
				else
				{
					RllegTransform->RotateWXYZ(decreseAngle, 0, -1, 0);
					currentMove.rll[1] += abs(decreseAngle);
				}

			}
			if (currentMove.rll[2] != 0)
			{
				increaseAngle = abs(jointIncrease.rll[2]);
				decreseAngle = abs(jointIncrease.rll[2]) * -1;

				if (currentMove.rll[2] > 0)
				{
					RllegTransform->RotateWXYZ(increaseAngle, 0, 0, -1);
					currentMove.rll[2] -= increaseAngle;
				}
				else
				{
					RllegTransform->RotateWXYZ(decreseAngle, 0, 0, -1);
					currentMove.rll[2] += abs(decreseAngle);
				}
			}
			////////////  Left upper LEG
			if (currentMove.lul[0] != 0)
			{
				if (currentMove.lul[0] > 0)
				{
					LlulegTransform->RotateWXYZ(increaseAngle, -1, 0, 0);
					currentMove.lul[0] -= increaseAngle;
				}
				else
				{
					LlulegTransform->RotateWXYZ(decreseAngle, -1, 0, 0);
					currentMove.lul[0] += abs(decreseAngle);
				}
			}
			if (currentMove.lul[1] != 0)
			{
				if (currentMove.lul[1] > 0)
				{
					LlulegTransform->RotateWXYZ(increaseAngle, 0, -1, 0);
					currentMove.lul[1] -= increaseAngle;
				}
				else
				{
					LlulegTransform->RotateWXYZ(decreseAngle, 0, -1, 0);
					currentMove.lul[1] += abs(decreseAngle);
				}

			}
			if (currentMove.lul[2] != 0)
			{
				if (currentMove.lul[2] > 0)
				{
					LlulegTransform->RotateWXYZ(increaseAngle, 0, 0, 1);
					currentMove.lul[2] -= increaseAngle;
				}
				else
				{
					LlulegTransform->RotateWXYZ(decreseAngle, 0, 0, 1);
					currentMove.lul[2] += abs(decreseAngle);
				}
			}
			////////////  Left upper LEG
			if (currentMove.lll[0] != 0)
			{
				if (currentMove.lll[0] > 0)
				{
					LllegTransform->RotateWXYZ(increaseAngle, -1, 0, 0);
					currentMove.lll[0] -= increaseAngle;
				}
				else
				{
					LllegTransform->RotateWXYZ(decreseAngle, -1, 0, 0);
					currentMove.lll[0] += abs(decreseAngle);
				}
			}
			if (currentMove.lll[1] != 0)
			{
				if (currentMove.lll[1] > 0)
				{
					LllegTransform->RotateWXYZ(increaseAngle, 0, -1, 0);
					currentMove.lll[1] -= increaseAngle;
				}
				else
				{
					LllegTransform->RotateWXYZ(decreseAngle, 0, -1, 0);
					currentMove.lll[1] += abs(decreseAngle);
				}

			}
			if (currentMove.lll[2] != 0)
			{
				if (currentMove.lll[2] > 0)
				{
					LllegTransform->RotateWXYZ(increaseAngle, 0, 0, 1);
					currentMove.lll[2] -= increaseAngle;
				}
				else
				{
					LllegTransform->RotateWXYZ(decreseAngle, 0, 0, 1);
					currentMove.lll[2] += abs(decreseAngle);
				}
			}
			


			if (currntIdx == drawIdx)
			{
				if (b_leftHand)
				{
					double leftdata[3] = { 0,0,0 };
					LeftHand_ObjReader_Transform->GetPosition(leftdata);

					vtkNew<vtkSphereSource> sphereSource1;
					vtkNew<vtkPolyDataMapper> mapper1;
					vtkNew<vtkActor> actor1;


					sphereSource1->SetCenter(leftdata[0], leftdata[1], leftdata[2]);
					sphereSource1->SetRadius(1);
					// Make the surface smooth.
					sphereSource1->SetPhiResolution(18);
					sphereSource1->SetThetaResolution(18);


					mapper1->SetInputConnection(sphereSource1->GetOutputPort());


					actor1->SetMapper(mapper1);
					actor1->GetProperty()->SetColor(colors->GetColor3d("Firebrick").GetData());
					actor1->GetProperty()->SetOpacity((double)((double)(100 / frameCnt * TimerCount) / 100));
					mRenderer->AddActor(actor1);
				}

				if (b_rightHand)
				{
					double rightdata[3] = { 0,0,0 };
					RightHand_ObjReader_Transform->GetPosition(rightdata);

					vtkNew<vtkSphereSource> sphereSource2;
					vtkNew<vtkPolyDataMapper> mapper2;
					vtkNew<vtkActor> actor2;


					sphereSource2->SetCenter(rightdata[0], rightdata[1], rightdata[2]);
					sphereSource2->SetRadius(1);
					// Make the surface smooth.
					sphereSource2->SetPhiResolution(18);
					sphereSource2->SetThetaResolution(18);


					mapper2->SetInputConnection(sphereSource2->GetOutputPort());


					actor2->SetMapper(mapper2);
					actor2->GetProperty()->SetColor(colors->GetColor3d("Firebrick").GetData());
					actor2->GetProperty()->SetOpacity((double)((double)(100 / frameCnt * TimerCount) / 100));
					mRenderer->AddActor(actor2);

				}

				if (b_rightFoot)
				{
					double rightdata[3] = { 0,0,0 };
					RF_ObjReader_Transform->GetPosition(rightdata);

					vtkNew<vtkSphereSource> sphereSource3;
					vtkNew<vtkPolyDataMapper> mapper3;
					vtkNew<vtkActor> actor3;


					sphereSource3->SetCenter(rightdata[0], rightdata[1], rightdata[2]);
					sphereSource3->SetRadius(1);
					// Make the surface smooth.
					sphereSource3->SetPhiResolution(18);
					sphereSource3->SetThetaResolution(18);


					mapper3->SetInputConnection(sphereSource3->GetOutputPort());


					actor3->SetMapper(mapper3);
					actor3->GetProperty()->SetColor(colors->GetColor3d("Firebrick").GetData());
					actor3->GetProperty()->SetOpacity((double)((double)(100 / frameCnt * TimerCount) / 100));
					mRenderer->AddActor(actor3);
				}

			}
			if (b_saveImage)
			{
				vtkNew<vtkWindowToImageFilter> windowToImageFilter;
				windowToImageFilter->SetInput(iren->GetRenderWindow());
#if VTK_MAJOR_VERSION >= 8 || VTK_MAJOR_VERSION == 8 && VTK_MINOR_VERSION >= 90
				windowToImageFilter->SetScale(2); // image quality
#else
				windowToImageFilter->SetMagnification(2); // image quality
#endif
				windowToImageFilter->SetInputBufferTypeToRGBA(); // also record the alpha
																 // (transparency) channel
				windowToImageFilter->ReadFrontBufferOff();       // read from the back buffer
				windowToImageFilter->Update();

				vtkNew<vtkPNGWriter> writer;
				writer->SetFileName(savedName.c_str());
				writer->SetInputConnection(windowToImageFilter->GetOutputPort());
				writer->Write();
			}



			iren->GetRenderWindow()->Render();
			//mRenderer->RemoveActor(actor1);
		}
		else
		{	
			iren->DestroyTimer();
			std::cout << "Destroy" << std::endl;
		}
	}

private:
	int TimerCount = 0;
	int TotalCnt = 100;
	float increaseAngle = 2;
	float decreseAngle = -2;
	bool first = true;

public:
	int frameCnt = 10;
	JointMove jointIncrease2;
	JointMove jointIncrease;
	JointMove currentMove;
	std::vector<JointMove> poses;
	int currntIdx = 0;

};

namespace {

	// Define interaction style
	class customMouseInteractorStyle : public vtkInteractorStyleTrackballActor
	{

	public:
		static customMouseInteractorStyle* New(); vtkTypeMacro(customMouseInteractorStyle, vtkInteractorStyleTrackballActor);

		
		bool b_targetSelect = false;
		int oldX, oldY;
		vtkActor* tartget;
		vtkActor* RUA;
		vtkActor* RLA;
		vtkActor* LUA;
		vtkActor* LLA;
		vtkActor* RUL;
		vtkActor* RLL;
		vtkActor* LUL;
		vtkActor* LLL;
		vtkActor* chestActor;
		vtkActor* headActor;
		vtkActor* LH_Actor;
		vtkActor* RH_Actor;
		vtkActor* LL_Actor;
		vtkActor* RL_Actor;
		vtkActor* Upper_chestActor;
		vtkActor* pelvisActor;

		vtkActor* RF_xposActor;
		vtkActor* RF_yposActor;
		vtkActor* RF_zposActor;

		vtkActor* RH_xposActor;
		vtkActor* RH_yposActor;
		vtkActor* RH_zposActor;

		vtkActor* RLA_xrotActor;
		vtkActor* RLA_yrotActor;
		vtkActor* RLA_zrotActor;

		vtkActor* RLL_xrotActor;
		vtkActor* RLL_yrotActor;
		vtkActor* RLL_zrotActor;

		vtkActor* XAX;
		vtkActor* YAX;
		vtkActor* ZAX;

		vtkActor* pJS;
		vtkActor* cJS;

		vtkActor* luaJS;
		vtkActor* llaJS;

		vtkActor* ruaJS;
		vtkActor* rlaJS;

		vtkActor* lulJS;
		vtkActor* lllJS;

		vtkActor* rulJS;
		vtkActor* rllJS;

		vtkActor* SM_pelvisActor; // 0
		vtkActor* SM_CH0; // 1
		vtkActor* SM_CH1; // 
		vtkActor* SM_CH2; // 
		vtkActor* SM_CH3; // 
		vtkActor* SM_headActor; // 
		vtkActor* SM_RUA; // 2
		vtkActor* SM_RLA; // 3
		vtkActor* SM_RH_Actor; // 10 and 109
		vtkActor* SM_LUA; // 4
		vtkActor* SM_LLA; // 5
		vtkActor* SM_LH_Actor; // 15 and 112
		vtkActor* SM_RUL; //6
		vtkActor* SM_RLL; //7
		vtkActor* SM_RF_Actor; // 16 and 115
		vtkActor* SM_LUL; //8
		vtkActor* SM_LLL; //9
		vtkActor* SM_LF_Actor; // 21 and 118

		vtkActor* ffIK_pelvisActor; // 500
		vtkActor* ffIK_CH0; // 501
		vtkActor* ffIK_CH1; //
		vtkActor* ffIK_CH2; // 
		vtkActor* ffIK_CH3; //
		vtkActor* ffIK_headActor; // 
		vtkActor* ffIK_RUA; // 502
		vtkActor* ffIK_RLA; // 503
		vtkActor* ffIK_RH; // 50 and 510
		vtkActor* ffIK_LUA; // 504
		vtkActor* ffIK_LLA; // 505
		vtkActor* ffIK_LH; // 51 and 511
		vtkActor* ffIK_RUL; // 506
		vtkActor* ffIK_RLL; // 507
		vtkActor* ffIK_RF_Actor; // 52 and 512
		vtkActor* ffIK_LUL; // 508
		vtkActor* ffIK_LLL; // 509
		vtkActor* ffIK_LF_Actor; // 53 and 513


		vtkActor* freeRightUL_Actor; // 2001
		vtkActor* freeRightLL_Actor; // 2002
		vtkActor* freeRightFoot_Actor; // 2003

		vtkActor* freeLeftUL_Actor; // 1001
		vtkActor* freeLeftLL_Actor; // 1002
		vtkActor* freeLeftFoot_Actor; // 1003

		vtkActor* ConsProp_sphere_actor; //91
		vtkActor* TConsProp_sphere_actor; //9100
		vtkActor* TConsProp_sphere_actor2; //9200
		vtkActor* TConsProp_sphere_actor3; //9300
		vtkActor* ConsProp_line_actor; //92
		vtkActor* TConsProp_line_actor; //9001
		vtkActor* TConsProp_line_actor2; //9002
		vtkActor* TConsProp_line_actor3; //9003

		vtkActor* ConsProp_plane_actor; //93
		vtkActor* ConsProp_cube_actor; //94



		int state = 0;
		bool Move;
		bool press;
		int screenX, screenY;
		int screenDiff, screenTemp, screenPrev;








		void moveSphereProp(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			ConstraintProp_sphere_transform->Translate(x, y, z);
			mRenderWindow->Render();
		}

		void TmoveSphereProp(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			TConstraintProp_sphere_transform->Translate(x, y, z);
			mRenderWindow->Render();
		}

		void TmoveSphereProp2(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			TConstraintProp_sphere_transform2->Translate(x, y, z);
			mRenderWindow->Render();
		}

		void TmoveSphereProp3(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			TConstraintProp_sphere_transform3->Translate(x, y, z);
			mRenderWindow->Render();
		}


		void moveLineProp(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			ConstraintProp_line_transform->Translate(x, y, z);
			ConstraintProp_line_transform1->Translate(x, y, z);
			cout << "Inrusion=" << RUA_collide->GetNumberOfContacts() << endl;

			TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("Teal").GetData());


			mRenderWindow->Render();
		}


		void TmoveLineProp(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			//TConstraintProp_line_transform->Translate(x, y, z);
			TConstraintProp_line_transform1->Translate(x, y, z);
			//cout << "Inrusion=" << RUA_collide->GetNumberOfContacts() << endl;
			mRenderWindow->Render();
			TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d("Teal").GetData());
			TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
		}


		void TmoveLineProp2(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			//TConstraintProp_line_transform->Translate(x, y, z);
			TConstraintProp_line_transform2->Translate(x, y, z);
			//cout << "Inrusion=" << RUA_collide->GetNumberOfContacts() << endl;

			TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());

			mRenderWindow->Render();
		}


		void TmoveLineProp3(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			//TConstraintProp_line_transform->Translate(x, y, z);
			TConstraintProp_line_transform3->Translate(x, y, z);
			//cout << "Inrusion=" << RUA_collide->GetNumberOfContacts() << endl;
			mRenderWindow->Render();
			TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
			TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("Teal").GetData());
			ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
		}


		void movePlaneProp(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			ConstraintProp_plane_transform->Translate(x, y, z);
			mRenderWindow->Render();
		}
		void moveCubeProp(int x, int y, int z)
		{
			cout << "x=" << x << "\t" << "y=" << y << endl;
			////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
			//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
			ConstraintProp_cube_transform->Translate(x, y, z);
			mRenderWindow->Render();
		}

		int prevX = 0;
		int prevY = 0;

		double x;
		double y;
		double z;

		double xpos = 0.0;
		double ypos = 0.0;
		double zpos = 0.0;
		int temp = 0;
		int diff;


		void compute(int A, int x, int y, int z, int bid)
		{
			axis.x = x; axis.y = y; axis.z = z;
			int angle = A;
			if (axis.x == 1 || axis.x == -1)
			{

				qx[bid].setW(cos(angle * PI / 180 / 2));
				qx[bid].setX(axis.x * sin(angle * PI / 180 / 2));
				qx[bid].setY(0 * sin(angle * PI / 180 / 2));
				qx[bid].setZ(0 * sin(angle * PI / 180 / 2));

				/*	qy[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
					qy[bid].setX(0);
					qy[bid].setY(sin(0 / 2));
					qy[bid].setZ(sin(0 / 2));

					qz[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
					qz[bid].setX(0);
					qz[bid].setY(sin(0 / 2));
					qz[bid].setZ(sin(0 / 2));*/

				xaxisQX[bid].setW(cos(angle * PI / 180 / 2));
				xaxisQX[bid].setX(axis.x * sin(angle * PI / 180 / 2));
				xaxisQX[bid].setY(0 * sin(angle * PI / 180 / 2));
				xaxisQX[bid].setZ(0 * sin(angle * PI / 180 / 2));

				xaxisQY[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQY[bid].setX(0);
				xaxisQY[bid].setY(sin(0 / 2));
				xaxisQY[bid].setZ(sin(0 / 2));

				xaxisQZ[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQZ[bid].setX(0);
				xaxisQZ[bid].setY(sin(0 / 2));
				xaxisQZ[bid].setZ(sin(0 / 2));

				xaxisQP[bid] = xaxisQX[bid].multiply(xaxisQY[bid].multiply(xaxisQZ[bid]));
				cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << xaxisQP[bid].getW() << "\t" << "X=" << xaxisQP[bid].getX() << "\t" << "Y=" << xaxisQP[bid].getY() << "\t" << "Z=" << xaxisQP[bid].getZ() << "\n";



				dummy1 = A;
				dummy2 = 0;
				dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

			}
			if (axis.z == 1 || axis.z == -1)
			{



				/*	qy[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
					qy[bid].setX(0);
					qy[bid].setY(sin(0 / 2));
					qy[bid].setZ(sin(0 / 2));

					qx[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
					qx[bid].setX(0);
					qx[bid].setY(sin(0 / 2));
					qx[bid].setZ(sin(0 / 2));*/

				qz[bid].setW(cos(angle * PI / 180 / 2));
				qz[bid].setY(0 * sin(angle * PI / 180 / 2));
				//qz[bid].setY(-0.01);
				qz[bid].setX(0 * sin(angle * PI / 180 / 2));
				/*	qz[bid].setX(-0.1);*/
				qz[bid].setZ(axis.z * sin(angle * PI / 180 / 2));


				zaxisQZ[bid].setW(cos(angle * PI / 180 / 2));
				zaxisQZ[bid].setX(axis.x * sin(angle * PI / 180 / 2));
				zaxisQZ[bid].setY(0 * sin(angle * PI / 180 / 2));
				zaxisQZ[bid].setZ(axis.z * sin(angle * PI / 180 / 2));

				zaxisQY[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
				zaxisQY[bid].setX(0);
				zaxisQY[bid].setY(sin(0 / 2));
				zaxisQY[bid].setZ(sin(0 / 2));

				zaxisQX[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
				zaxisQX[bid].setX(0);
				zaxisQX[bid].setY(sin(0 / 2));
				zaxisQX[bid].setZ(sin(0 / 2));


				zaxisQP[bid] = zaxisQX[bid].multiply(zaxisQY[bid].multiply(zaxisQZ[bid]));

				//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << axis.x << "\t" << axis.y << "\t" << axis.z << endl;

				//qsf[bid] = qx[bid].multiply(qy[bid].multiply(qz[bid]));

				//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qsf[bid].getW() << "\t" << "X=" << qsf[bid].getX() << "\t" << "Y=" << qsf[bid].getY() << "\t" << "Z=" << qsf[bid].getZ() << "\n";

				cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qz[bid].getW() << "\t" << "X=" << qz[bid].getX() << "\t" << "Y=" << qz[bid].getY() << "\t" << "Z=" << qz[bid].getZ() << "\n";

				//cout << "\n" << "================================================" << endl;
				//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << zaxisQP[bid].getW() << "\t" << "X=" << zaxisQP[bid].getX() << "\t" << "Y=" << zaxisQP[bid].getY() << "\t" << "Z=" << zaxisQP[bid].getZ() << "\n\n";


				dummy1 = 0;
				dummy2 = 0;
				dummy3 = A;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

			}
			if (axis.y == 1 || axis.y == -1)
			{
				/*qx[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
				qx[bid].setX(0);
				qx[bid].setY(sin(0 / 2));
				qx[bid].setZ(sin(0 / 2));*/

				qy[bid].setW(cos(angle * PI / 180 / 2));
				qy[bid].setX(0 * sin(angle * PI / 180 / 2));
				qy[bid].setY(axis.y * sin(angle * PI / 180 / 2));
				qy[bid].setZ(0 * sin(angle * PI / 180 / 2));

				/*		qz[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
						qz[bid].setX(0);
						qz[bid].setY(sin(0 / 2));
						qz[bid].setZ(sin(0 / 2));*/


				yaxisQX[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
				yaxisQX[bid].setX(0);
				yaxisQX[bid].setY(sin(0 / 2));
				yaxisQX[bid].setZ(sin(0 / 2));

				yaxisQZ[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
				yaxisQZ[bid].setX(0);
				yaxisQZ[bid].setY(sin(0 / 2));
				yaxisQZ[bid].setZ(sin(0 / 2));

				yaxisQY[bid].setW(cos(angle * PI / 180 / 2));
				yaxisQY[bid].setX(0 * sin(angle * PI / 180 / 2));
				yaxisQY[bid].setY(axis.y * sin(angle * PI / 180 / 2));
				yaxisQY[bid].setZ(0 * sin(angle * PI / 180 / 2));


				yaxisQP[bid] = yaxisQX[bid].multiply(yaxisQY[bid].multiply(yaxisQZ[bid]));

				//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << axis.x << "\t" << axis.y << "\t" << axis.z << endl;

				//qsf[bid] = qx[bid].multiply(qy[bid].multiply(qz[bid]));

				//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qsf[bid].getW() << "\t" << "X=" << qsf[bid].getX() << "\t" << "Y=" << qsf[bid].getY() << "\t" << "Z=" << qsf[bid].getZ() << "\n";

				cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qy[bid].getW() << "\t" << "X=" << qy[bid].getX() << "\t" << "Y=" << qy[bid].getY() << "\t" << "Z=" << qy[bid].getZ() << "\n";

				//cout << "\n" << "================================================" << endl;
				//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << yaxisQP[bid].getW() << "\t" << "X=" << yaxisQP[bid].getX() << "\t" << "Y=" << yaxisQP[bid].getY() << "\t" << "Z=" << yaxisQP[bid].getZ() << "\n\n";

				dummy1 = 0;
				dummy2 = A;
				dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();
			}

			qxIK[2] = qx[2];
			xaxisQP_IK[2] = xaxisQP[2];
			qyIK[2] = qy[2];
			yaxisQP_IK[2] = yaxisQP[2];
			qzIK[2] = qz[2];
			zaxisQP_IK[2] = zaxisQP[2];

			qxIK[3] = qx[3];
			xaxisQP_IK[3] = xaxisQP[3];
			qyIK[3] = qy[3];
			yaxisQP_IK[3] = yaxisQP[3];
			qzIK[3] = qz[3];
			zaxisQP_IK[3] = zaxisQP[3];

			qxIK[4] = qx[4];
			xaxisQP_IK[4] = xaxisQP[4];
			qyIK[4] = qy[4];
			yaxisQP_IK[4] = yaxisQP[4];
			qzIK[4] = qz[4];
			zaxisQP_IK[4] = zaxisQP[4];

			qxIK[5] = qx[5];
			xaxisQP_IK[5] = xaxisQP[5];
			qyIK[5] = qy[5];
			yaxisQP_IK[5] = yaxisQP[5];
			qzIK[5] = qz[5];
			zaxisQP_IK[5] = zaxisQP[5];

		}

		virtual void OnMouseMove()
		{	


			if (this->Move)
			{
				screenX = this->Interactor->GetEventPosition()[0];
				screenY = this->Interactor->GetEventPosition()[1];
				screenDiff = sqrt((prevX-screenX)* (prevX - screenX) + (prevY - screenY) * (prevY - screenY));

				if (boneID == 2220) //Pelvis
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];


					diff = temp + y;
					if (flag == 1)
					{
						if (diff > prevY)
						{
							//pelvis_Planted_key(1);
						}
						if (diff < prevY)
						{
							//pelvis_Planted_key(-1);
						}
						prevY = diff;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{
							//pelvis_Planted_key(1);
						}
						if (diff < prevY)
						{
							//pelvis_Planted_key(-1);
						}
						prevY = diff;

					}



				}

				if (boneID == 3333) //RightFoot
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;

					if (flag == 1)
					{
						if (diff > prevY)
						{
							FOOT(anim_RL_angle, -anim_RL_x, -anim_RL_y, -anim_RL_z);
						}

						if (diff < prevY)
						{
							FOOT(anim_RL_angle, anim_RL_x, anim_RL_y, anim_RL_z);
						}
						prevY = diff;
					}

					if (flag == 2)
					{
						if (diff > prevY)
						{
							FOOT(anim_RL_angle, -anim_RL_x, -anim_RL_y, -anim_RL_z);
						}

						if (diff < prevY)
						{
							FOOT(anim_RL_angle, anim_RL_x, anim_RL_y, anim_RL_z);
						}
						prevY = diff;
					}

					if (flag == 3)
					{
						if (diff > prevY)
						{
							FOOT(anim_RL_angle, -anim_RL_x, -anim_RL_y, -anim_RL_z);
						}

						if (diff < prevY)
						{
							FOOT(anim_RL_angle, anim_RL_x, anim_RL_y, anim_RL_z);
						}
						prevY = diff;
					}
				}

				if (boneID == 3332) //RightHand
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;

					if (flag == 1)
					{
						if (diff > prevY)
						{
							HAND(anim_RH_angle, -anim_RH_x, -anim_RH_y, -anim_RH_z);
						}

						if (diff < prevY)
						{
							HAND(anim_RH_angle, anim_RH_x, anim_RH_y, anim_RH_z);
						}
						prevY = diff;
					}

					if (flag == 2)
					{
						if (diff > prevY)
						{
							HAND(anim_RH_angle, -anim_RH_x, -anim_RH_y, -anim_RH_z);
						}

						if (diff < prevY)
						{
							HAND(anim_RH_angle, anim_RH_x, anim_RH_y, anim_RH_z);
						}
						prevY = diff;
					}

					if (flag == 3)
					{
						if (diff > prevY)
						{
							HAND(anim_RH_angle, -anim_RH_x, -anim_RH_y, -anim_RH_z);
						}

						if (diff < prevY)
						{
							HAND(anim_RH_angle, anim_RH_x, anim_RH_y, anim_RH_z);
						}
						prevY = diff;
					}
				}
				if (boneID == 3331) //HEAD
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;

					if (flag == 1)
					{
						if (diff > prevY)
						{
							HEAD(anim_head_angle, -anim_head_x, -anim_head_y, -anim_head_z);
						}

						if (diff < prevY)
						{
							HEAD(anim_head_angle, anim_head_x, anim_head_y, anim_head_z);
						}
						prevY = diff;
					}

					if (flag == 2)
					{
						if (diff > prevY)
						{
							HEAD(anim_head_angle, -anim_head_x, -anim_head_y, -anim_head_z);
						}

						if (diff < prevY)
						{
							HEAD(anim_head_angle, anim_head_x, anim_head_y, anim_head_z);
						}
						prevY = diff;
					}

					if (flag == 3)
					{
						if (diff > prevY)
						{
							HEAD(anim_head_angle, -anim_head_x, -anim_head_y, -anim_head_z);
						}

						if (diff < prevY)
						{
							HEAD(anim_head_angle, anim_head_x, anim_head_y, anim_head_z);
						}
						prevY = diff;
					}
				}


				if (boneID == 2221) //Chest

				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;

					if (flag == 1)
					{
						if (diff > prevY)
						{
							/*	compute(chest_angle, chest_x, chest_y, chest_z, boneID);
								chest_angle += 4;
								CHEST(anim_chest_angle, -anim_chest_x, -anim_chest_y, -anim_chest_z);*/

							compute(chest_angleX, chest_x, chest_y, chest_z, boneID);
							chest_angleX += 4;
							CHEST(anim_chest_angle, -anim_chest_x, -anim_chest_y, -anim_chest_z);
						}

						if (diff < prevY)
						{
							/*	compute(chest_angle, chest_x, chest_y, chest_z, boneID);
								chest_angle -= 4;
								CHEST(anim_chest_angle, anim_chest_x, anim_chest_y, anim_chest_z);*/

							chest_angleX -= 4;
							compute(chest_angleX, chest_x, chest_y, chest_z, boneID);
							CHEST(anim_chest_angle, anim_chest_x, anim_chest_y, anim_chest_z);
						}
						prevY = diff;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{
							chest_angleZ += 4;
							compute(chest_angleZ, chest_x, chest_y, chest_z, boneID);
							CHEST(anim_chest_angle, -anim_chest_x, -anim_chest_y, -anim_chest_z);
						}

						if (diff < prevY)
						{

							chest_angleZ -= 4;
							compute(chest_angleZ, chest_x, chest_y, chest_z, boneID);
							CHEST(anim_chest_angle, anim_chest_x, anim_chest_y, anim_chest_z);
						}
						prevY = diff;
					}
					if (flag == 3)
					{
						if (diff > prevY)
						{
							chest_angleY += 4;
							compute(chest_angleZ, chest_x, chest_y, chest_z, boneID);
							CHEST(anim_chest_angle, -anim_chest_x, -anim_chest_y, -anim_chest_z);
						}

						if (diff < prevY)
						{

							chest_angleY -= 4;
							compute(chest_angleZ, chest_x, chest_y, chest_z, boneID);
							CHEST(anim_chest_angle, anim_chest_x, anim_chest_y, anim_chest_z);
						}
						prevY = diff;
					}
				}
				if (boneID == 2222) //RUA
				{

					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];


					diff = temp + y;
					if (flag == 1)
					{
						if (diff > prevY)
						{
							/*compute(rua_angle, rua_x, rua_y, rua_z, boneID);
							rua_angle += 4;
							rua(anim_rua_angle, -anim_rua_x, -anim_rua_y, -anim_rua_z);*/
							//rua_angleX += 4;
							rua_angleX += 4;
							compute(rua_angleX, rua_x, rua_y, rua_z, boneID);
							rua(anim_rua_angle, -anim_rua_x, -anim_rua_y, -anim_rua_z);

						}

						if (diff < prevY)
						{
							/*	compute(rua_angle, rua_x, rua_y, rua_z, boneID);
								rua_angle -= 4;
								rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);*/

								//rua_angleX -= 4;
							rua_angleX -= 4;
							compute(rua_angleX, rua_x, rua_y, rua_z, boneID);
							rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);

						}
						prevY = diff;
						cout << "ruaX_angle=" << rua_angleX << endl;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{
							rua_angleZ += 4;
							compute(rua_angleZ, rua_x, rua_y, rua_z, boneID);
							rua(anim_rua_angle, -anim_rua_x, -anim_rua_y, -anim_rua_z);

							//rua_angleZ += 4;
						}
						if (diff < prevY)
						{
							//rua_angleZ -= 4;
							rua_angleZ -= 4;
							compute(rua_angleZ, rua_x, rua_y, rua_z, boneID);
							rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);
						}
						prevY = diff;
						cout << "ruaZ_angle=" << rua_angleZ << endl;
					}
					if (flag == 3)
					{
						if (diff > prevY)
						{
							rua_angleY+= 4;
							rua(anim_rua_angle, -anim_rua_x, -anim_rua_y, -anim_rua_z);

							//rua_angleZ += 4;
						}
						if (diff < prevY)
						{
							rua_angleY -= 4;
							rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);
						}
						prevY = diff;
						cout << "ruaZ_angle=" << rua_angleZ << endl;
					}
				}
				if (boneID == 2223) //RLA
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];


					diff = temp + y;

					// Use this while interacting Lowerarm Actor

					if (flag == 1)
					{
						if (diff > prevY)
						{
							/*		compute(rla_angle, rla_x, rla_y, rla_z, boneID);
									rla_angle += 4;
									rla(anim_rla_angle, -anim_rla_x, -anim_rla_y, -anim_rla_z);*/

							rla_angleX += 4;
							compute(rla_angleX, rla_x, rla_y, rla_z, boneID);
							rla(anim_rla_angle, -anim_rla_x, -anim_rla_y, -anim_rla_z);
						}
						if (diff < prevY)
						{
							/*	compute(rla_angle, rla_x, rla_y, rla_z, boneID);
								rla_angle -= 4;
								rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);*/
							rla_angleX -= 4;
							compute(rla_angleX, rla_x, rla_y, rla_z, boneID);
							rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);
						}
						prevY = diff;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{
							/*compute(rla_angle, rla_x, rla_y, rla_z, boneID);
							rla_angle += 4;
							rla(anim_rla_angle, -anim_rla_x, -anim_rla_y, -anim_rla_z);*/
							rla_angleZ += 4;
							compute(rla_angleZ, rla_x, rla_y, rla_z, boneID);
							rla(anim_rla_angle, -anim_rla_x, -anim_rla_y, -anim_rla_z);
						}
						if (diff < prevY)
						{
							/*compute(rla_angle, rla_x, rla_y, rla_z, boneID);
							rla_angle -= 4;
							rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);*/

							rla_angleZ -= 4;
							compute(rla_angleZ, rla_x, rla_y, rla_z, boneID);
							rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);
						}
						prevY = diff;
					}

					

					if (flag == 3)
					{
						if (diff > prevY)
						{
							rla(anim_rla_angle, -anim_rla_x, -anim_rla_y, -anim_rla_z);
						}
						if (diff < prevY)
						{
							rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);
						}
						prevY = diff;
					}

					std::cout << "anim_rla_angle " << anim_rla_angle << std::endl;

				}
				if (boneID == 2224)//LUA
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;

					if (flag == 1)
					{
						if (diff > prevY)
						{

							/*compute(lua_angle, lua_x, lua_y, lua_z, boneID);
							lua_angle += 4;
							lua(anim_lua_angle, -anim_lua_x, -anim_lua_y, -anim_lua_z);*/
							compute(lua_angleX, lua_x, lua_y, lua_z, boneID);
							lua_angleX += 4;
							lua(anim_lua_angle, -anim_lua_x, -anim_lua_y, -anim_lua_z);

						}

						if (diff < prevY)
						{
							lua_angleX -= 4;
							compute(lua_angleX, lua_x, lua_y, lua_z, boneID);
							lua(anim_lua_angle, anim_lua_x, anim_lua_y, anim_lua_z);
						}
						prevY = diff;

						std::cout<<"lua_angleX "<< lua_angleX<<std::endl;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{

							compute(lua_angleZ, lua_x, lua_y, lua_z, boneID);
							lua_angleZ += 4;
							lua(anim_lua_angle, -anim_lua_x, -anim_lua_y, -anim_lua_z);

						}

						if (diff < prevY)
						{
							lua_angleZ -= 4;
							compute(lua_angleZ, lua_x, lua_y, lua_z, boneID);
							lua(anim_lua_angle, anim_lua_x, anim_lua_y, anim_lua_z);
						}
						prevY = diff;
						std::cout << "lua_angleZ " << lua_angleZ << std::endl;
					}

					if (flag == 3)
					{
						if (diff > prevY)
						{

							lua_angleY += 4;
							lua(anim_lua_angle, -anim_lua_x, -anim_lua_y, -anim_lua_z);

						}

						if (diff < prevY)
						{
							lua_angleY -= 4;
							lua(anim_lua_angle, anim_lua_x, anim_lua_y, anim_lua_z);
						}
						prevY = diff;

						std::cout << "lua_angleY " << lua_angleY << std::endl;
					}

					
				}
				if (boneID == 2225) //LLA
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;

					if (flag == 1)
					{
						if (diff > prevY)
						{
							/*compute(lla_angle, lla_x, lla_y, lla_z, boneID);
							lla_angle += 4;
							lla(anim_lla_angle, -anim_lla_x, -anim_lla_y, -anim_lla_z);*/
							lla_angleX += 4;
							compute(lla_angleX, lla_x, lla_y, lla_z, boneID);
							lla(anim_lla_angle, -anim_lla_x, -anim_lla_y, -anim_lla_z);
						}

						if (diff < prevY)
						{
							/*	compute(lla_angle, lla_x, lla_y, lla_z, boneID);
								lla_angle -= 4;
								lla(anim_lla_angle, anim_lla_x, anim_lla_y, anim_lla_z);*/
							lla_angleX -= 4;
							compute(lla_angleX, lla_x, lla_y, lla_z, boneID);
							lla(anim_lla_angle, anim_lla_x, anim_lla_y, anim_lla_z);
						}
						prevY = diff;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{
							lla_angleZ += 4;
							compute(lla_angleZ, lla_x, lla_y, lla_z, boneID);
							lla(anim_lla_angle, -anim_lla_x, -anim_lla_y, -anim_lla_z);
						}

						if (diff < prevY)
						{

							lla_angleZ -= 4;
							compute(lla_angleZ, lla_x, lla_y, lla_z, boneID);
							lla(anim_lla_angle, anim_lla_x, anim_lla_y, anim_lla_z);
						}
						prevY = diff;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{
							lla(anim_lla_angle, -anim_lla_x, -anim_lla_y, -anim_lla_z);
						}

						if (diff < prevY)
						{
							lla(anim_lla_angle, anim_lla_x, anim_lla_y, anim_lla_z);
						}
						prevY = diff;
					}

				}
				if (boneID == 2226)//RUL
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (flag == 1)
					{

						if (diff > prevY)
						{
							/*compute(rul_angle, rul_x, rul_y, rul_z, boneID);
							rul_angle += 4;
							rul(anim_rul_angle, -anim_rul_x, -anim_rul_y, -anim_rul_z);*/
							compute(rul_angleX, rul_x, rul_y, rul_z, boneID);
							rul_angleX += 4;
							rul(anim_rul_angle, -anim_rul_x, -anim_rul_y, -anim_rul_z);
						}

						if (diff < prevY)
						{
							/*	compute(rul_angle, rul_x, rul_y, rul_z, boneID);
								rul_angle -= 4;
								rul(anim_rul_angle, anim_rul_x, anim_rul_y, anim_rul_z);*/
							rul_angleX -= 4;
							compute(rul_angleX, rul_x, rul_y, rul_z, boneID);
							rul(anim_rul_angle, anim_rul_x, anim_rul_y, anim_rul_z);
						}
						prevY = diff;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{

							compute(rul_angleZ, rul_x, rul_y, rul_z, boneID);
							rul_angleZ += 4;
							rul(anim_rul_angle, -anim_rul_x, -anim_rul_y, -anim_rul_z);
						}

						if (diff < prevY)
						{
							rul_angleZ -= 4;
							compute(rul_angleZ, rul_x, rul_y, rul_z, boneID);

							rul(anim_rul_angle, anim_rul_x, anim_rul_y, anim_rul_z);
						}
						prevY = diff;

					}
					if (flag == 3)
					{
						if (diff > prevY)
						{
							rul(anim_rul_angle, -anim_rul_x, -anim_rul_y, -anim_rul_z);
						}

						if (diff < prevY)
						{
							rul(anim_rul_angle, anim_rul_x, anim_rul_y, anim_rul_z);
						}
						prevY = diff;

					}
				}
				if (boneID == 2227)//RLL
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (flag == 1)
					{
						if (diff > prevY)
						{
							/*compute(rll_angle, rll_x, rll_y, rll_z, boneID);
							rll_angle += 4;
							rll(anim_rll_angle, -anim_rll_x, -anim_rll_y, -anim_rll_z)*/;
							compute(rll_angleX, rll_x, rll_y, rll_z, boneID);
							rll_angleX += 4;
							rll(anim_rll_angle, -anim_rll_x, -anim_rll_y, -anim_rll_z);
						}

						if (diff < prevY)
						{
							/*	compute(rll_angle, rll_x, rll_y, rll_z, boneID);
								rll_angle -= 4;
								rll(anim_rll_angle, anim_rll_x, anim_rll_y, anim_rll_z);*/
							rll_angleX -= 4;
							compute(rll_angleX, rll_x, rll_y, rll_z, boneID);
							rll(anim_rll_angle, anim_rll_x, anim_rll_y, anim_rll_z);
						}
						prevY = diff;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{

							compute(rll_angleZ, rll_x, rll_y, rll_z, boneID);
							rll_angleZ += 4;
							rll(anim_rll_angle, -anim_rll_x, -anim_rll_y, -anim_rll_z);
						}

						if (diff < prevY)
						{

							rll_angleZ -= 4;
							compute(rll_angleZ, rll_x, rll_y, rll_z, boneID);
							rll(anim_rll_angle, anim_rll_x, anim_rll_y, anim_rll_z);
						}
						prevY = diff;
					}
				}
				if (boneID == 2228)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;

					if (flag == 1)
					{
						if (diff > prevY)
						{
							/*		compute(lul_angle, lul_x, lul_y, lul_z, boneID);
									lul_angle += 4;
									lul(anim_lul_angle, -anim_lul_x, -anim_lul_y, -anim_lul_z);*/

							compute(lul_angleX, lul_x, lul_y, lul_z, boneID);
							lul_angleX += 4;
							lul(anim_lul_angle, -anim_lul_x, -anim_lul_y, -anim_lul_z);

						}

						if (diff < prevY)
						{
							/*	compute(lul_angle, lul_x, lul_y, lul_z, boneID);
								lul_angle -= 4;
								lul(anim_lul_angle, anim_lul_x, anim_lul_y, anim_lul_z);*/

							lul_angleX -= 4;
							compute(lul_angleX, lul_x, lul_y, lul_z, boneID);
							lul(anim_lul_angle, anim_lul_x, anim_lul_y, anim_lul_z);
						}
						prevY = diff;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{
							compute(lul_angleZ, lul_x, lul_y, lul_z, boneID);
							lul_angleZ += 4;
							lul(anim_lul_angle, -anim_lul_x, -anim_lul_y, -anim_lul_z);

						}

						if (diff < prevY)
						{
							lul_angleZ -= 4;
							compute(lul_angleZ, lul_x, lul_y, lul_z, boneID);
							lul(anim_lul_angle, anim_lul_x, anim_lul_y, anim_lul_z);
						}
						prevY = diff;
					}
				}
				if (boneID == 2229)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;

					if (flag == 1)
					{

						if (diff > prevY)
						{
							/*compute(lll_angle, lll_x, lll_y, lll_z, boneID);
							lll_angle += 4;
							lll(anim_lll_angle, -anim_lll_x, -anim_lll_y, -anim_lll_z);*/
							compute(lll_angleX, lll_x, lll_y, lll_z, boneID);
							lll_angleX += 4;
							lll(anim_lll_angle, -anim_lll_x, -anim_lll_y, -anim_lll_z);
						}

						if (diff < prevY)
						{
							lll_angleX -= 4;
							compute(lll_angleX, lll_x, lll_y, lll_z, boneID);
							lll(anim_lll_angle, anim_lll_x, anim_lll_y, anim_lll_z);
						}
						prevY = diff;
					}
					if (flag == 2)
					{
						if (diff > prevY)
						{

							compute(lll_angleZ, lll_x, lll_y, lll_z, boneID);
							lll_angleZ += 4;
							lll(anim_lll_angle, -anim_lll_x, -anim_lll_y, -anim_lll_z);
						}

						if (diff < prevY)
						{
							lll_angleZ -= 4;
							compute(lll_angleZ, lll_x, lll_y, lll_z, boneID);
							lll(anim_lll_angle, anim_lll_x, anim_lll_y, anim_lll_z);
						}
						prevY = diff;

					}
				}

				if (boneID == 10)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;


					if (flag == 1)
					{
						if (diff > prevY)
						{
							if(rhIK_Targetx<32)
								rhIK_Targetx++;
							
						}

						if (diff < prevY)
						{
							if (rhIK_Targetx > -32)
								rhIK_Targetx--;
						}

						
					}

					if (flag == 2)
					{
						if (diff > prevY)
						{
							if (rhIK_Targety < 32)
								rhIK_Targety++;
						}

						if (diff < prevY)
						{
							if (rhIK_Targety > -32)
								rhIK_Targety--;
						}
					}


					//totalAngleOfRUA_z
					if (flag == 3)
					{
						if (diff > prevY)
						{
							if (rhIK_Targetz < 32)
								rhIK_Targetz++;
						}

						if (diff < prevY)
						{
							if (rhIK_Targetz > -32)
								rhIK_Targetz--;
						}

					}

					calculate3Angle(rhIK_Targetx, rhIK_Targety, rhIK_Targetz);
					std::cout << "  rhIK_Targetx = " << rhIK_Targetx << "  rhIK_Targety = " << rhIK_Targety << "  rhIK_Targetz = " << rhIK_Targetz << std::endl;
					mRenderer->Render();
					prevY = diff;
				}


				if (screenDiff > screenPrev)
				{
					if (flag == 1)
					{
						if (boneID == 0)
						{

						}
						if (boneID == 1)
						{
							SMch0_angleX += 4;
							animateSM_CH0(SManim_ch0_angleX, -SMch0_x, -SMch0_y, -SMch0_z);
							compute(SMch0_angleX, SMch0_x, SMch0_y, SMch0_z, boneID);
							mRenderWindow->Render();
						}

						if (boneID == 103)
						{

						}
						if (boneID == 104)
						{

						}
						if (boneID == 105)
						{

						}
						if (boneID == 106)
						{

						}
						if (boneID == 2)
						{
							SMrua_angleX += 4;
							animateSM_RUA(SManim_rua_angleX, -SMrua_x, -SMrua_y, -SMrua_z);
							compute(SMrua_angleX, SMrua_x, SMrua_y, SMrua_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 3)
						{
							SMrla_angleX += 4;
							animateSM_RLA(SManim_rla_angleX, -SMrla_x, -SMrla_y, -SMrla_z);
							compute(SMrla_angleX, SMrla_x, SMrla_y, SMrla_z, boneID);
							mRenderWindow->Render();
						}
						//if (boneID == 10)
						//{
						//	std::cout << rhIK_Targetx << std::endl;
						//	computeSM_ikRH(rhIK_Targetx, rhIK_Targety, SMrh_x, SMrh_y, SMrh_z, boneID);
						//	rhIK_Targetx--;
						//}
						if (boneID == 109)
						{
							SMrh_angleX -= 4;
							animateSM_RH(SMrh_angleX);
							mRenderWindow->Render();
						}
						if (boneID == 4)
						{
							SMlua_angleX += 4;
							animateSM_LUA(SManim_lua_angleX, -SMlua_x, -SMlua_y, -SMlua_z);
							compute(SMlua_angleX, SMlua_x, SMlua_y, SMlua_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 5)
						{
							SMlla_angleX += 4;
							animateSM_LLA(SManim_lla_angleX, -SMlla_x, -SMlla_y, -SMlla_z);
							compute(SMlla_angleX, SMlla_x, SMlla_y, SMlla_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 15)
						{

							computeSM_ikRH(lhIK_Targetx, lhIK_Targety, SMlh_x, SMlh_y, SMlh_z, boneID);
							lhIK_Targetx--;
						}
						if (boneID == 112)
						{
							SMlh_angleX -= 4;
							animateSM_LH(SMlh_angleX);
							mRenderWindow->Render();
						}
						if (boneID == 6)
						{
							SMrul_angleX += 4;
							animateSM_RUL(SManim_rul_angleX, -SMrul_x, -SMrul_y, -SMrul_z);
							compute(SMrul_angleX, SMrul_x, SMrul_y, SMrul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 7)
						{
							SMrll_angleX += 4;
							animateSM_RLL(SManim_rll_angleX, -SMrll_x, -SMrll_y, -SMrll_z);
							compute(SMrll_angleX, SMrll_x, SMrll_y, SMrll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 16)
						{
							computeSM_ikRH(rfIK_Targetx, rfIK_Targety, SMrf_x, SMrf_y, SMrf_z, boneID);
							rfIK_Targetx--;
						}
						if (boneID == 115)
						{
							SMrf_angleX -= 4;
							animateSM_RF(SMrf_angleX);
							mRenderWindow->Render();
						}
						if (boneID == 8)
						{
							SMlul_angleX += 4;
							animateSM_LUL(SManim_lul_angleX, -SMlul_x, -SMlul_y, -SMlul_z);
							compute(SMlul_angleX, SMlul_x, SMlul_y, SMlul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 9)
						{
							SMlll_angleX += 4;
							animateSM_LLL(SManim_lll_angleX, -SMlll_x, -SMlll_y, -SMlll_z);
							compute(SMlll_angleX, SMlll_x, SMlll_y, SMlll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 21)
						{
							computeSM_ikRH(lfIK_Targetx, lfIK_Targety, SMlf_x, SMlf_y, SMlf_z, boneID);
							lfIK_Targetx--;
						}
						if (boneID == 118)
						{
							SMlf_angleX -= 4;
							animateSM_LF(SMlf_angleX);
							mRenderWindow->Render();

						}


						//===================================================================================
						if (boneID == 500)
						{
							ffIK_rfTargetx++;
							computeSM_ikRH(ffIK_rfTargetx, ffIK_rfTargety, ffIKpl_x, ffIKpl_y, ffIKpl_z, boneID);

							mRenderWindow->Render();
						}
						if (boneID == 501)
						{
							ffIKch0_angleX += 4;
							animateffIK_CH0(ffIKanim_ch0_angleX, -ffIKch0_x, -ffIKch0_y, -ffIKch0_z);
							compute(ffIKch0_angleX, ffIKch0_x, ffIKch0_y, ffIKch0_z, boneID);
							mRenderWindow->Render();
						}


						if (boneID == 502)
						{
							ffIKrua_angleX += 4;
							animateffIK_RUA(ffIKanim_rua_angleX, -ffIKrua_x, -ffIKrua_y, -ffIKrua_z);
							compute(ffIKrua_angleX, ffIKrua_x, ffIKrua_y, ffIKrua_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 503)
						{
							ffIKrla_angleX += 4;
							animateffIK_RLA(ffIKanim_rla_angleX, -ffIKrla_x, -ffIKrla_y, -ffIKrla_z);
							compute(ffIKrla_angleX, ffIKrla_x, ffIKrla_y, ffIKrla_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 50)
						{
							// Noram Hand Segment rotation //refer 109 ID
						}
						if (boneID == 510)
						{
							computeSM_ikRH(ffIK_rhTargetX, ffIK_rhTargetY, ffIKrh_x, ffIKrh_y, ffIKrh_z, boneID);
							ffIK_rhTargetX--;
						}
						if (boneID == 504)
						{
							ffIKlua_angleX += 4;
							animateffIK_LUA(ffIKanim_lua_angleX, -ffIKlua_x, -ffIKlua_y, -ffIKlua_z);
							compute(ffIKlua_angleX, ffIKlua_x, ffIKlua_y, ffIKlua_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 505)
						{
							ffIKlla_angleX += 4;
							animateffIK_LLA(ffIKanim_lla_angleX, -ffIKlla_x, -ffIKlla_y, -ffIKlla_z);
							compute(ffIKlla_angleX, ffIKlla_x, ffIKlla_y, ffIKlla_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 51)
						{

						}
						if (boneID == 511)
						{

							computeSM_ikRH(ffIK_lhTargetX, ffIK_lhTargetY, ffIKlh_x, ffIKlh_y, ffIKlh_z, boneID);
							ffIK_lhTargetX--;
						}

						if (boneID == 506)
						{
							ffIKrul_angleX += 4;
							animateffIK_RUL(ffIKanim_rul_angleX, -ffIKrul_x, -ffIKrul_y, -ffIKrul_z);
							//compute(ffIKrul_angleX, ffIKrul_x, ffIKrul_y, ffIKrul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 507)
						{
							ffIKrll_angleX += 4;
							animateffIK_RLL(ffIKanim_rll_angleX, -ffIKrll_x, -ffIKrll_y, -ffIKrll_z);
							//compute(ffIKrll_angleX, ffIKrll_x, ffIKrll_y, ffIKrll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 52)
						{

						}
						if (boneID == 512)
						{

						}

						if (boneID == 508)
						{
							ffIKlul_angleX += 4;
							animateffIK_LUL(ffIKanim_lul_angleX, -ffIKlul_x, -ffIKlul_y, -ffIKlul_z);
							//compute(ffIKlul_angleX, ffIKlul_x, ffIKlul_y, ffIKlul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 509)
						{
							ffIKlll_angleX += 4;
							animateffIK_LLL(ffIKanim_lll_angleX, -ffIKlll_x, -ffIKlll_y, -ffIKlll_z);
							//compute(ffIKlll_angleX, ffIKlll_x, ffIKlll_y, ffIKlll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 53)
						{

						}
						if (boneID == 513)
						{

						}

						//===============================================================================
						if (boneID == 1003)
						{

							computeSM_ikRH(freeLF_Targetx, freeLF_Targety, freeLF_x, freeLF_y, freeLF_z, boneID);
							freeLF_Targetx--;
						}
						if (boneID == 2003)
						{

							computeSM_ikRH(freeRF_Targetx, freeRF_Targety, freeRF_x, freeRF_y, freeRF_z, boneID);
							freeRF_Targetx--;
						}

						//================================================================================



					}
					if (flag == 2)
					{
						if (boneID == 0)
						{

						}
						if (boneID == 1)
						{
							SMch0_angleZ += 4;
							animateSM_CH0(SManim_ch0_angleZ, -SMch0_x, -SMch0_y, -SMch0_z);
							compute(SMch0_angleZ, SMch0_x, SMch0_y, SMch0_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 2)
						{
							SMrua_angleZ += 4;
							animateSM_RUA(SManim_rua_angleZ, -SMrua_x, -SMrua_y, -SMrua_z);
							compute(SMrua_angleZ, SMrua_x, SMrua_y, SMrua_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 3)
						{
							SMrla_angleZ += 4;
							animateSM_RLA(SManim_rla_angleZ, -SMrla_x, -SMrla_y, -SMrla_z);
							compute(SMrla_angleZ, SMrla_x, SMrla_y, SMrla_z, boneID);
							mRenderWindow->Render();
						}
						//if (boneID == 10)
						//{
						//	computeSM_ikRH(rhIK_Targetx, rhIK_Targety, SMrh_x, SMrh_y, SMrh_z, boneID);
						//	rhIK_Targety--;
						//}
						if (boneID == 4)
						{
							SMlua_angleZ += 4;
							animateSM_LUA(SManim_lua_angleZ, SMlua_x, SMlua_y, SMlua_z);
							compute(SMlua_angleZ, -SMlua_x, -SMlua_y, -SMlua_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 5)
						{
							SMlla_angleZ += 4;
							animateSM_LLA(SManim_lla_angleZ, SMlla_x, SMlla_y, SMlla_z);
							compute(SMlla_angleZ, -SMlla_x, -SMlla_y, -SMlla_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 15)
						{
							computeSM_ikRH(lhIK_Targetx, lhIK_Targety, SMlh_x, SMlh_y, SMlh_z, boneID);
							lhIK_Targety--;
						}
						if (boneID == 6)
						{
							SMrul_angleZ += 4;
							animateSM_RUL(SManim_rul_angleZ, -SMrul_x, -SMrul_y, -SMrul_z);
							compute(SMrul_angleZ, SMrul_x, SMrul_y, SMrul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 7)
						{
							SMrll_angleZ += 4;
							animateSM_RLL(SManim_rll_angleZ, -SMrll_x, -SMrll_y, -SMrll_z);
							compute(SMrll_angleZ, SMrll_x, SMrll_y, SMrll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 16)
						{
							computeSM_ikRH(rfIK_Targetx, rfIK_Targety, SMrf_x, SMrf_y, SMrf_z, boneID);
							rfIK_Targety--;
						}
						if (boneID == 8)
						{
							SMlul_angleZ += 4;
							animateSM_LUL(SManim_lul_angleZ, SMlul_x, SMlul_y, SMlul_z);
							compute(SMlul_angleZ, -SMlul_x, -SMlul_y, -SMlul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 9)
						{
							SMlll_angleZ += 4;
							animateSM_LLL(SManim_lll_angleZ, SMlll_x, SMlll_y, SMlll_z);
							compute(SMlll_angleZ, -SMlll_x, -SMlll_y, -SMlll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 21)
						{
							computeSM_ikRH(lfIK_Targetx, lfIK_Targety, SMlf_x, SMlf_y, SMlf_z, boneID);
							lfIK_Targety--;
						}

						//=========================================================
						if (boneID == 500)
						{
							ffIK_rfTargety++;
							computeSM_ikRH(ffIK_rfTargetx, ffIK_rfTargety, ffIKpl_x, ffIKpl_y, ffIKpl_z, boneID);
						}
						if (boneID == 501)
						{
							ffIKch0_angleZ += 4;
							animateffIK_CH0(ffIKanim_ch0_angleZ, -ffIKch0_x, -ffIKch0_y, -ffIKch0_z);
							compute(ffIKch0_angleZ, ffIKch0_x, ffIKch0_y, ffIKch0_z, boneID);
							mRenderWindow->Render();
						}

						if (boneID == 502)
						{
							ffIKrua_angleZ += 4;
							animateffIK_RUA(ffIKanim_rua_angleZ, -ffIKrua_x, -ffIKrua_y, -ffIKrua_z);
							compute(ffIKrua_angleZ, ffIKrua_x, ffIKrua_y, ffIKrua_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 503)
						{
							ffIKrla_angleZ += 4;
							animateffIK_RLA(ffIKanim_rla_angleZ, -ffIKrla_x, -ffIKrla_y, -ffIKrla_z);
							compute(ffIKrla_angleZ, ffIKrla_x, ffIKrla_y, ffIKrla_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 510)
						{
							computeSM_ikRH(ffIK_rhTargetX, ffIK_rhTargetY, ffIKrh_x, ffIKrh_y, ffIKrh_z, boneID);
							ffIK_rhTargetY--;
						}

						if (boneID == 504)
						{
							ffIKlua_angleZ += 4;
							animateffIK_LUA(ffIKanim_lua_angleZ, ffIKlua_x, ffIKlua_y, ffIKlua_z);
							compute(ffIKlua_angleZ, -ffIKlua_x, -ffIKlua_y, -ffIKlua_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 505)
						{
							ffIKlla_angleZ += 4;
							animateffIK_LLA(ffIKanim_lla_angleZ, ffIKlla_x, ffIKlla_y, ffIKlla_z);
							compute(ffIKlla_angleZ, -ffIKlla_x, -ffIKlla_y, -ffIKlla_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 511)
						{

							computeSM_ikRH(ffIK_lhTargetX, ffIK_lhTargetY, ffIKlh_x, ffIKlh_y, ffIKlh_z, boneID);
							ffIK_lhTargetY--;
						}

						//=========================================================
						if (boneID == 1003)
						{

							computeSM_ikRH(freeLF_Targetx, freeLF_Targety, freeLF_x, freeLF_y, freeLF_z, boneID);
							freeLF_Targety--;
						}
						if (boneID == 2003)
						{

							computeSM_ikRH(freeRF_Targetx, freeRF_Targety, freeRF_x, freeRF_y, freeRF_z, boneID);
							freeRF_Targety--;
						}
					}

				}
				if (screenDiff < screenPrev)
				{
					if (flag == 1)
					{
						if (boneID == 0)
						{

						}
						if (boneID == 1)
						{

							animateSM_CH0(SManim_ch0_angleX, SMch0_x, SMch0_y, SMch0_z);
							SMch0_angleX -= 4;
							compute(SMch0_angleX, SMch0_x, SMch0_y, SMch0_z, boneID);
							mRenderWindow->Render();

						}
						if (boneID == 103)
						{


						}
						if (boneID == 104)
						{

						}
						if (boneID == 105)
						{

						}
						if (boneID == 106)
						{

						}
						if (boneID == 2)
						{
							animateSM_RUA(SManim_rua_angleX, SMrua_x, SMrua_y, SMrua_z);
							SMrua_angleX -= 4;
							compute(SMrua_angleX, SMrua_x, SMrua_y, SMrua_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 3)
						{
							animateSM_RLA(SManim_rla_angleX, SMrla_x, SMrla_y, SMrla_z);
							SMrla_angleX -= 4;
							compute(SMrla_angleX, SMrla_x, SMrla_y, SMrla_z, boneID);
							mRenderWindow->Render();
						}
						//if (boneID == 10)
						//{
						//	rhIK_Targetx++;
						//	computeSM_ikRH(rhIK_Targetx, rhIK_Targety, SMrh_x, SMrh_y, SMrh_z, boneID);

						//}
						if (boneID == 109)
						{

							animateSM_RH(SMrh_angleX);
							SMrh_angleX += 4;
							mRenderWindow->Render();
						}
						if (boneID == 4)
						{

							animateSM_LUA(SManim_lua_angleX, SMlua_x, SMlua_y, SMlua_z);
							SMlua_angleX -= 4;
							compute(SMlua_angleX, SMlua_x, SMlua_y, SMlua_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 5)
						{
							animateSM_LLA(SManim_lla_angleX, SMlla_x, SMlla_y, SMlla_z);
							SMlla_angleX -= 4;
							compute(SMlla_angleX, SMlla_x, SMlla_y, SMlla_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 15)
						{
							lhIK_Targetx++;
							computeSM_ikRH(lhIK_Targetx, lhIK_Targety, SMlh_x, SMlh_y, SMlh_z, boneID);

						}

						if (boneID == 112)
						{

							animateSM_LH(SMlh_angleX);
							SMlh_angleX += 4;
							mRenderWindow->Render();
						}
						if (boneID == 6)
						{

							animateSM_RUL(SManim_rul_angleX, SMrul_x, SMrul_y, SMrul_z);
							SMrul_angleX -= 4;
							compute(SMrul_angleX, SMrul_x, SMrul_y, SMrul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 7)
						{
							animateSM_RLL(SManim_rll_angleX, SMrll_x, SMrll_y, SMrll_z);
							SMrll_angleX -= 4;
							compute(SMrll_angleX, SMrll_x, SMrll_y, SMrll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 16)
						{
							rfIK_Targetx++;
							computeSM_ikRH(rfIK_Targetx, rfIK_Targety, SMrf_x, SMrf_y, SMrf_z, boneID);
						}
						if (boneID == 115)
						{
							animateSM_RF(SMrf_angleX);
							SMrf_angleX += 4;
							mRenderWindow->Render();
						}
						if (boneID == 8)
						{

							animateSM_LUL(SManim_lul_angleX, SMlul_x, SMlul_y, SMlul_z);
							SMlul_angleX -= 4;
							compute(SMlul_angleX, SMlul_x, SMlul_y, SMlul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 9)
						{
							animateSM_LLL(SManim_lll_angleX, SMlll_x, SMlll_y, SMlll_z);
							SMlll_angleX -= 4;
							compute(SMlll_angleX, SMlll_x, SMlll_y, SMlll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 21)
						{
							lfIK_Targetx++;
							computeSM_ikRH(lfIK_Targetx, lfIK_Targety, SMlf_x, SMlf_y, SMlf_z, boneID);

						}
						if (boneID == 118)
						{

							animateSM_LF(SMlf_angleX);
							SMlf_angleX += 4;
							mRenderWindow->Render();

						}



						//=================================================================

						if (boneID == 500)
						{
							computeSM_ikRH(ffIK_rfTargetx, ffIK_rfTargety, ffIKpl_x, ffIKpl_y, ffIKpl_z, boneID);
							ffIK_rfTargetx--;
							mRenderWindow->Render();
						}
						if (boneID == 501)
						{

							animateffIK_CH0(ffIKanim_ch0_angleX, ffIKch0_x, ffIKch0_y, ffIKch0_z);
							ffIKch0_angleX -= 4;
							compute(ffIKch0_angleX, ffIKch0_x, ffIKch0_y, ffIKch0_z, boneID);
							mRenderWindow->Render();
						}


						if (boneID == 502)
						{

							animateffIK_RUA(ffIKanim_rua_angleX, ffIKrua_x, ffIKrua_y, ffIKrua_z);
							ffIKrua_angleX -= 4;
							compute(ffIKrua_angleX, ffIKrua_x, ffIKrua_y, ffIKrua_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 503)
						{

							animateffIK_RLA(ffIKanim_rla_angleX, ffIKrla_x, ffIKrla_y, ffIKrla_z);
							ffIKrla_angleX -= 4;
							compute(ffIKrla_angleX, ffIKrla_x, ffIKrla_y, ffIKrla_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 50)
						{

						}
						if (boneID == 510)
						{
							ffIK_rhTargetX++;
							computeSM_ikRH(ffIK_rhTargetX, ffIK_rhTargetY, ffIKrh_x, ffIKrh_y, ffIKrh_z, boneID);

						}


						if (boneID == 504)
						{

							animateffIK_LUA(ffIKanim_lua_angleX, ffIKlua_x, ffIKlua_y, ffIKlua_z);
							ffIKlua_angleX -= 4;
							compute(ffIKlua_angleX, ffIKlua_x, ffIKlua_y, ffIKlua_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 505)
						{

							animateffIK_LLA(ffIKanim_lla_angleX, ffIKlla_x, ffIKlla_y, ffIKlla_z);
							ffIKlla_angleX -= 4;
							compute(ffIKlla_angleX, ffIKlla_x, ffIKlla_y, ffIKlla_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 51)
						{

						}
						if (boneID == 511)
						{
							ffIK_lhTargetX++;
							computeSM_ikRH(ffIK_lhTargetX, ffIK_lhTargetY, ffIKlh_x, ffIKlh_y, ffIKlh_z, boneID);

						}

						if (boneID == 506)
						{

							animateffIK_RUL(ffIKanim_rul_angleX, ffIKrul_x, ffIKrul_y, ffIKrul_z);
							ffIKrul_angleX -= 4;
							//compute(ffIKrul_angleX, ffIKrul_x, ffIKrul_y, ffIKrul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 507)
						{

							animateffIK_RLL(ffIKanim_rll_angleX, ffIKrll_x, ffIKrll_y, ffIKrll_z);
							ffIKrll_angleX -= 4;
							//compute(ffIKrll_angleX, ffIKrll_x, ffIKrll_y, ffIKrll_z, boneID);
							mRenderWindow->Render();

						}
						if (boneID == 52)
						{

						}
						if (boneID == 512)
						{

						}

						if (boneID == 508)
						{

							animateffIK_LUL(ffIKanim_lul_angleX, ffIKlul_x, ffIKlul_y, ffIKlul_z);
							ffIKlul_angleX += 4;
							//compute(ffIKlul_angleX, ffIKlul_x, ffIKlul_y, ffIKlul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 509)
						{

							animateffIK_LLL(ffIKanim_lll_angleX, ffIKlll_x, ffIKlll_y, ffIKlll_z);
							ffIKlll_angleX += 4;
							//compute(ffIKlll_angleX, ffIKlll_x, ffIKlll_y, ffIKlll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 53)
						{

						}
						if (boneID == 513)
						{

						}

						//===================================================================
						if (boneID == 1003)
						{
							freeLF_Targetx++;
							computeSM_ikRH(freeLF_Targetx, freeLF_Targety, freeLF_x, freeLF_y, freeLF_z, boneID);

						}
						if (boneID == 2003)
						{
							freeRF_Targetx++;
							computeSM_ikRH(freeRF_Targetx, freeRF_Targety, freeRF_x, freeRF_y, freeRF_z, boneID);

						}
					}
					if (flag == 2)
					{
						if (boneID == 0)
						{

						}
						if (boneID == 1)
						{

							animateSM_CH0(SManim_ch0_angleZ, SMch0_x, SMch0_y, SMch0_z);
							SMch0_angleZ -= 4;
							compute(SMch0_angleZ, SMch0_x, SMch0_y, SMch0_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 2)
						{
							animateSM_RUA(SManim_rua_angleZ, SMrua_x, SMrua_y, SMrua_z);
							SMrua_angleZ -= 4;
							compute(SMrua_angleZ, SMrua_x, SMrua_y, SMrua_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 3)
						{
							animateSM_RLA(SManim_rla_angleZ, SMrla_x, SMrla_y, SMrla_z);
							SMrla_angleZ -= 4;
							compute(SMrla_angleZ, SMrla_x, SMrla_y, SMrla_z, boneID);
							mRenderWindow->Render();
						}
						//if (boneID == 10)
						//{
						//	rhIK_Targety++;
						//	computeSM_ikRH(rhIK_Targetx, rhIK_Targety, SMrh_x, SMrh_y, SMrh_z, boneID);

						//}
						if (boneID == 4)
						{
							animateSM_LUA(SManim_lua_angleZ, -SMlua_x, -SMlua_y, -SMlua_z);
							SMlua_angleZ -= 4;
							compute(SMlua_angleZ, -SMlua_x, -SMlua_y, -SMlua_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 5)
						{
							animateSM_LLA(SManim_lla_angleZ, -SMlla_x, -SMlla_y, -SMlla_z);
							SMlla_angleZ -= 4;
							compute(SMlla_angleZ, -SMlla_x, -SMlla_y, -SMlla_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 15)
						{
							lhIK_Targety++;
							computeSM_ikRH(lhIK_Targetx, lhIK_Targety, SMlh_x, SMlh_y, SMlh_z, boneID);

						}
						if (boneID == 6)
						{
							animateSM_RUL(SManim_rul_angleZ, SMrul_x, SMrul_y, SMrul_z);
							SMrul_angleZ -= 4;
							compute(SMrul_angleZ, SMrul_x, SMrul_y, SMrul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 7)
						{
							animateSM_RLL(SManim_rll_angleZ, SMrll_x, SMrll_y, SMrll_z);
							SMrll_angleZ -= 4;
							compute(SMrll_angleZ, SMrll_x, SMrll_y, SMrll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 16)
						{
							rfIK_Targety++;
							computeSM_ikRH(rfIK_Targetx, rfIK_Targety, SMrf_x, SMrf_y, SMrf_z, boneID);

						}
						if (boneID == 8)
						{
							animateSM_LUL(SManim_lul_angleZ, -SMlul_x, -SMlul_y, -SMlul_z);
							SMlul_angleZ -= 4;
							compute(SMlul_angleZ, -SMlul_x, -SMlul_y, -SMlul_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 9)
						{
							animateSM_LLL(SManim_lll_angleZ, -SMlll_x, -SMlll_y, -SMlll_z);
							SMlla_angleZ -= 4;
							compute(SMlll_angleZ, -SMlll_x, -SMlll_y, -SMlll_z, boneID);
							mRenderWindow->Render();
						}
						if (boneID == 21)
						{
							lfIK_Targety++;
							computeSM_ikRH(lfIK_Targetx, lfIK_Targety, SMlf_x, SMlf_y, SMlf_z, boneID);

						}


						//=========================================================
						if (boneID == 500)
						{

							computeSM_ikRH(ffIK_rfTargetx, ffIK_rfTargety, ffIKpl_x, ffIKpl_y, ffIKpl_z, boneID);
							ffIK_rfTargety--;
						}
						if (boneID == 501)
						{

							animateffIK_CH0(ffIKanim_ch0_angleZ, ffIKch0_x, ffIKch0_y, ffIKch0_z);
							ffIKch0_angleZ -= 4;
							compute(ffIKch0_angleZ, ffIKch0_x, ffIKch0_y, ffIKch0_z, boneID);
							mRenderWindow->Render();
						}

						if (boneID == 502)
						{

							animateffIK_RUA(ffIKanim_rua_angleZ, ffIKrua_x, ffIKrua_y, ffIKrua_z);
							ffIKrua_angleZ -= 4;
							compute(ffIKrua_angleZ, ffIKrua_x, ffIKrua_y, ffIKrua_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 503)
						{

							animateffIK_RLA(ffIKanim_rla_angleZ, ffIKrla_x, ffIKrla_y, ffIKrla_z);
							ffIKrla_angleZ -= 4;
							compute(ffIKrla_angleZ, ffIKrla_x, ffIKrla_y, ffIKrla_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 510)
						{
							ffIK_rhTargetY++;
							computeSM_ikRH(ffIK_rhTargetX, ffIK_rhTargetY, ffIKrh_x, ffIKrh_y, ffIKrh_z, boneID);

						}

						if (boneID == 504)
						{

							animateffIK_LUA(ffIKanim_lua_angleZ, -ffIKlua_x, -ffIKlua_y, -ffIKlua_z);
							ffIKlua_angleZ -= 4;
							compute(ffIKlua_angleZ, -ffIKlua_x, -ffIKlua_y, -ffIKlua_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 505)
						{

							animateffIK_LLA(ffIKanim_lla_angleZ, -ffIKlla_x, -ffIKlla_y, -ffIKlla_z);
							ffIKlla_angleZ -= 4;
							compute(ffIKlla_angleZ, -ffIKlla_x, -ffIKlla_y, -ffIKlla_z, boneID - 500);
							mRenderWindow->Render();

						}
						if (boneID == 511)
						{
							ffIK_lhTargetY++;
							computeSM_ikRH(ffIK_lhTargetX, ffIK_lhTargetY, ffIKlh_x, ffIKlh_y, ffIKlh_z, boneID);

						}

						//=======================================================
						if (boneID == 1003)
						{
							freeLF_Targety++;
							computeSM_ikRH(freeLF_Targetx, freeLF_Targety, freeLF_x, freeLF_y, freeLF_z, boneID);

						}
						if (boneID == 2003)
						{
							freeRF_Targety++;
							computeSM_ikRH(freeRF_Targetx, freeRF_Targety, freeRF_x, freeRF_y, freeRF_z, boneID);

						}

					}

				}
				screenPrev = screenDiff;



				if (boneID == 91)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						moveSphereProp(consProp_sphere_x, consProp_sphere_y, consProp_sphere_z);
					}
					if (diff < prevY)
					{
						moveSphereProp(-consProp_sphere_x, -consProp_sphere_y, -consProp_sphere_z);
					}
					prevY = diff;
				}


				if (boneID == 9100)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						TmoveSphereProp(TconsProp_sphere_x, TconsProp_sphere_y, TconsProp_sphere_z);
					}
					if (diff < prevY)
					{
						TmoveSphereProp(-TconsProp_sphere_x, -TconsProp_sphere_y, -TconsProp_sphere_z);
					}
					prevY = diff;
				}

				if (boneID == 9200)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						TmoveSphereProp2(TconsProp_sphere_x2, TconsProp_sphere_y2, TconsProp_sphere_z2);
					}
					if (diff < prevY)
					{
						TmoveSphereProp2(-TconsProp_sphere_x2, -TconsProp_sphere_y2, -TconsProp_sphere_z2);
					}
					prevY = diff;
				}
				if (boneID == 9300)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						TmoveSphereProp3(TconsProp_sphere_x3, TconsProp_sphere_y3, TconsProp_sphere_z3);
					}
					if (diff < prevY)
					{
						TmoveSphereProp3(-TconsProp_sphere_x3, -TconsProp_sphere_y3, -TconsProp_sphere_z3);
					}
					prevY = diff;
				}


				if (boneID == 92)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						moveLineProp(consProp_line_x, consProp_line_y, consProp_line_z);
					}
					if (diff < prevY)
					{
						moveLineProp(-consProp_line_x, -consProp_line_y, -consProp_line_z);
					}
					prevY = diff;
				}
				if (boneID == 9001)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						TmoveLineProp(TconsProp_line_x, TconsProp_line_y, TconsProp_line_z);
					}
					if (diff < prevY)
					{
						TmoveLineProp(-TconsProp_line_x, -TconsProp_line_y, -TconsProp_line_z);
					}
					prevY = diff;
				}
				if (boneID == 9002)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						TmoveLineProp2(TconsProp_line_x2, TconsProp_line_y2, TconsProp_line_z2);
					}
					if (diff < prevY)
					{
						TmoveLineProp2(-TconsProp_line_x2, -TconsProp_line_y2, -TconsProp_line_z2);
					}
					prevY = diff;
				}
				if (boneID == 9003)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						TmoveLineProp3(TconsProp_line_x3, TconsProp_line_y3, TconsProp_line_z3);
					}
					if (diff < prevY)
					{
						TmoveLineProp3(-TconsProp_line_x3, -TconsProp_line_y3, -TconsProp_line_z3);
					}
					prevY = diff;
				}

				if (boneID == 93)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						movePlaneProp(consProp_plane_x, consProp_plane_y, consProp_plane_z);
					}
					if (diff < prevY)
					{
						movePlaneProp(-consProp_plane_x, -consProp_plane_y, -consProp_plane_z);
					}
					prevY = diff;
				}
				if (boneID == 94)
				{
					x = this->Interactor->GetEventPosition()[0];
					y = this->Interactor->GetEventPosition()[1];

					diff = temp + y;
					if (diff > prevY)
					{
						moveCubeProp(consProp_cube_x, consProp_cube_y, consProp_cube_z);
					}
					if (diff < prevY)
					{
						moveCubeProp(-consProp_cube_x, -consProp_cube_y, -consProp_cube_z);
					}
					prevY = diff;
				}

			}

			screenPrev = screenDiff;
		}
		virtual void 	OnMiddleButtonUp() override
		{
			vtkInteractorStyleTrackballActor::OnMiddleButtonUp();

			std::cout << this->Move << "	,	" << boneID << std::endl;
			this->Move = false;

			


		}
		virtual void OnMiddleButtonDown() override
		{
			vtkInteractorStyleTrackballActor::OnMiddleButtonDown();
			cout << "Selecting Objects";

			prevX = this->Interactor->GetEventPosition()[0];
			prevY = this->Interactor->GetEventPosition()[1];

			flag = 3;
			boneID = 0;

			if (this->InteractionProp == this->tartget)
			{

				b_targetSelect = true;
				boneID = 10;
				this->Move = true;
			}

			if (this->InteractionProp == this->RH_Actor)
			{
				boneID = 3332;
				axis_flag = 'x';
				this->Move = true;
				RH_x = 0;
				RH_y = 1;
				RH_z = 0;
				RH_angle = 4;
				anim_RH_x = 0;
				anim_RH_y = 1;
				anim_RH_z = 0;
				anim_RH_angle = 4;

				COLOR_RightHand_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}
			if (this->InteractionProp == this->RL_Actor)
			{
				boneID = 3333;
				axis_flag = 'x';
				this->Move = true;
				RL_x = 0;
				RL_y = 1;
				RL_z = 0;
				RL_angle = 4;
				anim_RL_x = 0;
				anim_RL_y = 1;
				anim_RL_z = 0;
				anim_RL_angle = 4;

				COLOR_RF_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}

			if (this->InteractionProp == this->headActor)
			{
				boneID = 3331;
				axis_flag = 'y';
				this->Move = true;
				head_x = 0;
				head_y = 1;
				head_z = 0;
				head_angle = 4;
				anim_head_x = 0;
				anim_head_y = 1;
				anim_head_z = 0;
				anim_head_angle = 4;

				COLOR_Head_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}

			if (this->InteractionProp == this->chestActor)
			{
				boneID = 2221;
				axis_flag = 'x';
				this->Move = true;
				chest_x = 1;
				chest_y = 0;
				chest_z = 0;
				anim_chest_angle = 4;
				anim_chest_x = 0;
				anim_chest_y = 1;
				anim_chest_z = 0;

				COLOR_CUconeActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->RLA)
			{
				boneID = 2223;
				axis_flag = 'x';
				this->Move = true;
				rla_x = 0;
				rla_y = 1;
				rla_z = 0;
				anim_rla_angle = 4;
				anim_rla_x = 0;
				anim_rla_y = 1;
				anim_rla_z = 0;

				COLOR_RforearmActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());

				mRenderer->Render();

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderWindow->Render();

			}
			if (this->InteractionProp == this->RUA)
			{

				boneID = 2222;
				axis_flag = 'x';
				this->Move = true;
				/*	rua_x = 1;
					rua_y = 0;
					rua_z = 0;*/
				anim_rua_angle = 4;
				anim_rua_x = 0;
				anim_rua_y = 1;
				anim_rua_z = 0;

				COLOR_RarmActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderer->Render();
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->RLA)
			{
				boneID = 2223;
				axis_flag = 'x';
				this->Move = true;
				rla_x = 0;
				rla_y = 1;
				rla_z = 0;
				anim_rla_angle = 4;
				anim_rla_x = 0;
				anim_rla_y = 1;
				anim_rla_z = 0;

				COLOR_RforearmActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());

				textActor->SetInput(text);


				mRenderer->Render();

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());



				mRenderWindow->Render();

			}
			if (this->InteractionProp == this->LUA)
			{
				boneID = 2224;
				axis_flag = 'z';
				this->Move = true;
				lua_x = 0;
				lua_y = 1;
				lua_z = 0;
				anim_lua_angle = 4;
				anim_lua_x = 0;
				anim_lua_y = 1;
				anim_lua_z = 0;
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());



				mRenderWindow->Render();

			}
			if (this->InteractionProp == this->LLA)
			{
				boneID = 2225;
				axis_flag = 'x';
				this->Move = true;
				lla_x = 0;
				lla_y = 1;
				lla_z = 0;
				anim_lla_angle = 4;
				anim_lla_x = 0;
				anim_lla_y = 1;
				anim_lla_z = 0;

				COLOR_LforearmActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());


				mRenderer->Render();



				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->RUL)
			{
				boneID = 2226;
				axis_flag = 'x';
				this->Move = true;
				rul_x = 0;
				rul_y = 1;
				rul_z = 0;
				anim_rul_angle = 4;
				anim_rul_x = 0;
				anim_rul_y = 1;
				anim_rul_z = 0;

				COLOR_RlulegActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderer->Render();
				mRenderWindow->Render();
			}

		}

		virtual void OnLeftButtonUp() override
		{
			boneID = 0;
			vtkInteractorStyleTrackballActor::OnLeftButtonUp();
			std::cout << this->Move << "	,	" << boneID << std::endl;
			this->Move = false;
			

			if (this->InteractionProp == this->tartget)
			{
				//x = this->Interactor->GetEventPosition()[0];
				//y = this->Interactor->GetEventPosition()[1];

				//if (b_targetSelect)
				//{
				//	targetActor->SetPosition((x - oldX)/10, 0, 0);
				//	targetActor->SetPosition(0, (y - oldY)/10, 0);


				//	mRenderer->Render();
				//}

				//double targetPosition[3] = {0,0,0};
				//double handPosition[3] = { 0,0,0 };
				//double differnce[3] = { 0,0,0 };

				//targetActor->GetPosition(targetPosition);
				//RightHand_ObjReader_Transform->GetPosition(handPosition);
				//differnce[0] = targetPosition[0] - handPosition[0];
				//differnce[1] = targetPosition[1] - handPosition[1];
				//differnce[2] = targetPosition[2] - handPosition[2];


				//double diffLength = sqrt(differnce[0]* differnce[0] + differnce[1]* differnce[1] + differnce[2]* differnce[2]);
				//if (diffLength > 0.01)
				//{

				//	
				//}
				


			}

			b_targetSelect = false;
		}
		virtual void OnLeftButtonDown() override
		{
			vtkInteractorStyleTrackballActor::OnLeftButtonDown();
			cout << "Selecting Objects";

			oldX = this->Interactor->GetEventPosition()[0];
			oldY = this->Interactor->GetEventPosition()[1];

			prevX = this->Interactor->GetEventPosition()[0];
			prevY = this->Interactor->GetEventPosition()[1];

			flag = 1;
			boneID = 0;

			//colorSetting(1,"Gray");

			if (this->InteractionProp == this->tartget)
			{
				
				b_targetSelect = true;
				boneID = 10;
				this->Move = true;


			}



			// ======================================================================================================//
			if (this->InteractionProp == this->LH_Actor)
			{



				COLOR_LeftHand_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}
			if (this->InteractionProp == this->RH_Actor)
			{
				boneID = 3332;
				axis_flag = 'x';
				this->Move = true;
				RH_x = 1;
				RH_y = 0;
				RH_z = 0;
				RH_angle = 4;
				anim_RH_x = 1;
				anim_RH_y = 0;
				anim_RH_z = 0;
				anim_RH_angle = 4;

				COLOR_RightHand_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}

			if (this->InteractionProp == this->LL_Actor)
			{

				COLOR_LF_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}

			if (this->InteractionProp == this->RL_Actor)
			{
				boneID = 3333;
				axis_flag = 'x';
				this->Move = true;
				RL_x = 1;
				RL_y= 0;
				RL_z = 0;
				RL_angle = 4;
				anim_RL_x = 1;
				anim_RL_y = 0;
				anim_RL_z = 0;
				anim_RL_angle = 4;

				COLOR_RF_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}

			if (this->InteractionProp == this->headActor)
			{
				boneID = 3331;
				axis_flag = 'x';
				this->Move = true;
				head_x = 1;
				head_y = 0;
				head_z = 0;
				head_angle = 4;
				anim_head_x = 1;
				anim_head_y = 0;
				anim_head_z = 0;
				anim_head_angle = 4;

				COLOR_Head_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}




			if (this->InteractionProp == this->pelvisActor)
			{

				boneID = 2220;
				axis_flag = 'x';
				this->Move = true;
				pelvis_x = 1;
				pelvis_y = 0;
				pelvis_z = 0;
				anim_pelvis_angle = 4;
				anim_pelvis_x = 1;
				anim_pelvis_y = 0;
				anim_pelvis_z = 0;

				COLOR_PlconeActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());



				//dummy1 = 0;
				//dummy2 = 0;
				//dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderWindow->Render();


			}
			if (this->InteractionProp == this->chestActor)
			{
				boneID = 2221;
				axis_flag = 'x';
				this->Move = true;
				chest_x = 1;
				chest_y = 0;
				chest_z = 0;
				anim_chest_angle = 4;
				anim_chest_x = 1;
				anim_chest_y = 0;
				anim_chest_z = 0;

				COLOR_CUconeActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());



				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->RUA)
			{
				boneID = 2222;
				axis_flag = 'x';
				this->Move = true;
			/*	rua_x = 1;
				rua_y = 0;
				rua_z = 0;*/
				anim_rua_angle = 4;
				anim_rua_x = 1;
				anim_rua_y = 0;
				anim_rua_z = 0;

				COLOR_RarmActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());


				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderer->Render();
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->RLA)
			{
				boneID = 2223;
				axis_flag = 'x';
				this->Move = true;
				rla_x = 1;
				rla_y = 0;
				rla_z = 0;
				anim_rla_angle = 4;
				anim_rla_x = 1;
				anim_rla_y = 0;
				anim_rla_z = 0;

				COLOR_RforearmActor = "Yellow";


				
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());


				//PlconeActor->GetProperty()->SetOpacity(0.0);
				//CUconeActor->GetProperty()->SetOpacity(0.0);
				//CUconeActor_upper->GetProperty()->SetOpacity(0.0);
				//Head_objActor->GetProperty()->SetOpacity(0.0);

				//LeftHand_objActor->GetProperty()->SetOpacity(0.0);
				////RightHand_objActor->GetProperty()->SetOpacity(0.0);
				//LF_objActor->GetProperty()->SetOpacity(0.0);
				//RF_objActor->GetProperty()->SetOpacity(0.0);


				////RarmActor->GetProperty()->SetOpacity(0.0);
				////RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				//LarmActor->GetProperty()->SetOpacity(0.0);
				//LforearmActor->GetProperty()->SetOpacity(0.0);
				//RlulegActor->GetProperty()->SetOpacity(0.0);
				//RllegActor->GetProperty()->SetOpacity(0.0);
				//LlulegActor->GetProperty()->SetOpacity(0.0);
				//LllegActor->GetProperty()->SetOpacity(0.0);
				

				/*dummy1 = 0;
				dummy2 = 0;
				dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);


				mRenderer->Render();

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());



				mRenderWindow->Render();



			}
			if (this->InteractionProp == this->LUA)
			{
				boneID = 2224;
				axis_flag = 'x';
				this->Move = true;
				lua_x = 1;
				lua_y = 0;
				lua_z = 0;
				anim_lua_angle = 4;
				anim_lua_x = 1;
				anim_lua_y = 0;
				anim_lua_z = 0;

				COLOR_LarmActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());




				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderer->Render();
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->LLA)
			{
				boneID = 2225;
				axis_flag = 'x';
				this->Move = true;
				lla_x = 1;
				lla_y = 0;
				lla_z = 0;
				anim_lla_angle = 4;
				anim_lla_x = 1;
				anim_lla_y = 0;
				anim_lla_z = 0;

				COLOR_LforearmActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )"; 


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());


				mRenderer->Render();



				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->RUL)
			{
				boneID = 2226;
				axis_flag = 'x';
				this->Move = true;
				rul_x = 1;
				rul_y = 0;
				rul_z = 0;
				anim_rul_angle = 4;
				anim_rul_x = 1;
				anim_rul_y = 0;
				anim_rul_z = 0;

				COLOR_RlulegActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());

				//PlconeActor->GetProperty()->SetOpacity(0.0);
				//CUconeActor->GetProperty()->SetOpacity(0.0);
				//CUconeActor_upper->GetProperty()->SetOpacity(0.0);
				//Head_objActor->GetProperty()->SetOpacity(0.0);

				//LeftHand_objActor->GetProperty()->SetOpacity(0.0);
				//RightHand_objActor->GetProperty()->SetOpacity(0.0);
				//LF_objActor->GetProperty()->SetOpacity(0.0);
				////RF_objActor->GetProperty()->SetOpacity(0.0);


				//RarmActor->GetProperty()->SetOpacity(0.0);
				//RforearmActor->GetProperty()->SetOpacity(0.0);
				//LarmActor->GetProperty()->SetOpacity(0.0);
				//LforearmActor->GetProperty()->SetOpacity(0.0);
				////RlulegActor->GetProperty()->SetOpacity(0.0);
				////RllegActor->GetProperty()->SetOpacity(0.0);
				//LlulegActor->GetProperty()->SetOpacity(0.0);
				//LllegActor->GetProperty()->SetOpacity(0.0);



				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderer->Render();
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->RLL)
			{
				boneID = 2227;
				axis_flag = 'x';
				this->Move = true;
				rll_x = 1;
				rll_y = 0;
				rll_z = 0;
				anim_rll_angle = 4;
				anim_rll_x = 1;
				anim_rll_y = 0;
				anim_rll_z = 0;

				COLOR_RllegActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData()); 
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());



				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderer->Render();



				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->LUL)
			{
				boneID = 2228;
				axis_flag = 'x';
				this->Move = true;
				lul_x = 1;
				lul_y = 0;
				lul_z = 0;
				anim_lul_angle = 4;
				anim_lul_x = 1;
				anim_lul_y = 0;
				anim_lul_z = 0;

				COLOR_LlulegActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());


				//dummy1 = 0;
				//dummy2 = 0;
				//dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor).GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_plane_actor).GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_cube_actor).GetData());

				mRenderer->Render();
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->LLL)
			{
				boneID = 2229;
				axis_flag = 'x';
				this->Move = true;
				lll_x = 1;
				lll_y = 0;
				lll_z = 0;
				anim_lll_angle = 4;
				anim_lll_x = 1;
				anim_lll_y = 0;
				anim_lll_z = 0;

				COLOR_LllegActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());


				//dummy1 = 0;
				//dummy2 = 0;
				//dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				mRenderer->Render();
				mRenderWindow->Render();
			}


		
			//=====================================================================================================//


			if (this->InteractionProp == this->SM_pelvisActor)
			{
				boneID = 1;
				axis_flag = 'x';
				SMpl_x = 1;
				SMpl_y = 0;
				SMpl_z = 0;
				SManim_pl_angleX = 1;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->SM_CH0)
			{
				boneID = 1;
				axis_flag = 'x';
				SMch0_x = 1;
				SMch0_y = 0;
				SMch0_z = 0;
				SManim_ch0_angleX = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_CH1)
			{
				boneID = 103;
				axis_flag = 'x';
				this->Move = true;

				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_CH2)
			{
				boneID = 104;
				axis_flag = 'x';
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_CH3)
			{
				boneID = 105;
				axis_flag = 'x';
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->SM_headActor)
			{
				boneID = 106;
				axis_flag = 'x';
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->SM_RUA)
			{
				boneID = 2;
				axis_flag = 'x';
				SMrua_x = 1;
				SMrua_y = 0;
				SMrua_z = 0;
				SManim_rua_angleX = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_RLA)
			{
				boneID = 3;
				axis_flag = 'x';
				this->Move = true;
				SMrla_x = 1;
				SMrla_y = 0;
				SMrla_z = 0;
				SManim_rla_angleX = 4;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_RH_Actor)
			{

				if (rhIK_flag == 1)
				{
					boneID = 10;

				}
				if (rhIK_flag == 0)
				{
					boneID = 109;

				}
				axis_flag = 'x';
				this->Move = true;
				SMrh_x = 1;
				SMrh_y = 0;
				SMrh_z = 0;


				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->SM_LUA)
			{

				boneID = 4;
				axis_flag = 'x';
				SMlua_x = 1;
				SMlua_y = 0;
				SMlua_z = 0;
				SManim_lua_angleX = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_LLA)
			{
				boneID = 5;
				axis_flag = 'x';
				SMlla_x = 1;
				SMlla_y = 0;
				SMlla_z = 0;
				SManim_lla_angleX = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_LH_Actor)
			{

				if (rhIK_flag == 1)
				{
					boneID = 15;

				}
				if (rhIK_flag == 0)
				{
					boneID = 112;

				}
				axis_flag = 'x';
				this->Move = true;
				SMlh_x = 1;
				SMlh_y = 0;
				SMlh_z = 0;

				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->SM_RUL)
			{
				boneID = 6;
				axis_flag = 'x';
				SMrul_x = 1;
				SMrul_y = 0;
				SMrul_z = 0;
				SManim_rul_angleX = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_RLL)
			{
				boneID = 7;
				axis_flag = 'x';
				SMrll_x = 1;
				SMrll_y = 0;
				SMrll_z = 0;
				SManim_rll_angleX = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_RF_Actor)
			{
				if (rfIK_flag == 1)
				{
					boneID = 16;
				}
				if (rfIK_flag == 0)
				{
					boneID = 115;
				}
				axis_flag = 'x';
				this->Move = true;
				SMrf_x = 1;
				SMrf_y = 0;
				SMrf_z = 0;

				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->SM_LUL)
			{
				boneID = 8;
				axis_flag = 'x';
				SMlul_x = 1;
				SMlul_y = 0;
				SMlul_z = 0;
				SManim_lul_angleX = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_LLL)
			{
				boneID = 9;
				axis_flag = 'x';
				SMlll_x = 1;
				SMlll_y = 0;
				SMlll_z = 0;
				SManim_lll_angleX = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_LF_Actor)
			{
				if (lfIK_flag == 1)
				{
					boneID = 21;
				}
				if (lfIK_flag == 0)
				{
					boneID = 118;
				}
				axis_flag = 'x';
				this->Move = true;
				SMlf_x = 1;
				SMlf_y = 0;
				SMlf_z = 0;

				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				mRenderWindow->Render();
			}

			//======================================================================================================//

			if (this->InteractionProp == this->ffIK_pelvisActor)
			{
				boneID = 500;
				axis_flag = 'x';
				ffIKpl_x = 1;
				ffIKpl_y = 0;
				ffIKpl_z = 0;
				ffIKanim_pl_angleX = 4;
				this->Move = true;


				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ffIK_CH0)
			{
				boneID = 501;
				axis_flag = 'x';
				ffIKch0_x = 1;
				ffIKch0_y = 0;
				ffIKch0_z = 0;
				ffIKanim_ch0_angleX = 4;
				this->Move = true;
				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ffIK_CH1)
			{

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_CH2)
			{
				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_CH3)
			{

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ffIK_headActor)
			{
				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ffIK_RUA)
			{
				boneID = 502;
				axis_flag = 'x';
				ffIKrua_x = 1;
				ffIKrua_y = 0;
				ffIKrua_z = 0;
				ffIKanim_rua_angleX = 4;
				this->Move = true;
				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_RLA)
			{
				boneID = 503;
				axis_flag = 'x';
				ffIKrla_x = 1;
				ffIKrla_y = 0;
				ffIKrla_z = 0;
				ffIKanim_rla_angleX = 4;
				this->Move = true;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_RH)
			{
				if (rhIK_flag == 1)
				{
					boneID = 510;
				}
				if (rhIK_flag == 0)
				{
					boneID = 50;
				}
				axis_flag = 'x';
				this->Move = true;
				ffIKrh_x = 1;
				ffIKrh_y = 0;
				ffIKrh_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ffIK_LUA)
			{
				boneID = 504;
				axis_flag = 'x';
				ffIKlua_x = 1;
				ffIKlua_y = 0;
				ffIKlua_z = 0;
				ffIKanim_lua_angleX = 4;
				this->Move = true;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_LLA)
			{
				boneID = 505;
				axis_flag = 'x';
				ffIKlla_x = 1;
				ffIKlla_y = 0;
				ffIKlla_z = 0;
				ffIKanim_lla_angleX = 4;
				this->Move = true;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_LH)
			{
				if (lhIK_flag == 1)
				{
					boneID = 511;
				}
				if (lhIK_flag == 0)
				{
					boneID = 51;
				}
				axis_flag = 'x';
				this->Move = true;
				ffIKlh_x = 1;
				ffIKlh_y = 0;
				ffIKlh_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ffIK_RUL)
			{
				boneID = 506;
				axis_flag = 'x';
				ffIKrul_x = 1;
				ffIKrul_y = 0;
				ffIKrul_z = 0;
				ffIKanim_rul_angleX = 4;
				this->Move = true;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_RLL)
			{
				boneID = 507;
				axis_flag = 'x';
				ffIKrll_x = 1;
				ffIKrll_y = 0;
				ffIKrll_z = 0;
				ffIKanim_rll_angleX = 4;
				this->Move = true;
				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_RF_Actor)
			{
				if (rfIK_flag == 1)
				{
					boneID = 512;
				}
				if (rfIK_flag == 0)
				{
					boneID = 52;
				}
				axis_flag = 'x';
				this->Move = true;
				ffIKrf_x = 1;
				ffIKrf_y = 0;
				ffIKrf_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ffIK_LUL)
			{
				boneID = 508;
				axis_flag = 'x';
				ffIKlul_x = 1;
				ffIKlul_y = 0;
				ffIKlul_z = 0;
				ffIKanim_lul_angleX = 4;
				this->Move = true;
				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_LLL)
			{
				boneID = 509;
				axis_flag = 'x';
				ffIKlll_x = 1;
				ffIKlll_y = 0;
				ffIKlll_z = 0;
				ffIKanim_lll_angleX = 4;
				this->Move = true;
				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_LF_Actor)
			{

				if (lfIK_flag == 1)
				{
					boneID = 513;
				}
				if (lfIK_flag == 0)
				{
					boneID = 53;
				}
				axis_flag = 'x';
				this->Move = true;
				ffIKlf_x = 1;
				ffIKlf_y = 0;
				ffIKlf_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}



			//================================= Free Left Foot and Right Foot =========================//

			if (this->InteractionProp == this->freeLeftFoot_Actor)
			{
				if (lfIK_flag == 1)
				{
					boneID = 1003;
				}
				axis_flag = 'x';
				this->Move = true;
				freeLF_x = 1;
				freeLF_y = 0;
				freeLF_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_freeLeftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();

			}
			if (this->InteractionProp == this->freeRightFoot_Actor)
			{
				if (rfIK_flag == 1)
				{
					boneID = 2003;
				}
				axis_flag = 'x';
				this->Move = true;
				freeRF_x = 1;
				freeRF_y = 0;
				freeRF_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_freeRightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			//================================= Props ==================================================//
			if (this->InteractionProp == this->ConsProp_sphere_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 91;
				this->Move = true;
				//axis_flag = 'y';
				consProp_sphere_x = 0;
				consProp_sphere_y = 1;
				consProp_sphere_z = 0;
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_sphere_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9100;
				this->Move = true;
				//axis_flag = 'y';
				TconsProp_sphere_x = 0;
				TconsProp_sphere_y = 1;
				TconsProp_sphere_z = 0;
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_sphere_actor2)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9200;
				this->Move = true;
				//axis_flag = 'y';
				TconsProp_sphere_x2 = 0;
				TconsProp_sphere_y2 = 1;
				TconsProp_sphere_z2 = 0;
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->TConsProp_sphere_actor3)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9300;
				this->Move = true;
				//axis_flag = 'y';
				TconsProp_sphere_x3 = 0;
				TconsProp_sphere_y3 = 1;
				TconsProp_sphere_z3 = 0;
				mRenderWindow->Render();
			}




			if (this->InteractionProp == this->ConsProp_line_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 92;
				this->Move = true;
				axis_flag = 'y';
				consProp_line_x = 0;
				consProp_line_y = 1;
				consProp_line_z = 0;
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_line_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 9001;
				this->Move = true;
				axis_flag = 'y';
				TconsProp_line_x = 0;
				TconsProp_line_y = 1;
				TconsProp_line_z = 0;
				mRenderWindow->Render();

			}

			if (this->InteractionProp == this->TConsProp_line_actor2)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 9002;
				this->Move = true;
				axis_flag = 'y';
				TconsProp_line_x2 = 0;
				TconsProp_line_y2 = 1;
				TconsProp_line_z2 = 0;
				mRenderWindow->Render();

			}
			if (this->InteractionProp == this->TConsProp_line_actor3)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 9003;
				this->Move = true;
				axis_flag = 'y';
				TconsProp_line_x3 = 0;
				TconsProp_line_y3 = 1;
				TconsProp_line_z3 = 0;
				mRenderWindow->Render();

			}



			if (this->InteractionProp == this->ConsProp_plane_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				boneID = 93;
				this->Move = true;
				axis_flag = 'y';
				consProp_plane_x = 0;
				consProp_plane_y = 1;
				consProp_plane_z = 0;
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ConsProp_cube_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 94;
				this->Move = true;
				axis_flag = 'y';
				consProp_cube_x = 0;
				consProp_cube_y = 1;
				consProp_cube_z = 0;
				mRenderWindow->Render();
			}
		}

		virtual void OnRightButtonUp() override
		{
			boneID = 0;
			vtkInteractorStyleTrackballActor::OnRightButtonUp();
			this->Move = false;

		}
		virtual void OnRightButtonDown() override
		{
			vtkInteractorStyleTrackballActor::OnRightButtonDown();
			flag = 2;


			if (this->InteractionProp == this->tartget)
			{

				b_targetSelect = true;
				boneID = 10;
				this->Move = true;
			}


			if (this->InteractionProp == this->RH_Actor)
			{
				boneID = 3332;
				axis_flag = 'x';
				this->Move = true;
				RH_x = 0;
				RH_y = 0;
				RH_z = 1;
				RH_angle = 4;
				anim_RH_x = 0;
				anim_RH_y = 0;
				anim_RH_z = 1;
				anim_RH_angle = 4;

				COLOR_RightHand_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}
			if (this->InteractionProp == this->RL_Actor)
			{
				boneID = 3333;
				axis_flag = 'x';
				this->Move = true;
				RL_x = 0;
				RL_y = 0;
				RL_z = 1;
				RL_angle = 4;
				anim_RL_x = 0;
				anim_RL_y = 0;
				anim_RL_z = 1;
				anim_RL_angle = 4;

				COLOR_RF_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}


			if (this->InteractionProp == this->headActor)
			{
				boneID = 3331;
				axis_flag = 'y';
				this->Move = true;
				head_x = 0;
				head_y = 0;
				head_z = 1;
				head_angle = 4;
				anim_head_x = 0;
				anim_head_y = 0;
				anim_head_z = 1;
				anim_head_angle = 4;

				COLOR_Head_objActor = "Yellow";

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor_upper).GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());


				RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
			}

			if (this->InteractionProp == this->pelvisActor)
			{

				boneID = 2220;
				axis_flag = 'z';
				this->Move = true;
				pelvis_x = 0;
				pelvis_y = 0;
				pelvis_z = 1;
				anim_pelvis_angle = 4;
				anim_pelvis_x = 0;
				anim_pelvis_y = 0;
				anim_pelvis_z = 1;

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->chestActor)
			{
				boneID = 2221;
				axis_flag = 'z';
				this->Move = true;
				chest_x = 0;
				chest_y = 0;
				chest_z = 1;
				anim_chest_angle = 4;
				anim_chest_x = 0;
				anim_chest_y = 0;
				anim_chest_z = -1;
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;
		*/
				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->RUA)
			{
				boneID = 2222;
				axis_flag = 'z';
				this->Move = true;
				rua_x = 0;
				rua_y = 0;
				rua_z = 1;
				anim_rua_angle = 4;
				anim_rua_x = 0;
				anim_rua_y = 0;
				anim_rua_z = 1;
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());


				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();

			}
			if (this->InteractionProp == this->RLA)
			{
				boneID = 2223;
				axis_flag = 'z';
				this->Move = true;
				rla_x = 0;
				rla_y = 0;
				rla_z = 1;
				anim_rla_angle = 4;
				anim_rla_x = 0;
				anim_rla_y = 0;
				anim_rla_z = 1;
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();


			}
			if (this->InteractionProp == this->LUA)
			{
				boneID = 2224;
				axis_flag = 'z';
				this->Move = true;
				lua_x = 0;
				lua_y = 0;
				lua_z = -1;
				anim_lua_angle = 4;
				anim_lua_x = 0;
				anim_lua_y = 0;
				anim_lua_z = -1;
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();

			}
			if (this->InteractionProp == this->LLA)
			{
				boneID = 2225;
				axis_flag = 'z';
				this->Move = true;
				lla_x = 0;
				lla_y = 0;
				lla_z = -1;
				anim_lla_angle = 4;
				anim_lla_x = 0;
				anim_lla_y = 0;
				anim_lla_z = -1;
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

			}
			if (this->InteractionProp == this->RUL)
			{
				boneID = 2226;
				axis_flag = 'z';
				this->Move = true;
				rul_x = 0;
				rul_y = 0;
				rul_z = 1;
				anim_rul_angle = 4;
				anim_rul_x = 0;
				anim_rul_y = 0;
				anim_rul_z = 1;
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);


				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->RLL)
			{
				boneID = 2227;
				axis_flag = 'z';
				this->Move = true;
				rll_x = 0;
				rll_y = 0;
				rll_z = 1;
				anim_rll_angle = 4;
				anim_rll_x = 0;
				anim_rll_y = 0;
				anim_rll_z = 1;

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->LUL)
			{
				boneID = 2228;
				axis_flag = 'z';
				this->Move = true;
				lul_x = 0;
				lul_y = 0;
				lul_z = -1;
				anim_lul_angle = 4;
				anim_lul_x = 0;
				anim_lul_y = 0;
				anim_lul_z = -1;
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				//dummy1 = 0;
				//dummy2 = 0;
				//dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->LLL)
			{
				boneID = 2229;
				axis_flag = 'z';
				this->Move = true;
				lll_x = 0;
				lll_y = 0;
				lll_z = -1;
				anim_lll_angle = 4;
				anim_lll_x = 0;
				anim_lll_y = 0;
				anim_lll_z = -1;
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();
			}

			//======================================================================================//
			if (this->InteractionProp == this->SM_CH0)
			{

				boneID = 1;
				axis_flag = 'z';
				SMch0_x = 0;
				SMch0_y = 0;
				SMch0_z = 1;
				SManim_ch0_angleZ = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->SM_RUA)
			{
				boneID = 2;
				axis_flag = 'z';
				SMrua_x = 0;
				SMrua_y = 0;
				SMrua_z = 1;
				SManim_rua_angleZ = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_RLA)
			{
				boneID = 3;
				axis_flag = 'z';
				this->Move = true;
				SMrla_x = 0;
				SMrla_y = 0;
				SMrla_z = 1;
				SManim_rla_angleZ = 4;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_RH_Actor)
			{

				if (rhIK_flag == 1)
				{
					boneID = 10;

				}
				if (rhIK_flag == 0)
				{
					boneID = 109;

				}
				axis_flag = 'x';
				this->Move = true;
				SMrh_x = 1;
				SMrh_y = 0;
				SMrh_z = 0;


				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->SM_LUA)
			{

				boneID = 4;
				axis_flag = 'z';
				SMlua_x = 0;
				SMlua_y = 0;
				SMlua_z = 1;
				SManim_lua_angleZ = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_LLA)
			{
				boneID = 5;
				axis_flag = 'z';
				SMlla_x = 0;
				SMlla_y = 0;
				SMlla_z = 1;
				SManim_lla_angleZ = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_LH_Actor)
			{

				if (rhIK_flag == 1)
				{
					boneID = 15;

				}
				if (rhIK_flag == 0)
				{
					boneID = 112;

				}
				axis_flag = 'x';
				this->Move = true;
				SMlh_x = 1;
				SMlh_y = 0;
				SMlh_z = 0;

				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->SM_RUL)
			{
				boneID = 6;
				axis_flag = 'z';
				SMrul_x = 0;
				SMrul_y = 0;
				SMrul_z = 1;
				SManim_rul_angleZ = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_RLL)
			{
				boneID = 7;
				axis_flag = 'z';
				SMrll_x = 0;
				SMrll_y = 0;
				SMrll_z = 1;
				SManim_rll_angleZ = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_RF_Actor)
			{
				if (rfIK_flag == 1)
				{
					boneID = 16;
				}
				if (rfIK_flag == 0)
				{
					boneID = 115;
				}
				axis_flag = 'x';
				this->Move = true;
				SMrf_x = 1;
				SMrf_y = 0;
				SMrf_z = 0;

				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->SM_LUL)
			{
				boneID = 8;
				axis_flag = 'z';
				SMlul_x = 0;
				SMlul_y = 0;
				SMlul_z = 1;
				SManim_lul_angleZ = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_LLL)
			{
				boneID = 9;
				axis_flag = 'z';
				SMlll_x = 0;
				SMlll_y = 0;
				SMlll_z = 1;
				SManim_lll_angleZ = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->SM_LF_Actor)
			{


				if (lfIK_flag == 1)
				{
					boneID = 21;
				}
				if (lfIK_flag == 0)
				{
					boneID = 118;
				}
				axis_flag = 'x';
				this->Move = true;
				SMlf_x = 1;
				SMlf_y = 0;
				SMlf_z = 0;

				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				mRenderWindow->Render();
			}

			//=======================================================================================//

			if (this->InteractionProp == this->ffIK_pelvisActor)
			{
				boneID = 500;
				axis_flag = 'x';
				ffIKpl_x = 1;
				ffIKpl_y = 0;
				ffIKpl_z = 0;
				ffIKanim_pl_angleX = 4;
				this->Move = true;


				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_CH0)
			{
				boneID = 501;
				axis_flag = 'z';
				ffIKch0_x = 0;
				ffIKch0_y = 0;
				ffIKch0_z = 1;
				ffIKanim_ch0_angleZ = 4;
				this->Move = true;
				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ffIK_RUA)
			{
				boneID = 502;
				axis_flag = 'z';
				ffIKrua_x = 0;
				ffIKrua_y = 0;
				ffIKrua_z = 1;
				ffIKanim_rua_angleZ = 4;
				this->Move = true;
				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_RLA)
			{
				boneID = 503;
				axis_flag = 'z';
				ffIKrla_x = 0;
				ffIKrla_y = 0;
				ffIKrla_z = 1;
				ffIKanim_rla_angleZ = 4;
				this->Move = true;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_RH)
			{
				if (rhIK_flag == 1)
				{
					boneID = 510;
				}
				if (rhIK_flag == 0)
				{
					boneID = 50;
				}
				axis_flag = 'x';
				this->Move = true;
				ffIKrh_x = 1;
				ffIKrh_y = 0;
				ffIKrh_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ffIK_LUA)
			{
				boneID = 504;
				axis_flag = 'z';
				ffIKlua_x = 0;
				ffIKlua_y = 0;
				ffIKlua_z = 1;
				ffIKanim_lua_angleZ = 4;
				this->Move = true;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_LLA)
			{
				boneID = 505;
				axis_flag = 'z';
				ffIKlla_x = 0;
				ffIKlla_y = 0;
				ffIKlla_z = 1;
				ffIKanim_lla_angleZ = 4;
				this->Move = true;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ffIK_LH)
			{
				if (lhIK_flag == 1)
				{
					boneID = 511;
				}
				if (lhIK_flag == 0)
				{
					boneID = 51;
				}
				axis_flag = 'x';
				this->Move = true;
				ffIKlh_x = 1;
				ffIKlh_y = 0;
				ffIKlh_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				mRenderWindow->Render();
			}

			//============================================================================================
			if (this->InteractionProp == this->freeLeftFoot_Actor)
			{
				if (lfIK_flag == 1)
				{
					boneID = 1003;
				}
				axis_flag = 'x';
				this->Move = true;
				freeLF_x = 1;
				freeLF_y = 0;
				freeLF_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_freeLeftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();

			}
			if (this->InteractionProp == this->freeRightFoot_Actor)
			{
				if (rfIK_flag == 1)
				{
					boneID = 2003;
				}
				axis_flag = 'x';
				this->Move = true;
				freeRF_x = 1;
				freeRF_y = 0;
				freeRF_z = 0;

				IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_freeRightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

				IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());


				IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				mRenderWindow->Render();
			}

			//============================================================================================
			if (this->InteractionProp == this->ConsProp_sphere_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 91;
				this->Move = true;
				axis_flag = 'x';
				consProp_sphere_x = 1;
				consProp_sphere_y = 0;
				consProp_sphere_z = 0;
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_sphere_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9100;
				this->Move = true;
				axis_flag = 'x';
				TconsProp_sphere_x = 1;
				TconsProp_sphere_y = 0;
				TconsProp_sphere_z = 0;
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->TConsProp_sphere_actor2)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9200;
				this->Move = true;
				axis_flag = 'x';
				TconsProp_sphere_x2 = 1;
				TconsProp_sphere_y2 = 0;
				TconsProp_sphere_z2 = 0;
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->TConsProp_sphere_actor3)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9300;
				this->Move = true;
				axis_flag = 'x';
				TconsProp_sphere_x3 = 1;
				TconsProp_sphere_y3 = 0;
				TconsProp_sphere_z3 = 0;
				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->ConsProp_line_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 92;
				this->Move = true;
				axis_flag = 'x';
				consProp_line_x = 1;
				consProp_line_y = 0;
				consProp_line_z = 0;
				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->TConsProp_line_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9001;
				this->Move = true;
				axis_flag = 'x';
				TconsProp_line_x = 1;
				TconsProp_line_y = 0;
				TconsProp_line_z = 0;
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->TConsProp_line_actor2)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9002;
				this->Move = true;
				axis_flag = 'x';
				TconsProp_line_x2 = 1;
				TconsProp_line_y2 = 0;
				TconsProp_line_z2 = 0;
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->TConsProp_line_actor3)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9003;
				this->Move = true;
				axis_flag = 'x';
				TconsProp_line_x3 = 1;
				TconsProp_line_y3 = 0;
				TconsProp_line_z3 = 0;
				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->ConsProp_plane_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 93;
				this->Move = true;
				axis_flag = 'x';
				consProp_plane_x = 1;
				consProp_plane_y = 0;
				consProp_plane_z = 0;
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ConsProp_cube_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 94;
				this->Move = true;
				axis_flag = 'x';
				consProp_cube_x = 1;
				consProp_cube_y = 0;
				consProp_cube_z = 0;
				mRenderWindow->Render();
			}
		}

		virtual void OnMouseWheelForward()  override
		{

			vtkInteractorStyleTrackballActor::OnMouseWheelForward();

			flag = 3;

			if (this->InteractionProp == this->chestActor)
			{
				/*	boneID = 1;
					axis_flag = 'y';

					chest_x = 0;
					chest_y = 1;
					chest_z = 0;
					anim_chest_angle = 4;
					anim_chest_x = 0;
					anim_chest_y = 1;
					anim_chest_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);



				compute(chest_angle, chest_x, chest_y, chest_z, boneID);
				CHEST(anim_chest_angle, anim_chest_x, anim_chest_y, anim_chest_z);
				chest_angle += 4;
			}

			if (this->InteractionProp == this->RUA)
			{
				/*boneID = 2;
				axis_flag = 'y';

				rua_x = 0;
				rua_y = 1;
				rua_z = 0;
				anim_rua_angle = 4;
				anim_rua_x = 0;
				anim_rua_y = 1;
				anim_rua_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				//dummy1 = 0;
				//dummy2 = 0;
				//dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();

				/*	compute(rua_angle, rua_x, rua_y, rua_z, boneID);
					rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);
					rua_angle++;*/

				compute(rua_angleY, rua_x, rua_y, rua_z, boneID);
				rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);
				rua_angleY += 4;
				/*rua_angleY += 4;
				cout << "ruaY_angle=" << rua_angleY << endl;*/


			}
			if (this->InteractionProp == this->RLA)
			{
				/*boneID = 3;
				axis_flag = 'y';

				rla_x = 0;
				rla_y = 1;
				rla_z = 0;
				anim_rla_angle = 4;
				anim_rla_x = 0;
				anim_rla_y = 1;
				anim_rla_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				//dummy1 = 0;
				//dummy2 = 0;
				//dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

				//compute(rla_angle, rla_x, rla_y, rla_z, boneID);
				//rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);
				//rla_angle++;


				compute(rla_angleY, rla_x, rla_y, rla_z, boneID);
				rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);
				rla_angleY += 4;


			}

			if (this->InteractionProp == this->LUA)
			{
				/*boneID = 4;
				axis_flag = 'y';

				lua_x = 0;
				lua_y = 1;
				lua_z = 0;
				anim_lua_angle = 4;
				anim_lua_x = 0;
				anim_lua_y = 1;
				anim_lua_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();

				compute(lua_angle, lua_x, lua_y, lua_z, boneID);
				lua(anim_lua_angle, anim_lua_x, anim_lua_y, anim_lua_z);
				lua_angle += 4;

			}
			if (this->InteractionProp == this->LLA)
			{
				/*boneID = 5;
				axis_flag = 'y';

				lla_x = 0;
				lla_y = 1;
				lla_z = 0;
				anim_lla_angle = 4;
				anim_lla_x = 0;
				anim_lla_y = 1;
				anim_lla_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();

				compute(lla_angle, lla_x, lla_y, lla_z, boneID);
				lla(anim_lla_angle, anim_lla_x, anim_lla_y, anim_lla_z);
				lla_angle += 4;

			}

			if (this->InteractionProp == this->RUL)
			{
				/*boneID = 6;
				axis_flag = 'y';

				rul_x = 0;
				rul_y = 1;
				rul_z = 0;
				anim_rul_angle = 4;
				anim_rul_x = 0;
				anim_rul_y = 1;
				anim_rul_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();


				compute(rul_angle, rul_x, rul_y, rul_z, boneID);
				rul(anim_rul_angle, anim_rul_x, anim_rul_y, anim_rul_z);
				rul_angle += 4;

			}
			if (this->InteractionProp == this->RLL)
			{
				/*boneID = 7;
				axis_flag = 'y';

				rll_x = 0;
				rll_y = 1;
				rll_z = 0;
				anim_rll_angle = 4;
				anim_rll_x = 0;
				anim_rll_y = 1;
				anim_rll_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());


				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();


				compute(rll_angle, rll_x, rll_y, rll_z, boneID);
				rll(anim_rll_angle, anim_rll_x, anim_rll_y, anim_rll_z);
				rll_angle += 4;



			}

			if (this->InteractionProp == this->LUL)
			{
				/*boneID = 8;
				axis_flag = 'y';

				lul_x = 0;
				lul_y = 1;
				lul_z = 0;
				anim_lul_angle = 4;
				anim_lul_x = 0;
				anim_lul_y = 1;
				anim_lul_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();

				compute(lul_angle, lul_x, lul_y, lul_z, boneID);
				lul(anim_lul_angle, anim_lul_x, anim_lul_y, anim_lul_z);
				lul_angle += 4;

			}
			if (this->InteractionProp == this->LLL)
			{
				/*boneID = 9;
				axis_flag = 'y';

				lll_x = 0;
				lll_y = 1;
				lll_z = 0;
				anim_lll_angle = 4;
				anim_lll_x = 0;
				anim_lll_y = 1;
				anim_lll_z = 0;*/
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();


				compute(lll_angle, lll_x, lll_y, lll_z, boneID);
				lll(anim_lll_angle, anim_lll_x, anim_lll_y, anim_lll_z);
				lll_angle += 4;

			}

			//============================================================================================================
			if (this->InteractionProp == this->SM_CH0)
			{

				boneID = 1;
				axis_flag = 'y';
				SMch0_x = 0;
				SMch0_y = 1;
				SMch0_z = 0;
				SManim_ch0_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();


				SMch0_angleY += 4;
				animateSM_CH0(SManim_ch0_angleY, -SMch0_x, -SMch0_y, -SMch0_z);
				compute(SMch0_angleY, -SMch0_x, -SMch0_y, -SMch0_z, boneID);

			}

			if (this->InteractionProp == this->SM_RUA)
			{
				boneID = 2;
				axis_flag = 'y';
				SMrua_x = 0;
				SMrua_y = 1;
				SMrua_z = 0;
				SManim_rua_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();

				SMrua_angleY += 4;
				animateSM_RUA(SManim_rua_angleY, -SMrua_x, -SMrua_y, -SMrua_z);
				compute(SMrua_angleY, -SMrua_x, -SMrua_y, -SMrua_z, boneID);
			}
			if (this->InteractionProp == this->SM_RLA)
			{
				boneID = 3;
				axis_flag = 'y';
				this->Move = true;
				SMrla_x = 0;
				SMrla_y = 1;
				SMrla_z = 0;
				SManim_rla_angleY = 4;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();

				SMrla_angleY += 4;
				animateSM_RLA(SManim_rla_angleY, -SMrla_x, -SMrla_y, -SMrla_z);
				compute(SMrla_angleY, -SMrla_x, -SMrla_y, -SMrla_z, boneID);
			}

			if (this->InteractionProp == this->SM_LUA)
			{

				boneID = 4;
				axis_flag = 'y';
				SMlua_x = 0;
				SMlua_y = 1;
				SMlua_z = 0;
				SManim_lua_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();

				SMlua_angleY += 4;
				animateSM_LUA(SManim_lua_angleY, SMlua_x, SMlua_y, SMlua_z);
				compute(SMlua_angleY, SMlua_x, SMlua_y, SMlua_z, boneID);
			}
			if (this->InteractionProp == this->SM_LLA)
			{
				boneID = 5;
				axis_flag = 'y';
				SMlla_x = 0;
				SMlla_y = 1;
				SMlla_z = 0;
				SManim_lla_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();

				SMlla_angleY += 4;
				animateSM_LLA(SManim_lla_angleY, SMlla_x, SMlla_y, SMlla_z);
				compute(SMlla_angleY, SMlla_x, SMlla_y, SMlla_z, boneID);
			}


			if (this->InteractionProp == this->SM_RUL)
			{
				boneID = 6;
				axis_flag = 'y';
				SMrul_x = 0;
				SMrul_y = 1;
				SMrul_z = 0;
				SManim_rul_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();

				SMrul_angleY += 4;
				animateSM_RUL(SManim_rul_angleY, -SMrul_x, -SMrul_y, -SMrul_z);
				compute(SMrul_angleY, -SMrul_x, -SMrul_y, -SMrul_z, boneID);
			}
			if (this->InteractionProp == this->SM_RLL)
			{
				boneID = 7;
				axis_flag = 'y';
				SMrll_x = 0;
				SMrll_y = 1;
				SMrll_z = 0;
				SManim_rll_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();


				SMrll_angleY += 4;
				animateSM_RLL(SManim_rll_angleY, -SMrll_x, -SMrll_y, -SMrll_z);
				compute(SMrll_angleY, -SMrll_x, -SMrll_y, -SMrll_z, boneID);
			}

			if (this->InteractionProp == this->SM_LUL)
			{
				boneID = 8;
				axis_flag = 'y';
				SMlul_x = 0;
				SMlul_y = 1;
				SMlul_z = 0;
				SManim_lul_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();


				SMlul_angleY += 4;
				animateSM_LUL(SManim_lul_angleY, SMlul_x, SMlul_y, SMlul_z);
				compute(SMlul_angleY, SMlul_x, SMlul_y, SMlul_z, boneID);

			}
			if (this->InteractionProp == this->SM_LLL)
			{
				boneID = 9;
				axis_flag = 'y';
				SMlll_x = 0;
				SMlll_y = 1;
				SMlll_z = 0;
				SManim_lll_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();


				SMlll_angleY += 4;
				animateSM_LLL(SManim_lll_angleY, SMlll_x, SMlll_y, SMlll_z);
				compute(SMlll_angleY, SMlll_x, SMlll_y, SMlll_z, boneID);
			}

			//==============================================================================================================
			if (this->InteractionProp == this->ConsProp_sphere_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 91;
				//this->Move = true;
				axis_flag = 'z';
				consProp_sphere_x = 0;
				consProp_sphere_y = 0;
				consProp_sphere_z = 1;

				moveSphereProp(consProp_sphere_x, consProp_sphere_y, consProp_sphere_z);

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->TConsProp_sphere_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9100;
				//this->Move = true;
				axis_flag = 'z';
				TconsProp_sphere_x = 0;
				TconsProp_sphere_y = 0;
				TconsProp_sphere_z = 1;

				TmoveSphereProp(TconsProp_sphere_x, TconsProp_sphere_y, TconsProp_sphere_z);

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_sphere_actor2)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9200;
				//this->Move = true;
				axis_flag = 'z';
				TconsProp_sphere_x2 = 0;
				TconsProp_sphere_y2 = 0;
				TconsProp_sphere_z2 = 1;

				TmoveSphereProp2(TconsProp_sphere_x2, TconsProp_sphere_y2, TconsProp_sphere_z2);

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_sphere_actor3)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9300;
				//this->Move = true;
				axis_flag = 'z';
				TconsProp_sphere_x3 = 0;
				TconsProp_sphere_y3 = 0;
				TconsProp_sphere_z3 = 1;

				TmoveSphereProp3(TconsProp_sphere_x3, TconsProp_sphere_y3, TconsProp_sphere_z3);

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->ConsProp_line_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 92;
				/*this->Move = true;*/
				axis_flag = 'z';
				consProp_line_x = 0;
				consProp_line_y = 0;
				consProp_line_z = 1;
				moveLineProp(consProp_line_x, consProp_line_y, consProp_line_z);
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_line_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9001;
				/*this->Move = true;*/
				axis_flag = 'z';
				TconsProp_line_x = 0;
				TconsProp_line_y = 0;
				TconsProp_line_z = 1;
				TmoveLineProp(TconsProp_line_x, TconsProp_line_y, TconsProp_line_z);
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_line_actor2)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9002;
				/*this->Move = true;*/
				axis_flag = 'z';
				TconsProp_line_x2 = 0;
				TconsProp_line_y2 = 0;
				TconsProp_line_z2 = 1;
				TmoveLineProp2(TconsProp_line_x2, TconsProp_line_y2, TconsProp_line_z2);
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_line_actor3)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9003;
				/*this->Move = true;*/
				axis_flag = 'z';
				TconsProp_line_x3 = 0;
				TconsProp_line_y3 = 0;
				TconsProp_line_z3 = 1;
				TmoveLineProp3(TconsProp_line_x3, TconsProp_line_y3, TconsProp_line_z3);
				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->ConsProp_plane_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 93;
				/*this->Move = true;*/
				axis_flag = 'z';
				consProp_plane_x = 0;
				consProp_plane_y = 0;
				consProp_plane_z = 1;
				movePlaneProp(consProp_plane_x, consProp_plane_y, consProp_plane_z);
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ConsProp_cube_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 94;
				/*this->Move = true;*/
				axis_flag = 'z';
				consProp_cube_x = 0;
				consProp_cube_y = 0;
				consProp_cube_z = 1;
				moveCubeProp(consProp_cube_x, consProp_cube_y, consProp_cube_z);
				mRenderWindow->Render();
			}

		}
		virtual void OnMouseWheelBackward()  override
		{

			vtkInteractorStyleTrackballActor::OnMouseWheelBackward();

			flag = 3;

			if (this->InteractionProp == this->chestActor)
			{
				/*boneID = 1;
				axis_flag = 'y';

				chest_x = 0;
				chest_y = 1;
				chest_z = 0;
				anim_chest_angle = 4;
				anim_chest_x = 0;
				anim_chest_y = 1;
				anim_chest_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

				chest_angle -= 4;
				compute(chest_angle, chest_x, chest_y, chest_z, boneID);
				CHEST(anim_chest_angle, anim_chest_x, -anim_chest_y, anim_chest_z);

			}

			if (this->InteractionProp == this->RUA)
			{
				/*boneID = 2;
				axis_flag = 'y';

				rua_x = 0;
				rua_y = 1;
				rua_z = 0;
				anim_rua_angle = 4;
				anim_rua_x = 0;
				anim_rua_y = 1;
				anim_rua_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				//dummy1 = 0;
				//dummy2 = 0;
				//dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);

				mRenderWindow->Render();

				/*	compute(rua_angle, rua_x, rua_y, rua_z, boneID);
					rua(anim_rua_angle, anim_rua_x, -anim_rua_y, anim_rua_z);
					rua_angle--;*/

				rua_angleY -= 4;
				compute(rua_angleY, rua_x, rua_y, rua_z, boneID);
				rua(anim_rua_angle, anim_rua_x, -anim_rua_y, anim_rua_z);


				//rua_angleY -= 4;
				//cout << "ruaY_angle=" << rua_angleY << endl;
			}
			if (this->InteractionProp == this->RLA)
			{
				/*boneID = 3;
				axis_flag = 'y';

				rla_x = 0;
				rla_y = 1;
				rla_z = 0;
				anim_rla_angle = 4;
				anim_rla_x = 0;
				anim_rla_y = 1;
				anim_rla_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

				//compute(rla_angle, rla_x, rla_y, rla_z, boneID);
				//rla_angle--;
				//rla(anim_rla_angle, anim_rla_x, -anim_rla_y, anim_rla_z);

				rla_angleY -= 4;
				compute(rla_angleY, rla_x, rla_y, rla_z, boneID);
				rla(anim_rla_angle, anim_rla_x, -anim_rla_y, anim_rla_z);


			}

			if (this->InteractionProp == this->LUA)
			{
				/*boneID = 4;
				axis_flag = 'y';

				lua_x = 0;
				lua_y = 1;
				lua_z = 0;
				anim_lua_angle = 4;
				anim_lua_x = 0;
				anim_lua_y = 1;
				anim_lua_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());


				dummy1 = 0;
				dummy2 = 0;
				dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

				lua_angle -= 4;
				compute(lua_angle, lua_x, lua_y, lua_z, boneID);
				lua(anim_lua_angle, anim_lua_x, -anim_lua_y, anim_lua_z);

			}
			if (this->InteractionProp == this->LLA)
			{
				/*boneID = 5;
				axis_flag = 'y';

				lla_x = 0;
				lla_y = 1;
				lla_z = 0;
				anim_lla_angle = 4;
				anim_lla_x = 0;
				anim_lla_y = 1;
				anim_lla_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0*/;

					std::string tA1 = "( ";
					std::string tA2 = std::to_string(dummy1);
					std::string tA3 = " ,";
					std::string tA4 = std::to_string(dummy2);
					std::string tA5 = " ,";
					std::string tA6 = std::to_string(dummy3);
					std::string tA7 = " )";


					std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
					const char* text = tA.data();


					textActor->SetInput(text);
					mRenderWindow->Render();

					lla_angle -= 4;
					compute(lla_angle, lla_x, lla_y, lla_z, boneID);
					lla(anim_lla_angle, anim_lla_x, -anim_lla_y, anim_lla_z);



			}

			if (this->InteractionProp == this->RUL)
			{
				/*boneID = 6;
				axis_flag = 'y';

				rul_x = 0;
				rul_y = 1;
				rul_z = 0;
				anim_rul_angle = 4;
				anim_rul_x = 0;
				anim_rul_y = 1;
				anim_rul_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				dummy1 = 0;
				dummy2 = 0;
				dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

				rul_angle -= 4;
				compute(rul_angle, rul_x, rul_y, rul_z, boneID);
				rul(anim_rul_angle, anim_rul_x, -anim_rul_y, anim_rul_z);
			}
			if (this->InteractionProp == this->RLL)
			{
				/*boneID = 7;
				axis_flag = 'y';

				rll_x = 0;
				rll_y = 1;
				rll_z = 0;
				anim_rll_angle = 4;
				anim_rll_x = 0;
				anim_rll_y = 1;
				anim_rll_z = 0;*/
				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				/*	dummy1 = 0;
					dummy2 = 0;
					dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

				rll_angle -= 4;
				compute(rll_angle, rll_x, rll_y, rll_z, boneID);
				rll(anim_rll_angle, anim_rll_x, -anim_rll_y, anim_rll_z);

			}

			if (this->InteractionProp == this->LUL)
			{
				/*boneID = 8;
				axis_flag = 'y';

				lul_x = 0;
				lul_y = 1;
				lul_z = 0;
				anim_lul_angle = 4;
				anim_lul_x = 0;
				anim_lul_y = 1;
				anim_lul_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());


				/*		dummy1 = 0;
						dummy2 = 0;
						dummy3 = 0;*/

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

				lul_angle -= 4;
				compute(lul_angle, lul_x, lul_y, lul_z, boneID);
				lul(anim_lul_angle, anim_lul_x, -anim_lul_y, anim_lul_z);
			}
			if (this->InteractionProp == this->LLL)
			{
				/*boneID = 9;
				axis_flag = 'y';

				lll_x = 0;
				lll_y = 1;
				lll_z = 0;
				anim_lll_angle = 4;
				anim_lll_x = 0;
				anim_lll_y = 1;
				anim_lll_z = 0;*/

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());


				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				dummy1 = 0;
				dummy2 = 0;
				dummy3 = 0;

				std::string tA1 = "( ";
				std::string tA2 = std::to_string(dummy1);
				std::string tA3 = " ,";
				std::string tA4 = std::to_string(dummy2);
				std::string tA5 = " ,";
				std::string tA6 = std::to_string(dummy3);
				std::string tA7 = " )";


				std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
				const char* text = tA.data();


				textActor->SetInput(text);
				mRenderWindow->Render();

				lll_angle -= 4;
				compute(lll_angle, lll_x, lll_y, lll_z, boneID);
				lll(anim_lll_angle, anim_lll_x, -anim_lll_y, anim_lll_z);

			}


			//=================================================================================

			if (this->InteractionProp == this->SM_CH0)
			{
				boneID = 1;
				axis_flag = 'y';
				SMch0_x = 0;
				SMch0_y = 1;
				SMch0_z = 0;
				SManim_ch0_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();



				animateSM_CH0(SManim_ch0_angleY, SMch0_x, SMch0_y, SMch0_z);
				SMch0_angleY -= 4;
				compute(SMch0_angleY, -SMch0_x, -SMch0_y, -SMch0_z, boneID);

			}

			if (this->InteractionProp == this->SM_RUA)
			{
				boneID = 2;
				axis_flag = 'y';
				SMrua_x = 0;
				SMrua_y = 1;
				SMrua_z = 0;
				SManim_rua_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();


				animateSM_RUA(SManim_rua_angleY, SMrua_x, SMrua_y, SMrua_z);
				SMrua_angleY -= 4;
				compute(SMrua_angleY, -SMrua_x, -SMrua_y, -SMrua_z, boneID);
			}
			if (this->InteractionProp == this->SM_RLA)
			{
				boneID = 3;
				axis_flag = 'y';
				this->Move = true;
				SMrla_x = 0;
				SMrla_y = 1;
				SMrla_z = 0;
				SManim_rla_angleY = 4;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();


				animateSM_RLA(SManim_rla_angleY, SMrla_x, SMrla_y, SMrla_z);
				SMrla_angleY -= 4;
				compute(SMrla_angleY, -SMrla_x, -SMrla_y, -SMrla_z, boneID);
			}

			if (this->InteractionProp == this->SM_LUA)
			{

				boneID = 4;
				axis_flag = 'y';
				SMlua_x = 0;
				SMlua_y = 1;
				SMlua_z = 0;
				SManim_lua_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();


				animateSM_LUA(SManim_lua_angleY, -SMlua_x, -SMlua_y, -SMlua_z);
				SMlua_angleY -= 4;
				compute(SMlua_angleY, SMlua_x, SMlua_y, SMlua_z, boneID);
			}
			if (this->InteractionProp == this->SM_LLA)
			{
				boneID = 5;
				axis_flag = 'y';
				SMlla_x = 0;
				SMlla_y = 1;
				SMlla_z = 0;
				SManim_lla_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();


				animateSM_LLA(SManim_lla_angleY, -SMlla_x, -SMlla_y, -SMlla_z);
				SMlla_angleY -= 4;
				compute(SMlla_angleY, SMlla_x, SMlla_y, SMlla_z, boneID);
			}


			if (this->InteractionProp == this->SM_RUL)
			{
				boneID = 6;
				axis_flag = 'y';
				SMrul_x = 0;
				SMrul_y = 1;
				SMrul_z = 0;
				SManim_rul_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();


				animateSM_RUL(SManim_rul_angleY, SMrul_x, SMrul_y, SMrul_z);
				SMrul_angleY -= 4;
				compute(SMrul_angleY, -SMrul_x, -SMrul_y, -SMrul_z, boneID);
			}
			if (this->InteractionProp == this->SM_RLL)
			{
				boneID = 7;
				axis_flag = 'y';
				SMrll_x = 0;
				SMrll_y = 1;
				SMrll_z = 0;
				SManim_rll_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();



				animateSM_RLL(SManim_rll_angleY, SMrll_x, SMrll_y, SMrll_z);
				SMrll_angleY -= 4;
				compute(SMrll_angleY, -SMrll_x, -SMrll_y, -SMrll_z, boneID);
			}

			if (this->InteractionProp == this->SM_LUL)
			{
				boneID = 8;
				axis_flag = 'y';
				SMlul_x = 0;
				SMlul_y = 1;
				SMlul_z = 0;
				SManim_lul_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();



				animateSM_LUL(SManim_lul_angleY, -SMlul_x, -SMlul_y, -SMlul_z);
				SMlul_angleY -= 4;
				compute(SMlul_angleY, SMlul_x, SMlul_y, SMlul_z, boneID);

			}
			if (this->InteractionProp == this->SM_LLL)
			{
				boneID = 9;
				axis_flag = 'y';
				SMlll_x = 0;
				SMlll_y = 1;
				SMlll_z = 0;
				SManim_lll_angleY = 4;
				this->Move = true;
				stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
				stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
				stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				mRenderWindow->Render();



				animateSM_LLL(SManim_lll_angleY, -SMlll_x, -SMlll_y, -SMlll_z);
				SMlll_angleY -= 4;
				compute(SMlll_angleY, SMlll_x, SMlll_y, SMlll_z, boneID);
			}

			//===================================================================================
			if (this->InteractionProp == this->ConsProp_sphere_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 91;
				//this->Move = true;
				axis_flag = 'z';
				consProp_sphere_x = 0;
				consProp_sphere_y = 0;
				consProp_sphere_z = 1;

				moveSphereProp(-consProp_sphere_x, -consProp_sphere_y, -consProp_sphere_z);

				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_sphere_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9100;
				//this->Move = true;
				axis_flag = 'z';
				TconsProp_sphere_x = 0;
				TconsProp_sphere_y = 0;
				TconsProp_sphere_z = 1;

				TmoveSphereProp(-TconsProp_sphere_x, -TconsProp_sphere_y, -TconsProp_sphere_z);

				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->TConsProp_sphere_actor2)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9200;
				//this->Move = true;
				axis_flag = 'z';
				TconsProp_sphere_x2 = 0;
				TconsProp_sphere_y2 = 0;
				TconsProp_sphere_z2 = 1;

				TmoveSphereProp2(-TconsProp_sphere_x2, -TconsProp_sphere_y2, -TconsProp_sphere_z2);

				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->TConsProp_sphere_actor3)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());

				boneID = 9300;
				//this->Move = true;
				axis_flag = 'z';
				TconsProp_sphere_x3 = 0;
				TconsProp_sphere_y3 = 0;
				TconsProp_sphere_z3 = 1;

				TmoveSphereProp3(-TconsProp_sphere_x3, -TconsProp_sphere_y3, -TconsProp_sphere_z3);

				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->ConsProp_line_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 92;
				/*this->Move = true;*/
				axis_flag = 'z';
				consProp_line_x = 0;
				consProp_line_y = 0;
				consProp_line_z = 1;
				moveLineProp(-consProp_line_x, -consProp_line_y, -consProp_line_z);
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_line_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 9001;
				/*this->Move = true;*/
				axis_flag = 'z';
				TconsProp_line_x = 0;
				TconsProp_line_y = 0;
				TconsProp_line_z = 1;
				TmoveLineProp(-TconsProp_line_x, -TconsProp_line_y, -TconsProp_line_z);
				mRenderWindow->Render();
			}


			if (this->InteractionProp == this->TConsProp_line_actor2)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 9002;
				/*this->Move = true;*/
				axis_flag = 'z';
				TconsProp_line_x2 = 0;
				TconsProp_line_y2 = 0;
				TconsProp_line_z2 = 1;
				TmoveLineProp2(-TconsProp_line_x2, -TconsProp_line_y2, -TconsProp_line_z2);
				mRenderWindow->Render();
			}

			if (this->InteractionProp == this->TConsProp_line_actor3)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 9003;
				/*this->Move = true;*/
				axis_flag = 'z';
				TconsProp_line_x3 = 0;
				TconsProp_line_y3 = 0;
				TconsProp_line_z3 = 1;
				TmoveLineProp3(-TconsProp_line_x3, -TconsProp_line_y3, -TconsProp_line_z3);
				mRenderWindow->Render();
			}



			if (this->InteractionProp == this->ConsProp_plane_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 93;
				/*this->Move = true;*/
				axis_flag = 'z';
				consProp_plane_x = 0;
				consProp_plane_y = 0;
				consProp_plane_z = 1;
				movePlaneProp(-consProp_plane_x, -consProp_plane_y, -consProp_plane_z);
				mRenderWindow->Render();
			}
			if (this->InteractionProp == this->ConsProp_cube_actor)
			{
				ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
				ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
				Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
				RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());

				RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
				LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());


				boneID = 94;
				/*this->Move = true;*/
				axis_flag = 'z';
				consProp_cube_x = 0;
				consProp_cube_y = 0;
				consProp_cube_z = 1;
				moveCubeProp(-consProp_cube_x, -consProp_cube_y, -consProp_cube_z);
				mRenderWindow->Render();
			}
		}
	};

	vtkStandardNewMacro(customMouseInteractorStyle);

} // namespace

void robotModel(int rotate)
{
	colorSetting(1, "Gray");

	Pelvis_ObjReader->SetFileName(Pelvis_objFilename.c_str());
	PlconeMapper->SetInputConnection(Pelvis_ObjReader->GetOutputPort());
	PlconeTransform->Translate(pelvisObj_xpos, pelvisObj_ypos, pelvisObj_zpos);
	PlconeActor->SetUserTransform(PlconeTransform);
	PlconeActor->SetMapper(PlconeMapper);
	PlconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_PlconeActor).GetData());
	PlconeActor->SetScale(pelvisObj_scale);


	Chest_ObjReader->SetFileName(Chest_objFilename.c_str());
	CUconeMapper->SetInputConnection(Chest_ObjReader->GetOutputPort());
	CUconeTransform->Translate(chestObj_xpos, chestObj_ypos, chestObj_zpos);
	CUconeTransform->SetInput(PlconeTransform);
	CUconeActor->SetUserTransform(CUconeTransform);
	CUconeActor->SetMapper(CUconeMapper);
	CUconeActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_CUconeActor).GetData());
	CUconeActor->SetScale(chestObj_scale);


	headNeck_ObjReader->SetFileName(headNeck_objFilename.c_str());
	Head_ObjReader_mapper->SetInputConnection(headNeck_ObjReader->GetOutputPort());
	Head_ObjReader_Transform->Translate(head_NeckObj_xpos, head_NeckObj_ypos, head_NeckObj_zpos);
	Head_ObjReader_Transform->SetInput(CUconeTransform);
	Head_objActor->SetUserTransform(Head_ObjReader_Transform);
	Head_objActor->SetMapper(Head_ObjReader_mapper);
	Head_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_Head_objActor).GetData());
	Head_objActor->SetScale(head_NeckObj_scale);
	headTexture_reader->SetFileName(headTexture_filename);
	// Apply the texture
	head_texture->SetInputConnection(headTexture_reader->GetOutputPort());
	Head_objActor->SetTexture(head_texture);


	RUA_ObjReader->SetFileName(RUA_objFilename.c_str());
	//RarmMapper->SetInputConnection(RUA_ObjReader->GetOutputPort());
	RarmMapper->SetInputConnection(RUA_collide->GetOutputPort(0));
	RarmMapper->ScalarVisibilityOff();
	RarmTransform->Translate(ruaObj_xpos, ruaObj_ypos, ruaObj_zpos);
	RarmTransform->SetInput(CUconeTransform);
	RarmActor->SetUserTransform(RarmTransform);
	RarmActor->SetMapper(RarmMapper);
	RarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RarmActor).GetData());
	RarmActor->SetScale(ruaObj_scale);


	RLA_ObjReader->SetFileName(RLA_objFilename.c_str());
	RforearmMapper->SetInputConnection(RLA_ObjReader->GetOutputPort());
	RforearmTransform->Translate(rlaObj_xpos, rlaObj_ypos, rlaObj_zpos);
	RforearmTransform->SetInput(RarmTransform);
	RforearmActor->SetUserTransform(RforearmTransform);
	RforearmActor->SetMapper(RforearmMapper);
	RforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RforearmActor).GetData());
	RforearmActor->SetScale(rlaObj_scale);



	ConstraintProp_sphereSource->SetCenter(0.0, 50.0, 10.0);
	ConstraintProp_sphereSource->SetRadius(consProp_sphere_size);
	ConstraintProp_sphereSource->SetPhiResolution(100);
	ConstraintProp_sphereSource->SetThetaResolution(100);
	ConstraintProp_sphere_mapper->SetInputConnection(ConstraintProp_sphereSource->GetOutputPort());
	ConstraintProp_sphere_mapper->ScalarVisibilityOff();
	ConstraintProp_sphere_actor->SetUserTransform(ConstraintProp_sphere_transform);
	ConstraintProp_sphere_actor->SetMapper(ConstraintProp_sphere_mapper);
	ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_sphere_actor).GetData());
	ConstraintProp_sphere_actor->SetScale(1);


	TConstraintProp_sphereSource->SetCenter(0.0, 10.0, 10.0);
	TConstraintProp_sphereSource->SetRadius(consProp_sphere_size);
	TConstraintProp_sphereSource->SetPhiResolution(100);
	TConstraintProp_sphereSource->SetThetaResolution(100);
	TConstraintProp_sphere_mapper->SetInputConnection(TConstraintProp_sphereSource->GetOutputPort());
	TConstraintProp_sphere_mapper->ScalarVisibilityOff();
	TConstraintProp_sphere_actor->SetUserTransform(TConstraintProp_sphere_transform);
	TConstraintProp_sphere_actor->SetMapper(TConstraintProp_sphere_mapper);
	TConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d(COLOR_TConstraintProp_sphere_actor).GetData());
	TConstraintProp_sphere_actor->SetScale(1);


	TConstraintProp_sphereSource2->SetCenter(10.0, 10.0, 10.0);
	TConstraintProp_sphereSource2->SetRadius(consProp_sphere_size);
	TConstraintProp_sphereSource2->SetPhiResolution(100);
	TConstraintProp_sphereSource2->SetThetaResolution(100);
	TConstraintProp_sphere_mapper2->SetInputConnection(TConstraintProp_sphereSource2->GetOutputPort());
	TConstraintProp_sphere_mapper2->ScalarVisibilityOff();
	TConstraintProp_sphere_actor2->SetUserTransform(TConstraintProp_sphere_transform2);
	TConstraintProp_sphere_actor2->SetMapper(TConstraintProp_sphere_mapper2);
	TConstraintProp_sphere_actor2->GetProperty()->SetColor(colors->GetColor3d(COLOR_TConstraintProp_sphere_actor2).GetData());
	TConstraintProp_sphere_actor2->SetScale(1);


	TConstraintProp_sphereSource3->SetCenter(20.0, 10.0, 10.0);
	TConstraintProp_sphereSource3->SetRadius(consProp_sphere_size);
	TConstraintProp_sphereSource3->SetPhiResolution(100);
	TConstraintProp_sphereSource3->SetThetaResolution(100);
	TConstraintProp_sphere_mapper3->SetInputConnection(TConstraintProp_sphereSource3->GetOutputPort());
	TConstraintProp_sphere_mapper3->ScalarVisibilityOff();
	TConstraintProp_sphere_actor3->SetUserTransform(TConstraintProp_sphere_transform3);
	TConstraintProp_sphere_actor3->SetMapper(TConstraintProp_sphere_mapper3);
	TConstraintProp_sphere_actor3->GetProperty()->SetColor(colors->GetColor3d(COLOR_TConstraintProp_sphere_actor3).GetData());
	TConstraintProp_sphere_actor3->SetScale(1);




	ConstraintProp_lineSource1->SetTipLength(0);
	ConstraintProp_lineSource1->SetTipResolution(0);
	ConstraintProp_lineSource1->Update();

	ConstraintProp_line_mapper1->SetInputData(RUA_collide->GetOutput(1));
	ConstraintProp_line_mapper1->ScalarVisibilityOff();
	ConstraintProp_line_transform1->Translate(-30.0, 65.25, 5);
	ConstraintProp_line_actor1->SetMapper(ConstraintProp_line_mapper1);
	ConstraintProp_line_actor1->SetUserTransform(ConstraintProp_line_transform1);
	ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d(COLOR_ConstraintProp_line_actor1).GetData());
	ConstraintProp_line_actor1->SetScale(50);






	RUA_collide->SetInputConnection(0, RUA_ObjReader->GetOutputPort(0));
	RUA_collide->SetTransform(0, RarmTransform);

	RUA_collide->SetInputConnection(1, ConstraintProp_lineSource1->GetOutputPort());
	RUA_collide->SetMatrix(1, matrix1);

	RUA_collide->SetTransform(1, ConstraintProp_line_transform1);
	RUA_collide->SetBoxTolerance(0.0);
	RUA_collide->SetCellTolerance(0.0);
	RUA_collide->SetNumberOfCellsPerNode(0);
	if (contactMode == 0)
	{
		RUA_collide->SetCollisionModeToAllContacts();
	}
	else if (contactMode == 1)
	{
		RUA_collide->SetCollisionModeToFirstContact();
	}
	else
	{
		RUA_collide->SetCollisionModeToHalfContacts();
	}
	RUA_collide->GenerateScalarsOn();



	TConstraintProp_lineSource1->SetTipLength(0);
	TConstraintProp_lineSource1->SetTipResolution(0);
	TConstraintProp_lineSource1->Update();
	TConstraintProp_line_mapper1->SetInputConnection(TConstraintProp_lineSource1->GetOutputPort());
	TConstraintProp_line_mapper1->ScalarVisibilityOff();
	TConstraintProp_line_transform1->Translate(-30.0, 60.25, 5);
	TConstraintProp_line_transform1->RotateZ(90);
	TConstraintProp_line_actor1->SetMapper(TConstraintProp_line_mapper1);
	TConstraintProp_line_actor1->SetUserTransform(TConstraintProp_line_transform1);
	TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d(COLOR_TConstraintProp_line_actor1).GetData());
	TConstraintProp_line_actor1->SetScale(50);


	TConstraintProp_lineSource2->SetTipLength(0);
	TConstraintProp_lineSource2->SetTipResolution(0);
	TConstraintProp_lineSource2->Update();
	TConstraintProp_line_mapper2->SetInputConnection(TConstraintProp_lineSource2->GetOutputPort());
	TConstraintProp_line_mapper2->ScalarVisibilityOff();
	TConstraintProp_line_transform2->Translate(-40.0, 60.25, 5);
	TConstraintProp_line_transform2->RotateZ(90);
	TConstraintProp_line_actor2->SetMapper(TConstraintProp_line_mapper2);
	TConstraintProp_line_actor2->SetUserTransform(TConstraintProp_line_transform2);
	TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d(COLOR_TConstraintProp_line_actor2).GetData());
	TConstraintProp_line_actor2->SetScale(50);


	TConstraintProp_lineSource3->SetTipLength(0);
	TConstraintProp_lineSource3->SetTipResolution(0);
	TConstraintProp_lineSource3->Update();
	TConstraintProp_line_mapper3->SetInputConnection(TConstraintProp_lineSource3->GetOutputPort());
	TConstraintProp_line_mapper3->ScalarVisibilityOff();
	TConstraintProp_line_transform3->Translate(-50.0, 60.25, 5);
	//TConstraintProp_line_transform3->RotateZ(90);
	TConstraintProp_line_actor3->SetMapper(TConstraintProp_line_mapper3);
	TConstraintProp_line_actor3->SetUserTransform(TConstraintProp_line_transform3);
	TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d(COLOR_TConstraintProp_line_actor3).GetData());
	TConstraintProp_line_actor3->SetScale(50);





	RH_ObjReader->SetFileName(RH_objFilename.c_str());
	RightHand_ObjReader_mapper->SetInputConnection(RH_ObjReader->GetOutputPort());
	RightHand_ObjReader_Transform->Translate(RHObj_xpos, RHObj_ypos, RHObj_zpos);
	RightHand_ObjReader_Transform->SetInput(RforearmTransform);
	RightHand_objActor->SetUserTransform(RightHand_ObjReader_Transform);
	RightHand_objActor->SetMapper(RightHand_ObjReader_mapper);
	if (rotate == 10)
		RightHand_objActor->RotateY(50);
	RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RightHand_objActor).GetData());
	//RightHand_objActor->SetScale(RHObj_scale);


	LUA_ObjReader->SetFileName(LUA_objFilename.c_str());
	LarmMapper->SetInputConnection(LUA_ObjReader->GetOutputPort());
	LarmTransform->Translate(luaObj_xpos, luaObj_ypos, luaObj_zpos); //-0.25, 0.36, -0.075
	LarmTransform->SetInput(CUconeTransform);
	LarmActor->SetUserTransform(LarmTransform);
	LarmActor->SetMapper(LarmMapper);
	LarmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LarmActor).GetData());
	LarmActor->SetScale(luaObj_scale);


	LLA_ObjReader->SetFileName(LLA_objFilename.c_str());
	LforearmMapper->SetInputConnection(LLA_ObjReader->GetOutputPort());
	LforearmTransform->Translate(llaObj_xpos, llaObj_ypos, llaObj_zpos); //-0.2125, 0.080, -0.045
	LforearmTransform->SetInput(LarmTransform);
	LforearmActor->SetUserTransform(LforearmTransform);
	LforearmActor->SetMapper(LforearmMapper);
	LforearmActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LforearmActor).GetData());
	LforearmActor->SetScale(llaObj_scale);




	LH_ObjReader->SetFileName(LH_objFilename.c_str());
	LeftHand_ObjReader_mapper->SetInputConnection(LH_ObjReader->GetOutputPort());
	LeftHand_ObjReader_Transform->Translate(LHObj_xpos, LHObj_ypos, LHObj_zpos);
	LeftHand_ObjReader_Transform->SetInput(LforearmTransform);
	LeftHand_objActor->SetUserTransform(LeftHand_ObjReader_Transform);
	LeftHand_objActor->SetMapper(LeftHand_ObjReader_mapper);
	LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LeftHand_objActor).GetData());
	//LeftHand_objActor->SetScale(LHObj_scale);


	RUL_ObjReader->SetFileName(RUL_objFilename.c_str());
	RlulegMapper->SetInputConnection(RUL_ObjReader->GetOutputPort());
	RlulegTransform->Translate(rulObj_xpos, rulObj_ypos, rulObj_zpos);
	RlulegTransform->SetInput(PlconeTransform);
	RlulegActor->SetUserTransform(RlulegTransform);
	RlulegActor->SetMapper(RlulegMapper);
	RlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RlulegActor).GetData());
	RlulegActor->SetScale(rulObj_scale);



	RLL_ObjReader->SetFileName(RLL_objFilename.c_str());
	RllegMapper->SetInputConnection(RLL_ObjReader->GetOutputPort());
	RllegTransform->Translate(rllObj_xpos, rllObj_ypos, rllObj_zpos);
	RllegTransform->SetInput(RlulegTransform);
	RllegActor->SetUserTransform(RllegTransform);
	RllegActor->SetMapper(RllegMapper);
	RllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RllegActor).GetData());
	RllegActor->SetScale(rllObj_scale);




	RF_ObjReader->SetFileName(RF_objFilename.c_str());
	RF_ObjReader_mapper->SetInputConnection(RF_ObjReader->GetOutputPort());
	RF_ObjReader_Transform->Translate(RFObj_xpos, RFObj_ypos, RFObj_zpos);
	RF_ObjReader_Transform->SetInput(RllegTransform);
	RF_objActor->SetUserTransform(RF_ObjReader_Transform);
	RF_objActor->SetMapper(RF_ObjReader_mapper);
	RF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_RF_objActor).GetData());
	RF_objActor->SetScale(RFObj_scale);


	LUL_ObjReader->SetFileName(LUL_objFilename.c_str());
	LlulegMapper->SetInputConnection(LUL_ObjReader->GetOutputPort());
	LlulegTransform->Translate(lulObj_xpos, lulObj_ypos, lulObj_zpos); //-0.055, 0.0125, -0.01
	LlulegTransform->SetInput(PlconeTransform);
	LlulegActor->SetUserTransform(LlulegTransform);
	LlulegActor->SetMapper(LlulegMapper);
	LlulegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LlulegActor).GetData());
	LlulegActor->SetScale(lulObj_scale);



	LLL_ObjReader->SetFileName(LLL_objFilename.c_str());
	LllegMapper->SetInputConnection(LLL_ObjReader->GetOutputPort());
	LllegTransform->Translate(lllObj_xpos, lllObj_ypos, lllObj_zpos);
	LllegTransform->SetInput(LlulegTransform);
	LllegActor->SetUserTransform(LllegTransform);
	LllegActor->SetMapper(LllegMapper);
	LllegActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LllegActor).GetData());
	LllegActor->SetScale(lllObj_scale);


	LF_ObjReader->SetFileName(LF_objFilename.c_str());
	LF_ObjReader_mapper->SetInputConnection(LF_ObjReader->GetOutputPort());
	LF_ObjReader_Transform->Translate(LFObj_xpos, LFObj_ypos, LFObj_zpos);
	LF_ObjReader_Transform->SetInput(LllegTransform);
	LF_objActor->SetUserTransform(LF_ObjReader_Transform);
	LF_objActor->SetMapper(LF_ObjReader_mapper);
	LF_objActor->GetProperty()->SetColor(colors->GetColor3d(COLOR_LF_objActor).GetData());
	LF_objActor->SetScale(LFObj_scale);



	RarmTransform->RotateWXYZ(-4, 0, 0, 1);
	LarmTransform->RotateWXYZ(4, 0, 0, 1);


	//TargetPoint - Sphere
	double rightData[3] = { 0,0,0 };
	RightHand_ObjReader_Transform->GetPosition(rightData);
	//targetTransform->Translate(rightData[0], rightData[1] - 8, rightData[2]);

	targetSphere->SetCenter(0, 0, 0);
	targetSphere->SetRadius(3);
	targetSphere->SetPhiResolution(100);
	targetSphere->SetThetaResolution(100);


	//sspark : inverse Kinematices
	targetMapper->SetInputConnection(targetSphere->GetOutputPort());
	targetTransform->SetInput(RightHand_ObjReader_Transform);
	targetActor->SetUserTransform(targetTransform);
	targetActor->SetMapper(targetMapper);
	targetActor->GetProperty()->SetColor(colors->GetColor3d("DarkGreen").GetData());


	//renderer->AddActor(planeActor);
	mRenderer->AddActor(PlconeActor);
	mRenderer->AddActor(CUconeActor);
	mRenderer->AddActor(Head_objActor);

	mRenderer->AddActor(RarmActor);
	mRenderer->AddActor(RforearmActor);
	mRenderer->AddActor(RightHand_objActor);

	mRenderer->AddActor(LarmActor);
	mRenderer->AddActor(LforearmActor);
	mRenderer->AddActor(LeftHand_objActor);

	mRenderer->AddActor(RlulegActor);
	mRenderer->AddActor(RllegActor); 
	mRenderer->AddActor(RF_objActor);

	mRenderer->AddActor(LlulegActor);
	mRenderer->AddActor(LllegActor);
	mRenderer->AddActor(LF_objActor);

	//sspark : inverseKinematices
	//mRenderer->AddActor(targetActor);
}
void MainWindow::displayRobot_Model(int rotate)
{
	robotModel(rotate);
}
void MainWindow::displayFixedFoots_Model()
{
	IK_rightFoot_Transform->Identity();
	ffIK_rf_outlineTransform->Identity();
	IK_rightLowerLeg_Transform->Identity();
	IK_rightKnee_Transform->Identity();
	IK_rightUpperLeg_Transform->Identity();
	IK_rightLegJoint_Transform->Identity();


	IK_pelvisTransform->Identity();

	IK_leftFoot_Transform->Identity();
	ffIK_lf_outlineTransform->Identity();
	IK_leftLowerLeg_Transform->Identity();
	IK_leftKnee_Transform->Identity();
	IK_leftUpperLeg_Transform->Identity();
	IK_leftLegJoint_Transform->Identity();

	IK_chest_0_Transform->Identity();
	IK_chest_1_Transform->Identity();
	IK_chest_2_Transform->Identity();
	IK_chest_3_Transform->Identity();
	IK_head_Transform->Identity();

	IK_rightShoulderJoint_Transform->Identity();
	IK_rightUpperArm_Transform->Identity();
	IK_rightElbow_Transform->Identity();
	IK_rightLowerArm_Transform->Identity();
	IK_rightHand_Transform->Identity();

	IK_leftShoulderJoint_Transform->Identity();
	IK_leftUpperArm_Transform->Identity();
	IK_leftElbow_Transform->Identity();
	IK_leftLowerArm_Transform->Identity();
	IK_leftHand_Transform->Identity();


	// IK_rightFoot
	IK_rightFoot_objFile = "../BodyGestureGenerator/data/RF.obj";
	IK_rightFoot_Reader->SetFileName(IK_rightFoot_objFile.c_str());
	IK_rightFoot_Mapper->SetInputConnection(IK_rightFoot_Reader->GetOutputPort());
	IK_rightFoot_Transform->Translate(-5.0, 7.1, 0);
	ffIK_F_x = -5.0;
	ffIK_F_y = 7.1;
	ffIK_F_z = 0;
	IK_rightFoot_Actor->SetUserTransform(IK_rightFoot_Transform);
	IK_rightFoot_Actor->SetMapper(IK_rightFoot_Mapper);
	IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	IK_rightFoot_Actor->SetScale(50.0);

	vtkPolyData* ffIK_rfOutliner = IK_rightFoot_Reader->GetOutput();
	ffIK_rf_outlineFilter->SetInputData(ffIK_rfOutliner);
	ffIK_rf_outlineTransform->SetInput(IK_rightFoot_Transform);
	ffIK_rf_outlineMapper->SetInputConnection(ffIK_rf_outlineFilter->GetOutputPort());
	ffIK_rf_outlineActor->SetMapper(ffIK_rf_outlineMapper);
	ffIK_rf_outlineActor->GetProperty()->SetLineWidth(0.5);
	ffIK_rf_outlineActor->GetProperty()->SetColor(1, 1, 0);
	ffIK_rf_outlineActor->SetScale(50, 50, 50);
	ffIK_rf_outlineActor->SetUserTransform(ffIK_rf_outlineTransform);


	//IK_rightLowerLeg
	IK_rightLowerLeg_Source->SetRadius(1.5);
	IK_rightLowerLeg_Source->SetHeight(16.0);
	IK_rightLowerLeg_Source->SetResolution(20);
	IK_rightLowerLeg_Source->SetCenter(0, IK_rightLowerLeg_Source->GetHeight() / 2, 0);
	ffIK_LL_x = 0;
	ffIK_LL_y = IK_rightLowerLeg_Source->GetRadius();
	ffIK_LL_z = 0;

	IK_rightLowerLeg_Mapper->SetInputConnection(IK_rightLowerLeg_Source->GetOutputPort());
	IK_rightLowerLeg_Transform->SetInput(IK_rightFoot_Transform);
	IK_rightLowerLeg_Actor->SetUserTransform(IK_rightLowerLeg_Transform);
	IK_rightLowerLeg_Actor->SetMapper(IK_rightLowerLeg_Mapper);
	IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//IK_rightKnee
	IK_rightKnee_Source->SetRadius(1.5);
	IK_rightKnee_Source->SetPhiResolution(100);
	IK_rightKnee_Source->SetThetaResolution(100);
	IK_rightKnee_Source->SetCenter(*(IK_rightLowerLeg_Source->GetCenter()),
		*(IK_rightLowerLeg_Source->GetCenter() + 1) + IK_rightLowerLeg_Source->GetHeight() / 2 + IK_rightKnee_Source->GetRadius(),
		*(IK_rightLowerLeg_Source->GetCenter() + 2));
	IK_rightKnee_Transform->SetInput(IK_rightLowerLeg_Transform);
	IK_rightKnee_Actor->SetUserTransform(IK_rightKnee_Transform);
	IK_rightKnee_Mapper->SetInputConnection(IK_rightKnee_Source->GetOutputPort());
	IK_rightKnee_Actor->SetMapper(IK_rightKnee_Mapper);
	IK_rightKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//IK_rightUpperLeg
	IK_rightUpperLeg_Source->SetRadius(1.5);
	IK_rightUpperLeg_Source->SetHeight(17.0);
	IK_rightUpperLeg_Source->SetResolution(20);
	IK_rightUpperLeg_Source->SetCenter(*(IK_rightKnee_Source->GetCenter()),
		*(IK_rightKnee_Source->GetCenter() + 1) + IK_rightUpperLeg_Source->GetHeight() / 2 + IK_rightKnee_Source->GetRadius(),
		*(IK_rightKnee_Source->GetCenter() + 2));

	ffIK_UL_x = *(IK_rightUpperLeg_Source->GetCenter());
	ffIK_UL_y = *(IK_rightLowerLeg_Source->GetCenter() + 1) + IK_rightLowerLeg_Source->GetHeight() / 2 + IK_rightKnee_Source->GetRadius();
	ffIK_UL_z = *(IK_rightUpperLeg_Source->GetCenter() + 2);

	IK_rightUpperLeg_Mapper->SetInputConnection(IK_rightUpperLeg_Source->GetOutputPort());
	IK_rightUpperLeg_Transform->SetInput(IK_rightKnee_Transform);
	IK_rightUpperLeg_Actor->SetUserTransform(IK_rightUpperLeg_Transform);
	IK_rightUpperLeg_Actor->SetMapper(IK_rightUpperLeg_Mapper);
	IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//IK_rightLegJoint
	IK_rightLegJoint_Source->SetRadius(2.75);
	IK_rightLegJoint_Source->SetPhiResolution(100);
	IK_rightLegJoint_Source->SetThetaResolution(100);
	IK_rightLegJoint_Source->SetCenter(*(IK_rightKnee_Source->GetCenter()),
		*(IK_rightKnee_Source->GetCenter() + 1) + IK_rightUpperLeg_Source->GetHeight() + IK_rightUpperLeg_Source->GetRadius() + 2.75,
		*(IK_rightKnee_Source->GetCenter() + 2));
	IK_rightLegJoint_Transform->SetInput(IK_rightUpperLeg_Transform);
	IK_rightLegJoint_Actor->SetUserTransform(IK_rightLegJoint_Transform);
	IK_rightLegJoint_Mapper->SetInputConnection(IK_rightLegJoint_Source->GetOutputPort());
	IK_rightLegJoint_Actor->SetMapper(IK_rightLegJoint_Mapper);
	IK_rightLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());

	//IK_pelvisJoint
	IK_pelvisSource->SetRadius(5.0);
	IK_pelvisSource->SetCenter(*(IK_rightLegJoint_Source->GetCenter()) + IK_rightLegJoint_Source->GetRadius() + 2.25,
		*(IK_rightLegJoint_Source->GetCenter() + 1) + IK_rightLegJoint_Source->GetRadius() / 2 + 0.65,
		*(IK_rightLegJoint_Source->GetCenter() + 2));

	ffIK_PL_x = *(IK_rightLegJoint_Source->GetCenter()) + IK_rightLegJoint_Source->GetRadius() + 2.25;
	ffIK_PL_y = *(IK_rightLegJoint_Source->GetCenter() + 1) + IK_rightLegJoint_Source->GetRadius() / 2 + 0.65;
	ffIK_PL_z = *(IK_rightLegJoint_Source->GetCenter() + 2);
	IK_pelvisSource->SetPhiResolution(100);
	IK_pelvisSource->SetThetaResolution(100);
	IK_pelvisTransform->SetInput(IK_rightLegJoint_Transform);
	IK_pelvisMapper->SetInputConnection(IK_pelvisSource->GetOutputPort());
	IK_pelvisActor->SetUserTransform(IK_pelvisTransform);
	IK_pelvisActor->SetMapper(IK_pelvisMapper);
	IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());




	// IK_leftFoot
	IK_leftFoot_objFile = "../BodyGestureGenerator/data/LF.obj";
	IK_leftFoot_Reader->SetFileName(IK_leftFoot_objFile.c_str());
	IK_leftFoot_Mapper->SetInputConnection(IK_leftFoot_Reader->GetOutputPort());
	IK_leftFoot_Transform->Translate(5.0, 7.1, 0);
	IK_leftFoot_Actor->SetUserTransform(IK_leftFoot_Transform);
	IK_leftFoot_Actor->SetMapper(IK_leftFoot_Mapper);
	IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	IK_leftFoot_Actor->SetScale(50.0);


	vtkPolyData* ffIK_lfOutliner = IK_leftFoot_Reader->GetOutput();
	ffIK_lf_outlineFilter->SetInputData(ffIK_lfOutliner);
	ffIK_lf_outlineTransform->SetInput(IK_leftFoot_Transform);
	ffIK_lf_outlineMapper->SetInputConnection(ffIK_lf_outlineFilter->GetOutputPort());
	ffIK_lf_outlineActor->SetMapper(ffIK_lf_outlineMapper);
	ffIK_lf_outlineActor->GetProperty()->SetLineWidth(0.5);
	ffIK_lf_outlineActor->GetProperty()->SetColor(1, 1, 0);
	ffIK_lf_outlineActor->SetScale(50, 50, 50);
	ffIK_lf_outlineActor->SetUserTransform(ffIK_lf_outlineTransform);

	//IK_leftLowerLeg
	IK_leftLowerLeg_Source->SetRadius(1.5);
	IK_leftLowerLeg_Source->SetHeight(16.0);
	IK_leftLowerLeg_Source->SetResolution(20);
	IK_leftLowerLeg_Source->SetCenter(0, IK_leftLowerLeg_Source->GetHeight() / 2, 0);
	IK_leftLowerLeg_Mapper->SetInputConnection(IK_leftLowerLeg_Source->GetOutputPort());
	IK_leftLowerLeg_Transform->SetInput(IK_leftFoot_Transform);
	IK_leftLowerLeg_Actor->SetUserTransform(IK_leftLowerLeg_Transform);
	IK_leftLowerLeg_Actor->SetMapper(IK_leftLowerLeg_Mapper);
	IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//IK_leftKnee
	IK_leftKnee_Source->SetRadius(1.5);
	IK_leftKnee_Source->SetPhiResolution(100);
	IK_leftKnee_Source->SetThetaResolution(100);
	IK_leftKnee_Source->SetCenter(*(IK_leftLowerLeg_Source->GetCenter()),
		*(IK_leftLowerLeg_Source->GetCenter() + 1) + IK_leftLowerLeg_Source->GetHeight() / 2 + IK_leftKnee_Source->GetRadius(),
		*(IK_leftLowerLeg_Source->GetCenter() + 2));
	IK_leftKnee_Transform->SetInput(IK_leftLowerLeg_Transform);
	IK_leftKnee_Actor->SetUserTransform(IK_leftKnee_Transform);
	IK_leftKnee_Mapper->SetInputConnection(IK_leftKnee_Source->GetOutputPort());
	IK_leftKnee_Actor->SetMapper(IK_leftKnee_Mapper);
	IK_leftKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());

	//IK_leftUpperLeg
	IK_leftUpperLeg_Source->SetRadius(1.5);
	IK_leftUpperLeg_Source->SetHeight(17.0);
	IK_leftUpperLeg_Source->SetResolution(20);
	IK_leftUpperLeg_Source->SetCenter(*(IK_leftKnee_Source->GetCenter()),
		*(IK_leftKnee_Source->GetCenter() + 1) + IK_leftUpperLeg_Source->GetHeight() / 2 + IK_leftKnee_Source->GetRadius(),
		*(IK_leftKnee_Source->GetCenter() + 2));
	IK_leftUpperLeg_Mapper->SetInputConnection(IK_leftUpperLeg_Source->GetOutputPort());
	IK_leftUpperLeg_Transform->SetInput(IK_leftKnee_Transform);
	IK_leftUpperLeg_Actor->SetUserTransform(IK_leftUpperLeg_Transform);
	IK_leftUpperLeg_Actor->SetMapper(IK_leftUpperLeg_Mapper);
	IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//IK_leftLegJoint
	IK_leftLegJoint_Source->SetRadius(2.75);
	IK_leftLegJoint_Source->SetPhiResolution(100);
	IK_leftLegJoint_Source->SetThetaResolution(100);
	IK_leftLegJoint_Source->SetCenter(*(IK_leftKnee_Source->GetCenter()),
		*(IK_leftKnee_Source->GetCenter() + 1) + IK_leftUpperLeg_Source->GetHeight() + IK_leftUpperLeg_Source->GetRadius() + 2.75,
		*(IK_leftKnee_Source->GetCenter() + 2));
	IK_leftLegJoint_Transform->SetInput(IK_leftUpperLeg_Transform);
	IK_leftLegJoint_Actor->SetUserTransform(IK_leftLegJoint_Transform);
	IK_leftLegJoint_Mapper->SetInputConnection(IK_leftLegJoint_Source->GetOutputPort());
	IK_leftLegJoint_Actor->SetMapper(IK_leftLegJoint_Mapper);
	IK_leftLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//IK_Chest 0
	IK_chest_0_Source->SetRadius(2.85);
	IK_chest_0_Source->SetPhiResolution(100);
	IK_chest_0_Source->SetThetaResolution(100);
	IK_chest_0_Source->SetCenter(*(IK_pelvisSource->GetCenter()),
		*(IK_pelvisSource->GetCenter() + 1) + IK_pelvisSource->GetRadius() + IK_chest_0_Source->GetRadius(), *(IK_pelvisSource->GetCenter() + 2));

	ffIK_CH0_x = *(IK_pelvisSource->GetCenter());
	ffIK_CH0_y = *(IK_pelvisSource->GetCenter() + 1);
	ffIK_CH0_z = *(IK_pelvisSource->GetCenter() + 2);

	IK_chest_0_Mapper->SetInputConnection(IK_chest_0_Source->GetOutputPort());
	IK_chest_0_Transform->SetInput(IK_pelvisTransform);
	IK_chest_0_Actor->SetUserTransform(IK_chest_0_Transform);
	IK_chest_0_Actor->SetMapper(IK_chest_0_Mapper);
	IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//chest_1
	IK_chest_1_Source->SetRadius(2.85);
	IK_chest_1_Source->SetPhiResolution(100);
	IK_chest_1_Source->SetThetaResolution(100);
	IK_chest_1_Source->SetCenter(*(IK_chest_0_Source->GetCenter()),
		*(IK_chest_0_Source->GetCenter() + 1) + IK_chest_0_Source->GetRadius() + IK_chest_1_Source->GetRadius(),
		*(IK_chest_0_Source->GetCenter() + 2));

	ffIK_CH1_x = *(IK_chest_0_Source->GetCenter());
	ffIK_CH1_y = *(IK_chest_0_Source->GetCenter() + 1);
	ffIK_CH1_z = *(IK_chest_0_Source->GetCenter() + 2);

	IK_chest_1_Transform->SetInput(IK_chest_0_Transform);
	IK_chest_1_Actor->SetUserTransform(IK_chest_1_Transform);
	IK_chest_1_Mapper->SetInputConnection(IK_chest_1_Source->GetOutputPort());
	IK_chest_1_Actor->SetMapper(IK_chest_1_Mapper);
	IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());


	//IK_chest_2
	IK_chest_2_Source->SetRadius(2.85);
	IK_chest_2_Source->SetPhiResolution(100);
	IK_chest_2_Source->SetThetaResolution(100);
	IK_chest_2_Source->SetCenter(*(IK_chest_1_Source->GetCenter()),
		*(IK_chest_1_Source->GetCenter() + 1) + IK_chest_1_Source->GetRadius() + IK_chest_2_Source->GetRadius(),
		*(IK_chest_1_Source->GetCenter() + 2));

	ffIK_CH2_x = *(IK_chest_1_Source->GetCenter());
	ffIK_CH2_y = *(IK_chest_1_Source->GetCenter() + 1);
	ffIK_CH2_z = *(IK_chest_1_Source->GetCenter() + 2);

	IK_chest_2_Transform->SetInput(IK_chest_1_Transform);
	IK_chest_2_Actor->SetUserTransform(IK_chest_2_Transform);
	IK_chest_2_Mapper->SetInputConnection(IK_chest_2_Source->GetOutputPort());
	IK_chest_2_Actor->SetMapper(IK_chest_2_Mapper);
	IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//IK_chest_3
	IK_chest_3_Source->SetRadius(3.75);
	IK_chest_3_Source->SetPhiResolution(100);
	IK_chest_3_Source->SetThetaResolution(100);
	IK_chest_3_Source->SetCenter(*(IK_chest_2_Source->GetCenter()),
		*(IK_chest_2_Source->GetCenter() + 1) + IK_chest_2_Source->GetRadius() + IK_chest_3_Source->GetRadius(),
		*(IK_chest_2_Source->GetCenter() + 2));
	IK_chest_3_Transform->SetInput(IK_chest_2_Transform);
	IK_chest_3_Actor->SetUserTransform(IK_chest_3_Transform);
	IK_chest_3_Mapper->SetInputConnection(IK_chest_3_Source->GetOutputPort());
	IK_chest_3_Actor->SetMapper(IK_chest_3_Mapper);
	IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//IK_head
	IK_head_objFile = "../BodyGestureGenerator/data/humanHead1.obj";
	const char* IK_headTexture_filename = "../BodyGestureGenerator/data/headmap.jpg";
	IK_head_Reader->SetFileName(IK_head_objFile.c_str());
	IK_head_Mapper->SetInputConnection(IK_head_Reader->GetOutputPort());

	IK_head_Transform->Translate(*(IK_chest_3_Source->GetCenter()),
		*(IK_chest_3_Source->GetCenter() + 1) + IK_chest_3_Source->GetRadius() + 0.05,
		*(IK_chest_3_Source->GetCenter() + 2));
	IK_head_Transform->SetInput(IK_chest_3_Transform);
	IK_head_Actor->SetUserTransform(IK_head_Transform);
	IK_head_Actor->SetMapper(IK_head_Mapper);
	IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	IK_head_Actor->SetScale(8);
	IK_headTexture_Reader->SetFileName(IK_headTexture_filename);
	// Apply the texture
	IK_head_Texture->SetInputConnection(IK_headTexture_Reader->GetOutputPort());
	IK_head_Actor->SetTexture(IK_head_Texture);


	//IK_rightShoulderJoint
	IK_rightShoulderJoint_Source->SetRadius(3.0);
	IK_rightShoulderJoint_Source->SetPhiResolution(100);
	IK_rightShoulderJoint_Source->SetThetaResolution(100);
	IK_rightShoulderJoint_Source->SetCenter(*(IK_chest_3_Source->GetCenter()) - IK_chest_3_Source->GetRadius() - IK_rightShoulderJoint_Source->GetRadius(),
		*(IK_chest_3_Source->GetCenter() + 1) - 1.0,
		*(IK_chest_3_Source->GetCenter() + 2));

	ffIK_Shoulder_x = *(IK_chest_3_Source->GetCenter()) - IK_chest_3_Source->GetRadius() - IK_rightShoulderJoint_Source->GetRadius();
	ffIK_Shoulder_y = *(IK_chest_3_Source->GetCenter() + 1) - 1.0;
	ffIK_Shoulder_z = *(IK_chest_3_Source->GetCenter() + 2);

	IK_rightShoulderJoint_Transform->SetInput(IK_chest_3_Transform);
	IK_rightShoulderJoint_Actor->SetUserTransform(IK_rightShoulderJoint_Transform);
	IK_rightShoulderJoint_Mapper->SetInputConnection(IK_rightShoulderJoint_Source->GetOutputPort());
	IK_rightShoulderJoint_Actor->SetMapper(IK_rightShoulderJoint_Mapper);
	IK_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());



	//IK_rightUpperArm
	IK_rightUpperArm_Source->SetRadius(1.5);
	IK_rightUpperArm_Source->SetHeight(12.0);
	IK_rightUpperArm_Source->SetResolution(20);
	IK_rightUpperArm_Source->SetCenter(*(IK_rightShoulderJoint_Source->GetCenter()),
		*(IK_rightShoulderJoint_Source->GetCenter() + 1) - IK_rightUpperArm_Source->GetHeight() / 2 - IK_rightShoulderJoint_Source->GetRadius(),
		*(IK_rightShoulderJoint_Source->GetCenter() + 2));
	IK_rightUpperArm_Mapper->SetInputConnection(IK_rightUpperArm_Source->GetOutputPort());

	ffIK_UA_x = *(IK_rightShoulderJoint_Source->GetCenter());
	ffIK_UA_y = *(IK_rightShoulderJoint_Source->GetCenter() + 1);
	ffIK_UA_z = *(IK_rightShoulderJoint_Source->GetCenter() + 2);


	IK_rightUpperArm_Transform->SetInput(IK_rightShoulderJoint_Transform);
	IK_rightUpperArm_Actor->SetUserTransform(IK_rightUpperArm_Transform);
	IK_rightUpperArm_Actor->SetMapper(IK_rightUpperArm_Mapper);
	IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//IK_rightElbow
	IK_rightElbow_Source->SetRadius(1.5);
	IK_rightElbow_Source->SetPhiResolution(100);
	IK_rightElbow_Source->SetThetaResolution(100);
	IK_rightElbow_Source->SetCenter(*(IK_rightUpperArm_Source->GetCenter()),
		*(IK_rightUpperArm_Source->GetCenter() + 1) - (IK_rightUpperArm_Source->GetHeight() / 2) - IK_rightElbow_Source->GetRadius(),
		*(IK_rightUpperArm_Source->GetCenter() + 2));

	IK_rightElbow_Transform->SetInput(IK_rightUpperArm_Transform);
	IK_rightElbow_Actor->SetUserTransform(IK_rightElbow_Transform);
	IK_rightElbow_Mapper->SetInputConnection(IK_rightElbow_Source->GetOutputPort());
	IK_rightElbow_Actor->SetMapper(IK_rightElbow_Mapper);
	IK_rightElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//IK_rightLowerArm
	IK_rightLowerArm_Source->SetRadius(1.5);
	IK_rightLowerArm_Source->SetHeight(12.0);
	IK_rightLowerArm_Source->SetResolution(20);
	IK_rightLowerArm_Source->SetCenter(*(IK_rightElbow_Source->GetCenter()),
		*(IK_rightElbow_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2 - IK_rightElbow_Source->GetRadius(),
		*(IK_rightElbow_Source->GetCenter() + 2));

	ffIK_LA_x = *(IK_rightElbow_Source->GetCenter());
	ffIK_LA_y = *(IK_rightElbow_Source->GetCenter() + 1);
	ffIK_LA_z = *(IK_rightElbow_Source->GetCenter() + 2);

	IK_rightLowerArm_Mapper->SetInputConnection(IK_rightLowerArm_Source->GetOutputPort());
	IK_rightLowerArm_Transform->SetInput(IK_rightElbow_Transform);
	IK_rightLowerArm_Actor->SetUserTransform(IK_rightLowerArm_Transform);
	IK_rightLowerArm_Actor->SetMapper(IK_rightLowerArm_Mapper);
	IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//IK_rightHand
	IK_rightHand_objFile = "../BodyGestureGenerator/data/RH_G.obj";
	IK_rightHand_Reader->SetFileName(IK_rightHand_objFile.c_str());
	IK_rightHand_Mapper->SetInputConnection(IK_rightHand_Reader->GetOutputPort());

	IK_rightHand_Transform->Translate(*(IK_rightLowerArm_Source->GetCenter()),
		*(IK_rightLowerArm_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2,
		*(IK_rightLowerArm_Source->GetCenter() + 2));

	ffIK_H_x = *(IK_rightLowerArm_Source->GetCenter());
	ffIK_H_y = *(IK_rightLowerArm_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2;
	ffIK_H_z = *(IK_rightLowerArm_Source->GetCenter() + 2);

	IK_rightHand_Transform->SetInput(IK_rightLowerArm_Transform);

	IK_rightHand_Actor->SetUserTransform(IK_rightHand_Transform);

	IK_rightHand_Actor->SetMapper(IK_rightHand_Mapper);
	//IK_rightHand_Actor->RotateY(-7);
	IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	IK_rightHand_Actor->SetScale(0.95);

	//IK_leftShoulderJoint
	IK_leftShoulderJoint_Source->SetRadius(3.0);
	IK_leftShoulderJoint_Source->SetPhiResolution(100);
	IK_leftShoulderJoint_Source->SetThetaResolution(100);
	IK_leftShoulderJoint_Source->SetCenter(*(IK_chest_3_Source->GetCenter()) + IK_chest_3_Source->GetRadius() + IK_leftShoulderJoint_Source->GetRadius(),
		*(IK_chest_3_Source->GetCenter() + 1) - 1.0,
		*(IK_chest_3_Source->GetCenter() + 2));

	ffIK_LShoulder_x = *(IK_chest_3_Source->GetCenter()) + IK_chest_3_Source->GetRadius() + IK_leftShoulderJoint_Source->GetRadius();
	ffIK_LShoulder_y = *(IK_chest_3_Source->GetCenter() + 1) - 1.0;
	ffIK_LShoulder_z = *(IK_chest_3_Source->GetCenter() + 2);

	IK_leftShoulderJoint_Transform->SetInput(IK_chest_3_Transform);
	IK_leftShoulderJoint_Actor->SetUserTransform(IK_leftShoulderJoint_Transform);
	IK_leftShoulderJoint_Mapper->SetInputConnection(IK_leftShoulderJoint_Source->GetOutputPort());
	IK_leftShoulderJoint_Actor->SetMapper(IK_leftShoulderJoint_Mapper);
	IK_leftShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//IK_leftUpperArm
	IK_leftUpperArm_Source->SetRadius(1.5);
	IK_leftUpperArm_Source->SetHeight(12.0);
	IK_leftUpperArm_Source->SetResolution(20);
	IK_leftUpperArm_Source->SetCenter(*(IK_leftShoulderJoint_Source->GetCenter()),
		*(IK_leftShoulderJoint_Source->GetCenter() + 1) - IK_leftUpperArm_Source->GetHeight() / 2 - IK_leftShoulderJoint_Source->GetRadius(),
		*(IK_leftShoulderJoint_Source->GetCenter() + 2));
	IK_leftUpperArm_Mapper->SetInputConnection(IK_leftUpperArm_Source->GetOutputPort());
	ffIK_LUA_x = *(IK_leftShoulderJoint_Source->GetCenter());
	ffIK_LUA_y = *(IK_leftShoulderJoint_Source->GetCenter() + 1);
	ffIK_LUA_z = *(IK_leftShoulderJoint_Source->GetCenter() + 2);

	IK_leftUpperArm_Transform->SetInput(IK_leftShoulderJoint_Transform);
	IK_leftUpperArm_Actor->SetUserTransform(IK_leftUpperArm_Transform);
	IK_leftUpperArm_Actor->SetMapper(IK_leftUpperArm_Mapper);
	IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//IK_leftElbow
	IK_leftElbow_Source->SetRadius(1.5);
	IK_leftElbow_Source->SetPhiResolution(100);
	IK_leftElbow_Source->SetThetaResolution(100);
	IK_leftElbow_Source->SetCenter(*(IK_leftUpperArm_Source->GetCenter()),
		*(IK_leftUpperArm_Source->GetCenter() + 1) - (IK_leftUpperArm_Source->GetHeight() / 2) - IK_leftElbow_Source->GetRadius(),
		*(IK_leftUpperArm_Source->GetCenter() + 2));

	IK_leftElbow_Transform->SetInput(IK_leftUpperArm_Transform);
	IK_leftElbow_Actor->SetUserTransform(IK_leftElbow_Transform);
	IK_leftElbow_Mapper->SetInputConnection(IK_leftElbow_Source->GetOutputPort());
	IK_leftElbow_Actor->SetMapper(IK_leftElbow_Mapper);
	IK_leftElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//IK_leftLowerArm
	IK_leftLowerArm_Source->SetRadius(1.5);
	IK_leftLowerArm_Source->SetHeight(12.0);
	IK_leftLowerArm_Source->SetResolution(20);
	IK_leftLowerArm_Source->SetCenter(*(IK_leftElbow_Source->GetCenter()),
		*(IK_leftElbow_Source->GetCenter() + 1) - IK_leftLowerArm_Source->GetHeight() / 2 - IK_leftElbow_Source->GetRadius(),
		*(IK_leftElbow_Source->GetCenter() + 2));

	ffIK_LLA_x = *(IK_leftElbow_Source->GetCenter());
	ffIK_LLA_y = *(IK_leftElbow_Source->GetCenter() + 1);
	ffIK_LLA_z = *(IK_leftElbow_Source->GetCenter() + 2);

	IK_leftLowerArm_Mapper->SetInputConnection(IK_leftLowerArm_Source->GetOutputPort());
	IK_leftLowerArm_Transform->SetInput(IK_leftElbow_Transform);
	IK_leftLowerArm_Actor->SetUserTransform(IK_leftLowerArm_Transform);
	IK_leftLowerArm_Actor->SetMapper(IK_leftLowerArm_Mapper);
	IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//IK_leftHand
	IK_leftHand_objFile = "../BodyGestureGenerator/data/LH_G.obj";
	IK_leftHand_Reader->SetFileName(IK_leftHand_objFile.c_str());
	IK_leftHand_Mapper->SetInputConnection(IK_leftHand_Reader->GetOutputPort());

	IK_leftHand_Transform->Translate(*(IK_leftLowerArm_Source->GetCenter()),
		*(IK_leftLowerArm_Source->GetCenter() + 1) - IK_leftLowerArm_Source->GetHeight() / 2 - 0.03,
		*(IK_leftLowerArm_Source->GetCenter() + 2) - 0.05);

	IK_leftHand_Transform->SetInput(IK_leftLowerArm_Transform);

	IK_leftHand_Actor->SetUserTransform(IK_leftHand_Transform);

	IK_leftHand_Actor->SetMapper(IK_leftHand_Mapper);
	//IK_leftHand_Actor->RotateY(-7);
	IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	IK_leftHand_Actor->SetScale(0.95);



	IK_rightShoulderJoint_Transform->Identity();
	IK_rightShoulderJoint_Transform->Translate(ffIK_Shoulder_x, ffIK_Shoulder_y, 0);
	IK_rightShoulderJoint_Transform->RotateWXYZ(-8, 0, 0, 1);
	IK_rightShoulderJoint_Transform->Translate(-ffIK_Shoulder_x, -ffIK_Shoulder_y, 0);

	IK_leftShoulderJoint_Transform->Identity();
	IK_leftShoulderJoint_Transform->Translate(ffIK_LShoulder_x, ffIK_LShoulder_y, 0);
	IK_leftShoulderJoint_Transform->RotateWXYZ(8, 0, 0, 1);
	IK_leftShoulderJoint_Transform->Translate(-ffIK_LShoulder_x, -ffIK_LShoulder_y, 0);


	mRenderer->AddActor(IK_rightFoot_Actor);

	mRenderer->AddActor(IK_rightLowerLeg_Actor);
	mRenderer->AddActor(IK_rightKnee_Actor);
	mRenderer->AddActor(IK_rightUpperLeg_Actor);
	mRenderer->AddActor(IK_rightLegJoint_Actor);

	mRenderer->AddActor(IK_leftFoot_Actor);
	mRenderer->AddActor(ffIK_rf_outlineActor);
	mRenderer->AddActor(IK_leftLowerLeg_Actor);
	mRenderer->AddActor(IK_leftKnee_Actor);
	mRenderer->AddActor(IK_leftUpperLeg_Actor);
	mRenderer->AddActor(IK_leftLegJoint_Actor);

	mRenderer->AddActor(IK_pelvisActor);
	mRenderer->AddActor(ffIK_lf_outlineActor);
	mRenderer->AddActor(IK_chest_0_Actor);
	mRenderer->AddActor(IK_chest_1_Actor);
	mRenderer->AddActor(IK_chest_2_Actor);
	mRenderer->AddActor(IK_chest_3_Actor);

	mRenderer->AddActor(IK_head_Actor);

	mRenderer->AddActor(IK_rightShoulderJoint_Actor);
	mRenderer->AddActor(IK_rightUpperArm_Actor);
	mRenderer->AddActor(IK_rightElbow_Actor);
	mRenderer->AddActor(IK_rightLowerArm_Actor);
	mRenderer->AddActor(IK_rightHand_Actor);

	mRenderer->AddActor(IK_leftShoulderJoint_Actor);
	mRenderer->AddActor(IK_leftUpperArm_Actor);
	mRenderer->AddActor(IK_leftElbow_Actor);
	mRenderer->AddActor(IK_leftLowerArm_Actor);
	mRenderer->AddActor(IK_leftHand_Actor);
}

void MainWindow::displayStick_Model()
{
	// stickModel_Pelvis
	stickModel_pelvisSource->SetRadius(5.0);
	stickModel_pelvisSource->SetCenter(0.0, 47.875, 0.0);
	stickModel_pelvisSource->SetPhiResolution(100);
	stickModel_pelvisSource->SetThetaResolution(100);
	stickModel_pelvisMapper->SetInputConnection(stickModel_pelvisSource->GetOutputPort());
	stickModel_pelvisActor->SetUserTransform(stickModel_pelvisTransform);
	stickModel_pelvisActor->SetMapper(stickModel_pelvisMapper);
	stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
	
	//stickModel_Chest 0
	stickModel_chest_0_Source->SetRadius(2.85);
	stickModel_chest_0_Source->SetPhiResolution(100);
	stickModel_chest_0_Source->SetThetaResolution(100);
	stickModel_chest_0_Source->SetCenter(*(stickModel_pelvisSource->GetCenter()),
		*(stickModel_pelvisSource->GetCenter() + 1) + stickModel_pelvisSource->GetRadius() + stickModel_chest_0_Source->GetRadius(),
		*(stickModel_pelvisSource->GetCenter() + 2));
	stickModel_chest_0_Mapper->SetInputConnection(stickModel_chest_0_Source->GetOutputPort());
	CH0_x = *(stickModel_pelvisSource->GetCenter());
	CH0_y = *(stickModel_pelvisSource->GetCenter() + 1) ;
	CH0_z = *(stickModel_pelvisSource->GetCenter() + 2);
	//cout << CH0_x << "\t" << CH0_y << "\t" << CH0_z << endl;
	stickModel_chest_0_Transform->SetInput(stickModel_pelvisTransform);
	stickModel_chest_0_Actor->SetUserTransform(stickModel_chest_0_Transform);
	stickModel_chest_0_Actor->SetMapper(stickModel_chest_0_Mapper);
	stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	
	//stickModel_chest 1
	stickModel_chest_1_Source->SetRadius(2.85);
	stickModel_chest_1_Source->SetPhiResolution(100);
	stickModel_chest_1_Source->SetThetaResolution(100);
	stickModel_chest_1_Source->SetCenter(*(stickModel_chest_0_Source->GetCenter()),
		*(stickModel_chest_0_Source->GetCenter() + 1) + stickModel_chest_0_Source->GetRadius() + stickModel_chest_1_Source->GetRadius(),
		*(stickModel_chest_0_Source->GetCenter() + 2));
	CH1_x = *(stickModel_chest_0_Source->GetCenter());
	CH1_y = *(stickModel_chest_0_Source->GetCenter() + 1);
	CH1_z = *(stickModel_chest_0_Source->GetCenter() + 2);
	//cout << CH1_x << "\t" << CH1_y << "\t" << CH1_z << endl;
	stickModel_chest_1_Transform->SetInput(stickModel_chest_0_Transform);
	stickModel_chest_1_Actor->SetUserTransform(stickModel_chest_1_Transform);
	stickModel_chest_1_Mapper->SetInputConnection(stickModel_chest_1_Source->GetOutputPort());
	stickModel_chest_1_Actor->SetMapper(stickModel_chest_1_Mapper);
	stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());


	//stickModel_chest 2
	stickModel_chest_2_Source->SetRadius(2.85);
	stickModel_chest_2_Source->SetPhiResolution(100);
	stickModel_chest_2_Source->SetThetaResolution(100);
	stickModel_chest_2_Source->SetCenter(*(stickModel_chest_1_Source->GetCenter()),
		*(stickModel_chest_1_Source->GetCenter() + 1) + stickModel_chest_1_Source->GetRadius() + stickModel_chest_2_Source->GetRadius(),
		*(stickModel_chest_1_Source->GetCenter() + 2));
	//CH2_x = *(stickModel_chest_1_Source->GetCenter());
	//CH2_y = *(stickModel_chest_1_Source->GetCenter() + 1) + stickModel_chest_1_Source->GetRadius() + stickModel_chest_2_Source->GetRadius();
	//CH2_z = *(stickModel_chest_1_Source->GetCenter() + 2);
	//cout << CH2_x << "\t" << CH2_y << "\t" << CH2_z << endl;*/
	stickModel_chest_2_Transform->SetInput(stickModel_chest_1_Transform);
	stickModel_chest_2_Actor->SetUserTransform(stickModel_chest_2_Transform);
	stickModel_chest_2_Mapper->SetInputConnection(stickModel_chest_2_Source->GetOutputPort());
	stickModel_chest_2_Actor->SetMapper(stickModel_chest_2_Mapper);
	stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());


	//stickModel_chest 3
	stickModel_chest_3_Source->SetRadius(3.75);
	stickModel_chest_3_Source->SetPhiResolution(100);
	stickModel_chest_3_Source->SetThetaResolution(100);
	stickModel_chest_3_Source->SetCenter(*(stickModel_chest_2_Source->GetCenter()),
		*(stickModel_chest_2_Source->GetCenter() + 1) + stickModel_chest_2_Source->GetRadius() + stickModel_chest_3_Source->GetRadius(),
		*(stickModel_chest_2_Source->GetCenter() + 2));
	//CH3_x = *(stickModel_chest_2_Source->GetCenter());
	//CH3_y = *(stickModel_chest_2_Source->GetCenter() + 1) + stickModel_chest_2_Source->GetRadius() + stickModel_chest_3_Source->GetRadius();
	//CH3_z = *(stickModel_chest_2_Source->GetCenter() + 2);
	//cout << CH3_x << "\t" << CH3_y << "\t" << CH3_z << endl;
	stickModel_chest_3_Transform->SetInput(stickModel_chest_2_Transform);
	stickModel_chest_3_Actor->SetUserTransform(stickModel_chest_3_Transform);
	stickModel_chest_3_Mapper->SetInputConnection(stickModel_chest_3_Source->GetOutputPort());
	stickModel_chest_3_Actor->SetMapper(stickModel_chest_3_Mapper);
	stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//stickModel_head
	stickModel_head_objFile = "../BodyGestureGenerator/data/humanHead1.obj";
	const char* stickModel_headTexture_filename = "../BodyGestureGenerator/data/headmap.jpg";
	stickModel_head_Reader->SetFileName(stickModel_head_objFile.c_str());
	stickModel_head_Mapper->SetInputConnection(stickModel_head_Reader->GetOutputPort());

	stickModel_head_Transform->Translate(*(stickModel_chest_3_Source->GetCenter()),
		*(stickModel_chest_3_Source->GetCenter() + 1) + stickModel_chest_3_Source->GetRadius() + 0.05,
		*(stickModel_chest_3_Source->GetCenter() + 2));
	stickModel_head_Transform->SetInput(stickModel_chest_3_Transform);
	//H_x = *(chest_3_Source->GetCenter());
	//H_y = *(chest_3_Source->GetCenter() + 1) + chest_3_Source->GetRadius() + 0.05;
	//H_z = *(chest_2_Source->GetCenter() + 2);
	//cout << H_x << "\t" << H_y << "\t" << H_z << endl;
	stickModel_head_Actor->SetUserTransform(stickModel_head_Transform);
	stickModel_head_Actor->SetMapper(stickModel_head_Mapper);
	stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	stickModel_head_Actor->SetScale(8);
	stickModel_headTexture_Reader->SetFileName(headTexture_filename);
	// Apply the texture
	stickModel_head_Texture->SetInputConnection(stickModel_headTexture_Reader->GetOutputPort());
	stickModel_head_Actor->SetTexture(stickModel_head_Texture);
	

	//stickModel_rightShoulderJoint
	stickModel_rightShoulderJoint_Source->SetRadius(3.0);
	stickModel_rightShoulderJoint_Source->SetPhiResolution(100);
	stickModel_rightShoulderJoint_Source->SetThetaResolution(100);
	stickModel_rightShoulderJoint_Source->SetCenter(*(stickModel_chest_3_Source->GetCenter()) - stickModel_chest_3_Source->GetRadius() - stickModel_rightShoulderJoint_Source->GetRadius(),
		*(stickModel_chest_3_Source->GetCenter() + 1) - 1.0,
		*(stickModel_chest_3_Source->GetCenter() + 2));
	Shoulder_x = *(stickModel_chest_3_Source->GetCenter()) - stickModel_chest_3_Source->GetRadius() - stickModel_rightShoulderJoint_Source->GetRadius();
	Shoulder_y = *(stickModel_chest_3_Source->GetCenter() + 1) - 1.0;
	Shoulder_z = *(stickModel_chest_3_Source->GetCenter() + 2);
	stickModel_rightShoulderJoint_Transform->SetInput(stickModel_chest_3_Transform);
	stickModel_rightShoulderJoint_Actor->SetUserTransform(stickModel_rightShoulderJoint_Transform);
	stickModel_rightShoulderJoint_Mapper->SetInputConnection(stickModel_rightShoulderJoint_Source->GetOutputPort());
	stickModel_rightShoulderJoint_Actor->SetMapper(stickModel_rightShoulderJoint_Mapper);
	/*stickModel_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());*/
	//stickModel_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
	stickModel_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
	stickModel_rightShoulderJoint_Actor->GetProperty()->SetSpecular(.5);
	stickModel_rightShoulderJoint_Actor->GetProperty()->SetSpecularPower(20);

	//stickModel_rightUpperArm
	stickModel_rightUpperArm_Source->SetRadius(1.5);
	stickModel_rightUpperArm_Source->SetHeight(12.0);
	stickModel_rightUpperArm_Source->SetResolution(20);
	stickModel_rightUpperArm_Source->SetCenter(*(stickModel_rightShoulderJoint_Source->GetCenter()),
		*(stickModel_rightShoulderJoint_Source->GetCenter() + 1) - stickModel_rightUpperArm_Source->GetHeight() / 2 - stickModel_rightShoulderJoint_Source->GetRadius(),
		*(stickModel_rightShoulderJoint_Source->GetCenter() + 2));
	stickModel_rightUpperArm_Mapper->SetInputConnection(stickModel_rightUpperArm_Source->GetOutputPort());
	stickModel_rightUpperArm_Transform->SetInput(stickModel_rightShoulderJoint_Transform);
	stickModel_rightUpperArm_Actor->SetUserTransform(stickModel_rightUpperArm_Transform);
	stickModel_rightUpperArm_Actor->SetMapper(stickModel_rightUpperArm_Mapper);
	stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
	smUA_x = *(stickModel_rightShoulderJoint_Source->GetCenter());
	smUA_y = *(stickModel_rightShoulderJoint_Source->GetCenter() + 1) ;
	smUA_z = *(stickModel_rightShoulderJoint_Source->GetCenter() + 2);
	//cout << smUA_x << "\t" << smUA_y << "\t" << smUA_y << endl;


	//stickModel_rightElbow
	stickModel_rightElbow_Source->SetRadius(1.5);
	stickModel_rightElbow_Source->SetPhiResolution(100);
	stickModel_rightElbow_Source->SetThetaResolution(100);
	stickModel_rightElbow_Source->SetCenter(*(stickModel_rightUpperArm_Source->GetCenter()),
		*(stickModel_rightUpperArm_Source->GetCenter() + 1) - (stickModel_rightUpperArm_Source->GetHeight() / 2) - stickModel_rightElbow_Source->GetRadius(),
		*(stickModel_rightUpperArm_Source->GetCenter() + 2));
	stickModel_rightElbow_Transform->SetInput(stickModel_rightUpperArm_Transform);
	stickModel_rightElbow_Actor->SetUserTransform(stickModel_rightElbow_Transform);
	stickModel_rightElbow_Mapper->SetInputConnection(stickModel_rightElbow_Source->GetOutputPort());
	stickModel_rightElbow_Actor->SetMapper(stickModel_rightElbow_Mapper);
	stickModel_rightElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());

	   	

	//stickModel_rightLowerArm
	stickModel_rightLowerArm_Source->SetRadius(1.5);
	stickModel_rightLowerArm_Source->SetHeight(12.0);
	stickModel_rightLowerArm_Source->SetResolution(20);
	stickModel_rightLowerArm_Source->SetCenter(*(stickModel_rightElbow_Source->GetCenter()),
		*(stickModel_rightElbow_Source->GetCenter() + 1) - stickModel_rightLowerArm_Source->GetHeight() / 2 - stickModel_rightElbow_Source->GetRadius(),
		*(stickModel_rightElbow_Source->GetCenter() + 2));
	stickModel_rightLowerArm_Mapper->SetInputConnection(stickModel_rightLowerArm_Source->GetOutputPort());
	stickModel_rightLowerArm_Transform->SetInput(stickModel_rightElbow_Transform);
	stickModel_rightLowerArm_Actor->SetUserTransform(stickModel_rightLowerArm_Transform);
	stickModel_rightLowerArm_Actor->SetMapper(stickModel_rightLowerArm_Mapper);
	stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
	smLA_x = *(stickModel_rightElbow_Source->GetCenter());
	smLA_y = *(stickModel_rightElbow_Source->GetCenter() + 1) ;
	smLA_z = *(stickModel_rightElbow_Source->GetCenter() + 2);
	//cout << smLA_x << "\t" << smLA_y << "\t" << smLA_y << endl;


	//stickModel_rightHand
	stickModel_rightHand_objFile = "../BodyGestureGenerator/data/RH_G.obj";
	stickModel_rightHand_Reader->SetFileName(stickModel_rightHand_objFile.c_str());
	stickModel_rightHand_Mapper->SetInputConnection(stickModel_rightHand_Reader->GetOutputPort());
	stickModel_rightHand_Transform->Translate(*(stickModel_rightLowerArm_Source->GetCenter()),
		*(stickModel_rightLowerArm_Source->GetCenter() + 1) - stickModel_rightLowerArm_Source->GetHeight() / 2,
		*(stickModel_rightLowerArm_Source->GetCenter() + 2));
	smH_x = *(stickModel_rightLowerArm_Source->GetCenter());
	smH_y = *(stickModel_rightLowerArm_Source->GetCenter() + 1) - stickModel_rightLowerArm_Source->GetHeight() / 2;
	smH_z = *(stickModel_rightLowerArm_Source->GetCenter() + 2);
	cout << smH_x << "\t" << smH_y << "\t" << smH_z << endl;
	stickModel_rightHand_Transform->SetInput(stickModel_rightLowerArm_Transform);
	stickModel_rightHand_Actor->SetUserTransform(stickModel_rightHand_Transform);
	stickModel_rightHand_Actor->SetMapper(stickModel_rightHand_Mapper);
	//stickModel_rightHand_Actor->RotateY(-7);
	stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	stickModel_rightHand_Actor->SetScale(0.95);



	//stickModel_leftShoulderJoint
	stickModel_leftShoulderJoint_Source->SetRadius(3.0);
	stickModel_leftShoulderJoint_Source->SetPhiResolution(100);
	stickModel_leftShoulderJoint_Source->SetThetaResolution(100);
	stickModel_leftShoulderJoint_Source->SetCenter(*(stickModel_chest_3_Source->GetCenter()) + stickModel_chest_3_Source->GetRadius() + stickModel_leftShoulderJoint_Source->GetRadius(),
		*(stickModel_chest_3_Source->GetCenter() + 1) - 1.0,
		*(stickModel_chest_3_Source->GetCenter() + 2));
	stickModel_leftShoulderJoint_Transform->SetInput(stickModel_chest_3_Transform);
	stickModel_leftShoulderJoint_Actor->SetUserTransform(stickModel_leftShoulderJoint_Transform);
	stickModel_leftShoulderJoint_Mapper->SetInputConnection(stickModel_leftShoulderJoint_Source->GetOutputPort());
	stickModel_leftShoulderJoint_Actor->SetMapper(stickModel_leftShoulderJoint_Mapper);
	stickModel_leftShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//stickModel_leftUpperArm
	stickModel_leftUpperArm_Source->SetRadius(1.5);
	stickModel_leftUpperArm_Source->SetHeight(12.0);
	stickModel_leftUpperArm_Source->SetResolution(20);
	stickModel_leftUpperArm_Source->SetCenter(*(stickModel_leftShoulderJoint_Source->GetCenter()),
		*(stickModel_leftShoulderJoint_Source->GetCenter() + 1) - stickModel_leftUpperArm_Source->GetHeight() / 2 - stickModel_leftShoulderJoint_Source->GetRadius(),
		*(stickModel_leftShoulderJoint_Source->GetCenter() + 2));
	stickModel_leftUpperArm_Mapper->SetInputConnection(stickModel_leftUpperArm_Source->GetOutputPort());
	stickModel_leftUpperArm_Transform->SetInput(stickModel_leftShoulderJoint_Transform);
	stickModel_leftUpperArm_Actor->SetUserTransform(stickModel_leftUpperArm_Transform);
	stickModel_leftUpperArm_Actor->SetMapper(stickModel_leftUpperArm_Mapper);
	stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
	

	//stickModel_leftElbow
	stickModel_leftElbow_Source->SetRadius(1.5);
	stickModel_leftElbow_Source->SetPhiResolution(100);
	stickModel_leftElbow_Source->SetThetaResolution(100);
	stickModel_leftElbow_Source->SetCenter(*(stickModel_leftUpperArm_Source->GetCenter()),
		*(stickModel_leftUpperArm_Source->GetCenter() + 1) - (stickModel_leftUpperArm_Source->GetHeight() / 2) - stickModel_leftElbow_Source->GetRadius(),
		*(stickModel_leftUpperArm_Source->GetCenter() + 2));
	stickModel_leftElbow_Transform->SetInput(stickModel_leftUpperArm_Transform);
	stickModel_leftElbow_Actor->SetUserTransform(stickModel_leftElbow_Transform);
	stickModel_leftElbow_Mapper->SetInputConnection(stickModel_leftElbow_Source->GetOutputPort());
	stickModel_leftElbow_Actor->SetMapper(stickModel_leftElbow_Mapper);
	stickModel_leftElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());

	//stickModel_leftLowerArm
	stickModel_leftLowerArm_Source->SetRadius(1.5);
	stickModel_leftLowerArm_Source->SetHeight(12.0);
	stickModel_leftLowerArm_Source->SetResolution(20);
	stickModel_leftLowerArm_Source->SetCenter(*(stickModel_leftElbow_Source->GetCenter()),
		*(stickModel_leftElbow_Source->GetCenter() + 1) - stickModel_leftLowerArm_Source->GetHeight() / 2 - stickModel_leftElbow_Source->GetRadius(),
		*(stickModel_leftElbow_Source->GetCenter() + 2));
	stickModel_leftLowerArm_Mapper->SetInputConnection(stickModel_leftLowerArm_Source->GetOutputPort());
	stickModel_leftLowerArm_Transform->SetInput(stickModel_leftElbow_Transform);
	stickModel_leftLowerArm_Actor->SetUserTransform(stickModel_leftLowerArm_Transform);
	stickModel_leftLowerArm_Actor->SetMapper(stickModel_leftLowerArm_Mapper);
	stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());


	//stickModel_leftHand
	stickModel_leftHand_objFile = "../BodyGestureGenerator/data/LH_G.obj";
	stickModel_leftHand_Reader->SetFileName(stickModel_leftHand_objFile.c_str());
	stickModel_leftHand_Mapper->SetInputConnection(stickModel_leftHand_Reader->GetOutputPort());
	stickModel_leftHand_Transform->Translate(*(stickModel_leftLowerArm_Source->GetCenter()), *(stickModel_leftLowerArm_Source->GetCenter() + 1) - stickModel_leftLowerArm_Source->GetHeight() / 2 - 0.03, *(stickModel_leftLowerArm_Source->GetCenter() + 2) - 0.05);
	stickModel_leftHand_Transform->SetInput(stickModel_leftLowerArm_Transform);
	stickModel_leftHand_Actor->SetUserTransform(stickModel_leftHand_Transform);
	stickModel_leftHand_Actor->SetMapper(stickModel_leftHand_Mapper);
	//stickModel_leftHand_Actor->RotateY(-7);
	stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	stickModel_leftHand_Actor->SetScale(0.95);


	//stickModel_rightLegJoint
	stickModel_rightLegJoint_Source->SetRadius(2.75);
	stickModel_rightLegJoint_Source->SetPhiResolution(100);
	stickModel_rightLegJoint_Source->SetThetaResolution(100);
	stickModel_rightLegJoint_Source->SetCenter(*(stickModel_pelvisSource->GetCenter()) - stickModel_pelvisSource->GetRadius(),
		*(stickModel_pelvisSource->GetCenter() + 1) - 2.0,
		*(stickModel_pelvisSource->GetCenter() + 2));
	stickModel_rightLegJoint_Transform->SetInput(stickModel_pelvisTransform);
	stickModel_rightLegJoint_Actor->SetUserTransform(stickModel_rightLegJoint_Transform);
	stickModel_rightLegJoint_Mapper->SetInputConnection(stickModel_rightLegJoint_Source->GetOutputPort());
	stickModel_rightLegJoint_Actor->SetMapper(stickModel_rightLegJoint_Mapper);
	stickModel_rightLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//stickModel_rightUpperLeg
	stickModel_rightUpperLeg_Source->SetRadius(1.5);
	stickModel_rightUpperLeg_Source->SetHeight(17.0);
	stickModel_rightUpperLeg_Source->SetResolution(20);
	stickModel_rightUpperLeg_Source->SetCenter(*(stickModel_rightLegJoint_Source->GetCenter()),
		*(stickModel_rightLegJoint_Source->GetCenter() + 1) - stickModel_rightUpperLeg_Source->GetHeight() / 2 - stickModel_rightLegJoint_Source->GetRadius(),
		*(stickModel_rightLegJoint_Source->GetCenter() + 2));
	smUL_x = *(stickModel_rightLegJoint_Source->GetCenter());
	smUL_y = *(stickModel_rightLegJoint_Source->GetCenter() + 1);
	smUL_z = *(stickModel_rightLegJoint_Source->GetCenter() + 2);
	//cout << smUL_x << "\t" << smUL_y << "\t" << smUL_z << endl;
	stickModel_rightUpperLeg_Mapper->SetInputConnection(stickModel_rightUpperLeg_Source->GetOutputPort());
	stickModel_rightUpperLeg_Transform->SetInput(stickModel_rightLegJoint_Transform);
	stickModel_rightUpperLeg_Actor->SetUserTransform(stickModel_rightUpperLeg_Transform);
	stickModel_rightUpperLeg_Actor->SetMapper(stickModel_rightUpperLeg_Mapper);
	stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());


	//stickModel_rightKnee
	stickModel_rightKnee_Source->SetRadius(1.5);
	stickModel_rightKnee_Source->SetPhiResolution(100);
	stickModel_rightKnee_Source->SetThetaResolution(100);
	stickModel_rightKnee_Source->SetCenter(*(stickModel_rightUpperLeg_Source->GetCenter()),
		*(stickModel_rightUpperLeg_Source->GetCenter() + 1) - (stickModel_rightUpperLeg_Source->GetHeight() / 2) - stickModel_rightKnee_Source->GetRadius(),
		*(stickModel_rightUpperLeg_Source->GetCenter() + 2));
	stickModel_rightKnee_Transform->SetInput(stickModel_rightUpperLeg_Transform);
	stickModel_rightKnee_Actor->SetUserTransform(stickModel_rightKnee_Transform);
	stickModel_rightKnee_Mapper->SetInputConnection(stickModel_rightKnee_Source->GetOutputPort());
	stickModel_rightKnee_Actor->SetMapper(stickModel_rightKnee_Mapper);
	stickModel_rightKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());

	//stickModel_rightLowerLeg
	stickModel_rightLowerLeg_Source->SetRadius(1.5);
	stickModel_rightLowerLeg_Source->SetHeight(16.0);
	stickModel_rightLowerLeg_Source->SetResolution(20);
	stickModel_rightLowerLeg_Source->SetCenter(*(stickModel_rightKnee_Source->GetCenter()),
		*(stickModel_rightKnee_Source->GetCenter() + 1) - stickModel_rightLowerLeg_Source->GetHeight() / 2 - stickModel_rightKnee_Source->GetRadius(),
		*(stickModel_rightKnee_Source->GetCenter() + 2));

	smLL_x = *(stickModel_rightKnee_Source->GetCenter());
	smLL_y = *(stickModel_rightKnee_Source->GetCenter() + 1) ;
	smLL_z = *(stickModel_rightKnee_Source->GetCenter() + 2);
	//cout << smLL_x << "\t" << smLL_y << "\t" << smLL_z << endl;

	stickModel_rightLowerLeg_Mapper->SetInputConnection(stickModel_rightLowerLeg_Source->GetOutputPort());
	stickModel_rightLowerLeg_Transform->SetInput(stickModel_rightKnee_Transform);
	stickModel_rightLowerLeg_Actor->SetUserTransform(stickModel_rightLowerLeg_Transform);
	stickModel_rightLowerLeg_Actor->SetMapper(stickModel_rightLowerLeg_Mapper);
	stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
	

	// stickModel_rightFoot
	stickModel_rightFoot_objFile = "../BodyGestureGenerator/data/RF.obj";
	stickModel_rightFoot_Reader->SetFileName(stickModel_rightFoot_objFile.c_str());
	stickModel_rightFoot_Mapper->SetInputConnection(stickModel_rightFoot_Reader->GetOutputPort());
	stickModel_rightFoot_Transform->Translate(*(stickModel_rightLowerLeg_Source->GetCenter()),
		*(stickModel_rightLowerLeg_Source->GetCenter() + 1) - stickModel_rightLowerLeg_Source->GetHeight() / 2,
		*(stickModel_rightLowerLeg_Source->GetCenter() + 2));
	smF_x = *(stickModel_rightLowerLeg_Source->GetCenter());
	smF_y = *(stickModel_rightLowerLeg_Source->GetCenter() + 1) - stickModel_rightLowerLeg_Source->GetHeight() / 2;
	smF_z = *(stickModel_rightLowerLeg_Source->GetCenter() + 2);
	//cout << rFx << "\t" << rFy << "\t" << rFz << endl;
	stickModel_rightFoot_Transform->SetInput(stickModel_rightLowerLeg_Transform);
	stickModel_rightFoot_Actor->SetUserTransform(stickModel_rightFoot_Transform);
	stickModel_rightFoot_Actor->SetMapper(stickModel_rightFoot_Mapper);
	stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	stickModel_rightFoot_Actor->SetScale(50.0);

	//stickModel_leftLegJoint
	stickModel_leftLegJoint_Source->SetRadius(2.75);
	stickModel_leftLegJoint_Source->SetPhiResolution(100);
	stickModel_leftLegJoint_Source->SetThetaResolution(100);
	stickModel_leftLegJoint_Source->SetCenter(*(stickModel_pelvisSource->GetCenter()) + stickModel_pelvisSource->GetRadius(),
		*(stickModel_pelvisSource->GetCenter() + 1) - 2.0,
		*(stickModel_pelvisSource->GetCenter() + 2));

	stickModel_leftLegJoint_Transform->SetInput(stickModel_pelvisTransform);
	stickModel_leftLegJoint_Actor->SetUserTransform(stickModel_leftLegJoint_Transform);
	stickModel_leftLegJoint_Mapper->SetInputConnection(stickModel_leftLegJoint_Source->GetOutputPort());
	stickModel_leftLegJoint_Actor->SetMapper(stickModel_leftLegJoint_Mapper);
	stickModel_leftLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());

	//stickModel_leftUpperLeg
	stickModel_leftUpperLeg_Source->SetRadius(1.5);
	stickModel_leftUpperLeg_Source->SetHeight(17.0);
	stickModel_leftUpperLeg_Source->SetResolution(20);
	stickModel_leftUpperLeg_Source->SetCenter(*(stickModel_leftLegJoint_Source->GetCenter()),
		*(stickModel_leftLegJoint_Source->GetCenter() + 1) - stickModel_leftUpperLeg_Source->GetHeight() / 2 - stickModel_leftLegJoint_Source->GetRadius(),
		*(stickModel_leftLegJoint_Source->GetCenter() + 2));
	stickModel_leftUpperLeg_Mapper->SetInputConnection(stickModel_leftUpperLeg_Source->GetOutputPort());
	stickModel_leftUpperLeg_Transform->SetInput(stickModel_leftLegJoint_Transform);
	stickModel_leftUpperLeg_Actor->SetUserTransform(stickModel_leftUpperLeg_Transform);
	stickModel_leftUpperLeg_Actor->SetMapper(stickModel_leftUpperLeg_Mapper);
	stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	//stickModel_leftKnee
	stickModel_leftKnee_Source->SetRadius(1.5);
	stickModel_leftKnee_Source->SetPhiResolution(100);
	stickModel_leftKnee_Source->SetThetaResolution(100);
	stickModel_leftKnee_Source->SetCenter(*(stickModel_leftUpperLeg_Source->GetCenter()),
		*(stickModel_leftUpperLeg_Source->GetCenter() + 1) - (stickModel_leftUpperLeg_Source->GetHeight() / 2) - stickModel_leftKnee_Source->GetRadius(),
		*(stickModel_leftUpperLeg_Source->GetCenter() + 2));
	stickModel_leftKnee_Transform->SetInput(stickModel_leftUpperLeg_Transform);
	stickModel_leftKnee_Actor->SetUserTransform(stickModel_leftKnee_Transform);
	stickModel_leftKnee_Mapper->SetInputConnection(stickModel_leftKnee_Source->GetOutputPort());
	stickModel_leftKnee_Actor->SetMapper(stickModel_leftKnee_Mapper);
	stickModel_leftKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());


	//stickModel_leftLowerleg
	stickModel_leftLowerLeg_Source->SetRadius(1.5);
	stickModel_leftLowerLeg_Source->SetHeight(16.0);
	stickModel_leftLowerLeg_Source->SetResolution(20);
	stickModel_leftLowerLeg_Source->SetCenter(*(stickModel_leftKnee_Source->GetCenter()),
		*(stickModel_leftKnee_Source->GetCenter() + 1) - stickModel_leftLowerLeg_Source->GetHeight() / 2 - stickModel_leftKnee_Source->GetRadius(),
		*(stickModel_leftKnee_Source->GetCenter() + 2));
	stickModel_leftLowerLeg_Mapper->SetInputConnection(stickModel_leftLowerLeg_Source->GetOutputPort());
	stickModel_leftLowerLeg_Transform->SetInput(stickModel_leftKnee_Transform);
	stickModel_leftLowerLeg_Actor->SetUserTransform(stickModel_leftLowerLeg_Transform);
	stickModel_leftLowerLeg_Actor->SetMapper(stickModel_leftLowerLeg_Mapper);
	stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());

	// stickModel_leftFoot
	stickModel_leftFoot_objFile = "../BodyGestureGenerator/data/LF.obj";
	stickModel_leftFoot_Reader->SetFileName(stickModel_leftFoot_objFile.c_str());
	stickModel_leftFoot_Mapper->SetInputConnection(stickModel_leftFoot_Reader->GetOutputPort());
	stickModel_leftFoot_Transform->Translate(*(stickModel_leftLowerLeg_Source->GetCenter()),
		*(stickModel_leftLowerLeg_Source->GetCenter() + 1) - stickModel_leftLowerLeg_Source->GetHeight() / 2,
		*(stickModel_leftLowerLeg_Source->GetCenter() + 2));
	stickModel_leftFoot_Transform->SetInput(stickModel_leftLowerLeg_Transform);
	stickModel_leftFoot_Actor->SetUserTransform(stickModel_leftFoot_Transform);
	stickModel_leftFoot_Actor->SetMapper(stickModel_leftFoot_Mapper);
	stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
	stickModel_leftFoot_Actor->SetScale(50.0);
	
	
	stickModel_rightShoulderJoint_Transform->Identity();
	stickModel_rightShoulderJoint_Transform->Translate(Shoulder_x, Shoulder_y, 0);
	stickModel_rightShoulderJoint_Transform->RotateWXYZ(-8, 0, 0,1);
	stickModel_rightShoulderJoint_Transform->Translate(-Shoulder_x, -Shoulder_y, 0);


	stickModel_leftShoulderJoint_Transform->Identity();
	stickModel_leftShoulderJoint_Transform->Translate(-Shoulder_x, Shoulder_y, 0);
	stickModel_leftShoulderJoint_Transform->RotateWXYZ(8, 0, 0, 1);
	stickModel_leftShoulderJoint_Transform->Translate(Shoulder_x, -Shoulder_y, 0);

	   	  
	mRenderer->AddActor(stickModel_pelvisActor);

	mRenderer->AddActor(stickModel_chest_0_Actor);
	mRenderer->AddActor(stickModel_chest_1_Actor);
	mRenderer->AddActor(stickModel_chest_2_Actor);
	mRenderer->AddActor(stickModel_chest_3_Actor);

	mRenderer->AddActor(stickModel_head_Actor);

	mRenderer->AddActor(stickModel_rightShoulderJoint_Actor);
	mRenderer->AddActor(stickModel_rightUpperArm_Actor);
	mRenderer->AddActor(stickModel_rightElbow_Actor);
	mRenderer->AddActor(stickModel_rightLowerArm_Actor);
	//renderer->AddActor(stickModel_rightHand_Actor);

	mRenderer->AddActor(stickModel_leftShoulderJoint_Actor);
	mRenderer->AddActor(stickModel_leftUpperArm_Actor);
	mRenderer->AddActor(stickModel_leftElbow_Actor);
	mRenderer->AddActor(stickModel_leftLowerArm_Actor);
	//renderer->AddActor(stickModel_leftHand_Actor);

	mRenderer->AddActor(stickModel_rightLegJoint_Actor);
	mRenderer->AddActor(stickModel_rightUpperLeg_Actor);
	mRenderer->AddActor(stickModel_rightKnee_Actor);
	mRenderer->AddActor(stickModel_rightLowerLeg_Actor);
	mRenderer->AddActor(stickModel_rightFoot_Actor);

	mRenderer->AddActor(stickModel_leftLegJoint_Actor);
	mRenderer->AddActor(stickModel_leftUpperLeg_Actor);
	mRenderer->AddActor(stickModel_leftKnee_Actor);
	mRenderer->AddActor(stickModel_leftLowerLeg_Actor);
	mRenderer->AddActor(stickModel_leftFoot_Actor);

	mRenderWindow->Render();



}


void multiSensingDataRead(string filePath, std::vector<EulerAngles>& out)
{
	vector<Quaternion> tempQuat;
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
	//string fname = "C:\\Users\\SSPARK\\Desktop\\dataset\\testQuat\\" + senserDataFileName[0];
	std::cout << filePath << std::endl;
	fstream file(filePath, ios::in);

	tempQuat.clear();
	row.clear();
	tempQuat.clear();

	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout << "Could not open the file\n";


	for (int i = 0; i < content.size(); i++)
	{
		//for (int j = 0; j < content[i].size(); j++)
		//{
		//	cout << content[i][j] << " ";
		//}

		if (content[i].size() > 0)
		{

			if (i == 0 || i == 1) continue;
			Quaternion temp;
			temp.setW(std::stod(content[i][1]));
			temp.setX(std::stod(content[i][2]));
			temp.setY(std::stod(content[i][3]));
			temp.setZ(std::stod(content[i][4]));

			tempQuat.push_back(temp);

			//cout << endl;
		}
	}


	double totalx = 0;
	double totaly = 0;
	double totalz = 0;

	out.clear();

	for (int i = 0; i < tempQuat.size(); i++)
	{

		if (i == 0) continue;

		tempQuat[i] = tempQuat[i].multiply(tempQuat[1].inverse());
		tempQuat[i].toEulerAngle(totalx, totaly, totalz);

		EulerAngles temp;
		temp.x_roll = totalx;
		temp.y_pitch = totaly;
		temp.z_yaw = totalz;

		out.push_back(temp);
	}
}


MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{

	mRenderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	mRenderer = vtkSmartPointer<vtkRenderer>::New();
	mInteractor = vtkSmartPointer<QVTKInteractor>::New();
	mInteractorStyle = vtkSmartPointer<vtkInteractorStyle>::New();


	savedPoses.clear();
	savedTarget.clear();


	ui->setupUi(this);

	// Set up the rendering
	mRenderWindow->AddRenderer(mRenderer);

	mRenderWindow->SetInteractor(mInteractor);
	//ui->openGLWidget->SetRenderWindow(mRenderWindow);
	ui->openGLWidget->setRenderWindow(mRenderWindow);
	mInteractor->SetInteractorStyle(mInteractorStyle);
	mInteractor->Initialize();


	// Set the background color
	mRenderer->SetBackground(1, 1, 1);

	mRenderer->ResetCamera();
	mRenderWindow->Render();


	ui->comboBox->addItem("Select");
	ui->comboBox->addItem("Humanoid Model");
	ui->comboBox->addItem("Skeletal Model");

	for (int i = 0; i < 13; i++)
	{

		qp[i].setW(1); qp[i].setX(0); qp[i].setY(0); qp[i].setZ(0);
		qx[i].setW(1); qx[i].setX(0); qx[i].setY(0); qx[i].setZ(0);
		qy[i].setW(1); qy[i].setX(0); qy[i].setY(0); qy[i].setZ(0);
		qz[i].setW(1); qz[i].setX(0); qz[i].setY(0); qz[i].setZ(0);

		xaxisQP[i].setW(1); xaxisQP[i].setX(0); xaxisQP[i].setY(0); xaxisQP[i].setZ(0);
		xaxisQX[i].setW(1); xaxisQX[i].setX(0); xaxisQX[i].setY(0); xaxisQX[i].setZ(0);
		xaxisQY[i].setW(1); xaxisQY[i].setX(0); xaxisQY[i].setY(0); xaxisQY[i].setZ(0);
		xaxisQZ[i].setW(1); xaxisQZ[i].setX(0); xaxisQZ[i].setY(0); xaxisQZ[i].setZ(0);

		yaxisQP[i].setW(1); yaxisQP[i].setX(0); zaxisQP[i].setY(0); zaxisQP[i].setZ(0);
		yaxisQX[i].setW(1); yaxisQX[i].setX(0); zaxisQX[i].setY(0); zaxisQX[i].setZ(0);
		yaxisQY[i].setW(1); yaxisQY[i].setX(0); zaxisQY[i].setY(0); zaxisQY[i].setZ(0);
		yaxisQZ[i].setW(1); yaxisQZ[i].setX(0); zaxisQZ[i].setY(0); zaxisQZ[i].setZ(0);

		zaxisQP[i].setW(1); zaxisQP[i].setX(0); zaxisQP[i].setY(0); zaxisQP[i].setZ(0);
		zaxisQX[i].setW(1); zaxisQX[i].setX(0); zaxisQX[i].setY(0); zaxisQX[i].setZ(0);
		zaxisQY[i].setW(1); zaxisQY[i].setX(0); zaxisQY[i].setY(0); zaxisQY[i].setZ(0);
		zaxisQZ[i].setW(1); zaxisQZ[i].setX(0); zaxisQZ[i].setY(0); zaxisQZ[i].setZ(0);

		// For Inverse kinematics 
		qpIK[i].setW(1); qpIK[i].setX(0); qpIK[i].setY(0); qpIK[i].setZ(0);
		qxIK[i].setW(1); qxIK[i].setX(0); qxIK[i].setY(0); qxIK[i].setZ(0);
		qyIK[i].setW(1); qyIK[i].setX(0); qyIK[i].setY(0); qyIK[i].setZ(0);
		qzIK[i].setW(1); qzIK[i].setX(0); qzIK[i].setY(0); qzIK[i].setZ(0);

		xaxisQP_IK[i].setW(1); xaxisQP_IK[i].setX(0); xaxisQP_IK[i].setY(0); xaxisQP_IK[i].setZ(0);
		xaxisQX_IK[i].setW(1); xaxisQX_IK[i].setX(0); xaxisQX_IK[i].setY(0); xaxisQX_IK[i].setZ(0);
		xaxisQY_IK[i].setW(1); xaxisQY_IK[i].setX(0); xaxisQY_IK[i].setY(0); xaxisQY_IK[i].setZ(0);
		xaxisQZ_IK[i].setW(1); xaxisQZ_IK[i].setX(0); xaxisQZ_IK[i].setY(0); xaxisQZ_IK[i].setZ(0);
		yaxisQP_IK[i].setW(1); yaxisQP_IK[i].setX(0); zaxisQP_IK[i].setY(0); zaxisQP_IK[i].setZ(0);
		yaxisQX_IK[i].setW(1); yaxisQX_IK[i].setX(0); zaxisQX_IK[i].setY(0); zaxisQX_IK[i].setZ(0);
		yaxisQY_IK[i].setW(1); yaxisQY_IK[i].setX(0); zaxisQY_IK[i].setY(0); zaxisQY_IK[i].setZ(0);
		yaxisQZ_IK[i].setW(1); yaxisQZ_IK[i].setX(0); zaxisQZ_IK[i].setY(0); zaxisQZ_IK[i].setZ(0);
		zaxisQP_IK[i].setW(1); zaxisQP_IK[i].setX(0); zaxisQP_IK[i].setY(0); zaxisQP_IK[i].setZ(0);
		zaxisQX_IK[i].setW(1); zaxisQX_IK[i].setX(0); zaxisQX_IK[i].setY(0); zaxisQX_IK[i].setZ(0);
		zaxisQY_IK[i].setW(1); zaxisQY_IK[i].setX(0); zaxisQY_IK[i].setY(0); zaxisQY_IK[i].setZ(0);
		zaxisQZ_IK[i].setW(1); zaxisQZ_IK[i].setX(0); zaxisQZ_IK[i].setY(0); zaxisQZ_IK[i].setZ(0);

	}


	quatTo_posFile.open("pos.txt");
	quatTo_posFile << "FULLBODY" << "\t" << "1" << endl;



	// Set the UI connections
	//QObject::connect(ui->drawSphere_button, &QPushButton::clicked, this, &MainWindow::onDrawSphereClick);
	QObject::connect(ui->drawSphere_button, &QPushButton::clicked, this, &MainWindow::authoring_mode);
	QObject::connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::addPose);
	QObject::connect(ui->BtnView, &QPushButton::clicked, this, &MainWindow::viewing);
	//QObject::connect(ui->btnRadioFixed, &QPushButton::clicked, this, &MainWindow::enableFixedFoots);
	QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectModel(int)));
	QObject::connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::selectList);
	QObject::connect(ui->listWidget_2, &QListWidget::itemClicked, this, &MainWindow::selectTarget);

	QObject::connect(ui->btnSave, &QPushButton::clicked, this, &MainWindow::saveImage);
	QObject::connect(ui->btnTrajectory, &QPushButton::clicked, this, &MainWindow::drawTrajectory);

	QObject::connect(ui->btnDraw, &QPushButton::clicked, this, &MainWindow::drawThetaPhi);
	QObject::connect(ui->targetAddBtn, &QPushButton::clicked, this, &MainWindow::targetAdd);
	QObject::connect(ui->playBtn, &QPushButton::clicked, this, &MainWindow::playTargets);
	QObject::connect(ui->nextBtn, &QPushButton::clicked, this, &MainWindow::nextPosition);
	QObject::connect(ui->sensingBtn, &QPushButton::clicked, this, &MainWindow::sensingPlay);

	//Gesture Target 지정
	nextBtncnt = 0;
	savedTarget.clear();
	fstream ob;
	ui->listWidget_2->clear();
	ob.open("GestureInterface/targetPosition_0.txt", ios::in);	//again opening the file but in reading mode
	int cnt = 0;
	targetPoint temp;
	temp.pos_x = 0;
	temp.pos_y = 0;
	temp.pos_z = 0;

	while (!ob.eof())

	{
		string str;
		ob >> str;

		cnt++;
		if (cnt % 3 == 1)
		{
			temp.pos_x = std::stoi(str);
		}
		if (cnt % 3 == 2)
		{
			temp.pos_y = std::stoi(str);
		}
		if (cnt % 3 == 0)
		{
			temp.pos_z = std::stoi(str);
			savedTarget.push_back(temp);

			string currentName = "targetPoint ";
			currentName += to_string(savedTarget.size());

			ui->listWidget_2->addItem(currentName.c_str());

			temp.pos_x = 0;
			temp.pos_y = 0;
			temp.pos_z = 0;

		}
	}

	ob.close();	//closing the file after use
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::moveToward(std::vector<double> target)
{
}

//Model 선택 지정
void MainWindow::selectModel(int ID)
{
	std::cout << ID << std::endl;
	if (ID == 0)
	{
		cout << "Scene Cleared" << endl;
		mRenderer->RemoveActor(PlconeActor);
		mRenderer->RemoveActor(CUconeActor);
		mRenderer->RemoveActor(Head_objActor);

		mRenderer->RemoveActor(RarmActor);
		mRenderer->RemoveActor(RforearmActor);
		mRenderer->RemoveActor(RightHand_objActor);


		mRenderer->RemoveActor(LarmActor);
		mRenderer->RemoveActor(LforearmActor);
		mRenderer->RemoveActor(LeftHand_objActor);


		mRenderer->RemoveActor(RlulegActor);
		mRenderer->RemoveActor(RllegActor);
		mRenderer->RemoveActor(RF_objActor);

		mRenderer->RemoveActor(LlulegActor);
		mRenderer->RemoveActor(LllegActor);
		mRenderer->RemoveActor(LF_objActor);


		mRenderer->RemoveActor(stickModel_pelvisActor);

		mRenderer->RemoveActor(stickModel_chest_0_Actor);
		mRenderer->RemoveActor(stickModel_chest_1_Actor);
		mRenderer->RemoveActor(stickModel_chest_2_Actor);
		mRenderer->RemoveActor(stickModel_chest_3_Actor);

		mRenderer->RemoveActor(stickModel_head_Actor);

		mRenderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
		mRenderer->RemoveActor(stickModel_rightUpperArm_Actor);
		mRenderer->RemoveActor(stickModel_rightElbow_Actor);
		mRenderer->RemoveActor(stickModel_rightLowerArm_Actor);
		mRenderer->RemoveActor(stickModel_rightHand_Actor);

		mRenderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
		mRenderer->RemoveActor(stickModel_leftUpperArm_Actor);
		mRenderer->RemoveActor(stickModel_leftElbow_Actor);
		mRenderer->RemoveActor(stickModel_leftLowerArm_Actor);
		mRenderer->RemoveActor(stickModel_leftHand_Actor);

		mRenderer->RemoveActor(stickModel_rightLegJoint_Actor);
		mRenderer->RemoveActor(stickModel_rightUpperLeg_Actor);
		mRenderer->RemoveActor(stickModel_rightKnee_Actor);
		mRenderer->RemoveActor(stickModel_rightLowerLeg_Actor);
		mRenderer->RemoveActor(stickModel_rightFoot_Actor);

		mRenderer->RemoveActor(stickModel_leftLegJoint_Actor);
		mRenderer->RemoveActor(stickModel_leftUpperLeg_Actor);
		mRenderer->RemoveActor(stickModel_leftKnee_Actor);
		mRenderer->RemoveActor(stickModel_leftLowerLeg_Actor);
		mRenderer->RemoveActor(stickModel_leftFoot_Actor);


		mRenderer->AddActor(none_xaxis_actor);
		mRenderer->AddActor(none_yaxis_actor);
		mRenderer->AddActor(none_zaxis_actor);

		mRenderer->RemoveActor(rh_outlineActor);
		rhIK_flag = 0;
		mRenderer->RemoveActor(lh_outlineActor);
		lhIK_flag = 0;
		mRenderer->RemoveActor(rf_outlineActor);
		rfIK_flag = 0;
		mRenderer->RemoveActor(lf_outlineActor);
		lfIK_flag = 0;

		mRenderer->RemoveActor(pelvisJS_actor);
		mRenderer->RemoveActor(chestJS_actor);
		mRenderer->RemoveActor(LUA_JS_actor);
		mRenderer->RemoveActor(LLA_JS_actor);
		mRenderer->RemoveActor(RUA_JS_actor);
		mRenderer->RemoveActor(RLA_JS_actor);
		mRenderer->RemoveActor(LUL_JS_actor);
		mRenderer->RemoveActor(LLL_JS_actor);
		mRenderer->RemoveActor(RUL_JS_actor);
		mRenderer->RemoveActor(RLL_JS_actor);

		mRenderWindow->Render();
	}
	if (ID == 1)
	{
		male_biped = 1;
		vitruvian_biped = 0;
		skeleton_biped = 0;
		cout << "Male Biped Selected" << endl;

		Pelvis_objFilename = "../BodyGestureGenerator/data/Pelvis.obj";
		Chest_objFilename = "../BodyGestureGenerator/data/Chest.obj";
		headNeck_objFilename = "../BodyGestureGenerator/data/humanHead1.obj";
		LUA_objFilename = "../BodyGestureGenerator/data/LUA.obj";
		LLA_objFilename = "../BodyGestureGenerator/data/LLA.obj";
		LH_objFilename = "../BodyGestureGenerator/data/LH_G.obj";
		RUA_objFilename = "../BodyGestureGenerator/data/RUA.obj";
		RLA_objFilename = "../BodyGestureGenerator/data/RLA.obj";
		RH_objFilename = "../BodyGestureGenerator/data/RH_G.obj";
		LUL_objFilename = "../BodyGestureGenerator/data/LUL.obj";
		LLL_objFilename = "../BodyGestureGenerator/data/LLL.obj";
		LF_objFilename = "../BodyGestureGenerator/data/LF.obj";
		RUL_objFilename = "../BodyGestureGenerator/data/RUL.obj";
		RLL_objFilename = "../BodyGestureGenerator/data/RLL.obj";
		RF_objFilename = "../BodyGestureGenerator/data/RF.obj";

		PlconeTransform->Identity();
		CUconeTransform->Identity();
		Head_ObjReader_Transform->Identity();
		RarmTransform->Identity();
		RforearmTransform->Identity();
		RightHand_ObjReader_Transform->Identity();
		LarmTransform->Identity();
		LforearmTransform->Identity();
		LeftHand_ObjReader_Transform->Identity();
		RlulegTransform->Identity();
		RllegTransform->Identity();
		RF_ObjReader_Transform->Identity();
		LlulegTransform->Identity();
		LllegTransform->Identity();
		LF_ObjReader_Transform->Identity();

		RUA_JS_Transform->Identity();
		RLA_JS_Transform->Identity();
		LUA_JS_Transform->Identity();
		LLA_JS_Transform->Identity();
		RUL_JS_Transform->Identity();
		RLL_JS_Transform->Identity();
		LUL_JS_Transform->Identity();
		LLL_JS_Transform->Identity();

		pelvisObj_xpos = 0;
		pelvisObj_ypos = 47.875;
		pelvisObj_zpos = 0;
		pelvisObj_scale = 50;

		chestObj_xpos = 0;
		chestObj_ypos = 2.5;
		chestObj_zpos = 0;
		chestObj_scale = 50;

		head_NeckObj_xpos = 0;
		head_NeckObj_ypos = 26.0;
		head_NeckObj_zpos = -1.0;
		head_NeckObj_scale = 8;


		ruaObj_xpos = -10.5;
		ruaObj_ypos = 20.0;
		ruaObj_zpos = -2.5;
		ruaObj_scale = 50;

		rlaObj_xpos = 0.0;
		rlaObj_ypos = -14.0;
		rlaObj_zpos = 1.0;
		rlaObj_scale = 50;

		RHObj_xpos = -0.5;
		RHObj_ypos = -12.75;
		RHObj_zpos = 0.5;
		RHObj_scale = 40;

		luaObj_xpos = 10.50;
		luaObj_ypos = 20.0;
		luaObj_zpos = -2.5;
		luaObj_scale = 50;

		llaObj_xpos = 0.5;
		llaObj_ypos = -14.0;
		llaObj_zpos = 0.5;
		llaObj_scale = 50;

		LHObj_xpos = -0.5;
		LHObj_ypos = -12.75;
		LHObj_zpos = 0.5;
		LHObj_scale = 40;


		rulObj_xpos = -3.40;
		rulObj_ypos = 0; //-2.125
		rulObj_zpos = 0.0;
		rulObj_scale = 50;

		rllObj_xpos = -0.25;
		rllObj_ypos = -21.0;
		rllObj_zpos = 0.0;
		rllObj_scale = 50;

		RFObj_xpos = 0.7;
		RFObj_ypos = -19.25;
		RFObj_zpos = -2.10;
		RFObj_scale = 50;
		RF_xaxis_actor_Zpos = 20;

		lulObj_xpos = 3.90;
		lulObj_ypos = 0; //-2.125
		lulObj_zpos = 0.0;
		lulObj_scale = 50;

		lllObj_xpos = 1.0;
		lllObj_ypos = -21.0;
		lllObj_zpos = -0.75;
		lllObj_scale = 50;

		LFObj_xpos = 0.0;
		LFObj_ypos = -19.25;
		LFObj_zpos = -2.10;
		LFObj_scale = 50;


		mRenderer->RemoveActor(stickModel_pelvisActor);
		mRenderer->RemoveActor(stickModel_chest_0_Actor);
		mRenderer->RemoveActor(stickModel_chest_1_Actor);
		mRenderer->RemoveActor(stickModel_chest_2_Actor);
		mRenderer->RemoveActor(stickModel_chest_3_Actor);
		mRenderer->RemoveActor(stickModel_head_Actor);
		mRenderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
		mRenderer->RemoveActor(stickModel_rightUpperArm_Actor);
		mRenderer->RemoveActor(stickModel_rightElbow_Actor);
		mRenderer->RemoveActor(stickModel_rightLowerArm_Actor);
		mRenderer->RemoveActor(stickModel_rightHand_Actor);
		mRenderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
		mRenderer->RemoveActor(stickModel_leftUpperArm_Actor);
		mRenderer->RemoveActor(stickModel_leftElbow_Actor);
		mRenderer->RemoveActor(stickModel_leftLowerArm_Actor);
		mRenderer->RemoveActor(stickModel_leftHand_Actor);
		mRenderer->RemoveActor(stickModel_rightLegJoint_Actor);
		mRenderer->RemoveActor(stickModel_rightUpperLeg_Actor);
		mRenderer->RemoveActor(stickModel_rightKnee_Actor);
		mRenderer->RemoveActor(stickModel_rightLowerLeg_Actor);
		mRenderer->RemoveActor(stickModel_rightFoot_Actor);
		mRenderer->RemoveActor(stickModel_leftLegJoint_Actor);
		mRenderer->RemoveActor(stickModel_leftUpperLeg_Actor);
		mRenderer->RemoveActor(stickModel_leftKnee_Actor);
		mRenderer->RemoveActor(stickModel_leftLowerLeg_Actor);
		mRenderer->RemoveActor(stickModel_leftFoot_Actor);
		mRenderer->RemoveActor(none_xaxis_actor);
		mRenderer->RemoveActor(none_yaxis_actor);
		mRenderer->RemoveActor(none_zaxis_actor);


		mRenderer->RemoveActor(rh_outlineActor);
		rhIK_flag = 0;
		mRenderer->RemoveActor(lh_outlineActor);
		lhIK_flag = 0;
		mRenderer->RemoveActor(rf_outlineActor);
		rfIK_flag = 0;
		mRenderer->RemoveActor(lf_outlineActor);
		lfIK_flag = 0;

		mRenderer->RemoveActor(pelvisJS_actor);
		mRenderer->RemoveActor(chestJS_actor);
		mRenderer->RemoveActor(LUA_JS_actor);
		mRenderer->RemoveActor(LLA_JS_actor);
		mRenderer->RemoveActor(RUA_JS_actor);
		mRenderer->RemoveActor(RLA_JS_actor);
		mRenderer->RemoveActor(LUL_JS_actor);
		mRenderer->RemoveActor(LLL_JS_actor);
		mRenderer->RemoveActor(RUL_JS_actor);
		mRenderer->RemoveActor(RLL_JS_actor);


		displayRobot_Model(1);
		mRenderWindow->Render();
	}
	if (ID == 2)
	{

		male_biped = 0;
		vitruvian_biped = 0;
		skeleton_biped = 1;
		cout << "Stick Biped Selected" << endl;


		stickModel_pelvisTransform->Identity();
		stickModel_chest_0_Transform->Identity();
		stickModel_chest_1_Transform->Identity();
		stickModel_chest_2_Transform->Identity();
		stickModel_chest_3_Transform->Identity();

		stickModel_head_Transform->Identity();

		stickModel_rightShoulderJoint_Transform->Identity();
		stickModel_rightUpperArm_Transform->Identity();
		stickModel_rightElbow_Transform->Identity();
		stickModel_rightLowerArm_Transform->Identity();
		stickModel_rightHand_Transform->Identity();

		stickModel_leftShoulderJoint_Transform->Identity();
		stickModel_leftUpperArm_Transform->Identity();
		stickModel_leftElbow_Transform->Identity();
		stickModel_leftLowerArm_Transform->Identity();
		stickModel_leftHand_Transform->Identity();

		stickModel_rightLegJoint_Transform->Identity();
		stickModel_rightUpperLeg_Transform->Identity();
		stickModel_rightKnee_Transform->Identity();
		stickModel_rightLowerLeg_Transform->Identity();
		stickModel_rightFoot_Transform->Identity();

		stickModel_leftLegJoint_Transform->Identity();
		stickModel_leftUpperLeg_Transform->Identity();
		stickModel_leftKnee_Transform->Identity();
		stickModel_leftLowerLeg_Transform->Identity();
		stickModel_leftFoot_Transform->Identity();

		RUA_JS_Transform->Identity();
		RLA_JS_Transform->Identity();
		LUA_JS_Transform->Identity();
		LLA_JS_Transform->Identity();
		RUL_JS_Transform->Identity();
		RLL_JS_Transform->Identity();
		LUL_JS_Transform->Identity();
		LLL_JS_Transform->Identity();

		mRenderer->RemoveActor(none_xaxis_actor);
		mRenderer->RemoveActor(none_yaxis_actor);
		mRenderer->RemoveActor(none_zaxis_actor);


		mRenderer->RemoveActor(PlconeActor);
		mRenderer->RemoveActor(CUconeActor);
		mRenderer->RemoveActor(Head_objActor);

		mRenderer->RemoveActor(RarmActor);
		mRenderer->RemoveActor(RforearmActor);
		mRenderer->RemoveActor(RightHand_objActor);


		mRenderer->RemoveActor(LarmActor);
		mRenderer->RemoveActor(LforearmActor);
		mRenderer->RemoveActor(LeftHand_objActor);


		mRenderer->RemoveActor(RlulegActor);
		mRenderer->RemoveActor(RllegActor);
		mRenderer->RemoveActor(RF_objActor);

		mRenderer->RemoveActor(LlulegActor);
		mRenderer->RemoveActor(LllegActor);
		mRenderer->RemoveActor(LF_objActor);

		mRenderer->RemoveActor(pelvisJS_actor);
		mRenderer->RemoveActor(chestJS_actor);
		mRenderer->RemoveActor(LUA_JS_actor);
		mRenderer->RemoveActor(LLA_JS_actor);
		mRenderer->RemoveActor(RUA_JS_actor);
		mRenderer->RemoveActor(RLA_JS_actor);
		mRenderer->RemoveActor(LUL_JS_actor);
		mRenderer->RemoveActor(LLL_JS_actor);
		mRenderer->RemoveActor(RUL_JS_actor);
		mRenderer->RemoveActor(RLL_JS_actor);

		displayStick_Model();
		mRenderWindow->Render();
	}

}
void MainWindow::viewing()
{
	vtkSmartPointer<vtkInteractorStyleTrackballCamera> style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New(); //like paravie
	mInteractor->SetInteractorStyle(style);
}

void MainWindow::enableFixedFoots()
{
	cout << "Fixed Foot with End Effectors IK Enabled" << endl;
	if (skeleton_biped == 1)
	{
		ffIK_both = 1;
		ffIK_RF = 0;
		ffIK_LF = 0;

		mRenderer->RemoveActor(stickModel_pelvisActor);
		mRenderer->RemoveActor(stickModel_chest_0_Actor);
		mRenderer->RemoveActor(stickModel_chest_1_Actor);
		mRenderer->RemoveActor(stickModel_chest_2_Actor);
		mRenderer->RemoveActor(stickModel_chest_3_Actor);
		mRenderer->RemoveActor(stickModel_head_Actor);
		mRenderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
		mRenderer->RemoveActor(stickModel_rightUpperArm_Actor);
		mRenderer->RemoveActor(stickModel_rightElbow_Actor);
		mRenderer->RemoveActor(stickModel_rightLowerArm_Actor);
		mRenderer->RemoveActor(stickModel_rightHand_Actor);
		mRenderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
		mRenderer->RemoveActor(stickModel_leftUpperArm_Actor);
		mRenderer->RemoveActor(stickModel_leftElbow_Actor);
		mRenderer->RemoveActor(stickModel_leftLowerArm_Actor);
		mRenderer->RemoveActor(stickModel_leftHand_Actor);
		mRenderer->RemoveActor(stickModel_rightLegJoint_Actor);
		mRenderer->RemoveActor(stickModel_rightUpperLeg_Actor);
		mRenderer->RemoveActor(stickModel_rightKnee_Actor);
		mRenderer->RemoveActor(stickModel_rightLowerLeg_Actor);
		mRenderer->RemoveActor(stickModel_rightFoot_Actor);
		mRenderer->RemoveActor(stickModel_leftLegJoint_Actor);
		mRenderer->RemoveActor(stickModel_leftUpperLeg_Actor);
		mRenderer->RemoveActor(stickModel_leftKnee_Actor);
		mRenderer->RemoveActor(stickModel_leftLowerLeg_Actor);
		mRenderer->RemoveActor(stickModel_leftFoot_Actor);

		IKflag_Status = 0;
		mRenderer->RemoveActor(rh_outlineActor);
		rhIK_flag = 0;
		mRenderer->RemoveActor(lh_outlineActor);
		lhIK_flag = 0;
		mRenderer->RemoveActor(rf_outlineActor);
		rfIK_flag = 0;
		mRenderer->RemoveActor(lf_outlineActor);
		lfIK_flag = 0;


		mRenderer->RemoveActor(IK_freeLeftFoot_Actor);
		mRenderer->RemoveActor(IK_freeLeftLowerLeg_Actor);
		mRenderer->RemoveActor(IK_freeLeftKnee_Actor);
		mRenderer->RemoveActor(IK_freeLeftUpperLeg_Actor);
		mRenderer->RemoveActor(IK_freeLeftLegJoint_Actor);

		mRenderer->RemoveActor(IK_freeRightFoot_Actor);
		mRenderer->RemoveActor(IK_freeRightLowerLeg_Actor);
		mRenderer->RemoveActor(IK_freeRightKnee_Actor);
		mRenderer->RemoveActor(IK_freeRightUpperLeg_Actor);
		mRenderer->RemoveActor(IK_freeRightLegJoint_Actor);

		IK_rightFoot_Transform->Identity();
		ffIK_rf_outlineTransform->Identity();
		IK_rightLowerLeg_Transform->Identity();
		IK_rightKnee_Transform->Identity();
		IK_rightUpperLeg_Transform->Identity();
		IK_rightLegJoint_Transform->Identity();

		IK_pelvisTransform->Identity();

		IK_leftFoot_Transform->Identity();
		ffIK_lf_outlineTransform->Identity();
		IK_leftLowerLeg_Transform->Identity();
		IK_leftKnee_Transform->Identity();
		IK_leftUpperLeg_Transform->Identity();
		IK_leftLegJoint_Transform->Identity();

		IK_chest_0_Transform->Identity();
		IK_chest_1_Transform->Identity();
		IK_chest_2_Transform->Identity();
		IK_chest_3_Transform->Identity();
		IK_head_Transform->Identity();

		IK_rightShoulderJoint_Transform->Identity();
		IK_rightUpperArm_Transform->Identity();
		IK_rightElbow_Transform->Identity();
		IK_rightLowerArm_Transform->Identity();
		IK_rightHand_Transform->Identity();

		IK_leftShoulderJoint_Transform->Identity();
		IK_leftUpperArm_Transform->Identity();
		IK_leftElbow_Transform->Identity();
		IK_leftLowerArm_Transform->Identity();
		IK_leftHand_Transform->Identity();



		displayFixedFoots_Model();
		mRenderWindow->Render();

	}

}

void MainWindow::authoring_mode()
{
	targetLinePoints = vtkSmartPointer<vtkPoints>::New();

	std::cout << "Authoring Mode Enabled " << endl;
	customMouseInteractorStyle* style = new customMouseInteractorStyle();

	
	mInteractor->SetInteractorStyle(style);
	style->SetDefaultRenderer(mRenderer);
	style->pelvisActor = PlconeActor;
	style->headActor = Head_objActor;
	style->chestActor = CUconeActor;
	style->Upper_chestActor = CUconeActor_upper;
	style->RUA = RarmActor;
	style->RLA = RforearmActor;
	style->LUA = LarmActor;
	style->LLA = LforearmActor;
	style->RUL = RlulegActor;
	style->RLL = RllegActor;
	style->LUL = LlulegActor;
	style->LLL = LllegActor;
	style->LH_Actor = LeftHand_objActor;
	style->RH_Actor = RightHand_objActor;
	style->LL_Actor = LF_objActor;
	style->RL_Actor = RF_objActor;


	style->SM_pelvisActor = stickModel_pelvisActor;
	style->SM_CH0 = stickModel_chest_0_Actor;
	style->SM_CH1 = stickModel_chest_1_Actor;
	style->SM_CH2 = stickModel_chest_2_Actor;
	style->SM_CH3 = stickModel_chest_3_Actor;
	style->SM_headActor = stickModel_head_Actor;
	style->SM_RUA = stickModel_rightUpperArm_Actor;
	style->SM_RLA = stickModel_rightLowerArm_Actor;
	style->SM_RH_Actor = stickModel_rightHand_Actor;
	style->SM_LUA = stickModel_leftUpperArm_Actor;
	style->SM_LLA = stickModel_leftLowerArm_Actor;
	style->SM_LH_Actor = stickModel_leftHand_Actor;
	style->SM_RUL = stickModel_rightUpperLeg_Actor;
	style->SM_RLL = stickModel_rightLowerLeg_Actor;
	style->SM_RF_Actor = stickModel_rightFoot_Actor;
	style->SM_LUL = stickModel_leftUpperLeg_Actor;
	style->SM_LLL = stickModel_leftLowerLeg_Actor;
	style->SM_LF_Actor = stickModel_leftFoot_Actor;


	style->ffIK_pelvisActor = IK_pelvisActor;
	style->ffIK_CH0 = IK_chest_0_Actor;
	style->ffIK_CH1 = IK_chest_1_Actor;
	style->ffIK_CH2 = IK_chest_2_Actor;
	style->ffIK_CH3 = IK_chest_3_Actor;
	style->ffIK_headActor = IK_head_Actor;;
	style->ffIK_RUA = IK_rightUpperArm_Actor;
	style->ffIK_RLA = IK_rightLowerArm_Actor;
	style->ffIK_RH = IK_rightHand_Actor;
	style->ffIK_LUA = IK_leftUpperArm_Actor;
	style->ffIK_LLA = IK_leftLowerArm_Actor;
	style->ffIK_LH = IK_leftHand_Actor;
	style->ffIK_RUL = IK_rightUpperLeg_Actor;
	style->ffIK_RLL = IK_rightLowerLeg_Actor;
	style->ffIK_RF_Actor = IK_rightFoot_Actor;
	style->ffIK_LUL = IK_leftUpperLeg_Actor;
	style->ffIK_LLL = IK_leftLowerLeg_Actor;
	style->ffIK_LF_Actor = IK_leftFoot_Actor;

	style->freeRightUL_Actor = IK_freeRightUpperLeg_Actor;
	style->freeRightLL_Actor = IK_freeRightLowerLeg_Actor;
	style->freeRightFoot_Actor = IK_freeRightFoot_Actor;

	style->freeLeftUL_Actor = IK_freeLeftUpperLeg_Actor;
	style->freeLeftLL_Actor = IK_freeLeftLowerLeg_Actor;
	style->freeLeftFoot_Actor = IK_freeLeftFoot_Actor;


	style->ConsProp_sphere_actor = ConstraintProp_sphere_actor;
	style->TConsProp_sphere_actor = TConstraintProp_sphere_actor;
	style->TConsProp_sphere_actor2 = TConstraintProp_sphere_actor2;
	style->TConsProp_sphere_actor3 = TConstraintProp_sphere_actor3;

	style->ConsProp_line_actor = ConstraintProp_line_actor1;
	style->TConsProp_line_actor = TConstraintProp_line_actor1;
	style->TConsProp_line_actor2 = TConstraintProp_line_actor2;
	style->TConsProp_line_actor3 = TConstraintProp_line_actor3;

	style->ConsProp_plane_actor = ConstraintProp_plane_actor;
	style->ConsProp_cube_actor = ConstraintProp_cube_actor;
	style->tartget = targetActor;

	mInteractor->SetInteractorStyle(style);
	mInteractor->Start();
}
void MainWindow::addPose()
{

	std::cout <<"rua_angleY " << rua_angleY << std::endl;
	JointMove temp;
	temp.chest[0] = chest_angleX;
	temp.chest[1] = chest_angleY;
	temp.chest[2] = chest_angleZ;

	temp.lla[0] = lla_angleX;
	temp.lla[1] = lla_angleY;
	temp.lla[2] = lla_angleZ;

	temp.lll[0] = lll_angleX;
	temp.lll[1] = lll_angleY;
	temp.lll[2] = lll_angleZ;

	temp.lua[0] = lua_angleX;
	temp.lua[1] = lua_angleY;
	temp.lua[2] = lua_angleZ;

	temp.lul[0] = lul_angleX;
	temp.lul[1] = lul_angleY;
	temp.lul[2] = lul_angleZ;

	temp.rla[0] = rla_angleX;
	temp.rla[1] = rla_angleY;
	temp.rla[2] = rla_angleZ;

	temp.rll[0] = rll_angleX;
	temp.rll[1] = rll_angleY;
	temp.rll[2] = rll_angleZ;

	temp.rua[0] = rua_angleX;
	temp.rua[1] = rua_angleY;
	temp.rua[2] = rua_angleZ;

	temp.rul[0] = rul_angleX;
	temp.rul[1] = rul_angleY;
	temp.rul[2] = rul_angleZ;


	string currentName = "pose";
	currentName += to_string(savedPoses.size());

	ui->listWidget->addItem(currentName.c_str());
	std::cout << chest_angleX << std::endl;
	std::cout << chest_angleY << std::endl;
	std::cout << chest_angleZ << std::endl;

	savedPoses.push_back(temp);

}
void MainWindow::selectList()
{
	std::cout << ui->listWidget->currentRow() << std::endl;

	int selectidx = ui->listWidget->currentRow();


	std::cout << savedPoses[selectidx].chest[0] << std::endl;
	std::cout << savedPoses[selectidx].chest[1] << std::endl;
	std::cout << savedPoses[selectidx].chest[2] << std::endl;



	male_biped = 1;
	vitruvian_biped = 0;
	skeleton_biped = 0;
	cout << "Male Biped Selected" << endl;

	Pelvis_objFilename = "../BodyGestureGenerator/data/Pelvis.obj";
	Chest_objFilename = "../BodyGestureGenerator/data/Chest.obj";
	headNeck_objFilename = "../BodyGestureGenerator/data/humanHead1.obj";
	LUA_objFilename = "../BodyGestureGenerator/data/LUA.obj";
	LLA_objFilename = "../BodyGestureGenerator/data/LLA.obj";
	LH_objFilename = "../BodyGestureGenerator/data/LH_G.obj";
	RUA_objFilename = "../BodyGestureGenerator/data/RUA.obj";
	RLA_objFilename = "../BodyGestureGenerator/data/RLA.obj";
	RH_objFilename = "../BodyGestureGenerator/data/RH_G.obj";
	LUL_objFilename = "../BodyGestureGenerator/data/LUL.obj";
	LLL_objFilename = "../BodyGestureGenerator/data/LLL.obj";
	LF_objFilename = "../BodyGestureGenerator/data/LF.obj";
	RUL_objFilename = "../BodyGestureGenerator/data/RUL.obj";
	RLL_objFilename = "../BodyGestureGenerator/data/RLL.obj";
	RF_objFilename = "../BodyGestureGenerator/data/RF.obj";

	PlconeTransform->Identity();
	CUconeTransform->Identity();
	Head_ObjReader_Transform->Identity();
	RarmTransform->Identity();
	RforearmTransform->Identity();
	RightHand_ObjReader_Transform->Identity();
	LarmTransform->Identity();
	LforearmTransform->Identity();
	LeftHand_ObjReader_Transform->Identity();
	RlulegTransform->Identity();
	RllegTransform->Identity();
	RF_ObjReader_Transform->Identity();
	LlulegTransform->Identity();
	LllegTransform->Identity();
	LF_ObjReader_Transform->Identity();

	RUA_JS_Transform->Identity();
	RLA_JS_Transform->Identity();
	LUA_JS_Transform->Identity();
	LLA_JS_Transform->Identity();
	RUL_JS_Transform->Identity();
	RLL_JS_Transform->Identity();
	LUL_JS_Transform->Identity();
	LLL_JS_Transform->Identity();

	pelvisObj_xpos = 0;
	pelvisObj_ypos = 47.875;
	pelvisObj_zpos = 0;
	pelvisObj_scale = 50;

	chestObj_xpos = 0;
	chestObj_ypos = 2.5;
	chestObj_zpos = 0;
	chestObj_scale = 50;

	head_NeckObj_xpos = 0;
	head_NeckObj_ypos = 26.0;
	head_NeckObj_zpos = -1.0;
	head_NeckObj_scale = 8;


	ruaObj_xpos = -10.5;
	ruaObj_ypos = 20.0;
	ruaObj_zpos = -2.5;
	ruaObj_scale = 50;

	rlaObj_xpos = 0.0;
	rlaObj_ypos = -14.0;
	rlaObj_zpos = 1.0;
	rlaObj_scale = 50;

	RHObj_xpos = -0.5;
	RHObj_ypos = -12.75;
	RHObj_zpos = 0.5;
	RHObj_scale = 40;

	luaObj_xpos = 10.50;
	luaObj_ypos = 20.0;
	luaObj_zpos = -2.5;
	luaObj_scale = 50;

	llaObj_xpos = 0.5;
	llaObj_ypos = -14.0;
	llaObj_zpos = 0.5;
	llaObj_scale = 50;

	LHObj_xpos = -0.5;
	LHObj_ypos = -12.75;
	LHObj_zpos = 0.5;
	LHObj_scale = 40;


	rulObj_xpos = -3.40;
	rulObj_ypos = 0; //-2.125
	rulObj_zpos = 0.0;
	rulObj_scale = 50;

	rllObj_xpos = -0.25;
	rllObj_ypos = -21.0;
	rllObj_zpos = 0.0;
	rllObj_scale = 50;

	RFObj_xpos = 0.7;
	RFObj_ypos = -19.25;
	RFObj_zpos = -2.10;
	RFObj_scale = 50;
	RF_xaxis_actor_Zpos = 20;

	lulObj_xpos = 3.90;
	lulObj_ypos = 0; //-2.125
	lulObj_zpos = 0.0;
	lulObj_scale = 50;

	lllObj_xpos = 1.0;
	lllObj_ypos = -21.0;
	lllObj_zpos = -0.75;
	lllObj_scale = 50;

	LFObj_xpos = 0.0;
	LFObj_ypos = -19.25;
	LFObj_zpos = -2.10;
	LFObj_scale = 50;



	mRenderer->RemoveActor(stickModel_pelvisActor);

	mRenderer->RemoveActor(stickModel_chest_0_Actor);
	mRenderer->RemoveActor(stickModel_chest_1_Actor);
	mRenderer->RemoveActor(stickModel_chest_2_Actor);
	mRenderer->RemoveActor(stickModel_chest_3_Actor);

	mRenderer->RemoveActor(stickModel_head_Actor);

	mRenderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
	mRenderer->RemoveActor(stickModel_rightUpperArm_Actor);
	mRenderer->RemoveActor(stickModel_rightElbow_Actor);
	mRenderer->RemoveActor(stickModel_rightLowerArm_Actor);
	mRenderer->RemoveActor(stickModel_rightHand_Actor);

	mRenderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
	mRenderer->RemoveActor(stickModel_leftUpperArm_Actor);
	mRenderer->RemoveActor(stickModel_leftElbow_Actor);
	mRenderer->RemoveActor(stickModel_leftLowerArm_Actor);
	mRenderer->RemoveActor(stickModel_leftHand_Actor);

	mRenderer->RemoveActor(stickModel_rightLegJoint_Actor);
	mRenderer->RemoveActor(stickModel_rightUpperLeg_Actor);
	mRenderer->RemoveActor(stickModel_rightKnee_Actor);
	mRenderer->RemoveActor(stickModel_rightLowerLeg_Actor);
	mRenderer->RemoveActor(stickModel_rightFoot_Actor);

	mRenderer->RemoveActor(stickModel_leftLegJoint_Actor);
	mRenderer->RemoveActor(stickModel_leftUpperLeg_Actor);
	mRenderer->RemoveActor(stickModel_leftKnee_Actor);
	mRenderer->RemoveActor(stickModel_leftLowerLeg_Actor);
	mRenderer->RemoveActor(stickModel_leftFoot_Actor);

	mRenderer->RemoveActor(none_xaxis_actor);
	mRenderer->RemoveActor(none_yaxis_actor);
	mRenderer->RemoveActor(none_zaxis_actor);

	mRenderer->RemoveActor(rh_outlineActor);
	rhIK_flag = 0;
	mRenderer->RemoveActor(lh_outlineActor);
	lhIK_flag = 0;
	mRenderer->RemoveActor(rf_outlineActor);
	rfIK_flag = 0;
	mRenderer->RemoveActor(lf_outlineActor);
	lfIK_flag = 0;

	mRenderer->RemoveActor(pelvisJS_actor);
	mRenderer->RemoveActor(chestJS_actor);
	mRenderer->RemoveActor(LUA_JS_actor);
	mRenderer->RemoveActor(LLA_JS_actor);
	mRenderer->RemoveActor(RUA_JS_actor);
	mRenderer->RemoveActor(RLA_JS_actor);
	mRenderer->RemoveActor(LUL_JS_actor);
	mRenderer->RemoveActor(LLL_JS_actor);
	mRenderer->RemoveActor(RUL_JS_actor);
	mRenderer->RemoveActor(RLL_JS_actor);


	if(selectidx == 3)
		displayRobot_Model(10);
	else
		displayRobot_Model(1);
	//jointSpheres();
	mRenderWindow->Render();


	customMouseInteractorStyle* style = new customMouseInteractorStyle();
	mInteractor->SetInteractorStyle(style);
	style->SetDefaultRenderer(mRenderer);
	style->pelvisActor = PlconeActor;
	style->headActor = Head_objActor;
	style->chestActor = CUconeActor;
	style->Upper_chestActor = CUconeActor_upper;
	style->RUA = RarmActor;
	style->RLA = RforearmActor;
	style->LUA = LarmActor;
	style->LLA = LforearmActor;
	style->RUL = RlulegActor;
	style->RLL = RllegActor;
	style->LUL = LlulegActor;
	style->LLL = LllegActor;
	style->LH_Actor = LeftHand_objActor;
	style->RH_Actor = RightHand_objActor;
	style->LL_Actor = LF_objActor;
	style->RL_Actor = RF_objActor;


	style->SM_pelvisActor = stickModel_pelvisActor;
	style->SM_CH0 = stickModel_chest_0_Actor;
	style->SM_CH1 = stickModel_chest_1_Actor;
	style->SM_CH2 = stickModel_chest_2_Actor;
	style->SM_CH3 = stickModel_chest_3_Actor;
	style->SM_headActor = stickModel_head_Actor;
	style->SM_RUA = stickModel_rightUpperArm_Actor;
	style->SM_RLA = stickModel_rightLowerArm_Actor;
	style->SM_RH_Actor = stickModel_rightHand_Actor;
	style->SM_LUA = stickModel_leftUpperArm_Actor;
	style->SM_LLA = stickModel_leftLowerArm_Actor;
	style->SM_LH_Actor = stickModel_leftHand_Actor;
	style->SM_RUL = stickModel_rightUpperLeg_Actor;
	style->SM_RLL = stickModel_rightLowerLeg_Actor;
	style->SM_RF_Actor = stickModel_rightFoot_Actor;
	style->SM_LUL = stickModel_leftUpperLeg_Actor;
	style->SM_LLL = stickModel_leftLowerLeg_Actor;
	style->SM_LF_Actor = stickModel_leftFoot_Actor;


	style->ffIK_pelvisActor = IK_pelvisActor;
	style->ffIK_CH0 = IK_chest_0_Actor;
	style->ffIK_CH1 = IK_chest_1_Actor;
	style->ffIK_CH2 = IK_chest_2_Actor;
	style->ffIK_CH3 = IK_chest_3_Actor;
	style->ffIK_headActor = IK_head_Actor;;
	style->ffIK_RUA = IK_rightUpperArm_Actor;
	style->ffIK_RLA = IK_rightLowerArm_Actor;
	style->ffIK_RH = IK_rightHand_Actor;
	style->ffIK_LUA = IK_leftUpperArm_Actor;
	style->ffIK_LLA = IK_leftLowerArm_Actor;
	style->ffIK_LH = IK_leftHand_Actor;
	style->ffIK_RUL = IK_rightUpperLeg_Actor;
	style->ffIK_RLL = IK_rightLowerLeg_Actor;
	style->ffIK_RF_Actor = IK_rightFoot_Actor;
	style->ffIK_LUL = IK_leftUpperLeg_Actor;
	style->ffIK_LLL = IK_leftLowerLeg_Actor;
	style->ffIK_LF_Actor = IK_leftFoot_Actor;

	style->freeRightUL_Actor = IK_freeRightUpperLeg_Actor;
	style->freeRightLL_Actor = IK_freeRightLowerLeg_Actor;
	style->freeRightFoot_Actor = IK_freeRightFoot_Actor;

	style->freeLeftUL_Actor = IK_freeLeftUpperLeg_Actor;
	style->freeLeftLL_Actor = IK_freeLeftLowerLeg_Actor;
	style->freeLeftFoot_Actor = IK_freeLeftFoot_Actor;


	style->ConsProp_sphere_actor = ConstraintProp_sphere_actor;
	style->TConsProp_sphere_actor = TConstraintProp_sphere_actor;
	style->TConsProp_sphere_actor2 = TConstraintProp_sphere_actor2;
	style->TConsProp_sphere_actor3 = TConstraintProp_sphere_actor3;

	//style->ConsProp_line_actor = ConstraintProp_line_actor;
	style->ConsProp_line_actor = ConstraintProp_line_actor1;
	style->TConsProp_line_actor = TConstraintProp_line_actor1;
	style->TConsProp_line_actor2 = TConstraintProp_line_actor2;
	style->TConsProp_line_actor3 = TConstraintProp_line_actor3;

	style->ConsProp_plane_actor = ConstraintProp_plane_actor;
	style->ConsProp_cube_actor = ConstraintProp_cube_actor;

	mInteractor->SetInteractorStyle(style);
	mInteractor->SetRenderWindow(mRenderWindow);

	vtkNew<vtkTimerCallback_Animation> cb;
	cb->currentMove = savedPoses[selectidx];
	cb->poses.clear();
	cb->poses.assign(savedPoses.begin(), savedPoses.end());
	cb->currntIdx = selectidx;

	mInteractor->RemoveAllObservers();
	mInteractor->AddObserver(vtkCommand::TimerEvent, cb);
	
	cb->frameCnt = 50;
	int timerId = mInteractor->CreateRepeatingTimer(cb->frameCnt);
	cb->timerId = timerId;
	
	mInteractor->Start();

	
	
}
void MainWindow::saveImage()
{
	std::cout << "saveImage" << std::endl;

	time_t now = time(0);

	string savedName = "Frame/";
	savedName += std::to_string(now);
	savedName += ".png";

	vtkNew<vtkWindowToImageFilter> windowToImageFilter;
	windowToImageFilter->SetInput(mRenderer->GetRenderWindow());
#if VTK_MAJOR_VERSION >= 8 || VTK_MAJOR_VERSION == 8 && VTK_MINOR_VERSION >= 90
	windowToImageFilter->SetScale(2); // image quality
#else
	windowToImageFilter->SetMagnification(2); // image quality
#endif
	windowToImageFilter->SetInputBufferTypeToRGBA(); // also record the alpha
													 // (transparency) channel
	windowToImageFilter->ReadFrontBufferOff();       // read from the back buffer
	windowToImageFilter->Update();

	vtkNew<vtkPNGWriter> writer;
	writer->SetFileName(savedName.c_str());
	writer->SetInputConnection(windowToImageFilter->GetOutputPort());
	writer->Write();
	

}

void MainWindow::drawTrajectory()
{
	std::cout << "drawTrajectory" << std::endl;
	colorSetting(1, "Gray");
}

void MainWindow::onDrawSphereClick() {

	std::cout << "button Clicked" << std::endl;
	male_biped = 1;
	vitruvian_biped = 0;
	skeleton_biped = 0;
	cout << "Male Biped Selected" << endl;

	Pelvis_objFilename = "../BodyGestureGenerator/data/Pelvis.obj";
	Chest_objFilename = "../BodyGestureGenerator/data/Chest.obj";
	headNeck_objFilename = "../BodyGestureGenerator/data/humanHead1.obj";
	LUA_objFilename = "../BodyGestureGenerator/data/LUA.obj";
	LLA_objFilename = "../BodyGestureGenerator/data/LLA.obj";
	LH_objFilename = "../BodyGestureGenerator/data/LH_G.obj";
	RUA_objFilename = "../BodyGestureGenerator/data/RUA.obj";
	RLA_objFilename = "../BodyGestureGenerator/data/RLA.obj";
	RH_objFilename = "../BodyGestureGenerator/data/RH_G.obj";
	LUL_objFilename = "../BodyGestureGenerator/data/LUL.obj";
	LLL_objFilename = "../BodyGestureGenerator/data/LLL.obj";
	LF_objFilename = "../BodyGestureGenerator/data/LF.obj";
	RUL_objFilename = "../BodyGestureGenerator/data/RUL.obj";
	RLL_objFilename = "../BodyGestureGenerator/data/RLL.obj";
	RF_objFilename = "../BodyGestureGenerator/data/RF.obj";

	PlconeTransform->Identity();
	CUconeTransform->Identity();
	Head_ObjReader_Transform->Identity();
	RarmTransform->Identity();
	RforearmTransform->Identity();
	RightHand_ObjReader_Transform->Identity();
	LarmTransform->Identity();
	LforearmTransform->Identity();
	LeftHand_ObjReader_Transform->Identity();
	RlulegTransform->Identity();
	RllegTransform->Identity();
	RF_ObjReader_Transform->Identity();
	LlulegTransform->Identity();
	LllegTransform->Identity();
	LF_ObjReader_Transform->Identity();

	RUA_JS_Transform->Identity();
	RLA_JS_Transform->Identity();
	LUA_JS_Transform->Identity();
	LLA_JS_Transform->Identity();
	RUL_JS_Transform->Identity();
	RLL_JS_Transform->Identity();
	LUL_JS_Transform->Identity();
	LLL_JS_Transform->Identity();

	pelvisObj_xpos = 0;
	pelvisObj_ypos = 47.875;
	pelvisObj_zpos = 0;
	pelvisObj_scale = 50;

	chestObj_xpos = 0;
	chestObj_ypos = 2.5;
	chestObj_zpos = 0;
	chestObj_scale = 50;

	head_NeckObj_xpos = 0;
	head_NeckObj_ypos = 26.0;
	head_NeckObj_zpos = -3.0;
	head_NeckObj_scale = 8;


	ruaObj_xpos = -10.5;
	ruaObj_ypos = 20.0;
	ruaObj_zpos = -2.5;
	ruaObj_scale = 50;

	rlaObj_xpos = 0.0;
	rlaObj_ypos = -14.0;
	rlaObj_zpos = 1.0;
	rlaObj_scale = 50;

	RHObj_xpos = -0.5;
	RHObj_ypos = -12.75;
	RHObj_zpos = 0.5;
	RHObj_scale = 40;

	luaObj_xpos = 10.50;
	luaObj_ypos = 20.0;
	luaObj_zpos = -2.5;
	luaObj_scale = 50;

	llaObj_xpos = 0.5;
	llaObj_ypos = -14.0;
	llaObj_zpos = 0.5;
	llaObj_scale = 50;

	LHObj_xpos = -0.5;
	LHObj_ypos = -12.75;
	LHObj_zpos = 0.5;
	LHObj_scale = 40;


	rulObj_xpos = -3.40;
	rulObj_ypos = 0; //-2.125
	rulObj_zpos = 0.0;
	rulObj_scale = 50;

	rllObj_xpos = -0.25;
	rllObj_ypos = -21.0;
	rllObj_zpos = 0.0;
	rllObj_scale = 50;

	RFObj_xpos = 0.7;
	RFObj_ypos = -19.25;
	RFObj_zpos = -2.10;
	RFObj_scale = 50;
	RF_xaxis_actor_Zpos = 20;

	lulObj_xpos = 3.90;
	lulObj_ypos = 0; //-2.125
	lulObj_zpos = 0.0;
	lulObj_scale = 50;

	lllObj_xpos = 1.0;
	lllObj_ypos = -21.0;
	lllObj_zpos = -0.75;
	lllObj_scale = 50;

	LFObj_xpos = 0.0;
	LFObj_ypos = -19.25;
	LFObj_zpos = -2.10;
	LFObj_scale = 50;



	displayRobot_Model(1);

	mRenderer->ResetCamera();
	mRenderWindow->Render();

	vtkNew<customMouseInteractorStyle> style;
	renderWindowInteractor->SetInteractorStyle(style);
	renderWindowInteractor->Start();


}


void calculate3Angle(int p1, int p2, int p3)
{
	/**********************************************************/
	male_biped = 1;
	vitruvian_biped = 0;
	skeleton_biped = 0;
	cout << "Male Biped Selected" << endl;

	Pelvis_objFilename = "../BodyGestureGenerator/data/Pelvis.obj";
	Chest_objFilename = "../BodyGestureGenerator/data/Chest.obj";
	headNeck_objFilename = "../BodyGestureGenerator/data/humanHead1.obj";
	LUA_objFilename = "../BodyGestureGenerator/data/LUA.obj";
	LLA_objFilename = "../BodyGestureGenerator/data/LLA.obj";
	LH_objFilename = "../BodyGestureGenerator/data/LH_G.obj";
	RUA_objFilename = "../BodyGestureGenerator/data/RUA.obj";
	RLA_objFilename = "../BodyGestureGenerator/data/RLA.obj";
	RH_objFilename = "../BodyGestureGenerator/data/RH_G.obj";
	LUL_objFilename = "../BodyGestureGenerator/data/LUL.obj";
	LLL_objFilename = "../BodyGestureGenerator/data/LLL.obj";
	LF_objFilename = "../BodyGestureGenerator/data/LF.obj";
	RUL_objFilename = "../BodyGestureGenerator/data/RUL.obj";
	RLL_objFilename = "../BodyGestureGenerator/data/RLL.obj";
	RF_objFilename = "../BodyGestureGenerator/data/RF.obj";

	PlconeTransform->Identity();
	CUconeTransform->Identity();
	Head_ObjReader_Transform->Identity();
	RarmTransform->Identity();
	RforearmTransform->Identity();
	RightHand_ObjReader_Transform->Identity();
	LarmTransform->Identity();
	LforearmTransform->Identity();
	LeftHand_ObjReader_Transform->Identity();
	RlulegTransform->Identity();
	RllegTransform->Identity();
	RF_ObjReader_Transform->Identity();
	LlulegTransform->Identity();
	LllegTransform->Identity();
	LF_ObjReader_Transform->Identity();

	RUA_JS_Transform->Identity();
	RLA_JS_Transform->Identity();
	LUA_JS_Transform->Identity();
	LLA_JS_Transform->Identity();
	RUL_JS_Transform->Identity();
	RLL_JS_Transform->Identity();
	LUL_JS_Transform->Identity();
	LLL_JS_Transform->Identity();

	pelvisObj_xpos = 0;
	pelvisObj_ypos = 47.875;
	pelvisObj_zpos = 0;
	pelvisObj_scale = 50;

	chestObj_xpos = 0;
	chestObj_ypos = 2.5;
	chestObj_zpos = 0;
	chestObj_scale = 50;

	head_NeckObj_xpos = 0;
	head_NeckObj_ypos = 26.0;
	head_NeckObj_zpos = -1.0;
	head_NeckObj_scale = 8;


	ruaObj_xpos = -10.5;
	ruaObj_ypos = 20.0;
	ruaObj_zpos = -2.5;
	ruaObj_scale = 50;

	rlaObj_xpos = 0.0;
	rlaObj_ypos = -14.0;
	rlaObj_zpos = 1.0;
	rlaObj_scale = 50;

	RHObj_xpos = -0.5;
	RHObj_ypos = -12.75;
	RHObj_zpos = 0.5;
	RHObj_scale = 40;

	luaObj_xpos = 10.50;
	luaObj_ypos = 20.0;
	luaObj_zpos = -2.5;
	luaObj_scale = 50;

	llaObj_xpos = 0.5;
	llaObj_ypos = -14.0;
	llaObj_zpos = 0.5;
	llaObj_scale = 50;

	LHObj_xpos = -0.5;
	LHObj_ypos = -12.75;
	LHObj_zpos = 0.5;
	LHObj_scale = 40;


	rulObj_xpos = -3.40;
	rulObj_ypos = 0; //-2.125
	rulObj_zpos = 0.0;
	rulObj_scale = 50;

	rllObj_xpos = -0.25;
	rllObj_ypos = -21.0;
	rllObj_zpos = 0.0;
	rllObj_scale = 50;

	RFObj_xpos = 0.7;
	RFObj_ypos = -19.25;
	RFObj_zpos = -2.10;
	RFObj_scale = 50;
	RF_xaxis_actor_Zpos = 20;

	lulObj_xpos = 3.90;
	lulObj_ypos = 0; //-2.125
	lulObj_zpos = 0.0;
	lulObj_scale = 50;

	lllObj_xpos = 1.0;
	lllObj_ypos = -21.0;
	lllObj_zpos = -0.75;
	lllObj_scale = 50;

	LFObj_xpos = 0.0;
	LFObj_ypos = -19.25;
	LFObj_zpos = -2.10;
	LFObj_scale = 50;



	mRenderer->RemoveActor(stickModel_pelvisActor);

	mRenderer->RemoveActor(stickModel_chest_0_Actor);
	mRenderer->RemoveActor(stickModel_chest_1_Actor);
	mRenderer->RemoveActor(stickModel_chest_2_Actor);
	mRenderer->RemoveActor(stickModel_chest_3_Actor);

	mRenderer->RemoveActor(stickModel_head_Actor);

	mRenderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
	mRenderer->RemoveActor(stickModel_rightUpperArm_Actor);
	mRenderer->RemoveActor(stickModel_rightElbow_Actor);
	mRenderer->RemoveActor(stickModel_rightLowerArm_Actor);
	mRenderer->RemoveActor(stickModel_rightHand_Actor);

	mRenderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
	mRenderer->RemoveActor(stickModel_leftUpperArm_Actor);
	mRenderer->RemoveActor(stickModel_leftElbow_Actor);
	mRenderer->RemoveActor(stickModel_leftLowerArm_Actor);
	mRenderer->RemoveActor(stickModel_leftHand_Actor);

	mRenderer->RemoveActor(stickModel_rightLegJoint_Actor);
	mRenderer->RemoveActor(stickModel_rightUpperLeg_Actor);
	mRenderer->RemoveActor(stickModel_rightKnee_Actor);
	mRenderer->RemoveActor(stickModel_rightLowerLeg_Actor);
	mRenderer->RemoveActor(stickModel_rightFoot_Actor);

	mRenderer->RemoveActor(stickModel_leftLegJoint_Actor);
	mRenderer->RemoveActor(stickModel_leftUpperLeg_Actor);
	mRenderer->RemoveActor(stickModel_leftKnee_Actor);
	mRenderer->RemoveActor(stickModel_leftLowerLeg_Actor);
	mRenderer->RemoveActor(stickModel_leftFoot_Actor);

	mRenderer->RemoveActor(none_xaxis_actor);
	mRenderer->RemoveActor(none_yaxis_actor);
	mRenderer->RemoveActor(none_zaxis_actor);

	mRenderer->RemoveActor(rh_outlineActor);
	rhIK_flag = 0;
	mRenderer->RemoveActor(lh_outlineActor);
	lhIK_flag = 0;
	mRenderer->RemoveActor(rf_outlineActor);
	rfIK_flag = 0;
	mRenderer->RemoveActor(lf_outlineActor);
	lfIK_flag = 0;

	mRenderer->RemoveActor(pelvisJS_actor);
	mRenderer->RemoveActor(chestJS_actor);
	mRenderer->RemoveActor(LUA_JS_actor);
	mRenderer->RemoveActor(LLA_JS_actor);
	mRenderer->RemoveActor(RUA_JS_actor);
	mRenderer->RemoveActor(RLA_JS_actor);
	mRenderer->RemoveActor(LUL_JS_actor);
	mRenderer->RemoveActor(LLL_JS_actor);
	mRenderer->RemoveActor(RUL_JS_actor);
	mRenderer->RemoveActor(RLL_JS_actor);
	mRenderer->RemoveActor(targetActor);
	mRenderer->RemoveActor(sphere2Actor);
	
	robotModel(1);

	mRenderWindow->Render();

	rhIK_solvePosAngle2 = true;

	double angle_z = 0;
	angle_z = atan((double)((double)p3 / (double)p1)) * 180 / PI;


	inverseKinematices_Theta_0 = angle_z;
	computeSM_ikRH(p1, p2, -1, 0, 0, 10);

	if(b_draw_endPose)
		rua(angle_z, 0, 0, 1);

	double position[3] = { 0,0,0 };
	RightHand_ObjReader_Transform->GetPosition(position);
	targetLinePoints->InsertNextPoint(position);
	//std::cout << position[0] << "   " << position[1] << "   " << position[2] << std::endl;

	//std::cout << "XYZ : " << getTheta << "  " << getPhi << "  " << getZ << std::endl;

	targetTransform->SetInput(RightHand_ObjReader_Transform);
	mRenderer->Render();
	mRenderWindow->Render();
}

void MainWindow::drawThetaPhi()
{

	QString q_theta = ui->edit_theta->text();
	QString q_phi = ui->edit_phi->text();
	QString q_z = ui->edit_z->text();

	int getTheta = 0;
	int getPhi = 0;
	int getZ = 0;


	if (q_theta.toStdString().size() > 0)
		getTheta = stoi(q_theta.toStdString());


	if (q_phi.toStdString().size() > 0)
		getPhi = stoi(q_phi.toStdString());

	if (q_z.toStdString().size() > 0)
		getZ = stoi(q_z.toStdString());

	calculate3Angle(getTheta, getPhi, getZ);

}


void MainWindow::selectTarget()
{
	int selectidx = ui->listWidget_2->currentRow();

	if (selectidx >= 0)
	{
		std::cout <<" targetPoint    " << savedTarget[selectidx].pos_x << "  " << savedTarget[selectidx].pos_y << "   " << savedTarget[selectidx].pos_z << std::endl;

		ui->edit_theta->setText(to_string(savedTarget[selectidx].pos_x).c_str());
		ui->edit_phi->setText(to_string(savedTarget[selectidx].pos_y).c_str());
		ui->edit_z->setText(to_string(savedTarget[selectidx].pos_z).c_str());

	}

	drawThetaPhi();

}
void MainWindow::targetAdd()
{
	QString q_theta = ui->edit_theta->text();
	QString q_phi = ui->edit_phi->text();
	QString q_z = ui->edit_z->text();

	int getTheta = 0;
	int getPhi = 0;
	int getZ = 0;


	if (q_theta.toStdString().size() > 0)
		getTheta = stoi(q_theta.toStdString());


	if (q_phi.toStdString().size() > 0)
		getPhi = stoi(q_phi.toStdString());

	if (q_z.toStdString().size() > 0)
		getZ = stoi(q_z.toStdString());


	targetPoint temp;
	temp.pos_x = getTheta;
	temp.pos_y = getPhi;
	temp.pos_z = getZ;


	string currentName = "targetPoint ";
	currentName += to_string(savedTarget.size());

	ui->listWidget_2->addItem(currentName.c_str());

	savedTarget.push_back(temp);

}


void MainWindow::playTargets()
{
	//GestureInterface
	std::cout << "Play Targets" << std::endl;
	string savedName = "GestureInterface/";
	string savedName_csv = "GestureInterface/";
	wstring temp = L"";
	double prev_theta0 = 0;
	double prev_theta1 = 0;
	double prev_theta2 = 0;
	string strTemp = "";

	targetLinePoints = vtkSmartPointer<vtkPoints>::New();

	string strGestureTemp = "";
	std::vector<string> gestureStr;
	gestureStr.clear();

	for (int i = 0; i < savedTarget.size(); i++)
	{
		savedName = "GestureInterface/";
		savedName += "Posture";
		savedName += std::to_string(i);
		savedName += ".png";

		std::cout << " targetPoint    " << savedTarget[i].pos_x << "  " << savedTarget[i].pos_y << "   " << savedTarget[i].pos_z << std::endl;

		ui->edit_theta->setText(to_string(savedTarget[i].pos_x).c_str());
		ui->edit_phi->setText(to_string(savedTarget[i].pos_y).c_str());
		ui->edit_z->setText(to_string(savedTarget[i].pos_z).c_str());

		drawThetaPhi();
		mRenderer->Render();
		mRenderWindow->Render();


		vtkNew<vtkWindowToImageFilter> w2if;
		w2if->SetInput(mRenderWindow);
		w2if->SetInputBufferTypeToRGBA();
		w2if->Update();

		vtkNew<vtkPNGWriter> writer;
		writer->SetFileName(savedName.c_str());
		writer->SetInputConnection(w2if->GetOutputPort());
		writer->Write();

		std::cout << i << "   inverseKinematices_Theta 0 1 2 = " << inverseKinematices_Theta_0 << " , " << inverseKinematices_Theta_1 << " , " << inverseKinematices_Theta_2 << std::endl;


		if (i > 0)
		{

			strGestureTemp = "Gesture ";
			strGestureTemp += to_string(i);
			strGestureTemp += "\n\n";
			savedName_csv = "GestureInterface/";
			savedName_csv += "Gesture";
			savedName_csv += std::to_string(i);
			savedName_csv += ".csv";


			std::ofstream csvFile;
			csvFile.open(savedName_csv);
			csvFile.clear();
			

			if (inverseKinematices_Theta_0 > -22)
			{
				if (prev_theta1 < inverseKinematices_Theta_1)
				{
					//굽힘
					temp = L"Rs,Flexion,";
					temp += to_wstring(abs(inverseKinematices_Theta_1 - prev_theta1));
					temp += L"\n";
					strTemp = "";
					strTemp.assign(temp.begin(), temp.end());
					csvFile << strTemp;

					strGestureTemp += strTemp;
				}
				else
				{
					if (inverseKinematices_Theta_1 - prev_theta1 != 0)
					{
						//폄
						temp = L"Rs,Extension,";
						temp += to_wstring(abs(inverseKinematices_Theta_1 - prev_theta1));
						temp += L"\n";
						strTemp = "";
						strTemp.assign(temp.begin(), temp.end());
						csvFile << strTemp;

						strGestureTemp += strTemp;
					}


				}
			}
			else
			{
				if (prev_theta1 < inverseKinematices_Theta_1)
				{
					//벌림
					temp = L"Rs,Abduction,";
					temp += to_wstring(abs(inverseKinematices_Theta_1 - prev_theta1));
					temp += L"\n";
					strTemp = "";
					strTemp.assign(temp.begin(), temp.end());
					csvFile << strTemp;

					strGestureTemp += strTemp;
				}
				else
				{
					if (inverseKinematices_Theta_1 - prev_theta1 != 0)
					{
						//모음
						temp = L"Rs,Adduction,";
						temp += to_wstring(abs(inverseKinematices_Theta_1 - prev_theta1));
						temp += L"\n";
						strTemp = "";
						strTemp.assign(temp.begin(), temp.end());
						csvFile << strTemp;

						strGestureTemp += strTemp;
					}

				}
			}

			if (prev_theta0 < inverseKinematices_Theta_0)
			{
				//수평모음
				temp = L"Rs,Horizontal Adduction,";
				temp += to_wstring(abs(inverseKinematices_Theta_0 - prev_theta0));
				temp += L"\n";
				strTemp = "";
				strTemp.assign(temp.begin(), temp.end());
				csvFile << strTemp;

				strGestureTemp += strTemp;
			}
			else
			{
				if (inverseKinematices_Theta_0 - prev_theta0 != 0)
				{
					//수평벌림
					temp = L"Rs,Horizontal Abduction,";
					temp += to_wstring(abs(inverseKinematices_Theta_0 - prev_theta0));
					temp += L"\n";
					strTemp = "";
					strTemp.assign(temp.begin(), temp.end());
					csvFile << strTemp;

					strGestureTemp += strTemp;
				}
			}

			if (prev_theta2 < inverseKinematices_Theta_2)
			{
				//굽힘
				temp = L"Re,Flexion,";
				temp += to_wstring(abs(inverseKinematices_Theta_2 - prev_theta2));
				temp += L"\n";
				strTemp = "";
				strTemp.assign(temp.begin(), temp.end());
				csvFile << strTemp;

				strGestureTemp += strTemp;
			}
			else
			{
				if (inverseKinematices_Theta_2 - prev_theta2 != 0)
				{
					//폄
					temp = L"Re,Extension,";
					temp += to_wstring(abs(inverseKinematices_Theta_2 - prev_theta2));
					temp += L"\n";
					strTemp = "";
					strTemp.assign(temp.begin(), temp.end());
					csvFile << strTemp;

					strGestureTemp += strTemp;
				}
			}
			csvFile.close();

			if (strGestureTemp.size() > 0)
			{
				gestureStr.push_back(strGestureTemp);
			}

		}
		
		vtkNew<vtkActor> lineActor;
		if (i > 0)
		{
			vtkNew<vtkLineSource> lineSource;
			lineSource->SetPoint1(targetLinePoints->GetPoint(i - 1));
			lineSource->SetPoint2(targetLinePoints->GetPoint(i));

			vtkNew<vtkPolyDataMapper> lineMapper;
			lineMapper->SetInputConnection(lineSource->GetOutputPort());
			
			lineActor->SetMapper(lineMapper);
			lineActor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());
			lineActor->GetProperty()->SetLineWidth(2.5);


			mRenderer->AddActor(lineActor);
		}


		mRenderer->Render();
		mRenderWindow->Render();
		QApplication::processEvents();
		Sleep(1000);

		prev_theta0 = inverseKinematices_Theta_0;
		prev_theta1 = inverseKinematices_Theta_1;
		prev_theta2 = inverseKinematices_Theta_2;


		mRenderer->RemoveActor(lineActor);

	}

	for (int i = 0; i < savedTarget.size(); i++)
	{
		savedName = "GestureInterface/";
		savedName += "Posture";
		savedName += std::to_string(i);
		savedName += ".png";

		QPixmap m_img;
		m_img.load(savedName.c_str());

		int w = 200;
		int h = 50;


		if(i==0)
		{
			ui->lbl_posture0->setPixmap(m_img.scaled(w, h, Qt::KeepAspectRatioByExpanding));
			ui->lbl_name_0->setText("Posture0");

			ui->lbl_posture0->setFrameShape(QFrame::Box);
			ui->lbl_name_0->setFrameShape(QFrame::Box);
			
		}
			
		if (i == 1)
		{
			ui->lbl_posture1->setPixmap(m_img.scaled(w, h, Qt::KeepAspectRatioByExpanding));
			ui->lbl_name_1->setText("Posture1");
			ui->lbl_gesture1->setText(gestureStr[i-1].c_str());

			ui->lbl_posture1->setFrameShape(QFrame::Box);
			ui->lbl_name_1->setFrameShape(QFrame::Box);
			ui->lbl_gesture1->setFrameShape(QFrame::Box);
		}
			
		if (i == 2)
		{
			ui->lbl_posture2->setPixmap(m_img.scaled(w, h, Qt::KeepAspectRatioByExpanding));
			ui->lbl_name_2->setText("Posture2");
			ui->lbl_gesture2->setText(gestureStr[i-1].c_str());

			ui->lbl_posture2->setFrameShape(QFrame::Box);
			ui->lbl_name_2->setFrameShape(QFrame::Box);
			ui->lbl_gesture2->setFrameShape(QFrame::Box);
		}
			
		if (i == 3)
		{
			ui->lbl_posture3->setPixmap(m_img.scaled(w, h, Qt::KeepAspectRatioByExpanding));
			ui->lbl_name_3->setText("Posture3");
			ui->lbl_gesture3->setText(gestureStr[i-1].c_str());

			ui->lbl_posture3->setFrameShape(QFrame::Box);
			ui->lbl_name_3->setFrameShape(QFrame::Box);
			ui->lbl_gesture3->setFrameShape(QFrame::Box);
		}
			
		if (i == 4)
		{
			ui->lbl_posture4->setPixmap(m_img.scaled(w, h, Qt::KeepAspectRatioByExpanding));
			ui->lbl_name_4->setText("Posture4");
			ui->lbl_gesture4->setText(gestureStr[i-1].c_str());

			ui->lbl_posture4->setFrameShape(QFrame::Box);
			ui->lbl_name_4->setFrameShape(QFrame::Box);
			ui->lbl_gesture4->setFrameShape(QFrame::Box);
		}
			
		if (i == 5)
		{
			ui->lbl_posture5->setPixmap(m_img.scaled(w, h, Qt::KeepAspectRatioByExpanding));
			ui->lbl_name_5->setText("Posture5");
			ui->lbl_gesture5->setText(gestureStr[i-1].c_str());

			ui->lbl_posture5->setFrameShape(QFrame::Box);
			ui->lbl_name_5->setFrameShape(QFrame::Box);
			ui->lbl_gesture5->setFrameShape(QFrame::Box);
		}
			
		if (i == 6)
		{
			ui->lbl_posture6->setPixmap(m_img.scaled(w, h, Qt::KeepAspectRatioByExpanding));
			ui->lbl_name_6->setText("Posture6");
			ui->lbl_gesture6->setText(gestureStr[i-1].c_str());

			ui->lbl_posture6->setFrameShape(QFrame::Box);
			ui->lbl_name_6->setFrameShape(QFrame::Box);
			ui->lbl_gesture6->setFrameShape(QFrame::Box);
		}
		if (i == 7)
		{
			ui->lbl_posture7->setPixmap(m_img.scaled(w, h, Qt::KeepAspectRatioByExpanding));
			ui->lbl_name_7->setText("Posture7");
			ui->lbl_gesture7->setText(gestureStr[i - 1].c_str());

			ui->lbl_posture7->setFrameShape(QFrame::Box);
			ui->lbl_name_7->setFrameShape(QFrame::Box);
			ui->lbl_gesture7->setFrameShape(QFrame::Box);
		}
		
	}

	vtkNew<vtkCellArray> lines;
	vtkNew<vtkPolyData> linesPolyData;
	vtkNew<vtkPolyDataMapper> sphere2Mapper;
	sphere2Actor->RemoveAllObservers();
	lines->RemoveAllObservers();
	linesPolyData->RemoveAllObservers();
	sphere2Mapper->RemoveAllInputs();

	// Create four lines
	for (unsigned int i = 0; i < savedTarget.size()-1; i++)
	{
		vtkNew<vtkLine> line;
		line->GetPointIds()->SetId(0, i);
		line->GetPointIds()->SetId(1, i + 1);
		lines->InsertNextCell(line);
	}

	

	// Add the points to the dataset
	linesPolyData->SetPoints(targetLinePoints);

	// Add the lines to the dataset
	linesPolyData->SetLines(lines);

	
	sphere2Mapper->SetInputData(linesPolyData);

	
	sphere2Actor->SetMapper(sphere2Mapper);
	sphere2Actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
	sphere2Actor->GetProperty()->SetLineWidth(2.5);

	mRenderer->AddActor(sphere2Actor);
	
	mRenderer->Render();
	mRenderWindow->Render();
}

void MainWindow::nextPosition()
{

	ui->lbl_posture0->setPixmap(QPixmap());
	ui->lbl_posture0->setText("");
	ui->lbl_posture0->setFrameShape(QFrame::NoFrame);

	ui->lbl_posture1->setPixmap(QPixmap());
	ui->lbl_posture1->setText("");
	ui->lbl_posture1->setFrameShape(QFrame::NoFrame);

	ui->lbl_posture2->setPixmap(QPixmap());
	ui->lbl_posture2->setText("");
	ui->lbl_posture2->setFrameShape(QFrame::NoFrame);

	ui->lbl_posture3->setPixmap(QPixmap());
	ui->lbl_posture3->setText("");
	ui->lbl_posture3->setFrameShape(QFrame::NoFrame);

	ui->lbl_posture4->setPixmap(QPixmap());
	ui->lbl_posture4->setText("");
	ui->lbl_posture4->setFrameShape(QFrame::NoFrame);

	ui->lbl_posture5->setPixmap(QPixmap());
	ui->lbl_posture5->setText("");
	ui->lbl_posture5->setFrameShape(QFrame::NoFrame);

	ui->lbl_posture6->setPixmap(QPixmap());
	ui->lbl_posture6->setText("");
	ui->lbl_posture6->setFrameShape(QFrame::NoFrame);

	ui->lbl_posture7->setPixmap(QPixmap());
	ui->lbl_posture7->setText("");
	ui->lbl_posture7->setFrameShape(QFrame::NoFrame);

	ui->lbl_name_0->setText("");
	ui->lbl_name_0->setFrameShape(QFrame::NoFrame);

	ui->lbl_name_1->setText("");
	ui->lbl_name_1->setFrameShape(QFrame::NoFrame);

	ui->lbl_name_2->setText("");
	ui->lbl_name_2->setFrameShape(QFrame::NoFrame);

	ui->lbl_name_3->setText("");
	ui->lbl_name_3->setFrameShape(QFrame::NoFrame);

	ui->lbl_name_4->setText("");
	ui->lbl_name_4->setFrameShape(QFrame::NoFrame);

	ui->lbl_name_5->setText("");
	ui->lbl_name_5->setFrameShape(QFrame::NoFrame);

	ui->lbl_name_6->setText("");
	ui->lbl_name_6->setFrameShape(QFrame::NoFrame);

	ui->lbl_name_7->setText("");
	ui->lbl_name_7->setFrameShape(QFrame::NoFrame);

	ui->lbl_gesture1->setText("");
	ui->lbl_gesture1->setFrameShape(QFrame::NoFrame);

	ui->lbl_gesture2->setText("");
	ui->lbl_gesture2->setFrameShape(QFrame::NoFrame);

	ui->lbl_gesture3->setText("");
	ui->lbl_gesture3->setFrameShape(QFrame::NoFrame);

	ui->lbl_gesture4->setText("");
	ui->lbl_gesture4->setFrameShape(QFrame::NoFrame);

	ui->lbl_gesture5->setText("");
	ui->lbl_gesture5->setFrameShape(QFrame::NoFrame);

	ui->lbl_gesture6->setText("");
	ui->lbl_gesture6->setFrameShape(QFrame::NoFrame);

	ui->lbl_gesture7->setText("");
	ui->lbl_gesture7->setFrameShape(QFrame::NoFrame);

	
	


	nextBtncnt++;

	fstream ob;
	ui->listWidget_2->clear();
	savedTarget.clear();
	if(nextBtncnt%3==0)
		ob.open("GestureInterface/targetPosition_0.txt", ios::in);	
	else if(nextBtncnt % 3 == 1)
		ob.open("GestureInterface/targetPosition_1.txt", ios::in);
	else
		ob.open("GestureInterface/targetPosition_2.txt", ios::in);
	int cnt = 0;
	targetPoint temp;
	temp.pos_x = 0;
	temp.pos_y = 0;
	temp.pos_z = 0;

	while (!ob.eof())

	{
		string str;
		ob >> str;

		//cout << "str : "<<str << "\n";
		//cout << "str : " <<std::stoi(str) << "\n";
		cnt++;
		if (cnt % 3 == 1)
		{
			temp.pos_x = std::stoi(str);
		}
		if (cnt % 3 == 2)
		{
			temp.pos_y = std::stoi(str);
		}
		if (cnt % 3 == 0)
		{
			temp.pos_z = std::stoi(str);
			savedTarget.push_back(temp);

			string currentName = "targetPoint ";
			currentName += to_string(savedTarget.size());

			ui->listWidget_2->addItem(currentName.c_str());

			temp.pos_x = 0;
			temp.pos_y = 0;
			temp.pos_z = 0;

		}
	}

	ob.close();	//closing the file after use


}

void MainWindow::sensingPlay()
{

	readSensingAngles.clear();
	readSensingAngles_LU.clear();
	readSensingAngles_RL.clear();
	readSensingAngles_LL.clear();


	//upperRight thigh
	string fname = "./playSensingData/0_RightThigh.csv";
	multiSensingDataRead(fname, readSensingAngles);

	fname = "./playSensingData/1_LeftThigh.csv";
	multiSensingDataRead(fname, readSensingAngles_LU);

	fname = "./playSensingData/2_RightKnee.csv";
	multiSensingDataRead(fname, readSensingAngles_RL);

	fname = "./playSensingData/3_LeftKnee.csv";
	multiSensingDataRead(fname, readSensingAngles_LL);






	if (readSensingAngles.size() > 0)
	{
		for (int i = 0; i < readSensingAngles.size(); i++)
		{
			male_biped = 1;
			vitruvian_biped = 0;
			skeleton_biped = 0;
			//cout << "Male Biped Selected" << endl;

			Pelvis_objFilename = "../BodyGestureGenerator/data/Pelvis.obj";
			Chest_objFilename = "../BodyGestureGenerator/data/Chest.obj";
			headNeck_objFilename = "../BodyGestureGenerator/data/humanHead1.obj";
			LUA_objFilename = "../BodyGestureGenerator/data/LUA.obj";
			LLA_objFilename = "../BodyGestureGenerator/data/LLA.obj";
			LH_objFilename = "../BodyGestureGenerator/data/LH_G.obj";
			RUA_objFilename = "../BodyGestureGenerator/data/RUA.obj";
			RLA_objFilename = "../BodyGestureGenerator/data/RLA.obj";
			RH_objFilename = "../BodyGestureGenerator/data/RH_G.obj";
			LUL_objFilename = "../BodyGestureGenerator/data/LUL.obj";
			LLL_objFilename = "../BodyGestureGenerator/data/LLL.obj";
			LF_objFilename = "../BodyGestureGenerator/data/LF.obj";
			RUL_objFilename = "../BodyGestureGenerator/data/RUL.obj";
			RLL_objFilename = "../BodyGestureGenerator/data/RLL.obj";
			RF_objFilename = "../BodyGestureGenerator/data/RF.obj";

			PlconeTransform->Identity();
			CUconeTransform->Identity();
			Head_ObjReader_Transform->Identity();
			RarmTransform->Identity();
			RforearmTransform->Identity();
			RightHand_ObjReader_Transform->Identity();
			LarmTransform->Identity();
			LforearmTransform->Identity();
			LeftHand_ObjReader_Transform->Identity();
			RlulegTransform->Identity();
			RllegTransform->Identity();
			RF_ObjReader_Transform->Identity();
			LlulegTransform->Identity();
			LllegTransform->Identity();
			LF_ObjReader_Transform->Identity();

			RUA_JS_Transform->Identity();
			RLA_JS_Transform->Identity();
			LUA_JS_Transform->Identity();
			LLA_JS_Transform->Identity();
			RUL_JS_Transform->Identity();
			RLL_JS_Transform->Identity();
			LUL_JS_Transform->Identity();
			LLL_JS_Transform->Identity();

			pelvisObj_xpos = 0;
			pelvisObj_ypos = 47.875;
			pelvisObj_zpos = 0;
			pelvisObj_scale = 50;

			chestObj_xpos = 0;
			chestObj_ypos = 2.5;
			chestObj_zpos = 0;
			chestObj_scale = 50;

			head_NeckObj_xpos = 0;
			head_NeckObj_ypos = 26.0;
			head_NeckObj_zpos = -1.0;
			head_NeckObj_scale = 8;


			ruaObj_xpos = -10.5;
			ruaObj_ypos = 20.0;
			ruaObj_zpos = -2.5;
			ruaObj_scale = 50;

			rlaObj_xpos = 0.0;
			rlaObj_ypos = -14.0;
			rlaObj_zpos = 1.0;
			rlaObj_scale = 50;

			RHObj_xpos = -0.5;
			RHObj_ypos = -12.75;
			RHObj_zpos = 0.5;
			RHObj_scale = 40;

			luaObj_xpos = 10.50;
			luaObj_ypos = 20.0;
			luaObj_zpos = -2.5;
			luaObj_scale = 50;

			llaObj_xpos = 0.5;
			llaObj_ypos = -14.0;
			llaObj_zpos = 0.5;
			llaObj_scale = 50;

			LHObj_xpos = -0.5;
			LHObj_ypos = -12.75;
			LHObj_zpos = 0.5;
			LHObj_scale = 40;


			rulObj_xpos = -3.40;
			rulObj_ypos = 0; //-2.125
			rulObj_zpos = 0.0;
			rulObj_scale = 50;

			rllObj_xpos = -0.25;
			rllObj_ypos = -21.0;
			rllObj_zpos = 0.0;
			rllObj_scale = 50;

			RFObj_xpos = 0.7;
			RFObj_ypos = -19.25;
			RFObj_zpos = -2.10;
			RFObj_scale = 50;
			RF_xaxis_actor_Zpos = 20;

			lulObj_xpos = 3.90;
			lulObj_ypos = 0; //-2.125
			lulObj_zpos = 0.0;
			lulObj_scale = 50;

			lllObj_xpos = 1.0;
			lllObj_ypos = -21.0;
			lllObj_zpos = -0.75;
			lllObj_scale = 50;

			LFObj_xpos = 0.0;
			LFObj_ypos = -19.25;
			LFObj_zpos = -2.10;
			LFObj_scale = 50;



			mRenderer->RemoveActor(stickModel_pelvisActor);

			mRenderer->RemoveActor(stickModel_chest_0_Actor);
			mRenderer->RemoveActor(stickModel_chest_1_Actor);
			mRenderer->RemoveActor(stickModel_chest_2_Actor);
			mRenderer->RemoveActor(stickModel_chest_3_Actor);

			mRenderer->RemoveActor(stickModel_head_Actor);

			mRenderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
			mRenderer->RemoveActor(stickModel_rightUpperArm_Actor);
			mRenderer->RemoveActor(stickModel_rightElbow_Actor);
			mRenderer->RemoveActor(stickModel_rightLowerArm_Actor);
			mRenderer->RemoveActor(stickModel_rightHand_Actor);

			mRenderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
			mRenderer->RemoveActor(stickModel_leftUpperArm_Actor);
			mRenderer->RemoveActor(stickModel_leftElbow_Actor);
			mRenderer->RemoveActor(stickModel_leftLowerArm_Actor);
			mRenderer->RemoveActor(stickModel_leftHand_Actor);

			mRenderer->RemoveActor(stickModel_rightLegJoint_Actor);
			mRenderer->RemoveActor(stickModel_rightUpperLeg_Actor);
			mRenderer->RemoveActor(stickModel_rightKnee_Actor);
			mRenderer->RemoveActor(stickModel_rightLowerLeg_Actor);
			mRenderer->RemoveActor(stickModel_rightFoot_Actor);

			mRenderer->RemoveActor(stickModel_leftLegJoint_Actor);
			mRenderer->RemoveActor(stickModel_leftUpperLeg_Actor);
			mRenderer->RemoveActor(stickModel_leftKnee_Actor);
			mRenderer->RemoveActor(stickModel_leftLowerLeg_Actor);
			mRenderer->RemoveActor(stickModel_leftFoot_Actor);

			mRenderer->RemoveActor(none_xaxis_actor);
			mRenderer->RemoveActor(none_yaxis_actor);
			mRenderer->RemoveActor(none_zaxis_actor);

			//this->fullbodyIK_checkBox->setChecked(0);
			//this->rhIK_checkBox->setChecked(0);
			//this->lhIK_checkBox->setChecked(0);
			//this->rfIK_checkBox->setChecked(0);
			//this->lfIK_checkBox->setChecked(0);

			mRenderer->RemoveActor(rh_outlineActor);
			rhIK_flag = 0;
			mRenderer->RemoveActor(lh_outlineActor);
			lhIK_flag = 0;
			mRenderer->RemoveActor(rf_outlineActor);
			rfIK_flag = 0;
			mRenderer->RemoveActor(lf_outlineActor);
			lfIK_flag = 0;

			mRenderer->RemoveActor(pelvisJS_actor);
			mRenderer->RemoveActor(chestJS_actor);
			mRenderer->RemoveActor(LUA_JS_actor);
			mRenderer->RemoveActor(LLA_JS_actor);
			mRenderer->RemoveActor(RUA_JS_actor);
			mRenderer->RemoveActor(RLA_JS_actor);
			mRenderer->RemoveActor(LUL_JS_actor);
			mRenderer->RemoveActor(LLL_JS_actor);
			mRenderer->RemoveActor(RUL_JS_actor);
			mRenderer->RemoveActor(RLL_JS_actor);
			mRenderer->RemoveActor(targetActor);
			mRenderer->RemoveActor(sphere2Actor);

			//vtkActorCollection* actors = vtkActorCollection::New();
			//int NumberOfActors = renderer->VisibleActorCount();
			//actors = mRenderer->GetActors();
			//actors->InitTraversal();
			//for (int i = 0; i < NumberOfActors; i++) {
			//	mRenderer->RemoveActor(actors->GetNextActor());
			//}
			//actors->Delete();



			//this->freeFoots_radioButton->setChecked(true);
			//this->fixedFoots_radioButton->setChecked(false);
			//this->fixedRF_radioButton->setChecked(false);
			//this->fixedLF_radioButton->setChecked(false);
			//this->freeFoots_radioButton->setEnabled(false);
			//this->fixedFoots_radioButton->setEnabled(false);
			//this->fixedRF_radioButton->setEnabled(false);
			//this->fixedLF_radioButton->setEnabled(false);

			robotModel(1);
			int scaleFactor = 3;
			rul(readSensingAngles[i].x_roll * scaleFactor, 1, 0, 0);
			rul(readSensingAngles[i].y_pitch* scaleFactor, 0, 1, 0);
			rul(readSensingAngles[i].z_yaw* scaleFactor, 0, 0, 1);

			rll(readSensingAngles_RL[i].x_roll* scaleFactor, 1, 0, 0);
			rll(readSensingAngles_RL[i].y_pitch* scaleFactor, 0, 1, 0);
			rll(readSensingAngles_RL[i].z_yaw* scaleFactor, 0, 0, 1); 

			lul(readSensingAngles_LU[i].x_roll* scaleFactor, 1, 0, 0);
			lul(readSensingAngles_LU[i].y_pitch* scaleFactor, 0, 1, 0);
			lul(readSensingAngles_LU[i].z_yaw* scaleFactor, 0, 0, 1);

			lll(readSensingAngles_LL[i].x_roll* scaleFactor, 1, 0, 0);
			lll(readSensingAngles_LL[i].y_pitch* scaleFactor, 0, 1, 0);
			lll(readSensingAngles_LL[i].z_yaw* scaleFactor, 0, 0, 1);

			ui->edit_sensing->setText(to_string(i).c_str());
			//
			mRenderer->Render();
			mRenderWindow->Render();
			QApplication::processEvents();
	
		}
	}
}
