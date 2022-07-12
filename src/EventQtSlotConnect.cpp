//#include "allheaders.h"
//
//#include "anatomicalinputs.h"
//#include "ui_anatomicalinputs.h"
//
//#include "motionsphere_dialog.h"
//#include "ui_motionsphere_dialog.h"
//
//#include "timerSettings_window.h"
//#include "ui_timerSettings_window.h"
//
//#include "jointsphere_Dialog.h"
//#include "ui_jointsphere_Dialog.h"
//
//#include "unitmotion_integrationDialog.h"
//#include "ui_unitmotion_integrationDialog.h"
//
//#include "constraintprops.h"
//#include "ui_constraintprops.h"
//
//
//
//void sceneWidgets()
//{
//
//	//x-axis
//	none_xaxis_arrowSource->SetTipLength(0.20);
//	none_xaxis_arrowSource->Update();
//	none_xaxis_mapper->SetInputConnection(none_xaxis_arrowSource->GetOutputPort());
//	none_xaxis_Transform->Translate(0, 50, 0);
//	none_xaxis_actor->SetMapper(none_xaxis_mapper);
//	none_xaxis_actor->SetUserTransform(none_xaxis_Transform);
//	none_xaxis_actor->GetProperty()->SetColor(1, 0, 0);
//	none_xaxis_actor->SetScale(20, 20, 20);
//
//	//y-axis
//	none_yaxis_arrowSource->SetTipLength(0.20);
//	none_yaxis_arrowSource->Update();
//	none_yaxis_mapper->SetInputConnection(none_yaxis_arrowSource->GetOutputPort());
//	none_yaxis_Transform->Translate(0, 50, 0);
//	none_yaxis_actor->SetMapper(none_yaxis_mapper);
//	none_yaxis_actor->SetUserTransform(none_yaxis_Transform);
//	none_yaxis_actor->RotateWXYZ(90, 0, 0, 1);
//	none_yaxis_actor->GetProperty()->SetColor(0, 1, 0);
//	none_yaxis_actor->SetScale(20, 20, 20);
//
//	//z-axis
//	none_zaxis_arrowSource->SetTipLength(0.20);
//	none_zaxis_arrowSource->Update();
//	none_zaxis_mapper->SetInputConnection(none_zaxis_arrowSource->GetOutputPort());
//	none_zaxis_Transform->Translate(0, 50, 0);
//	none_zaxis_actor->SetMapper(none_zaxis_mapper);
//	none_zaxis_actor->SetUserTransform(none_zaxis_Transform);
//	none_zaxis_actor->GetProperty()->SetColor(0, 0, 1);
//	none_zaxis_actor->RotateWXYZ(-90, 0, 1, 0);
//	none_zaxis_actor->SetScale(20, 20, 20);
//
//
//	//Frontal Plane
//	fP_source->SetCenter(0.0, 0.5, 0.0);
//	fP_source->Update();
//	vtkPolyData* fP = fP_source->GetOutput();
//	fP_mapper->SetInputData(fP);
//	fP_actor->SetMapper(fP_mapper);
//	fP_actor->GetProperty()->SetColor(colors->GetColor3d("CornflowerBlue").GetData());
//	fP_actor->SetScale(75);
//	fP_actor->GetProperty()->SetOpacity(0.35);
//	//renderer->AddActor(fP_actor);
//
//
//	//Sagital Plane
//	sP_source->SetCenter(0.0, 0.5, 0.0);
//	sP_source->Update();
//	vtkPolyData* sP = sP_source->GetOutput();
//	sP_mapper->SetInputData(sP);
//	sP_actor->SetMapper(sP_mapper);
//	sP_actor->GetProperty()->SetColor(colors->GetColor3d("Coral").GetData());
//	sP_actor->SetScale(75);
//	sP_actor->GetProperty()->SetOpacity(0.35);
//	sP_actor->RotateY(90);
//	//renderer->AddActor(sP_actor);
//
//	//Horizontal Plane
//	hP_source->SetCenter(0, 0, 0);
//	hP_source->Update();
//	vtkPolyData* hP = hP_source->GetOutput();
//	hP_mapper->SetInputData(hP);
//	hP_Transform->Translate(0, 40, 0);
//	hP_actor->SetMapper(hP_mapper);
//	hP_actor->GetProperty()->SetColor(colors->GetColor3d("Aquamarine").GetData());
//	hP_actor->SetScale(75);
//	hP_actor->GetProperty()->SetOpacity(0.35);
//	hP_actor->SetUserTransform(hP_Transform);
//	hP_actor->RotateX(-90);
//	//renderer->AddActor(hP_actor);
//}
//void Props()
//{
//	ConstraintProp_sphereSource->SetCenter(50.0, 0.0, 0.0);
//	ConstraintProp_sphereSource->SetRadius(consProp_sphere_size);
//	ConstraintProp_sphereSource->SetPhiResolution(100);
//	ConstraintProp_sphereSource->SetThetaResolution(100);
//	ConstraintProp_sphere_mapper->SetInputConnection(ConstraintProp_sphereSource->GetOutputPort());
//	ConstraintProp_sphere_actor->SetUserTransform(ConstraintProp_sphere_transform);
//	ConstraintProp_sphere_actor->SetMapper(ConstraintProp_sphere_mapper);
//	ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//	//ConstraintProp_lineSource->SetPoint1(lineSource_p0);
//	//ConstraintProp_lineSource->SetPoint2(lineSource_p1);
//	//ConstraintProp_line_mapper->SetInputConnection(ConstraintProp_lineSource->GetOutputPort());
//	//ConstraintProp_line_actor->SetUserTransform(ConstraintProp_line_transform);
//	//ConstraintProp_line_actor->SetMapper(ConstraintProp_line_mapper);
//	//ConstraintProp_line_actor->GetProperty()->SetLineWidth(3.0);
//	//ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//	ConstraintProp_planeSource->SetCenter(0.0, 0.0, 0.0);
//	ConstraintProp_planeSource->SetPoint1(consProp_plane_p1x, consProp_plane_p1y, consProp_plane_p1z);
//	ConstraintProp_planeSource->SetPoint2(consProp_plane_p2x, consProp_plane_p2y, consProp_plane_p2z);
//	ConstraintProp_plane_transform->Translate(50, 0, 0);
//	ConstraintProp_planeSource->Update();
//	ConstraintProp_plane_mapper->SetInputData(ConstraintProp_planeSource->GetOutput());
//	ConstraintProp_plane_actor->SetUserTransform(ConstraintProp_plane_transform);
//	ConstraintProp_plane_actor->SetMapper(ConstraintProp_plane_mapper);
//	ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//	ConstraintProp_cubeSource->SetCenter(0, 0, 0);
//	ConstraintProp_cubeSource->SetXLength(consProp_cube_xlength);
//	ConstraintProp_cubeSource->SetYLength(consProp_cube_ylength);
//	ConstraintProp_cubeSource->SetZLength(consProp_cube_zlength);
//	ConstraintProp_cubeSource->Update();
//	ConstraintProp_cube_transform->Translate(50, 0, 0);
//	ConstraintProp_cube_mapper->SetInputData(ConstraintProp_cubeSource->GetOutput());
//	ConstraintProp_cube_actor->SetUserTransform(ConstraintProp_cube_transform);
//	ConstraintProp_cube_actor->SetMapper(ConstraintProp_cube_mapper);
//	ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//	ConstraintProp_cube_actor->GetProperty()->SetOpacity(0.75);
//
//
//	boxingBag_ObjReader->SetFileName(boxingBag_objFilename.c_str());
//	boxingBag_ObjReader_mapper->SetInputConnection(boxingBag_ObjReader->GetOutputPort());
//	boxingBag_ObjReader_Transform->Translate(0, 80, 136);
//	//boxingBag_ObjReader_Transform->SetInput(boxingBag_ObjReader_Transform);
//	boxingBag_objActor->SetUserTransform(boxingBag_ObjReader_Transform);
//	boxingBag_objActor->SetMapper(boxingBag_ObjReader_mapper);
//	boxingBag_objActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	boxingBag_objActor->SetScale(9.0, 6.0, 9.0);
//
//}
//
////================================================================================# Vitruvian Model # ============================================================================================
//
//typedef struct vetruvianVtkAvatarSegment
//{
//	vtkSmartPointer<vtkParametricSuperEllipsoid> parametricObject = vtkSmartPointer<vtkParametricSuperEllipsoid>::New();
//	vtkSmartPointer<vtkParametricFunctionSource> cylinderSource = vtkSmartPointer<vtkParametricFunctionSource>::New();
//	vtkSmartPointer<vtkPolyDataMapper> cylinderMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	vtkSmartPointer<vtkActor> cylinderActor = vtkSmartPointer<vtkActor>::New();
//
//	vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
//	vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
//
//	vtkSmartPointer<vtkSphereSource> jointSource = vtkSmartPointer<vtkSphereSource>::New();
//	vtkSmartPointer<vtkPolyDataMapper> jointMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	vtkSmartPointer<vtkActor> jointActor = vtkSmartPointer<vtkActor>::New();
//	double jointPoint[3];
//	float length;
//} JointSegment;
//
//typedef struct vetruvianTorso
//{
//	vtkSmartPointer<vtkConeSource> coneSource = vtkSmartPointer<vtkConeSource>::New();
//	vtkSmartPointer<vtkPolyDataMapper> coneMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	vtkSmartPointer<vtkActor> coneActor = vtkSmartPointer<vtkActor>::New();
//
//	vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
//	vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
//
//
//	double jointPoint[3];
//	float length;
//} Torso;
//
//struct Hand
//{
//	vtkSmartPointer<vtkOBJReader> handSource = vtkSmartPointer<vtkOBJReader>::New();
//	vtkSmartPointer<vtkPolyDataMapper> handMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	vtkSmartPointer<vtkActor> handActor = vtkSmartPointer<vtkActor>::New();
//	quaternion rotation;
//};
//
//struct Hand leftHand, rightHand;
//vtkSmartPointer<vtkCubeSource> leftHandSource = vtkSmartPointer<vtkCubeSource>::New();
//vtkSmartPointer<vtkPolyDataMapper> leftHandMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//vtkSmartPointer<vtkActor> leftHandActor = vtkSmartPointer<vtkActor>::New();
//
//JointSegment rightFootLowerLeg, rightKneeUpperLeg, rightHipSegment, leftFootLowerLeg, leftKneeUpperLeg, leftHipSegment, pelvisStomach;
//JointSegment sternumChest, neckToChin, chinToHead, head, rightShoulderSegment, rightElbowUpperArm, rightHandLowerArm, leftShoulderSegment, leftElbowUpperArm, leftHandLowerArm;
//
//
//SphereUtility vitruvianSphereUtility;
////int MotionSphere::sphereID;
//char* lllc, *lulc, *rllc, *rulc, *pc, *cc, *ruhc, *rlhc, *luhc, *llhc;
//bool isEqual = false;
//
//void drawSphere(JointSegment &jointSegment, float radius)
//{
//	// Create spheres for start and end point
//
//	jointSegment.sphereSource->SetCenter(jointSegment.jointPoint);
//	jointSegment.sphereSource->SetRadius(radius);
//	jointSegment.sphereSource->SetPhiResolution(50);
//	jointSegment.sphereSource->SetThetaResolution(50);
//	jointSegment.sphereMapper->SetInputConnection(jointSegment.sphereSource->GetOutputPort());
//
//	jointSegment.sphereActor->SetMapper(jointSegment.sphereMapper);
//	jointSegment.sphereActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//	//jointSegment.sphereActor->GetProperty()->SetSpecular(.5);
//	//jointSegment.sphereActor->GetProperty()->SetSpecularPower(20);
//
//	renderer->AddActor(jointSegment.sphereActor);
//}
//void drawJointSphere(JointSegment &jointSegment, float radius)
//{
//	jointSegment.jointSource->SetCenter(jointSegment.jointPoint);
//	jointSegment.jointSource->SetRadius(radius);
//	jointSegment.jointSource->SetPhiResolution(50);
//	jointSegment.jointSource->SetThetaResolution(50);
//	jointSegment.jointMapper->SetInputConnection(jointSegment.jointSource->GetOutputPort());
//
//	jointSegment.jointActor->SetMapper(jointSegment.jointMapper);
//	jointSegment.jointActor->GetProperty()->SetColor(colors->GetColor3d("White").GetData());
//	//jointSegment.jointActor->GetProperty()->SetOpacity(0.5);
//	//jointSegment.jointActor->GetProperty()->SetSpecularPower(20);
//
//	renderer->AddActor(jointSegment.jointActor);
//}
//void drawCube(JointSegment& handJoint, Hand& hand, float size)
//{
//	/*hand.handSource->SetCenter(handJoint.jointPoint);
//	hand.handSource->SetXLength(size - 2);
//	hand.handSource->SetYLength(size + 1);
//	hand.handSource->SetZLength(size);*/
//	// Create a mapper and actor.
//
//	hand.handMapper->SetInputConnection(hand.handSource->GetOutputPort());
//
//	/*float axis[3], angle;
//	angle = 2 * acos(hand.rotation.mData[3]);
//	if (angle < 0.001)
//	{
//		axis[0] = hand.rotation.mData[0];
//		axis[1] = hand.rotation.mData[2];
//		axis[2] = -hand.rotation.mData[1];
//	}
//	else
//	{
//		axis[0] = hand.rotation.mData[0] / sqrt(1 - hand.rotation.mData[3] * hand.rotation.mData[3]);
//		axis[1] = hand.rotation.mData[2] / sqrt(1 - hand.rotation.mData[3] * hand.rotation.mData[3]);
//		axis[2] = -hand.rotation.mData[1] / sqrt(1 - hand.rotation.mData[3] * hand.rotation.mData[3]);
//	}*/
//	hand.rotation.quattoaxisangle();
//
//	vtkSmartPointer<vtkTransform> transform =
//		vtkSmartPointer<vtkTransform>::New();
//	//transform->PostMultiply(); //this is the key line
//	transform->Translate(handJoint.jointPoint);
//	transform->Scale(size, size, size);
//	/*transform->RotateX(90);
//	transform->RotateY(-90);*/
//	transform->RotateWXYZ(hand.rotation.axisangle[0],
//		hand.rotation.axisangle[1],
//		hand.rotation.axisangle[2],
//		hand.rotation.axisangle[3]);
//	//hand.handActor->RotateWXYZ(angle, axis[0], axis[1], axis[2]);
//	hand.handActor->SetMapper(hand.handMapper);
//	hand.handActor->SetUserTransform(transform);
//	//hand.handActor->GetProperty()->SetSpecular(.5);
//	//hand.handActor->GetProperty()->SetSpecularPower(10);
//	renderer->AddActor(hand.handActor);
//}
//
//vtkSmartPointer<vtkOBJReader> headSource = vtkSmartPointer<vtkOBJReader>::New();
//vtkSmartPointer<vtkPolyDataMapper> headMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//vtkSmartPointer<vtkActor> headActor = vtkSmartPointer<vtkActor>::New();
//quaternion headQuat;
//
//void drawHead(JointSegment &neck)
//{
//
//
//	/*hand.handSource->SetCenter(handJoint.jointPoint);
//	hand.handSource->SetXLength(size - 2);
//	hand.handSource->SetYLength(size + 1);
//	hand.handSource->SetZLength(size);*/
//	// Create a mapper and actor.
//
//	headMapper->SetInputConnection(headSource->GetOutputPort());
//
//	headQuat.quattoaxisangle();
//
//	/*float axis[3], angle;
//	angle = 2 * acos(headQuat.mData[3]);
//	if (angle < 0.001)
//	{
//		axis[0] = headQuat.mData[0];
//		axis[1] = headQuat.mData[1];
//		axis[2] = headQuat.mData[2];
//	}
//	else
//	{
//		axis[0] = headQuat.mData[0] / sin(angle / 2);
//		axis[1] = headQuat.mData[1] / sin(angle / 2);
//		axis[2] = headQuat.mData[2] / sin(angle / 2);
//	}*/
//
//
//	vtkSmartPointer<vtkTransform> transform =
//		vtkSmartPointer<vtkTransform>::New();
//	//transform->PostMultiply(); //this is the key line
//	transform->Translate(neck.jointPoint);
//	transform->Scale(12.5, 12.5, 12.5);
//	/*transform->RotateX(90);
//	transform->RotateY(-90);*/
//	transform->RotateWXYZ(headQuat.axisangle[0], headQuat.axisangle[1], headQuat.axisangle[2], headQuat.axisangle[3]);
//	//headActor->RotateWXYZ(angle * 180 / PI, axis[0], axis[1], axis[2]);
//	headActor->SetMapper(headMapper);
//	headActor->SetUserTransform(transform);
//	//headActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//	//headActor->GetProperty()->SetSpecular(.5);
//	//headActor->GetProperty()->SetSpecularPower(10);
//	//headActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	renderer->AddActor(headActor);
//}
//void drawBoneSegment(JointSegment &startSegment, JointSegment &endSegment, float* scaling, bool isHead, char* color)
//{
//	//set parametric ellipsoid to source
//	startSegment.cylinderSource->SetParametricFunction(startSegment.parametricObject);
//	startSegment.cylinderSource->Update();
//	startSegment.cylinderSource->SetGenerateTextureCoordinates(true);
//	// Set the background color.
//	std::array<unsigned char, 4> bkg{ {255, 255, 255, 0} };
//	colors->SetColor("BkgColor", bkg.data());
//
//	// Create a cylinder.
//	// Cylinder height vector is (0,1,0).
//	// Cylinder center is in the middle of the cylinder
//
//	//startSegment.cylinderSource->SetResolution(50);
//	//startSegment.cylinderSource->SetRadius(2);
//	startSegment.parametricObject->SetN1(1.0);
//	startSegment.parametricObject->SetXRadius(scaling[0]);
//	startSegment.parametricObject->SetYRadius(scaling[1]);
//	startSegment.parametricObject->SetZRadius(scaling[2]);
//
//	////create a texture map for torso
//	//vtkSmartPointer<vtkTexture> texture =
//	//	vtkSmartPointer<vtkTexture>::New();
//	//vtkSmartPointer<vtkJPEGReader> reader =
//	//	vtkSmartPointer<vtkJPEGReader>::New();
//
//	vtkSmartPointer<vtkTransform> transform =
//		vtkSmartPointer<vtkTransform>::New();
//	if (scaling[0] == 10)
//	{
//		//startSegment.cylinderActor->RotateX(90);
//		startSegment.parametricObject->SetXRadius(scaling[0]);
//		startSegment.parametricObject->SetYRadius(scaling[1]);
//		startSegment.parametricObject->SetZRadius(scaling[2]);
//
//		// Read the image which will be the texture
//		//reader->SetFileName("velab.jpg");
//		//// Apply the texture
//		//texture->SetInputConnection(reader->GetOutputPort());
//		//VitruvianAvatar::vitruvianAvatarUpdate.b1.quattoaxisangle();
//		/*transform->RotateWXYZ(VitruvianAvatar::vitruvianAvatarUpdate.b1.axisangle[0],
//			VitruvianAvatar::vitruvianAvatarUpdate.b1.axisangle[1],
//			VitruvianAvatar::vitruvianAvatarUpdate.b1.axisangle[2],
//			VitruvianAvatar::vitruvianAvatarUpdate.b1.axisangle[3]);*/
//	}
//
//	// Compute a basis
//	double normalizedX[3];
//	double normalizedY[3];
//	double normalizedZ[3];
//
//	// The X axis is a vector from start to end
//	vtkMath::Subtract(endSegment.jointPoint, startSegment.jointPoint, normalizedX);
//	double length = vtkMath::Norm(normalizedX);
//	vtkMath::Normalize(normalizedX);
//
//	vtkSmartPointer<vtkMinimalStandardRandomSequence> rng =
//		vtkSmartPointer<vtkMinimalStandardRandomSequence>::New();
//	// The Z axis is an arbitrary vector cross X
//	double arbitrary[3];
//	for (auto i = 0; i < 3; ++i)
//	{
//		rng->Next();
//		arbitrary[i] = rng->GetRangeValue(-10, 10);
//	}
//	vtkMath::Cross(normalizedX, arbitrary, normalizedZ);
//	vtkMath::Normalize(normalizedZ);
//
//	// The Y axis is Z cross X
//	vtkMath::Cross(normalizedZ, normalizedX, normalizedY);
//	vtkSmartPointer<vtkMatrix4x4> matrix =
//		vtkSmartPointer<vtkMatrix4x4>::New();
//
//	// Create the direction cosine matrix
//	matrix->Identity();
//	for (unsigned int i = 0; i < 3; i++)
//	{
//		matrix->SetElement(i, 0, normalizedX[i]);
//		matrix->SetElement(i, 1, normalizedY[i]);
//		matrix->SetElement(i, 2, normalizedZ[i]);
//	}
//
//
//	// Apply the transforms
//
//	transform->Translate(startSegment.jointPoint);   // translate to starting point
//	transform->Concatenate(matrix);     // apply direction cosines
//	transform->RotateZ(-90.0);          // align cylinder to x axis
//	transform->RotateY(-27.0);
//
//	transform->Scale(1.0, length, 1.0); // scale along the height vector
//	transform->Translate(0, .5, 0);     // translate to start of cylinder
//
//	// Transform the polydata
//	vtkSmartPointer<vtkTransformPolyDataFilter> transformPD =
//		vtkSmartPointer<vtkTransformPolyDataFilter>::New();
//	transformPD->SetTransform(transform);
//	transformPD->SetInputConnection(startSegment.cylinderSource->GetOutputPort());
//
//#ifdef USER_MATRIX
//	startSegment.cylinderMapper->SetInputConnection(startSegment.cylinderSource->GetOutputPort());
//	startSegment.cylinderActor->SetUserMatrix(transform->GetMatrix());
//#else
//	mapper->SetInputConnection(transformPD->GetOutputPort());
//#endif
//	startSegment.cylinderActor->SetMapper(startSegment.cylinderMapper);
//	if (scaling[0] == 30)
//	{
//		//attach texture to the actor
//		//startSegment.cylinderActor->SetTexture(texture);
//		//startSegment.cylinderActor->RotateWXYZ(VitruvianAvatar::vitruvianAvatarUpdate.b1.axisangle[0],
//		//	VitruvianAvatar::vitruvianAvatarUpdate.b1.axisangle[1],
//		//	VitruvianAvatar::vitruvianAvatarUpdate.b1.axisangle[2],
//		//	VitruvianAvatar::vitruvianAvatarUpdate.b1.axisangle[3]);
//		//
//	}
//	else
//		startSegment.cylinderActor->GetProperty()->SetColor(colors->GetColor3d(color).GetData());
//	//startSegment.cylinderActor->GetProperty()->SetSpecular(.5);
//	//startSegment.cylinderActor->GetProperty()->SetSpecularPower(20);
//	//draw start and end points as a sphere
//	drawSphere(startSegment, 3);
//	drawSphere(endSegment, 3);
//	//if (!isHead)
//	{
//		//drawJointSphere(startSegment, 8);
//	}
//
//
//	//Add the actor to the scene
//
//	renderer->AddActor(startSegment.cylinderActor);
//}
//double max(double var1, double var2)
//{
//	return var1 >= var2 ? var1 : var2;
//}
//
//double VitruvianAvatar::humanHeight = 172.0;
//double headUnit;
//void updatejoints()
//{
//	rightKneeUpperLeg.jointPoint[0] = rightFootLowerLeg.jointPoint[0];
//	rightKneeUpperLeg.jointPoint[1] = rightFootLowerLeg.jointPoint[1] + 1.5 * headUnit;
//	rightKneeUpperLeg.jointPoint[2] = rightFootLowerLeg.jointPoint[2];
//
//	rightHipSegment.jointPoint[0] = rightKneeUpperLeg.jointPoint[0];
//	rightHipSegment.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + 1.5*headUnit;
//	rightHipSegment.jointPoint[2] = rightKneeUpperLeg.jointPoint[2];
//
//	leftKneeUpperLeg.jointPoint[0] = leftFootLowerLeg.jointPoint[0];
//	leftKneeUpperLeg.jointPoint[1] = leftFootLowerLeg.jointPoint[1] + 1.5 * headUnit;
//	leftKneeUpperLeg.jointPoint[2] = leftFootLowerLeg.jointPoint[2];
//
//	leftHipSegment.jointPoint[0] = leftKneeUpperLeg.jointPoint[0];
//	leftHipSegment.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] + 1.5*headUnit;
//	leftHipSegment.jointPoint[2] = leftKneeUpperLeg.jointPoint[2];
//
//	pelvisStomach.jointPoint[0] = (leftHipSegment.jointPoint[0] + rightHipSegment.jointPoint[0]) / 2;
//	pelvisStomach.jointPoint[1] = max(leftHipSegment.jointPoint[1], rightHipSegment.jointPoint[1]);
//	pelvisStomach.jointPoint[2] = max(leftHipSegment.jointPoint[2], rightHipSegment.jointPoint[2]);
//
//	sternumChest.jointPoint[0] = pelvisStomach.jointPoint[0];
//	sternumChest.jointPoint[1] = pelvisStomach.jointPoint[1] + headUnit;
//	sternumChest.jointPoint[2] = pelvisStomach.jointPoint[2];
//
//	neckToChin.jointPoint[0] = sternumChest.jointPoint[0];
//	neckToChin.jointPoint[1] = sternumChest.jointPoint[1] + headUnit;
//	neckToChin.jointPoint[2] = sternumChest.jointPoint[2];
//
//	chinToHead.jointPoint[0] = neckToChin.jointPoint[0];
//	chinToHead.jointPoint[1] = neckToChin.jointPoint[1] + (headUnit*0.4);
//	chinToHead.jointPoint[2] = neckToChin.jointPoint[2];
//
//	head.jointPoint[0] = chinToHead.jointPoint[0];
//	head.jointPoint[1] = chinToHead.jointPoint[1] + (headUnit*0.6);
//	head.jointPoint[2] = chinToHead.jointPoint[2];
//
//	rightShoulderSegment.jointPoint[0] = neckToChin.jointPoint[0] - 0.8*headUnit;
//	rightShoulderSegment.jointPoint[1] = neckToChin.jointPoint[1];
//	rightShoulderSegment.jointPoint[2] = neckToChin.jointPoint[2];
//
//	rightElbowUpperArm.jointPoint[0] = rightShoulderSegment.jointPoint[0];
//	rightElbowUpperArm.jointPoint[1] = rightShoulderSegment.jointPoint[1] - (1.2*headUnit);
//	rightElbowUpperArm.jointPoint[2] = rightShoulderSegment.jointPoint[2];
//
//	rightHandLowerArm.jointPoint[0] = rightElbowUpperArm.jointPoint[0];
//	rightHandLowerArm.jointPoint[1] = rightElbowUpperArm.jointPoint[1] - (1.2*headUnit);
//	rightHandLowerArm.jointPoint[2] = rightElbowUpperArm.jointPoint[2];
//
//	leftShoulderSegment.jointPoint[0] = neckToChin.jointPoint[0] + 0.8*headUnit;
//	leftShoulderSegment.jointPoint[1] = neckToChin.jointPoint[1];
//	leftShoulderSegment.jointPoint[2] = neckToChin.jointPoint[2];
//
//	leftElbowUpperArm.jointPoint[0] = leftShoulderSegment.jointPoint[0];
//	leftElbowUpperArm.jointPoint[1] = leftShoulderSegment.jointPoint[1] - (1.2*headUnit);
//	leftElbowUpperArm.jointPoint[2] = leftShoulderSegment.jointPoint[2];
//
//	leftHandLowerArm.jointPoint[0] = leftElbowUpperArm.jointPoint[0];
//	leftHandLowerArm.jointPoint[1] = leftElbowUpperArm.jointPoint[1] - (1.2*headUnit);
//	leftHandLowerArm.jointPoint[2] = leftElbowUpperArm.jointPoint[2];
//}
//
//void drawFloors()
//{
//	// Create a plane
//	vtkSmartPointer<vtkPlaneSource> planeSource =
//		vtkSmartPointer<vtkPlaneSource>::New();
//	planeSource->SetCenter(0.0, -0.0015, 0.0);
//	//planeSource->SetCenter(0.0, 0.005, 0.0);
//	planeSource->SetNormal(0.0, 1.0, 0.0);
//	//planeSource->set
//	planeSource->Update();
//
//	vtkPolyData* plane = planeSource->GetOutput();
//
//	// Create a mapper and actor
//	vtkSmartPointer<vtkPolyDataMapper> mapper =
//		vtkSmartPointer<vtkPolyDataMapper>::New();
//	mapper->SetInputData(plane);
//
//	vtkSmartPointer<vtkTexture> planeTexture = vtkSmartPointer<vtkTexture>::New();
//	vtkSmartPointer<vtkJPEGReader> reader = vtkSmartPointer<vtkJPEGReader>::New();
//	// Read the image which will be the texture
//	reader->SetFileName("..\\src\\data\\avtar\\floor.jpg");
//	// Apply the texture
//	planeTexture->SetInputConnection(reader->GetOutputPort());
//	planeTexture->SetRepeat(true);
//	vtkSmartPointer<vtkActor> actor =
//		vtkSmartPointer<vtkActor>::New();
//	actor->SetMapper(mapper);
//	actor->SetTexture(planeTexture);
//	actor->GetProperty()->LightingOff();
//	//actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	actor->SetScale(500.0);
//	renderer->AddActor(actor);
//}
//void drawAvatar()
//{
//	float scaling[3];
//
//	scaling[0] = 2.5; scaling[1] = 0.5; scaling[2] = 2.5;
//	drawBoneSegment(rightFootLowerLeg, rightKneeUpperLeg, scaling, true, rllc); // right lower leg
//	scaling[0] = 3.5; scaling[1] = 0.5; scaling[2] = 3.5;
//	drawBoneSegment(rightKneeUpperLeg, rightHipSegment, scaling, false, rulc); // right upper leg
//
//	scaling[0] = 2.5; scaling[1] = 0.5; scaling[2] = 2.5;
//	drawBoneSegment(leftFootLowerLeg, leftKneeUpperLeg, scaling, true, lllc); // left lower leg
//	scaling[0] = 3.5; scaling[1] = 0.5; scaling[2] = 3.5;
//	drawBoneSegment(leftKneeUpperLeg, leftHipSegment, scaling, false, lulc); // left upper leg
//
//	scaling[0] = 4.5; scaling[1] = 0.5; scaling[2] = 4.5;
//
//	drawBoneSegment(rightHipSegment, pelvisStomach, scaling, false, (char*)"DarkGray"); // right hips
//	drawBoneSegment(leftHipSegment, pelvisStomach, scaling, false, (char*)"DarkGray"); // left hips
//
//	scaling[0] = 5.0; scaling[1] = 0.5; scaling[2] = 5.0;
//	drawBoneSegment(pelvisStomach, sternumChest, scaling, false, pc); // stomach
//	scaling[0] = 10.0; scaling[1] = 0.5; scaling[2] = 7.5;
//	drawBoneSegment(sternumChest, neckToChin, scaling, false, cc); // chest
//	//scaling[0] = 1.75; scaling[1] = 0.5; scaling[2] = 1.75;
//	//drawBoneSegment(neckToChin, chinToHead,scaling,true, "DarkGray"); // neck
//	//scaling[0] = 5.0; scaling[1] = 0.8; scaling[2] = 3.5;
//	//drawBoneSegment(chinToHead, head, scaling, true, "DarkGray"); // head
//	//drawBoneSegment(head, head, scaling,true); //head
//	drawHead(neckToChin);
//
//	scaling[0] = 3.5; scaling[1] = 0.5; scaling[2] = 3.5;
//	drawBoneSegment(rightShoulderSegment, neckToChin, scaling, false, (char*)"DimGray"); // right shoulder
//	drawBoneSegment(rightElbowUpperArm, rightShoulderSegment, scaling, false, ruhc); // right upper arm
//	scaling[0] = 2.5; scaling[1] = 0.5; scaling[2] = 2.5;
//	drawBoneSegment(rightHandLowerArm, rightElbowUpperArm, scaling, true, rlhc); // right lower arm
//	drawCube(rightHandLowerArm, rightHand, 15);
//
//	scaling[0] = 3.5; scaling[1] = 0.5; scaling[2] = 3.5;
//	drawBoneSegment(leftShoulderSegment, neckToChin, scaling, false, (char*)"DimGray"); // left shoulder
//	drawBoneSegment(leftElbowUpperArm, leftShoulderSegment, scaling, false, luhc); // left upper arm
//	scaling[0] = 2.5; scaling[1] = 0.5; scaling[2] = 2.5;
//	drawBoneSegment(leftHandLowerArm, leftElbowUpperArm, scaling, true, llhc); // left lower arm
//	drawCube(leftHandLowerArm, leftHand, 15);
//}
//void rotateAvatar(msAvatar avatar)
//{
//	//--------------------------------------- Translate lower body to ground point ---------------------------
//	double diffR = rightFootLowerLeg.jointPoint[1];
//	double diffL = leftFootLowerLeg.jointPoint[1];
//
//	rightFootLowerLeg.jointPoint[0] = rightFootLowerLeg.jointPoint[0];
//	rightFootLowerLeg.jointPoint[1] = 0;
//	rightFootLowerLeg.jointPoint[2] = rightFootLowerLeg.jointPoint[2];
//
//	leftFootLowerLeg.jointPoint[0] = leftFootLowerLeg.jointPoint[0];
//	leftFootLowerLeg.jointPoint[1] = 0;
//	leftFootLowerLeg.jointPoint[2] = leftFootLowerLeg.jointPoint[2];
//
//	rightKneeUpperLeg.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] - diffR;
//	rightHipSegment.jointPoint[1] = rightHipSegment.jointPoint[1] - diffR;
//
//	leftKneeUpperLeg.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] - diffL;
//	leftHipSegment.jointPoint[1] = leftHipSegment.jointPoint[1] - diffL;
//
//
//	//---------------------------------------- Bottom-Up Update -----------------------------------------------
//	//Finding right knee joint from the fixed right foot.
//	quaternion q = avatar.b7;// .Inverse().mutiplication(avatar.b7);
//	quaternion vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	rightKneeUpperLeg.jointPoint[0] = rightFootLowerLeg.jointPoint[0] + vec.mData[0] * rightFootLowerLeg.length;
//	rightKneeUpperLeg.jointPoint[1] = 0 + vec.mData[2] * rightFootLowerLeg.length;
//	rightKneeUpperLeg.jointPoint[2] = rightFootLowerLeg.jointPoint[2] + -vec.mData[1] * rightFootLowerLeg.length;
//
//	//Finding left knee joint from the fixed left foot.
//	q = avatar.b9;// .Inverse().mutiplication(avatar.b9);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	leftKneeUpperLeg.jointPoint[0] = leftFootLowerLeg.jointPoint[0] + vec.mData[0] * leftFootLowerLeg.length;
//	leftKneeUpperLeg.jointPoint[1] = 0 + vec.mData[2] * leftFootLowerLeg.length;
//	leftKneeUpperLeg.jointPoint[2] = leftFootLowerLeg.jointPoint[2] + -vec.mData[1] * leftFootLowerLeg.length;
//
//	//Finding right pelvis joint from the right knee.
//	q = avatar.b6;// .Inverse().mutiplication(avatar.b6);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	rightHipSegment.jointPoint[0] = rightKneeUpperLeg.jointPoint[0] + vec.mData[0] * rightKneeUpperLeg.length;
//	rightHipSegment.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + vec.mData[2] * rightKneeUpperLeg.length;
//	rightHipSegment.jointPoint[2] = rightKneeUpperLeg.jointPoint[2] + -vec.mData[1] * rightKneeUpperLeg.length;
//
//	//Finding left pelvis joint from the left knee.
//	q = avatar.b8;// .Inverse().mutiplication(avatar.b8);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	leftHipSegment.jointPoint[0] = leftKneeUpperLeg.jointPoint[0] + vec.mData[0] * leftKneeUpperLeg.length;
//	leftHipSegment.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] + vec.mData[2] * leftKneeUpperLeg.length;
//	leftHipSegment.jointPoint[2] = leftKneeUpperLeg.jointPoint[2] + -vec.mData[1] * leftKneeUpperLeg.length;
//
//	//Finding pelvis joint from the left and right pelvis.
//	if (leftHipSegment.jointPoint[1] > rightHipSegment.jointPoint[1])
//	{
//		q = avatar.b0;// .Inverse().mutiplication(avatar.b8);
//		vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse()));
//
//		pelvisStomach.jointPoint[0] = leftHipSegment.jointPoint[0] + vec.mData[0] * leftHipSegment.length;
//		pelvisStomach.jointPoint[1] = leftHipSegment.jointPoint[1] + vec.mData[2] * leftHipSegment.length;
//		pelvisStomach.jointPoint[2] = leftHipSegment.jointPoint[2] - vec.mData[1] * leftHipSegment.length;
//
//		/*float diffR = leftHipSegment.jointPoint[1] - rightHipSegment.jointPoint[1];
//		rightKneeUpperLeg.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + diffR;
//		rightFootLowerLeg.jointPoint[1] = rightFootLowerLeg.jointPoint[1] + diffR;
//		rightHipSegment.jointPoint[1] = rightHipSegment.jointPoint[1] + diffR;
//
//		diffR = leftHipSegment.jointPoint[2] - rightHipSegment.jointPoint[2];;
//		rightKneeUpperLeg.jointPoint[2] = rightKneeUpperLeg.jointPoint[2] + diffR;
//		rightFootLowerLeg.jointPoint[2] = rightFootLowerLeg.jointPoint[2] + diffR;
//		rightHipSegment.jointPoint[2] = rightHipSegment.jointPoint[2] + diffR;*/
//
//		//	isEqual = false;
//
//	}
//	else 	if (rightHipSegment.jointPoint[1] >= leftHipSegment.jointPoint[1])
//	{
//		q = avatar.b0;// .Inverse().mutiplication(avatar.b8);
//		vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse()));
//
//		pelvisStomach.jointPoint[0] = rightHipSegment.jointPoint[0] + vec.mData[0] * rightHipSegment.length;
//		pelvisStomach.jointPoint[1] = rightHipSegment.jointPoint[1] + vec.mData[2] * rightHipSegment.length;
//		pelvisStomach.jointPoint[2] = rightHipSegment.jointPoint[2] - vec.mData[1] * rightHipSegment.length;
//		//cout << pelvisStomach.jointPoint[0] << "," << pelvisStomach.jointPoint[1] << "," << pelvisStomach.jointPoint[2] << ",";
//
//		/*float diffR = rightHipSegment.jointPoint[1] - leftHipSegment.jointPoint[1];
//		leftKneeUpperLeg.jointPoint[1]	= leftKneeUpperLeg.jointPoint[1] + diffR;
//		leftFootLowerLeg.jointPoint[1]	= leftFootLowerLeg.jointPoint[1] + diffR;
//		leftHipSegment.jointPoint[1]	= leftHipSegment.jointPoint[1] + diffR;
//
//		diffR = rightHipSegment.jointPoint[2] - leftHipSegment.jointPoint[2];
//		leftKneeUpperLeg.jointPoint[2]	= leftKneeUpperLeg.jointPoint[2] + diffR;
//		leftFootLowerLeg.jointPoint[2]	= leftFootLowerLeg.jointPoint[2] + diffR;
//		leftHipSegment.jointPoint[2]	= leftHipSegment.jointPoint[2]   + diffR;*/
//		// isEqual = false;
//	}
//	/*else
//	{
//		pelvisStomach.jointPoint[0] = (rightHipSegment.jointPoint[0] + leftHipSegment.jointPoint[0]) / 2;
//		pelvisStomach.jointPoint[1] = (rightHipSegment.jointPoint[1] + leftHipSegment.jointPoint[1]) / 2;
//		pelvisStomach.jointPoint[2] = (rightHipSegment.jointPoint[2] + leftHipSegment.jointPoint[2]) / 2;
//		isEqual = true;
//	}*/
//	cout << pelvisStomach.jointPoint[0] << "," << pelvisStomach.jointPoint[1] << "," << pelvisStomach.jointPoint[2] << endl;
//
//
//	//----------------------------------------Top-Down Update---------------------------------------------------------------------------------------
//			//Finding right pelvis joint from the pelvis.
//	q = avatar.b0;// .Inverse().mutiplication(avatar.b0);
//	vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse()));
//
//	rightHipSegment.jointPoint[0] = pelvisStomach.jointPoint[0] + vec.mData[0] * rightHipSegment.length;
//	rightHipSegment.jointPoint[1] = pelvisStomach.jointPoint[1] + vec.mData[2] * rightHipSegment.length; //Changes in Lower body with pelvis rotation and model moves continously in z axis
//	rightHipSegment.jointPoint[2] = pelvisStomach.jointPoint[2] - vec.mData[1] * rightHipSegment.length;//Changes in Lower body with pelvis rotation and model moves continously in z axis
//	//cout << rightHipSegment.jointPoint[0] << "," << rightHipSegment.jointPoint[1] << "," << rightHipSegment.jointPoint[2] << ",";
//
//	//Finding left pelvis joint from the pelvis.
//	q = avatar.b0;// .Inverse().mutiplication(avatar.b0);
//	vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse()));
//
//	leftHipSegment.jointPoint[0] = pelvisStomach.jointPoint[0] + vec.mData[0] * leftHipSegment.length;
//	leftHipSegment.jointPoint[1] = pelvisStomach.jointPoint[1] + vec.mData[2] * leftHipSegment.length;  //Changes in Lower body with pelvis rotation and model moves continously in z axis
//	leftHipSegment.jointPoint[2] = pelvisStomach.jointPoint[2] - vec.mData[1] * leftHipSegment.length;	//Changes in Lower body with pelvis rotation and model moves continously in z axis
//	//cout << leftHipSegment.jointPoint[0] << "," << leftHipSegment.jointPoint[1] << "," << leftHipSegment.jointPoint[2] << ",";
//
////if (!isEqual) //Execute topdown approach only when left and right hips are unequal
//	{
//		//Finding right knee from the right pelvis point
//		q = avatar.b6;// .Inverse().mutiplication(avatar.b6);
//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//		rightKneeUpperLeg.jointPoint[0] = (rightHipSegment.jointPoint[0] + vec.mData[0] * rightKneeUpperLeg.length);
//		rightKneeUpperLeg.jointPoint[1] = rightHipSegment.jointPoint[1] + vec.mData[2] * rightKneeUpperLeg.length;
//		rightKneeUpperLeg.jointPoint[2] = rightHipSegment.jointPoint[2] + -vec.mData[1] * rightKneeUpperLeg.length;
//		//cout << rightKneeUpperLeg.jointPoint[0] << "," << rightKneeUpperLeg.jointPoint[1] << "," << rightKneeUpperLeg.jointPoint[2] << ",";
//
//		//Finding left knee from the left pelvis point
//		q = avatar.b8;// .Inverse().mutiplication(avatar.b8);
//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//		leftKneeUpperLeg.jointPoint[0] = leftHipSegment.jointPoint[0] + vec.mData[0] * leftKneeUpperLeg.length;
//		leftKneeUpperLeg.jointPoint[1] = leftHipSegment.jointPoint[1] + vec.mData[2] * leftKneeUpperLeg.length;
//		leftKneeUpperLeg.jointPoint[2] = leftHipSegment.jointPoint[2] + -vec.mData[1] * leftKneeUpperLeg.length;
//		//cout << leftKneeUpperLeg.jointPoint[0] << "," << leftKneeUpperLeg.jointPoint[1] << "," << leftKneeUpperLeg.jointPoint[2] << ",";
//
//		//Finding right foot from the right knee point
//		q = avatar.b7;// .Inverse().mutiplication(avatar.b7);
//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//		rightFootLowerLeg.jointPoint[0] = rightKneeUpperLeg.jointPoint[0] + vec.mData[0] * rightFootLowerLeg.length;
//		rightFootLowerLeg.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + vec.mData[2] * rightFootLowerLeg.length;
//		rightFootLowerLeg.jointPoint[2] = rightKneeUpperLeg.jointPoint[2] + -vec.mData[1] * rightFootLowerLeg.length;
//		//cout << rightFootLowerLeg.jointPoint[0] << "," << rightFootLowerLeg.jointPoint[1] << "," << rightFootLowerLeg.jointPoint[2] << ",";
//
//		//Finding left foot from the left knee point
//		q = avatar.b9;// .Inverse().mutiplication(avatar.b9);
//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//		leftFootLowerLeg.jointPoint[0] = leftKneeUpperLeg.jointPoint[0] + vec.mData[0] * leftFootLowerLeg.length;
//		leftFootLowerLeg.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] + vec.mData[2] * leftFootLowerLeg.length;;
//		leftFootLowerLeg.jointPoint[2] = leftKneeUpperLeg.jointPoint[2] + -vec.mData[1] * leftFootLowerLeg.length;
//		//cout << leftFootLowerLeg.jointPoint[0] << "," << leftFootLowerLeg.jointPoint[1] << "," << leftFootLowerLeg.jointPoint[2] << ",";
//	}
//	//---------------------------------------------Updating UpperBody starting from pelvis position --------------------
//	//Finding sternum from the pelvis point
//	q = avatar.b0;// .Inverse().mutiplication(avatar.b0);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	sternumChest.jointPoint[0] = pelvisStomach.jointPoint[0] + vec.mData[0] * pelvisStomach.length;
//	sternumChest.jointPoint[1] = pelvisStomach.jointPoint[1] + vec.mData[2] * pelvisStomach.length;
//	sternumChest.jointPoint[2] = pelvisStomach.jointPoint[2] + -vec.mData[1] * pelvisStomach.length;
//	//cout << sternumChest.jointPoint[0] << "," << sternumChest.jointPoint[1] << "," << sternumChest.jointPoint[2] << ",";
//	//Finding neck from the sternum point
//	q = avatar.b1;// .Inverse().mutiplication(avatar.b1);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	neckToChin.jointPoint[0] = sternumChest.jointPoint[0] + vec.mData[0] * sternumChest.length;
//	neckToChin.jointPoint[1] = sternumChest.jointPoint[1] + vec.mData[2] * sternumChest.length;
//	neckToChin.jointPoint[2] = sternumChest.jointPoint[2] + -vec.mData[1] * sternumChest.length;
//	//cout << neckToChin.jointPoint[0] << "," << neckToChin.jointPoint[1] << "," << neckToChin.jointPoint[2] << ",";
//	headQuat = avatar.b1; //assigning headQuat for head rotation
//
//	//Finding head from the neck point
//	q = avatar.b1;// .Inverse().mutiplication(avatar.b1);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	chinToHead.jointPoint[0] = neckToChin.jointPoint[0] + vec.mData[0] * neckToChin.length;
//	chinToHead.jointPoint[1] = neckToChin.jointPoint[1] + vec.mData[2] * neckToChin.length;
//	chinToHead.jointPoint[2] = neckToChin.jointPoint[2] + -vec.mData[1] * neckToChin.length;
//
//	head.jointPoint[0] = chinToHead.jointPoint[0] + vec.mData[0] * chinToHead.length;
//	head.jointPoint[1] = chinToHead.jointPoint[1] + vec.mData[2] * chinToHead.length;
//	head.jointPoint[2] = chinToHead.jointPoint[2] + -vec.mData[1] * chinToHead.length;
//	//cout << head.jointPoint[0] << "," << head.jointPoint[1] << "," << head.jointPoint[2] << ",";
//	//---------------------------------------------- Hands ----------------------------------------------------
//		//Finding rightShoulder from the neck point
//	q = avatar.b1;// .Inverse().mutiplication(avatar.b1);
//	vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse()));
//
//	rightShoulderSegment.jointPoint[0] = neckToChin.jointPoint[0] + vec.mData[0] * rightShoulderSegment.length;
//	rightShoulderSegment.jointPoint[1] = neckToChin.jointPoint[1] + vec.mData[2] * rightShoulderSegment.length;
//	rightShoulderSegment.jointPoint[2] = neckToChin.jointPoint[2] + -vec.mData[1] * rightShoulderSegment.length;
//	//cout << rightShoulderSegment.jointPoint[0] << "," << rightShoulderSegment.jointPoint[1] << "," << rightShoulderSegment.jointPoint[2] << ",";
//	//Finding leftShoulder from the neck point
//	q = avatar.b1;// .Inverse().mutiplication(avatar.b1);
//	vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse()));
//
//	leftShoulderSegment.jointPoint[0] = neckToChin.jointPoint[0] + vec.mData[0] * leftShoulderSegment.length;
//	leftShoulderSegment.jointPoint[1] = neckToChin.jointPoint[1] + vec.mData[2] * leftShoulderSegment.length;
//	leftShoulderSegment.jointPoint[2] = neckToChin.jointPoint[2] + -vec.mData[1] * leftShoulderSegment.length;
//	//cout << leftShoulderSegment.jointPoint[0] << "," << leftShoulderSegment.jointPoint[1] << "," << leftShoulderSegment.jointPoint[2] << ",";
//	//Finding right elbow from the right shoulder point
//	q = avatar.b2;// .Inverse().mutiplication(avatar.b2);
//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse())); // Attention Pose
//	//vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse())); // T-Pose
//
//	rightElbowUpperArm.jointPoint[0] = rightShoulderSegment.jointPoint[0] + vec.mData[0] * rightElbowUpperArm.length;
//	rightElbowUpperArm.jointPoint[1] = rightShoulderSegment.jointPoint[1] + vec.mData[2] * rightElbowUpperArm.length;
//	rightElbowUpperArm.jointPoint[2] = rightShoulderSegment.jointPoint[2] + -vec.mData[1] * rightElbowUpperArm.length;
//	//cout << rightElbowUpperArm.jointPoint[0] << "," << rightElbowUpperArm.jointPoint[1] << "," << rightElbowUpperArm.jointPoint[2] << ",";
//	//Finding left elbow from the left shoulder point
//	q = avatar.b4;// .Inverse().mutiplication(avatar.b4);
//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse())); // Attention Pose
//	//vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse())); // T-Pose
//
//	leftElbowUpperArm.jointPoint[0] = leftShoulderSegment.jointPoint[0] + vec.mData[0] * leftElbowUpperArm.length;
//	leftElbowUpperArm.jointPoint[1] = leftShoulderSegment.jointPoint[1] + vec.mData[2] * leftElbowUpperArm.length;
//	leftElbowUpperArm.jointPoint[2] = leftShoulderSegment.jointPoint[2] + -vec.mData[1] * leftElbowUpperArm.length;
//	//cout << leftElbowUpperArm.jointPoint[0] << "," << leftElbowUpperArm.jointPoint[1] << "," << leftElbowUpperArm.jointPoint[2] << ",";
//	//Finding right hand from the right elbow point
//	q = avatar.b3;// .Inverse().mutiplication(avatar.b3);
//	rightHand.rotation = q;
//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse())); // Attention pose
//	//vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse())); // t-Pose
//
//	rightHandLowerArm.jointPoint[0] = rightElbowUpperArm.jointPoint[0] + vec.mData[0] * rightHandLowerArm.length;
//	rightHandLowerArm.jointPoint[1] = rightElbowUpperArm.jointPoint[1] + vec.mData[2] * rightHandLowerArm.length;
//	rightHandLowerArm.jointPoint[2] = rightElbowUpperArm.jointPoint[2] + -vec.mData[1] * rightHandLowerArm.length;
//	//cout << rightHandLowerArm.jointPoint[0] << "," << rightHandLowerArm.jointPoint[1] << "," << rightHandLowerArm.jointPoint[2]<<",";
//	//Finding left hand from the left elbow point
//	q = avatar.b5;// .Inverse().mutiplication(avatar.b5);
//	leftHand.rotation = q;
//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse())); // Attention Pose
//	//vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse())); // T-pose
//
//	leftHandLowerArm.jointPoint[0] = leftElbowUpperArm.jointPoint[0] + vec.mData[0] * leftHandLowerArm.length;
//	leftHandLowerArm.jointPoint[1] = leftElbowUpperArm.jointPoint[1] + vec.mData[2] * leftHandLowerArm.length;
//	leftHandLowerArm.jointPoint[2] = leftElbowUpperArm.jointPoint[2] + -vec.mData[1] * leftHandLowerArm.length;
//	//cout << leftHandLowerArm.jointPoint[0] << "," << leftHandLowerArm.jointPoint[1] << "," << leftHandLowerArm.jointPoint[2]<<endl;
//	drawAvatar();
//}
//double myRound(double var)
//{
//	// 37.66666 * 100 =3766.66 
//	// 3766.66 + .5 =3767.16    for rounding off value 
//	// then type cast to int so value is 3767 
//	// then divided by 100 so the value converted into 37.67 
//	double value = (int)(var * 100 + .5);
//	return (double)value / 100;
//}
//void rotateAvatar(int index)
//{
//	msAvatar currentAvatar = vitruvianSphereUtility.avatarData[index];
//	msAvatar initialAvatar = vitruvianSphereUtility.avatarData[1];
//	//--------------------------------------- Translate lower body to ground point ---------------------------
//	double diffR = rightFootLowerLeg.jointPoint[1];
//	double diffL = leftFootLowerLeg.jointPoint[1];
//
//	rightFootLowerLeg.jointPoint[0] = rightFootLowerLeg.jointPoint[0];
//	rightFootLowerLeg.jointPoint[1] = 0;
//	rightFootLowerLeg.jointPoint[2] = rightFootLowerLeg.jointPoint[2];
//
//	leftFootLowerLeg.jointPoint[0] = leftFootLowerLeg.jointPoint[0];
//	leftFootLowerLeg.jointPoint[1] = 0;
//	leftFootLowerLeg.jointPoint[2] = leftFootLowerLeg.jointPoint[2];
//
//	rightKneeUpperLeg.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] - diffR;
//	rightHipSegment.jointPoint[1] = rightHipSegment.jointPoint[1] - diffR;
//
//	leftKneeUpperLeg.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] - diffL;
//	leftHipSegment.jointPoint[1] = leftHipSegment.jointPoint[1] - diffL;
//
//
//	//---------------------------------------- Bottom-Up Update -----------------------------------------------
//	//Finding right knee joint from the fixed right foot.
//	quaternion q = initialAvatar.b7.Inverse().mutiplication(currentAvatar.b7);
//	quaternion vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	rightKneeUpperLeg.jointPoint[0] = rightFootLowerLeg.jointPoint[0] + vec.mData[0] * rightFootLowerLeg.length;
//	rightKneeUpperLeg.jointPoint[1] = 0 + vec.mData[2] * rightFootLowerLeg.length;
//	rightKneeUpperLeg.jointPoint[2] = rightFootLowerLeg.jointPoint[2] + -vec.mData[1] * rightFootLowerLeg.length;
//
//	//Finding left knee joint from the fixed left foot.
//	q = initialAvatar.b9.Inverse().mutiplication(currentAvatar.b9);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	leftKneeUpperLeg.jointPoint[0] = leftFootLowerLeg.jointPoint[0] + vec.mData[0] * leftFootLowerLeg.length;
//	leftKneeUpperLeg.jointPoint[1] = 0 + vec.mData[2] * leftFootLowerLeg.length;
//	leftKneeUpperLeg.jointPoint[2] = leftFootLowerLeg.jointPoint[2] + -vec.mData[1] * leftFootLowerLeg.length;
//
//	//Finding right pelvis joint from the right knee.
//	q = initialAvatar.b6.Inverse().mutiplication(currentAvatar.b6);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	rightHipSegment.jointPoint[0] = rightKneeUpperLeg.jointPoint[0] + vec.mData[0] * rightKneeUpperLeg.length;
//	rightHipSegment.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + vec.mData[2] * rightKneeUpperLeg.length;
//	rightHipSegment.jointPoint[2] = rightKneeUpperLeg.jointPoint[2] + -vec.mData[1] * rightKneeUpperLeg.length;
//
//	//Finding left pelvis joint from the left knee.
//	q = initialAvatar.b8.Inverse().mutiplication(currentAvatar.b8);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	leftHipSegment.jointPoint[0] = leftKneeUpperLeg.jointPoint[0] + vec.mData[0] * leftKneeUpperLeg.length;
//	leftHipSegment.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] + vec.mData[2] * leftKneeUpperLeg.length;
//	leftHipSegment.jointPoint[2] = leftKneeUpperLeg.jointPoint[2] - vec.mData[1] * leftKneeUpperLeg.length;
//
//	//Finding pelvis joint from the left and right pelvis.
//	if (leftHipSegment.jointPoint[1] > rightHipSegment.jointPoint[1])
//	{
//		q = initialAvatar.b0.Inverse().mutiplication(currentAvatar.b0);
//		vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse()));
//
//		pelvisStomach.jointPoint[0] = leftHipSegment.jointPoint[0] + vec.mData[0] * leftHipSegment.length;
//		pelvisStomach.jointPoint[1] = leftHipSegment.jointPoint[1] + vec.mData[2] * leftHipSegment.length;
//		pelvisStomach.jointPoint[2] = leftHipSegment.jointPoint[2] - vec.mData[1] * leftHipSegment.length;
//
//		/*float diffR = leftHipSegment.jointPoint[1] - rightHipSegment.jointPoint[1];
//		rightKneeUpperLeg.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + diffR;
//		rightFootLowerLeg.jointPoint[1] = rightFootLowerLeg.jointPoint[1] + diffR;
//		rightHipSegment.jointPoint[1] = rightHipSegment.jointPoint[1] + diffR;
//
//		diffR = leftHipSegment.jointPoint[2] - rightHipSegment.jointPoint[2];;
//		rightKneeUpperLeg.jointPoint[2] = rightKneeUpperLeg.jointPoint[2] + diffR;
//		rightFootLowerLeg.jointPoint[2] = rightFootLowerLeg.jointPoint[2] + diffR;
//		rightHipSegment.jointPoint[2] = rightHipSegment.jointPoint[2] + diffR;*/
//
//		//	isEqual = false;
//
//	}
//	else if (rightHipSegment.jointPoint[1] >= leftHipSegment.jointPoint[1])
//	{
//		q = initialAvatar.b0.Inverse().mutiplication(currentAvatar.b0);
//		vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse()));
//
//		pelvisStomach.jointPoint[0] = rightHipSegment.jointPoint[0] + vec.mData[0] * rightHipSegment.length;
//		pelvisStomach.jointPoint[1] = rightHipSegment.jointPoint[1] + vec.mData[2] * rightHipSegment.length;
//		pelvisStomach.jointPoint[2] = rightHipSegment.jointPoint[2] - vec.mData[1] * rightHipSegment.length;
//
//		/*float diffR = rightHipSegment.jointPoint[1] - leftHipSegment.jointPoint[1];
//		leftKneeUpperLeg.jointPoint[1]	= leftKneeUpperLeg.jointPoint[1] + diffR;
//		leftFootLowerLeg.jointPoint[1]	= leftFootLowerLeg.jointPoint[1] + diffR;
//		leftHipSegment.jointPoint[1]	= leftHipSegment.jointPoint[1] + diffR;
//
//		diffR = rightHipSegment.jointPoint[2] - leftHipSegment.jointPoint[2];
//		leftKneeUpperLeg.jointPoint[2]	= leftKneeUpperLeg.jointPoint[2] + diffR;
//		leftFootLowerLeg.jointPoint[2]	= leftFootLowerLeg.jointPoint[2] + diffR;
//		leftHipSegment.jointPoint[2]	= leftHipSegment.jointPoint[2]   + diffR;*/
//		// isEqual = false;
//	}
//	/*else
//	{
//		pelvisStomach.jointPoint[0] = (rightHipSegment.jointPoint[0] + leftHipSegment.jointPoint[0]) / 2;
//		pelvisStomach.jointPoint[1] = (rightHipSegment.jointPoint[1] + leftHipSegment.jointPoint[1]) / 2;
//		pelvisStomach.jointPoint[2] = (rightHipSegment.jointPoint[2] + leftHipSegment.jointPoint[2]) / 2;
//		isEqual = true;
//	}*/
//
//	//----------------------------------------Top-Down Update---------------------------------------------------------------------------------------
//			//Finding right pelvis joint from the pelvis.
//	q = initialAvatar.b0.Inverse().mutiplication(currentAvatar.b0);
//	vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse()));
//
//	rightHipSegment.jointPoint[0] = pelvisStomach.jointPoint[0] + vec.mData[0] * rightHipSegment.length;
//	rightHipSegment.jointPoint[1] = pelvisStomach.jointPoint[1] + vec.mData[2] * rightHipSegment.length; //Changes in Lower body with pelvis rotation and model moves continously in z axis
//	rightHipSegment.jointPoint[2] = pelvisStomach.jointPoint[2] - vec.mData[1] * rightHipSegment.length;//Changes in Lower body with pelvis rotation and model moves continously in z axis
//
//	//Finding left pelvis joint from the pelvis.
//	q = initialAvatar.b0.Inverse().mutiplication(currentAvatar.b0);
//	vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse()));
//
//	leftHipSegment.jointPoint[0] = pelvisStomach.jointPoint[0] + vec.mData[0] * leftHipSegment.length;
//	leftHipSegment.jointPoint[1] = pelvisStomach.jointPoint[1] + vec.mData[2] * leftHipSegment.length;  //Changes in Lower body with pelvis rotation and model moves continously in z axis
//	leftHipSegment.jointPoint[2] = pelvisStomach.jointPoint[2] - vec.mData[1] * leftHipSegment.length;	//Changes in Lower body with pelvis rotation and model moves continously in z axis
//
////if (!isEqual) //Execute topdown approach only when left and right hips are unequal
//	{
//		//Finding right knee from the right pelvis point
//		q = initialAvatar.b6.Inverse().mutiplication(currentAvatar.b6);
//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//		rightKneeUpperLeg.jointPoint[0] = (rightHipSegment.jointPoint[0] + vec.mData[0] * rightKneeUpperLeg.length);
//		rightKneeUpperLeg.jointPoint[1] = rightHipSegment.jointPoint[1] + vec.mData[2] * rightKneeUpperLeg.length;
//		rightKneeUpperLeg.jointPoint[2] = rightHipSegment.jointPoint[2] + -vec.mData[1] * rightKneeUpperLeg.length;
//
//		//Finding left knee from the left pelvis point
//		q = initialAvatar.b8.Inverse().mutiplication(currentAvatar.b8);
//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//		leftKneeUpperLeg.jointPoint[0] = leftHipSegment.jointPoint[0] + vec.mData[0] * leftKneeUpperLeg.length;
//		leftKneeUpperLeg.jointPoint[1] = leftHipSegment.jointPoint[1] + vec.mData[2] * leftKneeUpperLeg.length;
//		leftKneeUpperLeg.jointPoint[2] = leftHipSegment.jointPoint[2] + -vec.mData[1] * leftKneeUpperLeg.length;
//
//		//Finding right foot from the right knee point
//		q = initialAvatar.b7.Inverse().mutiplication(currentAvatar.b7);
//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//		rightFootLowerLeg.jointPoint[0] = rightKneeUpperLeg.jointPoint[0] + vec.mData[0] * rightFootLowerLeg.length;
//		rightFootLowerLeg.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + vec.mData[2] * rightFootLowerLeg.length;
//		rightFootLowerLeg.jointPoint[2] = rightKneeUpperLeg.jointPoint[2] + -vec.mData[1] * rightFootLowerLeg.length;
//
//		//Finding left foot from the left knee point
//		q = initialAvatar.b9.Inverse().mutiplication(currentAvatar.b9);
//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//		leftFootLowerLeg.jointPoint[0] = leftKneeUpperLeg.jointPoint[0] + vec.mData[0] * leftFootLowerLeg.length;
//		leftFootLowerLeg.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] + vec.mData[2] * leftFootLowerLeg.length;;
//		leftFootLowerLeg.jointPoint[2] = leftKneeUpperLeg.jointPoint[2] + -vec.mData[1] * leftFootLowerLeg.length;
//	}
//	//---------------------------------------------Updating UpperBody starting from pelvis position --------------------
//	//Finding sternum from the pelvis point
//	q = initialAvatar.b0.Inverse().mutiplication(currentAvatar.b0);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	sternumChest.jointPoint[0] = pelvisStomach.jointPoint[0] + vec.mData[0] * pelvisStomach.length;
//	sternumChest.jointPoint[1] = pelvisStomach.jointPoint[1] + vec.mData[2] * pelvisStomach.length;
//	sternumChest.jointPoint[2] = pelvisStomach.jointPoint[2] + -vec.mData[1] * pelvisStomach.length;
//
//	//Finding neck from the sternum point
//	q = initialAvatar.b1.Inverse().mutiplication(currentAvatar.b1);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	neckToChin.jointPoint[0] = sternumChest.jointPoint[0] + vec.mData[0] * sternumChest.length;
//	neckToChin.jointPoint[1] = sternumChest.jointPoint[1] + vec.mData[2] * sternumChest.length;
//	neckToChin.jointPoint[2] = sternumChest.jointPoint[2] + -vec.mData[1] * sternumChest.length;
//
//	headQuat = q; //assigning headQuat for head rotation
//
//	//Finding head from the neck point
//	q = initialAvatar.b1.Inverse().mutiplication(currentAvatar.b1);
//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));
//
//	chinToHead.jointPoint[0] = neckToChin.jointPoint[0] + vec.mData[0] * neckToChin.length;
//	chinToHead.jointPoint[1] = neckToChin.jointPoint[1] + vec.mData[2] * neckToChin.length;
//	chinToHead.jointPoint[2] = neckToChin.jointPoint[2] + -vec.mData[1] * neckToChin.length;
//
//	head.jointPoint[0] = chinToHead.jointPoint[0] + vec.mData[0] * chinToHead.length;
//	head.jointPoint[1] = chinToHead.jointPoint[1] + vec.mData[2] * chinToHead.length;
//	head.jointPoint[2] = chinToHead.jointPoint[2] + -vec.mData[1] * chinToHead.length;
//
//	//---------------------------------------------- Hands ----------------------------------------------------
//		//Finding rightShoulder from the neck point
//	q = initialAvatar.b1.Inverse().mutiplication(currentAvatar.b1);
//	vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse()));
//
//	rightShoulderSegment.jointPoint[0] = neckToChin.jointPoint[0] + vec.mData[0] * rightShoulderSegment.length;
//	rightShoulderSegment.jointPoint[1] = neckToChin.jointPoint[1] + vec.mData[2] * rightShoulderSegment.length;
//	rightShoulderSegment.jointPoint[2] = neckToChin.jointPoint[2] + -vec.mData[1] * rightShoulderSegment.length;
//
//	//Finding leftShoulder from the neck point
//	q = initialAvatar.b1.Inverse().mutiplication(currentAvatar.b1);
//	vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse()));
//
//	leftShoulderSegment.jointPoint[0] = neckToChin.jointPoint[0] + vec.mData[0] * leftShoulderSegment.length;
//	leftShoulderSegment.jointPoint[1] = neckToChin.jointPoint[1] + vec.mData[2] * leftShoulderSegment.length;
//	leftShoulderSegment.jointPoint[2] = neckToChin.jointPoint[2] + -vec.mData[1] * leftShoulderSegment.length;
//
//	//Finding right elbow from the right shoulder point
//	q = initialAvatar.b2.Inverse().mutiplication(currentAvatar.b2);
//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//	rightElbowUpperArm.jointPoint[0] = rightShoulderSegment.jointPoint[0] + vec.mData[0] * rightElbowUpperArm.length;
//	rightElbowUpperArm.jointPoint[1] = rightShoulderSegment.jointPoint[1] + vec.mData[2] * rightElbowUpperArm.length;
//	rightElbowUpperArm.jointPoint[2] = rightShoulderSegment.jointPoint[2] + -vec.mData[1] * rightElbowUpperArm.length;
//
//	//Finding left elbow from the left shoulder point
//	q = initialAvatar.b4.Inverse().mutiplication(currentAvatar.b4);
//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//	leftElbowUpperArm.jointPoint[0] = leftShoulderSegment.jointPoint[0] + vec.mData[0] * leftElbowUpperArm.length;
//	leftElbowUpperArm.jointPoint[1] = leftShoulderSegment.jointPoint[1] + vec.mData[2] * leftElbowUpperArm.length;
//	leftElbowUpperArm.jointPoint[2] = leftShoulderSegment.jointPoint[2] + -vec.mData[1] * leftElbowUpperArm.length;
//
//	//Finding right hand from the right elbow point
//	q = initialAvatar.b3.Inverse().mutiplication(currentAvatar.b3);
//	rightHand.rotation = q;
//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//	rightHandLowerArm.jointPoint[0] = rightElbowUpperArm.jointPoint[0] + vec.mData[0] * rightHandLowerArm.length;
//	rightHandLowerArm.jointPoint[1] = rightElbowUpperArm.jointPoint[1] + vec.mData[2] * rightHandLowerArm.length;
//	rightHandLowerArm.jointPoint[2] = rightElbowUpperArm.jointPoint[2] + -vec.mData[1] * rightHandLowerArm.length;
//
//	//Finding left hand from the left elbow point
//	q = initialAvatar.b5.Inverse().mutiplication(currentAvatar.b5);
//	leftHand.rotation = q;
//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));
//
//	leftHandLowerArm.jointPoint[0] = leftElbowUpperArm.jointPoint[0] + vec.mData[0] * leftHandLowerArm.length;
//	leftHandLowerArm.jointPoint[1] = leftElbowUpperArm.jointPoint[1] + vec.mData[2] * leftHandLowerArm.length;
//	leftHandLowerArm.jointPoint[2] = leftElbowUpperArm.jointPoint[2] + -vec.mData[1] * leftHandLowerArm.length;
//
//	drawAvatar();
//
//
//
//}
//msAvatar getFirstInverse(int index, SphereUtility *mySu)
//{
//	msAvatar result;
//	result.b0 = mySu->avatarData[index].b0.mutiplication(mySu->avatarData[0].b0.Inverse());
//	result.b1 = mySu->avatarData[index].b1.mutiplication(mySu->avatarData[0].b1.Inverse());
//	result.b2 = mySu->avatarData[index].b2.mutiplication(mySu->avatarData[0].b2.Inverse());
//	result.b3 = mySu->avatarData[index].b3.mutiplication(mySu->avatarData[0].b3.Inverse());
//	result.b4 = mySu->avatarData[index].b4.mutiplication(mySu->avatarData[0].b4.Inverse());
//	result.b5 = mySu->avatarData[index].b5.mutiplication(mySu->avatarData[0].b5.Inverse());
//	result.b6 = mySu->avatarData[index].b6.mutiplication(mySu->avatarData[0].b6.Inverse());
//	result.b7 = mySu->avatarData[index].b7.mutiplication(mySu->avatarData[0].b7.Inverse());
//	result.b8 = mySu->avatarData[index].b8.mutiplication(mySu->avatarData[0].b8.Inverse());
//	result.b9 = mySu->avatarData[index].b9.mutiplication(mySu->avatarData[0].b9.Inverse());
//
//	return result;
//}
//
//void VitruvianAvatar::initializeVetruvianVtkAvatar()
//{
//	headUnit = VitruvianAvatar::humanHeight / 7.5;
//	rightFootLowerLeg.jointPoint[0] = -0.5*headUnit;
//	rightFootLowerLeg.jointPoint[1] = rightFootLowerLeg.jointPoint[2] = 0;
//
//	leftFootLowerLeg.jointPoint[0] = 0.5*headUnit;
//	leftFootLowerLeg.jointPoint[1] = leftFootLowerLeg.jointPoint[2] = 0;
//
//	leftFootLowerLeg.length = rightFootLowerLeg.length = 1.5 * headUnit;
//	leftFootLowerLeg.length = rightFootLowerLeg.length = 1.5 * headUnit;
//
//	leftKneeUpperLeg.length = rightKneeUpperLeg.length = 1.5 * headUnit;
//	leftKneeUpperLeg.length = rightKneeUpperLeg.length = 1.5 * headUnit;
//
//	leftHipSegment.length = rightHipSegment.length = 0.5 * headUnit;
//
//	pelvisStomach.length = sternumChest.length = headUnit;
//	neckToChin.length = chinToHead.length = headUnit * 0.5;
//
//	rightShoulderSegment.length = leftShoulderSegment.length = 0.8*headUnit;
//	rightElbowUpperArm.length = leftElbowUpperArm.length = 1.2*headUnit;
//	rightHandLowerArm.length = leftHandLowerArm.length = 1.2*headUnit;
//
//	//------------------------------- read obj files --------------------------------
//	// readRightHand.
//	rightHand.handSource->SetFileName("..\\src\\data\\avtar\\RightHand.obj");
//	rightHand.handSource->Update();
//
//	// readLeftHand.
//	leftHand.handSource->SetFileName("..\\src\\data\\avtar\\LeftHand.obj");
//	leftHand.handSource->Update();
//
//	//readHead
//	headSource->SetFileName("..\\src\\data\\avtar\\humanHead.obj");
//	headSource->Update();
//
//	//create a texture map for torso
//	vtkSmartPointer<vtkTexture> texture =
//		vtkSmartPointer<vtkTexture>::New();
//	vtkSmartPointer<vtkJPEGReader> reader =
//		vtkSmartPointer<vtkJPEGReader>::New();
//	reader->SetFileName("..\\src\\data\\avtar\\headmap.jpg");
//	// Apply the texture
//	texture->SetInputConnection(reader->GetOutputPort());
//	headActor->SetTexture(texture);
//
//	lllc = (char*)"DimGray"; lulc = (char*)"DimGray"; rllc = (char*)"DimGray"; rulc = (char*)"DimGray"; pc = (char*)"DimGray";
//	cc = (char*)"DimGray"; ruhc = (char*)"DimGray"; rlhc = (char*)"DimGray"; luhc = (char*)"DimGray"; llhc = (char*)"DimGray";
//	updatejoints();
//}
//void VitruvianAvatar::startVetruvianAvatar()
//{
//	
//	//drawFloors();
//	drawAvatar();
//	vitruvianSphereUtility.readAvatarData("FormFile.txt");
//
//	
//}
//
//
////===============================================================================================================
//
//
//void jointSpheres()
//{
//
//
//	if (male_biped == 1)
//	{
//		////Pelvis JS
//		//pelvisJS->SetRadius(SphereRadius);
//		//pelvisJS->SetThetaResolution(50);
//		//pelvisJS->SetPhiResolution(50);
//		//pelvisJS->SetCenter(*(Plcone->GetCenter()), *(Plcone->GetCenter() + 1), *(Plcone->GetCenter() + 2));
//
//		//pelvisJS_mapper->SetInputConnection(pelvisJS->GetOutputPort());
//
//		//pelvisJS_Transform->SetInput(PlconeTransform);
//
//		//pelvisJS_actor->SetMapper(pelvisJS_mapper);
//		//pelvisJS_actor->GetProperty()->SetOpacity(0.5);
//		//pelvisJS_actor->SetUserTransform(pelvisJS_Transform);
//		//pelvisJS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//		////Chest JS
//		//chestJS->SetRadius(SphereRadius);
//		//chestJS->SetThetaResolution(50);
//		//chestJS->SetPhiResolution(50);
//		//chestJS->SetCenter(*(forechest->GetCenter()), *(forechest->GetCenter() + 1) - 10, *(forechest->GetCenter() + 2));
//
//		//chestJS_mapper->SetInputConnection(chestJS->GetOutputPort());
//
//		//chestJS_Transform->SetInput(CUconeTransform);
//
//		//chestJS_actor->SetMapper(chestJS_mapper);
//		//chestJS_actor->GetProperty()->SetOpacity(0.5);
//		//chestJS_actor->SetUserTransform(chestJS_Transform);
//		//chestJS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//
//		//RUA JS
//		RUA_JS->SetRadius(SphereRadius);
//		RUA_JS->SetThetaResolution(50);
//		RUA_JS->SetPhiResolution(50);
//		RUA_JS->SetCenter(*(RShoulder->GetCenter()), *(RShoulder->GetCenter() + 1), *(RShoulder->GetCenter() + 2));
//		RUA_JS_mapper->SetInputConnection(RUA_JS->GetOutputPort());
//
//		RUA_JS_Transform->SetInput(RarmTransform);
//
//		RUA_JS_actor->SetUserTransform(RUA_JS_Transform);
//		RUA_JS_actor->SetMapper(RUA_JS_mapper);
//		RUA_JS_actor->GetProperty()->SetOpacity(0.5);
//		RUA_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//		//RLA JS
//		RLA_JS->SetRadius(SphereRadius);
//		RLA_JS->SetThetaResolution(50);
//		RLA_JS->SetPhiResolution(50);
//		RLA_JS->SetCenter(*(Relbow->GetCenter()), *(Relbow->GetCenter() + 1), *(Relbow->GetCenter() + 2));
//
//		RLA_JS_mapper->SetInputConnection(RLA_JS->GetOutputPort());
//
//		RLA_JS_Transform->SetInput(RforearmTransform);
//
//		RLA_JS_actor->SetUserTransform(RLA_JS_Transform);
//		RLA_JS_actor->SetMapper(RLA_JS_mapper);
//		RLA_JS_actor->GetProperty()->SetOpacity(0.5);
//		RLA_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//		//LUA JS
//		LUA_JS->SetRadius(SphereRadius);
//		LUA_JS->SetThetaResolution(50);
//		LUA_JS->SetPhiResolution(50);
//		LUA_JS->SetCenter(*(LShoulder->GetCenter()), *(LShoulder->GetCenter() + 1), *(LShoulder->GetCenter() + 2));
//
//		LUA_JS_mapper->SetInputConnection(LUA_JS->GetOutputPort());
//
//		LUA_JS_Transform->SetInput(LarmTransform);
//
//		LUA_JS_actor->SetMapper(LUA_JS_mapper);
//		LUA_JS_actor->GetProperty()->SetOpacity(0.5);
//		LUA_JS_actor->SetUserTransform(LUA_JS_Transform);
//
//		LUA_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//		//LLA JS
//		LLA_JS->SetRadius(SphereRadius);
//		LLA_JS->SetThetaResolution(50);
//		LLA_JS->SetPhiResolution(50);
//		LLA_JS->SetCenter(*(Lelbow->GetCenter()), *(Lelbow->GetCenter() + 1), *(Lelbow->GetCenter() + 2));
//
//		LLA_JS_mapper->SetInputConnection(LLA_JS->GetOutputPort());
//
//		LLA_JS_Transform->SetInput(LforearmTransform);
//
//		LLA_JS_actor->SetMapper(LLA_JS_mapper);
//		LLA_JS_actor->GetProperty()->SetOpacity(0.5);
//		LLA_JS_actor->SetUserTransform(LLA_JS_Transform);
//		LLA_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//		//RUL JS
//		RUL_JS->SetRadius(SphereRadius);
//		RUL_JS->SetThetaResolution(50);
//		RUL_JS->SetPhiResolution(50);
//		RUL_JS->SetCenter(*(Rlujoint->GetCenter()), *(Rlujoint->GetCenter() + 1), *(Rlujoint->GetCenter() + 2));
//
//		RUL_JS_mapper->SetInputConnection(RUL_JS->GetOutputPort());
//
//		RUL_JS_Transform->SetInput(RlulegTransform);
//
//
//		RUL_JS_actor->SetMapper(RUL_JS_mapper);
//		RUL_JS_actor->GetProperty()->SetOpacity(0.5);
//		RUL_JS_actor->SetUserTransform(RUL_JS_Transform);
//		RUL_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//		//RLL JS
//		RLL_JS->SetRadius(SphereRadius);
//		RLL_JS->SetThetaResolution(50);
//		RLL_JS->SetPhiResolution(50);
//		RLL_JS->SetCenter(*(Rknee->GetCenter()), *(Rknee->GetCenter() + 1), *(Rknee->GetCenter() + 2));
//
//		RLL_JS_mapper->SetInputConnection(RLL_JS->GetOutputPort());
//
//		RLL_JS_Transform->SetInput(RllegTransform);
//
//		RLL_JS_actor->SetMapper(RLL_JS_mapper);
//		RLL_JS_actor->GetProperty()->SetOpacity(0.5);
//		RLL_JS_actor->SetUserTransform(RLL_JS_Transform);
//		RLL_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//		//LUL JS
//		LUL_JS->SetRadius(SphereRadius);
//		LUL_JS->SetThetaResolution(50);
//		LUL_JS->SetPhiResolution(50);
//		LUL_JS->SetCenter(*(Llujoint->GetCenter()), *(Llujoint->GetCenter() + 1), *(Llujoint->GetCenter() + 2));
//
//		LUL_JS_mapper->SetInputConnection(LUL_JS->GetOutputPort());
//
//		LUL_JS_Transform->SetInput(LlulegTransform);
//
//		LUL_JS_actor->SetMapper(LUL_JS_mapper);
//		LUL_JS_actor->GetProperty()->SetOpacity(0.5);
//		LUL_JS_actor->SetUserTransform(LUL_JS_Transform);
//		LUL_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//		//LLL JS
//		LLL_JS->SetRadius(SphereRadius);
//		LLL_JS->SetThetaResolution(50);
//		LLL_JS->SetPhiResolution(50);
//		LLL_JS->SetCenter(*(Lknee->GetCenter()), *(Lknee->GetCenter() + 1), *(Lknee->GetCenter() + 2));
//
//		LLL_JS_mapper->SetInputConnection(LLL_JS->GetOutputPort());
//
//		LLL_JS_Transform->SetInput(LllegTransform);
//
//		LLL_JS_actor->SetMapper(LLL_JS_mapper);
//		LLL_JS_actor->GetProperty()->SetOpacity(0.5);
//		LLL_JS_actor->SetUserTransform(LLL_JS_Transform);
//		LLL_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//	}
//
//	if (skeleton_biped == 1)
//	{
//		//RUA JS
//		RUA_JS->SetRadius(SphereRadius);
//		RUA_JS->SetThetaResolution(50);
//		RUA_JS->SetPhiResolution(50);
//		RUA_JS->SetCenter(*(stickModel_chest_3_Source->GetCenter()) - stickModel_chest_3_Source->GetRadius() - stickModel_rightShoulderJoint_Source->GetRadius(),
//			*(stickModel_chest_3_Source->GetCenter() + 1) - 1.0,
//			*(stickModel_chest_3_Source->GetCenter() + 2));
//		RUA_JS_mapper->SetInputConnection(RUA_JS->GetOutputPort());
//
//		RUA_JS_Transform->SetInput(stickModel_chest_3_Transform);
//
//		RUA_JS_actor->SetUserTransform(RUA_JS_Transform);
//		RUA_JS_actor->SetMapper(RUA_JS_mapper);
//		RUA_JS_actor->GetProperty()->SetOpacity(0.5);
//		RUA_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//		//RLA JS
//		RLA_JS->SetRadius(SphereRadius);
//		RLA_JS->SetThetaResolution(50);
//		RLA_JS->SetPhiResolution(50);
//		RLA_JS->SetCenter(*(stickModel_rightUpperArm_Source->GetCenter()),
//			*(stickModel_rightUpperArm_Source->GetCenter() + 1) - (stickModel_rightUpperArm_Source->GetHeight() / 2) - stickModel_rightElbow_Source->GetRadius(),
//			*(stickModel_rightUpperArm_Source->GetCenter() + 2));
//
//		RLA_JS_mapper->SetInputConnection(RLA_JS->GetOutputPort());
//
//		RLA_JS_Transform->SetInput(stickModel_rightUpperArm_Transform);
//
//		RLA_JS_actor->SetUserTransform(RLA_JS_Transform);
//		RLA_JS_actor->SetMapper(RLA_JS_mapper);
//		RLA_JS_actor->GetProperty()->SetOpacity(0.5);
//		RLA_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//			//LUA JS
//		LUA_JS->SetRadius(SphereRadius);
//		LUA_JS->SetThetaResolution(50);
//		LUA_JS->SetPhiResolution(50);
//		LUA_JS->SetCenter(*(stickModel_chest_3_Source->GetCenter()) + stickModel_chest_3_Source->GetRadius() + stickModel_leftShoulderJoint_Source->GetRadius(),
//			*(stickModel_chest_3_Source->GetCenter() + 1) - 1.0,
//			*(stickModel_chest_3_Source->GetCenter() + 2));
//
//		LUA_JS_mapper->SetInputConnection(LUA_JS->GetOutputPort());
//
//		LUA_JS_Transform->SetInput(stickModel_chest_3_Transform);
//
//		LUA_JS_actor->SetMapper(LUA_JS_mapper);
//		LUA_JS_actor->GetProperty()->SetOpacity(0.5);
//		LUA_JS_actor->SetUserTransform(LUA_JS_Transform);
//
//		LUA_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//		//LLA JS
//		LLA_JS->SetRadius(SphereRadius);
//		LLA_JS->SetThetaResolution(50);
//		LLA_JS->SetPhiResolution(50);
//		LLA_JS->SetCenter(*(stickModel_leftUpperArm_Source->GetCenter()),
//			*(stickModel_leftUpperArm_Source->GetCenter() + 1) - (stickModel_leftUpperArm_Source->GetHeight() / 2) - stickModel_leftElbow_Source->GetRadius(),
//			*(stickModel_leftUpperArm_Source->GetCenter() + 2));
//
//		LLA_JS_mapper->SetInputConnection(LLA_JS->GetOutputPort());
//
//		LLA_JS_Transform->SetInput(stickModel_leftUpperArm_Transform);
//
//		LLA_JS_actor->SetMapper(LLA_JS_mapper);
//		LLA_JS_actor->GetProperty()->SetOpacity(0.5);
//		LLA_JS_actor->SetUserTransform(LLA_JS_Transform);
//		LLA_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//
//		//RUL JS
//		RUL_JS->SetRadius(SphereRadius);
//		RUL_JS->SetThetaResolution(50);
//		RUL_JS->SetPhiResolution(50);
//		RUL_JS->SetCenter(*(stickModel_pelvisSource->GetCenter()) - stickModel_pelvisSource->GetRadius(),
//			*(stickModel_pelvisSource->GetCenter() + 1) - 2.0,
//			*(stickModel_pelvisSource->GetCenter() + 2));
//
//		RUL_JS_mapper->SetInputConnection(RUL_JS->GetOutputPort());
//
//		RUL_JS_Transform->SetInput(stickModel_pelvisTransform);
//
//
//		RUL_JS_actor->SetMapper(RUL_JS_mapper);
//		RUL_JS_actor->GetProperty()->SetOpacity(0.5);
//		RUL_JS_actor->SetUserTransform(RUL_JS_Transform);
//		RUL_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//		//RLL JS
//		RLL_JS->SetRadius(SphereRadius);
//		RLL_JS->SetThetaResolution(50);
//		RLL_JS->SetPhiResolution(50);
//		RLL_JS->SetCenter(*(stickModel_rightUpperLeg_Source->GetCenter()),
//			*(stickModel_rightUpperLeg_Source->GetCenter() + 1) - (stickModel_rightUpperLeg_Source->GetHeight() / 2) - stickModel_rightKnee_Source->GetRadius(),
//			*(stickModel_rightUpperLeg_Source->GetCenter() + 2));
//
//		RLL_JS_mapper->SetInputConnection(RLL_JS->GetOutputPort());
//
//		RLL_JS_Transform->SetInput(stickModel_rightUpperLeg_Transform);
//
//		RLL_JS_actor->SetMapper(RLL_JS_mapper);
//		RLL_JS_actor->GetProperty()->SetOpacity(0.5);
//		RLL_JS_actor->SetUserTransform(RLL_JS_Transform);
//		RLL_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//		//LUL JS
//		LUL_JS->SetRadius(SphereRadius);
//		LUL_JS->SetThetaResolution(50);
//		LUL_JS->SetPhiResolution(50);
//		LUL_JS->SetCenter(*(stickModel_pelvisSource->GetCenter()) + stickModel_pelvisSource->GetRadius(),
//			*(stickModel_pelvisSource->GetCenter() + 1) - 2.0,
//			*(stickModel_pelvisSource->GetCenter() + 2));
//
//		LUL_JS_mapper->SetInputConnection(LUL_JS->GetOutputPort());
//
//		LUL_JS_Transform->SetInput(stickModel_pelvisTransform);
//
//		LUL_JS_actor->SetMapper(LUL_JS_mapper);
//		LUL_JS_actor->GetProperty()->SetOpacity(0.5);
//		LUL_JS_actor->SetUserTransform(LUL_JS_Transform);
//		LUL_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//		//LLL JS
//		LLL_JS->SetRadius(SphereRadius);
//		LLL_JS->SetThetaResolution(50);
//		LLL_JS->SetPhiResolution(50);
//		LLL_JS->SetCenter(*(stickModel_leftUpperLeg_Source->GetCenter()),
//			*(stickModel_leftUpperLeg_Source->GetCenter() + 1) - (stickModel_leftUpperLeg_Source->GetHeight() / 2) - stickModel_leftKnee_Source->GetRadius(),
//			*(stickModel_leftUpperLeg_Source->GetCenter() + 2));
//
//		LLL_JS_mapper->SetInputConnection(LLL_JS->GetOutputPort());
//
//		LLL_JS_Transform->SetInput(stickModel_leftUpperLeg_Transform);
//
//		LLL_JS_actor->SetMapper(LLL_JS_mapper);
//		LLL_JS_actor->GetProperty()->SetOpacity(0.5);
//		LLL_JS_actor->SetUserTransform(LLL_JS_Transform);
//		LLL_JS_actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
//
//
//	}
//	
//
//}
//void displayRobot_Model()
//{
//	Pelvis_ObjReader->SetFileName(Pelvis_objFilename.c_str());
//	PlconeMapper->SetInputConnection(Pelvis_ObjReader->GetOutputPort());
//
//	PlconeTransform->Translate(pelvisObj_xpos, pelvisObj_ypos, pelvisObj_zpos);
//
//	PlconeActor->SetUserTransform(PlconeTransform);
//
//	PlconeActor->SetMapper(PlconeMapper);
//	PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	PlconeActor->SetScale(pelvisObj_scale);
//
//
//
//	Chest_ObjReader->SetFileName(Chest_objFilename.c_str());
//	CUconeMapper->SetInputConnection(Chest_ObjReader->GetOutputPort());
//
//	CUconeTransform->Translate(chestObj_xpos, chestObj_ypos, chestObj_zpos);
//	CUconeTransform->SetInput(PlconeTransform);
//
//	CUconeActor->SetUserTransform(CUconeTransform);
//
//	CUconeActor->SetMapper(CUconeMapper);
//	CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//	CUconeActor->SetScale(chestObj_scale);
//
//
//
//	headNeck_ObjReader->SetFileName(headNeck_objFilename.c_str());
//	Head_ObjReader_mapper->SetInputConnection(headNeck_ObjReader->GetOutputPort());
//
//	Head_ObjReader_Transform->Translate(head_NeckObj_xpos, head_NeckObj_ypos, head_NeckObj_zpos);
//	Head_ObjReader_Transform->SetInput(CUconeTransform);
//
//	Head_objActor->SetUserTransform(Head_ObjReader_Transform);
//	Head_objActor->SetMapper(Head_ObjReader_mapper);
//	Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	Head_objActor->SetScale(head_NeckObj_scale);
//
//	headTexture_reader->SetFileName(headTexture_filename);
//	// Apply the texture
//	head_texture->SetInputConnection(headTexture_reader->GetOutputPort());
//	Head_objActor->SetTexture(head_texture);
//
//
//
//
//	RUA_ObjReader->SetFileName(RUA_objFilename.c_str());
//	//RarmMapper->SetInputConnection(RUA_ObjReader->GetOutputPort());
//	RarmMapper->SetInputConnection(RUA_collide->GetOutputPort(0));
//	RarmMapper->ScalarVisibilityOff();
//	RarmTransform->Translate(ruaObj_xpos, ruaObj_ypos, ruaObj_zpos);
//	RarmTransform->SetInput(CUconeTransform);
//
//	RarmActor->SetUserTransform(RarmTransform);
//	RarmActor->SetMapper(RarmMapper);
//	RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	RarmActor->SetScale(ruaObj_scale);
//	  
//
//
//	RLA_ObjReader->SetFileName(RLA_objFilename.c_str());
//	RforearmMapper->SetInputConnection(RLA_ObjReader->GetOutputPort());
//
//	RforearmTransform->Translate(rlaObj_xpos, rlaObj_ypos, rlaObj_zpos);
//	RforearmTransform->SetInput(RarmTransform);
//
//	RforearmActor->SetUserTransform(RforearmTransform);
//
//	RforearmActor->SetMapper(RforearmMapper);
//	RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	RforearmActor->SetScale(rlaObj_scale);
//
//	ConstraintProp_sphereSource->SetCenter(0.0, 50.0, 10.0);
//	ConstraintProp_sphereSource->SetRadius(consProp_sphere_size);
//	ConstraintProp_sphereSource->SetPhiResolution(100);
//	ConstraintProp_sphereSource->SetThetaResolution(100);
//	ConstraintProp_sphere_mapper->SetInputConnection(ConstraintProp_sphereSource->GetOutputPort());
//	ConstraintProp_sphere_mapper->ScalarVisibilityOff();
//	ConstraintProp_sphere_actor->SetUserTransform(ConstraintProp_sphere_transform);
//	ConstraintProp_sphere_actor->SetMapper(ConstraintProp_sphere_mapper);
//	ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//	ConstraintProp_sphere_actor->SetScale(1);
//
//	TConstraintProp_sphereSource->SetCenter(0.0, 10.0, 10.0);
//	TConstraintProp_sphereSource->SetRadius(consProp_sphere_size);
//	TConstraintProp_sphereSource->SetPhiResolution(100);
//	TConstraintProp_sphereSource->SetThetaResolution(100);
//	TConstraintProp_sphere_mapper->SetInputConnection(TConstraintProp_sphereSource->GetOutputPort());
//	TConstraintProp_sphere_mapper->ScalarVisibilityOff();
//	TConstraintProp_sphere_actor->SetUserTransform(TConstraintProp_sphere_transform);
//	TConstraintProp_sphere_actor->SetMapper(TConstraintProp_sphere_mapper);
//	TConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());
//	TConstraintProp_sphere_actor->SetScale(1);
//
//
//	TConstraintProp_sphereSource2->SetCenter(10.0, 10.0, 10.0);
//	TConstraintProp_sphereSource2->SetRadius(consProp_sphere_size);
//	TConstraintProp_sphereSource2->SetPhiResolution(100);
//	TConstraintProp_sphereSource2->SetThetaResolution(100);
//	TConstraintProp_sphere_mapper2->SetInputConnection(TConstraintProp_sphereSource2->GetOutputPort());
//	TConstraintProp_sphere_mapper2->ScalarVisibilityOff();
//	TConstraintProp_sphere_actor2->SetUserTransform(TConstraintProp_sphere_transform2);
//	TConstraintProp_sphere_actor2->SetMapper(TConstraintProp_sphere_mapper2);
//	TConstraintProp_sphere_actor2->GetProperty()->SetColor(colors->GetColor3d("DeepSkyBlue").GetData());
//	TConstraintProp_sphere_actor2->SetScale(1);
//
//
//	TConstraintProp_sphereSource3->SetCenter(20.0, 10.0, 10.0);
//	TConstraintProp_sphereSource3->SetRadius(consProp_sphere_size);
//	TConstraintProp_sphereSource3->SetPhiResolution(100);
//	TConstraintProp_sphereSource3->SetThetaResolution(100);
//	TConstraintProp_sphere_mapper3->SetInputConnection(TConstraintProp_sphereSource3->GetOutputPort());
//	TConstraintProp_sphere_mapper3->ScalarVisibilityOff();
//	TConstraintProp_sphere_actor3->SetUserTransform(TConstraintProp_sphere_transform3);
//	TConstraintProp_sphere_actor3->SetMapper(TConstraintProp_sphere_mapper3);
//	TConstraintProp_sphere_actor3->GetProperty()->SetColor(colors->GetColor3d("Indigo").GetData());
//	TConstraintProp_sphere_actor3->SetScale(1);
//
//
//
//
//	ConstraintProp_lineSource1->SetTipLength(0);
//	ConstraintProp_lineSource1->SetTipResolution(0);
//	ConstraintProp_lineSource1->Update();
//
//	ConstraintProp_line_mapper1->SetInputData(RUA_collide->GetOutput(1));
//	ConstraintProp_line_mapper1->ScalarVisibilityOff();
//	ConstraintProp_line_transform1->Translate(-30.0, 65.25, 5);
//	ConstraintProp_line_actor1->SetMapper(ConstraintProp_line_mapper1);
//	ConstraintProp_line_actor1->SetUserTransform(ConstraintProp_line_transform1);
//	ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//	ConstraintProp_line_actor1->SetScale(50);
//
//
//
//
//
//
//	RUA_collide->SetInputConnection(0, RUA_ObjReader->GetOutputPort(0));
//	RUA_collide->SetTransform(0, RarmTransform);
//
//	RUA_collide->SetInputConnection(1, ConstraintProp_lineSource1->GetOutputPort());
//	RUA_collide->SetMatrix(1, matrix1);
//
//	RUA_collide->SetTransform(1, ConstraintProp_line_transform1);
//	RUA_collide->SetBoxTolerance(0.0);
//	RUA_collide->SetCellTolerance(0.0);
//	RUA_collide->SetNumberOfCellsPerNode(0);
//	if (contactMode == 0)
//	{
//		RUA_collide->SetCollisionModeToAllContacts();
//	}
//	else if (contactMode == 1)
//	{
//		RUA_collide->SetCollisionModeToFirstContact();
//	}
//	else
//	{
//		RUA_collide->SetCollisionModeToHalfContacts();
//	}
//	RUA_collide->GenerateScalarsOn();
//
//
//	TConstraintProp_lineSource1->SetTipLength(0);
//	TConstraintProp_lineSource1->SetTipResolution(0);
//	TConstraintProp_lineSource1->Update();
//	TConstraintProp_line_mapper1->SetInputConnection(TConstraintProp_lineSource1->GetOutputPort());
//	TConstraintProp_line_mapper1->ScalarVisibilityOff();
//	TConstraintProp_line_transform1->Translate(-30.0, 60.25, 5);
//	TConstraintProp_line_transform1->RotateZ(90);
//	TConstraintProp_line_actor1->SetMapper(TConstraintProp_line_mapper1);
//	TConstraintProp_line_actor1->SetUserTransform(TConstraintProp_line_transform1);
//	TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//	TConstraintProp_line_actor1->SetScale(50);
//
//
//	TConstraintProp_lineSource2->SetTipLength(0);
//	TConstraintProp_lineSource2->SetTipResolution(0);
//	TConstraintProp_lineSource2->Update();
//	TConstraintProp_line_mapper2->SetInputConnection(TConstraintProp_lineSource2->GetOutputPort());
//	TConstraintProp_line_mapper2->ScalarVisibilityOff();
//	TConstraintProp_line_transform2->Translate(-40.0, 60.25, 5);
//	TConstraintProp_line_transform2->RotateZ(90);
//	TConstraintProp_line_actor2->SetMapper(TConstraintProp_line_mapper2);
//	TConstraintProp_line_actor2->SetUserTransform(TConstraintProp_line_transform2);
//	TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//	TConstraintProp_line_actor2->SetScale(50);
//
//	TConstraintProp_lineSource3->SetTipLength(0);
//	TConstraintProp_lineSource3->SetTipResolution(0);
//	TConstraintProp_lineSource3->Update();
//	TConstraintProp_line_mapper3->SetInputConnection(TConstraintProp_lineSource3->GetOutputPort());
//	TConstraintProp_line_mapper3->ScalarVisibilityOff();
//	TConstraintProp_line_transform3->Translate(-50.0, 60.25, 5);
//	//TConstraintProp_line_transform3->RotateZ(90);
//	TConstraintProp_line_actor3->SetMapper(TConstraintProp_line_mapper3);
//	TConstraintProp_line_actor3->SetUserTransform(TConstraintProp_line_transform3);
//	TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//	TConstraintProp_line_actor3->SetScale(50);
//
//
//
//
//
//	RH_ObjReader->SetFileName(RH_objFilename.c_str());
//	RightHand_ObjReader_mapper->SetInputConnection(RH_ObjReader->GetOutputPort());
//
//	RightHand_ObjReader_Transform->Translate(RHObj_xpos, RHObj_ypos, RHObj_zpos);
//	RightHand_ObjReader_Transform->SetInput(RforearmTransform);
//
//	RightHand_objActor->SetUserTransform(RightHand_ObjReader_Transform);
//
//	RightHand_objActor->SetMapper(RightHand_ObjReader_mapper);
//	RightHand_objActor->RotateY(-7);
//	RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	//RightHand_objActor->SetScale(RHObj_scale);
//
//
//
//	LUA_ObjReader->SetFileName(LUA_objFilename.c_str());
//	LarmMapper->SetInputConnection(LUA_ObjReader->GetOutputPort()); 
//
//	LarmTransform->Translate(luaObj_xpos, luaObj_ypos, luaObj_zpos); //-0.25, 0.36, -0.075
//	LarmTransform->SetInput(CUconeTransform);
//
//	LarmActor->SetUserTransform(LarmTransform);
//
//	LarmActor->SetMapper(LarmMapper);
//	LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	LarmActor->SetScale(luaObj_scale);
//
//
//	LLA_ObjReader->SetFileName(LLA_objFilename.c_str());
//	LforearmMapper->SetInputConnection(LLA_ObjReader->GetOutputPort());
//	LforearmTransform->Translate(llaObj_xpos, llaObj_ypos, llaObj_zpos); //-0.2125, 0.080, -0.045
//	LforearmTransform->SetInput(LarmTransform);
//
//	LforearmActor->SetUserTransform(LforearmTransform);
//
//	LforearmActor->SetMapper(LforearmMapper);
//	LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	LforearmActor->SetScale(llaObj_scale);
//
//
//	LH_ObjReader->SetFileName(LH_objFilename.c_str());
//	LeftHand_ObjReader_mapper->SetInputConnection(LH_ObjReader->GetOutputPort());
//
//	LeftHand_ObjReader_Transform->Translate(LHObj_xpos, LHObj_ypos, LHObj_zpos);
//	LeftHand_ObjReader_Transform->SetInput(LforearmTransform);
//
//	LeftHand_objActor->SetUserTransform(LeftHand_ObjReader_Transform);
//	LeftHand_objActor->SetMapper(LeftHand_ObjReader_mapper);
//	LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	//LeftHand_objActor->SetScale(LHObj_scale);
//
//
//	RUL_ObjReader->SetFileName(RUL_objFilename.c_str());
//	RlulegMapper->SetInputConnection(RUL_ObjReader->GetOutputPort());
//
//	RlulegTransform->Translate(rulObj_xpos, rulObj_ypos, rulObj_zpos);
//	RlulegTransform->SetInput(PlconeTransform);
//
//	RlulegActor->SetUserTransform(RlulegTransform);
//
//	RlulegActor->SetMapper(RlulegMapper);
//	RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	RlulegActor->SetScale(rulObj_scale);
//
//
//
//	RLL_ObjReader->SetFileName(RLL_objFilename.c_str());
//	RllegMapper->SetInputConnection(RLL_ObjReader->GetOutputPort());
//
//	RllegTransform->Translate(rllObj_xpos, rllObj_ypos, rllObj_zpos);
//	RllegTransform->SetInput(RlulegTransform);
//
//	RllegActor->SetUserTransform(RllegTransform);
//
//	RllegActor->SetMapper(RllegMapper);
//	RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	RllegActor->SetScale(rllObj_scale);
//
//
//
//
//	RF_ObjReader->SetFileName(RF_objFilename.c_str());
//	RF_ObjReader_mapper->SetInputConnection(RF_ObjReader->GetOutputPort());
//
//	RF_ObjReader_Transform->Translate(RFObj_xpos, RFObj_ypos, RFObj_zpos);
//	RF_ObjReader_Transform->SetInput(RllegTransform);
//
//	RF_objActor->SetUserTransform(RF_ObjReader_Transform);
//
//	RF_objActor->SetMapper(RF_ObjReader_mapper);
//	RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	RF_objActor->SetScale(RFObj_scale);
//
//
//	LUL_ObjReader->SetFileName(LUL_objFilename.c_str());
//	LlulegMapper->SetInputConnection(LUL_ObjReader->GetOutputPort());
//
//	LlulegTransform->Translate(lulObj_xpos, lulObj_ypos, lulObj_zpos); //-0.055, 0.0125, -0.01
//	LlulegTransform->SetInput(PlconeTransform);
//
//	LlulegActor->SetUserTransform(LlulegTransform);
//
//	LlulegActor->SetMapper(LlulegMapper);
//	LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	LlulegActor->SetScale(lulObj_scale);
//
//
//
//	LLL_ObjReader->SetFileName(LLL_objFilename.c_str());
//	LllegMapper->SetInputConnection(LLL_ObjReader->GetOutputPort());
//
//	LllegTransform->Translate(lllObj_xpos, lllObj_ypos, lllObj_zpos);
//	LllegTransform->SetInput(LlulegTransform);
//
//	LllegActor->SetUserTransform(LllegTransform);
//
//	LllegActor->SetMapper(LllegMapper);
//	LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	LllegActor->SetScale(lllObj_scale);
//
//
//	LF_ObjReader->SetFileName(LF_objFilename.c_str());
//	LF_ObjReader_mapper->SetInputConnection(LF_ObjReader->GetOutputPort());
//
//	LF_ObjReader_Transform->Translate(LFObj_xpos, LFObj_ypos, LFObj_zpos);
//	LF_ObjReader_Transform->SetInput(LllegTransform);
//
//	LF_objActor->SetUserTransform(LF_ObjReader_Transform);
//	LF_objActor->SetMapper(LF_ObjReader_mapper);
//	LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	LF_objActor->SetScale(LFObj_scale);
//	
//
//
//	RarmTransform->RotateWXYZ(-4, 0, 0, 1);
//	LarmTransform->RotateWXYZ(4, 0, 0, 1);
//
//	//renderer->AddActor(planeActor);
//	renderer->AddActor(PlconeActor);
//	renderer->AddActor(CUconeActor);
//	renderer->AddActor(Head_objActor);
//
//	renderer->AddActor(RarmActor);
//	renderer->AddActor(RforearmActor);
//	renderer->AddActor(RightHand_objActor);
//
//	/*renderer->AddActor(ConstraintProp_sphere_actor);
//	renderer->AddActor(TConstraintProp_sphere_actor);
//	renderer->AddActor(TConstraintProp_sphere_actor2);
//	renderer->AddActor(TConstraintProp_sphere_actor3);
//	renderer->AddActor(ConstraintProp_line_actor1);
//	renderer->AddActor(TConstraintProp_line_actor1);
//	renderer->AddActor(TConstraintProp_line_actor2);
//	renderer->AddActor(TConstraintProp_line_actor3);*/
//
//	renderer->AddActor(LarmActor);
//	renderer->AddActor(LforearmActor);
//	renderer->AddActor(LeftHand_objActor);
//
//	renderer->AddActor(RlulegActor);
//	renderer->AddActor(RllegActor);
//	renderer->AddActor(RF_objActor);
//
//	renderer->AddActor(LlulegActor);
//	renderer->AddActor(LllegActor);
//	renderer->AddActor(LF_objActor);
//
//	
//
//}
//void displayStick_Model()
//{
//	// stickModel_Pelvis
//	stickModel_pelvisSource->SetRadius(5.0);
//	stickModel_pelvisSource->SetCenter(0.0, 47.875, 0.0);
//	stickModel_pelvisSource->SetPhiResolution(100);
//	stickModel_pelvisSource->SetThetaResolution(100);
//	stickModel_pelvisMapper->SetInputConnection(stickModel_pelvisSource->GetOutputPort());
//	stickModel_pelvisActor->SetUserTransform(stickModel_pelvisTransform);
//	stickModel_pelvisActor->SetMapper(stickModel_pelvisMapper);
//	stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//	
//	//stickModel_Chest 0
//	stickModel_chest_0_Source->SetRadius(2.85);
//	stickModel_chest_0_Source->SetPhiResolution(100);
//	stickModel_chest_0_Source->SetThetaResolution(100);
//	stickModel_chest_0_Source->SetCenter(*(stickModel_pelvisSource->GetCenter()),
//		*(stickModel_pelvisSource->GetCenter() + 1) + stickModel_pelvisSource->GetRadius() + stickModel_chest_0_Source->GetRadius(),
//		*(stickModel_pelvisSource->GetCenter() + 2));
//	stickModel_chest_0_Mapper->SetInputConnection(stickModel_chest_0_Source->GetOutputPort());
//	CH0_x = *(stickModel_pelvisSource->GetCenter());
//	CH0_y = *(stickModel_pelvisSource->GetCenter() + 1) ;
//	CH0_z = *(stickModel_pelvisSource->GetCenter() + 2);
//	//cout << CH0_x << "\t" << CH0_y << "\t" << CH0_z << endl;
//	stickModel_chest_0_Transform->SetInput(stickModel_pelvisTransform);
//	stickModel_chest_0_Actor->SetUserTransform(stickModel_chest_0_Transform);
//	stickModel_chest_0_Actor->SetMapper(stickModel_chest_0_Mapper);
//	stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	
//	//stickModel_chest 1
//	stickModel_chest_1_Source->SetRadius(2.85);
//	stickModel_chest_1_Source->SetPhiResolution(100);
//	stickModel_chest_1_Source->SetThetaResolution(100);
//	stickModel_chest_1_Source->SetCenter(*(stickModel_chest_0_Source->GetCenter()),
//		*(stickModel_chest_0_Source->GetCenter() + 1) + stickModel_chest_0_Source->GetRadius() + stickModel_chest_1_Source->GetRadius(),
//		*(stickModel_chest_0_Source->GetCenter() + 2));
//	CH1_x = *(stickModel_chest_0_Source->GetCenter());
//	CH1_y = *(stickModel_chest_0_Source->GetCenter() + 1);
//	CH1_z = *(stickModel_chest_0_Source->GetCenter() + 2);
//	//cout << CH1_x << "\t" << CH1_y << "\t" << CH1_z << endl;
//	stickModel_chest_1_Transform->SetInput(stickModel_chest_0_Transform);
//	stickModel_chest_1_Actor->SetUserTransform(stickModel_chest_1_Transform);
//	stickModel_chest_1_Mapper->SetInputConnection(stickModel_chest_1_Source->GetOutputPort());
//	stickModel_chest_1_Actor->SetMapper(stickModel_chest_1_Mapper);
//	stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//
//	//stickModel_chest 2
//	stickModel_chest_2_Source->SetRadius(2.85);
//	stickModel_chest_2_Source->SetPhiResolution(100);
//	stickModel_chest_2_Source->SetThetaResolution(100);
//	stickModel_chest_2_Source->SetCenter(*(stickModel_chest_1_Source->GetCenter()),
//		*(stickModel_chest_1_Source->GetCenter() + 1) + stickModel_chest_1_Source->GetRadius() + stickModel_chest_2_Source->GetRadius(),
//		*(stickModel_chest_1_Source->GetCenter() + 2));
//	//CH2_x = *(stickModel_chest_1_Source->GetCenter());
//	//CH2_y = *(stickModel_chest_1_Source->GetCenter() + 1) + stickModel_chest_1_Source->GetRadius() + stickModel_chest_2_Source->GetRadius();
//	//CH2_z = *(stickModel_chest_1_Source->GetCenter() + 2);
//	//cout << CH2_x << "\t" << CH2_y << "\t" << CH2_z << endl;*/
//	stickModel_chest_2_Transform->SetInput(stickModel_chest_1_Transform);
//	stickModel_chest_2_Actor->SetUserTransform(stickModel_chest_2_Transform);
//	stickModel_chest_2_Mapper->SetInputConnection(stickModel_chest_2_Source->GetOutputPort());
//	stickModel_chest_2_Actor->SetMapper(stickModel_chest_2_Mapper);
//	stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//
//	//stickModel_chest 3
//	stickModel_chest_3_Source->SetRadius(3.75);
//	stickModel_chest_3_Source->SetPhiResolution(100);
//	stickModel_chest_3_Source->SetThetaResolution(100);
//	stickModel_chest_3_Source->SetCenter(*(stickModel_chest_2_Source->GetCenter()),
//		*(stickModel_chest_2_Source->GetCenter() + 1) + stickModel_chest_2_Source->GetRadius() + stickModel_chest_3_Source->GetRadius(),
//		*(stickModel_chest_2_Source->GetCenter() + 2));
//	//CH3_x = *(stickModel_chest_2_Source->GetCenter());
//	//CH3_y = *(stickModel_chest_2_Source->GetCenter() + 1) + stickModel_chest_2_Source->GetRadius() + stickModel_chest_3_Source->GetRadius();
//	//CH3_z = *(stickModel_chest_2_Source->GetCenter() + 2);
//	//cout << CH3_x << "\t" << CH3_y << "\t" << CH3_z << endl;
//	stickModel_chest_3_Transform->SetInput(stickModel_chest_2_Transform);
//	stickModel_chest_3_Actor->SetUserTransform(stickModel_chest_3_Transform);
//	stickModel_chest_3_Mapper->SetInputConnection(stickModel_chest_3_Source->GetOutputPort());
//	stickModel_chest_3_Actor->SetMapper(stickModel_chest_3_Mapper);
//	stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//stickModel_head
//	stickModel_head_objFile = "humanHead1.obj";
//	const char* stickModel_headTexture_filename = "headmap.jpg";
//	stickModel_head_Reader->SetFileName(stickModel_head_objFile.c_str());
//	stickModel_head_Mapper->SetInputConnection(stickModel_head_Reader->GetOutputPort());
//
//	stickModel_head_Transform->Translate(*(stickModel_chest_3_Source->GetCenter()),
//		*(stickModel_chest_3_Source->GetCenter() + 1) + stickModel_chest_3_Source->GetRadius() + 0.05,
//		*(stickModel_chest_3_Source->GetCenter() + 2));
//	stickModel_head_Transform->SetInput(stickModel_chest_3_Transform);
//	//H_x = *(chest_3_Source->GetCenter());
//	//H_y = *(chest_3_Source->GetCenter() + 1) + chest_3_Source->GetRadius() + 0.05;
//	//H_z = *(chest_2_Source->GetCenter() + 2);
//	//cout << H_x << "\t" << H_y << "\t" << H_z << endl;
//	stickModel_head_Actor->SetUserTransform(stickModel_head_Transform);
//	stickModel_head_Actor->SetMapper(stickModel_head_Mapper);
//	stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	stickModel_head_Actor->SetScale(8);
//	stickModel_headTexture_Reader->SetFileName(headTexture_filename);
//	// Apply the texture
//	stickModel_head_Texture->SetInputConnection(stickModel_headTexture_Reader->GetOutputPort());
//	stickModel_head_Actor->SetTexture(stickModel_head_Texture);
//	
//
//	//stickModel_rightShoulderJoint
//	stickModel_rightShoulderJoint_Source->SetRadius(3.0);
//	stickModel_rightShoulderJoint_Source->SetPhiResolution(100);
//	stickModel_rightShoulderJoint_Source->SetThetaResolution(100);
//	stickModel_rightShoulderJoint_Source->SetCenter(*(stickModel_chest_3_Source->GetCenter()) - stickModel_chest_3_Source->GetRadius() - stickModel_rightShoulderJoint_Source->GetRadius(),
//		*(stickModel_chest_3_Source->GetCenter() + 1) - 1.0,
//		*(stickModel_chest_3_Source->GetCenter() + 2));
//	Shoulder_x = *(stickModel_chest_3_Source->GetCenter()) - stickModel_chest_3_Source->GetRadius() - stickModel_rightShoulderJoint_Source->GetRadius();
//	Shoulder_y = *(stickModel_chest_3_Source->GetCenter() + 1) - 1.0;
//	Shoulder_z = *(stickModel_chest_3_Source->GetCenter() + 2);
//	stickModel_rightShoulderJoint_Transform->SetInput(stickModel_chest_3_Transform);
//	stickModel_rightShoulderJoint_Actor->SetUserTransform(stickModel_rightShoulderJoint_Transform);
//	stickModel_rightShoulderJoint_Mapper->SetInputConnection(stickModel_rightShoulderJoint_Source->GetOutputPort());
//	stickModel_rightShoulderJoint_Actor->SetMapper(stickModel_rightShoulderJoint_Mapper);
//	/*stickModel_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());*/
//	//stickModel_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//	stickModel_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//	stickModel_rightShoulderJoint_Actor->GetProperty()->SetSpecular(.5);
//	stickModel_rightShoulderJoint_Actor->GetProperty()->SetSpecularPower(20);
//
//	//stickModel_rightUpperArm
//	stickModel_rightUpperArm_Source->SetRadius(1.5);
//	stickModel_rightUpperArm_Source->SetHeight(12.0);
//	stickModel_rightUpperArm_Source->SetResolution(20);
//	stickModel_rightUpperArm_Source->SetCenter(*(stickModel_rightShoulderJoint_Source->GetCenter()),
//		*(stickModel_rightShoulderJoint_Source->GetCenter() + 1) - stickModel_rightUpperArm_Source->GetHeight() / 2 - stickModel_rightShoulderJoint_Source->GetRadius(),
//		*(stickModel_rightShoulderJoint_Source->GetCenter() + 2));
//	stickModel_rightUpperArm_Mapper->SetInputConnection(stickModel_rightUpperArm_Source->GetOutputPort());
//	stickModel_rightUpperArm_Transform->SetInput(stickModel_rightShoulderJoint_Transform);
//	stickModel_rightUpperArm_Actor->SetUserTransform(stickModel_rightUpperArm_Transform);
//	stickModel_rightUpperArm_Actor->SetMapper(stickModel_rightUpperArm_Mapper);
//	stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	smUA_x = *(stickModel_rightShoulderJoint_Source->GetCenter());
//	smUA_y = *(stickModel_rightShoulderJoint_Source->GetCenter() + 1) ;
//	smUA_z = *(stickModel_rightShoulderJoint_Source->GetCenter() + 2);
//	//cout << smUA_x << "\t" << smUA_y << "\t" << smUA_y << endl;
//
//
//	//stickModel_rightElbow
//	stickModel_rightElbow_Source->SetRadius(1.5);
//	stickModel_rightElbow_Source->SetPhiResolution(100);
//	stickModel_rightElbow_Source->SetThetaResolution(100);
//	stickModel_rightElbow_Source->SetCenter(*(stickModel_rightUpperArm_Source->GetCenter()),
//		*(stickModel_rightUpperArm_Source->GetCenter() + 1) - (stickModel_rightUpperArm_Source->GetHeight() / 2) - stickModel_rightElbow_Source->GetRadius(),
//		*(stickModel_rightUpperArm_Source->GetCenter() + 2));
//	stickModel_rightElbow_Transform->SetInput(stickModel_rightUpperArm_Transform);
//	stickModel_rightElbow_Actor->SetUserTransform(stickModel_rightElbow_Transform);
//	stickModel_rightElbow_Mapper->SetInputConnection(stickModel_rightElbow_Source->GetOutputPort());
//	stickModel_rightElbow_Actor->SetMapper(stickModel_rightElbow_Mapper);
//	stickModel_rightElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	   	
//
//	//stickModel_rightLowerArm
//	stickModel_rightLowerArm_Source->SetRadius(1.5);
//	stickModel_rightLowerArm_Source->SetHeight(12.0);
//	stickModel_rightLowerArm_Source->SetResolution(20);
//	stickModel_rightLowerArm_Source->SetCenter(*(stickModel_rightElbow_Source->GetCenter()),
//		*(stickModel_rightElbow_Source->GetCenter() + 1) - stickModel_rightLowerArm_Source->GetHeight() / 2 - stickModel_rightElbow_Source->GetRadius(),
//		*(stickModel_rightElbow_Source->GetCenter() + 2));
//	stickModel_rightLowerArm_Mapper->SetInputConnection(stickModel_rightLowerArm_Source->GetOutputPort());
//	stickModel_rightLowerArm_Transform->SetInput(stickModel_rightElbow_Transform);
//	stickModel_rightLowerArm_Actor->SetUserTransform(stickModel_rightLowerArm_Transform);
//	stickModel_rightLowerArm_Actor->SetMapper(stickModel_rightLowerArm_Mapper);
//	stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	smLA_x = *(stickModel_rightElbow_Source->GetCenter());
//	smLA_y = *(stickModel_rightElbow_Source->GetCenter() + 1) ;
//	smLA_z = *(stickModel_rightElbow_Source->GetCenter() + 2);
//	//cout << smLA_x << "\t" << smLA_y << "\t" << smLA_y << endl;
//
//
//	//stickModel_rightHand
//	stickModel_rightHand_objFile = "RH_G.obj";
//	stickModel_rightHand_Reader->SetFileName(stickModel_rightHand_objFile.c_str());
//	stickModel_rightHand_Mapper->SetInputConnection(stickModel_rightHand_Reader->GetOutputPort());
//	stickModel_rightHand_Transform->Translate(*(stickModel_rightLowerArm_Source->GetCenter()),
//		*(stickModel_rightLowerArm_Source->GetCenter() + 1) - stickModel_rightLowerArm_Source->GetHeight() / 2,
//		*(stickModel_rightLowerArm_Source->GetCenter() + 2));
//	smH_x = *(stickModel_rightLowerArm_Source->GetCenter());
//	smH_y = *(stickModel_rightLowerArm_Source->GetCenter() + 1) - stickModel_rightLowerArm_Source->GetHeight() / 2;
//	smH_z = *(stickModel_rightLowerArm_Source->GetCenter() + 2);
//	cout << smH_x << "\t" << smH_y << "\t" << smH_z << endl;
//	stickModel_rightHand_Transform->SetInput(stickModel_rightLowerArm_Transform);
//	stickModel_rightHand_Actor->SetUserTransform(stickModel_rightHand_Transform);
//	stickModel_rightHand_Actor->SetMapper(stickModel_rightHand_Mapper);
//	//stickModel_rightHand_Actor->RotateY(-7);
//	stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	stickModel_rightHand_Actor->SetScale(0.95);
//
//
//
//	//stickModel_leftShoulderJoint
//	stickModel_leftShoulderJoint_Source->SetRadius(3.0);
//	stickModel_leftShoulderJoint_Source->SetPhiResolution(100);
//	stickModel_leftShoulderJoint_Source->SetThetaResolution(100);
//	stickModel_leftShoulderJoint_Source->SetCenter(*(stickModel_chest_3_Source->GetCenter()) + stickModel_chest_3_Source->GetRadius() + stickModel_leftShoulderJoint_Source->GetRadius(),
//		*(stickModel_chest_3_Source->GetCenter() + 1) - 1.0,
//		*(stickModel_chest_3_Source->GetCenter() + 2));
//	stickModel_leftShoulderJoint_Transform->SetInput(stickModel_chest_3_Transform);
//	stickModel_leftShoulderJoint_Actor->SetUserTransform(stickModel_leftShoulderJoint_Transform);
//	stickModel_leftShoulderJoint_Mapper->SetInputConnection(stickModel_leftShoulderJoint_Source->GetOutputPort());
//	stickModel_leftShoulderJoint_Actor->SetMapper(stickModel_leftShoulderJoint_Mapper);
//	stickModel_leftShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//stickModel_leftUpperArm
//	stickModel_leftUpperArm_Source->SetRadius(1.5);
//	stickModel_leftUpperArm_Source->SetHeight(12.0);
//	stickModel_leftUpperArm_Source->SetResolution(20);
//	stickModel_leftUpperArm_Source->SetCenter(*(stickModel_leftShoulderJoint_Source->GetCenter()),
//		*(stickModel_leftShoulderJoint_Source->GetCenter() + 1) - stickModel_leftUpperArm_Source->GetHeight() / 2 - stickModel_leftShoulderJoint_Source->GetRadius(),
//		*(stickModel_leftShoulderJoint_Source->GetCenter() + 2));
//	stickModel_leftUpperArm_Mapper->SetInputConnection(stickModel_leftUpperArm_Source->GetOutputPort());
//	stickModel_leftUpperArm_Transform->SetInput(stickModel_leftShoulderJoint_Transform);
//	stickModel_leftUpperArm_Actor->SetUserTransform(stickModel_leftUpperArm_Transform);
//	stickModel_leftUpperArm_Actor->SetMapper(stickModel_leftUpperArm_Mapper);
//	stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	
//
//	//stickModel_leftElbow
//	stickModel_leftElbow_Source->SetRadius(1.5);
//	stickModel_leftElbow_Source->SetPhiResolution(100);
//	stickModel_leftElbow_Source->SetThetaResolution(100);
//	stickModel_leftElbow_Source->SetCenter(*(stickModel_leftUpperArm_Source->GetCenter()),
//		*(stickModel_leftUpperArm_Source->GetCenter() + 1) - (stickModel_leftUpperArm_Source->GetHeight() / 2) - stickModel_leftElbow_Source->GetRadius(),
//		*(stickModel_leftUpperArm_Source->GetCenter() + 2));
//	stickModel_leftElbow_Transform->SetInput(stickModel_leftUpperArm_Transform);
//	stickModel_leftElbow_Actor->SetUserTransform(stickModel_leftElbow_Transform);
//	stickModel_leftElbow_Mapper->SetInputConnection(stickModel_leftElbow_Source->GetOutputPort());
//	stickModel_leftElbow_Actor->SetMapper(stickModel_leftElbow_Mapper);
//	stickModel_leftElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//stickModel_leftLowerArm
//	stickModel_leftLowerArm_Source->SetRadius(1.5);
//	stickModel_leftLowerArm_Source->SetHeight(12.0);
//	stickModel_leftLowerArm_Source->SetResolution(20);
//	stickModel_leftLowerArm_Source->SetCenter(*(stickModel_leftElbow_Source->GetCenter()),
//		*(stickModel_leftElbow_Source->GetCenter() + 1) - stickModel_leftLowerArm_Source->GetHeight() / 2 - stickModel_leftElbow_Source->GetRadius(),
//		*(stickModel_leftElbow_Source->GetCenter() + 2));
//	stickModel_leftLowerArm_Mapper->SetInputConnection(stickModel_leftLowerArm_Source->GetOutputPort());
//	stickModel_leftLowerArm_Transform->SetInput(stickModel_leftElbow_Transform);
//	stickModel_leftLowerArm_Actor->SetUserTransform(stickModel_leftLowerArm_Transform);
//	stickModel_leftLowerArm_Actor->SetMapper(stickModel_leftLowerArm_Mapper);
//	stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//
//	//stickModel_leftHand
//	stickModel_leftHand_objFile = "LH_G.obj";
//	stickModel_leftHand_Reader->SetFileName(stickModel_leftHand_objFile.c_str());
//	stickModel_leftHand_Mapper->SetInputConnection(stickModel_leftHand_Reader->GetOutputPort());
//	stickModel_leftHand_Transform->Translate(*(stickModel_leftLowerArm_Source->GetCenter()), *(stickModel_leftLowerArm_Source->GetCenter() + 1) - stickModel_leftLowerArm_Source->GetHeight() / 2 - 0.03, *(stickModel_leftLowerArm_Source->GetCenter() + 2) - 0.05);
//	stickModel_leftHand_Transform->SetInput(stickModel_leftLowerArm_Transform);
//	stickModel_leftHand_Actor->SetUserTransform(stickModel_leftHand_Transform);
//	stickModel_leftHand_Actor->SetMapper(stickModel_leftHand_Mapper);
//	//stickModel_leftHand_Actor->RotateY(-7);
//	stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	stickModel_leftHand_Actor->SetScale(0.95);
//
//
//	//stickModel_rightLegJoint
//	stickModel_rightLegJoint_Source->SetRadius(2.75);
//	stickModel_rightLegJoint_Source->SetPhiResolution(100);
//	stickModel_rightLegJoint_Source->SetThetaResolution(100);
//	stickModel_rightLegJoint_Source->SetCenter(*(stickModel_pelvisSource->GetCenter()) - stickModel_pelvisSource->GetRadius(),
//		*(stickModel_pelvisSource->GetCenter() + 1) - 2.0,
//		*(stickModel_pelvisSource->GetCenter() + 2));
//	stickModel_rightLegJoint_Transform->SetInput(stickModel_pelvisTransform);
//	stickModel_rightLegJoint_Actor->SetUserTransform(stickModel_rightLegJoint_Transform);
//	stickModel_rightLegJoint_Mapper->SetInputConnection(stickModel_rightLegJoint_Source->GetOutputPort());
//	stickModel_rightLegJoint_Actor->SetMapper(stickModel_rightLegJoint_Mapper);
//	stickModel_rightLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//stickModel_rightUpperLeg
//	stickModel_rightUpperLeg_Source->SetRadius(1.5);
//	stickModel_rightUpperLeg_Source->SetHeight(17.0);
//	stickModel_rightUpperLeg_Source->SetResolution(20);
//	stickModel_rightUpperLeg_Source->SetCenter(*(stickModel_rightLegJoint_Source->GetCenter()),
//		*(stickModel_rightLegJoint_Source->GetCenter() + 1) - stickModel_rightUpperLeg_Source->GetHeight() / 2 - stickModel_rightLegJoint_Source->GetRadius(),
//		*(stickModel_rightLegJoint_Source->GetCenter() + 2));
//	smUL_x = *(stickModel_rightLegJoint_Source->GetCenter());
//	smUL_y = *(stickModel_rightLegJoint_Source->GetCenter() + 1);
//	smUL_z = *(stickModel_rightLegJoint_Source->GetCenter() + 2);
//	//cout << smUL_x << "\t" << smUL_y << "\t" << smUL_z << endl;
//	stickModel_rightUpperLeg_Mapper->SetInputConnection(stickModel_rightUpperLeg_Source->GetOutputPort());
//	stickModel_rightUpperLeg_Transform->SetInput(stickModel_rightLegJoint_Transform);
//	stickModel_rightUpperLeg_Actor->SetUserTransform(stickModel_rightUpperLeg_Transform);
//	stickModel_rightUpperLeg_Actor->SetMapper(stickModel_rightUpperLeg_Mapper);
//	stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//
//	//stickModel_rightKnee
//	stickModel_rightKnee_Source->SetRadius(1.5);
//	stickModel_rightKnee_Source->SetPhiResolution(100);
//	stickModel_rightKnee_Source->SetThetaResolution(100);
//	stickModel_rightKnee_Source->SetCenter(*(stickModel_rightUpperLeg_Source->GetCenter()),
//		*(stickModel_rightUpperLeg_Source->GetCenter() + 1) - (stickModel_rightUpperLeg_Source->GetHeight() / 2) - stickModel_rightKnee_Source->GetRadius(),
//		*(stickModel_rightUpperLeg_Source->GetCenter() + 2));
//	stickModel_rightKnee_Transform->SetInput(stickModel_rightUpperLeg_Transform);
//	stickModel_rightKnee_Actor->SetUserTransform(stickModel_rightKnee_Transform);
//	stickModel_rightKnee_Mapper->SetInputConnection(stickModel_rightKnee_Source->GetOutputPort());
//	stickModel_rightKnee_Actor->SetMapper(stickModel_rightKnee_Mapper);
//	stickModel_rightKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//stickModel_rightLowerLeg
//	stickModel_rightLowerLeg_Source->SetRadius(1.5);
//	stickModel_rightLowerLeg_Source->SetHeight(16.0);
//	stickModel_rightLowerLeg_Source->SetResolution(20);
//	stickModel_rightLowerLeg_Source->SetCenter(*(stickModel_rightKnee_Source->GetCenter()),
//		*(stickModel_rightKnee_Source->GetCenter() + 1) - stickModel_rightLowerLeg_Source->GetHeight() / 2 - stickModel_rightKnee_Source->GetRadius(),
//		*(stickModel_rightKnee_Source->GetCenter() + 2));
//
//	smLL_x = *(stickModel_rightKnee_Source->GetCenter());
//	smLL_y = *(stickModel_rightKnee_Source->GetCenter() + 1) ;
//	smLL_z = *(stickModel_rightKnee_Source->GetCenter() + 2);
//	//cout << smLL_x << "\t" << smLL_y << "\t" << smLL_z << endl;
//
//	stickModel_rightLowerLeg_Mapper->SetInputConnection(stickModel_rightLowerLeg_Source->GetOutputPort());
//	stickModel_rightLowerLeg_Transform->SetInput(stickModel_rightKnee_Transform);
//	stickModel_rightLowerLeg_Actor->SetUserTransform(stickModel_rightLowerLeg_Transform);
//	stickModel_rightLowerLeg_Actor->SetMapper(stickModel_rightLowerLeg_Mapper);
//	stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	
//
//	// stickModel_rightFoot
//	stickModel_rightFoot_objFile = "RF.obj";
//	stickModel_rightFoot_Reader->SetFileName(stickModel_rightFoot_objFile.c_str());
//	stickModel_rightFoot_Mapper->SetInputConnection(stickModel_rightFoot_Reader->GetOutputPort());
//	stickModel_rightFoot_Transform->Translate(*(stickModel_rightLowerLeg_Source->GetCenter()),
//		*(stickModel_rightLowerLeg_Source->GetCenter() + 1) - stickModel_rightLowerLeg_Source->GetHeight() / 2,
//		*(stickModel_rightLowerLeg_Source->GetCenter() + 2));
//	smF_x = *(stickModel_rightLowerLeg_Source->GetCenter());
//	smF_y = *(stickModel_rightLowerLeg_Source->GetCenter() + 1) - stickModel_rightLowerLeg_Source->GetHeight() / 2;
//	smF_z = *(stickModel_rightLowerLeg_Source->GetCenter() + 2);
//	//cout << rFx << "\t" << rFy << "\t" << rFz << endl;
//	stickModel_rightFoot_Transform->SetInput(stickModel_rightLowerLeg_Transform);
//	stickModel_rightFoot_Actor->SetUserTransform(stickModel_rightFoot_Transform);
//	stickModel_rightFoot_Actor->SetMapper(stickModel_rightFoot_Mapper);
//	stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	stickModel_rightFoot_Actor->SetScale(50.0);
//
//	//stickModel_leftLegJoint
//	stickModel_leftLegJoint_Source->SetRadius(2.75);
//	stickModel_leftLegJoint_Source->SetPhiResolution(100);
//	stickModel_leftLegJoint_Source->SetThetaResolution(100);
//	stickModel_leftLegJoint_Source->SetCenter(*(stickModel_pelvisSource->GetCenter()) + stickModel_pelvisSource->GetRadius(),
//		*(stickModel_pelvisSource->GetCenter() + 1) - 2.0,
//		*(stickModel_pelvisSource->GetCenter() + 2));
//
//	stickModel_leftLegJoint_Transform->SetInput(stickModel_pelvisTransform);
//	stickModel_leftLegJoint_Actor->SetUserTransform(stickModel_leftLegJoint_Transform);
//	stickModel_leftLegJoint_Mapper->SetInputConnection(stickModel_leftLegJoint_Source->GetOutputPort());
//	stickModel_leftLegJoint_Actor->SetMapper(stickModel_leftLegJoint_Mapper);
//	stickModel_leftLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//stickModel_leftUpperLeg
//	stickModel_leftUpperLeg_Source->SetRadius(1.5);
//	stickModel_leftUpperLeg_Source->SetHeight(17.0);
//	stickModel_leftUpperLeg_Source->SetResolution(20);
//	stickModel_leftUpperLeg_Source->SetCenter(*(stickModel_leftLegJoint_Source->GetCenter()),
//		*(stickModel_leftLegJoint_Source->GetCenter() + 1) - stickModel_leftUpperLeg_Source->GetHeight() / 2 - stickModel_leftLegJoint_Source->GetRadius(),
//		*(stickModel_leftLegJoint_Source->GetCenter() + 2));
//	stickModel_leftUpperLeg_Mapper->SetInputConnection(stickModel_leftUpperLeg_Source->GetOutputPort());
//	stickModel_leftUpperLeg_Transform->SetInput(stickModel_leftLegJoint_Transform);
//	stickModel_leftUpperLeg_Actor->SetUserTransform(stickModel_leftUpperLeg_Transform);
//	stickModel_leftUpperLeg_Actor->SetMapper(stickModel_leftUpperLeg_Mapper);
//	stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//stickModel_leftKnee
//	stickModel_leftKnee_Source->SetRadius(1.5);
//	stickModel_leftKnee_Source->SetPhiResolution(100);
//	stickModel_leftKnee_Source->SetThetaResolution(100);
//	stickModel_leftKnee_Source->SetCenter(*(stickModel_leftUpperLeg_Source->GetCenter()),
//		*(stickModel_leftUpperLeg_Source->GetCenter() + 1) - (stickModel_leftUpperLeg_Source->GetHeight() / 2) - stickModel_leftKnee_Source->GetRadius(),
//		*(stickModel_leftUpperLeg_Source->GetCenter() + 2));
//	stickModel_leftKnee_Transform->SetInput(stickModel_leftUpperLeg_Transform);
//	stickModel_leftKnee_Actor->SetUserTransform(stickModel_leftKnee_Transform);
//	stickModel_leftKnee_Mapper->SetInputConnection(stickModel_leftKnee_Source->GetOutputPort());
//	stickModel_leftKnee_Actor->SetMapper(stickModel_leftKnee_Mapper);
//	stickModel_leftKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//stickModel_leftLowerleg
//	stickModel_leftLowerLeg_Source->SetRadius(1.5);
//	stickModel_leftLowerLeg_Source->SetHeight(16.0);
//	stickModel_leftLowerLeg_Source->SetResolution(20);
//	stickModel_leftLowerLeg_Source->SetCenter(*(stickModel_leftKnee_Source->GetCenter()),
//		*(stickModel_leftKnee_Source->GetCenter() + 1) - stickModel_leftLowerLeg_Source->GetHeight() / 2 - stickModel_leftKnee_Source->GetRadius(),
//		*(stickModel_leftKnee_Source->GetCenter() + 2));
//	stickModel_leftLowerLeg_Mapper->SetInputConnection(stickModel_leftLowerLeg_Source->GetOutputPort());
//	stickModel_leftLowerLeg_Transform->SetInput(stickModel_leftKnee_Transform);
//	stickModel_leftLowerLeg_Actor->SetUserTransform(stickModel_leftLowerLeg_Transform);
//	stickModel_leftLowerLeg_Actor->SetMapper(stickModel_leftLowerLeg_Mapper);
//	stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	// stickModel_leftFoot
//	stickModel_leftFoot_objFile = "LF.obj";
//	stickModel_leftFoot_Reader->SetFileName(stickModel_leftFoot_objFile.c_str());
//	stickModel_leftFoot_Mapper->SetInputConnection(stickModel_leftFoot_Reader->GetOutputPort());
//	stickModel_leftFoot_Transform->Translate(*(stickModel_leftLowerLeg_Source->GetCenter()),
//		*(stickModel_leftLowerLeg_Source->GetCenter() + 1) - stickModel_leftLowerLeg_Source->GetHeight() / 2,
//		*(stickModel_leftLowerLeg_Source->GetCenter() + 2));
//	stickModel_leftFoot_Transform->SetInput(stickModel_leftLowerLeg_Transform);
//	stickModel_leftFoot_Actor->SetUserTransform(stickModel_leftFoot_Transform);
//	stickModel_leftFoot_Actor->SetMapper(stickModel_leftFoot_Mapper);
//	stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	stickModel_leftFoot_Actor->SetScale(50.0);
//	
//	
//	stickModel_rightShoulderJoint_Transform->Identity();
//	stickModel_rightShoulderJoint_Transform->Translate(Shoulder_x, Shoulder_y, 0);
//	stickModel_rightShoulderJoint_Transform->RotateWXYZ(-8, 0, 0,1);
//	stickModel_rightShoulderJoint_Transform->Translate(-Shoulder_x, -Shoulder_y, 0);
//
//
//	stickModel_leftShoulderJoint_Transform->Identity();
//	stickModel_leftShoulderJoint_Transform->Translate(-Shoulder_x, Shoulder_y, 0);
//	stickModel_leftShoulderJoint_Transform->RotateWXYZ(8, 0, 0, 1);
//	stickModel_leftShoulderJoint_Transform->Translate(Shoulder_x, -Shoulder_y, 0);
//
//	   	  
//	renderer->AddActor(stickModel_pelvisActor);
//
//	renderer->AddActor(stickModel_chest_0_Actor);
//	renderer->AddActor(stickModel_chest_1_Actor);
//	renderer->AddActor(stickModel_chest_2_Actor);
//	renderer->AddActor(stickModel_chest_3_Actor);
//
//	renderer->AddActor(stickModel_head_Actor);
//
//	renderer->AddActor(stickModel_rightShoulderJoint_Actor);
//	renderer->AddActor(stickModel_rightUpperArm_Actor);
//	renderer->AddActor(stickModel_rightElbow_Actor);
//	renderer->AddActor(stickModel_rightLowerArm_Actor);
//	//renderer->AddActor(stickModel_rightHand_Actor);
//
//	renderer->AddActor(stickModel_leftShoulderJoint_Actor);
//	renderer->AddActor(stickModel_leftUpperArm_Actor);
//	renderer->AddActor(stickModel_leftElbow_Actor);
//	renderer->AddActor(stickModel_leftLowerArm_Actor);
//	//renderer->AddActor(stickModel_leftHand_Actor);
//
//	renderer->AddActor(stickModel_rightLegJoint_Actor);
//	renderer->AddActor(stickModel_rightUpperLeg_Actor);
//	renderer->AddActor(stickModel_rightKnee_Actor);
//	renderer->AddActor(stickModel_rightLowerLeg_Actor);
//	renderer->AddActor(stickModel_rightFoot_Actor);
//
//	renderer->AddActor(stickModel_leftLegJoint_Actor);
//	renderer->AddActor(stickModel_leftUpperLeg_Actor);
//	renderer->AddActor(stickModel_leftKnee_Actor);
//	renderer->AddActor(stickModel_leftLowerLeg_Actor);
//	renderer->AddActor(stickModel_leftFoot_Actor);
//
//	renderWindow->Render();
//
//}
//
//void EventQtSlotConnect::selectModel(int ID)
//{
//
//	if (ID == 0)
//	{
//		cout << "Scene Cleared" << endl;
//		renderer->RemoveActor(PlconeActor);
//		renderer->RemoveActor(CUconeActor);
//		renderer->RemoveActor(Head_objActor);
//
//		renderer->RemoveActor(RarmActor);
//		renderer->RemoveActor(RforearmActor);
//		renderer->RemoveActor(RightHand_objActor);
//
//
//		renderer->RemoveActor(LarmActor);
//		renderer->RemoveActor(LforearmActor);
//		renderer->RemoveActor(LeftHand_objActor);
//
//
//		renderer->RemoveActor(RlulegActor);
//		renderer->RemoveActor(RllegActor);
//		renderer->RemoveActor(RF_objActor);
//
//		renderer->RemoveActor(LlulegActor);
//		renderer->RemoveActor(LllegActor);
//		renderer->RemoveActor(LF_objActor);
//
//
//		renderer->RemoveActor(stickModel_pelvisActor);
//
//		renderer->RemoveActor(stickModel_chest_0_Actor);
//		renderer->RemoveActor(stickModel_chest_1_Actor);
//		renderer->RemoveActor(stickModel_chest_2_Actor);
//		renderer->RemoveActor(stickModel_chest_3_Actor);
//
//		renderer->RemoveActor(stickModel_head_Actor);
//
//		renderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperArm_Actor);
//		renderer->RemoveActor(stickModel_rightElbow_Actor);
//		renderer->RemoveActor(stickModel_rightLowerArm_Actor);
//		renderer->RemoveActor(stickModel_rightHand_Actor);
//
//		renderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperArm_Actor);
//		renderer->RemoveActor(stickModel_leftElbow_Actor);
//		renderer->RemoveActor(stickModel_leftLowerArm_Actor);
//		renderer->RemoveActor(stickModel_leftHand_Actor);
//
//		renderer->RemoveActor(stickModel_rightLegJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_rightKnee_Actor);
//		renderer->RemoveActor(stickModel_rightLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_rightFoot_Actor);
//
//		renderer->RemoveActor(stickModel_leftLegJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_leftKnee_Actor);
//		renderer->RemoveActor(stickModel_leftLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_leftFoot_Actor);
//
//
//		renderer->AddActor(none_xaxis_actor);
//		renderer->AddActor(none_yaxis_actor);
//		renderer->AddActor(none_zaxis_actor);
//	
//
//		this->fullbodyIK_checkBox->setChecked(0);
//		this->rhIK_checkBox->setChecked(0);
//		this->lhIK_checkBox->setChecked(0);
//		this->rfIK_checkBox->setChecked(0);
//		this->lfIK_checkBox->setChecked(0);
//
//		renderer->RemoveActor(rh_outlineActor);
//		rhIK_flag = 0;
//		renderer->RemoveActor(lh_outlineActor);
//		lhIK_flag = 0;
//		renderer->RemoveActor(rf_outlineActor);
//		rfIK_flag = 0;
//		renderer->RemoveActor(lf_outlineActor);
//		lfIK_flag = 0;
//
//
//		this->freeFoots_radioButton->setChecked(true);
//		this->fixedFoots_radioButton->setChecked(false);
//		this->fixedRF_radioButton->setChecked(false);
//		this->fixedLF_radioButton->setChecked(false);
//		this->freeFoots_radioButton->setEnabled(false);
//		this->fixedFoots_radioButton->setEnabled(false);
//		this->fixedRF_radioButton->setEnabled(false);
//		this->fixedLF_radioButton->setEnabled(false);
//
//		renderer->RemoveActor(pelvisJS_actor);
//		renderer->RemoveActor(chestJS_actor);
//		renderer->RemoveActor(LUA_JS_actor);
//		renderer->RemoveActor(LLA_JS_actor);
//		renderer->RemoveActor(RUA_JS_actor);
//		renderer->RemoveActor(RLA_JS_actor);
//		renderer->RemoveActor(LUL_JS_actor);
//		renderer->RemoveActor(LLL_JS_actor);
//		renderer->RemoveActor(RUL_JS_actor);
//		renderer->RemoveActor(RLL_JS_actor);
//
//		renderWindow->Render();
//	}
//	if (ID == 1)
//	{
//		male_biped = 1;
//		vitruvian_biped = 0;
//		skeleton_biped = 0;
//		cout << "Male Biped Selected" << endl;
//
//		Pelvis_objFilename = "Pelvis.obj";
//		Chest_objFilename = "Chest.obj";
//		headNeck_objFilename = "humanHead1.obj";
//		LUA_objFilename = "LUA.obj";
//		LLA_objFilename = "LLA.obj";
//		/*LH_objFilename = "LH.obj";*/
//		LH_objFilename = "LH_G.obj";
//		RUA_objFilename = "RUA.obj";
//		RLA_objFilename = "RLA.obj";
//		//RH_objFilename = "RH.obj";
//		RH_objFilename = "RH_G.obj";
//		LUL_objFilename = "LUL.obj";
//		LLL_objFilename = "LLL.obj";
//		LF_objFilename = "LF.obj";
//		RUL_objFilename = "RUL.obj";
//		RLL_objFilename = "RLL.obj";
//		RF_objFilename = "RF.obj";
//
//		PlconeTransform->Identity();
//		CUconeTransform->Identity();
//		Head_ObjReader_Transform->Identity();
//		RarmTransform->Identity();
//		RforearmTransform->Identity();
//		RightHand_ObjReader_Transform->Identity();
//		LarmTransform->Identity();
//		LforearmTransform->Identity();
//		LeftHand_ObjReader_Transform->Identity();
//		RlulegTransform->Identity();
//		RllegTransform->Identity();
//		RF_ObjReader_Transform->Identity();
//		LlulegTransform->Identity();
//		LllegTransform->Identity();
//		LF_ObjReader_Transform->Identity();
//
//		RUA_JS_Transform->Identity();
//		RLA_JS_Transform->Identity();
//		LUA_JS_Transform->Identity();
//		LLA_JS_Transform->Identity();
//		RUL_JS_Transform->Identity();
//		RLL_JS_Transform->Identity();
//		LUL_JS_Transform->Identity();
//		LLL_JS_Transform->Identity();
//
//		pelvisObj_xpos = 0;
//		pelvisObj_ypos = 47.875;
//		pelvisObj_zpos = 0;
//		pelvisObj_scale = 50;
//
//		chestObj_xpos = 0;
//		chestObj_ypos = 2.5;
//		chestObj_zpos = 0;
//		chestObj_scale = 50;
//
//		head_NeckObj_xpos = 0;
//		head_NeckObj_ypos = 26.0;
//		head_NeckObj_zpos = -3.0;
//		head_NeckObj_scale = 8;
//		
//
//		ruaObj_xpos = -10.5;
//		ruaObj_ypos = 20.0;
//		ruaObj_zpos = -2.5;
//		ruaObj_scale = 50;
//
//		rlaObj_xpos = 0.0;
//		rlaObj_ypos = -14.0;
//		rlaObj_zpos = 1.0;
//		rlaObj_scale = 50;
//
//		RHObj_xpos = -0.5;
//		RHObj_ypos = -12.75;
//		RHObj_zpos = 0.5;
//		RHObj_scale = 40;
//
//		luaObj_xpos = 10.50;
//		luaObj_ypos = 20.0;
//		luaObj_zpos = -2.5;
//		luaObj_scale = 50;
//
//		llaObj_xpos = 0.5;
//		llaObj_ypos = -14.0;
//		llaObj_zpos = 0.5;
//		llaObj_scale = 50;
//
//		LHObj_xpos = -0.5;
//		LHObj_ypos = -12.75;
//		LHObj_zpos = 0.5;
//		LHObj_scale = 40;
//
//
//		rulObj_xpos = -3.40;
//		rulObj_ypos = 0; //-2.125
//		rulObj_zpos = 0.0;
//		rulObj_scale = 50;
//
//		rllObj_xpos = -0.25;
//		rllObj_ypos = -21.0;
//		rllObj_zpos = 0.0;
//		rllObj_scale = 50;
//
//		RFObj_xpos = 0.7;
//		RFObj_ypos = -19.25;
//		RFObj_zpos = -2.10;
//		RFObj_scale = 50;
//		RF_xaxis_actor_Zpos = 20;
//
//		lulObj_xpos = 3.90;
//		lulObj_ypos = 0; //-2.125
//		lulObj_zpos = 0.0;
//		lulObj_scale = 50;
//
//		lllObj_xpos = 1.0;
//		lllObj_ypos = -21.0;
//		lllObj_zpos = -0.75;
//		lllObj_scale = 50;
//
//		LFObj_xpos = 0.0;
//		LFObj_ypos = -19.25;
//		LFObj_zpos = -2.10;
//		LFObj_scale = 50;
//
//
//
//		renderer->RemoveActor(stickModel_pelvisActor);
//
//		renderer->RemoveActor(stickModel_chest_0_Actor);
//		renderer->RemoveActor(stickModel_chest_1_Actor);
//		renderer->RemoveActor(stickModel_chest_2_Actor);
//		renderer->RemoveActor(stickModel_chest_3_Actor);
//
//		renderer->RemoveActor(stickModel_head_Actor);
//
//		renderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperArm_Actor);
//		renderer->RemoveActor(stickModel_rightElbow_Actor);
//		renderer->RemoveActor(stickModel_rightLowerArm_Actor);
//		renderer->RemoveActor(stickModel_rightHand_Actor);
//
//		renderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperArm_Actor);
//		renderer->RemoveActor(stickModel_leftElbow_Actor);
//		renderer->RemoveActor(stickModel_leftLowerArm_Actor);
//		renderer->RemoveActor(stickModel_leftHand_Actor);
//
//		renderer->RemoveActor(stickModel_rightLegJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_rightKnee_Actor);
//		renderer->RemoveActor(stickModel_rightLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_rightFoot_Actor);
//
//		renderer->RemoveActor(stickModel_leftLegJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_leftKnee_Actor);
//		renderer->RemoveActor(stickModel_leftLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_leftFoot_Actor);
//
//		renderer->RemoveActor(none_xaxis_actor);
//		renderer->RemoveActor(none_yaxis_actor);
//		renderer->RemoveActor(none_zaxis_actor);
//
//		this->fullbodyIK_checkBox->setChecked(0);
//		this->rhIK_checkBox->setChecked(0);
//		this->lhIK_checkBox->setChecked(0);
//		this->rfIK_checkBox->setChecked(0);
//		this->lfIK_checkBox->setChecked(0);
//
//		renderer->RemoveActor(rh_outlineActor);
//		rhIK_flag = 0;
//		renderer->RemoveActor(lh_outlineActor);
//		lhIK_flag = 0;
//		renderer->RemoveActor(rf_outlineActor);
//		rfIK_flag = 0;
//		renderer->RemoveActor(lf_outlineActor);
//		lfIK_flag = 0;
//
//		renderer->RemoveActor(pelvisJS_actor);
//		renderer->RemoveActor(chestJS_actor);
//		renderer->RemoveActor(LUA_JS_actor);
//		renderer->RemoveActor(LLA_JS_actor);
//		renderer->RemoveActor(RUA_JS_actor);
//		renderer->RemoveActor(RLA_JS_actor);
//		renderer->RemoveActor(LUL_JS_actor);
//		renderer->RemoveActor(LLL_JS_actor);
//		renderer->RemoveActor(RUL_JS_actor);
//		renderer->RemoveActor(RLL_JS_actor);
//
//
//		this->freeFoots_radioButton->setChecked(true);
//		this->fixedFoots_radioButton->setChecked(false);
//		this->fixedRF_radioButton->setChecked(false);
//		this->fixedLF_radioButton->setChecked(false);
//		this->freeFoots_radioButton->setEnabled(false);
//		this->fixedFoots_radioButton->setEnabled(false);
//		this->fixedRF_radioButton->setEnabled(false);
//		this->fixedLF_radioButton->setEnabled(false);
//
//
//		displayRobot_Model();
//		jointSpheres();
//		renderWindow->Render();
//	}
//	if (ID == 2)
//	{
//		male_biped = 0;
//		vitruvian_biped =1;
//		skeleton_biped = 0;
//
//		renderer->RemoveActor(stickModel_pelvisActor);
//
//		renderer->RemoveActor(stickModel_chest_0_Actor);
//		renderer->RemoveActor(stickModel_chest_1_Actor);
//		renderer->RemoveActor(stickModel_chest_2_Actor);
//		renderer->RemoveActor(stickModel_chest_3_Actor);
//
//		renderer->RemoveActor(stickModel_head_Actor);
//
//		renderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperArm_Actor);
//		renderer->RemoveActor(stickModel_rightElbow_Actor);
//		renderer->RemoveActor(stickModel_rightLowerArm_Actor);
//		renderer->RemoveActor(stickModel_rightHand_Actor);
//
//		renderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperArm_Actor);
//		renderer->RemoveActor(stickModel_leftElbow_Actor);
//		renderer->RemoveActor(stickModel_leftLowerArm_Actor);
//		renderer->RemoveActor(stickModel_leftHand_Actor);
//
//		renderer->RemoveActor(stickModel_rightLegJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_rightKnee_Actor);
//		renderer->RemoveActor(stickModel_rightLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_rightFoot_Actor);
//
//		renderer->RemoveActor(stickModel_leftLegJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_leftKnee_Actor);
//		renderer->RemoveActor(stickModel_leftLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_leftFoot_Actor);
//
//		renderer->RemoveActor(none_xaxis_actor);
//		renderer->RemoveActor(none_yaxis_actor);
//		renderer->RemoveActor(none_zaxis_actor);
//
//
//		renderer->RemoveActor(PlconeActor);
//		renderer->RemoveActor(CUconeActor);
//		renderer->RemoveActor(Head_objActor);
//
//		renderer->RemoveActor(RarmActor);
//		renderer->RemoveActor(RforearmActor);
//		renderer->RemoveActor(RightHand_objActor);
//
//
//		renderer->RemoveActor(LarmActor);
//		renderer->RemoveActor(LforearmActor);
//		renderer->RemoveActor(LeftHand_objActor);
//
//
//		renderer->RemoveActor(RlulegActor);
//		renderer->RemoveActor(RllegActor);
//		renderer->RemoveActor(RF_objActor);
//
//		renderer->RemoveActor(LlulegActor);
//		renderer->RemoveActor(LllegActor);
//		renderer->RemoveActor(LF_objActor);
//
//		renderer->RemoveActor(pelvisJS_actor);
//		renderer->RemoveActor(chestJS_actor);
//		renderer->RemoveActor(LUA_JS_actor);
//		renderer->RemoveActor(LLA_JS_actor);
//		renderer->RemoveActor(RUA_JS_actor);
//		renderer->RemoveActor(RLA_JS_actor);
//		renderer->RemoveActor(LUL_JS_actor);
//		renderer->RemoveActor(LLL_JS_actor);
//		renderer->RemoveActor(RUL_JS_actor);
//		renderer->RemoveActor(RLL_JS_actor);
//
//
//		vAvatar.initializeVetruvianVtkAvatar();
//		vAvatar.startVetruvianAvatar();
//		renderWindow->Render();
//	}
//	if (ID == 3)
//	{
//
//		male_biped = 0;
//		vitruvian_biped = 0;
//		skeleton_biped = 1;
//		cout << "Stick Biped Selected" << endl;
//
//
//		stickModel_pelvisTransform->Identity();
//		stickModel_chest_0_Transform->Identity();
//		stickModel_chest_1_Transform->Identity();
//		stickModel_chest_2_Transform->Identity();
//		stickModel_chest_3_Transform->Identity();
//
//		stickModel_head_Transform->Identity();
//
//		stickModel_rightShoulderJoint_Transform->Identity();
//		stickModel_rightUpperArm_Transform->Identity();
//		stickModel_rightElbow_Transform->Identity();
//		stickModel_rightLowerArm_Transform->Identity();
//		stickModel_rightHand_Transform->Identity();
//
//		stickModel_leftShoulderJoint_Transform->Identity();
//		stickModel_leftUpperArm_Transform->Identity();
//		stickModel_leftElbow_Transform->Identity();
//		stickModel_leftLowerArm_Transform->Identity();
//		stickModel_leftHand_Transform->Identity();
//
//		stickModel_rightLegJoint_Transform->Identity();
//		stickModel_rightUpperLeg_Transform->Identity();
//		stickModel_rightKnee_Transform->Identity();
//		stickModel_rightLowerLeg_Transform->Identity();
//		stickModel_rightFoot_Transform->Identity();
//
//		stickModel_leftLegJoint_Transform->Identity();
//		stickModel_leftUpperLeg_Transform->Identity();
//		stickModel_leftKnee_Transform->Identity();
//		stickModel_leftLowerLeg_Transform->Identity();
//		stickModel_leftFoot_Transform->Identity();
//		
//		RUA_JS_Transform->Identity();
//		RLA_JS_Transform->Identity();
//		LUA_JS_Transform->Identity();
//		LLA_JS_Transform->Identity();
//		RUL_JS_Transform->Identity();
//		RLL_JS_Transform->Identity();
//		LUL_JS_Transform->Identity();
//		LLL_JS_Transform->Identity();
//
//		renderer->RemoveActor(none_xaxis_actor);
//		renderer->RemoveActor(none_yaxis_actor);
//		renderer->RemoveActor(none_zaxis_actor);
//
//
//		renderer->RemoveActor(PlconeActor);
//		renderer->RemoveActor(CUconeActor);
//		renderer->RemoveActor(Head_objActor);
//
//		renderer->RemoveActor(RarmActor);
//		renderer->RemoveActor(RforearmActor);
//		renderer->RemoveActor(RightHand_objActor);
//
//
//		renderer->RemoveActor(LarmActor);
//		renderer->RemoveActor(LforearmActor);
//		renderer->RemoveActor(LeftHand_objActor);
//
//
//		renderer->RemoveActor(RlulegActor);
//		renderer->RemoveActor(RllegActor);
//		renderer->RemoveActor(RF_objActor);
//
//		renderer->RemoveActor(LlulegActor);
//		renderer->RemoveActor(LllegActor);
//		renderer->RemoveActor(LF_objActor);
//
//		renderer->RemoveActor(pelvisJS_actor);
//		renderer->RemoveActor(chestJS_actor);
//		renderer->RemoveActor(LUA_JS_actor);
//		renderer->RemoveActor(LLA_JS_actor);
//		renderer->RemoveActor(RUA_JS_actor);
//		renderer->RemoveActor(RLA_JS_actor);
//		renderer->RemoveActor(LUL_JS_actor);
//		renderer->RemoveActor(LLL_JS_actor);
//		renderer->RemoveActor(RUL_JS_actor);
//		renderer->RemoveActor(RLL_JS_actor);
//
//		this->freeFoots_radioButton->setChecked(true);
//		this->fixedFoots_radioButton->setChecked(false);
//		this->fixedRF_radioButton->setChecked(false);
//		this->fixedLF_radioButton->setChecked(false);
//		this->freeFoots_radioButton->setEnabled(true);
//		this->fixedFoots_radioButton->setEnabled(true);
//		this->fixedRF_radioButton->setEnabled(true);
//		this->fixedLF_radioButton->setEnabled(true);
//
//
//		displayStick_Model();
//		jointSpheres();
//		renderWindow->Render();
//	}
//
//}
//
//
//// ======================================== For Joint Sphere's===================================================
//
//void jointSphere_Dialog::display_all_JointSphere()
//{
//
//	if (jointSphere_ui->fb_JS_checkBox->isChecked())
//	{
//
//		renderer->AddActor(pelvisJS_actor);
//		renderer->AddActor(chestJS_actor);
//
//		renderer->AddActor(LUA_JS_actor);
//		renderer->AddActor(LLA_JS_actor);
//
//		renderer->AddActor(RUA_JS_actor);
//		renderer->AddActor(RLA_JS_actor);
//
//		renderer->AddActor(LUL_JS_actor);
//		renderer->AddActor(LLL_JS_actor);
//
//
//		renderer->AddActor(RUL_JS_actor);
//		renderer->AddActor(RLL_JS_actor);
//
//		renderWindow->Render();
//
//		jointSphere_ui->ub_JS_checkBox->setCheckable(false);
//			jointSphere_ui->rua_JS_checkBox->setCheckable(false);
//			jointSphere_ui->rla_JS_checkBox->setCheckable(false);
//			jointSphere_ui->lua_JS_checkBox->setCheckable(false);
//			jointSphere_ui->lla_JS_checkBox->setCheckable(false);
//
//		jointSphere_ui->lb_JS_checkBox->setCheckable(false);
//			jointSphere_ui->rul_JS_checkBox->setCheckable(false);
//			jointSphere_ui->rll_JS_checkBox->setCheckable(false);
//			jointSphere_ui->lul_JS_checkBox->setCheckable(false);
//			jointSphere_ui->lll_JS_checkBox->setCheckable(false);
//
//
//	}
//	if (!jointSphere_ui->fb_JS_checkBox->isChecked())
//	{
//
//		renderer->RemoveActor(pelvisJS_actor);
//		renderer->RemoveActor(chestJS_actor);
//
//		renderer->RemoveActor(LUA_JS_actor);
//		renderer->RemoveActor(LLA_JS_actor);
//
//		renderer->RemoveActor(RUA_JS_actor);
//		renderer->RemoveActor(RLA_JS_actor);
//
//		renderer->RemoveActor(LUL_JS_actor);
//		renderer->RemoveActor(LLL_JS_actor);
//
//
//		renderer->RemoveActor(RUL_JS_actor);
//		renderer->RemoveActor(RLL_JS_actor);
//
//		renderWindow->Render();
//
//		jointSphere_ui->ub_JS_checkBox->setCheckable(true);
//			jointSphere_ui->rua_JS_checkBox->setCheckable(true);
//			jointSphere_ui->rla_JS_checkBox->setCheckable(true);
//			jointSphere_ui->lua_JS_checkBox->setCheckable(true);
//			jointSphere_ui->lla_JS_checkBox->setCheckable(true);
//
//		jointSphere_ui->lb_JS_checkBox->setCheckable(true);
//			jointSphere_ui->rul_JS_checkBox->setCheckable(true);
//			jointSphere_ui->rll_JS_checkBox->setCheckable(true);
//			jointSphere_ui->lul_JS_checkBox->setCheckable(true);
//			jointSphere_ui->lll_JS_checkBox->setCheckable(true);
//
//
//	}
//}
//void jointSphere_Dialog::ub_JointSphere()
//{
//	if (jointSphere_ui->ub_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(RUA_JS_actor);
//		renderer->AddActor(RLA_JS_actor);
//		renderer->AddActor(LUA_JS_actor);
//		renderer->AddActor(LLA_JS_actor);
//		renderWindow->Render();
//
//
//
//		jointSphere_ui->rua_JS_checkBox->setChecked(1);
//		jointSphere_ui->rla_JS_checkBox->setChecked(1);
//		jointSphere_ui->lua_JS_checkBox->setChecked(1);
//		jointSphere_ui->lla_JS_checkBox->setChecked(1);
//
//	}
//	if (!jointSphere_ui->ub_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(RUA_JS_actor);
//		renderer->RemoveActor(RLA_JS_actor);
//		renderer->RemoveActor(LUA_JS_actor);
//		renderer->RemoveActor(LLA_JS_actor);
//		renderWindow->Render();
//
//
//
//		jointSphere_ui->rua_JS_checkBox->setChecked(0);
//		jointSphere_ui->rla_JS_checkBox->setChecked(0);
//		jointSphere_ui->lua_JS_checkBox->setChecked(0);
//		jointSphere_ui->lla_JS_checkBox->setChecked(0);
//	}
//	}
//void jointSphere_Dialog::lb_JointSphere()
//{
//	if (jointSphere_ui->lb_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(RUL_JS_actor);
//		renderer->AddActor(RLL_JS_actor);
//		renderer->AddActor(LUL_JS_actor);
//		renderer->AddActor(LLL_JS_actor);
//		renderWindow->Render();
//
//		jointSphere_ui->rul_JS_checkBox->setChecked(1);
//		jointSphere_ui->rll_JS_checkBox->setChecked(1);
//		jointSphere_ui->lul_JS_checkBox->setChecked(1);
//		jointSphere_ui->lll_JS_checkBox->setChecked(1);
//
//	}
//	if (!jointSphere_ui->lb_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(RUL_JS_actor);
//		renderer->RemoveActor(RLL_JS_actor);
//		renderer->RemoveActor(LUL_JS_actor);
//		renderer->RemoveActor(LLL_JS_actor);
//		renderWindow->Render();
//
//		jointSphere_ui->rul_JS_checkBox->setChecked(0);
//		jointSphere_ui->rll_JS_checkBox->setChecked(0);
//		jointSphere_ui->lul_JS_checkBox->setChecked(0);
//		jointSphere_ui->lll_JS_checkBox->setChecked(0);
//	}
//}
//
//void jointSphere_Dialog::display_RUA_JointSphere()
//{
//	if (jointSphere_ui->rua_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(RUA_JS_actor);
//		renderWindow->Render();
//	}
//	if (!jointSphere_ui->rua_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(RUA_JS_actor);
//		renderWindow->Render();
//	}
//}
//void jointSphere_Dialog::display_RLA_JointSphere()
//{
//	if (jointSphere_ui->rla_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(RLA_JS_actor);
//		renderWindow->Render();
//	}
//	if (!jointSphere_ui->rla_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(RLA_JS_actor);
//		renderWindow->Render();
//	}
//}
//
//void jointSphere_Dialog::display_LUA_JointSphere()
//{
//	if (jointSphere_ui->lua_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(LUA_JS_actor);
//		renderWindow->Render();
//	}
//	if (!jointSphere_ui->lua_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(LUA_JS_actor);
//		renderWindow->Render();
//	}
//}
//void jointSphere_Dialog::display_LLA_JointSphere()
//{
//	if (jointSphere_ui->lla_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(LLA_JS_actor);
//		renderWindow->Render();
//	}
//	if (!jointSphere_ui->lla_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(LLA_JS_actor);
//		renderWindow->Render();
//	}
//}
//
//void jointSphere_Dialog::display_RUL_JointSphere()
//{
//	if (jointSphere_ui->rul_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(RUL_JS_actor);
//		renderWindow->Render();
//	}
//	if (!jointSphere_ui->rul_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(RUL_JS_actor);
//		renderWindow->Render();
//	}
//}
//void jointSphere_Dialog::display_RLL_JointSphere()
//{
//	if (jointSphere_ui->rll_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(RLL_JS_actor);
//		renderWindow->Render();
//	}
//	if (!jointSphere_ui->rll_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(RLL_JS_actor);
//		renderWindow->Render();
//	}
//}
//
//void jointSphere_Dialog::display_LUL_JointSphere()
//{
//	if (jointSphere_ui->lul_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(LUL_JS_actor);
//		renderWindow->Render();
//	}
//	if (!jointSphere_ui->lul_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(LUL_JS_actor);
//		renderWindow->Render();
//	}
//}
//void jointSphere_Dialog::display_LLL_JointSphere()
//{
//	if (jointSphere_ui->lll_JS_checkBox->isChecked())
//	{
//		renderer->AddActor(LLL_JS_actor);
//		renderWindow->Render();
//	}
//	if (!jointSphere_ui->lll_JS_checkBox->isChecked())
//	{
//		renderer->RemoveActor(LLL_JS_actor);
//		renderWindow->Render();
//	}
//}
//
//
//
//jointSphere_Dialog::jointSphere_Dialog(QWidget *parent)
//	: QMainWindow(parent), jointSphere_ui(new Ui::jointSphere_Dialog)
//{
//	jointSphere_ui->setupUi(this);
//
//	connect(jointSphere_ui->fb_JS_checkBox, SIGNAL(clicked()), this, SLOT(display_all_JointSphere()));
//	
//	connect(jointSphere_ui->ub_JS_checkBox, SIGNAL(clicked()), this, SLOT(ub_JointSphere()));
//	connect(jointSphere_ui->lb_JS_checkBox, SIGNAL(clicked()), this, SLOT(lb_JointSphere()));
//
//	connect(jointSphere_ui->rua_JS_checkBox, SIGNAL(clicked()), this, SLOT(display_RUA_JointSphere()));
//	connect(jointSphere_ui->rla_JS_checkBox, SIGNAL(clicked()), this, SLOT(display_RLA_JointSphere()));
//
//	connect(jointSphere_ui->lua_JS_checkBox, SIGNAL(clicked()), this, SLOT(display_LUA_JointSphere()));
//	connect(jointSphere_ui->lla_JS_checkBox, SIGNAL(clicked()), this, SLOT(display_LLA_JointSphere()));
//
//
//	connect(jointSphere_ui->rul_JS_checkBox, SIGNAL(clicked()), this, SLOT(display_RUL_JointSphere()));
//	connect(jointSphere_ui->rll_JS_checkBox, SIGNAL(clicked()), this, SLOT(display_RLL_JointSphere()));
//
//
//	connect(jointSphere_ui->lul_JS_checkBox, SIGNAL(clicked()), this, SLOT(display_LUL_JointSphere()));
//	connect(jointSphere_ui->lll_JS_checkBox, SIGNAL(clicked()), this, SLOT(display_LLL_JointSphere()));
//
//	
//}
//jointSphere_Dialog::~jointSphere_Dialog()
//{
//	delete jointSphere_ui;
//}
//void EventQtSlotConnect::jointSphereOptions()
//{
//	jointSphere_Window->show();
//}
//
////======================================================= Motion Sphere ===============================================
//
//void motionSphere_dialog::fullbodyMS_Trajectory(bool checked)
//{
//	if (checked)
//	{
//		fullbodyMS_Status = 1;
//		cout << fullbodyMS_Status << endl;
//	
//	}
//	else
//	{
//		fullbodyMS_Status = 0;
//		cout << fullbodyMS_Status << endl;
//	
//	}
//}
//motionSphere_dialog::motionSphere_dialog(QWidget *parent): QMainWindow(parent), motionSphere(new Ui::motionSphere_dialog)
//{
//	motionSphere->setupUi(this);
//
//	motionSphere->fullbodyMS_checkBox->setChecked(1);
//	connect(motionSphere->fullbodyMS_checkBox, SIGNAL(clicked(bool)), this, SLOT(fullbodyMS_Trajectory(bool)));
//	
//	
//	motionSphere_Source->SetThetaResolution(30);
//	motionSphere_Source->SetRadius(1.0);
//	motionSphere_Source->SetPhiResolution(30);
//	motionSphere_Source->Update();
//
//	imageReader.TakeReference(
//		readerFactory->CreateImageReader2(motionSphereTexture_fname));
//	imageReader->SetFileName(motionSphereTexture_fname);
//
//	motionSphere_texture->SetInputConnection(imageReader->GetOutputPort());
//
//	transformTexture->SetInputConnection(motionSphere_Source->GetOutputPort());
//	//transformTexture->SetPosition(translate);
//
//	motionSphere_Mapper->SetInputConnection(transformTexture->GetOutputPort());
//	motionSphere_Actor->SetMapper(motionSphere_Mapper);
//	motionSphere_Actor->SetTexture(motionSphere_texture);
//	motionSphere_Actor->RotateX(-90);
//	//motionSphere_Actor->RotateZ(45);
//	//motionSphere_Actor->GetProperty()->SetOpacity(0.5);
//	//motionSphere_Actor->GetProperty()->SetColor(colors->GetColor4d("MistyRose").GetData());
//
//	motionSphere_renderer->AddActor(motionSphere_Actor);
//
//	motionSphere_renderer->SetBackground(colors->GetColor3d("DimGray").GetData());
//	motionSphere_renderWindow->SetWindowName("Motion-Sphere");
//
//	//motionSphere_renderWindow->Render();
//
//
//#if VTK890
//	//motionSphere->motionSphere_qvtkWidget->setRenderWindow(motionSphere_renderWindow);
//#else
//	motionSphere->motionSphere_qvtkWidget->SetRenderWindow(motionSphere_renderWindow);
//#endif
//
//
//#if VTK890
//	//motionSphere->motionSphere_qvtkWidget->motionSphere_renderWindow()->AddRenderer(motionSphere_renderer);
//#else
//	motionSphere->motionSphere_qvtkWidget->GetRenderWindow()->AddRenderer(motionSphere_renderer);
//#endif
//
//
//	
//}
//motionSphere_dialog::~motionSphere_dialog()
//{
//	delete motionSphere;
//}
//void EventQtSlotConnect::motionSphereWindow()
//{
//	motionSphere_Window->show();
//
//
//
//}
//
//
//double ruaEuler_X[1000];
//Quaternion ruaEuler_Xquat[1024];
//void anatomicalInputs::clearEulerInputs()
//{
//	anatomicalInput_ui->PL_sp_x->clear();
//	anatomicalInput_ui->PL_sp_y->clear();
//	anatomicalInput_ui->PL_sp_z->clear();
//	anatomicalInput_ui->PL_ep_x->clear();
//	anatomicalInput_ui->PL_ep_y->clear();
//	anatomicalInput_ui->PL_ep_z->clear();
//
//	anatomicalInput_ui->CH_sp_x->clear();
//	anatomicalInput_ui->CH_sp_y->clear();
//	anatomicalInput_ui->CH_sp_z->clear();
//	anatomicalInput_ui->CH_ep_x->clear();
//	anatomicalInput_ui->CH_ep_y->clear();
//	anatomicalInput_ui->CH_ep_z->clear();
//
//
//	anatomicalInput_ui->RUA_sp_x->clear();
//	anatomicalInput_ui->RUA_sp_y->clear();
//	anatomicalInput_ui->RUA_sp_z->clear();
//	anatomicalInput_ui->RUA_ep_x->clear();
//	anatomicalInput_ui->RUA_ep_y->clear();
//	anatomicalInput_ui->RUA_ep_z->clear();
//	
//	anatomicalInput_ui->RLA_sp_x->clear();
//	anatomicalInput_ui->RLA_sp_y->clear();
//	anatomicalInput_ui->RLA_sp_z->clear();
//	anatomicalInput_ui->RLA_ep_x->clear();
//	anatomicalInput_ui->RLA_ep_y->clear();
//	anatomicalInput_ui->RLA_ep_z->clear();
//
//
//	anatomicalInput_ui->LUA_sp_x->clear();
//	anatomicalInput_ui->LUA_sp_y->clear();
//	anatomicalInput_ui->LUA_sp_z->clear();
//	anatomicalInput_ui->LUA_ep_x->clear();
//	anatomicalInput_ui->LUA_ep_y->clear();
//	anatomicalInput_ui->LUA_ep_z->clear();
//
//
//	anatomicalInput_ui->LLA_sp_x->clear();
//	anatomicalInput_ui->LLA_sp_y->clear();
//	anatomicalInput_ui->LLA_sp_z->clear();
//	anatomicalInput_ui->LLA_ep_x->clear();
//	anatomicalInput_ui->LLA_ep_y->clear();
//	anatomicalInput_ui->LLA_ep_z->clear();
//
//
//	anatomicalInput_ui->RUL_sp_x->clear();
//	anatomicalInput_ui->RUL_sp_y->clear();
//	anatomicalInput_ui->RUL_sp_z->clear();
//	anatomicalInput_ui->RUL_ep_x->clear();
//	anatomicalInput_ui->RUL_ep_y->clear();
//	anatomicalInput_ui->RUL_ep_z->clear();
//
//
//	anatomicalInput_ui->RLL_sp_x->clear();
//	anatomicalInput_ui->RLL_sp_y->clear();
//	anatomicalInput_ui->RLL_sp_z->clear();
//	anatomicalInput_ui->RLL_ep_x->clear();
//	anatomicalInput_ui->RLL_ep_y->clear();
//	anatomicalInput_ui->RLL_ep_z->clear();
//
//
//	anatomicalInput_ui->LUL_sp_x->clear();
//	anatomicalInput_ui->LUL_sp_y->clear();
//	anatomicalInput_ui->LUL_sp_z->clear();
//	anatomicalInput_ui->LUL_ep_x->clear();
//	anatomicalInput_ui->LUL_ep_y->clear();
//	anatomicalInput_ui->LUL_ep_z->clear();
//
//	anatomicalInput_ui->LLL_sp_x->clear();
//	anatomicalInput_ui->LLL_sp_y->clear();
//	anatomicalInput_ui->LLL_sp_z->clear();
//	anatomicalInput_ui->LLL_ep_x->clear();
//	anatomicalInput_ui->LLL_ep_y->clear();
//	anatomicalInput_ui->LLL_ep_z->clear();
//}
//void anatomicalInputs::getEulerInputs()
//{
//
//	QString eulerFrameCount = anatomicalInput_ui->noOf_frames->text();
//
//	QString plXsp = anatomicalInput_ui->PL_sp_x->text();
//	QString plYsp = anatomicalInput_ui->PL_sp_y->text();
//	QString plZsp = anatomicalInput_ui->PL_sp_z->text();
//	QString plXep = anatomicalInput_ui->PL_ep_x->text();
//	QString plYep = anatomicalInput_ui->PL_ep_y->text();
//	QString plZep = anatomicalInput_ui->PL_ep_z->text();
//
//	QString chXsp = anatomicalInput_ui->CH_sp_x->text();
//	QString chYsp = anatomicalInput_ui->CH_sp_y->text();
//	QString chZsp = anatomicalInput_ui->CH_sp_z->text();
//	QString chXep = anatomicalInput_ui->CH_ep_x->text();
//	QString chYep = anatomicalInput_ui->CH_ep_y->text();
//	QString chZep = anatomicalInput_ui->CH_ep_z->text();
//
//	QString ruaXsp = anatomicalInput_ui->RUA_sp_x->text();
//	QString ruaYsp = anatomicalInput_ui->RUA_sp_y->text();
//	QString ruaZsp = anatomicalInput_ui->RUA_sp_z->text();
//	QString ruaXep = anatomicalInput_ui->RUA_ep_x->text();
//	QString ruaYep = anatomicalInput_ui->RUA_ep_y->text();
//	QString ruaZep = anatomicalInput_ui->RUA_ep_z->text();
//
//	QString rlaXsp = anatomicalInput_ui->RLA_sp_x->text();
//	QString rlaYsp = anatomicalInput_ui->RLA_sp_y->text();
//	QString rlaZsp = anatomicalInput_ui->RLA_sp_z->text();
//	QString rlaXep = anatomicalInput_ui->RLA_ep_x->text();
//	QString rlaYep = anatomicalInput_ui->RLA_ep_y->text();
//	QString rlaZep = anatomicalInput_ui->RLA_ep_z->text();
//
//	QString luaXsp = anatomicalInput_ui->LUA_sp_x->text();
//	QString luaYsp = anatomicalInput_ui->LUA_sp_y->text();
//	QString luaZsp = anatomicalInput_ui->LUA_sp_z->text();
//	QString luaXep = anatomicalInput_ui->LUA_ep_x->text();
//	QString luaYep = anatomicalInput_ui->LUA_ep_y->text();
//	QString luaZep = anatomicalInput_ui->LUA_ep_z->text();
//
//	QString llaXsp = anatomicalInput_ui->LLA_sp_x->text();
//	QString llaYsp = anatomicalInput_ui->LLA_sp_y->text();
//	QString llaZsp = anatomicalInput_ui->LLA_sp_z->text();
//	QString llaXep = anatomicalInput_ui->LLA_ep_x->text();
//	QString llaYep = anatomicalInput_ui->LLA_ep_y->text();
//	QString llaZep = anatomicalInput_ui->LLA_ep_z->text();
//	   	 
//	QString rulXsp = anatomicalInput_ui->RUL_sp_x->text();
//	QString rulYsp = anatomicalInput_ui->RUL_sp_y->text();
//	QString rulZsp = anatomicalInput_ui->RUL_sp_z->text();
//	QString rulXep = anatomicalInput_ui->RUL_ep_x->text();
//	QString rulYep = anatomicalInput_ui->RUL_ep_y->text();
//	QString rulZep = anatomicalInput_ui->RUL_ep_z->text();
//
//	QString rllXsp = anatomicalInput_ui->RLL_sp_x->text();
//	QString rllYsp = anatomicalInput_ui->RLL_sp_y->text();
//	QString rllZsp = anatomicalInput_ui->RLL_sp_z->text();
//	QString rllXep = anatomicalInput_ui->RLL_ep_x->text();
//	QString rllYep = anatomicalInput_ui->RLL_ep_y->text();
//	QString rllZep = anatomicalInput_ui->RLL_ep_z->text();
//
//	QString lulXsp = anatomicalInput_ui->LUL_sp_x->text();
//	QString lulYsp = anatomicalInput_ui->LUL_sp_y->text();
//	QString lulZsp = anatomicalInput_ui->LUL_sp_z->text();
//	QString lulXep = anatomicalInput_ui->LUL_ep_x->text();
//	QString lulYep = anatomicalInput_ui->LUL_ep_y->text();
//	QString lulZep = anatomicalInput_ui->LUL_ep_z->text();
//
//	QString lllXsp = anatomicalInput_ui->LLL_sp_x->text();
//	QString lllYsp = anatomicalInput_ui->LLL_sp_y->text();
//	QString lllZsp = anatomicalInput_ui->LLL_sp_z->text();
//	QString lllXep = anatomicalInput_ui->LLL_ep_x->text();
//	QString lllYep = anatomicalInput_ui->LLL_ep_y->text();
//	QString lllZep = anatomicalInput_ui->LLL_ep_z->text();
//
//	eulerFramesCount= eulerFrameCount.toInt();
//   
//	plspX_value = plXsp.toDouble();
//	plspY_value = plYsp.toDouble();
//	plspZ_value = plZsp.toDouble();
//	plepX_value = plXep.toDouble();
//	plepY_value = plYep.toDouble();
//	plepZ_value = plZep.toDouble();
//
//	chspX_value = chXsp.toDouble();
//	chspY_value = chYsp.toDouble();
//	chspZ_value = chZsp.toDouble();
//	chepX_value = chXep.toDouble();
//	chepY_value = chYep.toDouble();
//	chepZ_value = chZep.toDouble();
//
//	ruaspX_value = ruaXsp.toDouble();
//	ruaspY_value = ruaYsp.toDouble();
//	ruaspZ_value = ruaZsp.toDouble();
//	ruaepX_value = ruaXep.toDouble();
//	ruaepY_value = ruaYep.toDouble();
//	ruaepZ_value = ruaZep.toDouble();
//
//	rlaspX_value = rlaXsp.toDouble();
//	rlaspY_value = rlaYsp.toDouble();
//	rlaspZ_value = rlaZsp.toDouble();
//	rlaepX_value = rlaXep.toDouble();
//	rlaepY_value = rlaYep.toDouble();
//	rlaepZ_value = rlaZep.toDouble();
//
//	luaspX_value = luaXsp.toDouble();
//	luaspY_value = luaYsp.toDouble();
//	luaspZ_value = luaZsp.toDouble();
//	luaepX_value = luaXep.toDouble();
//	luaepY_value = luaYep.toDouble();
//	luaepZ_value = luaZep.toDouble();
//
//	llaspX_value = llaXsp.toDouble();
//	llaspY_value = llaYsp.toDouble();
//	llaspZ_value = llaZsp.toDouble();
//	llaepX_value = llaXep.toDouble();
//	llaepY_value = llaYep.toDouble();
//	llaepZ_value = llaZep.toDouble();
//
//	rulspX_value = rulXsp.toDouble();
//	rulspY_value = rulYsp.toDouble();
//	rulspZ_value = rulZsp.toDouble();
//	rulepX_value = rulXep.toDouble();
//	rulepY_value = rulYep.toDouble();
//	rulepZ_value = rulZep.toDouble();
//
//	rllspX_value = rllXsp.toDouble();
//	rllspY_value = rllYsp.toDouble();
//	rllspZ_value = rllZsp.toDouble();
//	rllepX_value = rllXep.toDouble();
//	rllepY_value = rllYep.toDouble();
//	rllepZ_value = rllZep.toDouble();
//
//	lulspX_value = lulXsp.toDouble();
//	lulspY_value = lulYsp.toDouble();
//	lulspZ_value = lulZsp.toDouble();
//	lulepX_value = lulXep.toDouble();
//	lulepY_value = lulYep.toDouble();
//	lulepZ_value = lulZep.toDouble();
//
//	lllspX_value = lllXsp.toDouble();
//	lllspY_value = lllYsp.toDouble();
//	lllspZ_value = lllZsp.toDouble();
//	lllepX_value = lllXep.toDouble();
//	lllepY_value = lllYep.toDouble();
//	lllepZ_value = lllZep.toDouble();
//	   
//
//	cout << "====================================================" << endl;
//	cout << "Frame Count:" << eulerFramesCount << endl;
//	cout << "pelvis:" << endl;
//	cout << "sp:" << "\t" << plspX_value << "\t" << plspY_value << "\t" << plspZ_value << endl;
//	cout << "Ep:" << "\t" << plepX_value << "\t" << plepY_value << "\t" << plepZ_value << endl;
//
//	cout << "chest:" << endl;
//	cout << "sp:" << "\t" << chspX_value << "\t" << chspY_value << "\t" << chspZ_value << endl;
//	cout << "Ep:" << "\t" << chepX_value << "\t" << chepY_value << "\t" << chepZ_value << endl;
//
//	cout << "rua:" << endl;
//	cout << "sp:" << "\t" << ruaspX_value << "\t" << ruaspY_value << "\t" << ruaspZ_value << endl;
//	cout << "Ep:" << "\t" << ruaepX_value << "\t" << ruaepY_value << "\t" << ruaepZ_value << endl;
//
//	cout << "rla:" << endl;
//	cout << "sp:" << "\t" << rlaspX_value << "\t" << rlaspY_value << "\t" << rlaspZ_value << endl;
//	cout << "Ep:" << "\t" << rlaepX_value << "\t" << rlaepY_value << "\t" << rlaepZ_value << endl;
//
//	cout << "lua:" << endl;
//	cout << "sp:" << "\t" << luaspX_value << "\t" << luaspY_value << "\t" << luaspZ_value << endl;
//	cout << "Ep:" << "\t" << luaepX_value << "\t" << luaepY_value << "\t" << luaepZ_value << endl;
//
//	cout << "lla:" << endl;
//	cout << "sp:" << "\t" << llaspX_value << "\t" << llaspY_value << "\t" << llaspZ_value << endl;
//	cout << "Ep:" << "\t" << llaepX_value << "\t" << llaepY_value << "\t" << llaepZ_value << endl;
//
//	cout << "rul:" << endl;
//	cout << "sp:" << "\t" << rulspX_value << "\t" << rulspY_value << "\t" << rulspZ_value << endl;
//	cout << "Ep:" << "\t" << rulepX_value << "\t" << rulepY_value << "\t" << rulepZ_value << endl;
//
//	cout << "rll:" << endl;
//	cout << "sp:" << "\t" << rllspX_value << "\t" << rllspY_value << "\t" << rllspZ_value << endl;
//	cout << "Ep:" << "\t" << rllepX_value << "\t" << rllepY_value << "\t" << rllepZ_value << endl;
//
//
//	cout << "lul:" << endl;
//	cout << "sp:" << "\t" << lulspX_value << "\t" << lulspY_value << "\t" << lulspZ_value << endl;
//	cout << "Ep:" << "\t" << lulepX_value << "\t" << lulepY_value << "\t" << lulepZ_value << endl;
//
//	cout << "lll:" << endl;
//	cout << "sp:" << "\t" << lllspX_value << "\t" << lllspY_value << "\t" << lllspZ_value << endl;
//	cout << "Ep:" << "\t" << lllepX_value << "\t" << lllepY_value << "\t" << lllepZ_value << endl;
//	cout << "====================================================" << endl;
//
//	//=================================================================================================
//	
//
//
//	if (ruaepX_value == ruaspX_value)
//	{
//		cout << "Same";
//		for (int i = 0; i < eulerFramesCount; i++)
//		{
//			//dummyyy = ruaepX_value;
//			ruaEuler_X[i] = ruaepX_value;
//			cout << ruaEuler_X[i] << endl;
//		}
//	}
//
//	if (ruaepX_value < ruaspX_value)
//	{
//		cout << "negative";
//		double diffVal = ruaepX_value - ruaspX_value;
//		double ruaXranger = diffVal / eulerFramesCount;
//		double dummyyy = ruaspX_value;
//		for (int i = 0; i < eulerFramesCount; i++)
//		{
//			dummyyy = dummyyy + ruaXranger;
//			ruaEuler_X[i] = dummyyy;
//			cout << ruaEuler_X[i] << endl;
//		}
//	}
//
//	if (ruaepX_value > ruaspX_value)
//	{
//		cout << "Positive";
//		double diffVal = ruaspX_value - ruaepX_value;
//		double ruaXranger = diffVal / eulerFramesCount;
//		double dummyyy = ruaspX_value;
//		for (int i = 0; i < eulerFramesCount; i++)
//		{
//			dummyyy = dummyyy - ruaXranger;
//			ruaEuler_X[i] = dummyyy;
//			cout << dummyyy << endl;
//
//		}
//	}
//	for (int i = 0; i < eulerFramesCount; i++)
//	{
//
//
//		ruaEuler_Xquat[i].setW(cos(ruaEuler_X[i] * PI / 180 / 2));
//		ruaEuler_Xquat[i].setX(1* sin(ruaEuler_X[i] * PI / 180 / 2));
//		ruaEuler_Xquat[i].setY(0 * sin(ruaEuler_X[i] * PI / 180 / 2));
//		ruaEuler_Xquat[i].setZ(0 * sin(ruaEuler_X[i] * PI / 180 / 2));
//
//
//		cout << ruaEuler_Xquat[i].getW()<< "\t" << ruaEuler_Xquat[i].getX() << "\t" << ruaEuler_Xquat[i].getY() << "\t" <<
//			ruaEuler_Xquat[i].getZ()<< endl;
//	}
//
//
//}
//void EventQtSlotConnect::eulerInputsWindow()
//{
//
//	eulerInput_Window->show();
//}
//anatomicalInputs::anatomicalInputs(QWidget *parent) : QMainWindow(parent) , anatomicalInput_ui(new Ui::anatomicalInputs)
//{
//		
//	anatomicalInput_ui->setupUi(this);
//	anatomicalInput_ui->noOf_frames->setText("10");
//	connect(anatomicalInput_ui->euler_submit_Button, SIGNAL(clicked()), this, SLOT(getEulerInputs()));
//	connect(anatomicalInput_ui->euler_clear_Button, SIGNAL(clicked()), this, SLOT(clearEulerInputs()));
//
//
//	anatomicalInput_ui->PL_X_Button->setEnabled(0);
//	anatomicalInput_ui->PL_Y_Button->setEnabled(0);
//	anatomicalInput_ui->PL_Z_Button->setEnabled(0);
//	anatomicalInput_ui->PL_SP_Button->setEnabled(0);
//	anatomicalInput_ui->PL_EP_Button->setEnabled(0);
//
//	anatomicalInput_ui->CH_X_Button->setEnabled(0);
//	anatomicalInput_ui->CH_Y_Button->setEnabled(0);
//	anatomicalInput_ui->CH_Z_Button->setEnabled(0);
//	anatomicalInput_ui->CH_SP_Button->setEnabled(0);
//	anatomicalInput_ui->CH_EP_Button->setEnabled(0);
//
//	anatomicalInput_ui->RUA_X_Button->setEnabled(0);
//	anatomicalInput_ui->RUA_Y_Button->setEnabled(0);
//	anatomicalInput_ui->RUA_Z_Button->setEnabled(0);
//	anatomicalInput_ui->RUA_SP_Button->setEnabled(0);
//	anatomicalInput_ui->RUA_EP_Button->setEnabled(0);
//
//	anatomicalInput_ui->RLA_X_Button->setEnabled(0);
//	anatomicalInput_ui->RLA_Y_Button->setEnabled(0);
//	anatomicalInput_ui->RLA_Z_Button->setEnabled(0);
//	anatomicalInput_ui->RLA_SP_Button->setEnabled(0);
//	anatomicalInput_ui->RLA_EP_Button->setEnabled(0);
//
//	anatomicalInput_ui->LUA_X_Button->setEnabled(0);
//	anatomicalInput_ui->LUA_Y_Button->setEnabled(0);
//	anatomicalInput_ui->LUA_Z_Button->setEnabled(0);
//	anatomicalInput_ui->LUA_SP_Button->setEnabled(0);
//	anatomicalInput_ui->LUA_EP_Button->setEnabled(0);
//
//	anatomicalInput_ui->LLA_X_Button->setEnabled(0);
//	anatomicalInput_ui->LLA_Y_Button->setEnabled(0);
//	anatomicalInput_ui->LLA_Z_Button->setEnabled(0);
//	anatomicalInput_ui->LLA_SP_Button->setEnabled(0);
//	anatomicalInput_ui->LLA_EP_Button->setEnabled(0);
//
//	anatomicalInput_ui->RUL_X_Button->setEnabled(0);
//	anatomicalInput_ui->RUL_Y_Button->setEnabled(0);
//	anatomicalInput_ui->RUL_Z_Button->setEnabled(0);
//	anatomicalInput_ui->RUL_SP_Button->setEnabled(0);
//	anatomicalInput_ui->RUL_EP_Button->setEnabled(0);
//
//	anatomicalInput_ui->RLL_X_Button->setEnabled(0);
//	anatomicalInput_ui->RLL_Y_Button->setEnabled(0);
//	anatomicalInput_ui->RLL_Z_Button->setEnabled(0);
//	anatomicalInput_ui->RLL_SP_Button->setEnabled(0);
//	anatomicalInput_ui->RLL_EP_Button->setEnabled(0);
//
//	anatomicalInput_ui->LUL_X_Button->setEnabled(0);
//	anatomicalInput_ui->LUL_Y_Button->setEnabled(0);
//	anatomicalInput_ui->LUL_Z_Button->setEnabled(0);
//	anatomicalInput_ui->LUL_SP_Button->setEnabled(0);
//	anatomicalInput_ui->LUL_EP_Button->setEnabled(0);
//
//	anatomicalInput_ui->LLL_X_Button->setEnabled(0);
//	anatomicalInput_ui->LLL_Y_Button->setEnabled(0);
//	anatomicalInput_ui->LLL_Z_Button->setEnabled(0);
//	anatomicalInput_ui->LLL_SP_Button->setEnabled(0);
//	anatomicalInput_ui->LLL_EP_Button->setEnabled(0);
//
//
//}
//anatomicalInputs::~anatomicalInputs()
//{
//	delete anatomicalInput_ui;
//}
//
//void timerSettings_Window::updateTimer_range(int r)
//{
//	cout << r << endl;
//	timerRange = r;
//}
//timerSettings_Window::timerSettings_Window(QWidget *parent)
//	: QMainWindow(parent)
//	, timerSettings_ui(new Ui::timerSettings_Window)
//{
//	timerSettings_ui->setupUi(this);
//	timerSettings_ui->timerEnd_spinBox->setRange(0,1000);
//	timerSettings_ui->timerEnd_spinBox->setValue(100);
//
//	connect(timerSettings_ui->timerEnd_spinBox, SIGNAL(valueChanged(int)), this, SLOT(updateTimer_range(int)));
//
//}
//timerSettings_Window::~timerSettings_Window()
//{
//	delete timerSettings_ui;
//}
//void EventQtSlotConnect::timerSettingsWindow()
//{
//	timerSettings_Dialog->show();
//
//
//}
//
//
//// Constructor
//EventQtSlotConnect::EventQtSlotConnect()
//{
//  this->setupUi(this);
//
//  renderWindowInteractor->SetRenderWindow(renderWindow);
//  renderWindowInteractor->SetLightFollowCamera(1);
//
//  this->modelType->addItem("Select");
//  this->modelType->addItem("Humanoid Model");
//  this->modelType->addItem("Vitruvian Model ");
//  this->modelType->addItem("Skeletal Model");
//  connect(this->modelType, SIGNAL(currentIndexChanged(int)), this, SLOT(selectModel(int))); modelType
//
//
//  // Grid Surface - Ground 
//  planeSource->SetResolution(25, 25);
//  planeSource->SetCenter(0.0, 0.0, 0.0);
//  planeSource->SetPoint1(800, 0, 0); // 300
//  planeSource->SetPoint2(0, 800, 0); // 300
//  planeSource->Update();
// 
//
//  PlaneTransform->Translate(-400, 0.0, 400);  //(-150,0,150)
//
//  vtkSmartPointer<vtkPolyDataMapper> planeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//  planeMapper->SetInputData(planeSource->GetOutput());
//
//  vtkSmartPointer<vtkActor> planeActor = vtkSmartPointer<vtkActor>::New();
//  planeActor->SetMapper(planeMapper);
//  planeActor->GetProperty()->SetRepresentationToWireframe();
//  //PlaneTransform->RotateWXYZ(45, 0, 1, 0);
//  planeActor->SetUserTransform(PlaneTransform);
//  planeActor->RotateX(-90);
//  planeActor->GetProperty()->SetColor(colors->GetColor3d("Black").GetData());
//  planeActor->GetProperty()->SetOpacity(0.25);
//  planeActor->GetProperty()->LightingOff();
//
//  renderer->AddActor(planeActor);
//
//  sceneWidgets();
//  //renderer->AddActor(sP_actor);
//  //renderer->AddActor(fP_actor);
//  //renderer->AddActor(hP_actor);
//  renderer->AddActor(none_xaxis_actor);
//  renderer->AddActor(none_yaxis_actor);
//  renderer->AddActor(none_zaxis_actor);
//
//	Props();
//
//	textActor->SetInput(text);
//	textActor->SetPosition(875,650); //875 650
//	textActor->GetTextProperty()->SetColor(1.0, 1.0, 0.0);
//	textActor->GetTextProperty()->SetFontSize(20);
//	//renderer->AddActor2D(textActor);
//  
//  
//  renderer->SetBackground(colors->GetColor3d("DimGray").GetData()); // Gray //DimGray
//  renderWindow->Render();
//   
//  renderer->ResetCamera();
//
//  //renderer->ResetCamera();
//  //renderer->GetActiveCamera()->Elevation(5);
//  //renderer->GetActiveCamera()->Azimuth(-40);
//  //renderer->GetActiveCamera()->Zoom(1.75);
//
//
//
//#if VTK890
//  this->qvtkWidget->setRenderWindow(renderWindow);
//#else
//  this->qvtkWidget->SetRenderWindow(renderWindow);
//#endif
//   
//#if VTK890
//  this->qvtkWidget->renderWindow()->AddRenderer(renderer);
//#else
//  this->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
//#endif
//
//
//  connect(this->viewMode_Button, SIGNAL(clicked()), this, SLOT(viewing_mode()));
//  connect(this->authorMode_Button, SIGNAL(clicked()), this, SLOT(authoring_mode()));
//  connect(this->reset_Button, SIGNAL(clicked()), this, SLOT(reset()));
//
//
//  this->keyframes_Slider->setTickPosition(QSlider::TicksAbove);
//  this->keyframes_Slider->setMinimum(0);
//  this->keyframes_Slider->setMaximum(timerRange);
//  this->keyframes_Slider->setTickInterval(5);
//  this->keyframes_Slider->setSingleStep(1);
//  this->keyframes_Slider->setAutoFillBackground(1);
//  connect(this->keyframes_Slider, SIGNAL(valueChanged(int)), this, SLOT(allkeyFrames_sliderMove(int)));
//  
//  connect(this->play_Button, SIGNAL(clicked()), this, SLOT(allKeyFrames_playPause()));
//  connect(this->timerSetting_pushButton, SIGNAL(clicked()), this, SLOT(timerSettingsWindow()));
//
//  timer = new QTimer(this);
//  connect(this->timer, SIGNAL(timeout()), this, SLOT(timerFunction()));
//
//  connect(this->kfCapture_Button, SIGNAL(clicked()), this, SLOT(kf_caputre()));
//  connect(this->Generate_All_KFs_Button, SIGNAL(clicked()), this, SLOT(allKF_Slerping()));
//
//  connect(this->actionAnatomical_Inputs, SIGNAL(triggered()), this, SLOT(eulerInputsWindow()));
// 
//  connect(this->actionMotion_Sphere, SIGNAL(triggered()), this, SLOT(motionSphereWindow()));
// 
//  connect(this->actionJoint_Sphere, SIGNAL(triggered()), this, SLOT(jointSphereOptions()));
//
//  connect(this->load_srqFormat, SIGNAL(triggered()), this, SLOT(load_sensedData()));
//  connect(this->load_sfqFormat, SIGNAL(triggered()), this, SLOT(load_AuthoredData()));
//
//  connect(this->fullbodyIK_checkBox, SIGNAL(clicked(bool)), this, SLOT(enableIK(bool)));
//  connect(this->restIK_Button, SIGNAL(clicked()), this, SLOT(resetIK()));
//
//  this->freeFoots_radioButton->setChecked(true);
//  connect(this->freeFoots_radioButton, SIGNAL(clicked()), this, SLOT(enableFreeFoots()));
// 
//  connect(this->fixedFoots_radioButton, SIGNAL(clicked()), this, SLOT(enableFixedFoots()));
//  connect(this->fixedRF_radioButton, SIGNAL(clicked()), this, SLOT(fixedRightFoot()));
//  connect(this->fixedLF_radioButton, SIGNAL(clicked()), this, SLOT(fixedLeftFoot()));
//
//  connect(this->IntegrateUM, SIGNAL(triggered()), this, SLOT(Blend_unitMotions()));
//  connect(this->actionsrq_format, SIGNAL(triggered()), this, SLOT(addUMs_srq()));
//  connect(this->actionsfq_format, SIGNAL(triggered()), this, SLOT(addUMs_sfq()));
//
//  connect(this->snapShot_Button, SIGNAL(clicked()), this, SLOT(take_snapShot()));
//
//  connect(this->actionConstraint_Props, SIGNAL(triggered()), this, SLOT(propsWindow()));
//
//
//  remove("C:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/build/unitMotions/allUMs_tofile.txt");
//
//  for (int i = 0; i < 13; i++)
//  {
//
//	  qp[i].setW(1); qp[i].setX(0); qp[i].setY(0); qp[i].setZ(0);
//	  qx[i].setW(1); qx[i].setX(0); qx[i].setY(0); qx[i].setZ(0);
//	  qy[i].setW(1); qy[i].setX(0); qy[i].setY(0); qy[i].setZ(0);
//	  qz[i].setW(1); qz[i].setX(0); qz[i].setY(0); qz[i].setZ(0);
//
//	  xaxisQP[i].setW(1); xaxisQP[i].setX(0); xaxisQP[i].setY(0); xaxisQP[i].setZ(0);
//	  xaxisQX[i].setW(1); xaxisQX[i].setX(0); xaxisQX[i].setY(0); xaxisQX[i].setZ(0);
//	  xaxisQY[i].setW(1); xaxisQY[i].setX(0); xaxisQY[i].setY(0); xaxisQY[i].setZ(0);
//	  xaxisQZ[i].setW(1); xaxisQZ[i].setX(0); xaxisQZ[i].setY(0); xaxisQZ[i].setZ(0);
//
//	  yaxisQP[i].setW(1); yaxisQP[i].setX(0); zaxisQP[i].setY(0); zaxisQP[i].setZ(0);
//	  yaxisQX[i].setW(1); yaxisQX[i].setX(0); zaxisQX[i].setY(0); zaxisQX[i].setZ(0);
//	  yaxisQY[i].setW(1); yaxisQY[i].setX(0); zaxisQY[i].setY(0); zaxisQY[i].setZ(0);
//	  yaxisQZ[i].setW(1); yaxisQZ[i].setX(0); zaxisQZ[i].setY(0); zaxisQZ[i].setZ(0);
//
//	  zaxisQP[i].setW(1); zaxisQP[i].setX(0); zaxisQP[i].setY(0); zaxisQP[i].setZ(0);
//	  zaxisQX[i].setW(1); zaxisQX[i].setX(0); zaxisQX[i].setY(0); zaxisQX[i].setZ(0);
//	  zaxisQY[i].setW(1); zaxisQY[i].setX(0); zaxisQY[i].setY(0); zaxisQY[i].setZ(0);
//	  zaxisQZ[i].setW(1); zaxisQZ[i].setX(0); zaxisQZ[i].setY(0); zaxisQZ[i].setZ(0);
//
//	  // For Inverse kinematics 
//	  qpIK[i].setW(1); qpIK[i].setX(0); qpIK[i].setY(0); qpIK[i].setZ(0);
//	  qxIK[i].setW(1); qxIK[i].setX(0); qxIK[i].setY(0); qxIK[i].setZ(0);
//	  qyIK[i].setW(1); qyIK[i].setX(0); qyIK[i].setY(0); qyIK[i].setZ(0);
//	  qzIK[i].setW(1); qzIK[i].setX(0); qzIK[i].setY(0); qzIK[i].setZ(0);
//
//	  xaxisQP_IK[i].setW(1); xaxisQP_IK[i].setX(0); xaxisQP_IK[i].setY(0); xaxisQP_IK[i].setZ(0);
//	  xaxisQX_IK[i].setW(1); xaxisQX_IK[i].setX(0); xaxisQX_IK[i].setY(0); xaxisQX_IK[i].setZ(0);
//	  xaxisQY_IK[i].setW(1); xaxisQY_IK[i].setX(0); xaxisQY_IK[i].setY(0); xaxisQY_IK[i].setZ(0);
//	  xaxisQZ_IK[i].setW(1); xaxisQZ_IK[i].setX(0); xaxisQZ_IK[i].setY(0); xaxisQZ_IK[i].setZ(0);
//	  yaxisQP_IK[i].setW(1); yaxisQP_IK[i].setX(0); zaxisQP_IK[i].setY(0); zaxisQP_IK[i].setZ(0);
//	  yaxisQX_IK[i].setW(1); yaxisQX_IK[i].setX(0); zaxisQX_IK[i].setY(0); zaxisQX_IK[i].setZ(0);
//	  yaxisQY_IK[i].setW(1); yaxisQY_IK[i].setX(0); zaxisQY_IK[i].setY(0); zaxisQY_IK[i].setZ(0);
//	  yaxisQZ_IK[i].setW(1); yaxisQZ_IK[i].setX(0); zaxisQZ_IK[i].setY(0); zaxisQZ_IK[i].setZ(0);
//	  zaxisQP_IK[i].setW(1); zaxisQP_IK[i].setX(0); zaxisQP_IK[i].setY(0); zaxisQP_IK[i].setZ(0);
//	  zaxisQX_IK[i].setW(1); zaxisQX_IK[i].setX(0); zaxisQX_IK[i].setY(0); zaxisQX_IK[i].setZ(0);
//	  zaxisQY_IK[i].setW(1); zaxisQY_IK[i].setX(0); zaxisQY_IK[i].setY(0); zaxisQY_IK[i].setZ(0);
//	  zaxisQZ_IK[i].setW(1); zaxisQZ_IK[i].setX(0); zaxisQZ_IK[i].setY(0); zaxisQZ_IK[i].setZ(0);
// }
//
//
// quatTo_posFile.open("pos.txt");
// quatTo_posFile << "FULLBODY" << "\t" << "1" << endl;
//
//};
//
//
//void EventQtSlotConnect::take_snapShot()
//{
//	PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//	CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//	Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//	LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//	RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//	LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//
//	stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//	stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//	IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//	IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//	IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//	IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//	IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//	IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	IK_freeLeftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//	IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//	IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//	IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//	IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//	IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//	renderWindow->Render();
//
//
//
//
//}
//
//
//void constraintProps::selectConstraintProp(int propID)
//{
//
//	if (propID == 0)
//	{
//		temp_consProp_selectionID = 0;
//		renderer->RemoveActor(ConstraintProp_sphere_actor);
//		renderer->RemoveActor(ConstraintProp_line_actor);
//		renderer->RemoveActor(ConstraintProp_plane_actor);
//		renderer->RemoveActor(ConstraintProp_cube_actor);
//		renderer->RemoveActor(boxingBag_objActor);
//
//		ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//		ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		renderWindow->Render();
//
//	}
//	if (propID == 1)
//	{
//		temp_consProp_selectionID = 1;
//		renderer->RemoveActor(ConstraintProp_line_actor);
//		renderer->RemoveActor(ConstraintProp_plane_actor);
//		renderer->RemoveActor(ConstraintProp_cube_actor);
//		renderer->RemoveActor(boxingBag_objActor);
//		renderer->AddActor(ConstraintProp_sphere_actor);
//
//		ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//		ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		cout << "Point Selected";
//		renderWindow->Render();
//	}
//	if (propID == 2)
//	{
//		temp_consProp_selectionID = 2;
//		renderer->RemoveActor(ConstraintProp_sphere_actor);
//		renderer->RemoveActor(ConstraintProp_plane_actor);
//		renderer->RemoveActor(ConstraintProp_cube_actor);
//		renderer->RemoveActor(boxingBag_objActor);
//		renderer->AddActor(ConstraintProp_line_actor);
//
//		ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//		ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//		renderWindow->Render();
//	}
//	if (propID == 3)
//	{
//		temp_consProp_selectionID = 3;
//		renderer->RemoveActor(ConstraintProp_sphere_actor);
//		renderer->RemoveActor(ConstraintProp_line_actor);
//		renderer->RemoveActor(ConstraintProp_cube_actor);
//		renderer->RemoveActor(boxingBag_objActor);
//		renderer->AddActor(ConstraintProp_plane_actor);
//
//		ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//		ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//		renderWindow->Render();
//	}
//	if (propID == 4)
//	{
//		temp_consProp_selectionID = 4;
//		renderer->RemoveActor(ConstraintProp_sphere_actor);
//		renderer->RemoveActor(ConstraintProp_line_actor);
//		renderer->RemoveActor(ConstraintProp_plane_actor);
//		renderer->RemoveActor(boxingBag_objActor);
//		renderer->AddActor(ConstraintProp_cube_actor);
//
//		ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//		ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//		ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		renderWindow->Render();
//	}
//	if (propID == 5)
//	{
//		temp_consProp_selectionID = 5;
//		renderer->RemoveActor(ConstraintProp_sphere_actor);
//		renderer->RemoveActor(ConstraintProp_line_actor);
//		renderer->RemoveActor(ConstraintProp_plane_actor);
//		renderer->RemoveActor(ConstraintProp_cube_actor);
//		renderer->AddActor(boxingBag_objActor);
//
//		boxingBag_objActor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		renderWindow->Render();
//	}
//
//}
//
//constraintProps::constraintProps(QWidget *parent): QMainWindow(parent), constraintProp_ui(new Ui::constraintProps)
//{
//	constraintProp_ui->setupUi(this);
//	constraintProp_ui->selectProp_comboBox->addItem("Select");
//	constraintProp_ui->selectProp_comboBox->addItem("Point");
//	constraintProp_ui->selectProp_comboBox->addItem("Line");
//	constraintProp_ui->selectProp_comboBox->addItem("Plane");
//	constraintProp_ui->selectProp_comboBox->addItem("Box");
//	constraintProp_ui->selectProp_comboBox->addItem("Boxing Bag");
//	constraintProp_ui->selectProp_comboBox->addItem("Hook Targets");
//
//	connect(constraintProp_ui->selectProp_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectConstraintProp(int)));
//
//	/*constraintProp_ui->scaleProp_spinBox->setValue(5);
//	constraintProp_ui->scaleProp_spinBox->setMaximum(100);
//	constraintProp_ui->scaleProp_spinBox->setMinimum(1);
//	connect(constraintProp_ui->scaleProp_spinBox, SIGNAL(valueChanged(int)), this, SLOT(scale_consProps(int)));*/
//
//}
//
//constraintProps::~constraintProps()
//{
//	delete constraintProp_ui;
//}
//void EventQtSlotConnect::propsWindow()
//{
//	constraintProps_Window->show();
//	cout << "1";
//}
//
//
//class MouseInteractorStyle5 : public vtkInteractorStyleTrackballActor
//{
//public:
//	static MouseInteractorStyle5* New(); vtkTypeMacro(MouseInteractorStyle5, vtkInteractorStyleTrackballActor);
//
//	MouseInteractorStyle5() : NumberOfClicks(0), ResetPixelDistance(5)
//	{
//		this->PreviousPosition[0] = 0;
//		this->PreviousPosition[1] = 0;
//	}
//
//	// Male Biped Model
//	void CHEST(int A, int x, int y, int z)
//	{
//		renderWindow->Render();
//		//CUconeTransform->Identity();
//		CUconeTransform->Translate(0, chest, 0);
//		CUconeTransform->RotateWXYZ(A, x, y, z);
//		CUconeTransform->Translate(0, -chest, 0);
//		renderWindow->Render();
//	}
//
//	void rua(int A, int x, int y, int z)
//	{
//		renderWindow->Render();
//		//RarmTransform->Identity();
//		RarmTransform->Translate(-arm_X, arm_Y, 0);
//		RarmTransform->RotateWXYZ(A, x, y, z);
//		RarmTransform->Translate(arm_X, -arm_Y, 0);
//		//RarmTransform->Identity();
//		renderWindow->Render();
//	}
//	void rla(int A, int x, int y, int z)
//	{
//		renderWindow->Render();
//		//RarmTransform->Identity();
//		RforearmTransform->Translate(-arm_X, arm_Y2, 0);
//		RforearmTransform->RotateWXYZ(A, x, y, z);
//		RforearmTransform->Translate(arm_X, -arm_Y2, 0);
//		//RarmTransform->Identity();
//		renderWindow->Render();
//	}
//	
//	void lua(int A, int x, int y, int z)
//	{
//		renderWindow->Render();
//		//RarmTransform->Identity();
//		LarmTransform->Translate(arm_X, arm_Y, 0);
//		LarmTransform->RotateWXYZ(A, x, y, z);
//		LarmTransform->Translate(-arm_X, -arm_Y, 0);
//		//RarmTransform->Identity();
//		renderWindow->Render();
//	}
//	void lla(int A, int x, int y, int z)
//	{
//		renderWindow->Render();
//		//RarmTransform->Identity();
//		LforearmTransform->Translate(arm_X, arm_Y2, 0);
//		LforearmTransform->RotateWXYZ(A, x, y, z);
//		LforearmTransform->Translate(-arm_X, -arm_Y2, 0);
//		//RarmTransform->Identity();
//		renderWindow->Render();
//	}
//
//	void rul(int A, int x, int y, int z)
//	{
//		renderWindow->Render();
//		//RarmTransform->Identity();
//		RlulegTransform->Translate(-leg_X, leg_Y, 0);
//		RlulegTransform->RotateWXYZ(A, x, y, z);
//		RlulegTransform->Translate(leg_X, -leg_Y, 0);
//		//RarmTransform->Identity();
//		renderWindow->Render();
//	}
//	void rll(int A, int x, int y, int z)
//	{
//		renderWindow->Render();
//		//RarmTransform->Identity();
//		RllegTransform->Translate(-leg_X, leg_Y2, 0);
//		RllegTransform->RotateWXYZ(A, x, y, z);
//		RllegTransform->Translate(leg_X, -leg_Y2, 0);
//		//RarmTransform->Identity();
//		renderWindow->Render();
//	}
//
//	void lul(int A, int x, int y, int z)
//	{
//		renderWindow->Render();
//		//RarmTransform->Identity();
//		LlulegTransform->Translate(leg_X, leg_Y, 0);
//		LlulegTransform->RotateWXYZ(A, x, y, z);
//		LlulegTransform->Translate(-leg_X, -leg_Y, 0);
//		//RarmTransform->Identity();
//		renderWindow->Render();
//	}
//	void lll(int A, int x, int y, int z)
//	{
//		renderWindow->Render();
//		//RarmTransform->Identity();
//		LllegTransform->Translate(leg_X, leg_Y2, 0);
//		LllegTransform->RotateWXYZ(A, x, y, z);
//		LllegTransform->Translate(-leg_X, -leg_Y2, 0);
//		//RarmTransform->Identity();
//		renderWindow->Render();
//	}
//
//
//	// animation for skeleton Model 
//	void animateSM_CH0(int A, int x, int y, int z)
//	{
//		//stickModel_chest_0_Transform->Identity();
//		stickModel_chest_0_Transform->Translate(CH0_x, CH0_y, 0);
//		stickModel_chest_0_Transform->RotateWXYZ(A, x, y, z);
//		stickModel_chest_0_Transform->Translate(-CH0_x, -CH0_y, 0);
//		renderWindow->Render();
//	}
//
//	void animateSM_RUA(int A, int x, int y, int z)
//	{
//		//stickModel_rightUpperArm_Transform->Identity();
//		stickModel_rightUpperArm_Transform->Translate(smUA_x, smUA_y, 0);
//		stickModel_rightUpperArm_Transform->RotateWXYZ(A, x, y, z);
//		stickModel_rightUpperArm_Transform->Translate(-smUA_x, -smUA_y, 0);
//		renderWindow->Render();
//
//	}
//	void animateSM_RLA(int A, int x, int y, int z)
//	{
//		//stickModel_rightLowerArm_Transform->Identity();
//		stickModel_rightLowerArm_Transform->Translate(smLA_x, smLA_y, 0);
//		stickModel_rightLowerArm_Transform->RotateWXYZ(A, x, y, z);
//		stickModel_rightLowerArm_Transform->Translate(-smLA_x, -smLA_y, 0);
//		renderWindow->Render();
//	}
//	void animateSM_ikRH(double ruaA, double rlaA, int x, int y, int z)
//	{
//		stickModel_rightUpperArm_Transform->Identity();
//		stickModel_rightUpperArm_Transform->Translate(smUA_x, smUA_y, 0);
//		stickModel_rightUpperArm_Transform->RotateWXYZ(ruaA, x, y, z);
//		stickModel_rightUpperArm_Transform->Translate(-smUA_x, -smUA_y, 0);
//		renderWindow->Render();
//
//		stickModel_rightLowerArm_Transform->Identity();
//		stickModel_rightLowerArm_Transform->Translate(smLA_x, smLA_y, 0);
//		stickModel_rightLowerArm_Transform->RotateWXYZ(rlaA, x, y, z);
//		stickModel_rightLowerArm_Transform->Translate(-smLA_x, -smLA_y, 0);
//		renderWindow->Render();
//	}
//	void animateSM_RH(int X)
//	{
//		stickModel_rightHand_Transform->Identity();
//		stickModel_rightHand_Transform->Translate(smH_x, smH_y, 0);
//		stickModel_rightHand_Transform->RotateWXYZ(X,1, 0,0);
//
//		renderWindow->Render();
//	}
//	
//	void animateSM_LUA(int A, int x, int y, int z)
//	{
//		//stickModel_leftUpperArm_Transform->Identity();
//		stickModel_leftUpperArm_Transform->Translate(-smUA_x, smUA_y, 0);
//		stickModel_leftUpperArm_Transform->RotateWXYZ(A, x, y, z);
//		stickModel_leftUpperArm_Transform->Translate(smUA_x, -smUA_y, 0);
//		renderWindow->Render();
//
//	}
//	void animateSM_LLA(int A, int x, int y, int z)
//	{
//		//stickModel_leftLowerArm_Transform->Identity();
//		stickModel_leftLowerArm_Transform->Translate(-smLA_x, smLA_y, 0);
//		stickModel_leftLowerArm_Transform->RotateWXYZ(A, x, y, z);
//		stickModel_leftLowerArm_Transform->Translate(smLA_x, -smLA_y, 0);
//		renderWindow->Render();
//	}
//	void animateSM_ikLH(double luaA, double llaA, int x, int y, int z)
//	{
//		stickModel_leftUpperArm_Transform->Identity();
//		stickModel_leftUpperArm_Transform->Translate(-smUA_x, smUA_y, 0);
//		stickModel_leftUpperArm_Transform->RotateWXYZ(luaA, x, y, z);
//		stickModel_leftUpperArm_Transform->Translate(smUA_x, -smUA_y, 0);
//		renderWindow->Render();
//
//		stickModel_leftLowerArm_Transform->Identity();
//		stickModel_leftLowerArm_Transform->Translate(-smLA_x, smLA_y, 0);
//		stickModel_leftLowerArm_Transform->RotateWXYZ(llaA, x, y, z);
//		stickModel_leftLowerArm_Transform->Translate(smLA_x, -smLA_y, 0);
//		renderWindow->Render();
//	}
//	void animateSM_LH(int X)
//	{
//		stickModel_leftHand_Transform->Identity();
//		stickModel_leftHand_Transform->Translate(-smH_x, smH_y, 0);
//		stickModel_leftHand_Transform->RotateWXYZ(X, 1, 0,0);
//	
//		renderWindow->Render();
//	}
//	
//	void animateSM_RUL(int A, int x, int y, int z)
//	{
//		//stickModel_rightUpperLeg_Transform->Identity();
//		stickModel_rightUpperLeg_Transform->Translate(smUL_x, smUL_y, 0);
//		stickModel_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//		stickModel_rightUpperLeg_Transform->Translate(-smUL_x, -smUL_y, 0);
//		renderWindow->Render();
//
//	}
//	void animateSM_RLL(int A, int x, int y, int z)
//	{
//		//stickModel_rightLowerLeg_Transform->Identity();
//		stickModel_rightLowerLeg_Transform->Translate(smLL_x, smLL_y, 0);
//		stickModel_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
//		stickModel_rightLowerLeg_Transform->Translate(-smLL_x, -smLL_y, 0);
//		renderWindow->Render();
//	}
//	void animateSM_ikRF(double ruaA, double rlaA, int x, int y, int z)
//	{
//		stickModel_rightUpperLeg_Transform->Identity();
//		stickModel_rightUpperLeg_Transform->Translate(smUL_x, smUL_y, 0);
//		stickModel_rightUpperLeg_Transform->RotateWXYZ(ruaA, x, y, z);
//		stickModel_rightUpperLeg_Transform->Translate(-smUL_x, -smUL_y, 0);
//		renderWindow->Render();
//
//		stickModel_rightLowerLeg_Transform->Identity();
//		stickModel_rightLowerLeg_Transform->Translate(smLL_x, smLL_y, 0);
//		stickModel_rightLowerLeg_Transform->RotateWXYZ(rlaA, x, y, z);
//		stickModel_rightLowerLeg_Transform->Translate(-smLL_x, -smLL_y, 0);
//		renderWindow->Render();
//	}
//	void animateSM_RF(int X)
//	{
//		stickModel_rightFoot_Transform->Identity();
//		stickModel_rightFoot_Transform->Translate(smF_x, smF_y, 0);
//		stickModel_rightFoot_Transform->RotateWXYZ(X, 1, 0, 0);
//		renderWindow->Render();
//	}
//
//	void animateSM_LUL(int A, int x, int y, int z)
//	{
//		//stickModel_leftUpperLeg_Transform->Identity();
//		stickModel_leftUpperLeg_Transform->Translate(-smUL_x, smUL_y, 0);
//		stickModel_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//		stickModel_leftUpperLeg_Transform->Translate(smUL_x, -smUL_y, 0);
//		renderWindow->Render();
//
//	}
//	void animateSM_LLL(int A, int x, int y, int z)
//	{
//		//stickModel_leftLowerLeg_Transform->Identity();
//		stickModel_leftLowerLeg_Transform->Translate(-smLL_x, smLL_y, 0);
//		stickModel_leftLowerLeg_Transform->RotateWXYZ(A,x, y, z);
//		stickModel_leftLowerLeg_Transform->Translate(smLL_x, -smLL_y, 0);
//		renderWindow->Render();
//	}
//	void animateSM_ikLF(double ruaA, double rlaA, int x, int y, int z)
//	{
//		stickModel_leftUpperLeg_Transform->Identity();
//		stickModel_leftUpperLeg_Transform->Translate(-smUL_x, smUL_y, 0);
//		stickModel_leftUpperLeg_Transform->RotateWXYZ(ruaA, x, y, z);
//		stickModel_leftUpperLeg_Transform->Translate(smUL_x, -smUL_y, 0);
//		renderWindow->Render();
//
//		stickModel_leftLowerLeg_Transform->Identity();
//		stickModel_leftLowerLeg_Transform->Translate(-smLL_x, smLL_y, 0);
//		stickModel_leftLowerLeg_Transform->RotateWXYZ(rlaA, x, y, z);
//		stickModel_leftLowerLeg_Transform->Translate(smLL_x, -smLL_y, 0);
//		renderWindow->Render();
//	}
//	void animateSM_LF(int X)
//	{
//		stickModel_leftFoot_Transform->Identity();
//		stickModel_leftFoot_Transform->Translate(-smF_x, smF_y, 0);
//		stickModel_leftFoot_Transform->RotateWXYZ(X, 1, 0, 0);
//		renderWindow->Render();
//	}
//
//
//	// animation for FixedFoot IK model
//	void animateffIK_xPL(double ULangle, double LLangle, int x, int y, int z)
//	{
//		
//			renderWindow->Render();
//			IK_rightLowerLeg_Transform->Identity();
//			IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_rightLowerLeg_Transform->RotateWXYZ(ULangle, x, y, z);
//			IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);
//
//			IK_rightUpperLeg_Transform->Identity();
//			IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
//			IK_rightUpperLeg_Transform->RotateWXYZ(LLangle, x, y, z);
//			IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
//
//
//			IK_leftLowerLeg_Transform->Identity();
//			IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_leftLowerLeg_Transform->RotateWXYZ(ULangle, x, y, z);
//			IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);
//
//			IK_leftUpperLeg_Transform->Identity();
//			IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
//			IK_leftUpperLeg_Transform->RotateWXYZ(LLangle, x, y, z);
//			IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);
//		
//
//	}
//	void animateffIK_PL(double ULangle, double LLangle, int x, int y, int z)
//	{
//	
//			/*renderWindow->Render();*/
//			IK_chest_0_Transform->Identity();
//			IK_chest_0_Transform->Translate(ffIK_CH0_x, ffIK_CH0_y, 0);
//			IK_chest_0_Transform->RotateWXYZ(ULangle*2.5, x, y, z);
//			IK_chest_0_Transform->Translate(-ffIK_CH0_x, -ffIK_CH0_y, 0);
//
//			IK_rightLowerLeg_Transform->Identity();
//			IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_rightLowerLeg_Transform->RotateWXYZ(ULangle, x, y, z);
//			IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);
//
//			IK_rightUpperLeg_Transform->Identity();
//			IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
//			IK_rightUpperLeg_Transform->RotateWXYZ(LLangle, x, y, z);
//			IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
//
//
//			IK_leftLowerLeg_Transform->Identity();
//			IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_leftLowerLeg_Transform->RotateWXYZ(ULangle, x, y, z);
//			IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);
//
//			IK_leftUpperLeg_Transform->Identity();
//			IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
//			IK_leftUpperLeg_Transform->RotateWXYZ(LLangle, x, y, z);
//			IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);
//		
//			renderWindow->Render();
//
//	}
//	void animateffIK_CH0(int A, int x, int y, int z)
//	{
//		//IK_chest_0_Transform->Identity();
//		IK_chest_0_Transform->Translate(ffIK_CH0_x, ffIK_CH0_y, 0);
//		IK_chest_0_Transform->RotateWXYZ(A, x, y, z);
//		IK_chest_0_Transform->Translate(-ffIK_CH0_x, -ffIK_CH0_y, 0);
//		renderWindow->Render();
//	}
//
//	void animateffIK_RUA(int A, int x, int y, int z)
//	{
//		//IK_rightUpperArm_Transform->Identity();
//		IK_rightUpperArm_Transform->Translate(ffIK_UA_x, ffIK_UA_y, 0);
//		IK_rightUpperArm_Transform->RotateWXYZ(A, x, y, z);
//		IK_rightUpperArm_Transform->Translate(-ffIK_UA_x, -ffIK_UA_y, 0);
//		renderWindow->Render();
//	}
//	void animateffIK_RLA(int A, int x, int y, int z)
//	{
//		//IK_rightLowerArm_Transform->Identity();
//		IK_rightLowerArm_Transform->Translate(ffIK_LA_x, ffIK_LA_y, 0);
//		IK_rightLowerArm_Transform->RotateWXYZ(A, x, y, z);
//		IK_rightLowerArm_Transform->Translate(-ffIK_LA_x, -ffIK_LA_y, 0);
//		renderWindow->Render();
//	}
//	void animateffIK_RH(double ruaA, double rlaA, int x, int y, int z)
//	{
//		
//		IK_rightUpperArm_Transform->Identity();
//		IK_rightUpperArm_Transform->Translate(ffIK_UA_x, ffIK_UA_y, 0);
//		IK_rightUpperArm_Transform->RotateWXYZ(ruaA, x, y, z);
//		IK_rightUpperArm_Transform->Translate(-ffIK_UA_x, -ffIK_UA_y, 0);
//		
//
//		IK_rightLowerArm_Transform->Identity();
//		IK_rightLowerArm_Transform->Translate(ffIK_LA_x, ffIK_LA_y, 0);
//		IK_rightLowerArm_Transform->RotateWXYZ(rlaA, x, y, z);
//		IK_rightLowerArm_Transform->Translate(-ffIK_LA_x, -ffIK_LA_y, 0);
//		renderWindow->Render();
//
//
//	}
//
//	void animateffIK_LUA(int A, int x, int y, int z)
//	{
//		//IK_leftUpperArm_Transform->Identity();
//		IK_leftUpperArm_Transform->Translate(ffIK_LUA_x, ffIK_LUA_y, 0);
//		IK_leftUpperArm_Transform->RotateWXYZ(A, x, y, z);
//		IK_leftUpperArm_Transform->Translate(-ffIK_LUA_x, -ffIK_LUA_y, 0);
//		renderWindow->Render();
//	}
//	void animateffIK_LLA(int A, int x, int y, int z)
//	{
//		//IK_leftLowerArm_Transform->Identity();
//		IK_leftLowerArm_Transform->Translate(ffIK_LLA_x, ffIK_LLA_y, 0);
//		IK_leftLowerArm_Transform->RotateWXYZ(A, x, y, z);
//		IK_leftLowerArm_Transform->Translate(-ffIK_LLA_x, -ffIK_LLA_y, 0);
//		renderWindow->Render();
//	}
//	void animateffIK_LH(double ruaA, double rlaA, int x, int y, int z)
//	{
//		IK_leftUpperArm_Transform->Identity();
//		IK_leftUpperArm_Transform->Translate(ffIK_UA_x, ffIK_UA_y, 0);
//		IK_leftUpperArm_Transform->RotateWXYZ(ruaA, x, y, z);
//		IK_leftUpperArm_Transform->Translate(-ffIK_UA_x, -ffIK_UA_y, 0);
//
//
//		IK_leftLowerArm_Transform->Identity();
//		IK_leftLowerArm_Transform->Translate(ffIK_LA_x, ffIK_LA_y, 0);
//		IK_leftLowerArm_Transform->RotateWXYZ(rlaA, x, y, z);
//		IK_leftLowerArm_Transform->Translate(-ffIK_LA_x, -ffIK_LA_y, 0);
//		renderWindow->Render();
//	}
//
//
//	void animateffIK_RUL(int A, int x, int y, int z)
//	{
//
//		if (ffIK_both == 1)
//		{
//			//IK_rightUpperLeg_Transform->Identity();
//			IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
//			IK_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
//
//			IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
//			IK_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
//			renderWindow->Render();
//
//		}
//		if (ffIK_RF == 1)
//		{
//			//IK_rightUpperLeg_Transform->Identity();
//			IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
//			IK_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
//		}
//		if (ffIK_LF == 1)
//		{
//			IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
//			IK_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
//			renderWindow->Render();
//		}
//	}
//	void animateffIK_RLL(int A, int x, int y, int z)
//	{
//		if (ffIK_both == 1)
//		{
//			//IK_leftLowerLeg_Transform->Identity();
//			IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);
//
//			IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_leftLowerLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);
//
//			renderWindow->Render();
//		}
//		if (ffIK_RF == 1)
//		{
//			//IK_leftLowerLeg_Transform->Identity();
//			IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);
//
//			renderWindow->Render();
//		}
//		if (ffIK_LF == 1)
//		{
//			IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_leftLowerLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);
//
//			renderWindow->Render();
//		}
//			
//	}
//
//
//	void animateffIK_LUL(int A, int x, int y, int z)
//	{
//
//		if (ffIK_both == 1)
//		{
//			//IK_leftUpperLeg_Transform->Identity();
//			IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
//			IK_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);
//
//			//IK_rightUpperLeg_Transform->Identity();
//			IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
//			IK_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);
//
//			renderWindow->Render();
//		}
//		if (ffIK_RF == 1)
//		{
//			//IK_rightUpperLeg_Transform->Identity();
//			IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
//			IK_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);
//
//			renderWindow->Render();
//
//		}
//		if (ffIK_LF == 1)
//		{
//			//IK_leftUpperLeg_Transform->Identity();
//			IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
//			IK_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);
//
//			renderWindow->Render();
//		}
//		
//	}
//	void animateffIK_LLL(int A, int x, int y, int z)
//	{
//
//		if (ffIK_both == 1)
//		{
//			//IK_leftLowerLeg_Transform->Identity();
//			IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_leftLowerLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);
//
//			//IK_leftLowerLeg_Transform->Identity();
//			IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);
//
//			renderWindow->Render();
//		}
//		if (ffIK_RF == 1)
//		{
//			//IK_leftLowerLeg_Transform->Identity();
//			IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);
//
//			renderWindow->Render();
//		}
//		if (ffIK_LF == 1)
//		{
//			//IK_leftLowerLeg_Transform->Identity();
//			IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
//			IK_leftLowerLeg_Transform->RotateWXYZ(A, x, y, z);
//			IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);
//
//			renderWindow->Render();
//
//		}
//
//	}
//
//	// To animate Free Left Foot and Free Right Foot
//	void animateFreeLF(double lulA, double lllA, int x, int y, int z)
//	{
//		IK_freeLeftUpperLeg_Transform->Identity();
//		IK_freeLeftUpperLeg_Transform->Translate(-freefootLUL_x, freefootLUL_y, 0);
//		IK_freeLeftUpperLeg_Transform->RotateWXYZ(lulA, x, y, z);
//		IK_freeLeftUpperLeg_Transform->Translate(freefootLUL_x, -freefootLUL_y, 0);
//
//
//		IK_freeLeftLowerLeg_Transform->Identity();
//		IK_freeLeftLowerLeg_Transform->Translate(-freefootLLL_x, freefootLLL_y, 0);
//		IK_freeLeftLowerLeg_Transform->RotateWXYZ(lllA, x, y, z);
//		IK_freeLeftLowerLeg_Transform->Translate(freefootLLL_x, -freefootLLL_y, 0);
//		renderWindow->Render();
//	}
//	void animateFreeRF(double rulA, double rllA, int x, int y, int z)
//	{
//		IK_freeRightUpperLeg_Transform->Identity();
//		IK_freeRightUpperLeg_Transform->Translate(-freefootRUL_x, freefootRUL_y, 0);
//		IK_freeRightUpperLeg_Transform->RotateWXYZ(rulA, x, y, z);
//		IK_freeRightUpperLeg_Transform->Translate(freefootRUL_x, -freefootRUL_y, 0);
//
//
//		IK_freeRightLowerLeg_Transform->Identity();
//		IK_freeRightLowerLeg_Transform->Translate(-freefootRLL_x, freefootRLL_y, 0);
//		IK_freeRightLowerLeg_Transform->RotateWXYZ(rllA, x, y, z);
//		IK_freeRightLowerLeg_Transform->Translate(freefootRLL_x, -freefootRLL_y, 0);
//		renderWindow->Render();
//	}
//
//
//	void moveSphereProp(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		ConstraintProp_sphere_transform->Translate(x, y, z);
//		renderWindow->Render();
//	}
//
//	void TmoveSphereProp(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		TConstraintProp_sphere_transform->Translate(x, y, z);
//		renderWindow->Render();
//	}
//
//	void TmoveSphereProp2(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		TConstraintProp_sphere_transform2->Translate(x, y, z);
//		renderWindow->Render();
//	}
//
//	void TmoveSphereProp3(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		TConstraintProp_sphere_transform3->Translate(x, y, z);
//		renderWindow->Render();
//	}
//
//
//	void moveLineProp(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		ConstraintProp_line_transform->Translate(x, y, z);
//		ConstraintProp_line_transform1->Translate(x, y, z);
//		cout << "Inrusion=" << RUA_collide->GetNumberOfContacts() << endl;
//
//		TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("Teal").GetData());
//
//
//		renderWindow->Render();
//	}
//
//
//	void TmoveLineProp(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		//TConstraintProp_line_transform->Translate(x, y, z);
//		TConstraintProp_line_transform1->Translate(x, y, z);
//		//cout << "Inrusion=" << RUA_collide->GetNumberOfContacts() << endl;
//		renderWindow->Render();
//		TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d("Teal").GetData());
//		TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//	}
//
//
//	void TmoveLineProp2(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		//TConstraintProp_line_transform->Translate(x, y, z);
//		TConstraintProp_line_transform2->Translate(x, y, z);
//		//cout << "Inrusion=" << RUA_collide->GetNumberOfContacts() << endl;
//
//		TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//
//		renderWindow->Render();
//	}
//
//
//	void TmoveLineProp3(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		//TConstraintProp_line_transform->Translate(x, y, z);
//		TConstraintProp_line_transform3->Translate(x, y, z);
//		//cout << "Inrusion=" << RUA_collide->GetNumberOfContacts() << endl;
//		renderWindow->Render();
//		TConstraintProp_line_actor3->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		TConstraintProp_line_actor2->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//		TConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("Teal").GetData());
//		ConstraintProp_line_actor1->GetProperty()->SetColor(colors->GetColor3d("SandyBrown").GetData());
//	}
//
//
//	void movePlaneProp(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		ConstraintProp_plane_transform->Translate(x, y, z);
//		renderWindow->Render();
//	}
//	void moveCubeProp(int x, int y, int z)
//	{
//		cout << "x=" << x << "\t" << "y=" << y << endl;
//		////ConstraintProp_sphere_actor->RotateWXYZ(1, 1, 0, 0);
//		//ConstraintProp_sphere_actor->SetPosition(x, y, 0);
//		ConstraintProp_cube_transform->Translate(x, y, z);
//		renderWindow->Render();
//	}
//
//	int prevX = 0;
//	int prevY = 0;
//
//	double x;
//	double y;
//	double z;
//
//	double xpos = 0.0;
//	double ypos = 0.0;
//	double zpos = 0.0;
//	int temp = 0;
//	int diff;
//
//
//	void compute(int A, int x, int y, int z, int bid)
//	{
//		axis.x = x; axis.y = y; axis.z = z;
//		int angle = A;
//		if (axis.x == 1 || axis.x == -1)
//		{
//
//			qx[bid].setW(cos(angle* PI / 180 / 2));
//			qx[bid].setX(axis.x* sin(angle* PI / 180 / 2));
//			qx[bid].setY(0 * sin(angle * PI / 180 / 2));
//			qx[bid].setZ(0 * sin(angle* PI / 180 / 2));
//
//			/*	qy[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//				qy[bid].setX(0);
//				qy[bid].setY(sin(0 / 2));
//				qy[bid].setZ(sin(0 / 2));
//
//				qz[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//				qz[bid].setX(0);
//				qz[bid].setY(sin(0 / 2));
//				qz[bid].setZ(sin(0 / 2));*/
//
//
//			xaxisQX[bid].setW(cos(angle* PI / 180 / 2));
//			xaxisQX[bid].setX(axis.x* sin(angle* PI / 180 / 2));
//			xaxisQX[bid].setY(0 * sin(angle * PI / 180 / 2));
//			xaxisQX[bid].setZ(0 * sin(angle* PI / 180 / 2));
//
//			xaxisQY[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY[bid].setX(0);
//			xaxisQY[bid].setY(sin(0 / 2));
//			xaxisQY[bid].setZ(sin(0 / 2));
//
//			xaxisQZ[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ[bid].setX(0);
//			xaxisQZ[bid].setY(sin(0 / 2));
//			xaxisQZ[bid].setZ(sin(0 / 2));
//
//
//			xaxisQP[bid] = xaxisQX[bid].multiply(xaxisQY[bid].multiply(xaxisQZ[bid]));
//
//			//qsf[bid] = qx[bid].multiply(qy[bid].multiply(qz[bid]));
//
//			//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qsf[bid].getW() << "\t" << "X=" << qsf[bid].getX() << "\t" << "Y=" << qsf[bid].getY() << "\t" << "Z=" << qsf[bid].getZ() << "\n";
//
//
//			//cout << "bid=" << bid << "\t" << "count=" << A  << "\t" << axis.x  << "\t" << axis.y  << "\t" << axis.z << endl;
//
//			//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qx[bid].getW() << "\t" << "X=" << qx[bid].getX() << "\t" << "Y=" << qx[bid].getY() << "\t" << "Z=" << qx[bid].getZ() << "\n";
//
//			//cout << "\n" << "================================================" << endl;
//			
//			cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << xaxisQP[bid].getW() << "\t" << "X=" << xaxisQP[bid].getX() << "\t" << "Y=" << xaxisQP[bid].getY() << "\t" << "Z=" << xaxisQP[bid].getZ() << "\n";
//
//
//
//			dummy1 = A;
//			dummy2 = 0;
//			dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//
//		}
//		if (axis.z == 1 || axis.z == -1)
//		{
//
//
//
//			/*	qy[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//				qy[bid].setX(0);
//				qy[bid].setY(sin(0 / 2));
//				qy[bid].setZ(sin(0 / 2));
//
//				qx[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//				qx[bid].setX(0);
//				qx[bid].setY(sin(0 / 2));
//				qx[bid].setZ(sin(0 / 2));*/
//
//			qz[bid].setW(cos(angle* PI / 180 / 2));
//			qz[bid].setY(0 * sin(angle * PI / 180 / 2));
//			//qz[bid].setY(-0.01);
//			qz[bid].setX(0 * sin(angle* PI / 180 / 2));
//			/*	qz[bid].setX(-0.1);*/
//			qz[bid].setZ(axis.z* sin(angle* PI / 180 / 2));
//
//
//			zaxisQZ[bid].setW(cos(angle* PI / 180 / 2));
//			zaxisQZ[bid].setX(axis.x* sin(angle* PI / 180 / 2));
//			zaxisQZ[bid].setY(0 * sin(angle * PI / 180 / 2));
//			zaxisQZ[bid].setZ(axis.z* sin(angle* PI / 180 / 2));
//
//			zaxisQY[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//			zaxisQY[bid].setX(0);
//			zaxisQY[bid].setY(sin(0 / 2));
//			zaxisQY[bid].setZ(sin(0 / 2));
//
//			zaxisQX[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//			zaxisQX[bid].setX(0);
//			zaxisQX[bid].setY(sin(0 / 2));
//			zaxisQX[bid].setZ(sin(0 / 2));
//
//
//			zaxisQP[bid] = zaxisQX[bid].multiply(zaxisQY[bid].multiply(zaxisQZ[bid]));
//
//			//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << axis.x << "\t" << axis.y << "\t" << axis.z << endl;
//
//			//qsf[bid] = qx[bid].multiply(qy[bid].multiply(qz[bid]));
//
//			//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qsf[bid].getW() << "\t" << "X=" << qsf[bid].getX() << "\t" << "Y=" << qsf[bid].getY() << "\t" << "Z=" << qsf[bid].getZ() << "\n";
//
//			cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qz[bid].getW() << "\t" << "X=" << qz[bid].getX() << "\t" << "Y=" << qz[bid].getY() << "\t" << "Z=" << qz[bid].getZ() << "\n";
//
//			//cout << "\n" << "================================================" << endl;
//			//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << zaxisQP[bid].getW() << "\t" << "X=" << zaxisQP[bid].getX() << "\t" << "Y=" << zaxisQP[bid].getY() << "\t" << "Z=" << zaxisQP[bid].getZ() << "\n\n";
//
//
//			dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = A;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//
//		}
//		if (axis.y == 1 || axis.y == -1)
//		{
//			/*qx[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//			qx[bid].setX(0);
//			qx[bid].setY(sin(0 / 2));
//			qx[bid].setZ(sin(0 / 2));*/
//
//			qy[bid].setW(cos(angle* PI / 180 / 2));
//			qy[bid].setX(0 * sin(angle* PI / 180 / 2));
//			qy[bid].setY(axis.y* sin(angle* PI / 180 / 2));
//			qy[bid].setZ(0 * sin(angle * PI / 180 / 2));
//
//			/*		qz[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//					qz[bid].setX(0);
//					qz[bid].setY(sin(0 / 2));
//					qz[bid].setZ(sin(0 / 2));*/
//
//
//			yaxisQX[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//			yaxisQX[bid].setX(0);
//			yaxisQX[bid].setY(sin(0 / 2));
//			yaxisQX[bid].setZ(sin(0 / 2));
//
//			yaxisQZ[bid].setW(cos(0.000000000000001 / 2 * PI / 180));
//			yaxisQZ[bid].setX(0);
//			yaxisQZ[bid].setY(sin(0 / 2));
//			yaxisQZ[bid].setZ(sin(0 / 2));
//
//			yaxisQY[bid].setW(cos(angle* PI / 180 / 2));
//			yaxisQY[bid].setX(0 * sin(angle* PI / 180 / 2));
//			yaxisQY[bid].setY(axis.y* sin(angle* PI / 180 / 2));
//			yaxisQY[bid].setZ(0 * sin(angle * PI / 180 / 2));
//
//
//			yaxisQP[bid] = yaxisQX[bid].multiply(yaxisQY[bid].multiply(yaxisQZ[bid]));
//
//			//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << axis.x << "\t" << axis.y << "\t" << axis.z << endl;
//
//			//qsf[bid] = qx[bid].multiply(qy[bid].multiply(qz[bid]));
//
//			//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qsf[bid].getW() << "\t" << "X=" << qsf[bid].getX() << "\t" << "Y=" << qsf[bid].getY() << "\t" << "Z=" << qsf[bid].getZ() << "\n";
//
//			cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << qy[bid].getW() << "\t" << "X=" << qy[bid].getX() << "\t" << "Y=" << qy[bid].getY() << "\t" << "Z=" << qy[bid].getZ() << "\n";
//
//			//cout << "\n" << "================================================" << endl;
//			//cout << "bid=" << bid << "\t" << "count=" << A << "\t" << "W=" << yaxisQP[bid].getW() << "\t" << "X=" << yaxisQP[bid].getX() << "\t" << "Y=" << yaxisQP[bid].getY() << "\t" << "Z=" << yaxisQP[bid].getZ() << "\n\n";
//
//			dummy1 = 0;
//			dummy2 = A;
//			dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//		}
//
//		qxIK[2] = qx[2];
//		xaxisQP_IK[2] = xaxisQP[2];
//		qyIK[2] = qy[2];
//		yaxisQP_IK[2] = yaxisQP[2];
//		qzIK[2] = qz[2];
//		zaxisQP_IK[2] = zaxisQP[2];
//
//		qxIK[3] = qx[3];
//		xaxisQP_IK[3] = xaxisQP[3];
//		qyIK[3] = qy[3];
//		yaxisQP_IK[3] = yaxisQP[3];
//		qzIK[3] = qz[3];
//		zaxisQP_IK[3] = zaxisQP[3];
//
//		qxIK[4] = qx[4];
//		xaxisQP_IK[4] = xaxisQP[4];
//		qyIK[4] = qy[4];
//		yaxisQP_IK[4] = yaxisQP[4];
//		qzIK[4] = qz[4];
//		zaxisQP_IK[4] = zaxisQP[4];
//
//		qxIK[5] = qx[5];
//		xaxisQP_IK[5] = xaxisQP[5];
//		qyIK[5] = qy[5];
//		yaxisQP_IK[5] = yaxisQP[5];
//		qzIK[5] = qz[5];
//		zaxisQP_IK[5] = zaxisQP[5];
//
//	}
//
//	void computeSM_ikRH(int temptarget_X, int temptarget_Y, int x, int y, int z, int boneID)
//	{
//		rhIK_target_X = temptarget_X;
//		rhIK_target_Y = temptarget_Y;
//		rhIK_targetDistSqr = (rhIK_target_X*rhIK_target_X + rhIK_target_Y * rhIK_target_Y);
//		rhIK_cosAngle2_denom = 2 * rhIK_length1*rhIK_length2;
//		if (rhIK_cosAngle2_denom > epsilon)
//		{
//			rhIK_cosAngle2 = (rhIK_targetDistSqr - rhIK_length1 * rhIK_length1 - rhIK_length2 * rhIK_length2) / (rhIK_cosAngle2_denom);
//			if ((rhIK_cosAngle2 < -1.0) || (rhIK_cosAngle2 > 1.0))
//			{
//				rhIK_foundValidSolution = false;
//			}
//			double rhIK_tempMin;
//			rhIK_tempMin = min(1.0, rhIK_cosAngle2);
//			rhIK_cosAngle2 = max(-1.0, rhIK_tempMin);
//			rhIK_angle2 = acos(rhIK_cosAngle2);
//			if (!rhIK_solvePosAngle2)
//			{
//				rhIK_angle2 = -rhIK_angle2;
//			}
//			rhIK_sinAngle2 = sin(rhIK_angle2);
//
//		}
//		else
//		{
//			double rhIK_totalLenSqr = (rhIK_length1 + rhIK_length2) * (rhIK_length1 + rhIK_length2);
//			if (rhIK_targetDistSqr < (rhIK_totalLenSqr - epsilon) || rhIK_targetDistSqr >(rhIK_totalLenSqr + epsilon))
//			{
//				rhIK_foundValidSolution = false;
//			}
//			rhIK_angle2 = 0.0;
//			rhIK_cosAngle2 = 1.0;
//			rhIK_sinAngle2 = 0.0;
//		}
//
//		double rhIK_triAdjacent = rhIK_length1 + rhIK_length2 * rhIK_cosAngle2;
//		double rhIK_triOpposite = rhIK_length2 * rhIK_sinAngle2;
//
//		double rhIK_tanY = rhIK_target_Y * rhIK_triAdjacent - rhIK_target_X * rhIK_triOpposite;
//		double rhIK_tanX = rhIK_target_X * rhIK_triAdjacent + rhIK_target_Y * rhIK_triOpposite;
//		rhIK_angle1 = atan2(rhIK_tanY, rhIK_tanX);
//
//
//		double rhIK_theta1 = rhIK_angle1 * 180 / PI;
//		double rhIK_theta2 = rhIK_angle2 * 180 / PI;
//		cout << "theta1=" << rhIK_theta1 << "\t" << "theta2=" << rhIK_theta2 << endl;
//		//cout << "testTargetx:" << rhIK_Targetx << "\t" << "testTargety:" << rhIK_Targety << "\t" << "theta1=" << rhIK_theta1 << "\t" << "theta2=" << rhIK_theta2 << endl;
//		
//		if (boneID == 10)
//		{
//			animateSM_ikRH(rhIK_theta1, rhIK_theta2, x, y, z);
//			
//			// rightUpperArm
//			qxIK[2].setW(cos(-rhIK_theta1* PI / 180 / 2));
//			qxIK[2].setX(1* sin(-rhIK_theta1* PI / 180 / 2));
//			qxIK[2].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//			qxIK[2].setZ(0 * sin(-rhIK_theta1* PI / 180 / 2));
//
//			xaxisQX_IK[2].setW(cos(-rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[2].setX(1* sin(-rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[2].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//			xaxisQX_IK[2].setZ(0 * sin(-rhIK_theta1* PI / 180 / 2));
//
//			xaxisQY_IK[2].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[2].setX(0);
//			xaxisQY_IK[2].setY(sin(0 / 2));
//			xaxisQY_IK[2].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[2].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[2].setX(0);
//			xaxisQZ_IK[2].setY(sin(0 / 2));
//			xaxisQZ_IK[2].setZ(sin(0 / 2));
//			
//			xaxisQP_IK[2] = xaxisQX_IK[2].multiply(xaxisQY_IK[2].multiply(xaxisQZ_IK[2]));
//
//			//rightLowerArm
//			qxIK[3].setW(cos(-rhIK_theta2* PI / 180 / 2));
//			qxIK[3].setX(1* sin(-rhIK_theta2* PI / 180 / 2));
//			qxIK[3].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//			qxIK[3].setZ(0 * sin(-rhIK_theta2* PI / 180 / 2));
//
//			xaxisQX_IK[3].setW(cos(-rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[3].setX(1* sin(-rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[3].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//			xaxisQX_IK[3].setZ(0 * sin(-rhIK_theta2* PI / 180 / 2));
//
//			xaxisQY_IK[3].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[3].setX(0);
//			xaxisQY_IK[3].setY(sin(0 / 2));
//			xaxisQY_IK[3].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[3].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[3].setX(0);
//			xaxisQZ_IK[3].setY(sin(0 / 2));
//			xaxisQZ_IK[3].setZ(sin(0 / 2));
//
//			xaxisQP_IK[3] = xaxisQX_IK[3].multiply(xaxisQY_IK[3].multiply(xaxisQZ_IK[3]));
//		}
//		if (boneID == 15)
//		{
//			animateSM_ikLH(rhIK_theta1, rhIK_theta2, x, y, z);
//
//			// leftUpperArm
//			qxIK[4].setW(cos(-rhIK_theta1* PI / 180 / 2));
//			qxIK[4].setX(1 * sin(-rhIK_theta1* PI / 180 / 2));
//			qxIK[4].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//			qxIK[4].setZ(0 * sin(-rhIK_theta1* PI / 180 / 2));
//
//			xaxisQX_IK[4].setW(cos(-rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[4].setX(1 * sin(-rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[4].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//			xaxisQX_IK[4].setZ(0 * sin(-rhIK_theta1* PI / 180 / 2));
//
//			xaxisQY_IK[4].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[4].setX(0);
//			xaxisQY_IK[4].setY(sin(0 / 2));
//			xaxisQY_IK[4].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[4].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[4].setX(0);
//			xaxisQZ_IK[4].setY(sin(0 / 2));
//			xaxisQZ_IK[4].setZ(sin(0 / 2));
//
//			xaxisQP_IK[4] = xaxisQX_IK[4].multiply(xaxisQY_IK[4].multiply(xaxisQZ_IK[4]));
//
//			//LeftLowerArm
//			qxIK[5].setW(cos(-rhIK_theta2* PI / 180 / 2));
//			qxIK[5].setX(1 * sin(-rhIK_theta2* PI / 180 / 2));
//			qxIK[5].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//			qxIK[5].setZ(0 * sin(-rhIK_theta2* PI / 180 / 2));
//
//			xaxisQX_IK[5].setW(cos(-rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[5].setX(1 * sin(-rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[5].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//			xaxisQX_IK[5].setZ(0 * sin(-rhIK_theta2* PI / 180 / 2));
//
//			xaxisQY_IK[5].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[5].setX(0);
//			xaxisQY_IK[5].setY(sin(0 / 2));
//			xaxisQY_IK[5].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[5].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[5].setX(0);
//			xaxisQZ_IK[5].setY(sin(0 / 2));
//			xaxisQZ_IK[5].setZ(sin(0 / 2));
//
//			xaxisQP_IK[5] = xaxisQX_IK[5].multiply(xaxisQY_IK[5].multiply(xaxisQZ_IK[5]));
//
//		}
//		if (boneID == 16)
//		{
//			animateSM_ikRF(-rhIK_theta1, -rhIK_theta2, x, y, z);
//
//			// rightUpperLeg
//			qxIK[6].setW(cos(-rhIK_theta1* PI / 180 / 2));
//			qxIK[6].setX(1 * sin(rhIK_theta1* PI / 180 / 2));
//			qxIK[6].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
//			qxIK[6].setZ(0 * sin(rhIK_theta1* PI / 180 / 2));
//
//			xaxisQX_IK[6].setW(cos(rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[6].setX(1 * sin(rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[6].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
//			xaxisQX_IK[6].setZ(0 * sin(rhIK_theta1* PI / 180 / 2));
//
//			xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[6].setX(0);
//			xaxisQY_IK[6].setY(sin(0 / 2));
//			xaxisQY_IK[6].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[6].setX(0);
//			xaxisQZ_IK[6].setY(sin(0 / 2));
//			xaxisQZ_IK[6].setZ(sin(0 / 2));
//
//			xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));
//
//			//rightLowerLeg
//			qxIK[7].setW(cos(rhIK_theta2* PI / 180 / 2));
//			qxIK[7].setX(1 * sin(rhIK_theta2* PI / 180 / 2));
//			qxIK[7].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
//			qxIK[7].setZ(0 * sin(rhIK_theta2* PI / 180 / 2));
//
//			xaxisQX_IK[7].setW(cos(rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[7].setX(1 * sin(rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[7].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
//			xaxisQX_IK[7].setZ(0 * sin(rhIK_theta2* PI / 180 / 2));
//
//			xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[7].setX(0);
//			xaxisQY_IK[7].setY(sin(0 / 2));
//			xaxisQY_IK[7].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[7].setX(0);
//			xaxisQZ_IK[7].setY(sin(0 / 2));
//			xaxisQZ_IK[7].setZ(sin(0 / 2));
//
//			xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));
//
//		}
//		if (boneID == 21)
//		{
//			animateSM_ikLF(-rhIK_theta1, -rhIK_theta2, x, y, z);
//
//			// leftUpperLeg
//			qxIK[8].setW(cos(rhIK_theta1* PI / 180 / 2));
//			qxIK[8].setX(1 * sin(rhIK_theta1* PI / 180 / 2));
//			qxIK[8].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
//			qxIK[8].setZ(0 * sin(rhIK_theta1* PI / 180 / 2));
//
//			xaxisQX_IK[8].setW(cos(rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[8].setX(1 * sin(rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[8].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
//			xaxisQX_IK[8].setZ(0 * sin(rhIK_theta1* PI / 180 / 2));
//
//			xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[8].setX(0);
//			xaxisQY_IK[8].setY(sin(0 / 2));
//			xaxisQY_IK[8].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[8].setX(0);
//			xaxisQZ_IK[8].setY(sin(0 / 2));
//			xaxisQZ_IK[8].setZ(sin(0 / 2));
//
//			xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));
//
//			//leftLowerLeg
//			qxIK[9].setW(cos(rhIK_theta2* PI / 180 / 2));
//			qxIK[9].setX(1 * sin(rhIK_theta2* PI / 180 / 2));
//			qxIK[9].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
//			qxIK[9].setZ(0 * sin(rhIK_theta2* PI / 180 / 2));
//
//			xaxisQX_IK[9].setW(cos(rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[9].setX(1 * sin(rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[9].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
//			xaxisQX_IK[9].setZ(0 * sin(rhIK_theta2* PI / 180 / 2));
//
//			xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[9].setX(0);
//			xaxisQY_IK[9].setY(sin(0 / 2));
//			xaxisQY_IK[9].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[9].setX(0);
//			xaxisQZ_IK[9].setY(sin(0 / 2));
//			xaxisQZ_IK[9].setZ(sin(0 / 2));
//
//			xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
//		}
//			
//
//
//		//=======================================================================================================================================================================
//		if (boneID == 500)
//		{
//			if (flag == 1)
//			{
//				animateffIK_PL(rhIK_theta1, rhIK_theta2, x, y, z);
//
//
//				// rightUpperLeg
//				qxIK[1].setW(cos((-rhIK_theta1 * 2.5)* PI / 180 / 2));
//				qxIK[1].setX(1 * sin((-rhIK_theta1 * 2.5)* PI / 180 / 2));
//				qxIK[1].setY(0 * sin((-rhIK_theta1 * 2.5) * PI / 180 / 2));
//				qxIK[1].setZ(0 * sin((-rhIK_theta1 * 2.5)* PI / 180 / 2));
//
//				xaxisQX_IK[1].setW(cos((-rhIK_theta1 * 2.5)* PI / 180 / 2));
//				xaxisQX_IK[1].setX(1 * sin((-rhIK_theta1 * 2.5)* PI / 180 / 2));
//				xaxisQX_IK[1].setY(0 * sin((-rhIK_theta1 * 2.5) * PI / 180 / 2));
//				xaxisQX_IK[1].setZ(0 * sin((-rhIK_theta1 * 2.5)* PI / 180 / 2));
//
//				xaxisQY_IK[1].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQY_IK[1].setX(0);
//				xaxisQY_IK[1].setY(sin(0 / 2));
//				xaxisQY_IK[1].setZ(sin(0 / 2));
//
//				xaxisQZ_IK[1].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQZ_IK[1].setX(0);
//				xaxisQZ_IK[1].setY(sin(0 / 2));
//				xaxisQZ_IK[1].setZ(sin(0 / 2));
//
//				xaxisQP_IK[1] = xaxisQX_IK[1].multiply(xaxisQY_IK[1].multiply(xaxisQZ_IK[1]));
//							   
//				if (ffIK_both == 1)
//				{
//
//					// rightUpperLeg
//					qxIK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//					xaxisQX_IK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//					xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQY_IK[6].setX(0);
//					xaxisQY_IK[6].setY(sin(0 / 2));
//					xaxisQY_IK[6].setZ(sin(0 / 2));
//
//					xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQZ_IK[6].setX(0);
//					xaxisQZ_IK[6].setY(sin(0 / 2));
//					xaxisQZ_IK[6].setZ(sin(0 / 2));
//
//					xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));
//
//					//rightLowerLeg
//					qxIK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//					xaxisQX_IK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//					xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQY_IK[7].setX(0);
//					xaxisQY_IK[7].setY(sin(0 / 2));
//					xaxisQY_IK[7].setZ(sin(0 / 2));
//
//					xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQZ_IK[7].setX(0);
//					xaxisQZ_IK[7].setY(sin(0 / 2));
//					xaxisQZ_IK[7].setZ(sin(0 / 2));
//
//					xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));
//
//
//					// leftUpperLeg
//					qxIK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//					xaxisQX_IK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//					xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQY_IK[8].setX(0);
//					xaxisQY_IK[8].setY(sin(0 / 2));
//					xaxisQY_IK[8].setZ(sin(0 / 2));
//
//					xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQZ_IK[8].setX(0);
//					xaxisQZ_IK[8].setY(sin(0 / 2));
//					xaxisQZ_IK[8].setZ(sin(0 / 2));
//
//					xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));
//
//					//leftLowerLeg
//					qxIK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//					xaxisQX_IK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//					xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQY_IK[9].setX(0);
//					xaxisQY_IK[9].setY(sin(0 / 2));
//					xaxisQY_IK[9].setZ(sin(0 / 2));
//
//					xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQZ_IK[9].setX(0);
//					xaxisQZ_IK[9].setY(sin(0 / 2));
//					xaxisQZ_IK[9].setZ(sin(0 / 2));
//
//					xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
//				}
//				if (ffIK_RF == 1)
//				{
//
//					// rightUpperLeg
//					qxIK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//					xaxisQX_IK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//					xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQY_IK[6].setX(0);
//					xaxisQY_IK[6].setY(sin(0 / 2));
//					xaxisQY_IK[6].setZ(sin(0 / 2));
//
//					xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQZ_IK[6].setX(0);
//					xaxisQZ_IK[6].setY(sin(0 / 2));
//					xaxisQZ_IK[6].setZ(sin(0 / 2));
//
//					xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));
//
//					//rightLowerLeg
//					qxIK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//					xaxisQX_IK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//					xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQY_IK[7].setX(0);
//					xaxisQY_IK[7].setY(sin(0 / 2));
//					xaxisQY_IK[7].setZ(sin(0 / 2));
//
//					xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQZ_IK[7].setX(0);
//					xaxisQZ_IK[7].setY(sin(0 / 2));
//					xaxisQZ_IK[7].setZ(sin(0 / 2));
//
//					xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));
//									   				
//				}
//				if (ffIK_LF == 1)
//				{
//					// leftUpperLeg
//					qxIK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//					qxIK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//					xaxisQX_IK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//					xaxisQX_IK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//					xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQY_IK[8].setX(0);
//					xaxisQY_IK[8].setY(sin(0 / 2));
//					xaxisQY_IK[8].setZ(sin(0 / 2));
//
//					xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQZ_IK[8].setX(0);
//					xaxisQZ_IK[8].setY(sin(0 / 2));
//					xaxisQZ_IK[8].setZ(sin(0 / 2));
//
//					xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));
//
//					//leftLowerLeg
//					qxIK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//					qxIK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//					xaxisQX_IK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//					xaxisQX_IK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//					xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQY_IK[9].setX(0);
//					xaxisQY_IK[9].setY(sin(0 / 2));
//					xaxisQY_IK[9].setZ(sin(0 / 2));
//
//					xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//					xaxisQZ_IK[9].setX(0);
//					xaxisQZ_IK[9].setY(sin(0 / 2));
//					xaxisQZ_IK[9].setZ(sin(0 / 2));
//
//					xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
//				}
//				
//
//
//
//
//			}
//			if (flag == 2)
//			{
//				animateffIK_xPL(rhIK_theta1, rhIK_theta2, x, y, z);
//							
//
//				// rightUpperLeg
//				qxIK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//				qxIK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//				qxIK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//				qxIK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//				xaxisQX_IK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//				xaxisQX_IK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//				xaxisQX_IK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//				xaxisQX_IK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//				xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQY_IK[6].setX(0);
//				xaxisQY_IK[6].setY(sin(0 / 2));
//				xaxisQY_IK[6].setZ(sin(0 / 2));
//
//				xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQZ_IK[6].setX(0);
//				xaxisQZ_IK[6].setY(sin(0 / 2));
//				xaxisQZ_IK[6].setZ(sin(0 / 2));
//
//				xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));
//
//				//rightLowerLeg
//				qxIK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//				qxIK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//				qxIK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//				qxIK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//				xaxisQX_IK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//				xaxisQX_IK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//				xaxisQX_IK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//				xaxisQX_IK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//				xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQY_IK[7].setX(0);
//				xaxisQY_IK[7].setY(sin(0 / 2));
//				xaxisQY_IK[7].setZ(sin(0 / 2));
//
//				xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQZ_IK[7].setX(0);
//				xaxisQZ_IK[7].setY(sin(0 / 2));
//				xaxisQZ_IK[7].setZ(sin(0 / 2));
//
//				xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));
//
//
//				// leftUpperLeg
//				qxIK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//				qxIK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//				qxIK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//				qxIK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//				xaxisQX_IK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
//				xaxisQX_IK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
//				xaxisQX_IK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//				xaxisQX_IK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//
//				xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQY_IK[8].setX(0);
//				xaxisQY_IK[8].setY(sin(0 / 2));
//				xaxisQY_IK[8].setZ(sin(0 / 2));
//
//				xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQZ_IK[8].setX(0);
//				xaxisQZ_IK[8].setY(sin(0 / 2));
//				xaxisQZ_IK[8].setZ(sin(0 / 2));
//
//				xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));
//
//				//leftLowerLeg
//				qxIK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//				qxIK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//				qxIK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//				qxIK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//				xaxisQX_IK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
//				xaxisQX_IK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
//				xaxisQX_IK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//				xaxisQX_IK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//
//				xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQY_IK[9].setX(0);
//				xaxisQY_IK[9].setY(sin(0 / 2));
//				xaxisQY_IK[9].setZ(sin(0 / 2));
//
//				xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//				xaxisQZ_IK[9].setX(0);
//				xaxisQZ_IK[9].setY(sin(0 / 2));
//				xaxisQZ_IK[9].setZ(sin(0 / 2));
//
//				xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
//			}
//			
//		}
//		
//		if (boneID == 510)
//		{
//			animateffIK_RH(rhIK_theta1, rhIK_theta2, x, y, z);
//			// rightUpperArm
//			qxIK[2].setW(cos(-rhIK_theta1* PI / 180 / 2));
//			qxIK[2].setX(1 * sin(-rhIK_theta1* PI / 180 / 2));
//			qxIK[2].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//			qxIK[2].setZ(0 * sin(-rhIK_theta1* PI / 180 / 2));
//
//			xaxisQX_IK[2].setW(cos(-rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[2].setX(1 * sin(-rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[2].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//			xaxisQX_IK[2].setZ(0 * sin(-rhIK_theta1* PI / 180 / 2));
//
//			xaxisQY_IK[2].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[2].setX(0);
//			xaxisQY_IK[2].setY(sin(0 / 2));
//			xaxisQY_IK[2].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[2].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[2].setX(0);
//			xaxisQZ_IK[2].setY(sin(0 / 2));
//			xaxisQZ_IK[2].setZ(sin(0 / 2));
//
//			xaxisQP_IK[2] = xaxisQX_IK[2].multiply(xaxisQY_IK[2].multiply(xaxisQZ_IK[2]));
//
//			//rightLowerArm
//			qxIK[3].setW(cos(-rhIK_theta2* PI / 180 / 2));
//			qxIK[3].setX(1 * sin(-rhIK_theta2* PI / 180 / 2));
//			qxIK[3].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//			qxIK[3].setZ(0 * sin(-rhIK_theta2* PI / 180 / 2));
//
//			xaxisQX_IK[3].setW(cos(-rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[3].setX(1 * sin(-rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[3].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//			xaxisQX_IK[3].setZ(0 * sin(-rhIK_theta2* PI / 180 / 2));
//
//			xaxisQY_IK[3].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[3].setX(0);
//			xaxisQY_IK[3].setY(sin(0 / 2));
//			xaxisQY_IK[3].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[3].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[3].setX(0);
//			xaxisQZ_IK[3].setY(sin(0 / 2));
//			xaxisQZ_IK[3].setZ(sin(0 / 2));
//
//			xaxisQP_IK[3] = xaxisQX_IK[3].multiply(xaxisQY_IK[3].multiply(xaxisQZ_IK[3]));
//					   			 
//
//		}
//		if (boneID == 511)
//		{
//			animateffIK_LH(rhIK_theta1, rhIK_theta2, x, y, z);
//
//			// leftUpperArm
//			qxIK[4].setW(cos(-rhIK_theta1* PI / 180 / 2));
//			qxIK[4].setX(1 * sin(-rhIK_theta1* PI / 180 / 2));
//			qxIK[4].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//			qxIK[4].setZ(0 * sin(-rhIK_theta1* PI / 180 / 2));
//
//			xaxisQX_IK[4].setW(cos(-rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[4].setX(1 * sin(-rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[4].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
//			xaxisQX_IK[4].setZ(0 * sin(-rhIK_theta1* PI / 180 / 2));
//
//			xaxisQY_IK[4].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[4].setX(0);
//			xaxisQY_IK[4].setY(sin(0 / 2));
//			xaxisQY_IK[4].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[4].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[4].setX(0);
//			xaxisQZ_IK[4].setY(sin(0 / 2));
//			xaxisQZ_IK[4].setZ(sin(0 / 2));
//
//			xaxisQP_IK[4] = xaxisQX_IK[4].multiply(xaxisQY_IK[4].multiply(xaxisQZ_IK[4]));
//
//			//LeftLowerArm
//			qxIK[5].setW(cos(-rhIK_theta2* PI / 180 / 2));
//			qxIK[5].setX(1 * sin(-rhIK_theta2* PI / 180 / 2));
//			qxIK[5].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//			qxIK[5].setZ(0 * sin(-rhIK_theta2* PI / 180 / 2));
//
//			xaxisQX_IK[5].setW(cos(-rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[5].setX(1 * sin(-rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[5].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
//			xaxisQX_IK[5].setZ(0 * sin(-rhIK_theta2* PI / 180 / 2));
//
//			xaxisQY_IK[5].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[5].setX(0);
//			xaxisQY_IK[5].setY(sin(0 / 2));
//			xaxisQY_IK[5].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[5].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[5].setX(0);
//			xaxisQZ_IK[5].setY(sin(0 / 2));
//			xaxisQZ_IK[5].setZ(sin(0 / 2));
//
//			xaxisQP_IK[5] = xaxisQX_IK[5].multiply(xaxisQY_IK[5].multiply(xaxisQZ_IK[5]));
//		}
//		
//		//========================================================================================================================================================================
//		
//		
//		
//		if (boneID == 1003)
//		{
//			animateFreeLF(-rhIK_theta1, -rhIK_theta2, x, y, z);
//					   
//			// leftUpperLeg
//			qxIK[8].setW(cos(rhIK_theta1* PI / 180 / 2));
//			qxIK[8].setX(1 * sin(rhIK_theta1* PI / 180 / 2));
//			qxIK[8].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
//			qxIK[8].setZ(0 * sin(rhIK_theta1* PI / 180 / 2));
//
//			xaxisQX_IK[8].setW(cos(rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[8].setX(1 * sin(rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[8].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
//			xaxisQX_IK[8].setZ(0 * sin(rhIK_theta1* PI / 180 / 2));
//
//			xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[8].setX(0);
//			xaxisQY_IK[8].setY(sin(0 / 2));
//			xaxisQY_IK[8].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[8].setX(0);
//			xaxisQZ_IK[8].setY(sin(0 / 2));
//			xaxisQZ_IK[8].setZ(sin(0 / 2));
//
//			xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));
//
//			//leftLowerLeg
//			qxIK[9].setW(cos(rhIK_theta2* PI / 180 / 2));
//			qxIK[9].setX(1 * sin(rhIK_theta2* PI / 180 / 2));
//			qxIK[9].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
//			qxIK[9].setZ(0 * sin(rhIK_theta2* PI / 180 / 2));
//
//			xaxisQX_IK[9].setW(cos(rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[9].setX(1 * sin(rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[9].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
//			xaxisQX_IK[9].setZ(0 * sin(rhIK_theta2* PI / 180 / 2));
//
//			xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[9].setX(0);
//			xaxisQY_IK[9].setY(sin(0 / 2));
//			xaxisQY_IK[9].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[9].setX(0);
//			xaxisQZ_IK[9].setY(sin(0 / 2));
//			xaxisQZ_IK[9].setZ(sin(0 / 2));
//
//			xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
//		}
//		if (boneID == 2003)
//		{
//			animateFreeRF(-rhIK_theta1, -rhIK_theta2, x, y, z);
//
//			// rightUpperLeg
//			qxIK[6].setW(cos(rhIK_theta1* PI / 180 / 2));
//			qxIK[6].setX(1 * sin(rhIK_theta1* PI / 180 / 2));
//			qxIK[6].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
//			qxIK[6].setZ(0 * sin(rhIK_theta1* PI / 180 / 2));
//
//			xaxisQX_IK[6].setW(cos(rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[6].setX(1 * sin(rhIK_theta1* PI / 180 / 2));
//			xaxisQX_IK[6].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
//			xaxisQX_IK[6].setZ(0 * sin(rhIK_theta1* PI / 180 / 2));
//
//			xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[6].setX(0);
//			xaxisQY_IK[6].setY(sin(0 / 2));
//			xaxisQY_IK[6].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[6].setX(0);
//			xaxisQZ_IK[6].setY(sin(0 / 2));
//			xaxisQZ_IK[6].setZ(sin(0 / 2));
//
//			xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));
//
//			//rightLowerLeg
//			qxIK[7].setW(cos(rhIK_theta2* PI / 180 / 2));
//			qxIK[7].setX(1 * sin(rhIK_theta2* PI / 180 / 2));
//			qxIK[7].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
//			qxIK[7].setZ(0 * sin(rhIK_theta2* PI / 180 / 2));
//
//			xaxisQX_IK[7].setW(cos(rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[7].setX(1 * sin(rhIK_theta2* PI / 180 / 2));
//			xaxisQX_IK[7].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
//			xaxisQX_IK[7].setZ(0 * sin(rhIK_theta2* PI / 180 / 2));
//
//			xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQY_IK[7].setX(0);
//			xaxisQY_IK[7].setY(sin(0 / 2));
//			xaxisQY_IK[7].setZ(sin(0 / 2));
//
//			xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
//			xaxisQZ_IK[7].setX(0);
//			xaxisQZ_IK[7].setY(sin(0 / 2));
//			xaxisQZ_IK[7].setZ(sin(0 / 2));
//
//			xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));
//
//		}
//		//========================================================================================================================================================================
//
//
//
//		if (ffIK_both == 0 && ffIK_RF==0 && ffIK_LF==0)
//		{
//			qxIK[1] = qx[1];
//			xaxisQP_IK[1] = xaxisQP[1];
//
//
//		/*	qxIK[2] = qx[2];
//			xaxisQP_IK[2] = xaxisQP[2];*/
//		}
//
//		
//
//	}
//
//	virtual void OnMouseMove()
//	{
//		if (this->Move)
//		{
//
//			screenX = this->Interactor->GetEventPosition()[0];
//			screenY = this->Interactor->GetEventPosition()[1];
//
//			screenDiff = screenTemp + screenY;
//
//
//			if (boneID == 2220) //Pelvis
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//
//				diff = temp + y;
//				if (flag == 1)
//				{
//					if (diff > prevY)
//					{
//						//pelvis_Planted_key(1);
//					}
//					if (diff < prevY)
//					{
//						//pelvis_Planted_key(-1);
//					}
//					prevY = diff;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//						//pelvis_Planted_key(1);
//					}
//					if (diff < prevY)
//					{
//						//pelvis_Planted_key(-1);
//					}
//					prevY = diff;
//
//				}
//
//				
//
//			}
//			if (boneID == 2221) //Chest
//
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//				
//				diff = temp + y;
//
//				if (flag == 1)
//				{
//					if (diff > prevY)
//					{
//					/*	compute(chest_angle, chest_x, chest_y, chest_z, boneID);
//						chest_angle += 4;
//						CHEST(anim_chest_angle, -anim_chest_x, -anim_chest_y, -anim_chest_z);*/
//
//						compute(chest_angleX, chest_x, chest_y, chest_z, boneID);
//						chest_angleX += 4;
//						CHEST(anim_chest_angle, -anim_chest_x, -anim_chest_y, -anim_chest_z);
//					}
//
//					if (diff < prevY)
//					{
//					/*	compute(chest_angle, chest_x, chest_y, chest_z, boneID);
//						chest_angle -= 4;
//						CHEST(anim_chest_angle, anim_chest_x, anim_chest_y, anim_chest_z);*/
//						
//						chest_angleX -= 4;
//						compute(chest_angleX, chest_x, chest_y, chest_z, boneID);
//						CHEST(anim_chest_angle, anim_chest_x, anim_chest_y, anim_chest_z);
//					}
//					prevY = diff;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//						compute(chest_angleZ, chest_x, chest_y, chest_z, boneID);
//						chest_angleZ+= 4;
//						CHEST(anim_chest_angle, -anim_chest_x, -anim_chest_y, -anim_chest_z);
//					}
//
//					if (diff < prevY)
//					{
//						
//						chest_angleZ -= 4;
//						compute(chest_angleZ, chest_x, chest_y, chest_z, boneID);
//						CHEST(anim_chest_angle, anim_chest_x, anim_chest_y, anim_chest_z);
//					}
//					prevY = diff;
//				}
//
//			}
//
//			if (boneID == 2222) //RUA
//			{
//
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//
//				diff = temp + y;
//				if (flag == 1)
//				{
//					if (diff > prevY)
//					{
//						/*compute(rua_angle, rua_x, rua_y, rua_z, boneID);
//						rua_angle += 4;
//						rua(anim_rua_angle, -anim_rua_x, -anim_rua_y, -anim_rua_z);*/
//						//rua_angleX += 4;
//
//						compute(rua_angleX, rua_x, rua_y, rua_z, boneID);
//						rua_angleX += 4;
//						rua(anim_rua_angle, -anim_rua_x, -anim_rua_y, -anim_rua_z);
//
//					}
//
//					if (diff < prevY)
//					{
//						/*	compute(rua_angle, rua_x, rua_y, rua_z, boneID);
//							rua_angle -= 4;
//							rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);*/
//
//							//rua_angleX -= 4;
//						rua_angleX -= 4;
//						compute(rua_angleX, rua_x, rua_y, rua_z, boneID);
//						rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);
//
//					}
//					prevY = diff;
//					//cout << "ruaX_angle=" << rua_angleX << endl;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//						compute(rua_angleZ, rua_x, rua_y, rua_z, boneID);
//						rua_angleZ += 4;
//						rua(anim_rua_angle, -anim_rua_x, -anim_rua_y, -anim_rua_z);
//
//						//rua_angleZ += 4;
//					}
//					if (diff < prevY)
//					{
//						//rua_angleZ -= 4;
//						rua_angleZ -= 4;
//						compute(rua_angleZ, rua_x, rua_y, rua_z, boneID);
//						rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);
//					}
//					prevY = diff;
//					//cout << "ruaZ_angle=" << rua_angleZ << endl;
//				}
//
//
//			}
//			if (boneID == 2223) //RLA
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//
//				diff = temp + y;
//
//				// Use this while interacting Lowerarm Actor
//
//				if (flag == 1)
//				{
//					if (diff > prevY)
//					{
//						/*		compute(rla_angle, rla_x, rla_y, rla_z, boneID);
//								rla_angle += 4;
//								rla(anim_rla_angle, -anim_rla_x, -anim_rla_y, -anim_rla_z);*/
//
//						compute(rla_angleX, rla_x, rla_y, rla_z, boneID);
//						rla_angleX += 4;
//						rla(anim_rla_angle, -anim_rla_x, -anim_rla_y, -anim_rla_z);
//					}
//					if (diff < prevY)
//					{
//						/*	compute(rla_angle, rla_x, rla_y, rla_z, boneID);
//							rla_angle -= 4;
//							rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);*/
//						rla_angleX -= 4;
//						compute(rla_angleX, rla_x, rla_y, rla_z, boneID);
//						rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);
//					}
//					prevY = diff;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//						/*compute(rla_angle, rla_x, rla_y, rla_z, boneID);
//						rla_angle += 4;
//						rla(anim_rla_angle, -anim_rla_x, -anim_rla_y, -anim_rla_z);*/
//						compute(rla_angleZ, rla_x, rla_y, rla_z, boneID);
//						rla_angleZ += 4;
//						rla(anim_rla_angle, -anim_rla_x, -anim_rla_y, -anim_rla_z);
//					}
//					if (diff < prevY)
//					{
//						/*compute(rla_angle, rla_x, rla_y, rla_z, boneID);
//						rla_angle -= 4;
//						rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);*/
//
//						rla_angleZ -= 4;
//						compute(rla_angleZ, rla_x, rla_y, rla_z, boneID);
//						rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);
//					}
//					prevY = diff;
//				}
//			}
//
//			if (boneID == 2224)//LUA
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//				
//				diff = temp + y;
//
//				if (flag == 1)
//				{
//					if (diff > prevY)
//					{
//
//						/*compute(lua_angle, lua_x, lua_y, lua_z, boneID);
//						lua_angle += 4;
//						lua(anim_lua_angle, -anim_lua_x, -anim_lua_y, -anim_lua_z);*/
//						compute(lua_angleX, lua_x, lua_y, lua_z, boneID);
//						lua_angleX += 4;
//						lua(anim_lua_angle, -anim_lua_x, -anim_lua_y, -anim_lua_z);
//
//					}
//
//					if (diff < prevY)
//					{
//						lua_angleX -= 4;
//						compute(lua_angleX, lua_x, lua_y, lua_z, boneID);
//						lua(anim_lua_angle, anim_lua_x, anim_lua_y, anim_lua_z);
//					}
//					prevY = diff;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//
//						compute(lua_angleZ, lua_x, lua_y, lua_z, boneID);
//						lua_angleZ += 4;
//						lua(anim_lua_angle, -anim_lua_x, -anim_lua_y, -anim_lua_z);
//
//					}
//
//					if (diff < prevY)
//					{
//						lua_angleZ -= 4;
//						compute(lua_angleZ, lua_x, lua_y, lua_z, boneID);
//						lua(anim_lua_angle, anim_lua_x, anim_lua_y, anim_lua_z);
//					}
//					prevY = diff;
//
//				}
//				
//
//			}
//			if (boneID == 2225) //LLA
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//				
//				diff = temp + y;
//
//				if (flag == 1)
//				{
//					if (diff > prevY)
//					{
//						/*compute(lla_angle, lla_x, lla_y, lla_z, boneID);
//						lla_angle += 4;
//						lla(anim_lla_angle, -anim_lla_x, -anim_lla_y, -anim_lla_z);*/
//						compute(lla_angleX, lla_x, lla_y, lla_z, boneID);
//						lla_angleX += 4;
//						lla(anim_lla_angle, -anim_lla_x, -anim_lla_y, -anim_lla_z);
//					}
//
//					if (diff < prevY)
//					{
//					/*	compute(lla_angle, lla_x, lla_y, lla_z, boneID);
//						lla_angle -= 4;
//						lla(anim_lla_angle, anim_lla_x, anim_lla_y, anim_lla_z);*/
//						lla_angleX -= 4;
//						compute(lla_angleX, lla_x, lla_y, lla_z, boneID);
//						lla(anim_lla_angle, anim_lla_x, anim_lla_y, anim_lla_z);
//					}
//					prevY = diff;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//						
//						compute(lla_angleZ, lla_x, lla_y, lla_z, boneID);
//						lla_angleZ += 4;
//						lla(anim_lla_angle, -anim_lla_x, -anim_lla_y, -anim_lla_z);
//					}
//
//					if (diff < prevY)
//					{
//
//						lla_angleZ -= 4;
//						compute(lla_angleZ, lla_x, lla_y, lla_z, boneID);
//						lla(anim_lla_angle, anim_lla_x, anim_lla_y, anim_lla_z);
//					}
//					prevY = diff;
//				}
//				
//
//			}
//
//			if (boneID == 2226)//RUL
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (flag == 1)
//				{
//					
//					if (diff > prevY)
//					{
//						/*compute(rul_angle, rul_x, rul_y, rul_z, boneID);
//						rul_angle += 4;
//						rul(anim_rul_angle, -anim_rul_x, -anim_rul_y, -anim_rul_z);*/
//						compute(rul_angleX, rul_x, rul_y, rul_z, boneID);
//						rul_angleX += 4;
//						rul(anim_rul_angle, -anim_rul_x, -anim_rul_y, -anim_rul_z);
//					}
//
//					if (diff < prevY)
//					{
//					/*	compute(rul_angle, rul_x, rul_y, rul_z, boneID);
//						rul_angle -= 4;
//						rul(anim_rul_angle, anim_rul_x, anim_rul_y, anim_rul_z);*/
//						rul_angleX -= 4;
//						compute(rul_angleX, rul_x, rul_y, rul_z, boneID);
//						rul(anim_rul_angle, anim_rul_x, anim_rul_y, anim_rul_z);
//					}
//					prevY = diff;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//					
//						compute(rul_angleZ, rul_x, rul_y, rul_z, boneID);
//						rul_angleZ += 4;
//						rul(anim_rul_angle, -anim_rul_x, -anim_rul_y, -anim_rul_z);
//					}
//
//					if (diff < prevY)
//					{
//						rul_angleZ -= 4;
//						compute(rul_angleZ, rul_x, rul_y, rul_z, boneID);
//					
//						rul(anim_rul_angle, anim_rul_x, anim_rul_y, anim_rul_z);
//					}
//					prevY = diff;
//
//				}
//			}
//			if (boneID == 2227)//RLL
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//				
//				diff = temp + y;
//				if (flag == 1)
//				{
//					if (diff > prevY)
//					{
//						/*compute(rll_angle, rll_x, rll_y, rll_z, boneID);
//						rll_angle += 4;
//						rll(anim_rll_angle, -anim_rll_x, -anim_rll_y, -anim_rll_z)*/;
//						compute(rll_angleX, rll_x, rll_y, rll_z, boneID);
//						rll_angleX += 4;
//						rll(anim_rll_angle, -anim_rll_x, -anim_rll_y, -anim_rll_z);
//					}
//
//					if (diff < prevY)
//					{
//					/*	compute(rll_angle, rll_x, rll_y, rll_z, boneID);
//						rll_angle -= 4;
//						rll(anim_rll_angle, anim_rll_x, anim_rll_y, anim_rll_z);*/
//						rll_angleX -= 4;
//						compute(rll_angleX, rll_x, rll_y, rll_z, boneID);
//						rll(anim_rll_angle, anim_rll_x, anim_rll_y, anim_rll_z);
//					}
//					prevY = diff;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//						
//					compute(rll_angleZ, rll_x, rll_y, rll_z, boneID);
//					rll_angleZ += 4;
//					rll(anim_rll_angle, -anim_rll_x, -anim_rll_y, -anim_rll_z);
//					}
//
//					if (diff < prevY)
//					{
//					
//						rll_angleZ -= 4;
//						compute(rll_angleZ, rll_x, rll_y, rll_z, boneID);
//						rll(anim_rll_angle, anim_rll_x, anim_rll_y, anim_rll_z);
//					}
//					prevY = diff;
//				}
//			}
//
//			if (boneID == 2228)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//				
//				diff = temp + y;
//
//				if (flag == 1)
//				{
//					if (diff > prevY)
//					{
//				/*		compute(lul_angle, lul_x, lul_y, lul_z, boneID);
//						lul_angle += 4;
//						lul(anim_lul_angle, -anim_lul_x, -anim_lul_y, -anim_lul_z);*/
//
//						compute(lul_angleX, lul_x, lul_y, lul_z, boneID);
//						lul_angleX += 4;
//						lul(anim_lul_angle, -anim_lul_x, -anim_lul_y, -anim_lul_z);
//
//					}
//
//					if (diff < prevY)
//					{
//					/*	compute(lul_angle, lul_x, lul_y, lul_z, boneID);
//						lul_angle -= 4;
//						lul(anim_lul_angle, anim_lul_x, anim_lul_y, anim_lul_z);*/
//						
//						lul_angleX -= 4;
//						compute(lul_angleX, lul_x, lul_y, lul_z, boneID);
//						lul(anim_lul_angle, anim_lul_x, anim_lul_y, anim_lul_z);
//					}
//					prevY = diff;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//						compute(lul_angleZ, lul_x, lul_y, lul_z, boneID);
//						lul_angleZ += 4;
//						lul(anim_lul_angle, -anim_lul_x, -anim_lul_y, -anim_lul_z);
//
//					}
//
//					if (diff < prevY)
//					{
//						lul_angleZ -= 4;
//						compute(lul_angleZ, lul_x, lul_y, lul_z, boneID);
//						lul(anim_lul_angle, anim_lul_x, anim_lul_y, anim_lul_z);
//					}
//					prevY = diff;
//				}
//			}
//			if (boneID == 2229)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//				
//				diff = temp + y;
//
//				if (flag == 1)
//				{
//
//					if (diff > prevY)
//					{
//						/*compute(lll_angle, lll_x, lll_y, lll_z, boneID);
//						lll_angle += 4;
//						lll(anim_lll_angle, -anim_lll_x, -anim_lll_y, -anim_lll_z);*/
//						compute(lll_angleX, lll_x, lll_y, lll_z, boneID);
//						lll_angleX += 4;
//						lll(anim_lll_angle, -anim_lll_x, -anim_lll_y, -anim_lll_z);
//					}
//
//					if (diff < prevY)
//					{
//						lll_angleX -= 4;
//						compute(lll_angleX, lll_x, lll_y, lll_z, boneID);
//						lll(anim_lll_angle, anim_lll_x, anim_lll_y, anim_lll_z);
//					}
//					prevY = diff;
//				}
//				if (flag == 2)
//				{
//					if (diff > prevY)
//					{
//				
//						compute(lll_angleZ, lll_x, lll_y, lll_z, boneID);
//						lll_angleZ += 4;
//						lll(anim_lll_angle, -anim_lll_x, -anim_lll_y, -anim_lll_z);
//					}
//
//					if (diff < prevY)
//					{
//						lll_angleZ -= 4;
//						compute(lll_angleZ, lll_x, lll_y, lll_z, boneID);
//						lll(anim_lll_angle, anim_lll_x, anim_lll_y, anim_lll_z);
//					}
//					prevY = diff;
//
//				}
//			}
//			
//
//			if (screenDiff > screenPrev)
//			{
//				if (flag == 1)
//				{
//					if (boneID == 0)
//					{
//
//					}
//					if (boneID == 1)
//					{
//						SMch0_angleX += 4;
//						animateSM_CH0(SManim_ch0_angleX, -SMch0_x, -SMch0_y, -SMch0_z);
//						compute(SMch0_angleX, SMch0_x, SMch0_y, SMch0_z, boneID);
//						renderWindow->Render();
//					}
//					
//					if (boneID == 103)
//					{
//				
//					}
//					if (boneID == 104)
//					{
//
//					}
//					if (boneID == 105)
//					{
//
//					}
//					if (boneID == 106)
//					{
//
//					}
//					if (boneID == 2)
//					{
//						SMrua_angleX += 4;
//						animateSM_RUA(SManim_rua_angleX, -SMrua_x, -SMrua_y, -SMrua_z);
//						compute(SMrua_angleX, SMrua_x, SMrua_y, SMrua_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 3)
//					{
//						SMrla_angleX += 4;
//						animateSM_RLA(SManim_rla_angleX, -SMrla_x, -SMrla_y, -SMrla_z);
//						compute(SMrla_angleX, SMrla_x, SMrla_y, SMrla_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 10)
//					{
//						
//						computeSM_ikRH(rhIK_Targetx, rhIK_Targety, SMrh_x, SMrh_y, SMrh_z, boneID);
//						rhIK_Targetx--;
//					}
//					if (boneID == 109)
//					{
//						SMrh_angleX -= 4;
//						animateSM_RH(SMrh_angleX);
//						renderWindow->Render();
//					}
//					if (boneID == 4)
//					{
//						SMlua_angleX += 4;
//						animateSM_LUA(SManim_lua_angleX, -SMlua_x, -SMlua_y, -SMlua_z);
//						compute(SMlua_angleX, SMlua_x, SMlua_y, SMlua_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 5)
//					{
//						SMlla_angleX += 4;
//						animateSM_LLA(SManim_lla_angleX, -SMlla_x, -SMlla_y, -SMlla_z);
//						compute(SMlla_angleX, SMlla_x, SMlla_y, SMlla_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 15)
//					{
//
//						computeSM_ikRH(lhIK_Targetx, lhIK_Targety, SMlh_x, SMlh_y, SMlh_z, boneID);
//						lhIK_Targetx--;
//					}
//					if (boneID == 112)
//					{
//						SMlh_angleX -= 4;
//						animateSM_LH(SMlh_angleX);
//						renderWindow->Render();
//					}
//					if (boneID == 6)
//					{
//						SMrul_angleX += 4;
//						animateSM_RUL(SManim_rul_angleX, -SMrul_x, -SMrul_y, -SMrul_z);
//						compute(SMrul_angleX, SMrul_x, SMrul_y, SMrul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 7)
//					{
//						SMrll_angleX += 4;
//						animateSM_RLL(SManim_rll_angleX, -SMrll_x, -SMrll_y, -SMrll_z);
//						compute(SMrll_angleX, SMrll_x, SMrll_y, SMrll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 16)
//					{
//						computeSM_ikRH(rfIK_Targetx, rfIK_Targety, SMrf_x, SMrf_y, SMrf_z, boneID);
//						rfIK_Targetx--;
//					}
//					if (boneID == 115)
//					{
//						SMrf_angleX -= 4;
//						animateSM_RF(SMrf_angleX);
//						renderWindow->Render();
//					}
//					if (boneID == 8)
//					{
//						SMlul_angleX += 4;
//						animateSM_LUL(SManim_lul_angleX, -SMlul_x, -SMlul_y, -SMlul_z);
//						compute(SMlul_angleX, SMlul_x, SMlul_y, SMlul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 9)
//					{
//						SMlll_angleX += 4;
//						animateSM_LLL(SManim_lll_angleX, -SMlll_x, -SMlll_y, -SMlll_z);
//						compute(SMlll_angleX, SMlll_x, SMlll_y, SMlll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 21)
//					{
//						computeSM_ikRH(lfIK_Targetx, lfIK_Targety, SMlf_x, SMlf_y, SMlf_z, boneID);
//						lfIK_Targetx--;
//					}
//					if (boneID == 118)
//					{
//						SMlf_angleX -= 4;
//						animateSM_LF(SMlf_angleX);
//						renderWindow->Render();
//
//					}
//
//
//					//===================================================================================
//					if (boneID == 500)
//					{
//						ffIK_rfTargetx++;
//						computeSM_ikRH(ffIK_rfTargetx, ffIK_rfTargety, ffIKpl_x, ffIKpl_y, ffIKpl_z, boneID);
//								
//						renderWindow->Render();
//					}
//					if (boneID == 501)
//					{
//						ffIKch0_angleX += 4;
//						animateffIK_CH0(ffIKanim_ch0_angleX, -ffIKch0_x, -ffIKch0_y, -ffIKch0_z);
//						compute(ffIKch0_angleX, ffIKch0_x, ffIKch0_y, ffIKch0_z, boneID);
//						renderWindow->Render();
//					}
//
//
//					if (boneID == 502)
//					{
//						ffIKrua_angleX += 4;
//						animateffIK_RUA(ffIKanim_rua_angleX, -ffIKrua_x, -ffIKrua_y, -ffIKrua_z);
//						compute(ffIKrua_angleX, ffIKrua_x, ffIKrua_y, ffIKrua_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 503)
//					{
//						ffIKrla_angleX += 4;
//						animateffIK_RLA(ffIKanim_rla_angleX, -ffIKrla_x, -ffIKrla_y, -ffIKrla_z);
//						compute(ffIKrla_angleX, ffIKrla_x, ffIKrla_y, ffIKrla_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 50) 
//					{
//						// Noram Hand Segment rotation //refer 109 ID
//					}
//					if (boneID == 510)
//					{
//						computeSM_ikRH(ffIK_rhTargetX, ffIK_rhTargetY, ffIKrh_x, ffIKrh_y, ffIKrh_z, boneID);
//						ffIK_rhTargetX--;
//					}
//					if (boneID == 504)
//					{
//						ffIKlua_angleX += 4;
//						animateffIK_LUA(ffIKanim_lua_angleX, -ffIKlua_x, -ffIKlua_y, -ffIKlua_z);
//						compute(ffIKlua_angleX, ffIKlua_x, ffIKlua_y, ffIKlua_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 505)
//					{
//						ffIKlla_angleX += 4;
//						animateffIK_LLA(ffIKanim_lla_angleX, -ffIKlla_x, -ffIKlla_y, -ffIKlla_z);
//						compute(ffIKlla_angleX, ffIKlla_x, ffIKlla_y, ffIKlla_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 51)
//					{
//
//					}
//					if (boneID == 511)
//					{
//
//						computeSM_ikRH(ffIK_lhTargetX, ffIK_lhTargetY, ffIKlh_x, ffIKlh_y, ffIKlh_z, boneID);
//						ffIK_lhTargetX--;
//					}
//					
//					if (boneID == 506)
//					{
//						ffIKrul_angleX += 4;
//						animateffIK_RUL(ffIKanim_rul_angleX, -ffIKrul_x, -ffIKrul_y, -ffIKrul_z);
//						//compute(ffIKrul_angleX, ffIKrul_x, ffIKrul_y, ffIKrul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 507)
//					{
//						ffIKrll_angleX += 4;
//						animateffIK_RLL(ffIKanim_rll_angleX, -ffIKrll_x, -ffIKrll_y, -ffIKrll_z);
//						//compute(ffIKrll_angleX, ffIKrll_x, ffIKrll_y, ffIKrll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 52)
//					{
//
//					}
//					if (boneID == 512)
//					{
//
//					}
//
//					if (boneID == 508)
//					{
//						ffIKlul_angleX += 4;
//						animateffIK_LUL(ffIKanim_lul_angleX, -ffIKlul_x, -ffIKlul_y, -ffIKlul_z);
//						//compute(ffIKlul_angleX, ffIKlul_x, ffIKlul_y, ffIKlul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 509)
//					{
//						ffIKlll_angleX += 4;
//						animateffIK_LLL(ffIKanim_lll_angleX, -ffIKlll_x, -ffIKlll_y, -ffIKlll_z);
//						//compute(ffIKlll_angleX, ffIKlll_x, ffIKlll_y, ffIKlll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 53)
//					{
//
//					}
//					if (boneID == 513)
//					{
//
//					}
//
//					//===============================================================================
//					if (boneID == 1003)
//					{
//						
//						computeSM_ikRH(freeLF_Targetx, freeLF_Targety, freeLF_x, freeLF_y, freeLF_z, boneID);
//						freeLF_Targetx--;
//					}
//					if (boneID == 2003)
//					{
//
//						computeSM_ikRH(freeRF_Targetx, freeRF_Targety, freeRF_x, freeRF_y, freeRF_z, boneID);
//						freeRF_Targetx--;
//					}
//
//					//================================================================================
//
//
//
//				}
//				if (flag == 2)
//				{
//					if (boneID == 0)
//					{
//
//					}
//					if (boneID == 1)
//					{
//						SMch0_angleZ += 4;
//						animateSM_CH0(SManim_ch0_angleZ, -SMch0_x, -SMch0_y, -SMch0_z);
//						compute(SMch0_angleZ, SMch0_x, SMch0_y, SMch0_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 2)
//					{
//						SMrua_angleZ += 4;
//						animateSM_RUA(SManim_rua_angleZ, -SMrua_x, -SMrua_y, -SMrua_z);
//						compute(SMrua_angleZ, SMrua_x, SMrua_y, SMrua_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 3)
//					{
//						SMrla_angleZ += 4;
//						animateSM_RLA(SManim_rla_angleZ, -SMrla_x, -SMrla_y, -SMrla_z);
//						compute(SMrla_angleZ, SMrla_x, SMrla_y, SMrla_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 10)
//					{
//						computeSM_ikRH(rhIK_Targetx, rhIK_Targety, SMrh_x, SMrh_y, SMrh_z, boneID);
//						rhIK_Targety--;
//					}
//					if (boneID == 4)
//					{
//						SMlua_angleZ += 4;
//						animateSM_LUA(SManim_lua_angleZ, SMlua_x, SMlua_y, SMlua_z);
//						compute(SMlua_angleZ, -SMlua_x, -SMlua_y, -SMlua_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 5)
//					{
//						SMlla_angleZ += 4;
//						animateSM_LLA(SManim_lla_angleZ, SMlla_x, SMlla_y, SMlla_z);
//						compute(SMlla_angleZ, -SMlla_x, -SMlla_y, -SMlla_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 15)
//					{
//						computeSM_ikRH(lhIK_Targetx, lhIK_Targety, SMlh_x, SMlh_y, SMlh_z, boneID);
//						lhIK_Targety--;
//					}
//					if (boneID == 6)
//					{
//						SMrul_angleZ += 4;
//						animateSM_RUL(SManim_rul_angleZ, -SMrul_x, -SMrul_y, -SMrul_z);
//						compute(SMrul_angleZ, SMrul_x, SMrul_y, SMrul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 7)
//					{
//						SMrll_angleZ += 4;
//						animateSM_RLL(SManim_rll_angleZ, -SMrll_x, -SMrll_y, -SMrll_z);
//						compute(SMrll_angleZ, SMrll_x, SMrll_y, SMrll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 16)
//					{
//						computeSM_ikRH(rfIK_Targetx, rfIK_Targety, SMrf_x, SMrf_y, SMrf_z, boneID);
//						rfIK_Targety--;
//					}
//					if (boneID == 8)
//					{
//						SMlul_angleZ += 4;
//						animateSM_LUL(SManim_lul_angleZ, SMlul_x, SMlul_y, SMlul_z);
//						compute(SMlul_angleZ, -SMlul_x, -SMlul_y, -SMlul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 9)
//					{
//						SMlll_angleZ += 4;
//						animateSM_LLL(SManim_lll_angleZ, SMlll_x, SMlll_y, SMlll_z);
//						compute(SMlll_angleZ, -SMlll_x, -SMlll_y, -SMlll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 21)
//					{
//						computeSM_ikRH(lfIK_Targetx, lfIK_Targety, SMlf_x, SMlf_y, SMlf_z, boneID);
//						lfIK_Targety--;
//					}
//
//					//=========================================================
//					if (boneID == 500)
//					{
//						ffIK_rfTargety++;
//						computeSM_ikRH(ffIK_rfTargetx, ffIK_rfTargety, ffIKpl_x, ffIKpl_y, ffIKpl_z, boneID);
//					}
//					if (boneID == 501)
//					{
//						ffIKch0_angleZ += 4;
//						animateffIK_CH0(ffIKanim_ch0_angleZ, -ffIKch0_x, -ffIKch0_y, -ffIKch0_z);
//						compute(ffIKch0_angleZ, ffIKch0_x, ffIKch0_y, ffIKch0_z, boneID);
//						renderWindow->Render();
//					}
//
//					if (boneID == 502)
//					{
//						ffIKrua_angleZ += 4;
//						animateffIK_RUA(ffIKanim_rua_angleZ, -ffIKrua_x, -ffIKrua_y, -ffIKrua_z);
//						compute(ffIKrua_angleZ, ffIKrua_x, ffIKrua_y, ffIKrua_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 503)
//					{
//						ffIKrla_angleZ += 4;
//						animateffIK_RLA(ffIKanim_rla_angleZ, -ffIKrla_x, -ffIKrla_y, -ffIKrla_z);
//						compute(ffIKrla_angleZ, ffIKrla_x, ffIKrla_y, ffIKrla_z, boneID - 500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 510)
//					{
//						computeSM_ikRH(ffIK_rhTargetX, ffIK_rhTargetY, ffIKrh_x, ffIKrh_y, ffIKrh_z, boneID);
//						ffIK_rhTargetY--;
//					}
//					
//					if (boneID == 504)
//					{
//						ffIKlua_angleZ += 4;
//						animateffIK_LUA(ffIKanim_lua_angleZ, ffIKlua_x, ffIKlua_y, ffIKlua_z);
//						compute(ffIKlua_angleZ, -ffIKlua_x, -ffIKlua_y, -ffIKlua_z, boneID - 500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 505)
//					{
//						ffIKlla_angleZ += 4;
//						animateffIK_LLA(ffIKanim_lla_angleZ, ffIKlla_x, ffIKlla_y, ffIKlla_z);
//						compute(ffIKlla_angleZ, -ffIKlla_x, -ffIKlla_y, -ffIKlla_z, boneID - 500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 511)
//					{
//
//						computeSM_ikRH(ffIK_lhTargetX, ffIK_lhTargetY, ffIKlh_x, ffIKlh_y, ffIKlh_z, boneID);
//						ffIK_lhTargetY--;
//					}
//
//					//=========================================================
//					if (boneID == 1003)
//					{
//
//						computeSM_ikRH(freeLF_Targetx, freeLF_Targety, freeLF_x, freeLF_y, freeLF_z, boneID);
//						freeLF_Targety--;
//					}
//					if (boneID == 2003)
//					{
//
//						computeSM_ikRH(freeRF_Targetx, freeRF_Targety, freeRF_x, freeRF_y, freeRF_z, boneID);
//						freeRF_Targety--;
//					}
//				}
//				
//			}
//			if (screenDiff < screenPrev)
//			{
//				if (flag == 1)
//				{
//					if (boneID == 0)
//					{
//
//					}
//					if (boneID == 1)
//					{
//					
//						animateSM_CH0(SManim_ch0_angleX, SMch0_x, SMch0_y, SMch0_z);
//						SMch0_angleX -= 4;
//						compute(SMch0_angleX, SMch0_x, SMch0_y, SMch0_z, boneID);
//						renderWindow->Render();
//
//					}
//					if (boneID == 103)
//					{
//					
//
//					}
//					if (boneID == 104)
//					{
//
//					}
//					if (boneID == 105)
//					{
//
//					}
//					if (boneID == 106)
//					{
//
//					}
//					if (boneID == 2)
//					{
//						animateSM_RUA(SManim_rua_angleX, SMrua_x, SMrua_y, SMrua_z);
//						SMrua_angleX -= 4;
//						compute(SMrua_angleX, SMrua_x, SMrua_y, SMrua_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 3)
//					{
//						animateSM_RLA(SManim_rla_angleX, SMrla_x, SMrla_y, SMrla_z);
//						SMrla_angleX -= 4;
//						compute(SMrla_angleX, SMrla_x, SMrla_y, SMrla_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 10)
//					{
//						rhIK_Targetx++;
//						computeSM_ikRH(rhIK_Targetx, rhIK_Targety, SMrh_x, SMrh_y, SMrh_z, boneID);
//					
//					}
//					if (boneID == 109)
//					{
//
//						animateSM_RH(SMrh_angleX);
//						SMrh_angleX += 4;
//						renderWindow->Render();
//					}
//					if (boneID == 4)
//					{
//
//						animateSM_LUA(SManim_lua_angleX, SMlua_x, SMlua_y, SMlua_z);
//						SMlua_angleX -= 4;
//						compute(SMlua_angleX, SMlua_x, SMlua_y, SMlua_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 5)
//					{
//						animateSM_LLA(SManim_lla_angleX, SMlla_x, SMlla_y, SMlla_z);
//						SMlla_angleX -= 4;
//						compute(SMlla_angleX, SMlla_x, SMlla_y, SMlla_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 15)
//					{
//						lhIK_Targetx++;
//						computeSM_ikRH(lhIK_Targetx, lhIK_Targety, SMlh_x, SMlh_y, SMlh_z, boneID);
//						
//					}
//
//					if (boneID == 112)
//					{
//
//						animateSM_LH(SMlh_angleX);
//						SMlh_angleX += 4;
//						renderWindow->Render();
//					}
//					if (boneID == 6)
//					{
//
//						animateSM_RUL(SManim_rul_angleX, SMrul_x, SMrul_y, SMrul_z);
//						SMrul_angleX -= 4;
//						compute(SMrul_angleX, SMrul_x, SMrul_y, SMrul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 7)
//					{
//						animateSM_RLL(SManim_rll_angleX, SMrll_x, SMrll_y, SMrll_z);
//						SMrll_angleX -= 4;
//						compute(SMrll_angleX, SMrll_x, SMrll_y, SMrll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 16)
//					{
//						rfIK_Targetx++;
//						computeSM_ikRH(rfIK_Targetx, rfIK_Targety, SMrf_x, SMrf_y, SMrf_z, boneID);
//					}
//					if (boneID == 115)
//					{
//						animateSM_RF(SMrf_angleX);
//						SMrf_angleX += 4;
//						renderWindow->Render();
//					}
//					if (boneID == 8)
//					{
//
//						animateSM_LUL(SManim_lul_angleX, SMlul_x, SMlul_y, SMlul_z);
//						SMlul_angleX -= 4;
//						compute(SMlul_angleX, SMlul_x, SMlul_y, SMlul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 9)
//					{
//						animateSM_LLL(SManim_lll_angleX, SMlll_x, SMlll_y, SMlll_z);
//						SMlll_angleX -= 4;
//						compute(SMlll_angleX, SMlll_x, SMlll_y, SMlll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 21)
//					{
//						lfIK_Targetx++;
//						computeSM_ikRH(lfIK_Targetx, lfIK_Targety, SMlf_x, SMlf_y, SMlf_z, boneID);
//						
//					}
//					if (boneID == 118)
//					{
//
//						animateSM_LF(SMlf_angleX);
//						SMlf_angleX += 4;
//						renderWindow->Render();
//
//					}
//
//
//
//					//=================================================================
//
//					if (boneID == 500)
//					{						
//						computeSM_ikRH(ffIK_rfTargetx, ffIK_rfTargety, ffIKpl_x, ffIKpl_y, ffIKpl_z, boneID);
//						ffIK_rfTargetx--;
//						renderWindow->Render();
//					}
//					if (boneID == 501)
//					{
//						
//						animateffIK_CH0(ffIKanim_ch0_angleX, ffIKch0_x, ffIKch0_y, ffIKch0_z);
//						ffIKch0_angleX -= 4;
//						compute(ffIKch0_angleX, ffIKch0_x, ffIKch0_y, ffIKch0_z, boneID);
//						renderWindow->Render();
//					}
//				
//
//					if (boneID == 502)
//					{
//						
//						animateffIK_RUA(ffIKanim_rua_angleX, ffIKrua_x, ffIKrua_y, ffIKrua_z);
//						ffIKrua_angleX -= 4;
//						compute(ffIKrua_angleX, ffIKrua_x, ffIKrua_y, ffIKrua_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 503)
//					{
//						
//						animateffIK_RLA(ffIKanim_rla_angleX, ffIKrla_x, ffIKrla_y,ffIKrla_z);
//						ffIKrla_angleX -= 4;
//						compute(ffIKrla_angleX, ffIKrla_x, ffIKrla_y, ffIKrla_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 50)
//					{
//
//					}
//					if (boneID == 510)
//					{
//						ffIK_rhTargetX++;
//						computeSM_ikRH(ffIK_rhTargetX, ffIK_rhTargetY, ffIKrh_x, ffIKrh_y, ffIKrh_z, boneID);
//						
//					}
//			
//
//					if (boneID == 504)
//					{
//						
//						animateffIK_LUA(ffIKanim_lua_angleX, ffIKlua_x, ffIKlua_y, ffIKlua_z);
//						ffIKlua_angleX -= 4;
//						compute(ffIKlua_angleX, ffIKlua_x, ffIKlua_y, ffIKlua_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 505)
//					{
//						
//						animateffIK_LLA(ffIKanim_lla_angleX, ffIKlla_x, ffIKlla_y, ffIKlla_z);
//						ffIKlla_angleX -= 4;
//						compute(ffIKlla_angleX, ffIKlla_x, ffIKlla_y, ffIKlla_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 51)
//					{
//
//					}
//					if (boneID == 511)
//					{
//						ffIK_lhTargetX++;
//						computeSM_ikRH(ffIK_lhTargetX, ffIK_lhTargetY, ffIKlh_x, ffIKlh_y, ffIKlh_z, boneID);
//						
//					}
//
//					if (boneID == 506)
//					{
//						
//						animateffIK_RUL(ffIKanim_rul_angleX, ffIKrul_x, ffIKrul_y, ffIKrul_z);
//						ffIKrul_angleX -= 4;
//						//compute(ffIKrul_angleX, ffIKrul_x, ffIKrul_y, ffIKrul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 507)
//					{
//						
//						animateffIK_RLL(ffIKanim_rll_angleX, ffIKrll_x, ffIKrll_y, ffIKrll_z);
//						ffIKrll_angleX -= 4;
//						//compute(ffIKrll_angleX, ffIKrll_x, ffIKrll_y, ffIKrll_z, boneID);
//						renderWindow->Render();
//
//					}
//					if (boneID == 52)
//					{
//
//					}
//					if (boneID == 512)
//					{
//
//					}
//
//					if (boneID == 508)
//					{
//						
//						animateffIK_LUL(ffIKanim_lul_angleX, ffIKlul_x, ffIKlul_y, ffIKlul_z);
//						ffIKlul_angleX += 4;
//						//compute(ffIKlul_angleX, ffIKlul_x, ffIKlul_y, ffIKlul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 509)
//					{
//						
//						animateffIK_LLL(ffIKanim_lll_angleX, ffIKlll_x, ffIKlll_y, ffIKlll_z);
//						ffIKlll_angleX += 4;
//						//compute(ffIKlll_angleX, ffIKlll_x, ffIKlll_y, ffIKlll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 53)
//					{
//
//					}
//					if (boneID == 513)
//					{
//
//					}
//
//					//===================================================================
//					if (boneID == 1003)
//					{
//						freeLF_Targetx++;
//						computeSM_ikRH(freeLF_Targetx, freeLF_Targety, freeLF_x, freeLF_y, freeLF_z, boneID);
//					
//					}
//					if (boneID == 2003)
//					{
//						freeRF_Targetx++;
//						computeSM_ikRH(freeRF_Targetx, freeRF_Targety, freeRF_x, freeRF_y, freeRF_z, boneID);
//						
//					}
//				}
//				if (flag == 2)
//				{
//					if (boneID == 0)
//					{
//
//					}
//					if (boneID == 1)
//					{
//						
//						animateSM_CH0(SManim_ch0_angleZ, SMch0_x, SMch0_y, SMch0_z);
//						SMch0_angleZ -= 4;
//						compute(SMch0_angleZ, SMch0_x, SMch0_y, SMch0_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 2)
//					{
//						animateSM_RUA(SManim_rua_angleZ, SMrua_x, SMrua_y, SMrua_z);
//						SMrua_angleZ -= 4;
//						compute(SMrua_angleZ, SMrua_x, SMrua_y, SMrua_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 3)
//					{
//						animateSM_RLA(SManim_rla_angleZ, SMrla_x, SMrla_y, SMrla_z);
//						SMrla_angleZ -= 4;
//						compute(SMrla_angleZ, SMrla_x, SMrla_y, SMrla_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 10)
//					{
//						rhIK_Targety++;
//						computeSM_ikRH(rhIK_Targetx, rhIK_Targety, SMrh_x, SMrh_y, SMrh_z, boneID);
//					
//					}
//					if (boneID == 4)
//					{
//						animateSM_LUA(SManim_lua_angleZ, -SMlua_x, -SMlua_y, -SMlua_z);
//						SMlua_angleZ -= 4;
//						compute(SMlua_angleZ, -SMlua_x, -SMlua_y, -SMlua_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 5)
//					{
//						animateSM_LLA(SManim_lla_angleZ, -SMlla_x, -SMlla_y, -SMlla_z);
//						SMlla_angleZ -= 4;
//						compute(SMlla_angleZ, -SMlla_x, -SMlla_y, -SMlla_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 15)
//					{
//						lhIK_Targety++;
//						computeSM_ikRH(lhIK_Targetx, lhIK_Targety, SMlh_x, SMlh_y, SMlh_z, boneID);
//					
//					}
//					if (boneID == 6)
//					{
//						animateSM_RUL(SManim_rul_angleZ, SMrul_x, SMrul_y, SMrul_z);
//						SMrul_angleZ -= 4;
//						compute(SMrul_angleZ, SMrul_x, SMrul_y, SMrul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 7)
//					{
//						animateSM_RLL(SManim_rll_angleZ, SMrll_x, SMrll_y, SMrll_z);
//						SMrll_angleZ -= 4;
//						compute(SMrll_angleZ, SMrll_x, SMrll_y, SMrll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 16)
//					{
//						rfIK_Targety++;
//						computeSM_ikRH(rfIK_Targetx, rfIK_Targety, SMrf_x, SMrf_y, SMrf_z, boneID);
//
//					}
//					if (boneID == 8)
//					{
//						animateSM_LUL(SManim_lul_angleZ, -SMlul_x, -SMlul_y, -SMlul_z);
//						SMlul_angleZ -= 4;
//						compute(SMlul_angleZ, -SMlul_x, -SMlul_y, -SMlul_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 9)
//					{
//						animateSM_LLL(SManim_lll_angleZ, -SMlll_x, -SMlll_y, -SMlll_z);
//						SMlla_angleZ -= 4;
//						compute(SMlll_angleZ, -SMlll_x, -SMlll_y, -SMlll_z, boneID);
//						renderWindow->Render();
//					}
//					if (boneID == 21)
//					{
//						lfIK_Targety++;
//						computeSM_ikRH(lfIK_Targetx, lfIK_Targety, SMlf_x, SMlf_y, SMlf_z, boneID);
//
//					}
//
//
//					//=========================================================
//					if (boneID == 500)
//					{
//						
//						computeSM_ikRH(ffIK_rfTargetx, ffIK_rfTargety, ffIKpl_x, ffIKpl_y, ffIKpl_z, boneID);
//						ffIK_rfTargety--;
//					}
//					if (boneID == 501)
//					{
//
//						animateffIK_CH0(ffIKanim_ch0_angleZ, ffIKch0_x, ffIKch0_y, ffIKch0_z);
//						ffIKch0_angleZ -= 4;
//						compute(ffIKch0_angleZ, ffIKch0_x, ffIKch0_y, ffIKch0_z, boneID);
//						renderWindow->Render();
//					}
//					
//					if (boneID == 502)
//					{
//
//						animateffIK_RUA(ffIKanim_rua_angleZ, ffIKrua_x, ffIKrua_y, ffIKrua_z);
//						ffIKrua_angleZ -= 4;
//						compute(ffIKrua_angleZ, ffIKrua_x, ffIKrua_y, ffIKrua_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 503)
//					{
//
//						animateffIK_RLA(ffIKanim_rla_angleZ, ffIKrla_x, ffIKrla_y, ffIKrla_z);
//						ffIKrla_angleZ -= 4;
//						compute(ffIKrla_angleZ, ffIKrla_x, ffIKrla_y, ffIKrla_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 510)
//					{
//						ffIK_rhTargetY++;
//						computeSM_ikRH(ffIK_rhTargetX, ffIK_rhTargetY, ffIKrh_x, ffIKrh_y, ffIKrh_z, boneID);
//
//					}
//
//					if (boneID == 504)
//					{
//
//						animateffIK_LUA(ffIKanim_lua_angleZ, -ffIKlua_x, -ffIKlua_y, -ffIKlua_z);
//						ffIKlua_angleZ -= 4;
//						compute(ffIKlua_angleZ, -ffIKlua_x, -ffIKlua_y, -ffIKlua_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 505)
//					{
//
//						animateffIK_LLA(ffIKanim_lla_angleZ, -ffIKlla_x, -ffIKlla_y, -ffIKlla_z);
//						ffIKlla_angleZ -= 4;
//						compute(ffIKlla_angleZ, -ffIKlla_x, -ffIKlla_y, -ffIKlla_z, boneID-500);
//						renderWindow->Render();
//
//					}
//					if (boneID == 511)
//					{
//						ffIK_lhTargetY++;
//						computeSM_ikRH(ffIK_lhTargetX, ffIK_lhTargetY, ffIKlh_x, ffIKlh_y, ffIKlh_z, boneID);
//
//					}
//
//					//=======================================================
//					if (boneID == 1003)
//					{
//						freeLF_Targety++;
//						computeSM_ikRH(freeLF_Targetx, freeLF_Targety, freeLF_x, freeLF_y, freeLF_z, boneID);
//
//					}
//					if (boneID == 2003)
//					{
//						freeRF_Targety++;
//						computeSM_ikRH(freeRF_Targetx, freeRF_Targety, freeRF_x, freeRF_y, freeRF_z, boneID);
//
//					}
//
//				}
//				
//			}
//			screenPrev = screenDiff;
//
//
//
//			if (boneID == 91)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					moveSphereProp(consProp_sphere_x, consProp_sphere_y, consProp_sphere_z);
//				}
//				if (diff < prevY)
//				{
//					moveSphereProp(-consProp_sphere_x, -consProp_sphere_y, -consProp_sphere_z);
//				}
//				prevY = diff;
//			}
//
//
//			if (boneID == 9100)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					TmoveSphereProp(TconsProp_sphere_x, TconsProp_sphere_y, TconsProp_sphere_z);
//				}
//				if (diff < prevY)
//				{
//					TmoveSphereProp(-TconsProp_sphere_x, -TconsProp_sphere_y, -TconsProp_sphere_z);
//				}
//				prevY = diff;
//			}
//
//			if (boneID == 9200)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					TmoveSphereProp2(TconsProp_sphere_x2, TconsProp_sphere_y2, TconsProp_sphere_z2);
//				}
//				if (diff < prevY)
//				{
//					TmoveSphereProp2(-TconsProp_sphere_x2, -TconsProp_sphere_y2, -TconsProp_sphere_z2);
//				}
//				prevY = diff;
//			}
//			if (boneID == 9300)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					TmoveSphereProp3(TconsProp_sphere_x3, TconsProp_sphere_y3, TconsProp_sphere_z3);
//				}
//				if (diff < prevY)
//				{
//					TmoveSphereProp3(-TconsProp_sphere_x3, -TconsProp_sphere_y3, -TconsProp_sphere_z3);
//				}
//				prevY = diff;
//			}
//
//
//			if (boneID == 92)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					moveLineProp(consProp_line_x, consProp_line_y, consProp_line_z);
//				}
//				if (diff < prevY)
//				{
//					moveLineProp(-consProp_line_x, -consProp_line_y, -consProp_line_z);
//				}
//				prevY = diff;
//			}
//			if (boneID == 9001)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					TmoveLineProp(TconsProp_line_x, TconsProp_line_y, TconsProp_line_z);
//				}
//				if (diff < prevY)
//				{
//					TmoveLineProp(-TconsProp_line_x, -TconsProp_line_y, -TconsProp_line_z);
//				}
//				prevY = diff;
//			}
//			if (boneID == 9002)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					TmoveLineProp2(TconsProp_line_x2, TconsProp_line_y2, TconsProp_line_z2);
//				}
//				if (diff < prevY)
//				{
//					TmoveLineProp2(-TconsProp_line_x2, -TconsProp_line_y2, -TconsProp_line_z2);
//				}
//				prevY = diff;
//			}
//			if (boneID == 9003)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					TmoveLineProp3(TconsProp_line_x3, TconsProp_line_y3, TconsProp_line_z3);
//				}
//				if (diff < prevY)
//				{
//					TmoveLineProp3(-TconsProp_line_x3, -TconsProp_line_y3, -TconsProp_line_z3);
//				}
//				prevY = diff;
//			}
//
//			if (boneID == 93)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					movePlaneProp(consProp_plane_x, consProp_plane_y, consProp_plane_z);
//				}
//				if (diff < prevY)
//				{
//					movePlaneProp(-consProp_plane_x, -consProp_plane_y, -consProp_plane_z);
//				}
//				prevY = diff;
//			}
//			if (boneID == 94)
//			{
//				x = this->Interactor->GetEventPosition()[0];
//				y = this->Interactor->GetEventPosition()[1];
//
//				diff = temp + y;
//				if (diff > prevY)
//				{
//					moveCubeProp(consProp_cube_x, consProp_cube_y, consProp_cube_z);
//				}
//				if (diff < prevY)
//				{
//					moveCubeProp(-consProp_cube_x, -consProp_cube_y, -consProp_cube_z);
//				}
//				prevY = diff;
//			}
//			
//		}
//
//	}
//
//	virtual void OnLeftButtonUp() override
//	{
//		vtkInteractorStyleTrackballActor::OnLeftButtonUp();
//		this->Move = false;
//
//	}
//	virtual void OnLeftButtonDown() override
//	{
//		vtkInteractorStyleTrackballActor::OnLeftButtonDown();
//		//cout << "Selecting Objects";
//		
//		flag = 1;
//
//
//		// ======================================================================================================//
//		if (this->CurrentProp == this->pelvisActor)
//		{
//			boneID = 0;
//			axis_flag = 'x';
//			this->Move = true;
//			pelvis_x = 1;
//			pelvis_y = 0;
//			pelvis_z = 0;
//			anim_pelvis_angle = 4;
//			anim_pelvis_x = 1;
//			anim_pelvis_y = 0;
//			anim_pelvis_z = 0;
//
//
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//
//			//dummy1 = 0;
//			//dummy2 = 0;
//			//dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			/*		renderer->AddActor(PL_xrot_circle_Actor);
//					renderer->AddActor(PL_yrot_circle_Actor);
//					renderer->AddActor(PL_zrot_circle_Actor);
//					renderer->RemoveActor(CH_xrot_circle_Actor);
//					renderer->RemoveActor(CH_yrot_circle_Actor);
//					renderer->RemoveActor(CH_zrot_circle_Actor);
//					renderer->RemoveActor(Head_xrot_circle_Actor);
//					renderer->RemoveActor(Head_yrot_circle_Actor);
//					renderer->RemoveActor(Head_zrot_circle_Actor);
//					renderer->RemoveActor(RUA_xrot_circle_Actor);
//					renderer->RemoveActor(RUA_yrot_circle_Actor);
//					renderer->RemoveActor(RUA_zrot_circle_Actor);
//					renderer->RemoveActor(RLA_xrot_circle_Actor);
//					renderer->RemoveActor(RLA_yrot_circle_Actor);
//					renderer->RemoveActor(RLA_zrot_circle_Actor);
//					renderer->RemoveActor(RH_xrot_circle_Actor);
//					renderer->RemoveActor(RH_yrot_circle_Actor);
//					renderer->RemoveActor(RH_zrot_circle_Actor);
//					renderer->RemoveActor(LUA_xrot_circle_Actor);
//					renderer->RemoveActor(LUA_yrot_circle_Actor);
//					renderer->RemoveActor(LUA_zrot_circle_Actor);
//					renderer->RemoveActor(LLA_xrot_circle_Actor);
//					renderer->RemoveActor(LLA_yrot_circle_Actor);
//					renderer->RemoveActor(LLA_zrot_circle_Actor);
//					renderer->RemoveActor(LH_xrot_circle_Actor);
//					renderer->RemoveActor(LH_yrot_circle_Actor);
//					renderer->RemoveActor(LH_zrot_circle_Actor);
//					renderer->RemoveActor(RUL_xrot_circle_Actor);
//					renderer->RemoveActor(RUL_yrot_circle_Actor);
//					renderer->RemoveActor(RUL_zrot_circle_Actor);
//					renderer->RemoveActor(RLL_xrot_circle_Actor);
//					renderer->RemoveActor(RLL_yrot_circle_Actor);
//					renderer->RemoveActor(RLL_zrot_circle_Actor);
//					renderer->RemoveActor(RF_xrot_circle_Actor);
//					renderer->RemoveActor(RF_yrot_circle_Actor);
//					renderer->RemoveActor(RF_zrot_circle_Actor);
//					renderer->RemoveActor(LUL_xrot_circle_Actor);
//					renderer->RemoveActor(LUL_yrot_circle_Actor);
//					renderer->RemoveActor(LUL_zrot_circle_Actor);
//					renderer->RemoveActor(LLL_xrot_circle_Actor);
//					renderer->RemoveActor(LLL_yrot_circle_Actor);
//					renderer->RemoveActor(LLL_zrot_circle_Actor);
//					renderer->RemoveActor(LF_xrot_circle_Actor);
//					renderer->RemoveActor(LF_yrot_circle_Actor);
//					renderer->RemoveActor(LF_zrot_circle_Actor);*/
//
//
//			renderWindow->Render();
//
//
//		}
//		if (this->InteractionProp == this->chestActor)
//		{
//			//boneID = 1;
//			//axis_flag = 'x';
//			//this->Move = true;
//			//chest_x = 1;
//			//chest_y = 0;
//			//chest_z = 0;
//			//anim_chest_angle = 4;
//			//anim_chest_x = 1;
//			//anim_chest_y = 0;
//			//anim_chest_z = 0;
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			/*renderer->RemoveActor(PL_xrot_circle_Actor);
//			renderer->RemoveActor(PL_yrot_circle_Actor);
//			renderer->RemoveActor(PL_zrot_circle_Actor);
//			renderer->AddActor(CH_xrot_circle_Actor);
//			renderer->AddActor(CH_yrot_circle_Actor);
//			renderer->AddActor(CH_zrot_circle_Actor);
//			renderer->RemoveActor(Head_xrot_circle_Actor);
//			renderer->RemoveActor(Head_yrot_circle_Actor);
//			renderer->RemoveActor(Head_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RLA_xrot_circle_Actor);
//			renderer->RemoveActor(RLA_yrot_circle_Actor);
//			renderer->RemoveActor(RLA_zrot_circle_Actor);
//			renderer->RemoveActor(RH_xrot_circle_Actor);
//			renderer->RemoveActor(RH_yrot_circle_Actor);
//			renderer->RemoveActor(RH_zrot_circle_Actor);
//			renderer->RemoveActor(LUA_xrot_circle_Actor);
//			renderer->RemoveActor(LUA_yrot_circle_Actor);
//			renderer->RemoveActor(LUA_zrot_circle_Actor);
//			renderer->RemoveActor(LLA_xrot_circle_Actor);
//			renderer->RemoveActor(LLA_yrot_circle_Actor);
//			renderer->RemoveActor(LLA_zrot_circle_Actor);
//			renderer->RemoveActor(LH_xrot_circle_Actor);
//			renderer->RemoveActor(LH_yrot_circle_Actor);
//			renderer->RemoveActor(LH_zrot_circle_Actor);
//			renderer->RemoveActor(RUL_xrot_circle_Actor);
//			renderer->RemoveActor(RUL_yrot_circle_Actor);
//			renderer->RemoveActor(RUL_zrot_circle_Actor);
//			renderer->RemoveActor(RLL_xrot_circle_Actor);
//			renderer->RemoveActor(RLL_yrot_circle_Actor);
//			renderer->RemoveActor(RLL_zrot_circle_Actor);
//			renderer->RemoveActor(RF_xrot_circle_Actor);
//			renderer->RemoveActor(RF_yrot_circle_Actor);
//			renderer->RemoveActor(RF_zrot_circle_Actor);
//			renderer->RemoveActor(LUL_xrot_circle_Actor);
//			renderer->RemoveActor(LUL_yrot_circle_Actor);
//			renderer->RemoveActor(LUL_zrot_circle_Actor);
//			renderer->RemoveActor(LLL_xrot_circle_Actor);
//			renderer->RemoveActor(LLL_yrot_circle_Actor);
//			renderer->RemoveActor(LLL_zrot_circle_Actor);
//			renderer->RemoveActor(LF_xrot_circle_Actor);
//			renderer->RemoveActor(LF_yrot_circle_Actor);
//			renderer->RemoveActor(LF_zrot_circle_Actor);*/
//
//
//
//
//
//
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->RUA)
//		{
//		//	boneID = 2;
//		//	axis_flag = 'x';
//		//	this->Move = true;
//		///*	rua_x = 1;
//		//	rua_y = 0;
//		//	rua_z = 0;*/
//		//	anim_rua_angle = 4;
//		//	anim_rua_x = 1;
//		//	anim_rua_y = 0;
//		//	anim_rua_z = 0;
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//
//			renderer->Render();
//
//			/*renderer->RemoveActor(PL_xrot_circle_Actor);
//			renderer->RemoveActor(PL_yrot_circle_Actor);
//			renderer->RemoveActor(PL_zrot_circle_Actor);
//			renderer->RemoveActor(CH_xrot_circle_Actor);
//			renderer->RemoveActor(CH_yrot_circle_Actor);
//			renderer->RemoveActor(CH_zrot_circle_Actor);
//			renderer->RemoveActor(Head_xrot_circle_Actor);
//			renderer->RemoveActor(Head_yrot_circle_Actor);
//			renderer->RemoveActor(Head_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->AddActor(RUA_xrot_circle_Actor);
//			renderer->AddActor(RUA_yrot_circle_Actor);
//			renderer->AddActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RLA_xrot_circle_Actor);
//			renderer->RemoveActor(RLA_yrot_circle_Actor);
//			renderer->RemoveActor(RLA_zrot_circle_Actor);
//			renderer->RemoveActor(RH_xrot_circle_Actor);
//			renderer->RemoveActor(RH_yrot_circle_Actor);
//			renderer->RemoveActor(RH_zrot_circle_Actor);
//			renderer->RemoveActor(LUA_xrot_circle_Actor);
//			renderer->RemoveActor(LUA_yrot_circle_Actor);
//			renderer->RemoveActor(LUA_zrot_circle_Actor);
//			renderer->RemoveActor(LLA_xrot_circle_Actor);
//			renderer->RemoveActor(LLA_yrot_circle_Actor);
//			renderer->RemoveActor(LLA_zrot_circle_Actor);
//			renderer->RemoveActor(LH_xrot_circle_Actor);
//			renderer->RemoveActor(LH_yrot_circle_Actor);
//			renderer->RemoveActor(LH_zrot_circle_Actor);
//			renderer->RemoveActor(RUL_xrot_circle_Actor);
//			renderer->RemoveActor(RUL_yrot_circle_Actor);
//			renderer->RemoveActor(RUL_zrot_circle_Actor);
//			renderer->RemoveActor(RLL_xrot_circle_Actor);
//			renderer->RemoveActor(RLL_yrot_circle_Actor);
//			renderer->RemoveActor(RLL_zrot_circle_Actor);
//			renderer->RemoveActor(RF_xrot_circle_Actor);
//			renderer->RemoveActor(RF_yrot_circle_Actor);
//			renderer->RemoveActor(RF_zrot_circle_Actor);
//			renderer->RemoveActor(LUL_xrot_circle_Actor);
//			renderer->RemoveActor(LUL_yrot_circle_Actor);
//			renderer->RemoveActor(LUL_zrot_circle_Actor);
//			renderer->RemoveActor(LLL_xrot_circle_Actor);
//			renderer->RemoveActor(LLL_yrot_circle_Actor);
//			renderer->RemoveActor(LLL_zrot_circle_Actor);
//			renderer->RemoveActor(LF_xrot_circle_Actor);
//			renderer->RemoveActor(LF_yrot_circle_Actor);
//			renderer->RemoveActor(LF_zrot_circle_Actor);*/
//
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->RLA)
//		{
//			/*boneID = 3;
//			axis_flag = 'x';
//			this->Move = true;
//			rla_x = 1;
//			rla_y = 0;
//			rla_z = 0;
//			anim_rla_angle = 4;
//			anim_rla_x = 1;
//			anim_rla_y = 0;
//			anim_rla_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			
//
//
//			/*dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//
//			renderer->Render();
//
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			
//			renderWindow->Render();
//
//
//
//		}
//
//		if (this->InteractionProp == this->LUA)
//		{
//			/*boneID = 4;
//			axis_flag = 'x';
//			this->Move = true;
//			lua_x = 1;
//			lua_y = 0;
//			lua_z = 0;
//			anim_lua_angle = 4;
//			anim_lua_x = 1;
//			anim_lua_y = 0;
//			anim_lua_z = 0;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			renderer->Render();
//
//
//
//			/*renderer->RemoveActor(PL_xrot_circle_Actor);
//			renderer->RemoveActor(PL_yrot_circle_Actor);
//			renderer->RemoveActor(PL_zrot_circle_Actor);
//			renderer->RemoveActor(CH_xrot_circle_Actor);
//			renderer->RemoveActor(CH_yrot_circle_Actor);
//			renderer->RemoveActor(CH_zrot_circle_Actor);
//			renderer->RemoveActor(Head_xrot_circle_Actor);
//			renderer->RemoveActor(Head_yrot_circle_Actor);
//			renderer->RemoveActor(Head_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RLA_xrot_circle_Actor);
//			renderer->RemoveActor(RLA_yrot_circle_Actor);
//			renderer->RemoveActor(RLA_zrot_circle_Actor);
//			renderer->RemoveActor(RH_xrot_circle_Actor);
//			renderer->RemoveActor(RH_yrot_circle_Actor);
//			renderer->RemoveActor(RH_zrot_circle_Actor);
//			renderer->AddActor(LUA_xrot_circle_Actor);
//			renderer->AddActor(LUA_yrot_circle_Actor);
//			renderer->AddActor(LUA_zrot_circle_Actor);
//			renderer->RemoveActor(LLA_xrot_circle_Actor);
//			renderer->RemoveActor(LLA_yrot_circle_Actor);
//			renderer->RemoveActor(LLA_zrot_circle_Actor);
//			renderer->RemoveActor(LH_xrot_circle_Actor);
//			renderer->RemoveActor(LH_yrot_circle_Actor);
//			renderer->RemoveActor(LH_zrot_circle_Actor);
//			renderer->RemoveActor(RUL_xrot_circle_Actor);
//			renderer->RemoveActor(RUL_yrot_circle_Actor);
//			renderer->RemoveActor(RUL_zrot_circle_Actor);
//			renderer->RemoveActor(RLL_xrot_circle_Actor);
//			renderer->RemoveActor(RLL_yrot_circle_Actor);
//			renderer->RemoveActor(RLL_zrot_circle_Actor);
//			renderer->RemoveActor(RF_xrot_circle_Actor);
//			renderer->RemoveActor(RF_yrot_circle_Actor);
//			renderer->RemoveActor(RF_zrot_circle_Actor);
//			renderer->RemoveActor(LUL_xrot_circle_Actor);
//			renderer->RemoveActor(LUL_yrot_circle_Actor);
//			renderer->RemoveActor(LUL_zrot_circle_Actor);
//			renderer->RemoveActor(LLL_xrot_circle_Actor);
//			renderer->RemoveActor(LLL_yrot_circle_Actor);
//			renderer->RemoveActor(LLL_zrot_circle_Actor);
//			renderer->RemoveActor(LF_xrot_circle_Actor);
//			renderer->RemoveActor(LF_yrot_circle_Actor);
//			renderer->RemoveActor(LF_zrot_circle_Actor);*/
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->LLA)
//		{
//			/*boneID = 5;
//			axis_flag = 'x';
//			this->Move = true;
//			lla_x = 1;
//			lla_y = 0;
//			lla_z = 0;
//			anim_lla_angle = 4;
//			anim_lla_x = 1;
//			anim_lla_y = 0;
//			anim_lla_z = 0;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//		
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			renderer->Render();
//
//			//renderer->RemoveActor(PL_xrot_circle_Actor);
//		//renderer->RemoveActor(PL_yrot_circle_Actor);
//		//renderer->RemoveActor(PL_zrot_circle_Actor);
//		//renderer->RemoveActor(CH_xrot_circle_Actor);
//		//renderer->RemoveActor(CH_yrot_circle_Actor);
//		//renderer->RemoveActor(CH_zrot_circle_Actor);
//		//renderer->RemoveActor(Head_xrot_circle_Actor);
//		//renderer->RemoveActor(Head_yrot_circle_Actor);
//		//renderer->RemoveActor(Head_zrot_circle_Actor);
//		//renderer->RemoveActor(RUA_xrot_circle_Actor);
//		//renderer->RemoveActor(RUA_yrot_circle_Actor);
//		//renderer->RemoveActor(RUA_zrot_circle_Actor);
//		//renderer->RemoveActor(RUA_xrot_circle_Actor);
//		//renderer->RemoveActor(RUA_yrot_circle_Actor);
//		//renderer->RemoveActor(RUA_zrot_circle_Actor);
//		//renderer->RemoveActor(RLA_xrot_circle_Actor);
//		//renderer->RemoveActor(RLA_yrot_circle_Actor);
//		//renderer->RemoveActor(RLA_zrot_circle_Actor);
//		//renderer->RemoveActor(RH_xrot_circle_Actor);
//		//renderer->RemoveActor(RH_yrot_circle_Actor);
//		//renderer->RemoveActor(RH_zrot_circle_Actor);
//		//renderer->RemoveActor(LUA_xrot_circle_Actor);
//		//renderer->RemoveActor(LUA_yrot_circle_Actor);
//		//renderer->RemoveActor(LUA_zrot_circle_Actor);
//		//renderer->AddActor(LLA_xrot_circle_Actor);
//		//renderer->AddActor(LLA_yrot_circle_Actor);
//		//renderer->AddActor(LLA_zrot_circle_Actor);
//		//renderer->RemoveActor(LH_xrot_circle_Actor);
//		//renderer->RemoveActor(LH_yrot_circle_Actor);
//		//renderer->RemoveActor(LH_zrot_circle_Actor);
//		//renderer->RemoveActor(RUL_xrot_circle_Actor);
//		//renderer->RemoveActor(RUL_yrot_circle_Actor);
//		//renderer->RemoveActor(RUL_zrot_circle_Actor);
//		//renderer->RemoveActor(RLL_xrot_circle_Actor);
//		//renderer->RemoveActor(RLL_yrot_circle_Actor);
//		//renderer->RemoveActor(RLL_zrot_circle_Actor);
//		//renderer->RemoveActor(RF_xrot_circle_Actor);
//		//renderer->RemoveActor(RF_yrot_circle_Actor);
//		//renderer->RemoveActor(RF_zrot_circle_Actor);
//		//renderer->RemoveActor(LUL_xrot_circle_Actor);
//		//renderer->RemoveActor(LUL_yrot_circle_Actor);
//		//renderer->RemoveActor(LUL_zrot_circle_Actor);
//		//renderer->RemoveActor(LLL_xrot_circle_Actor);
//		//renderer->RemoveActor(LLL_yrot_circle_Actor);
//		//renderer->RemoveActor(LLL_zrot_circle_Actor);
//		//renderer->RemoveActor(LF_xrot_circle_Actor);
//		//renderer->RemoveActor(LF_yrot_circle_Actor);
//		//renderer->RemoveActor(LF_zrot_circle_Actor);
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->RUL)
//		{
//			/*boneID = 6;
//			axis_flag = 'x';
//			this->Move = true;
//			rul_x = 1;
//			rul_y = 0;
//			rul_z = 0;
//			anim_rul_angle = 4;
//			anim_rul_x = 1;
//			anim_rul_y = 0;
//			anim_rul_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			renderer->Render();
//
//
//			/*renderer->RemoveActor(PL_xrot_circle_Actor);
//			renderer->RemoveActor(PL_yrot_circle_Actor);
//			renderer->RemoveActor(PL_zrot_circle_Actor);
//			renderer->RemoveActor(CH_xrot_circle_Actor);
//			renderer->RemoveActor(CH_yrot_circle_Actor);
//			renderer->RemoveActor(CH_zrot_circle_Actor);
//			renderer->RemoveActor(Head_xrot_circle_Actor);
//			renderer->RemoveActor(Head_yrot_circle_Actor);
//			renderer->RemoveActor(Head_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RLA_xrot_circle_Actor);
//			renderer->RemoveActor(RLA_yrot_circle_Actor);
//			renderer->RemoveActor(RLA_zrot_circle_Actor);
//			renderer->RemoveActor(RH_xrot_circle_Actor);
//			renderer->RemoveActor(RH_yrot_circle_Actor);
//			renderer->RemoveActor(RH_zrot_circle_Actor);
//			renderer->RemoveActor(LUA_xrot_circle_Actor);
//			renderer->RemoveActor(LUA_yrot_circle_Actor);
//			renderer->RemoveActor(LUA_zrot_circle_Actor);
//			renderer->RemoveActor(LLA_xrot_circle_Actor);
//			renderer->RemoveActor(LLA_yrot_circle_Actor);
//			renderer->RemoveActor(LLA_zrot_circle_Actor);
//			renderer->RemoveActor(LH_xrot_circle_Actor);
//			renderer->RemoveActor(LH_yrot_circle_Actor);
//			renderer->RemoveActor(LH_zrot_circle_Actor);
//			renderer->AddActor(RUL_xrot_circle_Actor);
//			renderer->AddActor(RUL_yrot_circle_Actor);
//			renderer->AddActor(RUL_zrot_circle_Actor);
//			renderer->RemoveActor(RLL_xrot_circle_Actor);
//			renderer->RemoveActor(RLL_yrot_circle_Actor);
//			renderer->RemoveActor(RLL_zrot_circle_Actor);
//			renderer->RemoveActor(RF_xrot_circle_Actor);
//			renderer->RemoveActor(RF_yrot_circle_Actor);
//			renderer->RemoveActor(RF_zrot_circle_Actor);
//			renderer->RemoveActor(LUL_xrot_circle_Actor);
//			renderer->RemoveActor(LUL_yrot_circle_Actor);
//			renderer->RemoveActor(LUL_zrot_circle_Actor);
//			renderer->RemoveActor(LLL_xrot_circle_Actor);
//			renderer->RemoveActor(LLL_yrot_circle_Actor);
//			renderer->RemoveActor(LLL_zrot_circle_Actor);
//			renderer->RemoveActor(LF_xrot_circle_Actor);
//			renderer->RemoveActor(LF_yrot_circle_Actor);
//			renderer->RemoveActor(LF_zrot_circle_Actor);*/
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->RLL)
//		{
//			/*boneID = 7;
//			axis_flag = 'x';
//			this->Move = true;
//			rll_x = 1;
//			rll_y = 0;
//			rll_z = 0;
//			anim_rll_angle = 4;
//			anim_rll_x = 1;
//			anim_rll_y = 0;
//			anim_rll_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//		
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			renderer->Render();
//
//			
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->LUL)
//		{
//			/*boneID = 8;
//			axis_flag = 'x';
//			this->Move = true;
//			lul_x = 1;
//			lul_y = 0;
//			lul_z = 0;
//			anim_lul_angle = 4;
//			anim_lul_x = 1;
//			anim_lul_y = 0;
//			anim_lul_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//		
//
//			//dummy1 = 0;
//			//dummy2 = 0;
//			//dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			renderer->Render();
//
//
//
//			/*renderer->RemoveActor(PL_xrot_circle_Actor);
//			renderer->RemoveActor(PL_yrot_circle_Actor);
//			renderer->RemoveActor(PL_zrot_circle_Actor);
//			renderer->RemoveActor(CH_xrot_circle_Actor);
//			renderer->RemoveActor(CH_yrot_circle_Actor);
//			renderer->RemoveActor(CH_zrot_circle_Actor);
//			renderer->RemoveActor(Head_xrot_circle_Actor);
//			renderer->RemoveActor(Head_yrot_circle_Actor);
//			renderer->RemoveActor(Head_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RLA_xrot_circle_Actor);
//			renderer->RemoveActor(RLA_yrot_circle_Actor);
//			renderer->RemoveActor(RLA_zrot_circle_Actor);
//			renderer->RemoveActor(RH_xrot_circle_Actor);
//			renderer->RemoveActor(RH_yrot_circle_Actor);
//			renderer->RemoveActor(RH_zrot_circle_Actor);
//			renderer->RemoveActor(LUA_xrot_circle_Actor);
//			renderer->RemoveActor(LUA_yrot_circle_Actor);
//			renderer->RemoveActor(LUA_zrot_circle_Actor);
//			renderer->RemoveActor(LLA_xrot_circle_Actor);
//			renderer->RemoveActor(LLA_yrot_circle_Actor);
//			renderer->RemoveActor(LLA_zrot_circle_Actor);
//			renderer->RemoveActor(LH_xrot_circle_Actor);
//			renderer->RemoveActor(LH_yrot_circle_Actor);
//			renderer->RemoveActor(LH_zrot_circle_Actor);
//			renderer->RemoveActor(RUL_xrot_circle_Actor);
//			renderer->RemoveActor(RUL_yrot_circle_Actor);
//			renderer->RemoveActor(RUL_zrot_circle_Actor);
//			renderer->RemoveActor(RLL_xrot_circle_Actor);
//			renderer->RemoveActor(RLL_yrot_circle_Actor);
//			renderer->RemoveActor(RLL_zrot_circle_Actor);
//			renderer->RemoveActor(RF_xrot_circle_Actor);
//			renderer->RemoveActor(RF_yrot_circle_Actor);
//			renderer->RemoveActor(RF_zrot_circle_Actor);
//			renderer->AddActor(LUL_xrot_circle_Actor);
//			renderer->AddActor(LUL_yrot_circle_Actor);
//			renderer->AddActor(LUL_zrot_circle_Actor);
//			renderer->RemoveActor(LLL_xrot_circle_Actor);
//			renderer->RemoveActor(LLL_yrot_circle_Actor);
//			renderer->RemoveActor(LLL_zrot_circle_Actor);
//			renderer->RemoveActor(LF_xrot_circle_Actor);
//			renderer->RemoveActor(LF_yrot_circle_Actor);
//			renderer->RemoveActor(LF_zrot_circle_Actor);*/
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->LLL)
//		{
//			/*boneID = 9;
//			axis_flag = 'x';
//			this->Move = true;
//			lll_x = 1;
//			lll_y = 0;
//			lll_z = 0;
//			anim_lll_angle = 4;
//			anim_lll_x = 1;
//			anim_lll_y = 0;
//			anim_lll_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//
//			//dummy1 = 0;
//			//dummy2 = 0;
//			//dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			renderer->Render();
//
//
//			/*renderer->RemoveActor(PL_xrot_circle_Actor);
//			renderer->RemoveActor(PL_yrot_circle_Actor);
//			renderer->RemoveActor(PL_zrot_circle_Actor);
//			renderer->RemoveActor(CH_xrot_circle_Actor);
//			renderer->RemoveActor(CH_yrot_circle_Actor);
//			renderer->RemoveActor(CH_zrot_circle_Actor);
//			renderer->RemoveActor(Head_xrot_circle_Actor);
//			renderer->RemoveActor(Head_yrot_circle_Actor);
//			renderer->RemoveActor(Head_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RUA_xrot_circle_Actor);
//			renderer->RemoveActor(RUA_yrot_circle_Actor);
//			renderer->RemoveActor(RUA_zrot_circle_Actor);
//			renderer->RemoveActor(RLA_xrot_circle_Actor);
//			renderer->RemoveActor(RLA_yrot_circle_Actor);
//			renderer->RemoveActor(RLA_zrot_circle_Actor);
//			renderer->RemoveActor(RH_xrot_circle_Actor);
//			renderer->RemoveActor(RH_yrot_circle_Actor);
//			renderer->RemoveActor(RH_zrot_circle_Actor);
//			renderer->RemoveActor(LUA_xrot_circle_Actor);
//			renderer->RemoveActor(LUA_yrot_circle_Actor);
//			renderer->RemoveActor(LUA_zrot_circle_Actor);
//			renderer->RemoveActor(LLA_xrot_circle_Actor);
//			renderer->RemoveActor(LLA_yrot_circle_Actor);
//			renderer->RemoveActor(LLA_zrot_circle_Actor);
//			renderer->RemoveActor(LH_xrot_circle_Actor);
//			renderer->RemoveActor(LH_yrot_circle_Actor);
//			renderer->RemoveActor(LH_zrot_circle_Actor);
//			renderer->RemoveActor(RUL_xrot_circle_Actor);
//			renderer->RemoveActor(RUL_yrot_circle_Actor);
//			renderer->RemoveActor(RUL_zrot_circle_Actor);
//			renderer->RemoveActor(RLL_xrot_circle_Actor);
//			renderer->RemoveActor(RLL_yrot_circle_Actor);
//			renderer->RemoveActor(RLL_zrot_circle_Actor);
//			renderer->RemoveActor(RF_xrot_circle_Actor);
//			renderer->RemoveActor(RF_yrot_circle_Actor);
//			renderer->RemoveActor(RF_zrot_circle_Actor);
//			renderer->RemoveActor(LUL_xrot_circle_Actor);
//			renderer->RemoveActor(LUL_yrot_circle_Actor);
//			renderer->RemoveActor(LUL_zrot_circle_Actor);
//			renderer->AddActor(LLL_xrot_circle_Actor);
//			renderer->AddActor(LLL_yrot_circle_Actor);
//			renderer->AddActor(LLL_zrot_circle_Actor);
//			renderer->RemoveActor(LF_xrot_circle_Actor);
//			renderer->RemoveActor(LF_yrot_circle_Actor);
//			renderer->RemoveActor(LF_zrot_circle_Actor);*/
//
//			renderWindow->Render();
//		}
//
//
//		//=====================================================================================================//
//
//	
//		if (this->InteractionProp == this->SM_pelvisActor)
//		{
//			boneID = 1;
//			axis_flag = 'x';
//			SMpl_x = 1;
//			SMpl_y = 0;
//			SMpl_z = 0;
//			SManim_pl_angleX = 1;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		
//		if (this->InteractionProp == this->SM_CH0)
//		{			
//			boneID = 1;
//			axis_flag = 'x';
//			SMch0_x = 1;
//			SMch0_y = 0;
//			SMch0_z = 0;
//			SManim_ch0_angleX = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_CH1)
//		{
//			boneID = 103;
//			axis_flag = 'x';
//			this->Move = true;
//
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_CH2)
//		{
//			boneID = 104;
//			axis_flag = 'x';
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_CH3)
//		{
//			boneID = 105;
//			axis_flag = 'x';
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		
//		if (this->InteractionProp == this->SM_headActor)
//		{
//			boneID = 106;
//			axis_flag = 'x';
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		
//		if (this->InteractionProp == this->SM_RUA)
//		{
//			boneID = 2;
//			axis_flag = 'x';
//			SMrua_x = 1;
//			SMrua_y = 0;
//			SMrua_z = 0;
//			SManim_rua_angleX = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_RLA)
//		{
//			boneID = 3;
//			axis_flag = 'x';
//			this->Move = true;
//			SMrla_x = 1;
//			SMrla_y = 0;
//			SMrla_z = 0;
//			SManim_rla_angleX = 4;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_RH_Actor)
//		{
//
//			if (rhIK_flag == 1)
//			{
//				boneID = 10;
//		
//			}
//			if(rhIK_flag == 0)
//			{
//				boneID = 109;
//	
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			SMrh_x = 1;
//			SMrh_y = 0;
//			SMrh_z = 0;
//			
//				
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		
//		if (this->InteractionProp == this->SM_LUA)
//		{
//
//			boneID = 4;
//			axis_flag = 'x';
//			SMlua_x = 1;
//			SMlua_y = 0;
//			SMlua_z = 0;
//			SManim_lua_angleX = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_LLA)
//		{
//			boneID = 5;
//			axis_flag = 'x';
//			SMlla_x = 1;
//			SMlla_y = 0;
//			SMlla_z = 0;
//			SManim_lla_angleX = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_LH_Actor)
//		{
//
//			if (rhIK_flag == 1)
//			{
//				boneID = 15;
//
//			}
//			if (rhIK_flag == 0)
//			{
//				boneID = 112;
//
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			SMlh_x = 1;
//			SMlh_y = 0;
//			SMlh_z = 0;
//
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		
//		if (this->InteractionProp == this->SM_RUL)
//		{
//			boneID = 6;
//			axis_flag = 'x';
//			SMrul_x = 1;
//			SMrul_y = 0;
//			SMrul_z = 0;
//			SManim_rul_angleX = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_RLL)
//		{
//			boneID = 7;
//			axis_flag = 'x';
//			SMrll_x = 1;
//			SMrll_y = 0;
//			SMrll_z = 0;
//			SManim_rll_angleX = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_RF_Actor)
//		{
//			if (rfIK_flag == 1)
//			{
//				boneID = 16;
//			}
//			if (rfIK_flag == 0)
//			{
//				boneID = 115;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			SMrf_x = 1;
//			SMrf_y = 0;
//			SMrf_z = 0;
//
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		
//		if (this->InteractionProp == this->SM_LUL)
//		{
//			boneID = 8;
//			axis_flag = 'x';
//			SMlul_x = 1;
//			SMlul_y = 0;
//			SMlul_z = 0;
//			SManim_lul_angleX = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_LLL)
//		{
//			boneID = 9;
//			axis_flag = 'x';
//			SMlll_x = 1;
//			SMlll_y = 0;
//			SMlll_z = 0;
//			SManim_lll_angleX = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_LF_Actor)
//		{	
//			if (lfIK_flag == 1)
//			{
//				boneID = 21;
//			}
//			if (lfIK_flag == 0)
//			{
//				boneID = 118;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			SMlf_x = 1;
//			SMlf_y = 0;
//			SMlf_z = 0;
//
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			renderWindow->Render();
//		}
//
//		//======================================================================================================//
//
//		if (this->InteractionProp == this->ffIK_pelvisActor)
//		{
//			boneID = 500;
//			axis_flag = 'x';
//			ffIKpl_x = 1;
//			ffIKpl_y = 0;
//			ffIKpl_z = 0;
//			ffIKanim_pl_angleX = 4;
//			this->Move = true;
//
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->ffIK_CH0)
//		{
//			boneID = 501;
//			axis_flag = 'x';
//			ffIKch0_x = 1;
//			ffIKch0_y = 0;
//			ffIKch0_z = 0;
//			ffIKanim_ch0_angleX = 4;
//			this->Move = true;
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->ffIK_CH1)
//		{
//	
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_CH2)
//		{
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_CH3)
//		{
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->ffIK_headActor)
//		{
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->ffIK_RUA)
//		{
//			boneID = 502;
//			axis_flag = 'x';
//			ffIKrua_x = 1;
//			ffIKrua_y = 0;
//			ffIKrua_z = 0;
//			ffIKanim_rua_angleX = 4;
//			this->Move = true;
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_RLA)
//		{
//			boneID = 503;
//			axis_flag = 'x';
//			ffIKrla_x = 1;
//			ffIKrla_y = 0;
//			ffIKrla_z = 0;
//			ffIKanim_rla_angleX = 4;
//			this->Move = true;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_RH)
//		{
//			if (rhIK_flag == 1)
//			{
//				boneID = 510;
//			}
//			if (rhIK_flag == 0)
//			{
//				boneID = 50;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			ffIKrh_x = 1;
//			ffIKrh_y = 0;
//			ffIKrh_z = 0;
//		
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->ffIK_LUA)
//		{
//			boneID = 504;
//			axis_flag = 'x';
//			ffIKlua_x = 1;
//			ffIKlua_y = 0;
//			ffIKlua_z = 0;
//			ffIKanim_lua_angleX = 4;
//			this->Move = true;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_LLA)
//		{
//			boneID = 505;
//			axis_flag = 'x';
//			ffIKlla_x = 1;
//			ffIKlla_y = 0;
//			ffIKlla_z = 0;
//			ffIKanim_lla_angleX = 4;
//			this->Move = true;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_LH)
//		{
//			if (lhIK_flag == 1)
//			{
//				boneID = 511;
//			}
//			if (lhIK_flag == 0)
//			{
//				boneID = 51;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			ffIKlh_x = 1;
//			ffIKlh_y = 0;
//			ffIKlh_z = 0;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->ffIK_RUL)
//		{
//			boneID = 506;
//			axis_flag = 'x';
//			ffIKrul_x = 1;
//			ffIKrul_y = 0;
//			ffIKrul_z = 0;
//			ffIKanim_rul_angleX = 4;
//			this->Move = true;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_RLL)
//		{
//			boneID = 507;
//			axis_flag = 'x';
//			ffIKrll_x = 1;
//			ffIKrll_y = 0;
//			ffIKrll_z = 0;
//			ffIKanim_rll_angleX = 4;
//			this->Move = true;
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_RF_Actor)
//		{		
//			if (rfIK_flag == 1)
//			{
//				boneID = 512;
//			}
//			if (rfIK_flag == 0)
//			{
//				boneID = 52;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			ffIKrf_x = 1;
//			ffIKrf_y = 0;
//			ffIKrf_z = 0;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->ffIK_LUL)
//		{
//			boneID = 508;
//			axis_flag = 'x';
//			ffIKlul_x = 1;
//			ffIKlul_y = 0;
//			ffIKlul_z = 0;
//			ffIKanim_lul_angleX = 4;
//			this->Move = true;
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_LLL)
//		{
//			boneID = 509;
//			axis_flag = 'x';
//			ffIKlll_x = 1;
//			ffIKlll_y = 0;
//			ffIKlll_z = 0;
//			ffIKanim_lll_angleX = 4;
//			this->Move = true;
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_LF_Actor)
//		{
//
//			if (lfIK_flag == 1)
//			{
//				boneID = 513;
//			}
//			if (lfIK_flag == 0)
//			{
//				boneID = 53;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			ffIKlf_x = 1;
//			ffIKlf_y = 0;
//			ffIKlf_z = 0;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		//================================= Free Left Foot and Right Foot =========================//
//		
//		if (this->InteractionProp == this->freeLeftFoot_Actor)
//		{
//			if (lfIK_flag == 1)
//			{
//				boneID = 1003;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			freeLF_x = 1;
//			freeLF_y = 0;
//			freeLF_z = 0;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_freeLeftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//
//		}
//		if (this->InteractionProp == this->freeRightFoot_Actor)
//		{
//			if (rfIK_flag == 1)
//			{
//				boneID = 2003;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			freeRF_x = 1;
//			freeRF_y = 0;
//			freeRF_z = 0;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_freeRightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		//================================= Props ==================================================//
//		if (this->InteractionProp == this->ConsProp_sphere_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 91;
//			this->Move = true;
//			//axis_flag = 'y';
//			consProp_sphere_x = 0;
//			consProp_sphere_y = 1;
//			consProp_sphere_z = 0;
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_sphere_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9100;
//			this->Move = true;
//			//axis_flag = 'y';
//			TconsProp_sphere_x = 0;
//			TconsProp_sphere_y = 1;
//			TconsProp_sphere_z = 0;
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_sphere_actor2)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9200;
//			this->Move = true;
//			//axis_flag = 'y';
//			TconsProp_sphere_x2 = 0;
//			TconsProp_sphere_y2 = 1;
//			TconsProp_sphere_z2 = 0;
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->TConsProp_sphere_actor3)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9300;
//			this->Move = true;
//			//axis_flag = 'y';
//			TconsProp_sphere_x3 = 0;
//			TconsProp_sphere_y3 = 1;
//			TconsProp_sphere_z3 = 0;
//			renderWindow->Render();
//		}
//
//
//
//
//		if (this->InteractionProp == this->ConsProp_line_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 92;
//			this->Move = true;
//			axis_flag = 'y';
//			consProp_line_x = 0;
//			consProp_line_y = 1;
//			consProp_line_z = 0;
//			renderWindow->Render();
//		}
//		
//		if (this->InteractionProp == this->TConsProp_line_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 9001;
//			this->Move = true;
//			axis_flag = 'y';
//			TconsProp_line_x = 0;
//			TconsProp_line_y = 1;
//			TconsProp_line_z = 0;
//			renderWindow->Render();
//
//		}
//
//		if (this->InteractionProp == this->TConsProp_line_actor2)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 9002;
//			this->Move = true;
//			axis_flag = 'y';
//			TconsProp_line_x2 = 0;
//			TconsProp_line_y2 = 1;
//			TconsProp_line_z2 = 0;
//			renderWindow->Render();
//
//		}
//		if (this->InteractionProp == this->TConsProp_line_actor3)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 9003;
//			this->Move = true;
//			axis_flag = 'y';
//			TconsProp_line_x3 = 0;
//			TconsProp_line_y3 = 1;
//			TconsProp_line_z3 = 0;
//			renderWindow->Render();
//
//		}
//
//
//
//		if (this->InteractionProp == this->ConsProp_plane_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			boneID = 93;
//			this->Move = true;
//			axis_flag = 'y';
//			consProp_plane_x = 0;
//			consProp_plane_y = 1;
//			consProp_plane_z = 0;
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ConsProp_cube_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 94;
//			this->Move = true;
//			axis_flag = 'y';
//			consProp_cube_x = 0;
//			consProp_cube_y = 1;
//			consProp_cube_z = 0;
//			renderWindow->Render();
//		}
//
//	
//
//	}
//	
//	virtual void OnRightButtonUp() override
//	{
//		vtkInteractorStyleTrackballActor::OnRightButtonUp();
//		this->Move = false;
//
//	}
//	virtual void OnRightButtonDown() override
//	{
//		vtkInteractorStyleTrackballActor::OnRightButtonDown();
//		flag = 2;
//
//		if (this->InteractionProp == this->pelvisActor)
//		{
//
//			/*boneID = 0;
//			axis_flag = 'z';
//			this->Move = true;
//			pelvis_x = 0;
//			pelvis_y = 0;
//			pelvis_z = 1;
//			anim_pelvis_angle = 4;
//			anim_pelvis_x = 0;
//			anim_pelvis_y = 0;
//			anim_pelvis_z = 1;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->chestActor)
//		{
//			/*boneID = 1;
//			axis_flag = 'z';
//			this->Move = true;
//			chest_x = 0;
//			chest_y = 0;
//			chest_z = 1;
//			anim_chest_angle = 4;
//			anim_chest_x = 0;
//			anim_chest_y = 0;
//			anim_chest_z = -1;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;
//*/
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->RUA)
//		{
//			/*boneID = 2;
//			axis_flag = 'z';
//			this->Move = true;
//			rua_x = 0;
//			rua_y = 0;
//			rua_z = 1;
//			anim_rua_angle = 4;
//			anim_rua_x = 0;
//			anim_rua_y = 0;
//			anim_rua_z = 1;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//
//		}
//		if (this->InteractionProp == this->RLA)
//		{
//			/*boneID = 3;
//			axis_flag = 'z';
//			this->Move = true;
//			rla_x = 0;
//			rla_y = 0;
//			rla_z = 1;
//			anim_rla_angle = 4;
//			anim_rla_x = 0;
//			anim_rla_y = 0;
//			anim_rla_z = 1;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//
//
//		}
//
//		if (this->InteractionProp == this->LUA)
//		{
//			/*boneID = 4;
//			axis_flag = 'z';
//			this->Move = true;
//			lua_x = 0;
//			lua_y = 0;
//			lua_z = -1;
//			anim_lua_angle = 4;
//			anim_lua_x = 0;
//			anim_lua_y = 0;
//			anim_lua_z = -1;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//
//		}
//		if (this->InteractionProp == this->LLA)
//		{
//			/*boneID = 5;
//			axis_flag = 'z';
//			this->Move = true;
//			lla_x = 0;
//			lla_y = 0;
//			lla_z = -1;
//			anim_lla_angle = 4;
//			anim_lla_x = 0;
//			anim_lla_y = 0;
//			anim_lla_z = -1;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//
//		}
//
//		if (this->InteractionProp == this->RUL)
//		{
//			/*boneID = 6;
//			axis_flag = 'z';
//			this->Move = true;
//			rul_x = 0;
//			rul_y = 0;
//			rul_z = 1;
//			anim_rul_angle = 4;
//			anim_rul_x = 0;
//			anim_rul_y = 0;
//			anim_rul_z = 1;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->RLL)
//		{/*
//			boneID = 7;
//			axis_flag = 'z';
//			this->Move = true;
//			rll_x = 0;
//			rll_y = 0;
//			rll_z = 1;
//			anim_rll_angle = 4;
//			anim_rll_x = 0;
//			anim_rll_y = 0;
//			anim_rll_z = 1;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->LUL)
//		{
//			/*boneID = 8;
//			axis_flag = 'z';
//			this->Move = true;
//			lul_x = 0;
//			lul_y = 0;
//			lul_z = -1;
//			anim_lul_angle = 4;
//			anim_lul_x = 0;
//			anim_lul_y = 0;
//			anim_lul_z = -1;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			//dummy1 = 0;
//			//dummy2 = 0;
//			//dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->LLL)
//		{
//			/*boneID = 9;
//			axis_flag = 'z';
//			this->Move = true;
//			lll_x = 0;
//			lll_y = 0;
//			lll_z = -1;
//			anim_lll_angle = 4;
//			anim_lll_x = 0;
//			anim_lll_y = 0;
//			anim_lll_z = -1;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//		}
//
//		//======================================================================================//
//		if (this->InteractionProp == this->SM_CH0)
//		{
//
//			boneID = 1;
//			axis_flag = 'z';
//			SMch0_x = 0;
//			SMch0_y = 0;
//			SMch0_z = 1;
//			SManim_ch0_angleZ = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->SM_RUA)
//		{
//			boneID = 2;
//			axis_flag = 'z';
//			SMrua_x = 0;
//			SMrua_y = 0;
//			SMrua_z = 1;
//			SManim_rua_angleZ = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_RLA)
//		{
//			boneID = 3;
//			axis_flag = 'z';
//			this->Move = true;
//			SMrla_x = 0;
//			SMrla_y = 0;
//			SMrla_z = 1;
//			SManim_rla_angleZ = 4;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_RH_Actor)
//		{
//
//			if (rhIK_flag == 1)
//			{
//				boneID = 10;
//
//			}
//			if (rhIK_flag == 0)
//			{
//				boneID = 109;
//
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			SMrh_x = 1;
//			SMrh_y = 0;
//			SMrh_z = 0;
//
//
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->SM_LUA)
//		{
//
//			boneID = 4;
//			axis_flag = 'z';
//			SMlua_x = 0;
//			SMlua_y = 0;
//			SMlua_z = 1;
//			SManim_lua_angleZ = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_LLA)
//		{
//			boneID = 5;
//			axis_flag = 'z';
//			SMlla_x = 0;
//			SMlla_y = 0;
//			SMlla_z = 1;
//			SManim_lla_angleZ = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_LH_Actor)
//		{
//
//			if (rhIK_flag == 1)
//			{
//				boneID = 15;
//
//			}
//			if (rhIK_flag == 0)
//			{
//				boneID = 112;
//
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			SMlh_x = 1;
//			SMlh_y = 0;
//			SMlh_z = 0;
//
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->SM_RUL)
//		{
//			boneID = 6;
//			axis_flag = 'z';
//			SMrul_x = 0;
//			SMrul_y = 0;
//			SMrul_z = 1;
//			SManim_rul_angleZ = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_RLL)
//		{
//			boneID = 7;
//			axis_flag = 'z';
//			SMrll_x = 0;
//			SMrll_y = 0;
//			SMrll_z = 1;
//			SManim_rll_angleZ = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_RF_Actor)
//		{
//			if (rfIK_flag == 1)
//			{
//				boneID = 16;
//			}
//			if (rfIK_flag == 0)
//			{
//				boneID = 115;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			SMrf_x = 1;
//			SMrf_y = 0;
//			SMrf_z = 0;
//
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->SM_LUL)
//		{
//			boneID = 8;
//			axis_flag = 'z';
//			SMlul_x = 0;
//			SMlul_y = 0;
//			SMlul_z = 1;
//			SManim_lul_angleZ = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_LLL)
//		{
//			boneID = 9;
//			axis_flag = 'z';
//			SMlll_x = 0;
//			SMlll_y = 0;
//			SMlll_z = 1;
//			SManim_lll_angleZ = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->SM_LF_Actor)
//		{
//
//
//			if (lfIK_flag == 1)
//			{
//				boneID = 21;
//			}
//			if (lfIK_flag == 0)
//			{
//				boneID = 118;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			SMlf_x = 1;
//			SMlf_y = 0;
//			SMlf_z = 0;
//
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			renderWindow->Render();
//		}
//
//		//=======================================================================================//
//		
//		if (this->InteractionProp == this->ffIK_pelvisActor)
//		{
//			boneID = 500;
//			axis_flag = 'x';
//			ffIKpl_x = 1;
//			ffIKpl_y = 0;
//			ffIKpl_z = 0;
//			ffIKanim_pl_angleX = 4;
//			this->Move = true;
//
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_CH0)
//		{
//			boneID = 501;
//			axis_flag = 'z';
//			ffIKch0_x = 0;
//			ffIKch0_y = 0;
//			ffIKch0_z = 1;
//			ffIKanim_ch0_angleZ = 4;
//			this->Move = true;
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		
//		if (this->InteractionProp == this->ffIK_RUA)
//		{
//			boneID = 502;
//			axis_flag = 'z';
//			ffIKrua_x = 0;
//			ffIKrua_y = 0;
//			ffIKrua_z = 1;
//			ffIKanim_rua_angleZ = 4;
//			this->Move = true;
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_RLA)
//		{
//			boneID = 503;
//			axis_flag = 'z';
//			ffIKrla_x = 0;
//			ffIKrla_y = 0;
//			ffIKrla_z = 1;
//			ffIKanim_rla_angleZ = 4;
//			this->Move = true;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_RH)
//		{
//			if (rhIK_flag == 1)
//			{
//				boneID = 510;
//			}
//			if (rhIK_flag == 0)
//			{
//				boneID = 50;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			ffIKrh_x = 1;
//			ffIKrh_y = 0;
//			ffIKrh_z = 0;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->ffIK_LUA)
//		{
//			boneID = 504;
//			axis_flag = 'z';
//			ffIKlua_x = 0;
//			ffIKlua_y = 0;
//			ffIKlua_z = 1;
//			ffIKanim_lua_angleZ = 4;
//			this->Move = true;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_LLA)
//		{
//			boneID = 505;
//			axis_flag = 'z';
//			ffIKlla_x = 0;
//			ffIKlla_y = 0;
//			ffIKlla_z = 1;
//			ffIKanim_lla_angleZ = 4;
//			this->Move = true;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ffIK_LH)
//		{
//			if (lhIK_flag == 1)
//			{
//				boneID = 511;
//			}
//			if (lhIK_flag == 0)
//			{
//				boneID = 51;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			ffIKlh_x = 1;
//			ffIKlh_y = 0;
//			ffIKlh_z = 0;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			renderWindow->Render();
//		}
//
//		//============================================================================================
//		if (this->InteractionProp == this->freeLeftFoot_Actor)
//		{
//			if (lfIK_flag == 1)
//			{
//				boneID = 1003;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			freeLF_x = 1;
//			freeLF_y = 0;
//			freeLF_z = 0;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_freeLeftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//
//		}
//		if (this->InteractionProp == this->freeRightFoot_Actor)
//		{
//			if (rfIK_flag == 1)
//			{
//				boneID = 2003;
//			}
//			axis_flag = 'x';
//			this->Move = true;
//			freeRF_x = 1;
//			freeRF_y = 0;
//			freeRF_z = 0;
//
//			IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_freeRightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//			IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//
//			IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			renderWindow->Render();
//		}
//
//		//============================================================================================
//		if (this->InteractionProp == this->ConsProp_sphere_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 91;
//			this->Move = true;
//			axis_flag = 'x';
//			consProp_sphere_x = 1;
//			consProp_sphere_y = 0;
//			consProp_sphere_z = 0;
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_sphere_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9100;
//			this->Move = true;
//			axis_flag = 'x';
//			TconsProp_sphere_x = 1;
//			TconsProp_sphere_y = 0;
//			TconsProp_sphere_z = 0;
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->TConsProp_sphere_actor2)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9200;
//			this->Move = true;
//			axis_flag = 'x';
//			TconsProp_sphere_x2 = 1;
//			TconsProp_sphere_y2 = 0;
//			TconsProp_sphere_z2 = 0;
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->TConsProp_sphere_actor3)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9300;
//			this->Move = true;
//			axis_flag = 'x';
//			TconsProp_sphere_x3 = 1;
//			TconsProp_sphere_y3 = 0;
//			TconsProp_sphere_z3 = 0;
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->ConsProp_line_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 92;
//			this->Move = true;
//			axis_flag = 'x';
//			consProp_line_x = 1;
//			consProp_line_y = 0;
//			consProp_line_z = 0;
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->TConsProp_line_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9001;
//			this->Move = true;
//			axis_flag = 'x';
//			TconsProp_line_x = 1;
//			TconsProp_line_y = 0;
//			TconsProp_line_z = 0;
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->TConsProp_line_actor2)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9002;
//			this->Move = true;
//			axis_flag = 'x';
//			TconsProp_line_x2 = 1;
//			TconsProp_line_y2 = 0;
//			TconsProp_line_z2 = 0;
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->TConsProp_line_actor3)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9003;
//			this->Move = true;
//			axis_flag = 'x';
//			TconsProp_line_x3 = 1;
//			TconsProp_line_y3 = 0;
//			TconsProp_line_z3 = 0;
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->ConsProp_plane_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 93;
//			this->Move = true;
//			axis_flag = 'x';
//			consProp_plane_x = 1;
//			consProp_plane_y = 0;
//			consProp_plane_z = 0;
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ConsProp_cube_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 94;
//			this->Move = true;
//			axis_flag = 'x';
//			consProp_cube_x = 1;
//			consProp_cube_y = 0;
//			consProp_cube_z = 0;
//			renderWindow->Render();
//		}
//	}
//		
//	virtual void OnMouseWheelForward()  override
//	{
//
//		vtkInteractorStyleTrackballActor::OnMouseWheelForward();
//
//		flag = 3;
//
//		if (this->InteractionProp == this->chestActor)
//		{
//		/*	boneID = 1;
//			axis_flag = 'y';
//
//			chest_x = 0;
//			chest_y = 1;
//			chest_z = 0;
//			anim_chest_angle = 4;
//			anim_chest_x = 0;
//			anim_chest_y = 1;
//			anim_chest_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//
//
//			compute(chest_angle, chest_x, chest_y, chest_z, boneID);
//			CHEST(anim_chest_angle, anim_chest_x, anim_chest_y, anim_chest_z);
//			chest_angle+=4;
//		}
//
//		if (this->InteractionProp == this->RUA)
//		{
//			/*boneID = 2;
//			axis_flag = 'y';
//
//			rua_x = 0;
//			rua_y = 1;
//			rua_z = 0;
//			anim_rua_angle = 4;
//			anim_rua_x = 0;
//			anim_rua_y = 1;
//			anim_rua_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			//dummy1 = 0;
//			//dummy2 = 0;
//			//dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//
//			/*	compute(rua_angle, rua_x, rua_y, rua_z, boneID);
//				rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);
//				rua_angle++;*/
//
//			compute(rua_angleY, rua_x, rua_y, rua_z, boneID);
//			rua(anim_rua_angle, anim_rua_x, anim_rua_y, anim_rua_z);
//			rua_angleY += 4;
//			/*rua_angleY += 4;
//			cout << "ruaY_angle=" << rua_angleY << endl;*/
//
//
//		}
//		if (this->InteractionProp == this->RLA)
//		{
//			/*boneID = 3;
//			axis_flag = 'y';
//
//			rla_x = 0;
//			rla_y = 1;
//			rla_z = 0;
//			anim_rla_angle = 4;
//			anim_rla_x = 0;
//			anim_rla_y = 1;
//			anim_rla_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			//dummy1 = 0;
//			//dummy2 = 0;
//			//dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//
//			//compute(rla_angle, rla_x, rla_y, rla_z, boneID);
//			//rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);
//			//rla_angle++;
//
//
//			compute(rla_angleY, rla_x, rla_y, rla_z, boneID);
//			rla(anim_rla_angle, anim_rla_x, anim_rla_y, anim_rla_z);
//			rla_angleY += 4;
//
//
//		}
//
//		if (this->InteractionProp == this->LUA)
//		{
//			/*boneID = 4;
//			axis_flag = 'y';
//
//			lua_x = 0;
//			lua_y = 1;
//			lua_z = 0;
//			anim_lua_angle = 4;
//			anim_lua_x = 0;
//			anim_lua_y = 1;
//			anim_lua_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//
//			compute(lua_angle, lua_x, lua_y, lua_z, boneID);
//			lua(anim_lua_angle, anim_lua_x, anim_lua_y, anim_lua_z);
//			lua_angle+=4;
//
//		}
//		if (this->InteractionProp == this->LLA)
//		{
//			/*boneID = 5;
//			axis_flag = 'y';
//
//			lla_x = 0;
//			lla_y = 1;
//			lla_z = 0;
//			anim_lla_angle = 4;
//			anim_lla_x = 0;
//			anim_lla_y = 1;
//			anim_lla_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//
//			compute(lla_angle, lla_x, lla_y, lla_z, boneID);
//			lla(anim_lla_angle, anim_lla_x, anim_lla_y, anim_lla_z);
//			lla_angle+=4;
//
//		}
//
//		if (this->InteractionProp == this->RUL)
//		{
//			/*boneID = 6;
//			axis_flag = 'y';
//
//			rul_x = 0;
//			rul_y = 1;
//			rul_z = 0;
//			anim_rul_angle = 4;
//			anim_rul_x = 0;
//			anim_rul_y = 1;
//			anim_rul_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//
//			
//			compute(rul_angle, rul_x, rul_y, rul_z, boneID);
//			rul(anim_rul_angle, anim_rul_x, anim_rul_y, anim_rul_z);
//			rul_angle += 4;
//
//		}
//		if (this->InteractionProp == this->RLL)
//		{
//			/*boneID = 7;
//			axis_flag = 'y';
//
//			rll_x = 0;
//			rll_y = 1;
//			rll_z = 0;
//			anim_rll_angle = 4;
//			anim_rll_x = 0;
//			anim_rll_y = 1;
//			anim_rll_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//
//		
//			compute(rll_angle, rll_x, rll_y, rll_z, boneID);
//			rll(anim_rll_angle, anim_rll_x, anim_rll_y, anim_rll_z);
//			rll_angle += 4;
//
//
//
//		}
//
//		if (this->InteractionProp == this->LUL)
//		{
//			/*boneID = 8;
//			axis_flag = 'y';
//
//			lul_x = 0;
//			lul_y = 1;
//			lul_z = 0;
//			anim_lul_angle = 4;
//			anim_lul_x = 0;
//			anim_lul_y = 1;
//			anim_lul_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//
//			compute(lul_angle, lul_x, lul_y, lul_z, boneID);
//			lul(anim_lul_angle, anim_lul_x, anim_lul_y, anim_lul_z);
//			lul_angle+=4;
//
//		}
//		if (this->InteractionProp == this->LLL)
//		{
//			/*boneID = 9;
//			axis_flag = 'y';
//
//			lll_x = 0;
//			lll_y = 1;
//			lll_z = 0;
//			anim_lll_angle = 4;
//			anim_lll_x = 0;
//			anim_lll_y = 1;
//			anim_lll_z = 0;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//
//
//			compute(lll_angle, lll_x, lll_y, lll_z, boneID);
//			lll(anim_lll_angle, anim_lll_x, anim_lll_y, anim_lll_z);
//			lll_angle+=4;
//
//		}
//
//		//============================================================================================================
//		if (this->InteractionProp == this->SM_CH0)
//		{
//
//			boneID = 1;
//			axis_flag = 'y';
//			SMch0_x = 0;
//			SMch0_y = 1;
//			SMch0_z = 0;
//			SManim_ch0_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//
//			SMch0_angleY += 4;
//			animateSM_CH0(SManim_ch0_angleY, -SMch0_x, -SMch0_y, -SMch0_z);
//			compute(SMch0_angleY, -SMch0_x, -SMch0_y, -SMch0_z, boneID);
//
//		}
//
//		if (this->InteractionProp == this->SM_RUA)
//		{
//			boneID = 2;
//			axis_flag = 'y';
//			SMrua_x = 0;
//			SMrua_y = 1;
//			SMrua_z = 0;
//			SManim_rua_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//			SMrua_angleY += 4;
//			animateSM_RUA(SManim_rua_angleY, -SMrua_x, -SMrua_y, -SMrua_z);
//			compute(SMrua_angleY, -SMrua_x, -SMrua_y, -SMrua_z, boneID);
//		}
//		if (this->InteractionProp == this->SM_RLA)
//		{
//			boneID = 3;
//			axis_flag = 'y';
//			this->Move = true;
//			SMrla_x = 0;
//			SMrla_y = 1;
//			SMrla_z = 0;
//			SManim_rla_angleY = 4;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//			SMrla_angleY += 4;
//			animateSM_RLA(SManim_rla_angleY, -SMrla_x, -SMrla_y, -SMrla_z);
//			compute(SMrla_angleY, -SMrla_x, -SMrla_y, -SMrla_z, boneID);
//		}
//
//		if (this->InteractionProp == this->SM_LUA)
//		{
//
//			boneID = 4;
//			axis_flag = 'y';
//			SMlua_x = 0;
//			SMlua_y = 1;
//			SMlua_z = 0;
//			SManim_lua_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//			SMlua_angleY += 4;
//			animateSM_LUA(SManim_lua_angleY, SMlua_x, SMlua_y, SMlua_z);
//			compute(SMlua_angleY, SMlua_x, SMlua_y, SMlua_z, boneID);
//		}
//		if (this->InteractionProp == this->SM_LLA)
//		{
//			boneID = 5;
//			axis_flag = 'y';
//			SMlla_x = 0;
//			SMlla_y = 1;
//			SMlla_z = 0;
//			SManim_lla_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//			SMlla_angleY += 4;
//			animateSM_LLA(SManim_lla_angleY, SMlla_x, SMlla_y, SMlla_z);
//			compute(SMlla_angleY, SMlla_x, SMlla_y, SMlla_z, boneID);
//		}
//
//
//		if (this->InteractionProp == this->SM_RUL)
//		{
//			boneID = 6;
//			axis_flag = 'y';
//			SMrul_x = 0;
//			SMrul_y = 1;
//			SMrul_z = 0;
//			SManim_rul_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//			SMrul_angleY += 4;
//			animateSM_RUL(SManim_rul_angleY, -SMrul_x, -SMrul_y, -SMrul_z);
//			compute(SMrul_angleY, -SMrul_x, -SMrul_y, -SMrul_z, boneID);
//		}
//		if (this->InteractionProp == this->SM_RLL)
//		{
//			boneID = 7;
//			axis_flag = 'y';
//			SMrll_x = 0;
//			SMrll_y = 1;
//			SMrll_z = 0;
//			SManim_rll_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//
//			SMrll_angleY += 4;
//			animateSM_RLL(SManim_rll_angleY, -SMrll_x, -SMrll_y, -SMrll_z);
//			compute(SMrll_angleY, -SMrll_x, -SMrll_y, -SMrll_z, boneID);
//		}
//
//		if (this->InteractionProp == this->SM_LUL)
//		{
//			boneID = 8;
//			axis_flag = 'y';
//			SMlul_x = 0;
//			SMlul_y = 1;
//			SMlul_z = 0;
//			SManim_lul_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//
//			SMlul_angleY += 4;
//			animateSM_LUL(SManim_lul_angleY, SMlul_x, SMlul_y, SMlul_z);
//			compute(SMlul_angleY, SMlul_x, SMlul_y, SMlul_z, boneID);
//
//		}
//		if (this->InteractionProp == this->SM_LLL)
//		{
//			boneID = 9;
//			axis_flag = 'y';
//			SMlll_x = 0;
//			SMlll_y = 1;
//			SMlll_z = 0;
//			SManim_lll_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//
//			SMlll_angleY += 4;
//			animateSM_LLL(SManim_lll_angleY, SMlll_x, SMlll_y, SMlll_z);
//			compute(SMlll_angleY, SMlll_x, SMlll_y, SMlll_z, boneID);
//		}
//
//		//==============================================================================================================
//		if (this->InteractionProp == this->ConsProp_sphere_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 91;
//			//this->Move = true;
//			axis_flag = 'z';
//			consProp_sphere_x = 0;
//			consProp_sphere_y = 0;
//			consProp_sphere_z = 1;
//
//			moveSphereProp(consProp_sphere_x, consProp_sphere_y, consProp_sphere_z);
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->TConsProp_sphere_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9100;
//			//this->Move = true;
//			axis_flag = 'z';
//			TconsProp_sphere_x = 0;
//			TconsProp_sphere_y = 0;
//			TconsProp_sphere_z = 1;
//
//			TmoveSphereProp(TconsProp_sphere_x, TconsProp_sphere_y, TconsProp_sphere_z);
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_sphere_actor2)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9200;
//			//this->Move = true;
//			axis_flag = 'z';
//			TconsProp_sphere_x2 = 0;
//			TconsProp_sphere_y2 = 0;
//			TconsProp_sphere_z2 = 1;
//
//			TmoveSphereProp2(TconsProp_sphere_x2, TconsProp_sphere_y2, TconsProp_sphere_z2);
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_sphere_actor3)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9300;
//			//this->Move = true;
//			axis_flag = 'z';
//			TconsProp_sphere_x3 = 0;
//			TconsProp_sphere_y3 = 0;
//			TconsProp_sphere_z3 = 1;
//
//			TmoveSphereProp3(TconsProp_sphere_x3, TconsProp_sphere_y3, TconsProp_sphere_z3);
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->ConsProp_line_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 92;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			consProp_line_x = 0;
//			consProp_line_y = 0;
//			consProp_line_z = 1;
//			moveLineProp(consProp_line_x, consProp_line_y, consProp_line_z);
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_line_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9001;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			TconsProp_line_x = 0;
//			TconsProp_line_y = 0;
//			TconsProp_line_z = 1;
//			TmoveLineProp(TconsProp_line_x, TconsProp_line_y, TconsProp_line_z);
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_line_actor2)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9002;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			TconsProp_line_x2 = 0;
//			TconsProp_line_y2 = 0;
//			TconsProp_line_z2 = 1;
//			TmoveLineProp2(TconsProp_line_x2, TconsProp_line_y2, TconsProp_line_z2);
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_line_actor3)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9003;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			TconsProp_line_x3 = 0;
//			TconsProp_line_y3 = 0;
//			TconsProp_line_z3 = 1;
//			TmoveLineProp3(TconsProp_line_x3, TconsProp_line_y3, TconsProp_line_z3);
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->ConsProp_plane_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 93;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			consProp_plane_x = 0;
//			consProp_plane_y = 0;
//			consProp_plane_z = 1;
//			movePlaneProp(consProp_plane_x, consProp_plane_y, consProp_plane_z);
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ConsProp_cube_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 94;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			consProp_cube_x = 0;
//			consProp_cube_y = 0;
//			consProp_cube_z = 1;
//			moveCubeProp(consProp_cube_x, consProp_cube_y, consProp_cube_z);
//			renderWindow->Render();
//		}
//
//	}
//	virtual void OnMouseWheelBackward()  override
//	{
//
//		vtkInteractorStyleTrackballActor::OnMouseWheelBackward();
//
//		flag = 3;
//
//		if (this->InteractionProp == this->chestActor)
//		{
//			/*boneID = 1;
//			axis_flag = 'y';
//
//			chest_x = 0;
//			chest_y = 1;
//			chest_z = 0;
//			anim_chest_angle = 4;
//			anim_chest_x = 0;
//			anim_chest_y = 1;
//			anim_chest_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//
//			chest_angle -= 4;
//			compute(chest_angle, chest_x, chest_y, chest_z, boneID);
//			CHEST(anim_chest_angle, anim_chest_x, -anim_chest_y, anim_chest_z);
//
//		}
//
//		if (this->InteractionProp == this->RUA)
//		{
//			/*boneID = 2;
//			axis_flag = 'y';
//
//			rua_x = 0;
//			rua_y = 1;
//			rua_z = 0;
//			anim_rua_angle = 4;
//			anim_rua_x = 0;
//			anim_rua_y = 1;
//			anim_rua_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			//dummy1 = 0;
//			//dummy2 = 0;
//			//dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//
//			renderWindow->Render();
//
//			/*	compute(rua_angle, rua_x, rua_y, rua_z, boneID);
//				rua(anim_rua_angle, anim_rua_x, -anim_rua_y, anim_rua_z);
//				rua_angle--;*/
//
//			rua_angleY -= 4;
//			compute(rua_angleY, rua_x, rua_y, rua_z, boneID);
//			rua(anim_rua_angle, anim_rua_x, -anim_rua_y, anim_rua_z);
//
//
//			//rua_angleY -= 4;
//			//cout << "ruaY_angle=" << rua_angleY << endl;
//		}
//		if (this->InteractionProp == this->RLA)
//		{
//			/*boneID = 3;
//			axis_flag = 'y';
//
//			rla_x = 0;
//			rla_y = 1;
//			rla_z = 0;
//			anim_rla_angle = 4;
//			anim_rla_x = 0;
//			anim_rla_y = 1;
//			anim_rla_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//
//			//compute(rla_angle, rla_x, rla_y, rla_z, boneID);
//			//rla_angle--;
//			//rla(anim_rla_angle, anim_rla_x, -anim_rla_y, anim_rla_z);
//
//			rla_angleY -= 4;
//			compute(rla_angleY, rla_x, rla_y, rla_z, boneID);
//			rla(anim_rla_angle, anim_rla_x, -anim_rla_y, anim_rla_z);
//
//
//		}
//
//		if (this->InteractionProp == this->LUA)
//		{
//			/*boneID = 4;
//			axis_flag = 'y';
//
//			lua_x = 0;
//			lua_y = 1;
//			lua_z = 0;
//			anim_lua_angle = 4;
//			anim_lua_x = 0;
//			anim_lua_y = 1;
//			anim_lua_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//			dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//
//			lua_angle -= 4;
//			compute(lua_angle, lua_x, lua_y, lua_z, boneID);
//			lua(anim_lua_angle, anim_lua_x, -anim_lua_y, anim_lua_z);
//			
//		}
//		if (this->InteractionProp == this->LLA)
//		{
//			/*boneID = 5;
//			axis_flag = 'y';
//
//			lla_x = 0;
//			lla_y = 1;
//			lla_z = 0;
//			anim_lla_angle = 4;
//			anim_lla_x = 0;
//			anim_lla_y = 1;
//			anim_lla_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0*/;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//			
//			lla_angle-=4;
//			compute(lla_angle, lla_x, lla_y, lla_z, boneID);
//			lla(anim_lla_angle, anim_lla_x, -anim_lla_y, anim_lla_z);
//
//
//
//		}
//
//		if (this->InteractionProp == this->RUL)
//		{
//			/*boneID = 6;
//			axis_flag = 'y';
//
//			rul_x = 0;
//			rul_y = 1;
//			rul_z = 0;
//			anim_rul_angle = 4;
//			anim_rul_x = 0;
//			anim_rul_y = 1;
//			anim_rul_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//			
//			rul_angle-=4;
//			compute(rul_angle, rul_x, rul_y, rul_z, boneID);
//			rul(anim_rul_angle, anim_rul_x, -anim_rul_y, anim_rul_z);
//		}
//		if (this->InteractionProp == this->RLL)
//		{
//			/*boneID = 7;
//			axis_flag = 'y';
//
//			rll_x = 0;
//			rll_y = 1;
//			rll_z = 0;
//			anim_rll_angle = 4;
//			anim_rll_x = 0;
//			anim_rll_y = 1;
//			anim_rll_z = 0;*/
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//		/*	dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//			
//			rll_angle-=4;
//			compute(rll_angle, rll_x, rll_y, rll_z, boneID);
//			rll(anim_rll_angle, anim_rll_x, -anim_rll_y, anim_rll_z);
//
//		}
//
//		if (this->InteractionProp == this->LUL)
//		{
//			/*boneID = 8;
//			axis_flag = 'y';
//
//			lul_x = 0;
//			lul_y = 1;
//			lul_z = 0;
//			anim_lul_angle = 4;
//			anim_lul_x = 0;
//			anim_lul_y = 1;
//			anim_lul_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//
//	/*		dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;*/
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//			
//			lul_angle -= 4;
//			compute(lul_angle, lul_x, lul_y, lul_z, boneID);
//			lul(anim_lul_angle, anim_lul_x, -anim_lul_y, anim_lul_z);
//		}
//		if (this->InteractionProp == this->LLL)
//		{
//			/*boneID = 9;
//			axis_flag = 'y';
//
//			lll_x = 0;
//			lll_y = 1;
//			lll_z = 0;
//			anim_lll_angle = 4;
//			anim_lll_x = 0;
//			anim_lll_y = 1;
//			anim_lll_z = 0;*/
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			dummy1 = 0;
//			dummy2 = 0;
//			dummy3 = 0;
//
//			std::string tA1 = "( ";
//			std::string tA2 = std::to_string(dummy1);
//			std::string tA3 = " ,";
//			std::string tA4 = std::to_string(dummy2);
//			std::string tA5 = " ,";
//			std::string tA6 = std::to_string(dummy3);
//			std::string tA7 = " )";
//
//
//			std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//			const char *text = tA.data();
//
//
//			textActor->SetInput(text);
//			renderWindow->Render();
//			
//			lll_angle -= 4;
//			compute(lll_angle, lll_x, lll_y, lll_z, boneID);
//			lll(anim_lll_angle, anim_lll_x, -anim_lll_y, anim_lll_z);
//
//		}
//
//
//		//=================================================================================
//
//		if (this->InteractionProp == this->SM_CH0)
//		{
//			boneID = 1;
//			axis_flag = 'y';
//			SMch0_x = 0;
//			SMch0_y = 1;
//			SMch0_z = 0;
//			SManim_ch0_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//
//			
//			animateSM_CH0(SManim_ch0_angleY, SMch0_x, SMch0_y, SMch0_z);
//			SMch0_angleY -= 4;
//			compute(SMch0_angleY, -SMch0_x, -SMch0_y, -SMch0_z, boneID);
//
//		}
//
//		if (this->InteractionProp == this->SM_RUA)
//		{
//			boneID = 2;
//			axis_flag = 'y';
//			SMrua_x = 0;
//			SMrua_y = 1;
//			SMrua_z = 0;
//			SManim_rua_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//			
//			animateSM_RUA(SManim_rua_angleY, SMrua_x, SMrua_y, SMrua_z);
//			SMrua_angleY -= 4;
//			compute(SMrua_angleY, -SMrua_x, -SMrua_y, -SMrua_z, boneID);
//		}
//		if (this->InteractionProp == this->SM_RLA)
//		{
//			boneID = 3;
//			axis_flag = 'y';
//			this->Move = true;
//			SMrla_x = 0;
//			SMrla_y = 1;
//			SMrla_z = 0;
//			SManim_rla_angleY = 4;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//		
//			animateSM_RLA(SManim_rla_angleY, SMrla_x, SMrla_y, SMrla_z);
//			SMrla_angleY -= 4;
//			compute(SMrla_angleY, -SMrla_x, -SMrla_y, -SMrla_z, boneID);
//		}
//
//		if (this->InteractionProp == this->SM_LUA)
//		{
//
//			boneID = 4;
//			axis_flag = 'y';
//			SMlua_x = 0;
//			SMlua_y = 1;
//			SMlua_z = 0;
//			SManim_lua_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//		
//			animateSM_LUA(SManim_lua_angleY, -SMlua_x, -SMlua_y, -SMlua_z);
//			SMlua_angleY -= 4;
//			compute(SMlua_angleY, SMlua_x, SMlua_y, SMlua_z, boneID);
//		}
//		if (this->InteractionProp == this->SM_LLA)
//		{
//			boneID = 5;
//			axis_flag = 'y';
//			SMlla_x = 0;
//			SMlla_y = 1;
//			SMlla_z = 0;
//			SManim_lla_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//		
//			animateSM_LLA(SManim_lla_angleY, -SMlla_x, -SMlla_y, -SMlla_z);
//			SMlla_angleY -= 4;
//			compute(SMlla_angleY, SMlla_x, SMlla_y, SMlla_z, boneID);
//		}
//
//
//		if (this->InteractionProp == this->SM_RUL)
//		{
//			boneID = 6;
//			axis_flag = 'y';
//			SMrul_x = 0;
//			SMrul_y = 1;
//			SMrul_z = 0;
//			SManim_rul_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//			
//			animateSM_RUL(SManim_rul_angleY, SMrul_x, SMrul_y, SMrul_z);
//			SMrul_angleY -= 4;
//			compute(SMrul_angleY, -SMrul_x, -SMrul_y,-SMrul_z, boneID);
//		}
//		if (this->InteractionProp == this->SM_RLL)
//		{
//			boneID = 7;
//			axis_flag = 'y';
//			SMrll_x = 0;
//			SMrll_y = 1;
//			SMrll_z = 0;
//			SManim_rll_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//
//			
//			animateSM_RLL(SManim_rll_angleY, SMrll_x, SMrll_y, SMrll_z);
//			SMrll_angleY -= 4;
//			compute(SMrll_angleY, -SMrll_x, -SMrll_y, -SMrll_z, boneID);
//		}
//
//		if (this->InteractionProp == this->SM_LUL)
//		{
//			boneID = 8;
//			axis_flag = 'y';
//			SMlul_x = 0;
//			SMlul_y = 1;
//			SMlul_z = 0;
//			SManim_lul_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//
//	
//			animateSM_LUL(SManim_lul_angleY, -SMlul_x, -SMlul_y, -SMlul_z);
//			SMlul_angleY-= 4;
//			compute(SMlul_angleY, SMlul_x, SMlul_y, SMlul_z, boneID);
//
//		}
//		if (this->InteractionProp == this->SM_LLL)
//		{
//			boneID = 9;
//			axis_flag = 'y';
//			SMlll_x = 0;
//			SMlll_y = 1;
//			SMlll_z = 0;
//			SManim_lll_angleY = 4;
//			this->Move = true;
//			stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//			stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//			stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			renderWindow->Render();
//
//
//			
//			animateSM_LLL(SManim_lll_angleY, -SMlll_x, -SMlll_y, -SMlll_z);
//			SMlll_angleY -= 4;
//			compute(SMlll_angleY, SMlll_x, SMlll_y, SMlll_z, boneID);
//		}
//
//		//===================================================================================
//		if (this->InteractionProp == this->ConsProp_sphere_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 91;
//			//this->Move = true;
//			axis_flag = 'z';
//			consProp_sphere_x = 0;
//			consProp_sphere_y = 0;
//			consProp_sphere_z = 1;
//
//			moveSphereProp(-consProp_sphere_x, -consProp_sphere_y, -consProp_sphere_z);
//
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_sphere_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9100;
//			//this->Move = true;
//			axis_flag = 'z';
//			TconsProp_sphere_x = 0;
//			TconsProp_sphere_y = 0;
//			TconsProp_sphere_z = 1;
//
//			TmoveSphereProp(-TconsProp_sphere_x, -TconsProp_sphere_y, -TconsProp_sphere_z);
//
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->TConsProp_sphere_actor2)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9200;
//			//this->Move = true;
//			axis_flag = 'z';
//			TconsProp_sphere_x2 = 0;
//			TconsProp_sphere_y2 = 0;
//			TconsProp_sphere_z2 = 1;
//
//			TmoveSphereProp2(-TconsProp_sphere_x2, -TconsProp_sphere_y2, -TconsProp_sphere_z2);
//
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->TConsProp_sphere_actor3)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//			boneID = 9300;
//			//this->Move = true;
//			axis_flag = 'z';
//			TconsProp_sphere_x3 = 0;
//			TconsProp_sphere_y3 = 0;
//			TconsProp_sphere_z3 = 1;
//
//			TmoveSphereProp3(-TconsProp_sphere_x3, -TconsProp_sphere_y3, -TconsProp_sphere_z3);
//
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->ConsProp_line_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 92;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			consProp_line_x = 0;
//			consProp_line_y = 0;
//			consProp_line_z = 1;
//			moveLineProp(-consProp_line_x, -consProp_line_y, -consProp_line_z);
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_line_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 9001;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			TconsProp_line_x = 0;
//			TconsProp_line_y = 0;
//			TconsProp_line_z = 1;
//			TmoveLineProp(-TconsProp_line_x, -TconsProp_line_y, -TconsProp_line_z);
//			renderWindow->Render();
//		}
//
//
//		if (this->InteractionProp == this->TConsProp_line_actor2)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 9002;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			TconsProp_line_x2 = 0;
//			TconsProp_line_y2 = 0;
//			TconsProp_line_z2 = 1;
//			TmoveLineProp2(-TconsProp_line_x2, -TconsProp_line_y2, -TconsProp_line_z2);
//			renderWindow->Render();
//		}
//
//		if (this->InteractionProp == this->TConsProp_line_actor3)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 9003;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			TconsProp_line_x3 = 0;
//			TconsProp_line_y3 = 0;
//			TconsProp_line_z3 = 1;
//			TmoveLineProp3(-TconsProp_line_x3, -TconsProp_line_y3, -TconsProp_line_z3);
//			renderWindow->Render();
//		}
//
//
//
//		if (this->InteractionProp == this->ConsProp_plane_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 93;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			consProp_plane_x = 0;
//			consProp_plane_y = 0;
//			consProp_plane_z = 1;
//			movePlaneProp(-consProp_plane_x, -consProp_plane_y, -consProp_plane_z);
//			renderWindow->Render();
//		}
//		if (this->InteractionProp == this->ConsProp_cube_actor)
//		{
//			ConstraintProp_sphere_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_line_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_plane_actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
//			ConstraintProp_cube_actor->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
//
//			PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//			Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//			RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//			RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//			LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//			boneID = 94;
//			/*this->Move = true;*/
//			axis_flag = 'z';
//			consProp_cube_x = 0;
//			consProp_cube_y = 0;
//			consProp_cube_z = 1;
//			moveCubeProp(-consProp_cube_x, -consProp_cube_y, -consProp_cube_z);
//			renderWindow->Render();
//		}
//
//	}
//	   
//public:
//	QVTKOpenGLNativeWidget *qvtkWidget;
//	vtkActor* RUA;
//	vtkActor* RLA;
//	vtkActor* LUA;
//	vtkActor* LLA;
//	vtkActor* RUL;
//	vtkActor* RLL;
//	vtkActor* LUL;
//	vtkActor* LLL;
//	vtkActor* chestActor;
//	vtkActor* headActor;
//	vtkActor* LH_Actor;
//	vtkActor* RH_Actor;
//	vtkActor* LL_Actor;
//	vtkActor* RL_Actor;
//	vtkActor* Upper_chestActor;
//	vtkActor* pelvisActor;
//
//	vtkActor *RF_xposActor;
//	vtkActor *RF_yposActor;
//	vtkActor *RF_zposActor;
//
//	vtkActor *RH_xposActor;
//	vtkActor *RH_yposActor;
//	vtkActor *RH_zposActor;
//
//	vtkActor *RLA_xrotActor;
//	vtkActor *RLA_yrotActor;
//	vtkActor *RLA_zrotActor;
//
//	vtkActor *RLL_xrotActor;
//	vtkActor *RLL_yrotActor;
//	vtkActor *RLL_zrotActor;
//
//	vtkActor* XAX;
//	vtkActor* YAX;
//	vtkActor* ZAX;
//
//	vtkActor* pJS;
//	vtkActor* cJS;
//
//	vtkActor* luaJS;
//	vtkActor* llaJS;
//
//	vtkActor* ruaJS;
//	vtkActor* rlaJS;
//
//	vtkActor* lulJS;
//	vtkActor* lllJS;
//
//	vtkActor* rulJS;
//	vtkActor* rllJS;
//
//	vtkActor* SM_pelvisActor; // 0
//	vtkActor* SM_CH0; // 1
//	vtkActor* SM_CH1; // 
//	vtkActor* SM_CH2; // 
//	vtkActor* SM_CH3; // 
//	vtkActor* SM_headActor; // 
//	vtkActor* SM_RUA; // 2
//	vtkActor* SM_RLA; // 3
//	vtkActor* SM_RH_Actor; // 10 and 109
//	vtkActor* SM_LUA; // 4
//	vtkActor* SM_LLA; // 5
//	vtkActor* SM_LH_Actor; // 15 and 112
//	vtkActor* SM_RUL; //6
//	vtkActor* SM_RLL; //7
//	vtkActor* SM_RF_Actor; // 16 and 115
//	vtkActor* SM_LUL; //8
//	vtkActor* SM_LLL; //9
//	vtkActor* SM_LF_Actor; // 21 and 118
//
//	vtkActor* ffIK_pelvisActor; // 500
//	vtkActor* ffIK_CH0; // 501
//	vtkActor* ffIK_CH1; //
//	vtkActor* ffIK_CH2; // 
//	vtkActor* ffIK_CH3; //
//	vtkActor* ffIK_headActor; // 
//	vtkActor* ffIK_RUA; // 502
//	vtkActor* ffIK_RLA; // 503
//	vtkActor* ffIK_RH; // 50 and 510
//	vtkActor* ffIK_LUA; // 504
//	vtkActor* ffIK_LLA; // 505
//	vtkActor* ffIK_LH; // 51 and 511
//	vtkActor* ffIK_RUL; // 506
//	vtkActor* ffIK_RLL; // 507
//	vtkActor* ffIK_RF_Actor; // 52 and 512
//	vtkActor* ffIK_LUL; // 508
//	vtkActor* ffIK_LLL; // 509
//	vtkActor* ffIK_LF_Actor; // 53 and 513
//
//
//	vtkActor* freeRightUL_Actor; // 2001
//	vtkActor* freeRightLL_Actor; // 2002
//	vtkActor* freeRightFoot_Actor; // 2003
//
//	vtkActor* freeLeftUL_Actor; // 1001
//	vtkActor* freeLeftLL_Actor; // 1002
//	vtkActor* freeLeftFoot_Actor; // 1003
//
//	vtkActor *ConsProp_sphere_actor; //91
//	vtkActor *TConsProp_sphere_actor; //9100
//	vtkActor *TConsProp_sphere_actor2; //9200
//	vtkActor *TConsProp_sphere_actor3; //9300
//	vtkActor *ConsProp_line_actor; //92
//	vtkActor *TConsProp_line_actor; //9001
//	vtkActor *TConsProp_line_actor2; //9002
//	vtkActor *TConsProp_line_actor3; //9003
//
//	vtkActor *ConsProp_plane_actor; //93
//	vtkActor *ConsProp_cube_actor; //94
//
//
//	   	  
//	int state = 0;
//	bool Move = false;
//	bool press = true;
//
//	int screenX, screenY;
//	int screenDiff, screenTemp, screenPrev;
//
//	   
//private:
//	unsigned int NumberOfClicks;
//	int PreviousPosition[2];
//	int ResetPixelDistance;
//
//};
//vtkStandardNewMacro(MouseInteractorStyle5);
//
//void EventQtSlotConnect::kf_caputre()
//{
//	
//	cout << endl << "==============================" << endl;
//	cout << "Key Frame:" << captureCount << " " << "captured" << endl;
//	cout << "==============================" << endl;
//
//	/*cout << "=======================================" << endl;
//	cout << "xQuat Values:" << "W=" << xaxisQP[0].getW() << "\t" << "X=" << xaxisQP[0].getX() << "\t" << "Y=" << xaxisQP[0].getY() << "\t" << "Z=" << xaxisQP[0].getZ() << endl;
//	cout << "yQuat Values:" << "W=" << yaxisQP[0].getW() << "\t" << "X=" << yaxisQP[0].getX() << "\t" << "Y=" << yaxisQP[0].getY() << "\t" << "Z=" << yaxisQP[0].getZ() << endl;
//	cout << "zQuat Values:" << "W=" << zaxisQP[0].getW() << "\t" << "X=" << zaxisQP[0].getX() << "\t" << "Y=" << zaxisQP[0].getY() << "\t" << "Z=" << zaxisQP[0].getZ() << endl;
//	cout << "=======================================" << endl;*/
//
//	/*cout << "=======================================" << endl;
//	for (int i = 0; i <= 10; i++)
//	{
//
//		cout << "boneID =" << i << endl;
//		cout << "xQuat Values:" << "W=" << xaxisQP[i].getW() << "\t" << "X=" << xaxisQP[i].getX() << "\t" << "Y=" << xaxisQP[i].getY() << "\t" << "Z=" << xaxisQP[i].getZ() << endl;
//		cout << "yQuat Values:" << "W=" << yaxisQP[i].getW() << "\t" << "X=" << yaxisQP[i].getX() << "\t" << "Y=" << yaxisQP[i].getY() << "\t" << "Z=" << yaxisQP[i].getZ() << endl;
//		cout << "zQuat Values:" << "W=" << zaxisQP[i].getW() << "\t" << "X=" << zaxisQP[i].getX() << "\t" << "Y=" << zaxisQP[i].getY() << "\t" << "Z=" << zaxisQP[i].getZ() << endl;
//	}
//	cout << "=======================================" << endl;*/
//	  
//	for (int i = 0; i <= 10; i++)
//	{
//		qsf[i] = zaxisQP[i].multiply(yaxisQP[i].multiply(xaxisQP[i]));
//	}
//
//	for (int i = 0; i <= 10; i++)
//	{
//		
//		//cout << "boneID =" << i << endl;
//		//cout << "Quat Values:" << "W=" << qsf[i].getW() << "\t" "X=" << qsf[i].getX() << "\t" "Y=" << qsf[i].getY() << "\t" "Z=" << qsf[i].getZ() << endl;
//
//		if (i == 0)
//		{
//			slerp_pelvis_kf[captureCount].setW(qsf[i].getW());
//			slerp_pelvis_kf[captureCount].setX(qsf[i].getX());
//			slerp_pelvis_kf[captureCount].setY(qsf[i].getY());
//			slerp_pelvis_kf[captureCount].setZ(qsf[i].getZ());
//		}
//		if (i == 1)
//		{
//			slerp_chest_kf[captureCount].setW(qsf[i].getW());
//			slerp_chest_kf[captureCount].setX(qsf[i].getX());
//			slerp_chest_kf[captureCount].setY(qsf[i].getY());
//			slerp_chest_kf[captureCount].setZ(qsf[i].getZ());
//		}
//		if (i == 2)
//		{
//			slerp_rua_kf[captureCount].setW(qsf[i].getW());
//			slerp_rua_kf[captureCount].setX(qsf[i].getX());
//			slerp_rua_kf[captureCount].setY(qsf[i].getY());
//			slerp_rua_kf[captureCount].setZ(qsf[i].getZ());
//		}
//		if (i == 3)
//		{
//			slerp_rla_kf[captureCount].setW(qsf[i].getW());
//			slerp_rla_kf[captureCount].setX(qsf[i].getX());
//			slerp_rla_kf[captureCount].setY(qsf[i].getY());
//			slerp_rla_kf[captureCount].setZ(qsf[i].getZ());
//		}
//		if (i == 4)
//		{
//			slerp_lua_kf[captureCount].setW(qsf[i].getW());
//			slerp_lua_kf[captureCount].setX(qsf[i].getX());
//			slerp_lua_kf[captureCount].setY(qsf[i].getY());
//			slerp_lua_kf[captureCount].setZ(qsf[i].getZ());
//		}
//		if (i == 5)
//		{
//			slerp_lla_kf[captureCount].setW(qsf[i].getW());
//			slerp_lla_kf[captureCount].setX(qsf[i].getX());
//			slerp_lla_kf[captureCount].setY(qsf[i].getY());
//			slerp_lla_kf[captureCount].setZ(qsf[i].getZ());
//		}
//		if (i == 6)
//		{
//
//			slerp_rul_kf[captureCount].setW(qsf[i].getW());
//			slerp_rul_kf[captureCount].setX(qsf[i].getX());
//			slerp_rul_kf[captureCount].setY(qsf[i].getY());
//			slerp_rul_kf[captureCount].setZ(qsf[i].getZ());
//		}
//		if (i == 7)
//		{
//
//			slerp_rll_kf[captureCount].setW(qsf[i].getW());
//			slerp_rll_kf[captureCount].setX(qsf[i].getX());
//			slerp_rll_kf[captureCount].setY(qsf[i].getY());
//			slerp_rll_kf[captureCount].setZ(qsf[i].getZ());
//		}
//		if (i == 8)
//		{
//			slerp_lul_kf[captureCount].setW(qsf[i].getW());
//			slerp_lul_kf[captureCount].setX(qsf[i].getX());
//			slerp_lul_kf[captureCount].setY(qsf[i].getY());
//			slerp_lul_kf[captureCount].setZ(qsf[i].getZ());
//		}
//		if (i == 9)
//		{
//			slerp_lll_kf[captureCount].setW(qsf[i].getW());
//			slerp_lll_kf[captureCount].setX(qsf[i].getX());
//			slerp_lll_kf[captureCount].setY(qsf[i].getY());
//			slerp_lll_kf[captureCount].setZ(qsf[i].getZ());
//		}
//			  			
//	}
//
//	// For Inverse Kinematics Quaternions
//	for (int i = 0; i <= 10; i++)
//	{
//		qsfIK[i] = zaxisQP_IK[i].multiply(yaxisQP_IK[i].multiply(xaxisQP_IK[i]));
//	}
//	for (int i = 0; i <= 10; i++)
//	{
//		//cout << "boneID_IK =" << i << endl;
//		//cout << "Quat Values:" << "W=" << qsfIK[i].getW() << "\t" "X=" << qsfIK[i].getX() << "\t" "Y=" << qsfIK[i].getY() << "\t" "Z=" << qsfIK[i].getZ() << endl;
//
//		if (i == 1)
//		{
//			if (ffIK_both == 1 || ffIK_RF ==1 || ffIK_LF==1)
//			{
//				slerpIK_chest_kf[captureCount].setW(qsfIK[i].getW());
//				slerpIK_chest_kf[captureCount].setX(qsfIK[i].getX());
//				slerpIK_chest_kf[captureCount].setY(qsfIK[i].getY());
//				slerpIK_chest_kf[captureCount].setZ(qsfIK[i].getZ());
//			}
//			else
//			{
//				slerpIK_chest_kf[captureCount].setW(qsf[i].getW());
//				slerpIK_chest_kf[captureCount].setX(qsf[i].getX());
//				slerpIK_chest_kf[captureCount].setY(qsf[i].getY());
//				slerpIK_chest_kf[captureCount].setZ(qsf[i].getZ());
//			}
//			
//
//	
//		}
//		if (i == 2)
//		{
//			slerpIK_rua_kf[captureCount].setW(qsfIK[i].getW());
//			slerpIK_rua_kf[captureCount].setX(qsfIK[i].getX());
//			slerpIK_rua_kf[captureCount].setY(qsfIK[i].getY());
//			slerpIK_rua_kf[captureCount].setZ(qsfIK[i].getZ());
//		}
//		if (i == 3)
//		{
//			slerpIK_rla_kf[captureCount].setW(qsfIK[i].getW());
//			slerpIK_rla_kf[captureCount].setX(qsfIK[i].getX());
//			slerpIK_rla_kf[captureCount].setY(qsfIK[i].getY());
//			slerpIK_rla_kf[captureCount].setZ(qsfIK[i].getZ());
//		}
//		if (i == 4)
//		{
//			slerpIK_lua_kf[captureCount].setW(qsfIK[i].getW());
//			slerpIK_lua_kf[captureCount].setX(qsfIK[i].getX());
//			slerpIK_lua_kf[captureCount].setY(qsfIK[i].getY());
//			slerpIK_lua_kf[captureCount].setZ(qsfIK[i].getZ());
//		}
//		if (i == 5)
//		{
//			slerpIK_lla_kf[captureCount].setW(qsfIK[i].getW());
//			slerpIK_lla_kf[captureCount].setX(qsfIK[i].getX());
//			slerpIK_lla_kf[captureCount].setY(qsfIK[i].getY());
//			slerpIK_lla_kf[captureCount].setZ(qsfIK[i].getZ());
//		}
//		if (i == 6)
//		{
//			slerpIK_rul_kf[captureCount].setW(qsfIK[i].getW());
//			slerpIK_rul_kf[captureCount].setX(qsfIK[i].getX());
//			slerpIK_rul_kf[captureCount].setY(qsfIK[i].getY());
//			slerpIK_rul_kf[captureCount].setZ(qsfIK[i].getZ());
//		}
//		if (i == 7)
//		{
//			slerpIK_rll_kf[captureCount].setW(qsfIK[i].getW());
//			slerpIK_rll_kf[captureCount].setX(qsfIK[i].getX());
//			slerpIK_rll_kf[captureCount].setY(qsfIK[i].getY());
//			slerpIK_rll_kf[captureCount].setZ(qsfIK[i].getZ());
//		}
//		if (i == 8)
//		{
//			slerpIK_lul_kf[captureCount].setW(qsfIK[i].getW());
//			slerpIK_lul_kf[captureCount].setX(qsfIK[i].getX());
//			slerpIK_lul_kf[captureCount].setY(qsfIK[i].getY());
//			slerpIK_lul_kf[captureCount].setZ(qsfIK[i].getZ());
//		}
//		if (i == 9)
//		{
//			slerpIK_lll_kf[captureCount].setW(qsfIK[i].getW());
//			slerpIK_lll_kf[captureCount].setX(qsfIK[i].getX());
//			slerpIK_lll_kf[captureCount].setY(qsfIK[i].getY());
//			slerpIK_lll_kf[captureCount].setZ(qsfIK[i].getZ());
//		}
//	}
//
//
//
//	captureCount++;
//	this->KF_lcdNumber->display(captureCount);
//}
//void EventQtSlotConnect::allKF_Slerping() 
//{
//	// FK - Forward Kinematics 
//	if (IKflag_Status==0)
//	{
//		cout << " Number of Keyframes Captured:" << captureCount << endl;
//
//		Total_noOfFrames = (captureCount - 1) * Total_noOfFrames;
//		int dummyInc = 0;
//		all_KFs_file.open("fullBody_sfqData.txt");
//		all_KFs_file << "FULLBODY" << "\t" << "1" << endl;
//		all_KFs_file << "Frames:" << "\t" << Total_noOfFrames << endl;
//		for (int i = 0; i < captureCount - 1; i++)
//		{
//
//			for (int j = 0; j < noOfFrames_betweenKF; j++)
//			{
//				pelvisFrames[j] = pelvisFrames[j].SLERP(slerp_pelvis_kf[dummyInc], slerp_pelvis_kf[dummyInc + 1], slerpT);
//				chestFrames[j] = chestFrames[j].SLERP(slerp_chest_kf[dummyInc], slerp_chest_kf[dummyInc + 1], slerpT);
//
//				ruaFrames[j] = temp_ruaFrames[j].SLERP(slerp_rua_kf[dummyInc], slerp_rua_kf[dummyInc + 1], slerpT);
//				rlaFrames[j] = temp_rlaFrames[j].SLERP(slerp_rla_kf[dummyInc], slerp_rla_kf[dummyInc + 1], slerpT);
//				luaFrames[j] = temp_luaFrames[j].SLERP(slerp_lua_kf[dummyInc], slerp_lua_kf[dummyInc + 1], slerpT);
//				llaFrames[j] = temp_llaFrames[j].SLERP(slerp_lla_kf[dummyInc], slerp_lla_kf[dummyInc + 1], slerpT);
//
//				rulFrames[j] = temp_rulFrames[j].SLERP(slerp_rul_kf[dummyInc], slerp_rul_kf[dummyInc + 1], slerpT);
//				rllFrames[j] = temp_rllFrames[j].SLERP(slerp_rll_kf[dummyInc], slerp_rll_kf[dummyInc + 1], slerpT);
//				lulFrames[j] = temp_lulFrames[j].SLERP(slerp_lul_kf[dummyInc], slerp_lul_kf[dummyInc + 1], slerpT);
//				lllFrames[j] = temp_lllFrames[j].SLERP(slerp_lll_kf[dummyInc], slerp_lll_kf[dummyInc + 1], slerpT);
//
//				slerpT += slerpTT;
//			}
//
//			if (isnan((pelvisFrames[0].getW())) || isnan((pelvisFrames[0].getX())) || isnan((pelvisFrames[0].getY())) || isnan((pelvisFrames[0].getZ())))
//			{
//				for (int n = 0; n < noOfFrames_betweenKF; n++)
//				{
//					pelvisFrames[n].setW(1);
//					pelvisFrames[n].setX(0);
//					pelvisFrames[n].setY(0);
//					pelvisFrames[n].setZ(0);
//				}
//			}
//			if (isnan((chestFrames[0].getW())) || isnan((chestFrames[0].getX())) || isnan((chestFrames[0].getY())) || isnan((chestFrames[0].getZ())))
//			{
//				for (int n = 0; n < noOfFrames_betweenKF; n++)
//				{
//					chestFrames[n].setW(1);
//					chestFrames[n].setX(0);
//					chestFrames[n].setY(0);
//					chestFrames[n].setZ(0);
//				}
//			}
//
//			if (isnan((ruaFrames[0].getW())) || isnan((ruaFrames[0].getX())) || isnan((ruaFrames[0].getY())) || isnan((ruaFrames[0].getZ())))
//			{
//				for (int m = 0; m < noOfFrames_betweenKF; m++)
//				{
//					ruaFrames[m].setW(1);
//					ruaFrames[m].setX(0);
//					ruaFrames[m].setY(0);
//					ruaFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((rlaFrames[0].getW())) || isnan((rlaFrames[0].getX())) || isnan((rlaFrames[0].getY())) || isnan((rlaFrames[0].getZ())))
//			{
//				for (int m = 0; m < noOfFrames_betweenKF; m++)
//				{
//					rlaFrames[m].setW(1);
//					rlaFrames[m].setX(0);
//					rlaFrames[m].setY(0);
//					rlaFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((luaFrames[0].getW())) || isnan((luaFrames[0].getX())) || isnan((luaFrames[0].getY())) || isnan((luaFrames[0].getZ())))
//			{
//				for (int m = 0; m < noOfFrames_betweenKF; m++)
//				{
//					luaFrames[m].setW(1);
//					luaFrames[m].setX(0);
//					luaFrames[m].setY(0);
//					luaFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((llaFrames[0].getW())) || isnan((llaFrames[0].getX())) || isnan((llaFrames[0].getY())) || isnan((llaFrames[0].getZ())))
//			{
//				for (int m = 0; m < noOfFrames_betweenKF; m++)
//				{
//					llaFrames[m].setW(1);
//					llaFrames[m].setX(0);
//					llaFrames[m].setY(0);
//					llaFrames[m].setZ(0);
//
//
//				}
//			}
//
//			if (isnan((rulFrames[0].getW())) || isnan((rulFrames[0].getX())) || isnan((rulFrames[0].getY())) || isnan((rulFrames[0].getZ())))
//			{
//				for (int m = 0; m < noOfFrames_betweenKF; m++)
//				{
//					rulFrames[m].setW(1);
//					rulFrames[m].setX(0);
//					rulFrames[m].setY(0);
//					rulFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((rllFrames[0].getW())) || isnan((rllFrames[0].getX())) || isnan((rllFrames[0].getY())) || isnan((rllFrames[0].getZ())))
//			{
//				for (int m = 0; m < noOfFrames_betweenKF; m++)
//				{
//					rllFrames[m].setW(1);
//					rllFrames[m].setX(0);
//					rllFrames[m].setY(0);
//					rllFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((lulFrames[0].getW())) || isnan((lulFrames[0].getX())) || isnan((lulFrames[0].getY())) || isnan((lulFrames[0].getZ())))
//			{
//				for (int m = 0; m < noOfFrames_betweenKF; m++)
//				{
//					lulFrames[m].setW(1);
//					lulFrames[m].setX(0);
//					lulFrames[m].setY(0);
//					lulFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((lllFrames[0].getW())) || isnan((lllFrames[0].getX())) || isnan((lllFrames[0].getY())) || isnan((lllFrames[0].getZ())))
//			{
//				for (int m = 0; m < noOfFrames_betweenKF; m++)
//				{
//					lllFrames[m].setW(1);
//					lllFrames[m].setX(0);
//					lllFrames[m].setY(0);
//					lllFrames[m].setZ(0);
//
//
//				}
//			}
//
//			for (int k = 0; k < noOfFrames_betweenKF; k++)
//			{
//				all_KFs_file << pelvisFrames[k].getW() << "\t" << -pelvisFrames[k].getX() << "\t" << pelvisFrames[k].getZ() << "\t" << pelvisFrames[k].getY() << "\t"
//					<< chestFrames[k].getW() << "\t" << -chestFrames[k].getX() << "\t" << chestFrames[k].getZ() << "\t" << chestFrames[k].getY() << "\t"
//					<< ruaFrames[k].getW() << "\t" << -ruaFrames[k].getX() << "\t" << ruaFrames[k].getZ() << "\t" << ruaFrames[k].getY() << "\t"
//					<< rlaFrames[k].getW() << "\t" << -rlaFrames[k].getX() << "\t" << rlaFrames[k].getZ() << "\t" << rlaFrames[k].getY() << "\t"
//					<< luaFrames[k].getW() << "\t" << -luaFrames[k].getX() << "\t" << luaFrames[k].getZ() << "\t" << luaFrames[k].getY() << "\t"
//					<< llaFrames[k].getW() << "\t" << -llaFrames[k].getX() << "\t" << llaFrames[k].getZ() << "\t" << llaFrames[k].getY() << "\t"
//					<< rulFrames[k].getW() << "\t" << -rulFrames[k].getX() << "\t" << rulFrames[k].getZ() << "\t" << rulFrames[k].getY() << "\t"
//					<< rllFrames[k].getW() << "\t" << -rllFrames[k].getX() << "\t" << rllFrames[k].getZ() << "\t" << rllFrames[k].getY() << "\t"
//					<< lulFrames[k].getW() << "\t" << -lulFrames[k].getX() << "\t" << lulFrames[k].getZ() << "\t" << lulFrames[k].getY() << "\t"
//					<< lllFrames[k].getW() << "\t" << -lllFrames[k].getX() << "\t" << lllFrames[k].getZ() << "\t" << lllFrames[k].getY() << "\n";
//			}
//			slerpT = 0;
//			dummyInc++;
//		}
//		all_KFs_file.close();
//
//		authorMode = true;
//		fileMode = false;
//		Quatnode_rcm.nodecreate();
//		Quatnode_rcm.loadQuaternion("fullBody_sfqData.txt");
//		Quatnode_rcm.rotateaxis();
//		//Quatnode_rcm.quattoeuler();
//		Quatnode_rcm.quattoaxisangle();
//		Quatnode_rcm.quattoHeight();
//	
//
//		// For JointSphere Trajectories Data
//		Quatnode_rcm.Calpts();
//
//
//		current_frames_rcm = Quatnode_rcm.frames;
//		loadframes_rcm = Quatnode_rcm.frames;
//
//	
//
//
//	}
//	
//
//	// IK - Inverse Kinematics 
//	if (IKflag_Status==1)
//	{
//		//========================== For Inverse Kinematics KeyFrames Slerping=====================================================================================================
//		cout << " Number of Inverse Kinematics (IK) Keyframes Captured:" << captureCount << endl;
//		IK_Total_noOfFrames = (captureCount - 1) * IK_Total_noOfFrames;
//		int IKdummyInc = 0;
//		all_IK_KFs_file.open("fullBody_IKData.txt");
//		all_IK_KFs_file << "FULLBODY" << "\t" << "1" << endl;
//		all_IK_KFs_file << "Frames:" << "\t" << IK_Total_noOfFrames << endl;
//		for (int i = 0; i < captureCount - 1; i++)
//		{
//			for (int j = 0; j < IK_noOfFrames_betweenKF; j++)
//			{
//				IK_pelvisFrames[j] = IK_pelvisFrames[j].SLERP(slerpIK_pelvis_kf[IKdummyInc], slerpIK_pelvis_kf[IKdummyInc + 1], IK_slerpT);
//				IK_chestFrames[j] = IK_chestFrames[j].SLERP(slerpIK_chest_kf[IKdummyInc], slerpIK_chest_kf[IKdummyInc + 1], IK_slerpT);
//				IK_ruaFrames[j] = IK_temp_ruaFrames[j].SLERP(slerpIK_rua_kf[IKdummyInc], slerpIK_rua_kf[IKdummyInc + 1], IK_slerpT);
//				IK_rlaFrames[j] = IK_temp_rlaFrames[j].SLERP(slerpIK_rla_kf[IKdummyInc], slerpIK_rla_kf[IKdummyInc + 1], IK_slerpT);
//				IK_luaFrames[j] = IK_temp_luaFrames[j].SLERP(slerpIK_lua_kf[IKdummyInc], slerpIK_lua_kf[IKdummyInc + 1], IK_slerpT);
//				IK_llaFrames[j] = IK_temp_llaFrames[j].SLERP(slerpIK_lla_kf[IKdummyInc], slerpIK_lla_kf[IKdummyInc + 1], IK_slerpT);
//				IK_rulFrames[j] = IK_temp_rulFrames[j].SLERP(slerpIK_rul_kf[IKdummyInc], slerpIK_rul_kf[IKdummyInc + 1], IK_slerpT);
//				IK_rllFrames[j] = IK_temp_rllFrames[j].SLERP(slerpIK_rll_kf[IKdummyInc], slerpIK_rll_kf[IKdummyInc + 1], IK_slerpT);
//				IK_lulFrames[j] = IK_temp_lulFrames[j].SLERP(slerpIK_lul_kf[IKdummyInc], slerpIK_lul_kf[IKdummyInc + 1], IK_slerpT);
//				IK_lllFrames[j] = IK_temp_lllFrames[j].SLERP(slerpIK_lll_kf[IKdummyInc], slerpIK_lll_kf[IKdummyInc + 1], IK_slerpT);
//
//				IK_slerpT += IK_slerpTT;
//			}
//			if (isnan((IK_pelvisFrames[0].getW())) || isnan((IK_pelvisFrames[0].getX())) || isnan((IK_pelvisFrames[0].getY())) || isnan((IK_pelvisFrames[0].getZ())))
//			{
//				for (int n = 0; n < IK_noOfFrames_betweenKF; n++)
//				{
//					IK_pelvisFrames[n].setW(1);
//					IK_pelvisFrames[n].setX(0);
//					IK_pelvisFrames[n].setY(0);
//					IK_pelvisFrames[n].setZ(0);
//				}
//			}
//			if (isnan((IK_chestFrames[0].getW())) || isnan((IK_chestFrames[0].getX())) || isnan((IK_chestFrames[0].getY())) || isnan((IK_chestFrames[0].getZ())))
//			{
//				for (int n = 0; n < IK_noOfFrames_betweenKF; n++)
//				{
//					IK_chestFrames[n].setW(1);
//					IK_chestFrames[n].setX(0);
//					IK_chestFrames[n].setY(0);
//					IK_chestFrames[n].setZ(0);
//				}
//			}
//
//			if (isnan((IK_ruaFrames[0].getW())) || isnan((IK_ruaFrames[0].getX())) || isnan((IK_ruaFrames[0].getY())) || isnan((IK_ruaFrames[0].getZ())))
//			{
//				for (int m = 0; m < IK_noOfFrames_betweenKF; m++)
//				{
//					IK_ruaFrames[m].setW(1);
//					IK_ruaFrames[m].setX(0);
//					IK_ruaFrames[m].setY(0);
//					IK_ruaFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((IK_rlaFrames[0].getW())) || isnan((IK_rlaFrames[0].getX())) || isnan((IK_rlaFrames[0].getY())) || isnan((IK_rlaFrames[0].getZ())))
//			{
//				for (int m = 0; m < noOfFrames_betweenKF; m++)
//				{
//					IK_rlaFrames[m].setW(1);
//					IK_rlaFrames[m].setX(0);
//					IK_rlaFrames[m].setY(0);
//					IK_rlaFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((IK_luaFrames[0].getW())) || isnan((IK_luaFrames[0].getX())) || isnan((IK_luaFrames[0].getY())) || isnan((IK_luaFrames[0].getZ())))
//			{
//				for (int m = 0; m < IK_noOfFrames_betweenKF; m++)
//				{
//					IK_luaFrames[m].setW(1);
//					IK_luaFrames[m].setX(0);
//					IK_luaFrames[m].setY(0);
//					IK_luaFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((IK_llaFrames[0].getW())) || isnan((IK_llaFrames[0].getX())) || isnan((IK_llaFrames[0].getY())) || isnan((IK_llaFrames[0].getZ())))
//			{
//				for (int m = 0; m < IK_noOfFrames_betweenKF; m++)
//				{
//					IK_llaFrames[m].setW(1);
//					IK_llaFrames[m].setX(0);
//					IK_llaFrames[m].setY(0);
//					IK_llaFrames[m].setZ(0);
//
//
//				}
//			}
//
//			if (isnan((IK_rulFrames[0].getW())) || isnan((IK_rulFrames[0].getX())) || isnan((IK_rulFrames[0].getY())) || isnan((IK_rulFrames[0].getZ())))
//			{
//				for (int m = 0; m < IK_noOfFrames_betweenKF; m++)
//				{
//					IK_rulFrames[m].setW(1);
//					IK_rulFrames[m].setX(0);
//					IK_rulFrames[m].setY(0);
//					IK_rulFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((IK_rllFrames[0].getW())) || isnan((IK_rllFrames[0].getX())) || isnan((IK_rllFrames[0].getY())) || isnan((IK_rllFrames[0].getZ())))
//			{
//				for (int m = 0; m < IK_noOfFrames_betweenKF; m++)
//				{
//					IK_rllFrames[m].setW(1);
//					IK_rllFrames[m].setX(0);
//					IK_rllFrames[m].setY(0);
//					IK_rllFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((IK_lulFrames[0].getW())) || isnan((IK_lulFrames[0].getX())) || isnan((IK_lulFrames[0].getY())) || isnan((IK_lulFrames[0].getZ())))
//			{
//				for (int m = 0; m < IK_noOfFrames_betweenKF; m++)
//				{
//					IK_lulFrames[m].setW(1);
//					IK_lulFrames[m].setX(0);
//					IK_lulFrames[m].setY(0);
//					IK_lulFrames[m].setZ(0);
//
//
//				}
//			}
//			if (isnan((IK_lllFrames[0].getW())) || isnan((IK_lllFrames[0].getX())) || isnan((IK_lllFrames[0].getY())) || isnan((IK_lllFrames[0].getZ())))
//			{
//				for (int m = 0; m < IK_noOfFrames_betweenKF; m++)
//				{
//					IK_lllFrames[m].setW(1);
//					IK_lllFrames[m].setX(0);
//					IK_lllFrames[m].setY(0);
//					IK_lllFrames[m].setZ(0);
//
//
//				}
//			}
//
//
//			for (int k = 0; k < IK_noOfFrames_betweenKF; k++)
//			{
//				all_IK_KFs_file << IK_pelvisFrames[k].getW() << "\t" << IK_pelvisFrames[k].getX() << "\t" << IK_pelvisFrames[k].getZ() << "\t" << IK_pelvisFrames[k].getY() << "\t"
//					<< IK_chestFrames[k].getW() << "\t" << -IK_chestFrames[k].getX() << "\t" << IK_chestFrames[k].getZ() << "\t" << IK_chestFrames[k].getY() << "\t"
//					<< IK_ruaFrames[k].getW() << "\t" << -IK_ruaFrames[k].getX() << "\t" << IK_ruaFrames[k].getZ() << "\t" << IK_ruaFrames[k].getY() << "\t"
//					<< IK_rlaFrames[k].getW() << "\t" << -IK_rlaFrames[k].getX() << "\t" << IK_rlaFrames[k].getZ() << "\t" << IK_rlaFrames[k].getY() << "\t"
//					<< IK_luaFrames[k].getW() << "\t" << -IK_luaFrames[k].getX() << "\t" << IK_luaFrames[k].getZ() << "\t" << IK_luaFrames[k].getY() << "\t"
//					<< IK_llaFrames[k].getW() << "\t" << -IK_llaFrames[k].getX() << "\t" << IK_llaFrames[k].getZ() << "\t" << IK_llaFrames[k].getY() << "\t"
//					<< IK_rulFrames[k].getW() << "\t" << -IK_rulFrames[k].getX() << "\t" << IK_rulFrames[k].getZ() << "\t" << IK_rulFrames[k].getY() << "\t"
//					<< IK_rllFrames[k].getW() << "\t" << -IK_rllFrames[k].getX() << "\t" << IK_rllFrames[k].getZ() << "\t" << IK_rllFrames[k].getY() << "\t"
//					<< IK_lulFrames[k].getW() << "\t" << -IK_lulFrames[k].getX() << "\t" << IK_lulFrames[k].getZ() << "\t" << IK_lulFrames[k].getY() << "\t"
//					<< IK_lllFrames[k].getW() << "\t" << -IK_lllFrames[k].getX() << "\t" << IK_lllFrames[k].getZ() << "\t" << IK_lllFrames[k].getY() << "\n";
//			}
//
//			IK_slerpT = 0;
//			IKdummyInc++;
//		}
//		all_IK_KFs_file.close();
//
//		authorMode = true;
//		fileMode = false;
//		Quatnode_rcm.nodecreate();
//		Quatnode_rcm.loadQuaternion("fullBody_IKData.txt");
//		Quatnode_rcm.rotateaxis();
//		//Quatnode_rcm.quattoeuler();
//		Quatnode_rcm.quattoaxisangle();
//		Quatnode_rcm.quattoHeight();
//
//		// For JointSphere Trajectories Data
//		Quatnode_rcm.Calpts();
//
//		current_frames_rcm = Quatnode_rcm.frames;
//		loadframes_rcm = Quatnode_rcm.frames;
//	}
//
//
//	
//
//}
//
//void EventQtSlotConnect::timerFunction()
//{
//	
//	timerCount++;
//	if (keyframes_Slider->value() + 1 > keyframes_Slider->maximum())
//		keyframes_Slider->setValue(keyframes_Slider->minimum());
//	else
//		keyframes_Slider->setValue(keyframes_Slider->value() + 1);
//
//}
//void EventQtSlotConnect::allKeyFrames_playPause()
//{
//	if (!playPause)
//	{
//		timer->start(1);
//		play_Button->setStyleSheet("background-color:darkGreen;");
//
//	}
//	else
//	{
//		timer->stop();
//		play_Button->setStyleSheet("background-color:darkRed;");
//	}
//	playPause = !playPause;
//	
//}
//void EventQtSlotConnect::allkeyFrames_sliderMove(int a)
//{
//		
//		cout << a << endl;
//			   	
//		if (authorMode)
//		{
//			if (a < loadframes_rcm)
//			{
//			
//					if (male_biped)
//					{
//						//Lower Chest
//						transform_rcm[1] = CUconeTransform;
//						transform_rcm[1]->Identity();
//						transform_rcm[1]->Translate(chestObj_xpos, chestObj_ypos, chestObj_zpos);
//						transform_rcm[1]->RotateWXYZ(Quatnode_rcm.nodelist[1]->axisangle[a][0], Quatnode_rcm.nodelist[1]->axisangle[a][1], Quatnode_rcm.nodelist[1]->axisangle[a][2], Quatnode_rcm.nodelist[1]->axisangle[a][3]);
//
//						// Right Upper arm
//						transform_rcm[2] = RarmTransform;
//						transform_rcm[2]->Identity();
//						transform_rcm[2]->Translate(ruaObj_xpos, ruaObj_ypos, ruaObj_zpos);
//						transform_rcm[2]->RotateWXYZ(Quatnode_rcm.nodelist[2]->axisangle[a][0], Quatnode_rcm.nodelist[2]->axisangle[a][1], Quatnode_rcm.nodelist[2]->axisangle[a][2], Quatnode_rcm.nodelist[2]->axisangle[a][3]);
//
//						// Right Lower arm
//						transform_rcm[3] = RforearmTransform;
//						transform_rcm[3]->Identity();
//						transform_rcm[3]->Translate(rlaObj_xpos, rlaObj_ypos, rlaObj_zpos);
//						transform_rcm[3]->RotateWXYZ(Quatnode_rcm.nodelist[3]->axisangle[a][0], Quatnode_rcm.nodelist[3]->axisangle[a][1], Quatnode_rcm.nodelist[3]->axisangle[a][2], Quatnode_rcm.nodelist[3]->axisangle[a][3]);
//
//						// Left Upper arm
//						transform_rcm[4] = LarmTransform;
//						transform_rcm[4]->Identity();
//						transform_rcm[4]->Translate(luaObj_xpos, luaObj_ypos, luaObj_zpos);
//						transform_rcm[4]->RotateWXYZ(Quatnode_rcm.nodelist[4]->axisangle[a][0], Quatnode_rcm.nodelist[4]->axisangle[a][1], Quatnode_rcm.nodelist[4]->axisangle[a][2], Quatnode_rcm.nodelist[4]->axisangle[a][3]);
//
//						// Left Lower arm
//						transform_rcm[5] = LforearmTransform;
//						transform_rcm[5]->Identity();
//						transform_rcm[5]->Translate(llaObj_xpos, llaObj_ypos, llaObj_zpos);
//						transform_rcm[5]->RotateWXYZ(Quatnode_rcm.nodelist[5]->axisangle[a][0], Quatnode_rcm.nodelist[5]->axisangle[a][1], Quatnode_rcm.nodelist[5]->axisangle[a][2], Quatnode_rcm.nodelist[5]->axisangle[a][3]);
//
//						// Right Upper leg
//						transform_rcm[6] = RlulegTransform;
//						transform_rcm[6]->Identity();
//						transform_rcm[6]->Translate(rulObj_xpos, rulObj_ypos, rulObj_zpos);
//						transform_rcm[6]->RotateWXYZ(Quatnode_rcm.nodelist[6]->axisangle[a][0], Quatnode_rcm.nodelist[6]->axisangle[a][1], Quatnode_rcm.nodelist[6]->axisangle[a][2], Quatnode_rcm.nodelist[6]->axisangle[a][3]);
//
//						// Right Lower leg
//						transform_rcm[7] = RllegTransform;
//						transform_rcm[7]->Identity();
//						transform_rcm[7]->Translate(rllObj_xpos, rllObj_ypos, rllObj_zpos);
//						transform_rcm[7]->RotateWXYZ(Quatnode_rcm.nodelist[7]->axisangle[a][0], Quatnode_rcm.nodelist[7]->axisangle[a][1], Quatnode_rcm.nodelist[7]->axisangle[a][2], Quatnode_rcm.nodelist[7]->axisangle[a][3]);
//
//						//  Left Upper leg
//						transform_rcm[8] = LlulegTransform;
//						transform_rcm[8]->Identity();
//						transform_rcm[8]->Translate(lulObj_xpos, lulObj_ypos, lulObj_zpos);
//						transform_rcm[8]->RotateWXYZ(Quatnode_rcm.nodelist[8]->axisangle[a][0], Quatnode_rcm.nodelist[8]->axisangle[a][1], Quatnode_rcm.nodelist[8]->axisangle[a][2], Quatnode_rcm.nodelist[8]->axisangle[a][3]);
//
//						// Left Lower leg
//						transform_rcm[9] = LllegTransform;
//						transform_rcm[9]->Identity();
//						transform_rcm[9]->Translate(lllObj_xpos, lllObj_ypos, lllObj_zpos);
//						transform_rcm[9]->RotateWXYZ(Quatnode_rcm.nodelist[9]->axisangle[a][0], Quatnode_rcm.nodelist[9]->axisangle[a][1], Quatnode_rcm.nodelist[9]->axisangle[a][2], Quatnode_rcm.nodelist[9]->axisangle[a][3]);
//					}
//					if (skeleton_biped)
//					{
//						if (ffIK_both == 1)
//						{
//							//Lower Chest
//							transform_rcm[1] = IK_chest_0_Transform;
//							transform_rcm[1]->Identity();
//							transform_rcm[1]->Translate(ffIK_CH0_x, ffIK_CH0_y, 0);
//							transform_rcm[1]->RotateWXYZ(Quatnode_rcm.nodelist[1]->axisangle[a][0], Quatnode_rcm.nodelist[1]->axisangle[a][1], Quatnode_rcm.nodelist[1]->axisangle[a][2], Quatnode_rcm.nodelist[1]->axisangle[a][3]);
//							transform_rcm[1]->Translate(-ffIK_CH0_x, -ffIK_CH0_y, 0);
//
//							// Right Upper arm
//							transform_rcm[2] = IK_rightUpperArm_Transform;
//							transform_rcm[2]->Identity();
//							transform_rcm[2]->Translate(ffIK_UA_x, ffIK_UA_y, 0);
//							transform_rcm[2]->RotateWXYZ(Quatnode_rcm.nodelist[2]->axisangle[a][0], Quatnode_rcm.nodelist[2]->axisangle[a][1], Quatnode_rcm.nodelist[2]->axisangle[a][2], Quatnode_rcm.nodelist[2]->axisangle[a][3]);
//							transform_rcm[2]->Translate(-ffIK_UA_x, -ffIK_UA_y, 0);
//
//							// Right Lower arm
//							transform_rcm[3] = IK_rightLowerArm_Transform;
//							transform_rcm[3]->Identity();
//							transform_rcm[3]->Translate(ffIK_LA_x, ffIK_LA_y, 0);
//							transform_rcm[3]->RotateWXYZ(Quatnode_rcm.nodelist[3]->axisangle[a][0], Quatnode_rcm.nodelist[3]->axisangle[a][1], Quatnode_rcm.nodelist[3]->axisangle[a][2], Quatnode_rcm.nodelist[3]->axisangle[a][3]);
//							transform_rcm[3]->Translate(-ffIK_LA_x, -ffIK_LA_y, 0);
//
//
//							// Left Upper arm
//							transform_rcm[4] = IK_leftUpperArm_Transform;
//							transform_rcm[4]->Identity();
//							transform_rcm[4]->Translate(ffIK_LUA_x, ffIK_LUA_y, 0);
//							transform_rcm[4]->RotateWXYZ(Quatnode_rcm.nodelist[4]->axisangle[a][0], Quatnode_rcm.nodelist[4]->axisangle[a][1], Quatnode_rcm.nodelist[4]->axisangle[a][2], Quatnode_rcm.nodelist[4]->axisangle[a][3]);
//							transform_rcm[4]->Translate(-ffIK_LUA_x, -ffIK_LUA_y, 0);
//
//							// Left Lower arm
//							transform_rcm[5] = IK_leftLowerArm_Transform;
//							transform_rcm[5]->Identity();
//							transform_rcm[5]->Translate(ffIK_LLA_x, ffIK_LLA_y, 0);
//							transform_rcm[5]->RotateWXYZ(Quatnode_rcm.nodelist[5]->axisangle[a][0], Quatnode_rcm.nodelist[5]->axisangle[a][1], Quatnode_rcm.nodelist[5]->axisangle[a][2], Quatnode_rcm.nodelist[5]->axisangle[a][3]);
//							transform_rcm[5]->Translate(-ffIK_LLA_x, -ffIK_LLA_y, 0);
//
//
//							// Right Upper leg
//							transform_rcm[6] = IK_rightUpperLeg_Transform;
//							transform_rcm[6]->Identity();
//							transform_rcm[6]->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
//							transform_rcm[6]->RotateWXYZ(Quatnode_rcm.nodelist[6]->axisangle[a][0], Quatnode_rcm.nodelist[6]->axisangle[a][1], Quatnode_rcm.nodelist[6]->axisangle[a][2], Quatnode_rcm.nodelist[6]->axisangle[a][3]);
//							transform_rcm[6]->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
//
//							// Right Lower leg
//							transform_rcm[7] = IK_rightLowerLeg_Transform;
//							transform_rcm[7]->Identity();
//							transform_rcm[7]->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
//							transform_rcm[7]->RotateWXYZ(Quatnode_rcm.nodelist[7]->axisangle[a][0], Quatnode_rcm.nodelist[7]->axisangle[a][1], Quatnode_rcm.nodelist[7]->axisangle[a][2], Quatnode_rcm.nodelist[7]->axisangle[a][3]);
//							transform_rcm[7]->Translate(-ffIK_LL_x, ffIK_LL_y, 0);
//
//							// Left Upper leg
//							transform_rcm[8] = IK_leftUpperLeg_Transform;
//							transform_rcm[8]->Identity();
//							transform_rcm[8]->Translate(ffIK_UL_x, ffIK_UL_y, 0);
//							transform_rcm[8]->RotateWXYZ(Quatnode_rcm.nodelist[8]->axisangle[a][0], Quatnode_rcm.nodelist[8]->axisangle[a][1], Quatnode_rcm.nodelist[8]->axisangle[a][2], Quatnode_rcm.nodelist[8]->axisangle[a][3]);
//							transform_rcm[8]->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);
//
//							// Left Lower leg
//							transform_rcm[9] = IK_leftLowerLeg_Transform;
//							transform_rcm[9]->Identity();
//							transform_rcm[9]->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
//							transform_rcm[9]->RotateWXYZ(Quatnode_rcm.nodelist[9]->axisangle[a][0], Quatnode_rcm.nodelist[9]->axisangle[a][1], Quatnode_rcm.nodelist[9]->axisangle[a][2], Quatnode_rcm.nodelist[9]->axisangle[a][3]);
//							transform_rcm[9]->Translate(ffIK_LL_x, ffIK_LL_y, 0);
//
//
//						}
//						else if (ffIK_RF == 1)
//						{
//							//Lower Chest
//							transform_rcm[1] = IK_chest_0_Transform;
//							transform_rcm[1]->Identity();
//							transform_rcm[1]->Translate(ffIK_CH0_x, ffIK_CH0_y, 0);
//							transform_rcm[1]->RotateWXYZ(Quatnode_rcm.nodelist[1]->axisangle[a][0], Quatnode_rcm.nodelist[1]->axisangle[a][1], Quatnode_rcm.nodelist[1]->axisangle[a][2], Quatnode_rcm.nodelist[1]->axisangle[a][3]);
//							transform_rcm[1]->Translate(-ffIK_CH0_x, -ffIK_CH0_y, 0);
//
//							// Right Upper arm
//							transform_rcm[2] = IK_rightUpperArm_Transform;
//							transform_rcm[2]->Identity();
//							transform_rcm[2]->Translate(ffIK_UA_x, ffIK_UA_y, 0);
//							transform_rcm[2]->RotateWXYZ(Quatnode_rcm.nodelist[2]->axisangle[a][0], Quatnode_rcm.nodelist[2]->axisangle[a][1], Quatnode_rcm.nodelist[2]->axisangle[a][2], Quatnode_rcm.nodelist[2]->axisangle[a][3]);
//							transform_rcm[2]->Translate(-ffIK_UA_x, -ffIK_UA_y, 0);
//
//							// Right Lower arm
//							transform_rcm[3] = IK_rightLowerArm_Transform;
//							transform_rcm[3]->Identity();
//							transform_rcm[3]->Translate(ffIK_LA_x, ffIK_LA_y, 0);
//							transform_rcm[3]->RotateWXYZ(Quatnode_rcm.nodelist[3]->axisangle[a][0], Quatnode_rcm.nodelist[3]->axisangle[a][1], Quatnode_rcm.nodelist[3]->axisangle[a][2], Quatnode_rcm.nodelist[3]->axisangle[a][3]);
//							transform_rcm[3]->Translate(-ffIK_LA_x, -ffIK_LA_y, 0);
//
//
//							// Left Upper arm
//							transform_rcm[4] = IK_leftUpperArm_Transform;
//							transform_rcm[4]->Identity();
//							transform_rcm[4]->Translate(ffIK_LUA_x, ffIK_LUA_y, 0);
//							transform_rcm[4]->RotateWXYZ(Quatnode_rcm.nodelist[4]->axisangle[a][0], Quatnode_rcm.nodelist[4]->axisangle[a][1], Quatnode_rcm.nodelist[4]->axisangle[a][2], Quatnode_rcm.nodelist[4]->axisangle[a][3]);
//							transform_rcm[4]->Translate(-ffIK_LUA_x, -ffIK_LUA_y, 0);
//
//							// Left Lower arm
//							transform_rcm[5] = IK_leftLowerArm_Transform;
//							transform_rcm[5]->Identity();
//							transform_rcm[5]->Translate(ffIK_LLA_x, ffIK_LLA_y, 0);
//							transform_rcm[5]->RotateWXYZ(Quatnode_rcm.nodelist[5]->axisangle[a][0], Quatnode_rcm.nodelist[5]->axisangle[a][1], Quatnode_rcm.nodelist[5]->axisangle[a][2], Quatnode_rcm.nodelist[5]->axisangle[a][3]);
//							transform_rcm[5]->Translate(-ffIK_LLA_x, -ffIK_LLA_y, 0);
//
//							// Right Upper leg
//							transform_rcm[6] = IK_rightUpperLeg_Transform;
//							transform_rcm[6]->Identity();
//							transform_rcm[6]->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
//							transform_rcm[6]->RotateWXYZ(Quatnode_rcm.nodelist[6]->axisangle[a][0], Quatnode_rcm.nodelist[6]->axisangle[a][1], Quatnode_rcm.nodelist[6]->axisangle[a][2], Quatnode_rcm.nodelist[6]->axisangle[a][3]);
//							transform_rcm[6]->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
//
//							// Right Lower leg
//							transform_rcm[7] = IK_rightLowerLeg_Transform;
//							transform_rcm[7]->Identity();
//							transform_rcm[7]->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
//							transform_rcm[7]->RotateWXYZ(Quatnode_rcm.nodelist[7]->axisangle[a][0], Quatnode_rcm.nodelist[7]->axisangle[a][1], Quatnode_rcm.nodelist[7]->axisangle[a][2], Quatnode_rcm.nodelist[7]->axisangle[a][3]);
//							transform_rcm[7]->Translate(-ffIK_LL_x, ffIK_LL_y, 0);
//
//							// Left Upper leg
//							transform_rcm[8] = IK_freeLeftUpperLeg_Transform;
//							transform_rcm[8]->Identity();
//							transform_rcm[8]->Translate(-freefootLUL_x, freefootLUL_y, 0);
//							transform_rcm[8]->RotateWXYZ(Quatnode_rcm.nodelist[8]->axisangle[a][0], Quatnode_rcm.nodelist[8]->axisangle[a][1], Quatnode_rcm.nodelist[8]->axisangle[a][2], Quatnode_rcm.nodelist[8]->axisangle[a][3]);
//							transform_rcm[8]->Translate(freefootLUL_x, -freefootLUL_y, 0);
//
//							// Left Lower leg
//							transform_rcm[9] = IK_freeLeftLowerLeg_Transform;
//							transform_rcm[9]->Identity();
//							transform_rcm[9]->Translate(-freefootLLL_x, freefootLLL_y, 0);
//							transform_rcm[9]->RotateWXYZ(Quatnode_rcm.nodelist[9]->axisangle[a][0], Quatnode_rcm.nodelist[9]->axisangle[a][1], Quatnode_rcm.nodelist[9]->axisangle[a][2], Quatnode_rcm.nodelist[9]->axisangle[a][3]);
//							transform_rcm[9]->Translate(freefootLLL_x, -freefootLLL_y, 0);
//
//						}
//						else if (ffIK_LF == 1)
//						{
//							//Lower Chest
//							transform_rcm[1] = IK_chest_0_Transform;
//							transform_rcm[1]->Identity();
//							transform_rcm[1]->Translate(ffIK_CH0_x, ffIK_CH0_y, 0);
//							transform_rcm[1]->RotateWXYZ(Quatnode_rcm.nodelist[1]->axisangle[a][0], Quatnode_rcm.nodelist[1]->axisangle[a][1], Quatnode_rcm.nodelist[1]->axisangle[a][2], Quatnode_rcm.nodelist[1]->axisangle[a][3]);
//							transform_rcm[1]->Translate(-ffIK_CH0_x, -ffIK_CH0_y, 0);
//
//							// Right Upper arm
//							transform_rcm[2] = IK_rightUpperArm_Transform;
//							transform_rcm[2]->Identity();
//							transform_rcm[2]->Translate(ffIK_UA_x, ffIK_UA_y, 0);
//							transform_rcm[2]->RotateWXYZ(Quatnode_rcm.nodelist[2]->axisangle[a][0], Quatnode_rcm.nodelist[2]->axisangle[a][1], Quatnode_rcm.nodelist[2]->axisangle[a][2], Quatnode_rcm.nodelist[2]->axisangle[a][3]);
//							transform_rcm[2]->Translate(-ffIK_UA_x, -ffIK_UA_y, 0);
//
//							// Right Lower arm
//							transform_rcm[3] = IK_rightLowerArm_Transform;
//							transform_rcm[3]->Identity();
//							transform_rcm[3]->Translate(ffIK_LA_x, ffIK_LA_y, 0);
//							transform_rcm[3]->RotateWXYZ(Quatnode_rcm.nodelist[3]->axisangle[a][0], Quatnode_rcm.nodelist[3]->axisangle[a][1], Quatnode_rcm.nodelist[3]->axisangle[a][2], Quatnode_rcm.nodelist[3]->axisangle[a][3]);
//							transform_rcm[3]->Translate(-ffIK_LA_x, -ffIK_LA_y, 0);
//
//
//							// Left Upper arm
//							transform_rcm[4] = IK_leftUpperArm_Transform;
//							transform_rcm[4]->Identity();
//							transform_rcm[4]->Translate(ffIK_LUA_x, ffIK_LUA_y, 0);
//							transform_rcm[4]->RotateWXYZ(Quatnode_rcm.nodelist[4]->axisangle[a][0], Quatnode_rcm.nodelist[4]->axisangle[a][1], Quatnode_rcm.nodelist[4]->axisangle[a][2], Quatnode_rcm.nodelist[4]->axisangle[a][3]);
//							transform_rcm[4]->Translate(-ffIK_LUA_x, -ffIK_LUA_y, 0);
//
//							// Left Lower arm
//							transform_rcm[5] = IK_leftLowerArm_Transform;
//							transform_rcm[5]->Identity();
//							transform_rcm[5]->Translate(ffIK_LLA_x, ffIK_LLA_y, 0);
//							transform_rcm[5]->RotateWXYZ(Quatnode_rcm.nodelist[5]->axisangle[a][0], Quatnode_rcm.nodelist[5]->axisangle[a][1], Quatnode_rcm.nodelist[5]->axisangle[a][2], Quatnode_rcm.nodelist[5]->axisangle[a][3]);
//							transform_rcm[5]->Translate(-ffIK_LLA_x, -ffIK_LLA_y, 0);
//
//							// Right Upper leg
//							transform_rcm[6] = IK_freeRightUpperLeg_Transform;
//							transform_rcm[6]->Identity();
//							transform_rcm[6]->Translate(-freefootRUL_x, freefootRUL_y, 0);
//							transform_rcm[6]->RotateWXYZ(Quatnode_rcm.nodelist[6]->axisangle[a][0], Quatnode_rcm.nodelist[6]->axisangle[a][1], Quatnode_rcm.nodelist[6]->axisangle[a][2], Quatnode_rcm.nodelist[6]->axisangle[a][3]);
//							transform_rcm[6]->Translate(freefootRUL_x, -freefootRUL_y, 0);
//
//							// Right Lower leg
//							transform_rcm[7] = IK_freeRightLowerLeg_Transform;
//							transform_rcm[7]->Identity();
//							transform_rcm[7]->Translate(-freefootRLL_x, freefootRLL_y, 0);
//							transform_rcm[7]->RotateWXYZ(Quatnode_rcm.nodelist[7]->axisangle[a][0], Quatnode_rcm.nodelist[7]->axisangle[a][1], Quatnode_rcm.nodelist[7]->axisangle[a][2], Quatnode_rcm.nodelist[7]->axisangle[a][3]);
//							transform_rcm[7]->Translate(freefootRLL_x, -freefootRLL_y, 0);
//
//							// Left Upper leg
//							transform_rcm[8] = IK_leftUpperLeg_Transform;
//							transform_rcm[8]->Identity();
//							transform_rcm[8]->Translate(ffIK_UL_x, ffIK_UL_y, 0);
//							transform_rcm[8]->RotateWXYZ(Quatnode_rcm.nodelist[8]->axisangle[a][0], Quatnode_rcm.nodelist[8]->axisangle[a][1], Quatnode_rcm.nodelist[8]->axisangle[a][2], Quatnode_rcm.nodelist[8]->axisangle[a][3]);
//							transform_rcm[8]->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);
//
//							// Left Lower leg
//							transform_rcm[9] = IK_leftLowerLeg_Transform;
//							transform_rcm[9]->Identity();
//							transform_rcm[9]->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
//							transform_rcm[9]->RotateWXYZ(Quatnode_rcm.nodelist[9]->axisangle[a][0], Quatnode_rcm.nodelist[9]->axisangle[a][1], Quatnode_rcm.nodelist[9]->axisangle[a][2], Quatnode_rcm.nodelist[9]->axisangle[a][3]);
//							transform_rcm[9]->Translate(ffIK_LL_x, ffIK_LL_y, 0);
//
//						}
//
//						else
//						{
//							//Lower Chest
//							transform_rcm[1] = stickModel_chest_0_Transform;
//							transform_rcm[1]->Identity();
//							transform_rcm[1]->Translate(CH0_x, CH0_y, 0);
//							transform_rcm[1]->RotateWXYZ(Quatnode_rcm.nodelist[1]->axisangle[a][0], Quatnode_rcm.nodelist[1]->axisangle[a][1], Quatnode_rcm.nodelist[1]->axisangle[a][2], Quatnode_rcm.nodelist[1]->axisangle[a][3]);
//							transform_rcm[1]->Translate(-CH0_x, -CH0_y, 0);
//
//							// Right Upper arm
//							transform_rcm[2] = stickModel_rightUpperArm_Transform;
//							transform_rcm[2]->Identity();
//							transform_rcm[2]->Translate(smUA_x, smUA_y, 0);
//							transform_rcm[2]->RotateWXYZ(Quatnode_rcm.nodelist[2]->axisangle[a][0], Quatnode_rcm.nodelist[2]->axisangle[a][1], Quatnode_rcm.nodelist[2]->axisangle[a][2], Quatnode_rcm.nodelist[2]->axisangle[a][3]);
//							transform_rcm[2]->Translate(-smUA_x, -smUA_y, 0);
//
//							// Right Lower arm
//							transform_rcm[3] = stickModel_rightLowerArm_Transform;
//							transform_rcm[3]->Identity();
//							transform_rcm[3]->Translate(smLA_x, smLA_y, 0);
//							transform_rcm[3]->RotateWXYZ(Quatnode_rcm.nodelist[3]->axisangle[a][0], Quatnode_rcm.nodelist[3]->axisangle[a][1], Quatnode_rcm.nodelist[3]->axisangle[a][2], Quatnode_rcm.nodelist[3]->axisangle[a][3]);
//							transform_rcm[3]->Translate(-smLA_x, -smLA_y, 0);
//
//
//							// Left Upper arm
//							transform_rcm[4] = stickModel_leftUpperArm_Transform;
//							transform_rcm[4]->Identity();
//							transform_rcm[4]->Translate(-smUA_x, smUA_y, 0);
//							transform_rcm[4]->RotateWXYZ(Quatnode_rcm.nodelist[4]->axisangle[a][0], Quatnode_rcm.nodelist[4]->axisangle[a][1], Quatnode_rcm.nodelist[4]->axisangle[a][2], Quatnode_rcm.nodelist[4]->axisangle[a][3]);
//							transform_rcm[4]->Translate(smUA_x, -smUA_y, 0);
//
//							// Left Lower arm
//							transform_rcm[5] = stickModel_leftLowerArm_Transform;
//							transform_rcm[5]->Identity();
//							transform_rcm[5]->Translate(-smLA_x, smLA_y, 0);
//							transform_rcm[5]->RotateWXYZ(Quatnode_rcm.nodelist[5]->axisangle[a][0], Quatnode_rcm.nodelist[5]->axisangle[a][1], Quatnode_rcm.nodelist[5]->axisangle[a][2], Quatnode_rcm.nodelist[5]->axisangle[a][3]);
//							transform_rcm[5]->Translate(smLA_x, -smLA_y, 0);
//
//							// Right Upper leg
//							transform_rcm[6] = stickModel_rightUpperLeg_Transform;
//							transform_rcm[6]->Identity();
//							transform_rcm[6]->Translate(smUL_x, smUL_y, 0);
//							transform_rcm[6]->RotateWXYZ(Quatnode_rcm.nodelist[6]->axisangle[a][0], Quatnode_rcm.nodelist[6]->axisangle[a][1], Quatnode_rcm.nodelist[6]->axisangle[a][2], Quatnode_rcm.nodelist[6]->axisangle[a][3]);
//							transform_rcm[6]->Translate(-smUL_x, -smUL_y, 0);
//
//							// Right Lower leg
//							transform_rcm[7] = stickModel_rightLowerLeg_Transform;
//							transform_rcm[7]->Identity();
//							transform_rcm[7]->Translate(smLL_x, smLL_y, 0);
//							transform_rcm[7]->RotateWXYZ(Quatnode_rcm.nodelist[7]->axisangle[a][0], Quatnode_rcm.nodelist[7]->axisangle[a][1], Quatnode_rcm.nodelist[7]->axisangle[a][2], Quatnode_rcm.nodelist[7]->axisangle[a][3]);
//							transform_rcm[7]->Translate(-smLL_x, -smLL_y, 0);
//
//							// Left Upper leg
//							transform_rcm[8] = stickModel_leftUpperLeg_Transform;
//							transform_rcm[8]->Identity();
//							transform_rcm[8]->Translate(-smUL_x, smUL_y, 0);
//							transform_rcm[8]->RotateWXYZ(Quatnode_rcm.nodelist[8]->axisangle[a][0], Quatnode_rcm.nodelist[8]->axisangle[a][1], Quatnode_rcm.nodelist[8]->axisangle[a][2], Quatnode_rcm.nodelist[8]->axisangle[a][3]);
//							transform_rcm[8]->Translate(smUL_x, -smUL_y, 0);
//
//							// Left Lower leg
//							transform_rcm[9] = stickModel_leftLowerLeg_Transform;
//							transform_rcm[9]->Identity();
//							transform_rcm[9]->Translate(-smLL_x, smLL_y, 0);
//							transform_rcm[9]->RotateWXYZ(Quatnode_rcm.nodelist[9]->axisangle[a][0], Quatnode_rcm.nodelist[9]->axisangle[a][1], Quatnode_rcm.nodelist[9]->axisangle[a][2], Quatnode_rcm.nodelist[9]->axisangle[a][3]);
//							transform_rcm[9]->Translate(smLL_x, -smLL_y, 0);
//						}
//
//					}
//
//					if (fullbodyMS_Status)
//					{
//						cout << Quatnode_rcm.nodelist[2]->datatest[a][0] << "\t" << Quatnode_rcm.nodelist[2]->datatest[a][1] << "\t" << Quatnode_rcm.nodelist[2]->datatest[a][2] << "\t" << Quatnode_rcm.nodelist[2]->datatest[a][3] << endl;
//					}
//
//					else
//					{
//
//					}
//				
//				
//			}
//			//Sleep(15);
//			renderWindow->Render();
//		}
//		if (fileMode)
//		{
//			if (a < loadframes_srq)
//			{
//								
//					if (male_biped)
//					{
//						//Lower Chest
//						transform_srq[1] = CUconeTransform;
//						transform_srq[1]->Identity();
//						transform_srq[1]->Translate(chestObj_xpos, chestObj_ypos, chestObj_zpos);
//						transform_srq[1]->RotateWXYZ(Quatnode_srq.nodelist[1]->axisangle[a][0], Quatnode_srq.nodelist[1]->axisangle[a][1], Quatnode_srq.nodelist[1]->axisangle[a][2], Quatnode_srq.nodelist[1]->axisangle[a][3]);
//
//						// Right Upper arm
//						transform_srq[2] = RarmTransform;
//						transform_srq[2]->Identity();
//						transform_srq[2]->Translate(ruaObj_xpos, ruaObj_ypos, ruaObj_zpos);
//						transform_srq[2]->RotateWXYZ(Quatnode_srq.nodelist[2]->axisangle[a][0], Quatnode_srq.nodelist[2]->axisangle[a][1], Quatnode_srq.nodelist[2]->axisangle[a][2], Quatnode_srq.nodelist[2]->axisangle[a][3]);
//
//						// Right Lower arm
//						transform_srq[3] = RforearmTransform;
//						transform_srq[3]->Identity();
//						transform_srq[3]->Translate(rlaObj_xpos, rlaObj_ypos, rlaObj_zpos);
//						transform_srq[3]->RotateWXYZ(Quatnode_srq.nodelist[3]->axisangle[a][0], Quatnode_srq.nodelist[3]->axisangle[a][1], Quatnode_srq.nodelist[3]->axisangle[a][2], Quatnode_srq.nodelist[3]->axisangle[a][3]);
//
//						// Left Upper arm
//						transform_srq[4] = LarmTransform;
//						transform_srq[4]->Identity();
//						transform_srq[4]->Translate(luaObj_xpos, luaObj_ypos, luaObj_zpos);
//						transform_srq[4]->RotateWXYZ(Quatnode_srq.nodelist[4]->axisangle[a][0], Quatnode_srq.nodelist[4]->axisangle[a][1], Quatnode_srq.nodelist[4]->axisangle[a][2], Quatnode_srq.nodelist[4]->axisangle[a][3]);
//
//						// Left Lower arm
//						transform_srq[5] = LforearmTransform;
//						transform_srq[5]->Identity();
//						transform_srq[5]->Translate(llaObj_xpos, llaObj_ypos, llaObj_zpos);
//						transform_srq[5]->RotateWXYZ(Quatnode_srq.nodelist[5]->axisangle[a][0], Quatnode_srq.nodelist[5]->axisangle[a][1], Quatnode_srq.nodelist[5]->axisangle[a][2], Quatnode_srq.nodelist[5]->axisangle[a][3]);
//
//						// Right Upper leg
//						transform_srq[6] = RlulegTransform;
//						transform_srq[6]->Identity();
//						transform_srq[6]->Translate(rulObj_xpos, rulObj_ypos, rulObj_zpos);
//						transform_srq[6]->RotateWXYZ(Quatnode_srq.nodelist[6]->axisangle[a][0], Quatnode_srq.nodelist[6]->axisangle[a][1], Quatnode_srq.nodelist[6]->axisangle[a][2], Quatnode_srq.nodelist[6]->axisangle[a][3]);
//
//						// Right Lower leg
//						transform_srq[7] = RllegTransform;
//						transform_srq[7]->Identity();
//						transform_srq[7]->Translate(rllObj_xpos, rllObj_ypos, rllObj_zpos);
//						transform_srq[7]->RotateWXYZ(Quatnode_srq.nodelist[7]->axisangle[a][0], Quatnode_srq.nodelist[7]->axisangle[a][1], Quatnode_srq.nodelist[7]->axisangle[a][2], Quatnode_srq.nodelist[7]->axisangle[a][3]);
//
//						//  Left Upper leg
//						transform_srq[8] = LlulegTransform;
//						transform_srq[8]->Identity();
//						transform_srq[8]->Translate(lulObj_xpos, lulObj_ypos, lulObj_zpos);
//						transform_srq[8]->RotateWXYZ(Quatnode_srq.nodelist[8]->axisangle[a][0], Quatnode_srq.nodelist[8]->axisangle[a][1], Quatnode_srq.nodelist[8]->axisangle[a][2], Quatnode_srq.nodelist[8]->axisangle[a][3]);
//
//						// Left Lower leg
//						transform_srq[9] = LllegTransform;
//						transform_srq[9]->Identity();
//						transform_srq[9]->Translate(lllObj_xpos, lllObj_ypos, lllObj_zpos);
//						transform_srq[9]->RotateWXYZ(Quatnode_srq.nodelist[9]->axisangle[a][0], Quatnode_srq.nodelist[9]->axisangle[a][1], Quatnode_srq.nodelist[9]->axisangle[a][2], Quatnode_srq.nodelist[9]->axisangle[a][3]);
//						
//						cout << "RUA_Collide:"<< RUA_collide->GetNumberOfContacts() << endl;
//					}
//					if (skeleton_biped)
//					{
//
//							//Lower Chest
//							transform_srq[1] = stickModel_chest_0_Transform;
//							transform_srq[1]->Identity();
//							transform_srq[1]->Translate(CH0_x, CH0_y, 0);
//							transform_srq[1]->RotateWXYZ(Quatnode_srq.nodelist[1]->axisangle[a][0], Quatnode_srq.nodelist[1]->axisangle[a][1], Quatnode_srq.nodelist[1]->axisangle[a][2], Quatnode_srq.nodelist[1]->axisangle[a][3]);
//							transform_srq[1]->Translate(-CH0_x, -CH0_y, 0);
//
//							// Right Upper arm
//							transform_srq[2] = stickModel_rightUpperArm_Transform;
//							transform_srq[2]->Identity();
//							transform_srq[2]->Translate(smUA_x, smUA_y, 0);
//							transform_srq[2]->RotateWXYZ(Quatnode_srq.nodelist[2]->axisangle[a][0], Quatnode_srq.nodelist[2]->axisangle[a][1], Quatnode_srq.nodelist[2]->axisangle[a][2], Quatnode_srq.nodelist[2]->axisangle[a][3]);
//							transform_srq[2]->Translate(-smUA_x, -smUA_y, 0);
//
//							// Right Lower arm
//							transform_srq[3] = stickModel_rightLowerArm_Transform;
//							transform_srq[3]->Identity();
//							transform_srq[3]->Translate(smLA_x, smLA_y, 0);
//							transform_srq[3]->RotateWXYZ(Quatnode_srq.nodelist[3]->axisangle[a][0], Quatnode_srq.nodelist[3]->axisangle[a][1], Quatnode_srq.nodelist[3]->axisangle[a][2], Quatnode_srq.nodelist[3]->axisangle[a][3]);
//							transform_srq[3]->Translate(-smLA_x, -smLA_y, 0);
//
//
//							// Left Upper arm
//							transform_srq[4] = stickModel_leftUpperArm_Transform;
//							transform_srq[4]->Identity();
//							transform_srq[4]->Translate(-smUA_x, smUA_y, 0);
//							transform_srq[4]->RotateWXYZ(Quatnode_srq.nodelist[4]->axisangle[a][0], Quatnode_srq.nodelist[4]->axisangle[a][1], Quatnode_srq.nodelist[4]->axisangle[a][2], Quatnode_srq.nodelist[4]->axisangle[a][3]);
//							transform_srq[4]->Translate(smUA_x, -smUA_y, 0);
//
//							// Left Lower arm
//							transform_srq[5] = stickModel_leftLowerArm_Transform;
//							transform_srq[5]->Identity();
//							transform_srq[5]->Translate(-smLA_x, smLA_y, 0);
//							transform_srq[5]->RotateWXYZ(Quatnode_srq.nodelist[5]->axisangle[a][0], Quatnode_srq.nodelist[5]->axisangle[a][1], Quatnode_srq.nodelist[5]->axisangle[a][2], Quatnode_srq.nodelist[5]->axisangle[a][3]);
//							transform_srq[5]->Translate(smLA_x, -smLA_y, 0);
//
//							// Right Upper leg
//							transform_srq[6] = stickModel_rightUpperLeg_Transform;
//							transform_srq[6]->Identity();
//							transform_srq[6]->Translate(smUL_x, smUL_y, 0);
//							transform_srq[6]->RotateWXYZ(Quatnode_srq.nodelist[6]->axisangle[a][0], Quatnode_srq.nodelist[6]->axisangle[a][1], Quatnode_srq.nodelist[6]->axisangle[a][2], Quatnode_srq.nodelist[6]->axisangle[a][3]);
//							transform_srq[6]->Translate(-smUL_x, -smUL_y, 0);
//
//							// Right Lower leg
//							transform_srq[7] = stickModel_rightLowerLeg_Transform;
//							transform_srq[7]->Identity();
//							transform_srq[7]->Translate(smLL_x, smLL_y, 0);
//							transform_srq[7]->RotateWXYZ(Quatnode_srq.nodelist[7]->axisangle[a][0], Quatnode_srq.nodelist[7]->axisangle[a][1], Quatnode_srq.nodelist[7]->axisangle[a][2], Quatnode_srq.nodelist[7]->axisangle[a][3]);
//							transform_srq[7]->Translate(-smLL_x, -smLL_y, 0);
//
//							// Left Upper leg
//							transform_srq[8] = stickModel_leftUpperLeg_Transform;
//							transform_srq[8]->Identity();
//							transform_srq[8]->Translate(-smUL_x, smUL_y, 0);
//							transform_srq[8]->RotateWXYZ(Quatnode_srq.nodelist[8]->axisangle[a][0], Quatnode_srq.nodelist[8]->axisangle[a][1], Quatnode_srq.nodelist[8]->axisangle[a][2], Quatnode_srq.nodelist[8]->axisangle[a][3]);
//							transform_srq[8]->Translate(smUL_x, -smUL_y, 0);
//
//							// Left Lower leg
//							transform_srq[9] = stickModel_leftLowerLeg_Transform;
//							transform_srq[9]->Identity();
//							transform_srq[9]->Translate(-smLL_x, smLL_y, 0);
//							transform_srq[9]->RotateWXYZ(Quatnode_srq.nodelist[9]->axisangle[a][0], Quatnode_srq.nodelist[9]->axisangle[a][1], Quatnode_srq.nodelist[9]->axisangle[a][2], Quatnode_srq.nodelist[9]->axisangle[a][3]);
//							transform_srq[9]->Translate(smLL_x, -smLL_y, 0);
//					
//						
//					}
//			
//
//				
//			}
//			//Sleep(15);
//
//			renderWindow->Render();
//			
//		}
//	
//		//cout << pelvisStomach.jointPoint[0] << "," << pelvisStomach.jointPoint[1] << "," << pelvisStomach.jointPoint[2] << endl;
//		// quatTo_posFile << pelvisStomach.jointPoint[0] << "," << pelvisStomach.jointPoint[1] << "," << pelvisStomach.jointPoint[2] << endl;
//		quatTo_posFile << pelvisStomach.jointPoint[0] << "\t" << pelvisStomach.jointPoint[1] << "\t" << pelvisStomach.jointPoint[2] << "\t"
//			<< sternumChest.jointPoint[0] << "\t" << sternumChest.jointPoint[1] << "\t" << sternumChest.jointPoint[2] << "\t"
//			<< rightShoulderSegment.jointPoint[0] << "\t" << rightShoulderSegment.jointPoint[1] << "\t" << rightShoulderSegment.jointPoint[2] << "\t"
//			<< rightElbowUpperArm.jointPoint[0] << "\t" << rightElbowUpperArm.jointPoint[1] << "\t" << rightElbowUpperArm.jointPoint[2] << "\t"
//			<< leftShoulderSegment.jointPoint[0] << "\t" << leftShoulderSegment.jointPoint[1] << "\t" << leftShoulderSegment.jointPoint[2] << "\t"
//			<< leftElbowUpperArm.jointPoint[0] << "\t" << leftElbowUpperArm.jointPoint[1] << "\t" << leftElbowUpperArm.jointPoint[2] << "\t"
//			<< rightHipSegment.jointPoint[0] << "\t" << rightHipSegment.jointPoint[1] << "\t" << rightHipSegment.jointPoint[2] << "\t"
//			<< rightKneeUpperLeg.jointPoint[0] << "\t" << rightKneeUpperLeg.jointPoint[1] << "\t" << rightKneeUpperLeg.jointPoint[2] << "\t"
//			<< leftHipSegment.jointPoint[0] << "\t" << leftHipSegment.jointPoint[1] << "\t" << leftHipSegment.jointPoint[2] << "\t"
//			<< leftKneeUpperLeg.jointPoint[0] << "\t" << leftKneeUpperLeg.jointPoint[1] << "\t" << leftKneeUpperLeg.jointPoint[2] << "\t" << endl;
//		//quatTo_posFile << 1 << endl;
//
//		if (vitruvian_biped == 1 && bReadFile)
//		{
//			
//		
//			if (a >= vitruvian_su.noOfFrames)
//			{
//				bReadFile = false;
//				VitruvianAvatar::isLoaded = false;
//				quatTo_posFile.close();
//			}
//			else
//			{
//				a++;
//				VitruvianAvatar::vitruvianAvatarUpdate = getFirstInverse(a - 1, &vitruvian_su);
//				rotateAvatar(VitruvianAvatar::vitruvianAvatarUpdate);
//				renderWindow->Render();
//			
//			}
//		}
//		bReadFile = true;
//		VitruvianAvatar::isLoaded = true;
//}
//
//
//void EventQtSlotConnect::load_AuthoredData()
//{
//	cout << "Authored Motion File Loading Enabled" << endl;
//	QString authoredMotion_file = QFileDialog::getOpenFileName(this, "Open AuthoredMotion File", "c:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/motionDB/authoredMotion");
//	QFileInfo aM_file(authoredMotion_file);
//	QString afname = aM_file.fileName();
//	QMessageBox::information(this, "Motion File", afname);
//
//	string am_fi = authoredMotion_file.toStdString();
//	const char *am_file = am_fi.c_str();
//
//	authorMode = false;
//	fileMode = true;
//	Quatnode_srq.nodecreate();
//	Quatnode_srq.loadQuaternion(am_file);
//	Quatnode_srq.rotateaxis();
//	//Quatnode_srq.quattoeuler();
//	Quatnode_srq.quattoaxisangle();
//	Quatnode_srq.quattoHeight();
//
//	// For JointSphere Trajectories Data
//	Quatnode_srq.Calpts();
//
//	current_frames_srq = Quatnode_srq.frames;
//	loadframes_srq = Quatnode_srq.frames;
//
//}
//void EventQtSlotConnect::load_sensedData()
//{
//
//	if (vitruvian_biped == 1)
//	{
//		vitruvian_su.readAvatarData("formFile.txt");
//		VitruvianAvatar::isLoaded = true;
//		bReadFile = true;
//	}
//	else
//	{
//		VitruvianAvatar::isLoaded = false;
//		bReadFile = false;
//
//
//		cout << "Sensed Motion File Loading Enabled" << endl;
//		QString sensedMotion_file = QFileDialog::getOpenFileName(this, "Open SensedMotion File", "c:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/motionDB/sensedMotion");
//		QFileInfo sM_file(sensedMotion_file);
//		QString fname = sM_file.fileName();
//		QMessageBox::information(this, "Motion File", fname);
//
//		string sm_fi = sensedMotion_file.toStdString();
//		const char *sm_file = sm_fi.c_str();
//		//cout << "\n" << sensedMotion_file.toStdString() << endl;
//
//		rawQuatFile.readAvatarData(sm_fi);
//		cout << "========================================" << endl;
//		cout << "Frames:" << rawQuatFile.noOfFrames << endl << endl;;
//
//		firstQuat_Pelvis = rawQuatFile.avatarData[0].b0;
//		firstQuat_Chest = rawQuatFile.avatarData[0].b1;
//
//		firstQuat_RightUpperArm = rawQuatFile.avatarData[0].b2;
//		firstQuat_RightLowerArm = rawQuatFile.avatarData[0].b3;
//
//		firstQuat_LeftUpperArm = rawQuatFile.avatarData[0].b4;
//		firstQuat_LeftLowerArm = rawQuatFile.avatarData[0].b5;
//
//		firstQuat_RightUpperLeg = rawQuatFile.avatarData[0].b6;
//		firstQuat_RightLowerLeg = rawQuatFile.avatarData[0].b7;
//
//		firstQuat_LeftUpperLeg = rawQuatFile.avatarData[0].b8;
//		firstQuat_LeftLowerLeg = rawQuatFile.avatarData[0].b9;
//
//		firstInvQuat_Pelvis = firstQuat_Pelvis.Inverse();
//		firstInvQuat_Chest = firstQuat_Chest.Inverse();
//		firstInvQuat_RightUpperArm = firstQuat_RightUpperArm.Inverse();
//		firstInvQuat_RightLowerArm = firstQuat_RightLowerArm.Inverse();
//		firstInvQuat_LeftUpperArm = firstQuat_LeftUpperArm.Inverse();
//		firstInvQuat_LeftLowerArm = firstQuat_LeftLowerArm.Inverse();
//		firstInvQuat_RightUpperLeg = firstQuat_RightUpperLeg.Inverse();
//		firstInvQuat_RightLowerLeg = firstQuat_RightLowerLeg.Inverse();
//		firstInvQuat_LeftUpperLeg = firstQuat_LeftUpperLeg.Inverse();
//		firstInvQuat_LeftLowerLeg = firstQuat_LeftLowerLeg.Inverse();
//
//
//
//		/*cout << "==============All joints first Quat==================" << endl;
//		cout << "PL:" << "\t" << rawQuatFile.avatarData[0].b0.mData[3] << "\t" << rawQuatFile.avatarData[0].b0.mData[0] << "\t" << rawQuatFile.avatarData[0].b0.mData[1] << "\t" << rawQuatFile.avatarData[0].b0.mData[2] << endl;
//		cout << "CH:" << "\t" << rawQuatFile.avatarData[0].b1.mData[3] << "\t" << rawQuatFile.avatarData[0].b1.mData[0] << "\t" << rawQuatFile.avatarData[0].b1.mData[1] << "\t" << rawQuatFile.avatarData[0].b1.mData[2] << endl;
//		cout << "RUA:" << "\t" << rawQuatFile.avatarData[0].b2.mData[3] << "\t" << rawQuatFile.avatarData[0].b2.mData[0] << "\t" << rawQuatFile.avatarData[0].b2.mData[1] << "\t" << rawQuatFile.avatarData[0].b2.mData[2] << endl;
//		cout << "RLA:" << "\t" << rawQuatFile.avatarData[0].b3.mData[3] << "\t" << rawQuatFile.avatarData[0].b3.mData[0] << "\t" << rawQuatFile.avatarData[0].b3.mData[1] << "\t" << rawQuatFile.avatarData[0].b3.mData[2] << endl;
//		cout << "LUA:" << "\t" << rawQuatFile.avatarData[0].b4.mData[3] << "\t" << rawQuatFile.avatarData[0].b4.mData[0] << "\t" << rawQuatFile.avatarData[0].b4.mData[1] << "\t" << rawQuatFile.avatarData[0].b4.mData[2] << endl;
//		cout << "LLA:" << "\t" << rawQuatFile.avatarData[0].b5.mData[3] << "\t" << rawQuatFile.avatarData[0].b5.mData[0] << "\t" << rawQuatFile.avatarData[0].b5.mData[1] << "\t" << rawQuatFile.avatarData[0].b5.mData[2] << endl;
//		cout << "RUL:" << "\t" << rawQuatFile.avatarData[0].b6.mData[3] << "\t" << rawQuatFile.avatarData[0].b6.mData[0] << "\t" << rawQuatFile.avatarData[0].b6.mData[1] << "\t" << rawQuatFile.avatarData[0].b6.mData[2] << endl;
//		cout << "RLL:" << "\t" << rawQuatFile.avatarData[0].b7.mData[3] << "\t" << rawQuatFile.avatarData[0].b7.mData[0] << "\t" << rawQuatFile.avatarData[0].b7.mData[1] << "\t" << rawQuatFile.avatarData[0].b7.mData[2] << endl;
//		cout << "LUL:" << "\t" << rawQuatFile.avatarData[0].b8.mData[3] << "\t" << rawQuatFile.avatarData[0].b8.mData[0] << "\t" << rawQuatFile.avatarData[0].b8.mData[1] << "\t" << rawQuatFile.avatarData[0].b8.mData[2] << endl;
//		cout << "LLL:" << "\t" << rawQuatFile.avatarData[0].b9.mData[3] << "\t" << rawQuatFile.avatarData[0].b9.mData[0] << "\t" << rawQuatFile.avatarData[0].b9.mData[1] << "\t" << rawQuatFile.avatarData[0].b9.mData[2] << endl;
//		cout << "=====================================================" << endl << endl;
//
//		cout << "=====All joints first Inverse Quat ==================" << endl;
//		cout << "PL:" << "\t" << firstInvQuat_Pelvis.mData[3] << "\t" << firstInvQuat_Pelvis.mData[0] << "\t" << firstInvQuat_Pelvis.mData[1] << "\t" << firstInvQuat_Pelvis.mData[2] << endl;
//		cout << "CH:" << "\t" << firstInvQuat_Chest.mData[3] << "\t" << firstInvQuat_Chest.mData[0] << "\t" << firstInvQuat_Chest.mData[1] << "\t" << firstInvQuat_Chest.mData[2] << endl;
//		cout << "RUA:" << "\t" << firstInvQuat_RightUpperArm.mData[3] << "\t" << firstInvQuat_RightUpperArm.mData[0] << "\t" << firstInvQuat_RightUpperArm.mData[1] << "\t" << firstInvQuat_RightUpperArm.mData[2] << endl;
//		cout << "RLA:" << "\t" << firstInvQuat_RightLowerArm.mData[3] << "\t" << firstInvQuat_RightLowerArm.mData[0] << "\t" << firstInvQuat_RightLowerArm.mData[1] << "\t" << firstInvQuat_RightLowerArm.mData[2] << endl;
//		cout << "LUA:" << "\t" << firstInvQuat_LeftUpperArm.mData[3] << "\t" << firstInvQuat_LeftUpperArm.mData[0] << "\t" << firstInvQuat_LeftUpperArm.mData[1] << "\t" << firstInvQuat_LeftUpperArm.mData[2] << endl;
//		cout << "LLA:" << "\t" << firstInvQuat_LeftLowerArm.mData[3] << "\t" << firstInvQuat_LeftLowerArm.mData[0] << "\t" << firstInvQuat_LeftLowerArm.mData[1] << "\t" << firstInvQuat_LeftLowerArm.mData[2] << endl;
//		cout << "RUL:" << "\t" << firstInvQuat_RightUpperLeg.mData[3] << "\t" << firstInvQuat_RightUpperLeg.mData[0] << "\t" << firstInvQuat_RightUpperLeg.mData[1] << "\t" << firstInvQuat_RightUpperLeg.mData[2] << endl;
//		cout << "RLL:" << "\t" << firstInvQuat_RightLowerLeg.mData[3] << "\t" << firstInvQuat_RightLowerLeg.mData[0] << "\t" << firstInvQuat_RightLowerLeg.mData[1] << "\t" << firstInvQuat_RightLowerLeg.mData[2] << endl;
//		cout << "LUL:" << "\t" << firstInvQuat_LeftUpperLeg.mData[3] << "\t" << firstInvQuat_LeftUpperLeg.mData[0] << "\t" << firstInvQuat_LeftUpperLeg.mData[1] << "\t" << firstInvQuat_LeftUpperLeg.mData[2] << endl;
//		cout << "LLL:" << "\t" << firstInvQuat_LeftLowerLeg.mData[3] << "\t" << firstInvQuat_LeftLowerLeg.mData[0] << "\t" << firstInvQuat_LeftLowerLeg.mData[1] << "\t" << firstInvQuat_LeftLowerLeg.mData[2] << endl;
//		cout << "=====================================================" << endl << endl;*/
//
//
//		for (int i = 0; i < rawQuatFile.noOfFrames; i++)
//		{
//			QuatData_PL[i] = rawQuatFile.avatarData[i].b0.mutiplication(firstInvQuat_Pelvis);
//			QuatData_CH[i] = rawQuatFile.avatarData[i].b1.mutiplication(firstInvQuat_Chest);
//
//			QuatData_RUA[i] = rawQuatFile.avatarData[i].b2.mutiplication(firstInvQuat_RightUpperArm);
//			QuatData_RLA[i] = rawQuatFile.avatarData[i].b3.mutiplication(firstInvQuat_RightLowerArm);
//			QuatData_LUA[i] = rawQuatFile.avatarData[i].b4.mutiplication(firstInvQuat_LeftUpperArm);
//			QuatData_LLA[i] = rawQuatFile.avatarData[i].b5.mutiplication(firstInvQuat_LeftLowerArm);
//			QuatData_RUL[i] = rawQuatFile.avatarData[i].b6.mutiplication(firstInvQuat_RightUpperLeg);
//			QuatData_RLL[i] = rawQuatFile.avatarData[i].b7.mutiplication(firstInvQuat_RightLowerLeg);
//			QuatData_LUL[i] = rawQuatFile.avatarData[i].b8.mutiplication(firstInvQuat_LeftUpperLeg);
//			QuatData_LLL[i] = rawQuatFile.avatarData[i].b9.mutiplication(firstInvQuat_LeftLowerLeg);
//
//			QuatData_PL[i].normalize();
//			QuatData_CH[i].normalize();
//			QuatData_RUA[i].normalize();
//			QuatData_RLA[i].normalize();
//			QuatData_LUA[i].normalize();
//			QuatData_LLA[i].normalize();
//			QuatData_RUL[i].normalize();
//			QuatData_RLL[i].normalize();
//			QuatData_LUL[i].normalize();
//			QuatData_LLL[i].normalize();
//
//			//cout << QuatData_PL[i].mData[3] << "\t" << QuatData_PL[i].mData[0] << "\t" << QuatData_PL[i].mData[2] << "\t" << QuatData_PL[i].mData[1] << endl;
//		}
//		/*cout << "=== all joints first Inverse Quaternion (MULTIPLIED) ==" << endl;
//		cout << "PL: " << QuatData_PL[0].mData[3] << "\t" << QuatData_PL[0].mData[0] << "\t" << QuatData_PL[0].mData[2] << "\t" << QuatData_PL[0].mData[1] << endl;
//		cout << "CH: " << QuatData_CH[0].mData[3] << "\t" << QuatData_CH[0].mData[0] << "\t" << QuatData_CH[0].mData[2] << "\t" << QuatData_CH[0].mData[1] << endl;
//		cout << "RUA " << QuatData_RUA[0].mData[3] << "\t" << QuatData_RUA[0].mData[0] << "\t" << QuatData_RUA[0].mData[2] << "\t" << QuatData_RUA[0].mData[1] << endl;
//		cout << "RLA " << QuatData_RLA[0].mData[3] << "\t" << QuatData_RLA[0].mData[0] << "\t" << QuatData_RLA[0].mData[2] << "\t" << QuatData_RLA[0].mData[1] << endl;
//		cout << "LUA " << QuatData_LUA[0].mData[3] << "\t" << QuatData_LUA[0].mData[0] << "\t" << QuatData_LUA[0].mData[2] << "\t" << QuatData_LUA[0].mData[1] << endl;
//		cout << "LLA " << QuatData_LLA[0].mData[3] << "\t" << QuatData_LLA[0].mData[0] << "\t" << QuatData_LLA[0].mData[2] << "\t" << QuatData_LLA[0].mData[1] << endl;
//		cout << "RUL " << QuatData_RUL[0].mData[3] << "\t" << QuatData_RUL[0].mData[0] << "\t" << QuatData_RUL[0].mData[2] << "\t" << QuatData_RUL[0].mData[1] << endl;
//		cout << "RLL " << QuatData_RLL[0].mData[3] << "\t" << QuatData_RLL[0].mData[0] << "\t" << QuatData_RLL[0].mData[2] << "\t" << QuatData_RLL[0].mData[1] << endl;
//		cout << "LUL " << QuatData_LUL[0].mData[3] << "\t" << QuatData_LUL[0].mData[0] << "\t" << QuatData_LUL[0].mData[2] << "\t" << QuatData_LUL[0].mData[1] << endl;
//		cout << "LLL " << QuatData_LLL[0].mData[3] << "\t" << QuatData_LLL[0].mData[0] << "\t" << QuatData_LLL[0].mData[2] << "\t" << QuatData_LLL[0].mData[1] << endl;
//		cout << "========================================================" << endl << endl;*/
//		for (int i = 0; i < rawQuatFile.noOfFrames; i++)
//		{
//			sfq_QuatData_PL[i] = QuatData_PL[i];
//
//			sfq_QuatData_CH[i] = sfq_QuatData_PL[i].Inverse().mutiplication(QuatData_CH[i]);
//
//			sfq_QuatData_RUA[i] = QuatData_CH[i].Inverse().mutiplication(QuatData_RUA[i]);
//			sfq_QuatData_RLA[i] = QuatData_RUA[i].Inverse().mutiplication(QuatData_RLA[i]);
//
//			sfq_QuatData_LUA[i] = QuatData_CH[i].Inverse().mutiplication(QuatData_LUA[i]);
//			sfq_QuatData_LLA[i] = QuatData_LUA[i].Inverse().mutiplication(QuatData_LLA[i]);
//
//			sfq_QuatData_RUL[i] = sfq_QuatData_PL[i].Inverse().mutiplication(QuatData_RUL[i]);
//			sfq_QuatData_RLL[i] = QuatData_RUL[i].Inverse().mutiplication(QuatData_RLL[i]);
//
//			sfq_QuatData_LUL[i] = sfq_QuatData_PL[i].Inverse().mutiplication(QuatData_LUL[i]);
//			sfq_QuatData_LLL[i] = QuatData_LUL[i].Inverse().mutiplication(QuatData_LLL[i]);
//
//			sfq_QuatData_PL[i].normalize();
//			sfq_QuatData_CH[i].normalize();
//
//			sfq_QuatData_RUA[i].normalize();
//			sfq_QuatData_RLA[i].normalize();
//
//			sfq_QuatData_LUA[i].normalize();
//			sfq_QuatData_LLA[i].normalize();
//
//			sfq_QuatData_RUL[i].normalize();
//			sfq_QuatData_RLL[i].normalize();
//
//			sfq_QuatData_LUL[i].normalize();
//			sfq_QuatData_LLL[i].normalize();
//		}
//		// Saving Raw Quat (Sensed Data) to sfq Format
//		sfqQuat_dataFile.open("c:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/motionDB/sensedMotion/toSFQ/rawQuat_to_sfq.txt");
//		sfqQuat_dataFile << "FULLBODY" << "\t" << "1" << endl;
//		sfqQuat_dataFile << "FRAMES" << "\t" << rawQuatFile.noOfFrames << endl;
//		for (int i = 0; i < rawQuatFile.noOfFrames; i++)
//		{
//			sfqQuat_dataFile <<
//				sfq_QuatData_PL[i].mData[3] << "\t" << sfq_QuatData_PL[i].mData[0] << "\t" << sfq_QuatData_PL[i].mData[1] << "\t" << sfq_QuatData_PL[i].mData[2] << "\t" <<
//				sfq_QuatData_CH[i].mData[3] << "\t" << sfq_QuatData_CH[i].mData[0] << "\t" << sfq_QuatData_CH[i].mData[1] << "\t" << sfq_QuatData_CH[i].mData[2] << "\t" <<
//				sfq_QuatData_RUA[i].mData[3] << "\t" << sfq_QuatData_RUA[i].mData[0] << "\t" << sfq_QuatData_RUA[i].mData[1] << "\t" << sfq_QuatData_RUA[i].mData[2] << "\t" <<
//				sfq_QuatData_RLA[i].mData[3] << "\t" << sfq_QuatData_RLA[i].mData[0] << "\t" << sfq_QuatData_RLA[i].mData[1] << "\t" << sfq_QuatData_RLA[i].mData[2] << "\t" <<
//				sfq_QuatData_LUA[i].mData[3] << "\t" << sfq_QuatData_LUA[i].mData[0] << "\t" << sfq_QuatData_LUA[i].mData[1] << "\t" << sfq_QuatData_LUA[i].mData[2] << "\t" <<
//				sfq_QuatData_LLA[i].mData[3] << "\t" << sfq_QuatData_LLA[i].mData[0] << "\t" << sfq_QuatData_LLA[i].mData[1] << "\t" << sfq_QuatData_LLA[i].mData[2] << "\t" <<
//				sfq_QuatData_RUL[i].mData[3] << "\t" << sfq_QuatData_RUL[i].mData[0] << "\t" << sfq_QuatData_RUL[i].mData[1] << "\t" << sfq_QuatData_RUA[i].mData[2] << "\t" <<
//				sfq_QuatData_RLL[i].mData[3] << "\t" << sfq_QuatData_RLL[i].mData[0] << "\t" << sfq_QuatData_RLL[i].mData[1] << "\t" << sfq_QuatData_RLL[i].mData[2] << "\t" <<
//				sfq_QuatData_LUL[i].mData[3] << "\t" << sfq_QuatData_LUL[i].mData[0] << "\t" << sfq_QuatData_LUL[i].mData[1] << "\t" << sfq_QuatData_LUL[i].mData[2] << "\t" <<
//				sfq_QuatData_LLL[i].mData[3] << "\t" << sfq_QuatData_LLL[i].mData[0] << "\t" << sfq_QuatData_LLL[i].mData[1] << "\t" << sfq_QuatData_LLL[i].mData[2] << endl;
//		}
//		sfqQuat_dataFile.close();
//
//		authorMode = false;
//		fileMode = true;
//		Quatnode_srq.nodecreate();
//		Quatnode_srq.loadQuaternion("c:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/motionDB/sensedMotion/toSFQ/rawQuat_to_sfq.txt");
//		Quatnode_srq.rotateaxis();
//		//Quatnode_srq.quattoeuler();
//		Quatnode_srq.quattoaxisangle();
//		Quatnode_srq.quattoHeight();
//
//		// For JointSphere Trajectories Data
//		Quatnode_srq.Calpts();
//
//		current_frames_srq = Quatnode_srq.frames;
//		loadframes_srq = Quatnode_srq.frames;
//	}
//	
//
//	
//}
//
//void EventQtSlotConnect::enableIK(bool checked)
//{
//	
//
//
//	if (checked)
//	{
//
//		rh_outlineTransform->Identity();
//		lh_outlineTransform->Identity();
//		rf_outlineTransform->Identity();
//		lf_outlineTransform->Identity();
//
//		if (skeleton_biped == 0)
//		{
//			rf_outlineActor->SetScale(0, 0, 0);
//			lf_outlineActor->SetScale(0, 0, 0);
//			rh_outlineActor->SetScale(0, 0, 0);
//			lh_outlineActor->SetScale(0, 0, 0);
//
//			renderer->RemoveActor(rf_outlineActor);
//			renderer->RemoveActor(lf_outlineActor);
//			renderer->RemoveActor(rh_outlineActor);
//			renderer->RemoveActor(lh_outlineActor);
//
//			renderWindow->Render();
//		}
//
//		if (skeleton_biped == 1 && ffIK_both==0 && ffIK_RF == 0 && ffIK_LF ==0)
//		{
//
//			vtkPolyData* rhOutliner = stickModel_rightHand_Reader->GetOutput();
//			rh_outlineFilter->SetInputData(rhOutliner);
//			rh_outlineTransform->SetInput(stickModel_rightHand_Transform);
//			rh_outlineMapper->SetInputConnection(rh_outlineFilter->GetOutputPort());
//			rh_outlineActor->SetMapper(rh_outlineMapper);
//
//			vtkPolyData* lhOutliner = stickModel_leftHand_Reader->GetOutput();
//			lh_outlineFilter->SetInputData(lhOutliner);
//			lh_outlineTransform->SetInput(stickModel_leftHand_Transform);
//			lh_outlineMapper->SetInputConnection(lh_outlineFilter->GetOutputPort());
//			lh_outlineActor->SetMapper(lh_outlineMapper);
//
//			vtkPolyData* rfOutliner = stickModel_rightFoot_Reader->GetOutput();
//			rf_outlineFilter->SetInputData(rfOutliner);
//			rf_outlineTransform->SetInput(stickModel_rightFoot_Transform);
//			rf_outlineMapper->SetInputConnection(rf_outlineFilter->GetOutputPort());
//			rf_outlineActor->SetMapper(rf_outlineMapper);
//
//			vtkPolyData* lfOutliner = stickModel_leftFoot_Reader->GetOutput();
//			lf_outlineFilter->SetInputData(lfOutliner);
//			lf_outlineTransform->SetInput(stickModel_leftFoot_Transform);
//			lf_outlineMapper->SetInputConnection(lf_outlineFilter->GetOutputPort());
//			lf_outlineActor->SetMapper(lf_outlineMapper);
//
//
//			rh_outlineActor->SetScale(0.95, 0.95, 0.95);
//			lh_outlineActor->SetScale(0.95, 0.95, 0.95);
//			rf_outlineActor->SetScale(50, 50, 50);
//			lf_outlineActor->SetScale(50, 50, 50);
//
//
//			cout << "Fullbody IK Enabled" << endl;
//			this->rhIK_checkBox->setEnabled(1);
//			this->lhIK_checkBox->setEnabled(1);
//			this->rfIK_checkBox->setEnabled(1);
//			this->lfIK_checkBox->setEnabled(1);
//
//			this->rhIK_checkBox->setChecked(1);
//			this->lhIK_checkBox->setChecked(1);
//			this->rfIK_checkBox->setChecked(1);
//			this->lfIK_checkBox->setChecked(1);
//
//			IKflag_Status = 1;
//
//			rh_outlineActor->GetProperty()->SetLineWidth(0.5);
//			rh_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			rh_outlineActor->SetUserTransform(stickModel_rightHand_Transform);
//			renderer->AddActor(rh_outlineActor);
//			rhIK_flag = 1;
//
//			lh_outlineActor->GetProperty()->SetLineWidth(0.5);
//			lh_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			lh_outlineActor->SetUserTransform(stickModel_leftHand_Transform);
//			renderer->AddActor(lh_outlineActor);
//			lhIK_flag = 1;
//
//			rf_outlineActor->GetProperty()->SetLineWidth(0.5);
//			rf_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			rf_outlineActor->SetUserTransform(stickModel_rightFoot_Transform);
//			renderer->AddActor(rf_outlineActor);
//			rfIK_flag = 1;
//
//			lf_outlineActor->GetProperty()->SetLineWidth(0.5);
//			lf_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			lf_outlineActor->SetUserTransform(stickModel_leftFoot_Transform);
//			renderer->AddActor(lf_outlineActor);
//			lfIK_flag = 1;
//
//			renderWindow->Render();
//			
//		}
//
//		if (skeleton_biped == 1 && ffIK_both == 1)
//		{
//
//			vtkPolyData* rhOutliner = IK_rightHand_Reader->GetOutput();
//			rh_outlineFilter->SetInputData(rhOutliner);
//			rh_outlineTransform->SetInput(IK_rightHand_Transform);
//			rh_outlineMapper->SetInputConnection(rh_outlineFilter->GetOutputPort());
//			rh_outlineActor->SetMapper(rh_outlineMapper);
//
//			vtkPolyData* lhOutliner = IK_leftHand_Reader->GetOutput();
//			lh_outlineFilter->SetInputData(lhOutliner);
//			lh_outlineTransform->SetInput(IK_leftHand_Transform);
//			lh_outlineMapper->SetInputConnection(lh_outlineFilter->GetOutputPort());
//			lh_outlineActor->SetMapper(lh_outlineMapper);
//
//			//vtkPolyData* rfOutliner = IK_rightFoot_Reader->GetOutput();
//			//rf_outlineFilter->SetInputData(rfOutliner);
//			//rf_outlineTransform->SetInput(IK_rightFoot_Transform);
//			//rf_outlineMapper->SetInputConnection(rf_outlineFilter->GetOutputPort());
//			//rf_outlineActor->SetMapper(rf_outlineMapper);
//
//			//vtkPolyData* lfOutliner = IK_leftFoot_Reader->GetOutput();
//			//lf_outlineFilter->SetInputData(lfOutliner);
//			//lf_outlineTransform->SetInput(IK_leftFoot_Transform);
//			//lf_outlineMapper->SetInputConnection(lf_outlineFilter->GetOutputPort());
//			//lf_outlineActor->SetMapper(lf_outlineMapper);
//
//
//			rh_outlineActor->SetScale(0.95, 0.95, 0.95);
//			lh_outlineActor->SetScale(0.95, 0.95, 0.95);
//
//			cout << "Fullbody IK Enabled" << endl;
//			this->rhIK_checkBox->setChecked(1);
//			this->lhIK_checkBox->setChecked(1);
//			this->rfIK_checkBox->setChecked(0);
//			this->lfIK_checkBox->setChecked(0);
//			this->rfIK_checkBox->setEnabled(0);
//			this->lfIK_checkBox->setEnabled(0);
//
//			IKflag_Status = 1;
//
//			rh_outlineActor->GetProperty()->SetLineWidth(0.5);
//			rh_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			rh_outlineActor->SetUserTransform(rh_outlineTransform);
//			renderer->AddActor(rh_outlineActor);
//			rhIK_flag = 1;
//
//			lh_outlineActor->GetProperty()->SetLineWidth(0.5);
//			lh_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			lh_outlineActor->SetUserTransform(lh_outlineTransform);
//			renderer->AddActor(lh_outlineActor);
//			lhIK_flag = 1;
//
//			renderWindow->Render();
//
//		}
//
//		if (skeleton_biped == 1 && ffIK_RF == 1)
//		{
//			vtkPolyData* rhOutliner = IK_rightHand_Reader->GetOutput();
//			rh_outlineFilter->SetInputData(rhOutliner);
//			rh_outlineTransform->SetInput(IK_rightHand_Transform);
//			rh_outlineMapper->SetInputConnection(rh_outlineFilter->GetOutputPort());
//			rh_outlineActor->SetMapper(rh_outlineMapper);
//
//			vtkPolyData* lhOutliner = IK_leftHand_Reader->GetOutput();
//			lh_outlineFilter->SetInputData(lhOutliner);
//			lh_outlineTransform->SetInput(IK_leftHand_Transform);
//			lh_outlineMapper->SetInputConnection(lh_outlineFilter->GetOutputPort());
//			lh_outlineActor->SetMapper(lh_outlineMapper);
//
//			vtkPolyData* lfOutliner = IK_freeLeftFoot_Reader->GetOutput();
//			lf_outlineFilter->SetInputData(lfOutliner);
//			lf_outlineTransform->SetInput(IK_freeLeftFoot_Transform);
//			lf_outlineMapper->SetInputConnection(lf_outlineFilter->GetOutputPort());
//			lf_outlineActor->SetMapper(lf_outlineMapper);
//
//
//			rh_outlineActor->SetScale(0.95, 0.95, 0.95);
//			lh_outlineActor->SetScale(0.95, 0.95, 0.95);
//			lf_outlineActor->SetScale(50, 50, 50);
//
//
//			cout << "Fullbody IK Enabled" << endl;
//			this->rfIK_checkBox->setEnabled(0);
//
//			this->rhIK_checkBox->setChecked(1);
//			this->lhIK_checkBox->setChecked(1);
//			this->rfIK_checkBox->setChecked(0);
//			this->lfIK_checkBox->setChecked(1);
//			this->rfIK_checkBox->setEnabled(0);
//
//			IKflag_Status = 1;
//
//			rh_outlineActor->GetProperty()->SetLineWidth(0.5);
//			rh_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			rh_outlineActor->SetUserTransform(rh_outlineTransform);
//			renderer->AddActor(rh_outlineActor);
//			rhIK_flag = 1;
//
//			lh_outlineActor->GetProperty()->SetLineWidth(0.5);
//			lh_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			lh_outlineActor->SetUserTransform(lh_outlineTransform);
//			renderer->AddActor(lh_outlineActor);
//			lhIK_flag = 1;
//
//			lf_outlineActor->GetProperty()->SetLineWidth(0.5);
//			lf_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			lf_outlineActor->SetUserTransform(lf_outlineTransform);
//			renderer->AddActor(lf_outlineActor);
//			lfIK_flag = 1;
//
//			renderWindow->Render();
//		
//		}
//
//		if (skeleton_biped == 1 && ffIK_LF == 1)
//		{
//			
//			vtkPolyData* rhOutliner = IK_rightHand_Reader->GetOutput();
//			rh_outlineFilter->SetInputData(rhOutliner);
//			rh_outlineTransform->SetInput(IK_rightHand_Transform);
//			rh_outlineMapper->SetInputConnection(rh_outlineFilter->GetOutputPort());
//			rh_outlineActor->SetMapper(rh_outlineMapper);
//
//			vtkPolyData* lhOutliner = IK_leftHand_Reader->GetOutput();
//			lh_outlineFilter->SetInputData(lhOutliner);
//			lh_outlineTransform->SetInput(IK_leftHand_Transform);
//			lh_outlineMapper->SetInputConnection(lh_outlineFilter->GetOutputPort());
//			lh_outlineActor->SetMapper(lh_outlineMapper);
//
//			vtkPolyData* lfOutliner = IK_freeRightFoot_Reader->GetOutput();
//			lf_outlineFilter->SetInputData(lfOutliner);
//			lf_outlineTransform->SetInput(IK_freeRightFoot_Transform);
//			lf_outlineMapper->SetInputConnection(lf_outlineFilter->GetOutputPort());
//			lf_outlineActor->SetMapper(lf_outlineMapper);
//
//
//
//			rh_outlineActor->SetScale(0.95, 0.95, 0.95);
//			lh_outlineActor->SetScale(0.95, 0.95, 0.95);
//			lf_outlineActor->SetScale(50, 50, 50);
//
//			cout << "Fullbody IK Enabled" << endl;
//			this->rhIK_checkBox->setEnabled(1);
//			this->lhIK_checkBox->setEnabled(1);
//			this->rfIK_checkBox->setEnabled(1);
//			this->lfIK_checkBox->setEnabled(0);
//
//			this->rhIK_checkBox->setChecked(1);
//			this->lhIK_checkBox->setChecked(1);
//			this->rfIK_checkBox->setChecked(1);
//			this->lfIK_checkBox->setChecked(0);
//
//			IKflag_Status = 1;
//
//			rh_outlineActor->GetProperty()->SetLineWidth(0.5);
//			rh_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			rh_outlineActor->SetUserTransform(rh_outlineTransform);
//			renderer->AddActor(rh_outlineActor);
//			rhIK_flag = 1;
//
//			lh_outlineActor->GetProperty()->SetLineWidth(0.5);
//			lh_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			lh_outlineActor->SetUserTransform(lh_outlineTransform);
//			renderer->AddActor(lh_outlineActor);
//			lhIK_flag = 1;
//
//			lf_outlineActor->GetProperty()->SetLineWidth(0.5);
//			lf_outlineActor->GetProperty()->SetColor(1, 1, 1);
//			lf_outlineActor->SetUserTransform(lf_outlineTransform);
//			renderer->AddActor(lf_outlineActor);
//			rfIK_flag = 1;
//
//			renderWindow->Render();
//
//		}
//	}
//	else
//	{
//		this->rhIK_checkBox->setChecked(0);
//		this->lhIK_checkBox->setChecked(0);
//		this->rfIK_checkBox->setChecked(0);
//		this->lfIK_checkBox->setChecked(0);
//
//		renderer->RemoveActor(rh_outlineActor);
//		rhIK_flag = 0;
//		renderer->RemoveActor(lh_outlineActor);
//		lhIK_flag = 0;
//		renderer->RemoveActor(rf_outlineActor);
//		rfIK_flag = 0;
//		renderer->RemoveActor(lf_outlineActor);
//		lfIK_flag = 0;
//		
//		IKflag_Status = 0;
//
//		renderWindow->Render();
//	}
//	renderWindow->Render();
//
//}
//void EventQtSlotConnect::resetIK()
//{
//	this->fullbodyIK_checkBox->setChecked(0);
//	this->rhIK_checkBox->setChecked(0);
//	this->lhIK_checkBox->setChecked(0);
//	this->rfIK_checkBox->setChecked(0);
//	this->lfIK_checkBox->setChecked(0);
//
//	renderer->RemoveActor(rh_outlineActor);
//	rhIK_flag = 0;
//	renderer->RemoveActor(lh_outlineActor);
//	lhIK_flag = 0;
//	renderer->RemoveActor(rf_outlineActor);
//	rfIK_flag = 0;
//	renderer->RemoveActor(lf_outlineActor);
//	lfIK_flag = 0;
//
//	IKflag_Status = 0;
//
//
//	renderWindow->Render();
//}
//
//
//void displayFixedLeftFoot_Model() 
//{
//	// IK_leftFoot
//	IK_leftFoot_objFile = "LF.obj";
//	IK_leftFoot_Reader->SetFileName(IK_leftFoot_objFile.c_str());
//	IK_leftFoot_Mapper->SetInputConnection(IK_leftFoot_Reader->GetOutputPort());
//	IK_leftFoot_Transform->Translate(5.0, 7.1, 0);
//	ffIK_F_x = 5.0;
//	ffIK_F_y = 7.1;
//	ffIK_F_z = 0;
//	IK_leftFoot_Actor->SetUserTransform(IK_leftFoot_Transform);
//	IK_leftFoot_Actor->SetMapper(IK_leftFoot_Mapper);
//	IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData()); //Moccasin
//	IK_leftFoot_Actor->SetScale(50.0);
//
//	vtkPolyData* ffIK_lfOutliner = IK_leftFoot_Reader->GetOutput();
//	ffIK_lf_outlineFilter->SetInputData(ffIK_lfOutliner);
//	ffIK_lf_outlineTransform->SetInput(IK_leftFoot_Transform);
//	ffIK_lf_outlineMapper->SetInputConnection(ffIK_lf_outlineFilter->GetOutputPort());
//	ffIK_lf_outlineActor->SetMapper(ffIK_lf_outlineMapper);
//	ffIK_lf_outlineActor->GetProperty()->SetLineWidth(0.5);
//	ffIK_lf_outlineActor->GetProperty()->SetColor(1, 1, 0);
//	ffIK_lf_outlineActor->SetScale(50, 50, 50);
//	ffIK_lf_outlineActor->SetUserTransform(ffIK_lf_outlineTransform);
//
//	//IK_leftLowerLeg
//	IK_leftLowerLeg_Source->SetRadius(1.5);
//	IK_leftLowerLeg_Source->SetHeight(16.0);
//	IK_leftLowerLeg_Source->SetResolution(20);
//	IK_leftLowerLeg_Source->SetCenter(0, IK_leftLowerLeg_Source->GetHeight() / 2, 0);
//	ffIK_LL_x = 0;
//	ffIK_LL_y = IK_leftLowerLeg_Source->GetRadius();
//	ffIK_LL_z = 0;
//
//	IK_leftLowerLeg_Mapper->SetInputConnection(IK_leftLowerLeg_Source->GetOutputPort());
//	IK_leftLowerLeg_Transform->SetInput(IK_leftFoot_Transform);
//	IK_leftLowerLeg_Actor->SetUserTransform(IK_leftLowerLeg_Transform);
//	IK_leftLowerLeg_Actor->SetMapper(IK_leftLowerLeg_Mapper);
//	IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftKnee
//	IK_leftKnee_Source->SetRadius(1.5);
//	IK_leftKnee_Source->SetPhiResolution(100);
//	IK_leftKnee_Source->SetThetaResolution(100);
//	IK_leftKnee_Source->SetCenter(*(IK_leftLowerLeg_Source->GetCenter()),
//		*(IK_leftLowerLeg_Source->GetCenter() + 1) + IK_leftLowerLeg_Source->GetHeight() / 2 + IK_leftKnee_Source->GetRadius(),
//		*(IK_leftLowerLeg_Source->GetCenter() + 2));
//	IK_leftKnee_Transform->SetInput(IK_leftLowerLeg_Transform);
//	IK_leftKnee_Actor->SetUserTransform(IK_leftKnee_Transform);
//	IK_leftKnee_Mapper->SetInputConnection(IK_leftKnee_Source->GetOutputPort());
//	IK_leftKnee_Actor->SetMapper(IK_leftKnee_Mapper);
//	IK_leftKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_leftUpperLeg
//	IK_leftUpperLeg_Source->SetRadius(1.5);
//	IK_leftUpperLeg_Source->SetHeight(17.0);
//	IK_leftUpperLeg_Source->SetResolution(20);
//	IK_leftUpperLeg_Source->SetCenter(*(IK_leftKnee_Source->GetCenter()),
//		*(IK_leftKnee_Source->GetCenter() + 1) + IK_leftUpperLeg_Source->GetHeight() / 2 + IK_leftKnee_Source->GetRadius(),
//		*(IK_leftKnee_Source->GetCenter() + 2));
//
//	ffIK_UL_x = *(IK_leftUpperLeg_Source->GetCenter());
//	ffIK_UL_y = *(IK_leftLowerLeg_Source->GetCenter() + 1) + IK_leftLowerLeg_Source->GetHeight() / 2 + IK_leftKnee_Source->GetRadius();
//	ffIK_UL_z = *(IK_leftUpperLeg_Source->GetCenter() + 2);
//
//	IK_leftUpperLeg_Mapper->SetInputConnection(IK_leftUpperLeg_Source->GetOutputPort());
//	IK_leftUpperLeg_Transform->SetInput(IK_leftKnee_Transform);
//	IK_leftUpperLeg_Actor->SetUserTransform(IK_leftUpperLeg_Transform);
//	IK_leftUpperLeg_Actor->SetMapper(IK_leftUpperLeg_Mapper);
//	IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftLegJoint
//	IK_leftLegJoint_Source->SetRadius(2.75);
//	IK_leftLegJoint_Source->SetPhiResolution(100);
//	IK_leftLegJoint_Source->SetThetaResolution(100);
//	IK_leftLegJoint_Source->SetCenter(*(IK_leftKnee_Source->GetCenter()),
//		*(IK_leftKnee_Source->GetCenter() + 1) + IK_leftUpperLeg_Source->GetHeight() + IK_leftUpperLeg_Source->GetRadius() + 2.75,
//		*(IK_leftKnee_Source->GetCenter() + 2));
//	IK_leftLegJoint_Transform->SetInput(IK_leftUpperLeg_Transform);
//	IK_leftLegJoint_Actor->SetUserTransform(IK_leftLegJoint_Transform);
//	IK_leftLegJoint_Mapper->SetInputConnection(IK_leftLegJoint_Source->GetOutputPort());
//	IK_leftLegJoint_Actor->SetMapper(IK_leftLegJoint_Mapper);
//	IK_leftLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//IK_pelvisJoint
//	IK_pelvisSource->SetRadius(5.0);
//	IK_pelvisSource->SetCenter(*(IK_leftLegJoint_Source->GetCenter()) - IK_leftLegJoint_Source->GetRadius() - 2.25,
//		*(IK_leftLegJoint_Source->GetCenter() + 1) + IK_leftLegJoint_Source->GetRadius() / 2 + 0.65,
//		*(IK_leftLegJoint_Source->GetCenter() + 2));
//	IK_pelvisSource->SetPhiResolution(100);
//	IK_pelvisSource->SetThetaResolution(100);
//	IK_pelvisTransform->SetInput(IK_leftLegJoint_Transform);
//	IK_pelvisMapper->SetInputConnection(IK_pelvisSource->GetOutputPort());
//	IK_pelvisActor->SetUserTransform(IK_pelvisTransform);
//	IK_pelvisActor->SetMapper(IK_pelvisMapper);
//	IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//IK_freeRightLegJoint
//	IK_freeRightLegJoint_Source->SetRadius(2.75);
//	IK_freeRightLegJoint_Source->SetPhiResolution(100);
//	IK_freeRightLegJoint_Source->SetThetaResolution(100);
//	IK_freeRightLegJoint_Source->SetCenter(*(IK_leftLegJoint_Source->GetCenter()) - 10,
//		*(IK_leftLegJoint_Source->GetCenter() + 1),
//		*(IK_leftLegJoint_Source->GetCenter() + 2));
//	IK_freeRightLegJoint_Transform->SetInput(IK_pelvisTransform);
//	IK_freeRightLegJoint_Actor->SetUserTransform(IK_freeRightLegJoint_Transform);
//	IK_freeRightLegJoint_Mapper->SetInputConnection(IK_freeRightLegJoint_Source->GetOutputPort());
//	IK_freeRightLegJoint_Actor->SetMapper(IK_freeRightLegJoint_Mapper);
//	IK_freeRightLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//IK_freeRightUpperLeg
//	IK_freeRightUpperLeg_Source->SetRadius(1.5);
//	IK_freeRightUpperLeg_Source->SetHeight(17.0);
//	IK_freeRightUpperLeg_Source->SetResolution(20);
//	IK_freeRightUpperLeg_Source->SetCenter(*(IK_freeRightLegJoint_Source->GetCenter()),
//		*(IK_freeRightLegJoint_Source->GetCenter() + 1) - IK_freeRightUpperLeg_Source->GetHeight() / 2 - IK_freeRightLegJoint_Source->GetRadius(),
//		*(IK_leftLegJoint_Source->GetCenter() + 2));
//	IK_freeRightUpperLeg_Mapper->SetInputConnection(IK_freeRightUpperLeg_Source->GetOutputPort());
//	IK_freeRightUpperLeg_Transform->SetInput(IK_freeRightLegJoint_Transform);
//	IK_freeRightUpperLeg_Actor->SetUserTransform(IK_freeRightUpperLeg_Transform);
//	IK_freeRightUpperLeg_Actor->SetMapper(IK_freeRightUpperLeg_Mapper);
//	IK_freeRightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//	freefootRUL_x = *(IK_freeRightLegJoint_Source->GetCenter());
//	freefootRUL_y = *(IK_freeRightLegJoint_Source->GetCenter() + 1);
//	freefootRUL_z = *(IK_freeRightLegJoint_Source->GetCenter() + 2);
//
//	//IK_freeRightKnee
//	IK_freeRightKnee_Source->SetRadius(1.5);
//	IK_freeRightKnee_Source->SetPhiResolution(100);
//	IK_freeRightKnee_Source->SetThetaResolution(100);
//	IK_freeRightKnee_Source->SetCenter(*(IK_freeRightUpperLeg_Source->GetCenter()),
//		*(IK_freeRightUpperLeg_Source->GetCenter() + 1) - IK_freeRightUpperLeg_Source->GetHeight() / 2 - IK_freeRightKnee_Source->GetRadius(),
//		*(IK_freeRightUpperLeg_Source->GetCenter() + 2));
//	IK_freeRightKnee_Transform->SetInput(IK_freeRightUpperLeg_Transform);
//	IK_freeRightKnee_Actor->SetUserTransform(IK_freeRightKnee_Transform);
//	IK_freeRightKnee_Mapper->SetInputConnection(IK_freeRightKnee_Source->GetOutputPort());
//	IK_freeRightKnee_Actor->SetMapper(IK_freeRightKnee_Mapper);
//	IK_freeRightKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_freeRightLowerLeg
//	IK_freeRightLowerLeg_Source->SetRadius(1.5);
//	IK_freeRightLowerLeg_Source->SetHeight(16.0);
//	IK_freeRightLowerLeg_Source->SetResolution(20);
//	IK_freeRightLowerLeg_Source->SetCenter(*(IK_freeRightKnee_Source->GetCenter()),
//		*(IK_freeRightKnee_Source->GetCenter() + 1) - IK_freeRightLowerLeg_Source->GetHeight() / 2 - IK_freeRightKnee_Source->GetRadius(),
//		*(IK_freeRightKnee_Source->GetCenter() + 2));
//
//	freefootRLL_x = *(IK_freeRightKnee_Source->GetCenter());
//	freefootRLL_y = *(IK_freeRightKnee_Source->GetCenter() + 1);
//	freefootRLL_z = *(IK_freeRightKnee_Source->GetCenter() + 2);
//
//	IK_freeRightLowerLeg_Mapper->SetInputConnection(IK_freeRightLowerLeg_Source->GetOutputPort());
//	IK_freeRightLowerLeg_Transform->SetInput(IK_freeRightKnee_Transform);
//	IK_freeRightLowerLeg_Actor->SetUserTransform(IK_freeRightLowerLeg_Transform);
//	IK_freeRightLowerLeg_Actor->SetMapper(IK_freeRightLowerLeg_Mapper);
//	IK_freeRightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	// IK_freeRightFoot
//	IK_freeRightFoot_objFile = "RF.obj";
//	IK_freeRightFoot_Reader->SetFileName(IK_freeRightFoot_objFile.c_str());
//	IK_freeRightFoot_Mapper->SetInputConnection(IK_freeRightFoot_Reader->GetOutputPort());
//	IK_freeRightFoot_Transform->Translate(*(IK_freeRightLowerLeg_Source->GetCenter()),
//		*(IK_freeRightLowerLeg_Source->GetCenter() + 1) - IK_freeRightLowerLeg_Source->GetHeight() / 2,
//		*(IK_freeRightLowerLeg_Source->GetCenter() + 2));
//	IK_freeRightFoot_Transform->SetInput(IK_freeRightLowerLeg_Transform);
//	IK_freeRightFoot_Actor->SetUserTransform(IK_freeRightFoot_Transform);
//	IK_freeRightFoot_Actor->SetMapper(IK_freeRightFoot_Mapper);
//	IK_freeRightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_freeRightFoot_Actor->SetScale(50.0);
//
//
//	//IK_Chest 0
//	IK_chest_0_Source->SetRadius(2.85);
//	IK_chest_0_Source->SetPhiResolution(100);
//	IK_chest_0_Source->SetThetaResolution(100);
//	IK_chest_0_Source->SetCenter(*(IK_pelvisSource->GetCenter()),
//		*(IK_pelvisSource->GetCenter() + 1) + IK_pelvisSource->GetRadius() + IK_chest_0_Source->GetRadius(), *(IK_pelvisSource->GetCenter() + 2));
//
//	ffIK_CH0_x = *(IK_pelvisSource->GetCenter());
//	ffIK_CH0_y = *(IK_pelvisSource->GetCenter() + 1);
//	ffIK_CH0_z = *(IK_pelvisSource->GetCenter() + 2);
//
//	IK_chest_0_Mapper->SetInputConnection(IK_chest_0_Source->GetOutputPort());
//	IK_chest_0_Transform->SetInput(IK_pelvisTransform);
//	IK_chest_0_Actor->SetUserTransform(IK_chest_0_Transform);
//	IK_chest_0_Actor->SetMapper(IK_chest_0_Mapper);
//	IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//chest_1
//	IK_chest_1_Source->SetRadius(2.85);
//	IK_chest_1_Source->SetPhiResolution(100);
//	IK_chest_1_Source->SetThetaResolution(100);
//	IK_chest_1_Source->SetCenter(*(IK_chest_0_Source->GetCenter()),
//		*(IK_chest_0_Source->GetCenter() + 1) + IK_chest_0_Source->GetRadius() + IK_chest_1_Source->GetRadius(),
//		*(IK_chest_0_Source->GetCenter() + 2));
//
//	ffIK_CH1_x = *(IK_chest_0_Source->GetCenter());
//	ffIK_CH1_y = *(IK_chest_0_Source->GetCenter() + 1);
//	ffIK_CH1_z = *(IK_chest_0_Source->GetCenter() + 2);
//
//	IK_chest_1_Transform->SetInput(IK_chest_0_Transform);
//	IK_chest_1_Actor->SetUserTransform(IK_chest_1_Transform);
//	IK_chest_1_Mapper->SetInputConnection(IK_chest_1_Source->GetOutputPort());
//	IK_chest_1_Actor->SetMapper(IK_chest_1_Mapper);
//	IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//
//	//IK_chest_2
//	IK_chest_2_Source->SetRadius(2.85);
//	IK_chest_2_Source->SetPhiResolution(100);
//	IK_chest_2_Source->SetThetaResolution(100);
//	IK_chest_2_Source->SetCenter(*(IK_chest_1_Source->GetCenter()),
//		*(IK_chest_1_Source->GetCenter() + 1) + IK_chest_1_Source->GetRadius() + IK_chest_2_Source->GetRadius(),
//		*(IK_chest_1_Source->GetCenter() + 2));
//
//	ffIK_CH2_x = *(IK_chest_1_Source->GetCenter());
//	ffIK_CH2_y = *(IK_chest_1_Source->GetCenter() + 1);
//	ffIK_CH2_z = *(IK_chest_1_Source->GetCenter() + 2);
//
//	IK_chest_2_Transform->SetInput(IK_chest_1_Transform);
//	IK_chest_2_Actor->SetUserTransform(IK_chest_2_Transform);
//	IK_chest_2_Mapper->SetInputConnection(IK_chest_2_Source->GetOutputPort());
//	IK_chest_2_Actor->SetMapper(IK_chest_2_Mapper);
//	IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_chest_3
//	IK_chest_3_Source->SetRadius(3.75);
//	IK_chest_3_Source->SetPhiResolution(100);
//	IK_chest_3_Source->SetThetaResolution(100);
//	IK_chest_3_Source->SetCenter(*(IK_chest_2_Source->GetCenter()),
//		*(IK_chest_2_Source->GetCenter() + 1) + IK_chest_2_Source->GetRadius() + IK_chest_3_Source->GetRadius(),
//		*(IK_chest_2_Source->GetCenter() + 2));
//	IK_chest_3_Transform->SetInput(IK_chest_2_Transform);
//	IK_chest_3_Actor->SetUserTransform(IK_chest_3_Transform);
//	IK_chest_3_Mapper->SetInputConnection(IK_chest_3_Source->GetOutputPort());
//	IK_chest_3_Actor->SetMapper(IK_chest_3_Mapper);
//	IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_head
//	IK_head_objFile = "humanHead1.obj";
//	const char* IK_headTexture_filename = "headmap.jpg";
//	IK_head_Reader->SetFileName(IK_head_objFile.c_str());
//	IK_head_Mapper->SetInputConnection(IK_head_Reader->GetOutputPort());
//
//	IK_head_Transform->Translate(*(IK_chest_3_Source->GetCenter()),
//		*(IK_chest_3_Source->GetCenter() + 1) + IK_chest_3_Source->GetRadius() + 0.05,
//		*(IK_chest_3_Source->GetCenter() + 2));
//	IK_head_Transform->SetInput(IK_chest_3_Transform);
//	IK_head_Actor->SetUserTransform(IK_head_Transform);
//	IK_head_Actor->SetMapper(IK_head_Mapper);
//	IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_head_Actor->SetScale(8);
//	IK_headTexture_Reader->SetFileName(IK_headTexture_filename);
//	// Apply the texture
//	IK_head_Texture->SetInputConnection(IK_headTexture_Reader->GetOutputPort());
//	IK_head_Actor->SetTexture(IK_head_Texture);
//
//
//	//IK_rightShoulderJoint
//	IK_rightShoulderJoint_Source->SetRadius(3.0);
//	IK_rightShoulderJoint_Source->SetPhiResolution(100);
//	IK_rightShoulderJoint_Source->SetThetaResolution(100);
//	IK_rightShoulderJoint_Source->SetCenter(*(IK_chest_3_Source->GetCenter()) - IK_chest_3_Source->GetRadius() - IK_rightShoulderJoint_Source->GetRadius(),
//		*(IK_chest_3_Source->GetCenter() + 1) - 1.0,
//		*(IK_chest_3_Source->GetCenter() + 2));
//
//	ffIK_Shoulder_x = *(IK_chest_3_Source->GetCenter()) - IK_chest_3_Source->GetRadius() - IK_rightShoulderJoint_Source->GetRadius();
//	ffIK_Shoulder_y = *(IK_chest_3_Source->GetCenter() + 1) - 1.0;
//	ffIK_Shoulder_z = *(IK_chest_3_Source->GetCenter() + 2);
//
//	IK_rightShoulderJoint_Transform->SetInput(IK_chest_3_Transform);
//	IK_rightShoulderJoint_Actor->SetUserTransform(IK_rightShoulderJoint_Transform);
//	IK_rightShoulderJoint_Mapper->SetInputConnection(IK_rightShoulderJoint_Source->GetOutputPort());
//	IK_rightShoulderJoint_Actor->SetMapper(IK_rightShoulderJoint_Mapper);
//	IK_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//
//	//IK_rightUpperArm
//	IK_rightUpperArm_Source->SetRadius(1.5);
//	IK_rightUpperArm_Source->SetHeight(12.0);
//	IK_rightUpperArm_Source->SetResolution(20);
//	IK_rightUpperArm_Source->SetCenter(*(IK_rightShoulderJoint_Source->GetCenter()),
//		*(IK_rightShoulderJoint_Source->GetCenter() + 1) - IK_rightUpperArm_Source->GetHeight() / 2 - IK_rightShoulderJoint_Source->GetRadius(),
//		*(IK_rightShoulderJoint_Source->GetCenter() + 2));
//	IK_rightUpperArm_Mapper->SetInputConnection(IK_rightUpperArm_Source->GetOutputPort());
//
//	ffIK_UA_x = *(IK_rightShoulderJoint_Source->GetCenter());
//	ffIK_UA_y = *(IK_rightShoulderJoint_Source->GetCenter() + 1);
//	ffIK_UA_z = *(IK_rightShoulderJoint_Source->GetCenter() + 2);
//
//
//	IK_rightUpperArm_Transform->SetInput(IK_rightShoulderJoint_Transform);
//	IK_rightUpperArm_Actor->SetUserTransform(IK_rightUpperArm_Transform);
//	IK_rightUpperArm_Actor->SetMapper(IK_rightUpperArm_Mapper);
//	IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightElbow
//	IK_rightElbow_Source->SetRadius(1.5);
//	IK_rightElbow_Source->SetPhiResolution(100);
//	IK_rightElbow_Source->SetThetaResolution(100);
//	IK_rightElbow_Source->SetCenter(*(IK_rightUpperArm_Source->GetCenter()),
//		*(IK_rightUpperArm_Source->GetCenter() + 1) - (IK_rightUpperArm_Source->GetHeight() / 2) - IK_rightElbow_Source->GetRadius(),
//		*(IK_rightUpperArm_Source->GetCenter() + 2));
//
//	IK_rightElbow_Transform->SetInput(IK_rightUpperArm_Transform);
//	IK_rightElbow_Actor->SetUserTransform(IK_rightElbow_Transform);
//	IK_rightElbow_Mapper->SetInputConnection(IK_rightElbow_Source->GetOutputPort());
//	IK_rightElbow_Actor->SetMapper(IK_rightElbow_Mapper);
//	IK_rightElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_rightLowerArm
//	IK_rightLowerArm_Source->SetRadius(1.5);
//	IK_rightLowerArm_Source->SetHeight(12.0);
//	IK_rightLowerArm_Source->SetResolution(20);
//	IK_rightLowerArm_Source->SetCenter(*(IK_rightElbow_Source->GetCenter()),
//		*(IK_rightElbow_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2 - IK_rightElbow_Source->GetRadius(),
//		*(IK_rightElbow_Source->GetCenter() + 2));
//
//	ffIK_LA_x = *(IK_rightElbow_Source->GetCenter());
//	ffIK_LA_y = *(IK_rightElbow_Source->GetCenter() + 1);
//	ffIK_LA_z = *(IK_rightElbow_Source->GetCenter() + 2);
//
//	IK_rightLowerArm_Mapper->SetInputConnection(IK_rightLowerArm_Source->GetOutputPort());
//	IK_rightLowerArm_Transform->SetInput(IK_rightElbow_Transform);
//	IK_rightLowerArm_Actor->SetUserTransform(IK_rightLowerArm_Transform);
//	IK_rightLowerArm_Actor->SetMapper(IK_rightLowerArm_Mapper);
//	IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightHand
//	IK_rightHand_objFile = "RH_G.obj";
//	IK_rightHand_Reader->SetFileName(IK_rightHand_objFile.c_str());
//	IK_rightHand_Mapper->SetInputConnection(IK_rightHand_Reader->GetOutputPort());
//
//	IK_rightHand_Transform->Translate(*(IK_rightLowerArm_Source->GetCenter()),
//		*(IK_rightLowerArm_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2,
//		*(IK_rightLowerArm_Source->GetCenter() + 2));
//
//	ffIK_H_x = *(IK_rightLowerArm_Source->GetCenter());
//	ffIK_H_y = *(IK_rightLowerArm_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2;
//	ffIK_H_z = *(IK_rightLowerArm_Source->GetCenter() + 2);
//
//	IK_rightHand_Transform->SetInput(IK_rightLowerArm_Transform);
//
//	IK_rightHand_Actor->SetUserTransform(IK_rightHand_Transform);
//
//	IK_rightHand_Actor->SetMapper(IK_rightHand_Mapper);
//	//IK_rightHand_Actor->RotateY(-7);
//	IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_rightHand_Actor->SetScale(0.95);
//
//	//IK_leftShoulderJoint
//	IK_leftShoulderJoint_Source->SetRadius(3.0);
//	IK_leftShoulderJoint_Source->SetPhiResolution(100);
//	IK_leftShoulderJoint_Source->SetThetaResolution(100);
//	IK_leftShoulderJoint_Source->SetCenter(*(IK_chest_3_Source->GetCenter()) + IK_chest_3_Source->GetRadius() + IK_leftShoulderJoint_Source->GetRadius(),
//		*(IK_chest_3_Source->GetCenter() + 1) - 1.0,
//		*(IK_chest_3_Source->GetCenter() + 2));
//
//	ffIK_LShoulder_x = *(IK_chest_3_Source->GetCenter()) + IK_chest_3_Source->GetRadius() + IK_leftShoulderJoint_Source->GetRadius();
//	ffIK_LShoulder_y = *(IK_chest_3_Source->GetCenter() + 1) - 1.0;
//	ffIK_LShoulder_z = *(IK_chest_3_Source->GetCenter() + 2);
//
//	IK_leftShoulderJoint_Transform->SetInput(IK_chest_3_Transform);
//	IK_leftShoulderJoint_Actor->SetUserTransform(IK_leftShoulderJoint_Transform);
//	IK_leftShoulderJoint_Mapper->SetInputConnection(IK_leftShoulderJoint_Source->GetOutputPort());
//	IK_leftShoulderJoint_Actor->SetMapper(IK_leftShoulderJoint_Mapper);
//	IK_leftShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_leftUpperArm
//	IK_leftUpperArm_Source->SetRadius(1.5);
//	IK_leftUpperArm_Source->SetHeight(12.0);
//	IK_leftUpperArm_Source->SetResolution(20);
//	IK_leftUpperArm_Source->SetCenter(*(IK_leftShoulderJoint_Source->GetCenter()),
//		*(IK_leftShoulderJoint_Source->GetCenter() + 1) - IK_leftUpperArm_Source->GetHeight() / 2 - IK_leftShoulderJoint_Source->GetRadius(),
//		*(IK_leftShoulderJoint_Source->GetCenter() + 2));
//	IK_leftUpperArm_Mapper->SetInputConnection(IK_leftUpperArm_Source->GetOutputPort());
//
//	ffIK_LUA_x = *(IK_leftShoulderJoint_Source->GetCenter());
//	ffIK_LUA_y = *(IK_leftShoulderJoint_Source->GetCenter() + 1);
//	ffIK_LUA_z = *(IK_leftShoulderJoint_Source->GetCenter() + 2);
//
//	IK_leftUpperArm_Transform->SetInput(IK_leftShoulderJoint_Transform);
//	IK_leftUpperArm_Actor->SetUserTransform(IK_leftUpperArm_Transform);
//	IK_leftUpperArm_Actor->SetMapper(IK_leftUpperArm_Mapper);
//	IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftElbow
//	IK_leftElbow_Source->SetRadius(1.5);
//	IK_leftElbow_Source->SetPhiResolution(100);
//	IK_leftElbow_Source->SetThetaResolution(100);
//	IK_leftElbow_Source->SetCenter(*(IK_leftUpperArm_Source->GetCenter()),
//		*(IK_leftUpperArm_Source->GetCenter() + 1) - (IK_leftUpperArm_Source->GetHeight() / 2) - IK_leftElbow_Source->GetRadius(),
//		*(IK_leftUpperArm_Source->GetCenter() + 2));
//
//	IK_leftElbow_Transform->SetInput(IK_leftUpperArm_Transform);
//	IK_leftElbow_Actor->SetUserTransform(IK_leftElbow_Transform);
//	IK_leftElbow_Mapper->SetInputConnection(IK_leftElbow_Source->GetOutputPort());
//	IK_leftElbow_Actor->SetMapper(IK_leftElbow_Mapper);
//	IK_leftElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_leftLowerArm
//	IK_leftLowerArm_Source->SetRadius(1.5);
//	IK_leftLowerArm_Source->SetHeight(12.0);
//	IK_leftLowerArm_Source->SetResolution(20);
//	IK_leftLowerArm_Source->SetCenter(*(IK_leftElbow_Source->GetCenter()),
//		*(IK_leftElbow_Source->GetCenter() + 1) - IK_leftLowerArm_Source->GetHeight() / 2 - IK_leftElbow_Source->GetRadius(),
//		*(IK_leftElbow_Source->GetCenter() + 2));
//
//	ffIK_LLA_x = *(IK_leftElbow_Source->GetCenter());
//	ffIK_LLA_y = *(IK_leftElbow_Source->GetCenter() + 1);
//	ffIK_LLA_z = *(IK_leftElbow_Source->GetCenter() + 2);
//
//	IK_leftLowerArm_Mapper->SetInputConnection(IK_leftLowerArm_Source->GetOutputPort());
//	IK_leftLowerArm_Transform->SetInput(IK_leftElbow_Transform);
//	IK_leftLowerArm_Actor->SetUserTransform(IK_leftLowerArm_Transform);
//	IK_leftLowerArm_Actor->SetMapper(IK_leftLowerArm_Mapper);
//	IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftHand
//	IK_leftHand_objFile = "LH_G.obj";
//	IK_leftHand_Reader->SetFileName(IK_leftHand_objFile.c_str());
//	IK_leftHand_Mapper->SetInputConnection(IK_leftHand_Reader->GetOutputPort());
//
//	IK_leftHand_Transform->Translate(*(IK_leftLowerArm_Source->GetCenter()),
//		*(IK_leftLowerArm_Source->GetCenter() + 1) - IK_leftLowerArm_Source->GetHeight() / 2 - 0.03,
//		*(IK_leftLowerArm_Source->GetCenter() + 2) - 0.05);
//
//	IK_leftHand_Transform->SetInput(IK_leftLowerArm_Transform);
//
//	IK_leftHand_Actor->SetUserTransform(IK_leftHand_Transform);
//
//	IK_leftHand_Actor->SetMapper(IK_leftHand_Mapper);
//	//IK_leftHand_Actor->RotateY(-7);
//	IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_leftHand_Actor->SetScale(0.95);
//
//
//
//	IK_rightShoulderJoint_Transform->Identity();
//	IK_rightShoulderJoint_Transform->Translate(ffIK_Shoulder_x, ffIK_Shoulder_y, 0);
//	IK_rightShoulderJoint_Transform->RotateWXYZ(-8, 0, 0, 1);
//	IK_rightShoulderJoint_Transform->Translate(-ffIK_Shoulder_x, -ffIK_Shoulder_y, 0);
//
//	IK_leftShoulderJoint_Transform->Identity();
//	IK_leftShoulderJoint_Transform->Translate(ffIK_LShoulder_x, ffIK_LShoulder_y, 0);
//	IK_leftShoulderJoint_Transform->RotateWXYZ(8, 0, 0, 1);
//	IK_leftShoulderJoint_Transform->Translate(-ffIK_LShoulder_x, -ffIK_LShoulder_y, 0);
//
//
//	renderer->AddActor(IK_leftFoot_Actor);
//	renderer->AddActor(ffIK_lf_outlineActor);
//	renderer->AddActor(IK_leftLowerLeg_Actor);
//	renderer->AddActor(IK_leftKnee_Actor);
//	renderer->AddActor(IK_leftUpperLeg_Actor);
//	renderer->AddActor(IK_leftLegJoint_Actor);
//	   
//	renderer->AddActor(IK_freeRightFoot_Actor);
//	renderer->AddActor(IK_freeRightLowerLeg_Actor);
//	renderer->AddActor(IK_freeRightKnee_Actor);
//	renderer->AddActor(IK_freeRightUpperLeg_Actor);
//	renderer->AddActor(IK_freeRightLegJoint_Actor);
//
//	renderer->AddActor(IK_pelvisActor);
//	renderer->AddActor(ffIK_lf_outlineActor);
//	renderer->AddActor(IK_chest_0_Actor);
//	renderer->AddActor(IK_chest_1_Actor);
//	renderer->AddActor(IK_chest_2_Actor);
//	renderer->AddActor(IK_chest_3_Actor);
//
//	renderer->AddActor(IK_head_Actor);
//
//	renderer->AddActor(IK_rightShoulderJoint_Actor);
//	renderer->AddActor(IK_rightUpperArm_Actor);
//	renderer->AddActor(IK_rightElbow_Actor);
//	renderer->AddActor(IK_rightLowerArm_Actor);
//	renderer->AddActor(IK_rightHand_Actor);
//
//	renderer->AddActor(IK_leftShoulderJoint_Actor);
//	renderer->AddActor(IK_leftUpperArm_Actor);
//	renderer->AddActor(IK_leftElbow_Actor);
//	renderer->AddActor(IK_leftLowerArm_Actor);
//	renderer->AddActor(IK_leftHand_Actor);
//}
//
//void displayFixedRightFoot_Model()
//{
//	// IK_rightFoot
//	IK_rightFoot_objFile = "RF.obj";
//	IK_rightFoot_Reader->SetFileName(IK_rightFoot_objFile.c_str());
//	IK_rightFoot_Mapper->SetInputConnection(IK_rightFoot_Reader->GetOutputPort());
//	IK_rightFoot_Transform->Translate(-5.0, 7.1, 0);
//	ffIK_F_x = -5.0;
//	ffIK_F_y = 7.1;
//	ffIK_F_z = 0;
//	IK_rightFoot_Actor->SetUserTransform(IK_rightFoot_Transform);
//	IK_rightFoot_Actor->SetMapper(IK_rightFoot_Mapper);
//	IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_rightFoot_Actor->SetScale(50.0);
//
//	vtkPolyData* ffIK_rfOutliner = IK_rightFoot_Reader->GetOutput();
//	ffIK_rf_outlineFilter->SetInputData(ffIK_rfOutliner);
//	ffIK_rf_outlineTransform->SetInput(IK_rightFoot_Transform);
//	ffIK_rf_outlineMapper->SetInputConnection(ffIK_rf_outlineFilter->GetOutputPort());
//	ffIK_rf_outlineActor->SetMapper(ffIK_rf_outlineMapper);
//	ffIK_rf_outlineActor->GetProperty()->SetLineWidth(0.5);
//	ffIK_rf_outlineActor->GetProperty()->SetColor(1, 1, 0);
//	ffIK_rf_outlineActor->SetScale(50, 50, 50);
//	ffIK_rf_outlineActor->SetUserTransform(ffIK_rf_outlineTransform);
//
//
//	//IK_rightLowerLeg
//	IK_rightLowerLeg_Source->SetRadius(1.5);
//	IK_rightLowerLeg_Source->SetHeight(16.0);
//	IK_rightLowerLeg_Source->SetResolution(20);
//	IK_rightLowerLeg_Source->SetCenter(0, IK_rightLowerLeg_Source->GetHeight() / 2, 0);
//	ffIK_LL_x = 0;
//	ffIK_LL_y = IK_rightLowerLeg_Source->GetRadius();
//	ffIK_LL_z = 0;
//
//	IK_rightLowerLeg_Mapper->SetInputConnection(IK_rightLowerLeg_Source->GetOutputPort());
//	IK_rightLowerLeg_Transform->SetInput(IK_rightFoot_Transform);
//	IK_rightLowerLeg_Actor->SetUserTransform(IK_rightLowerLeg_Transform);
//	IK_rightLowerLeg_Actor->SetMapper(IK_rightLowerLeg_Mapper);
//	IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightKnee
//	IK_rightKnee_Source->SetRadius(1.5);
//	IK_rightKnee_Source->SetPhiResolution(100);
//	IK_rightKnee_Source->SetThetaResolution(100);
//	IK_rightKnee_Source->SetCenter(*(IK_rightLowerLeg_Source->GetCenter()),
//		*(IK_rightLowerLeg_Source->GetCenter() + 1) + IK_rightLowerLeg_Source->GetHeight() / 2 + IK_rightKnee_Source->GetRadius(),
//		*(IK_rightLowerLeg_Source->GetCenter() + 2));
//	IK_rightKnee_Transform->SetInput(IK_rightLowerLeg_Transform);
//	IK_rightKnee_Actor->SetUserTransform(IK_rightKnee_Transform);
//	IK_rightKnee_Mapper->SetInputConnection(IK_rightKnee_Source->GetOutputPort());
//	IK_rightKnee_Actor->SetMapper(IK_rightKnee_Mapper);
//	IK_rightKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_rightUpperLeg
//	IK_rightUpperLeg_Source->SetRadius(1.5);
//	IK_rightUpperLeg_Source->SetHeight(17.0);
//	IK_rightUpperLeg_Source->SetResolution(20);
//	IK_rightUpperLeg_Source->SetCenter(*(IK_rightKnee_Source->GetCenter()),
//		*(IK_rightKnee_Source->GetCenter() + 1) + IK_rightUpperLeg_Source->GetHeight() / 2 + IK_rightKnee_Source->GetRadius(),
//		*(IK_rightKnee_Source->GetCenter() + 2));
//
//	ffIK_UL_x = *(IK_rightUpperLeg_Source->GetCenter());
//	ffIK_UL_y = *(IK_rightLowerLeg_Source->GetCenter() + 1) + IK_rightLowerLeg_Source->GetHeight() / 2 + IK_rightKnee_Source->GetRadius();
//	ffIK_UL_z = *(IK_rightUpperLeg_Source->GetCenter() + 2);
//
//	IK_rightUpperLeg_Mapper->SetInputConnection(IK_rightUpperLeg_Source->GetOutputPort());
//	IK_rightUpperLeg_Transform->SetInput(IK_rightKnee_Transform);
//	IK_rightUpperLeg_Actor->SetUserTransform(IK_rightUpperLeg_Transform);
//	IK_rightUpperLeg_Actor->SetMapper(IK_rightUpperLeg_Mapper);
//	IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightLegJoint
//	IK_rightLegJoint_Source->SetRadius(2.75);
//	IK_rightLegJoint_Source->SetPhiResolution(100);
//	IK_rightLegJoint_Source->SetThetaResolution(100);
//	IK_rightLegJoint_Source->SetCenter(*(IK_rightKnee_Source->GetCenter()),
//		*(IK_rightKnee_Source->GetCenter() + 1) + IK_rightUpperLeg_Source->GetHeight() + IK_rightUpperLeg_Source->GetRadius() + 2.75,
//		*(IK_rightKnee_Source->GetCenter() + 2));
//	IK_rightLegJoint_Transform->SetInput(IK_rightUpperLeg_Transform);
//	IK_rightLegJoint_Actor->SetUserTransform(IK_rightLegJoint_Transform);
//	IK_rightLegJoint_Mapper->SetInputConnection(IK_rightLegJoint_Source->GetOutputPort());
//	IK_rightLegJoint_Actor->SetMapper(IK_rightLegJoint_Mapper);
//	IK_rightLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//IK_pelvisJoint
//	IK_pelvisSource->SetRadius(5.0);
//	IK_pelvisSource->SetCenter(*(IK_rightLegJoint_Source->GetCenter()) + IK_rightLegJoint_Source->GetRadius() + 2.25,
//		*(IK_rightLegJoint_Source->GetCenter() + 1) + IK_rightLegJoint_Source->GetRadius() / 2 + 0.65,
//		*(IK_rightLegJoint_Source->GetCenter() + 2));
//	IK_pelvisSource->SetPhiResolution(100);
//	IK_pelvisSource->SetThetaResolution(100);
//	IK_pelvisTransform->SetInput(IK_rightLegJoint_Transform);
//	IK_pelvisMapper->SetInputConnection(IK_pelvisSource->GetOutputPort());
//	IK_pelvisActor->SetUserTransform(IK_pelvisTransform);
//	IK_pelvisActor->SetMapper(IK_pelvisMapper);
//	IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_freeLeftLegJoint
//	IK_freeLeftLegJoint_Source->SetRadius(2.75);
//	IK_freeLeftLegJoint_Source->SetPhiResolution(100);
//	IK_freeLeftLegJoint_Source->SetThetaResolution(100);
//	IK_freeLeftLegJoint_Source->SetCenter(*(IK_rightLegJoint_Source->GetCenter()) + 10,
//		*(IK_rightLegJoint_Source->GetCenter() + 1),
//		*(IK_rightLegJoint_Source->GetCenter() + 2));
//	IK_freeLeftLegJoint_Transform->SetInput(IK_pelvisTransform);
//	IK_freeLeftLegJoint_Actor->SetUserTransform(IK_freeLeftLegJoint_Transform);
//	IK_freeLeftLegJoint_Mapper->SetInputConnection(IK_freeLeftLegJoint_Source->GetOutputPort());
//	IK_freeLeftLegJoint_Actor->SetMapper(IK_freeLeftLegJoint_Mapper);
//	IK_freeLeftLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//IK_freeLeftUpperLeg
//	IK_freeLeftUpperLeg_Source->SetRadius(1.5);
//	IK_freeLeftUpperLeg_Source->SetHeight(17.0);
//	IK_freeLeftUpperLeg_Source->SetResolution(20);
//	IK_freeLeftUpperLeg_Source->SetCenter(*(IK_freeLeftLegJoint_Source->GetCenter()),
//		*(IK_freeLeftLegJoint_Source->GetCenter() + 1) - IK_freeLeftUpperLeg_Source->GetHeight() / 2 - IK_freeLeftLegJoint_Source->GetRadius(),
//		*(IK_rightLegJoint_Source->GetCenter() + 2));
//
//	freefootLUL_x = *(IK_rightLegJoint_Source->GetCenter());
//	freefootLUL_y = *(IK_rightLegJoint_Source->GetCenter() + 1);
//	freefootLUL_z = *(IK_rightLegJoint_Source->GetCenter() + 2);
//
//	IK_freeLeftUpperLeg_Mapper->SetInputConnection(IK_freeLeftUpperLeg_Source->GetOutputPort());
//	IK_freeLeftUpperLeg_Transform->SetInput(IK_freeLeftLegJoint_Transform);
//	IK_freeLeftUpperLeg_Actor->SetUserTransform(IK_freeLeftUpperLeg_Transform);
//	IK_freeLeftUpperLeg_Actor->SetMapper(IK_freeLeftUpperLeg_Mapper);
//	IK_freeLeftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//
//	//IK_freeLeftKnee
//	IK_freeLeftKnee_Source->SetRadius(1.5);
//	IK_freeLeftKnee_Source->SetPhiResolution(100);
//	IK_freeLeftKnee_Source->SetThetaResolution(100);
//	IK_freeLeftKnee_Source->SetCenter(*(IK_freeLeftUpperLeg_Source->GetCenter()),
//		*(IK_freeLeftUpperLeg_Source->GetCenter() + 1) - IK_freeLeftUpperLeg_Source->GetHeight() / 2 - IK_freeLeftKnee_Source->GetRadius(),
//		*(IK_freeLeftUpperLeg_Source->GetCenter() + 2));
//	IK_freeLeftKnee_Transform->SetInput(IK_freeLeftUpperLeg_Transform);
//	IK_freeLeftKnee_Actor->SetUserTransform(IK_freeLeftKnee_Transform);
//	IK_freeLeftKnee_Mapper->SetInputConnection(IK_freeLeftKnee_Source->GetOutputPort());
//	IK_freeLeftKnee_Actor->SetMapper(IK_freeLeftKnee_Mapper);
//	IK_freeLeftKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_freeLeftLowerLeg
//	IK_freeLeftLowerLeg_Source->SetRadius(1.5);
//	IK_freeLeftLowerLeg_Source->SetHeight(16.0);
//	IK_freeLeftLowerLeg_Source->SetResolution(20);
//	IK_freeLeftLowerLeg_Source->SetCenter(*(IK_freeLeftKnee_Source->GetCenter()),
//		*(IK_freeLeftKnee_Source->GetCenter() + 1) - IK_freeLeftLowerLeg_Source->GetHeight() / 2 - IK_freeLeftKnee_Source->GetRadius(),
//		*(IK_freeLeftKnee_Source->GetCenter() + 2));
//
//
//	freefootLLL_x = *(IK_freeLeftKnee_Source->GetCenter());
//	freefootLLL_y = *(IK_freeLeftKnee_Source->GetCenter() + 1);
//	freefootLLL_z = *(IK_freeLeftKnee_Source->GetCenter() + 2);
//
//
//	IK_freeLeftLowerLeg_Mapper->SetInputConnection(IK_freeLeftLowerLeg_Source->GetOutputPort());
//	IK_freeLeftLowerLeg_Transform->SetInput(IK_freeLeftKnee_Transform);
//	IK_freeLeftLowerLeg_Actor->SetUserTransform(IK_freeLeftLowerLeg_Transform);
//	IK_freeLeftLowerLeg_Actor->SetMapper(IK_freeLeftLowerLeg_Mapper);
//	IK_freeLeftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	// IK_freeLeftFoot
//	IK_freeLeftFoot_objFile = "LF.obj";
//	IK_freeLeftFoot_Reader->SetFileName(IK_freeLeftFoot_objFile.c_str());
//	IK_freeLeftFoot_Mapper->SetInputConnection(IK_freeLeftFoot_Reader->GetOutputPort());
//	IK_freeLeftFoot_Transform->Translate(*(IK_freeLeftLowerLeg_Source->GetCenter()),
//		*(IK_freeLeftLowerLeg_Source->GetCenter() + 1) - IK_freeLeftLowerLeg_Source->GetHeight() / 2,
//		*(IK_freeLeftLowerLeg_Source->GetCenter() + 2));
//	IK_freeLeftFoot_Transform->SetInput(IK_freeLeftLowerLeg_Transform);
//	IK_freeLeftFoot_Actor->SetUserTransform(IK_freeLeftFoot_Transform);
//	IK_freeLeftFoot_Actor->SetMapper(IK_freeLeftFoot_Mapper);
//	IK_freeLeftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_freeLeftFoot_Actor->SetScale(50.0);
//
//
//	//IK_Chest 0
//	IK_chest_0_Source->SetRadius(2.85);
//	IK_chest_0_Source->SetPhiResolution(100);
//	IK_chest_0_Source->SetThetaResolution(100);
//	IK_chest_0_Source->SetCenter(*(IK_pelvisSource->GetCenter()),
//		*(IK_pelvisSource->GetCenter() + 1) + IK_pelvisSource->GetRadius() + IK_chest_0_Source->GetRadius(), *(IK_pelvisSource->GetCenter() + 2));
//
//	ffIK_CH0_x = *(IK_pelvisSource->GetCenter());
//	ffIK_CH0_y = *(IK_pelvisSource->GetCenter() + 1);
//	ffIK_CH0_z = *(IK_pelvisSource->GetCenter() + 2);
//
//	IK_chest_0_Mapper->SetInputConnection(IK_chest_0_Source->GetOutputPort());
//	IK_chest_0_Transform->SetInput(IK_pelvisTransform);
//	IK_chest_0_Actor->SetUserTransform(IK_chest_0_Transform);
//	IK_chest_0_Actor->SetMapper(IK_chest_0_Mapper);
//	IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//chest_1
//	IK_chest_1_Source->SetRadius(2.85);
//	IK_chest_1_Source->SetPhiResolution(100);
//	IK_chest_1_Source->SetThetaResolution(100);
//	IK_chest_1_Source->SetCenter(*(IK_chest_0_Source->GetCenter()),
//		*(IK_chest_0_Source->GetCenter() + 1) + IK_chest_0_Source->GetRadius() + IK_chest_1_Source->GetRadius(),
//		*(IK_chest_0_Source->GetCenter() + 2));
//
//	ffIK_CH1_x = *(IK_chest_0_Source->GetCenter());
//	ffIK_CH1_y = *(IK_chest_0_Source->GetCenter() + 1);
//	ffIK_CH1_z = *(IK_chest_0_Source->GetCenter() + 2);
//
//	IK_chest_1_Transform->SetInput(IK_chest_0_Transform);
//	IK_chest_1_Actor->SetUserTransform(IK_chest_1_Transform);
//	IK_chest_1_Mapper->SetInputConnection(IK_chest_1_Source->GetOutputPort());
//	IK_chest_1_Actor->SetMapper(IK_chest_1_Mapper);
//	IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//
//	//IK_chest_2
//	IK_chest_2_Source->SetRadius(2.85);
//	IK_chest_2_Source->SetPhiResolution(100);
//	IK_chest_2_Source->SetThetaResolution(100);
//	IK_chest_2_Source->SetCenter(*(IK_chest_1_Source->GetCenter()),
//		*(IK_chest_1_Source->GetCenter() + 1) + IK_chest_1_Source->GetRadius() + IK_chest_2_Source->GetRadius(),
//		*(IK_chest_1_Source->GetCenter() + 2));
//
//	ffIK_CH2_x = *(IK_chest_1_Source->GetCenter());
//	ffIK_CH2_y = *(IK_chest_1_Source->GetCenter() + 1);
//	ffIK_CH2_z = *(IK_chest_1_Source->GetCenter() + 2);
//
//	IK_chest_2_Transform->SetInput(IK_chest_1_Transform);
//	IK_chest_2_Actor->SetUserTransform(IK_chest_2_Transform);
//	IK_chest_2_Mapper->SetInputConnection(IK_chest_2_Source->GetOutputPort());
//	IK_chest_2_Actor->SetMapper(IK_chest_2_Mapper);
//	IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_chest_3
//	IK_chest_3_Source->SetRadius(3.75);
//	IK_chest_3_Source->SetPhiResolution(100);
//	IK_chest_3_Source->SetThetaResolution(100);
//	IK_chest_3_Source->SetCenter(*(IK_chest_2_Source->GetCenter()),
//		*(IK_chest_2_Source->GetCenter() + 1) + IK_chest_2_Source->GetRadius() + IK_chest_3_Source->GetRadius(),
//		*(IK_chest_2_Source->GetCenter() + 2));
//	IK_chest_3_Transform->SetInput(IK_chest_2_Transform);
//	IK_chest_3_Actor->SetUserTransform(IK_chest_3_Transform);
//	IK_chest_3_Mapper->SetInputConnection(IK_chest_3_Source->GetOutputPort());
//	IK_chest_3_Actor->SetMapper(IK_chest_3_Mapper);
//	IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_head
//	IK_head_objFile = "humanHead1.obj";
//	const char* IK_headTexture_filename = "headmap.jpg";
//	IK_head_Reader->SetFileName(IK_head_objFile.c_str());
//	IK_head_Mapper->SetInputConnection(IK_head_Reader->GetOutputPort());
//
//	IK_head_Transform->Translate(*(IK_chest_3_Source->GetCenter()),
//		*(IK_chest_3_Source->GetCenter() + 1) + IK_chest_3_Source->GetRadius() + 0.05,
//		*(IK_chest_3_Source->GetCenter() + 2));
//	IK_head_Transform->SetInput(IK_chest_3_Transform);
//	IK_head_Actor->SetUserTransform(IK_head_Transform);
//	IK_head_Actor->SetMapper(IK_head_Mapper);
//	IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_head_Actor->SetScale(8);
//	IK_headTexture_Reader->SetFileName(IK_headTexture_filename);
//	// Apply the texture
//	IK_head_Texture->SetInputConnection(IK_headTexture_Reader->GetOutputPort());
//	IK_head_Actor->SetTexture(IK_head_Texture);
//
//
//	//IK_rightShoulderJoint
//	IK_rightShoulderJoint_Source->SetRadius(3.0);
//	IK_rightShoulderJoint_Source->SetPhiResolution(100);
//	IK_rightShoulderJoint_Source->SetThetaResolution(100);
//	IK_rightShoulderJoint_Source->SetCenter(*(IK_chest_3_Source->GetCenter()) - IK_chest_3_Source->GetRadius() - IK_rightShoulderJoint_Source->GetRadius(),
//		*(IK_chest_3_Source->GetCenter() + 1) - 1.0,
//		*(IK_chest_3_Source->GetCenter() + 2));
//
//	ffIK_Shoulder_x = *(IK_chest_3_Source->GetCenter()) - IK_chest_3_Source->GetRadius() - IK_rightShoulderJoint_Source->GetRadius();
//	ffIK_Shoulder_y = *(IK_chest_3_Source->GetCenter() + 1) - 1.0;
//	ffIK_Shoulder_z = *(IK_chest_3_Source->GetCenter() + 2);
//
//	IK_rightShoulderJoint_Transform->SetInput(IK_chest_3_Transform);
//	IK_rightShoulderJoint_Actor->SetUserTransform(IK_rightShoulderJoint_Transform);
//	IK_rightShoulderJoint_Mapper->SetInputConnection(IK_rightShoulderJoint_Source->GetOutputPort());
//	IK_rightShoulderJoint_Actor->SetMapper(IK_rightShoulderJoint_Mapper);
//	IK_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//
//	//IK_rightUpperArm
//	IK_rightUpperArm_Source->SetRadius(1.5);
//	IK_rightUpperArm_Source->SetHeight(12.0);
//	IK_rightUpperArm_Source->SetResolution(20);
//	IK_rightUpperArm_Source->SetCenter(*(IK_rightShoulderJoint_Source->GetCenter()),
//		*(IK_rightShoulderJoint_Source->GetCenter() + 1) - IK_rightUpperArm_Source->GetHeight() / 2 - IK_rightShoulderJoint_Source->GetRadius(),
//		*(IK_rightShoulderJoint_Source->GetCenter() + 2));
//	IK_rightUpperArm_Mapper->SetInputConnection(IK_rightUpperArm_Source->GetOutputPort());
//
//	ffIK_UA_x = *(IK_rightShoulderJoint_Source->GetCenter());
//	ffIK_UA_y = *(IK_rightShoulderJoint_Source->GetCenter() + 1);
//	ffIK_UA_z = *(IK_rightShoulderJoint_Source->GetCenter() + 2);
//
//
//	IK_rightUpperArm_Transform->SetInput(IK_rightShoulderJoint_Transform);
//	IK_rightUpperArm_Actor->SetUserTransform(IK_rightUpperArm_Transform);
//	IK_rightUpperArm_Actor->SetMapper(IK_rightUpperArm_Mapper);
//	IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightElbow
//	IK_rightElbow_Source->SetRadius(1.5);
//	IK_rightElbow_Source->SetPhiResolution(100);
//	IK_rightElbow_Source->SetThetaResolution(100);
//	IK_rightElbow_Source->SetCenter(*(IK_rightUpperArm_Source->GetCenter()),
//		*(IK_rightUpperArm_Source->GetCenter() + 1) - (IK_rightUpperArm_Source->GetHeight() / 2) - IK_rightElbow_Source->GetRadius(),
//		*(IK_rightUpperArm_Source->GetCenter() + 2));
//
//	IK_rightElbow_Transform->SetInput(IK_rightUpperArm_Transform);
//	IK_rightElbow_Actor->SetUserTransform(IK_rightElbow_Transform);
//	IK_rightElbow_Mapper->SetInputConnection(IK_rightElbow_Source->GetOutputPort());
//	IK_rightElbow_Actor->SetMapper(IK_rightElbow_Mapper);
//	IK_rightElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_rightLowerArm
//	IK_rightLowerArm_Source->SetRadius(1.5);
//	IK_rightLowerArm_Source->SetHeight(12.0);
//	IK_rightLowerArm_Source->SetResolution(20);
//	IK_rightLowerArm_Source->SetCenter(*(IK_rightElbow_Source->GetCenter()),
//		*(IK_rightElbow_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2 - IK_rightElbow_Source->GetRadius(),
//		*(IK_rightElbow_Source->GetCenter() + 2));
//
//	ffIK_LA_x = *(IK_rightElbow_Source->GetCenter());
//	ffIK_LA_y = *(IK_rightElbow_Source->GetCenter() + 1);
//	ffIK_LA_z = *(IK_rightElbow_Source->GetCenter() + 2);
//
//	IK_rightLowerArm_Mapper->SetInputConnection(IK_rightLowerArm_Source->GetOutputPort());
//	IK_rightLowerArm_Transform->SetInput(IK_rightElbow_Transform);
//	IK_rightLowerArm_Actor->SetUserTransform(IK_rightLowerArm_Transform);
//	IK_rightLowerArm_Actor->SetMapper(IK_rightLowerArm_Mapper);
//	IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightHand
//	IK_rightHand_objFile = "RH_G.obj";
//	IK_rightHand_Reader->SetFileName(IK_rightHand_objFile.c_str());
//	IK_rightHand_Mapper->SetInputConnection(IK_rightHand_Reader->GetOutputPort());
//
//	IK_rightHand_Transform->Translate(*(IK_rightLowerArm_Source->GetCenter()),
//		*(IK_rightLowerArm_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2,
//		*(IK_rightLowerArm_Source->GetCenter() + 2));
//
//	ffIK_H_x = *(IK_rightLowerArm_Source->GetCenter());
//	ffIK_H_y = *(IK_rightLowerArm_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2;
//	ffIK_H_z = *(IK_rightLowerArm_Source->GetCenter() + 2);
//
//	IK_rightHand_Transform->SetInput(IK_rightLowerArm_Transform);
//
//	IK_rightHand_Actor->SetUserTransform(IK_rightHand_Transform);
//
//	IK_rightHand_Actor->SetMapper(IK_rightHand_Mapper);
//	//IK_rightHand_Actor->RotateY(-7);
//	IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_rightHand_Actor->SetScale(0.95);
//
//	//IK_leftShoulderJoint
//	IK_leftShoulderJoint_Source->SetRadius(3.0);
//	IK_leftShoulderJoint_Source->SetPhiResolution(100);
//	IK_leftShoulderJoint_Source->SetThetaResolution(100);
//	IK_leftShoulderJoint_Source->SetCenter(*(IK_chest_3_Source->GetCenter()) + IK_chest_3_Source->GetRadius() + IK_leftShoulderJoint_Source->GetRadius(),
//		*(IK_chest_3_Source->GetCenter() + 1) - 1.0,
//		*(IK_chest_3_Source->GetCenter() + 2));
//
//	ffIK_LShoulder_x = *(IK_chest_3_Source->GetCenter()) + IK_chest_3_Source->GetRadius() + IK_leftShoulderJoint_Source->GetRadius();
//	ffIK_LShoulder_y = *(IK_chest_3_Source->GetCenter() + 1) - 1.0;
//	ffIK_LShoulder_z = *(IK_chest_3_Source->GetCenter() + 2);
//
//	IK_leftShoulderJoint_Transform->SetInput(IK_chest_3_Transform);
//	IK_leftShoulderJoint_Actor->SetUserTransform(IK_leftShoulderJoint_Transform);
//	IK_leftShoulderJoint_Mapper->SetInputConnection(IK_leftShoulderJoint_Source->GetOutputPort());
//	IK_leftShoulderJoint_Actor->SetMapper(IK_leftShoulderJoint_Mapper);
//	IK_leftShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_leftUpperArm
//	IK_leftUpperArm_Source->SetRadius(1.5);
//	IK_leftUpperArm_Source->SetHeight(12.0);
//	IK_leftUpperArm_Source->SetResolution(20);
//	IK_leftUpperArm_Source->SetCenter(*(IK_leftShoulderJoint_Source->GetCenter()),
//		*(IK_leftShoulderJoint_Source->GetCenter() + 1) - IK_leftUpperArm_Source->GetHeight() / 2 - IK_leftShoulderJoint_Source->GetRadius(),
//		*(IK_leftShoulderJoint_Source->GetCenter() + 2));
//	IK_leftUpperArm_Mapper->SetInputConnection(IK_leftUpperArm_Source->GetOutputPort());
//
//	ffIK_LUA_x = *(IK_leftShoulderJoint_Source->GetCenter());
//	ffIK_LUA_y = *(IK_leftShoulderJoint_Source->GetCenter() + 1);
//	ffIK_LUA_z = *(IK_leftShoulderJoint_Source->GetCenter() + 2);
//
//
//	IK_leftUpperArm_Transform->SetInput(IK_leftShoulderJoint_Transform);
//	IK_leftUpperArm_Actor->SetUserTransform(IK_leftUpperArm_Transform);
//	IK_leftUpperArm_Actor->SetMapper(IK_leftUpperArm_Mapper);
//	IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftElbow
//	IK_leftElbow_Source->SetRadius(1.5);
//	IK_leftElbow_Source->SetPhiResolution(100);
//	IK_leftElbow_Source->SetThetaResolution(100);
//	IK_leftElbow_Source->SetCenter(*(IK_leftUpperArm_Source->GetCenter()),
//		*(IK_leftUpperArm_Source->GetCenter() + 1) - (IK_leftUpperArm_Source->GetHeight() / 2) - IK_leftElbow_Source->GetRadius(),
//		*(IK_leftUpperArm_Source->GetCenter() + 2));
//
//	IK_leftElbow_Transform->SetInput(IK_leftUpperArm_Transform);
//	IK_leftElbow_Actor->SetUserTransform(IK_leftElbow_Transform);
//	IK_leftElbow_Mapper->SetInputConnection(IK_leftElbow_Source->GetOutputPort());
//	IK_leftElbow_Actor->SetMapper(IK_leftElbow_Mapper);
//	IK_leftElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_leftLowerArm
//	IK_leftLowerArm_Source->SetRadius(1.5);
//	IK_leftLowerArm_Source->SetHeight(12.0);
//	IK_leftLowerArm_Source->SetResolution(20);
//	IK_leftLowerArm_Source->SetCenter(*(IK_leftElbow_Source->GetCenter()),
//		*(IK_leftElbow_Source->GetCenter() + 1) - IK_leftLowerArm_Source->GetHeight() / 2 - IK_leftElbow_Source->GetRadius(),
//		*(IK_leftElbow_Source->GetCenter() + 2));
//
//	ffIK_LLA_x = *(IK_leftElbow_Source->GetCenter());
//	ffIK_LLA_y = *(IK_leftElbow_Source->GetCenter() + 1);
//	ffIK_LLA_z = *(IK_leftElbow_Source->GetCenter() + 2);
//
//
//	IK_leftLowerArm_Mapper->SetInputConnection(IK_leftLowerArm_Source->GetOutputPort());
//	IK_leftLowerArm_Transform->SetInput(IK_leftElbow_Transform);
//	IK_leftLowerArm_Actor->SetUserTransform(IK_leftLowerArm_Transform);
//	IK_leftLowerArm_Actor->SetMapper(IK_leftLowerArm_Mapper);
//	IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftHand
//	IK_leftHand_objFile = "LH_G.obj";
//	IK_leftHand_Reader->SetFileName(IK_leftHand_objFile.c_str());
//	IK_leftHand_Mapper->SetInputConnection(IK_leftHand_Reader->GetOutputPort());
//
//	IK_leftHand_Transform->Translate(*(IK_leftLowerArm_Source->GetCenter()),
//		*(IK_leftLowerArm_Source->GetCenter() + 1) - IK_leftLowerArm_Source->GetHeight() / 2 - 0.03,
//		*(IK_leftLowerArm_Source->GetCenter() + 2) - 0.05);
//
//	IK_leftHand_Transform->SetInput(IK_leftLowerArm_Transform);
//
//	IK_leftHand_Actor->SetUserTransform(IK_leftHand_Transform);
//
//	IK_leftHand_Actor->SetMapper(IK_leftHand_Mapper);
//	//IK_leftHand_Actor->RotateY(-7);
//	IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_leftHand_Actor->SetScale(0.95);
//
//
//
//	IK_rightShoulderJoint_Transform->Identity();
//	IK_rightShoulderJoint_Transform->Translate(ffIK_Shoulder_x, ffIK_Shoulder_y, 0);
//	IK_rightShoulderJoint_Transform->RotateWXYZ(-8, 0, 0, 1);
//	IK_rightShoulderJoint_Transform->Translate(-ffIK_Shoulder_x, -ffIK_Shoulder_y, 0);
//
//	IK_leftShoulderJoint_Transform->Identity();
//	IK_leftShoulderJoint_Transform->Translate(ffIK_LShoulder_x, ffIK_LShoulder_y, 0);
//	IK_leftShoulderJoint_Transform->RotateWXYZ(8, 0, 0, 1);
//	IK_leftShoulderJoint_Transform->Translate(-ffIK_LShoulder_x, -ffIK_LShoulder_y, 0);
//
//
//	renderer->AddActor(IK_rightFoot_Actor);
//	renderer->AddActor(ffIK_rf_outlineActor);
//	renderer->AddActor(IK_rightLowerLeg_Actor);
//	renderer->AddActor(IK_rightKnee_Actor);
//	renderer->AddActor(IK_rightUpperLeg_Actor);
//	renderer->AddActor(IK_rightLegJoint_Actor);
//
//	renderer->AddActor(IK_freeLeftFoot_Actor);
//	renderer->AddActor(IK_freeLeftLowerLeg_Actor);
//	renderer->AddActor(IK_freeLeftKnee_Actor);
//	renderer->AddActor(IK_freeLeftUpperLeg_Actor);
//	renderer->AddActor(IK_freeLeftLegJoint_Actor);
//
//	renderer->AddActor(IK_pelvisActor);
//
//	renderer->AddActor(IK_chest_0_Actor);
//	renderer->AddActor(IK_chest_1_Actor);
//	renderer->AddActor(IK_chest_2_Actor);
//	renderer->AddActor(IK_chest_3_Actor);
//
//	renderer->AddActor(IK_head_Actor);
//
//	renderer->AddActor(IK_rightShoulderJoint_Actor);
//	renderer->AddActor(IK_rightUpperArm_Actor);
//	renderer->AddActor(IK_rightElbow_Actor);
//	renderer->AddActor(IK_rightLowerArm_Actor);
//	renderer->AddActor(IK_rightHand_Actor);
//
//	renderer->AddActor(IK_leftShoulderJoint_Actor);
//	renderer->AddActor(IK_leftUpperArm_Actor);
//	renderer->AddActor(IK_leftElbow_Actor);
//	renderer->AddActor(IK_leftLowerArm_Actor);
//	renderer->AddActor(IK_leftHand_Actor);
//
//	//renderer->RemoveActor(ffIK_lf_outlineActor);
//
//}
//
//void displayFixedFoots_Model()
//{
//	/*IK_rightFoot_Transform->Identity();
//	ffIK_rf_outlineTransform->Identity();
//	IK_rightLowerLeg_Transform->Identity();
//	IK_rightKnee_Transform->Identity();
//	IK_rightUpperLeg_Transform->Identity();
//	IK_rightLegJoint_Transform->Identity();
//
//
//	IK_pelvisTransform->Identity();
//
//	IK_leftFoot_Transform->Identity();
//	ffIK_lf_outlineTransform->Identity();
//	IK_leftLowerLeg_Transform->Identity();
//	IK_leftKnee_Transform->Identity();
//	IK_leftUpperLeg_Transform->Identity();
//	IK_leftLegJoint_Transform->Identity();
//
//	IK_chest_0_Transform->Identity();
//	IK_chest_1_Transform->Identity();
//	IK_chest_2_Transform->Identity();
//	IK_chest_3_Transform->Identity();
//	IK_head_Transform->Identity();
//
//	IK_rightShoulderJoint_Transform->Identity();
//	IK_rightUpperArm_Transform->Identity();
//	IK_rightElbow_Transform->Identity();
//	IK_rightLowerArm_Transform->Identity();
//	IK_rightHand_Transform->Identity();
//
//	IK_leftShoulderJoint_Transform->Identity();
//	IK_leftUpperArm_Transform->Identity();
//	IK_leftElbow_Transform->Identity();
//	IK_leftLowerArm_Transform->Identity();
//	IK_leftHand_Transform->Identity();*/
//
//
//	// IK_rightFoot
//	IK_rightFoot_objFile = "RF.obj";
//	IK_rightFoot_Reader->SetFileName(IK_rightFoot_objFile.c_str());
//	IK_rightFoot_Mapper->SetInputConnection(IK_rightFoot_Reader->GetOutputPort());
//	IK_rightFoot_Transform->Translate(-5.0, 7.1, 0);
//	ffIK_F_x = -5.0;
//	ffIK_F_y = 7.1;
//	ffIK_F_z = 0;
//	IK_rightFoot_Actor->SetUserTransform(IK_rightFoot_Transform);
//	IK_rightFoot_Actor->SetMapper(IK_rightFoot_Mapper);
//	IK_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_rightFoot_Actor->SetScale(50.0);
//	
//	vtkPolyData* ffIK_rfOutliner = IK_rightFoot_Reader->GetOutput();
//	ffIK_rf_outlineFilter->SetInputData(ffIK_rfOutliner);
//	ffIK_rf_outlineTransform->SetInput(IK_rightFoot_Transform);
//	ffIK_rf_outlineMapper->SetInputConnection(ffIK_rf_outlineFilter->GetOutputPort());
//	ffIK_rf_outlineActor->SetMapper(ffIK_rf_outlineMapper);
//	ffIK_rf_outlineActor->GetProperty()->SetLineWidth(0.5);
//	ffIK_rf_outlineActor->GetProperty()->SetColor(1, 1, 0);
//	ffIK_rf_outlineActor->SetScale(50, 50, 50);
//	ffIK_rf_outlineActor->SetUserTransform(ffIK_rf_outlineTransform);
//
//
//	//IK_rightLowerLeg
//	IK_rightLowerLeg_Source->SetRadius(1.5);
//	IK_rightLowerLeg_Source->SetHeight(16.0);
//	IK_rightLowerLeg_Source->SetResolution(20);
//	IK_rightLowerLeg_Source->SetCenter(0, IK_rightLowerLeg_Source->GetHeight() / 2, 0);
//	ffIK_LL_x = 0;
//	ffIK_LL_y = IK_rightLowerLeg_Source->GetRadius();
//	ffIK_LL_z = 0;
//
//	IK_rightLowerLeg_Mapper->SetInputConnection(IK_rightLowerLeg_Source->GetOutputPort());
//	IK_rightLowerLeg_Transform->SetInput(IK_rightFoot_Transform);
//	IK_rightLowerLeg_Actor->SetUserTransform(IK_rightLowerLeg_Transform);
//	IK_rightLowerLeg_Actor->SetMapper(IK_rightLowerLeg_Mapper);
//	IK_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightKnee
//	IK_rightKnee_Source->SetRadius(1.5);
//	IK_rightKnee_Source->SetPhiResolution(100);
//	IK_rightKnee_Source->SetThetaResolution(100);
//	IK_rightKnee_Source->SetCenter(*(IK_rightLowerLeg_Source->GetCenter()),
//		*(IK_rightLowerLeg_Source->GetCenter() + 1) + IK_rightLowerLeg_Source->GetHeight() / 2 + IK_rightKnee_Source->GetRadius(),
//		*(IK_rightLowerLeg_Source->GetCenter() + 2));
//	IK_rightKnee_Transform->SetInput(IK_rightLowerLeg_Transform);
//	IK_rightKnee_Actor->SetUserTransform(IK_rightKnee_Transform);
//	IK_rightKnee_Mapper->SetInputConnection(IK_rightKnee_Source->GetOutputPort());
//	IK_rightKnee_Actor->SetMapper(IK_rightKnee_Mapper);
//	IK_rightKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_rightUpperLeg
//	IK_rightUpperLeg_Source->SetRadius(1.5);
//	IK_rightUpperLeg_Source->SetHeight(17.0);
//	IK_rightUpperLeg_Source->SetResolution(20);
//	IK_rightUpperLeg_Source->SetCenter(*(IK_rightKnee_Source->GetCenter()),
//		*(IK_rightKnee_Source->GetCenter() + 1) + IK_rightUpperLeg_Source->GetHeight() / 2 + IK_rightKnee_Source->GetRadius(),
//		*(IK_rightKnee_Source->GetCenter() + 2));
//
//	ffIK_UL_x = *(IK_rightUpperLeg_Source->GetCenter());
//	ffIK_UL_y = *(IK_rightLowerLeg_Source->GetCenter() + 1) + IK_rightLowerLeg_Source->GetHeight() / 2 + IK_rightKnee_Source->GetRadius();
//	ffIK_UL_z = *(IK_rightUpperLeg_Source->GetCenter() + 2);
//
//	IK_rightUpperLeg_Mapper->SetInputConnection(IK_rightUpperLeg_Source->GetOutputPort());
//	IK_rightUpperLeg_Transform->SetInput(IK_rightKnee_Transform);
//	IK_rightUpperLeg_Actor->SetUserTransform(IK_rightUpperLeg_Transform);
//	IK_rightUpperLeg_Actor->SetMapper(IK_rightUpperLeg_Mapper);
//	IK_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightLegJoint
//	IK_rightLegJoint_Source->SetRadius(2.75);
//	IK_rightLegJoint_Source->SetPhiResolution(100);
//	IK_rightLegJoint_Source->SetThetaResolution(100);
//	IK_rightLegJoint_Source->SetCenter(*(IK_rightKnee_Source->GetCenter()),
//		*(IK_rightKnee_Source->GetCenter() + 1) + IK_rightUpperLeg_Source->GetHeight() + IK_rightUpperLeg_Source->GetRadius() + 2.75,
//		*(IK_rightKnee_Source->GetCenter() + 2));
//	IK_rightLegJoint_Transform->SetInput(IK_rightUpperLeg_Transform);
//	IK_rightLegJoint_Actor->SetUserTransform(IK_rightLegJoint_Transform);
//	IK_rightLegJoint_Mapper->SetInputConnection(IK_rightLegJoint_Source->GetOutputPort());
//	IK_rightLegJoint_Actor->SetMapper(IK_rightLegJoint_Mapper);
//	IK_rightLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//IK_pelvisJoint
//	IK_pelvisSource->SetRadius(5.0);
//	IK_pelvisSource->SetCenter(*(IK_rightLegJoint_Source->GetCenter()) + IK_rightLegJoint_Source->GetRadius() + 2.25,
//		*(IK_rightLegJoint_Source->GetCenter() + 1) + IK_rightLegJoint_Source->GetRadius() / 2 + 0.65,
//		*(IK_rightLegJoint_Source->GetCenter() + 2));
//
//	ffIK_PL_x = *(IK_rightLegJoint_Source->GetCenter()) + IK_rightLegJoint_Source->GetRadius() + 2.25;
//	ffIK_PL_y = *(IK_rightLegJoint_Source->GetCenter() + 1) + IK_rightLegJoint_Source->GetRadius() / 2 + 0.65;
//	ffIK_PL_z = *(IK_rightLegJoint_Source->GetCenter() + 2);
//	IK_pelvisSource->SetPhiResolution(100);
//	IK_pelvisSource->SetThetaResolution(100);
//	IK_pelvisTransform->SetInput(IK_rightLegJoint_Transform);
//	IK_pelvisMapper->SetInputConnection(IK_pelvisSource->GetOutputPort());
//	IK_pelvisActor->SetUserTransform(IK_pelvisTransform);
//	IK_pelvisActor->SetMapper(IK_pelvisMapper);
//	IK_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//
//	
//	// IK_leftFoot
//	IK_leftFoot_objFile = "LF.obj";
//	IK_leftFoot_Reader->SetFileName(IK_leftFoot_objFile.c_str());
//	IK_leftFoot_Mapper->SetInputConnection(IK_leftFoot_Reader->GetOutputPort());
//	IK_leftFoot_Transform->Translate(5.0, 7.1, 0);
//	IK_leftFoot_Actor->SetUserTransform(IK_leftFoot_Transform);
//	IK_leftFoot_Actor->SetMapper(IK_leftFoot_Mapper);
//	IK_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_leftFoot_Actor->SetScale(50.0);
//
//
//	vtkPolyData* ffIK_lfOutliner = IK_leftFoot_Reader->GetOutput();
//	ffIK_lf_outlineFilter->SetInputData(ffIK_lfOutliner);
//	ffIK_lf_outlineTransform->SetInput(IK_leftFoot_Transform);
//	ffIK_lf_outlineMapper->SetInputConnection(ffIK_lf_outlineFilter->GetOutputPort());
//	ffIK_lf_outlineActor->SetMapper(ffIK_lf_outlineMapper);
//	ffIK_lf_outlineActor->GetProperty()->SetLineWidth(0.5);
//	ffIK_lf_outlineActor->GetProperty()->SetColor(1, 1, 0);
//	ffIK_lf_outlineActor->SetScale(50, 50, 50);
//	ffIK_lf_outlineActor->SetUserTransform(ffIK_lf_outlineTransform);
//
//	//IK_leftLowerLeg
//	IK_leftLowerLeg_Source->SetRadius(1.5);
//	IK_leftLowerLeg_Source->SetHeight(16.0);
//	IK_leftLowerLeg_Source->SetResolution(20);
//	IK_leftLowerLeg_Source->SetCenter(0, IK_leftLowerLeg_Source->GetHeight() / 2, 0);
//	IK_leftLowerLeg_Mapper->SetInputConnection(IK_leftLowerLeg_Source->GetOutputPort());
//	IK_leftLowerLeg_Transform->SetInput(IK_leftFoot_Transform);
//	IK_leftLowerLeg_Actor->SetUserTransform(IK_leftLowerLeg_Transform);
//	IK_leftLowerLeg_Actor->SetMapper(IK_leftLowerLeg_Mapper);
//	IK_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftKnee
//	IK_leftKnee_Source->SetRadius(1.5);
//	IK_leftKnee_Source->SetPhiResolution(100);
//	IK_leftKnee_Source->SetThetaResolution(100);
//	IK_leftKnee_Source->SetCenter(*(IK_leftLowerLeg_Source->GetCenter()),
//		*(IK_leftLowerLeg_Source->GetCenter() + 1) + IK_leftLowerLeg_Source->GetHeight() / 2 + IK_leftKnee_Source->GetRadius(),
//		*(IK_leftLowerLeg_Source->GetCenter() + 2));
//	IK_leftKnee_Transform->SetInput(IK_leftLowerLeg_Transform);
//	IK_leftKnee_Actor->SetUserTransform(IK_leftKnee_Transform);
//	IK_leftKnee_Mapper->SetInputConnection(IK_leftKnee_Source->GetOutputPort());
//	IK_leftKnee_Actor->SetMapper(IK_leftKnee_Mapper);
//	IK_leftKnee_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//	//IK_leftUpperLeg
//	IK_leftUpperLeg_Source->SetRadius(1.5);
//	IK_leftUpperLeg_Source->SetHeight(17.0);
//	IK_leftUpperLeg_Source->SetResolution(20);
//	IK_leftUpperLeg_Source->SetCenter(*(IK_leftKnee_Source->GetCenter()),
//		*(IK_leftKnee_Source->GetCenter() + 1) + IK_leftUpperLeg_Source->GetHeight() / 2 + IK_leftKnee_Source->GetRadius(),
//		*(IK_leftKnee_Source->GetCenter() + 2));
//	IK_leftUpperLeg_Mapper->SetInputConnection(IK_leftUpperLeg_Source->GetOutputPort());
//	IK_leftUpperLeg_Transform->SetInput(IK_leftKnee_Transform);
//	IK_leftUpperLeg_Actor->SetUserTransform(IK_leftUpperLeg_Transform);
//	IK_leftUpperLeg_Actor->SetMapper(IK_leftUpperLeg_Mapper);
//	IK_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftLegJoint
//	IK_leftLegJoint_Source->SetRadius(2.75);
//	IK_leftLegJoint_Source->SetPhiResolution(100);
//	IK_leftLegJoint_Source->SetThetaResolution(100);
//	IK_leftLegJoint_Source->SetCenter(*(IK_leftKnee_Source->GetCenter()),
//		*(IK_leftKnee_Source->GetCenter() + 1) + IK_leftUpperLeg_Source->GetHeight() + IK_leftUpperLeg_Source->GetRadius() + 2.75,
//		*(IK_leftKnee_Source->GetCenter() + 2));
//	IK_leftLegJoint_Transform->SetInput(IK_leftUpperLeg_Transform);
//	IK_leftLegJoint_Actor->SetUserTransform(IK_leftLegJoint_Transform);
//	IK_leftLegJoint_Mapper->SetInputConnection(IK_leftLegJoint_Source->GetOutputPort());
//	IK_leftLegJoint_Actor->SetMapper(IK_leftLegJoint_Mapper);
//	IK_leftLegJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//	
//
//	//IK_Chest 0
//	IK_chest_0_Source->SetRadius(2.85);
//	IK_chest_0_Source->SetPhiResolution(100);
//	IK_chest_0_Source->SetThetaResolution(100);
//	IK_chest_0_Source->SetCenter(*(IK_pelvisSource->GetCenter()),
//		*(IK_pelvisSource->GetCenter() + 1) + IK_pelvisSource->GetRadius() + IK_chest_0_Source->GetRadius(), *(IK_pelvisSource->GetCenter() + 2));
//
//	ffIK_CH0_x = *(IK_pelvisSource->GetCenter());
//	ffIK_CH0_y = *(IK_pelvisSource->GetCenter() + 1);
//	ffIK_CH0_z = *(IK_pelvisSource->GetCenter() + 2);
//
//	IK_chest_0_Mapper->SetInputConnection(IK_chest_0_Source->GetOutputPort());
//	IK_chest_0_Transform->SetInput(IK_pelvisTransform);
//	IK_chest_0_Actor->SetUserTransform(IK_chest_0_Transform);
//	IK_chest_0_Actor->SetMapper(IK_chest_0_Mapper);
//	IK_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//chest_1
//	IK_chest_1_Source->SetRadius(2.85);
//	IK_chest_1_Source->SetPhiResolution(100);
//	IK_chest_1_Source->SetThetaResolution(100);
//	IK_chest_1_Source->SetCenter(*(IK_chest_0_Source->GetCenter()),
//		*(IK_chest_0_Source->GetCenter() + 1) + IK_chest_0_Source->GetRadius() + IK_chest_1_Source->GetRadius(),
//		*(IK_chest_0_Source->GetCenter() + 2));
//
//	ffIK_CH1_x = *(IK_chest_0_Source->GetCenter());
//	ffIK_CH1_y = *(IK_chest_0_Source->GetCenter() + 1);
//	ffIK_CH1_z = *(IK_chest_0_Source->GetCenter() + 2);
//
//	IK_chest_1_Transform->SetInput(IK_chest_0_Transform);
//	IK_chest_1_Actor->SetUserTransform(IK_chest_1_Transform);
//	IK_chest_1_Mapper->SetInputConnection(IK_chest_1_Source->GetOutputPort());
//	IK_chest_1_Actor->SetMapper(IK_chest_1_Mapper);
//	IK_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//
//	//IK_chest_2
//	IK_chest_2_Source->SetRadius(2.85);
//	IK_chest_2_Source->SetPhiResolution(100);
//	IK_chest_2_Source->SetThetaResolution(100);
//	IK_chest_2_Source->SetCenter(*(IK_chest_1_Source->GetCenter()),
//		*(IK_chest_1_Source->GetCenter() + 1) + IK_chest_1_Source->GetRadius() + IK_chest_2_Source->GetRadius(),
//		*(IK_chest_1_Source->GetCenter() + 2));
//
//	ffIK_CH2_x = *(IK_chest_1_Source->GetCenter());
//	ffIK_CH2_y = *(IK_chest_1_Source->GetCenter() + 1);
//	ffIK_CH2_z = *(IK_chest_1_Source->GetCenter() + 2);
//
//	IK_chest_2_Transform->SetInput(IK_chest_1_Transform);
//	IK_chest_2_Actor->SetUserTransform(IK_chest_2_Transform);
//	IK_chest_2_Mapper->SetInputConnection(IK_chest_2_Source->GetOutputPort());
//	IK_chest_2_Actor->SetMapper(IK_chest_2_Mapper);
//	IK_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_chest_3
//	IK_chest_3_Source->SetRadius(3.75);
//	IK_chest_3_Source->SetPhiResolution(100);
//	IK_chest_3_Source->SetThetaResolution(100);
//	IK_chest_3_Source->SetCenter(*(IK_chest_2_Source->GetCenter()),
//		*(IK_chest_2_Source->GetCenter() + 1) + IK_chest_2_Source->GetRadius() + IK_chest_3_Source->GetRadius(),
//		*(IK_chest_2_Source->GetCenter() + 2));
//	IK_chest_3_Transform->SetInput(IK_chest_2_Transform);
//	IK_chest_3_Actor->SetUserTransform(IK_chest_3_Transform);
//	IK_chest_3_Mapper->SetInputConnection(IK_chest_3_Source->GetOutputPort());
//	IK_chest_3_Actor->SetMapper(IK_chest_3_Mapper);
//	IK_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_head
//	IK_head_objFile = "humanHead1.obj";
//	const char* IK_headTexture_filename = "headmap.jpg";
//	IK_head_Reader->SetFileName(IK_head_objFile.c_str());
//	IK_head_Mapper->SetInputConnection(IK_head_Reader->GetOutputPort());
//
//	IK_head_Transform->Translate(*(IK_chest_3_Source->GetCenter()),
//		*(IK_chest_3_Source->GetCenter() + 1) + IK_chest_3_Source->GetRadius() + 0.05,
//		*(IK_chest_3_Source->GetCenter() + 2));
//	IK_head_Transform->SetInput(IK_chest_3_Transform);
//	IK_head_Actor->SetUserTransform(IK_head_Transform);
//	IK_head_Actor->SetMapper(IK_head_Mapper);
//	IK_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_head_Actor->SetScale(8);
//	IK_headTexture_Reader->SetFileName(IK_headTexture_filename);
//	// Apply the texture
//	IK_head_Texture->SetInputConnection(IK_headTexture_Reader->GetOutputPort());
//	IK_head_Actor->SetTexture(IK_head_Texture);
//
//
//	//IK_rightShoulderJoint
//	IK_rightShoulderJoint_Source->SetRadius(3.0);
//	IK_rightShoulderJoint_Source->SetPhiResolution(100);
//	IK_rightShoulderJoint_Source->SetThetaResolution(100);
//	IK_rightShoulderJoint_Source->SetCenter(*(IK_chest_3_Source->GetCenter()) - IK_chest_3_Source->GetRadius() - IK_rightShoulderJoint_Source->GetRadius(),
//		*(IK_chest_3_Source->GetCenter() + 1) - 1.0,
//		*(IK_chest_3_Source->GetCenter() + 2));
//
//	ffIK_Shoulder_x = *(IK_chest_3_Source->GetCenter()) - IK_chest_3_Source->GetRadius() - IK_rightShoulderJoint_Source->GetRadius();
//	ffIK_Shoulder_y = *(IK_chest_3_Source->GetCenter() + 1) - 1.0;
//	ffIK_Shoulder_z = *(IK_chest_3_Source->GetCenter() + 2);
//
//	IK_rightShoulderJoint_Transform->SetInput(IK_chest_3_Transform);
//	IK_rightShoulderJoint_Actor->SetUserTransform(IK_rightShoulderJoint_Transform);
//	IK_rightShoulderJoint_Mapper->SetInputConnection(IK_rightShoulderJoint_Source->GetOutputPort());
//	IK_rightShoulderJoint_Actor->SetMapper(IK_rightShoulderJoint_Mapper);
//	IK_rightShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//
//	//IK_rightUpperArm
//	IK_rightUpperArm_Source->SetRadius(1.5);
//	IK_rightUpperArm_Source->SetHeight(12.0);
//	IK_rightUpperArm_Source->SetResolution(20);
//	IK_rightUpperArm_Source->SetCenter(*(IK_rightShoulderJoint_Source->GetCenter()),
//		*(IK_rightShoulderJoint_Source->GetCenter() + 1) - IK_rightUpperArm_Source->GetHeight() / 2 - IK_rightShoulderJoint_Source->GetRadius(),
//		*(IK_rightShoulderJoint_Source->GetCenter() + 2));
//	IK_rightUpperArm_Mapper->SetInputConnection(IK_rightUpperArm_Source->GetOutputPort());
//
//	ffIK_UA_x = *(IK_rightShoulderJoint_Source->GetCenter());
//	ffIK_UA_y = *(IK_rightShoulderJoint_Source->GetCenter() + 1);
//	ffIK_UA_z = *(IK_rightShoulderJoint_Source->GetCenter() + 2);
//
//
//	IK_rightUpperArm_Transform->SetInput(IK_rightShoulderJoint_Transform);
//	IK_rightUpperArm_Actor->SetUserTransform(IK_rightUpperArm_Transform);
//	IK_rightUpperArm_Actor->SetMapper(IK_rightUpperArm_Mapper);
//	IK_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightElbow
//	IK_rightElbow_Source->SetRadius(1.5);
//	IK_rightElbow_Source->SetPhiResolution(100);
//	IK_rightElbow_Source->SetThetaResolution(100);
//	IK_rightElbow_Source->SetCenter(*(IK_rightUpperArm_Source->GetCenter()),
//		*(IK_rightUpperArm_Source->GetCenter() + 1) - (IK_rightUpperArm_Source->GetHeight() / 2) - IK_rightElbow_Source->GetRadius(),
//		*(IK_rightUpperArm_Source->GetCenter() + 2));
//
//	IK_rightElbow_Transform->SetInput(IK_rightUpperArm_Transform);
//	IK_rightElbow_Actor->SetUserTransform(IK_rightElbow_Transform);
//	IK_rightElbow_Mapper->SetInputConnection(IK_rightElbow_Source->GetOutputPort());
//	IK_rightElbow_Actor->SetMapper(IK_rightElbow_Mapper);
//	IK_rightElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_rightLowerArm
//	IK_rightLowerArm_Source->SetRadius(1.5);
//	IK_rightLowerArm_Source->SetHeight(12.0);
//	IK_rightLowerArm_Source->SetResolution(20);
//	IK_rightLowerArm_Source->SetCenter(*(IK_rightElbow_Source->GetCenter()),
//		*(IK_rightElbow_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2 - IK_rightElbow_Source->GetRadius(),
//		*(IK_rightElbow_Source->GetCenter() + 2));
//
//	ffIK_LA_x = *(IK_rightElbow_Source->GetCenter());
//	ffIK_LA_y = *(IK_rightElbow_Source->GetCenter() + 1);
//	ffIK_LA_z = *(IK_rightElbow_Source->GetCenter() + 2);
//
//	IK_rightLowerArm_Mapper->SetInputConnection(IK_rightLowerArm_Source->GetOutputPort());
//	IK_rightLowerArm_Transform->SetInput(IK_rightElbow_Transform);
//	IK_rightLowerArm_Actor->SetUserTransform(IK_rightLowerArm_Transform);
//	IK_rightLowerArm_Actor->SetMapper(IK_rightLowerArm_Mapper);
//	IK_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_rightHand
//	IK_rightHand_objFile = "RH_G.obj";
//	IK_rightHand_Reader->SetFileName(IK_rightHand_objFile.c_str());
//	IK_rightHand_Mapper->SetInputConnection(IK_rightHand_Reader->GetOutputPort());
//
//	IK_rightHand_Transform->Translate(*(IK_rightLowerArm_Source->GetCenter()),
//		*(IK_rightLowerArm_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2,
//		*(IK_rightLowerArm_Source->GetCenter() + 2));
//
//	ffIK_H_x = *(IK_rightLowerArm_Source->GetCenter());
//	ffIK_H_y = *(IK_rightLowerArm_Source->GetCenter() + 1) - IK_rightLowerArm_Source->GetHeight() / 2;
//	ffIK_H_z = *(IK_rightLowerArm_Source->GetCenter() + 2);
//
//	IK_rightHand_Transform->SetInput(IK_rightLowerArm_Transform);
//
//	IK_rightHand_Actor->SetUserTransform(IK_rightHand_Transform);
//
//	IK_rightHand_Actor->SetMapper(IK_rightHand_Mapper);
//	//IK_rightHand_Actor->RotateY(-7);
//	IK_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_rightHand_Actor->SetScale(0.95);
//
//	//IK_leftShoulderJoint
//	IK_leftShoulderJoint_Source->SetRadius(3.0);
//	IK_leftShoulderJoint_Source->SetPhiResolution(100);
//	IK_leftShoulderJoint_Source->SetThetaResolution(100);
//	IK_leftShoulderJoint_Source->SetCenter(*(IK_chest_3_Source->GetCenter()) + IK_chest_3_Source->GetRadius() + IK_leftShoulderJoint_Source->GetRadius(),
//		*(IK_chest_3_Source->GetCenter() + 1) - 1.0,
//		*(IK_chest_3_Source->GetCenter() + 2));
//
//	ffIK_LShoulder_x = *(IK_chest_3_Source->GetCenter()) + IK_chest_3_Source->GetRadius() + IK_leftShoulderJoint_Source->GetRadius();
//	ffIK_LShoulder_y = *(IK_chest_3_Source->GetCenter() + 1) - 1.0;
//	ffIK_LShoulder_z = *(IK_chest_3_Source->GetCenter() + 2);
//
//	IK_leftShoulderJoint_Transform->SetInput(IK_chest_3_Transform);
//	IK_leftShoulderJoint_Actor->SetUserTransform(IK_leftShoulderJoint_Transform);
//	IK_leftShoulderJoint_Mapper->SetInputConnection(IK_leftShoulderJoint_Source->GetOutputPort());
//	IK_leftShoulderJoint_Actor->SetMapper(IK_leftShoulderJoint_Mapper);
//	IK_leftShoulderJoint_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_leftUpperArm
//	IK_leftUpperArm_Source->SetRadius(1.5);
//	IK_leftUpperArm_Source->SetHeight(12.0);
//	IK_leftUpperArm_Source->SetResolution(20);
//	IK_leftUpperArm_Source->SetCenter(*(IK_leftShoulderJoint_Source->GetCenter()),
//		*(IK_leftShoulderJoint_Source->GetCenter() + 1) - IK_leftUpperArm_Source->GetHeight() / 2 - IK_leftShoulderJoint_Source->GetRadius(),
//		*(IK_leftShoulderJoint_Source->GetCenter() + 2));
//	IK_leftUpperArm_Mapper->SetInputConnection(IK_leftUpperArm_Source->GetOutputPort());
//	ffIK_LUA_x = *(IK_leftShoulderJoint_Source->GetCenter());
//	ffIK_LUA_y = *(IK_leftShoulderJoint_Source->GetCenter()+1);
//	ffIK_LUA_z = *(IK_leftShoulderJoint_Source->GetCenter()+2);
//
//	IK_leftUpperArm_Transform->SetInput(IK_leftShoulderJoint_Transform);
//	IK_leftUpperArm_Actor->SetUserTransform(IK_leftUpperArm_Transform);
//	IK_leftUpperArm_Actor->SetMapper(IK_leftUpperArm_Mapper);
//	IK_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftElbow
//	IK_leftElbow_Source->SetRadius(1.5);
//	IK_leftElbow_Source->SetPhiResolution(100);
//	IK_leftElbow_Source->SetThetaResolution(100);
//	IK_leftElbow_Source->SetCenter(*(IK_leftUpperArm_Source->GetCenter()),
//		*(IK_leftUpperArm_Source->GetCenter() + 1) - (IK_leftUpperArm_Source->GetHeight() / 2) - IK_leftElbow_Source->GetRadius(),
//		*(IK_leftUpperArm_Source->GetCenter() + 2));
//
//	IK_leftElbow_Transform->SetInput(IK_leftUpperArm_Transform);
//	IK_leftElbow_Actor->SetUserTransform(IK_leftElbow_Transform);
//	IK_leftElbow_Mapper->SetInputConnection(IK_leftElbow_Source->GetOutputPort());
//	IK_leftElbow_Actor->SetMapper(IK_leftElbow_Mapper);
//	IK_leftElbow_Actor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//
//
//	//IK_leftLowerArm
//	IK_leftLowerArm_Source->SetRadius(1.5);
//	IK_leftLowerArm_Source->SetHeight(12.0);
//	IK_leftLowerArm_Source->SetResolution(20);
//	IK_leftLowerArm_Source->SetCenter(*(IK_leftElbow_Source->GetCenter()),
//		*(IK_leftElbow_Source->GetCenter() + 1) - IK_leftLowerArm_Source->GetHeight() / 2 - IK_leftElbow_Source->GetRadius(),
//		*(IK_leftElbow_Source->GetCenter() + 2));
//	
//	ffIK_LLA_x = *(IK_leftElbow_Source->GetCenter());
//	ffIK_LLA_y = *(IK_leftElbow_Source->GetCenter()+1);
//	ffIK_LLA_z = *(IK_leftElbow_Source->GetCenter()+2);
//	
//	IK_leftLowerArm_Mapper->SetInputConnection(IK_leftLowerArm_Source->GetOutputPort());
//	IK_leftLowerArm_Transform->SetInput(IK_leftElbow_Transform);
//	IK_leftLowerArm_Actor->SetUserTransform(IK_leftLowerArm_Transform);
//	IK_leftLowerArm_Actor->SetMapper(IK_leftLowerArm_Mapper);
//	IK_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//
//	//IK_leftHand
//	IK_leftHand_objFile = "LH_G.obj";
//	IK_leftHand_Reader->SetFileName(IK_leftHand_objFile.c_str());
//	IK_leftHand_Mapper->SetInputConnection(IK_leftHand_Reader->GetOutputPort());
//
//	IK_leftHand_Transform->Translate(*(IK_leftLowerArm_Source->GetCenter()),
//		*(IK_leftLowerArm_Source->GetCenter() + 1) - IK_leftLowerArm_Source->GetHeight() / 2 - 0.03,
//		*(IK_leftLowerArm_Source->GetCenter() + 2) - 0.05);
//
//	IK_leftHand_Transform->SetInput(IK_leftLowerArm_Transform);
//
//	IK_leftHand_Actor->SetUserTransform(IK_leftHand_Transform);
//
//	IK_leftHand_Actor->SetMapper(IK_leftHand_Mapper);
//	//IK_leftHand_Actor->RotateY(-7);
//	IK_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//	IK_leftHand_Actor->SetScale(0.95);
//
//
//
//	IK_rightShoulderJoint_Transform->Identity();
//	IK_rightShoulderJoint_Transform->Translate(ffIK_Shoulder_x, ffIK_Shoulder_y, 0);
//	IK_rightShoulderJoint_Transform->RotateWXYZ(-8, 0, 0, 1);
//	IK_rightShoulderJoint_Transform->Translate(-ffIK_Shoulder_x, -ffIK_Shoulder_y, 0);
//
//	IK_leftShoulderJoint_Transform->Identity();
//	IK_leftShoulderJoint_Transform->Translate(ffIK_LShoulder_x, ffIK_LShoulder_y, 0);
//	IK_leftShoulderJoint_Transform->RotateWXYZ(8, 0, 0, 1);
//	IK_leftShoulderJoint_Transform->Translate(-ffIK_LShoulder_x, -ffIK_LShoulder_y, 0);
//
//
//	renderer->AddActor(IK_rightFoot_Actor);
//
//	renderer->AddActor(IK_rightLowerLeg_Actor);
//	renderer->AddActor(IK_rightKnee_Actor);
//	renderer->AddActor(IK_rightUpperLeg_Actor);
//	renderer->AddActor(IK_rightLegJoint_Actor);
//
//	renderer->AddActor(IK_leftFoot_Actor);
//	renderer->AddActor(ffIK_rf_outlineActor);
//	renderer->AddActor(IK_leftLowerLeg_Actor);
//	renderer->AddActor(IK_leftKnee_Actor);
//	renderer->AddActor(IK_leftUpperLeg_Actor);
//	renderer->AddActor(IK_leftLegJoint_Actor);
//
//	renderer->AddActor(IK_pelvisActor);
//	renderer->AddActor(ffIK_lf_outlineActor);
//	renderer->AddActor(IK_chest_0_Actor);
//	renderer->AddActor(IK_chest_1_Actor);
//	renderer->AddActor(IK_chest_2_Actor);
//	renderer->AddActor(IK_chest_3_Actor);
//
//	renderer->AddActor(IK_head_Actor);
//
//	renderer->AddActor(IK_rightShoulderJoint_Actor);
//	renderer->AddActor(IK_rightUpperArm_Actor);
//	renderer->AddActor(IK_rightElbow_Actor);
//	renderer->AddActor(IK_rightLowerArm_Actor);
//	renderer->AddActor(IK_rightHand_Actor);
//
//	renderer->AddActor(IK_leftShoulderJoint_Actor);
//	renderer->AddActor(IK_leftUpperArm_Actor);
//	renderer->AddActor(IK_leftElbow_Actor);
//	renderer->AddActor(IK_leftLowerArm_Actor);
//	renderer->AddActor(IK_leftHand_Actor);
//
//}
//
//void EventQtSlotConnect::enableFreeFoots()
//{
//	cout << "Free Foots with End Effectors IK Enabled" << endl;
//	ffIK_both = 0;
//	ffIK_RF = 0;
//	ffIK_LF = 0;
//
//	renderer->RemoveActor(IK_rightFoot_Actor);
//	renderer->RemoveActor(ffIK_rf_outlineActor);
//	renderer->RemoveActor(IK_rightLowerLeg_Actor);
//	renderer->RemoveActor(IK_rightKnee_Actor);
//	renderer->RemoveActor(IK_rightUpperLeg_Actor);
//	renderer->RemoveActor(IK_rightLegJoint_Actor);
//	renderer->RemoveActor(IK_leftFoot_Actor);
//	renderer->RemoveActor(ffIK_lf_outlineActor);
//	renderer->RemoveActor(IK_leftLowerLeg_Actor);
//	renderer->RemoveActor(IK_leftKnee_Actor);
//	renderer->RemoveActor(IK_leftUpperLeg_Actor);
//	renderer->RemoveActor(IK_leftLegJoint_Actor);
//	renderer->RemoveActor(IK_pelvisActor);
//	renderer->RemoveActor(IK_chest_0_Actor);
//	renderer->RemoveActor(IK_chest_1_Actor);
//	renderer->RemoveActor(IK_chest_2_Actor);
//	renderer->RemoveActor(IK_chest_3_Actor);
//	renderer->RemoveActor(IK_head_Actor);
//	renderer->RemoveActor(IK_rightShoulderJoint_Actor);
//	renderer->RemoveActor(IK_rightUpperArm_Actor);
//	renderer->RemoveActor(IK_rightElbow_Actor);
//	renderer->RemoveActor(IK_rightLowerArm_Actor);
//	renderer->RemoveActor(IK_rightHand_Actor);
//	renderer->RemoveActor(IK_leftShoulderJoint_Actor);
//	renderer->RemoveActor(IK_leftUpperArm_Actor);
//	renderer->RemoveActor(IK_leftElbow_Actor);
//	renderer->RemoveActor(IK_leftLowerArm_Actor);
//	renderer->RemoveActor(IK_leftHand_Actor);
//
//	this->fullbodyIK_checkBox->setChecked(0);
//	this->rhIK_checkBox->setChecked(0);
//	this->lhIK_checkBox->setChecked(0);
//	this->rfIK_checkBox->setChecked(0);
//	this->lfIK_checkBox->setChecked(0);
//	IKflag_Status = 0;
//	renderer->RemoveActor(rh_outlineActor);
//	rhIK_flag = 0;
//	renderer->RemoveActor(lh_outlineActor);
//	lhIK_flag = 0;
//	renderer->RemoveActor(rf_outlineActor);
//	rfIK_flag = 0;
//	renderer->RemoveActor(lf_outlineActor);
//	lfIK_flag = 0;
//
//	renderer->RemoveActor(IK_freeLeftFoot_Actor);
//	renderer->RemoveActor(IK_freeLeftLowerLeg_Actor);
//	renderer->RemoveActor(IK_freeLeftKnee_Actor);
//	renderer->RemoveActor(IK_freeLeftUpperLeg_Actor);
//	renderer->RemoveActor(IK_freeLeftLegJoint_Actor);
//
//	renderer->RemoveActor(IK_freeRightFoot_Actor);
//	renderer->RemoveActor(IK_freeRightLowerLeg_Actor);
//	renderer->RemoveActor(IK_freeRightKnee_Actor);
//	renderer->RemoveActor(IK_freeRightUpperLeg_Actor);
//	renderer->RemoveActor(IK_freeRightLegJoint_Actor);
//	  					 
//	stickModel_pelvisTransform->Identity();
//	stickModel_chest_0_Transform->Identity();
//	stickModel_chest_1_Transform->Identity();
//	stickModel_chest_2_Transform->Identity();
//	stickModel_chest_3_Transform->Identity();
//	stickModel_head_Transform->Identity();
//	stickModel_rightShoulderJoint_Transform->Identity();
//	stickModel_rightUpperArm_Transform->Identity();
//	stickModel_rightElbow_Transform->Identity();
//	stickModel_rightLowerArm_Transform->Identity();
//	stickModel_rightHand_Transform->Identity();
//	stickModel_leftShoulderJoint_Transform->Identity();
//	stickModel_leftUpperArm_Transform->Identity();
//	stickModel_leftElbow_Transform->Identity();
//	stickModel_leftLowerArm_Transform->Identity();
//	stickModel_leftHand_Transform->Identity();
//	stickModel_rightLegJoint_Transform->Identity();
//	stickModel_rightUpperLeg_Transform->Identity();
//	stickModel_rightKnee_Transform->Identity();
//	stickModel_rightLowerLeg_Transform->Identity();
//	stickModel_rightFoot_Transform->Identity();
//	stickModel_leftLegJoint_Transform->Identity();
//	stickModel_leftUpperLeg_Transform->Identity();
//	stickModel_leftKnee_Transform->Identity();
//	stickModel_leftLowerLeg_Transform->Identity();
//	stickModel_leftFoot_Transform->Identity();
//
//
//	displayStick_Model();
//
//	renderWindow->Render();
//}
//void EventQtSlotConnect::enableFixedFoots()
//{
//	cout << "Fixed Foot with End Effectors IK Enabled" << endl;
//	if (skeleton_biped == 1)
//	{
//		ffIK_both = 1;
//		ffIK_RF = 0;
//		ffIK_LF = 0;
//
//		renderer->RemoveActor(stickModel_pelvisActor);
//		renderer->RemoveActor(stickModel_chest_0_Actor);
//		renderer->RemoveActor(stickModel_chest_1_Actor);
//		renderer->RemoveActor(stickModel_chest_2_Actor);
//		renderer->RemoveActor(stickModel_chest_3_Actor);
//		renderer->RemoveActor(stickModel_head_Actor);
//		renderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperArm_Actor);
//		renderer->RemoveActor(stickModel_rightElbow_Actor);
//		renderer->RemoveActor(stickModel_rightLowerArm_Actor);
//		renderer->RemoveActor(stickModel_rightHand_Actor);
//		renderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperArm_Actor);
//		renderer->RemoveActor(stickModel_leftElbow_Actor);
//		renderer->RemoveActor(stickModel_leftLowerArm_Actor);
//		renderer->RemoveActor(stickModel_leftHand_Actor);
//		renderer->RemoveActor(stickModel_rightLegJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_rightKnee_Actor);
//		renderer->RemoveActor(stickModel_rightLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_rightFoot_Actor);
//		renderer->RemoveActor(stickModel_leftLegJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_leftKnee_Actor);
//		renderer->RemoveActor(stickModel_leftLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_leftFoot_Actor);
//
//		this->fullbodyIK_checkBox->setChecked(0);
//		this->rhIK_checkBox->setChecked(0);
//		this->lhIK_checkBox->setChecked(0);
//		this->rfIK_checkBox->setChecked(0);
//		this->lfIK_checkBox->setChecked(0);
//		IKflag_Status = 0;
//		renderer->RemoveActor(rh_outlineActor);
//		rhIK_flag = 0;
//		renderer->RemoveActor(lh_outlineActor);
//		lhIK_flag = 0;
//		renderer->RemoveActor(rf_outlineActor);
//		rfIK_flag = 0;
//		renderer->RemoveActor(lf_outlineActor);
//		lfIK_flag = 0;
//		
//			   
//		renderer->RemoveActor(IK_freeLeftFoot_Actor);
//		renderer->RemoveActor(IK_freeLeftLowerLeg_Actor);
//		renderer->RemoveActor(IK_freeLeftKnee_Actor);
//		renderer->RemoveActor(IK_freeLeftUpperLeg_Actor);
//		renderer->RemoveActor(IK_freeLeftLegJoint_Actor);
//		
//		renderer->RemoveActor(IK_freeRightFoot_Actor);
//		renderer->RemoveActor(IK_freeRightLowerLeg_Actor);
//		renderer->RemoveActor(IK_freeRightKnee_Actor);
//		renderer->RemoveActor(IK_freeRightUpperLeg_Actor);
//		renderer->RemoveActor(IK_freeRightLegJoint_Actor);
//
//		IK_rightFoot_Transform->Identity();
//		ffIK_rf_outlineTransform->Identity();
//		IK_rightLowerLeg_Transform->Identity();
//		IK_rightKnee_Transform->Identity();
//		IK_rightUpperLeg_Transform->Identity();
//		IK_rightLegJoint_Transform->Identity();
//		
//		IK_pelvisTransform->Identity();
//
//		IK_leftFoot_Transform->Identity();
//		ffIK_lf_outlineTransform->Identity();
//		IK_leftLowerLeg_Transform->Identity();
//		IK_leftKnee_Transform->Identity();
//		IK_leftUpperLeg_Transform->Identity();
//		IK_leftLegJoint_Transform->Identity();
//
//		IK_chest_0_Transform->Identity();
//		IK_chest_1_Transform->Identity();
//		IK_chest_2_Transform->Identity();
//		IK_chest_3_Transform->Identity();
//		IK_head_Transform->Identity();
//
//		IK_rightShoulderJoint_Transform->Identity();
//		IK_rightUpperArm_Transform->Identity();
//		IK_rightElbow_Transform->Identity();
//		IK_rightLowerArm_Transform->Identity();
//		IK_rightHand_Transform->Identity();
//
//		IK_leftShoulderJoint_Transform->Identity();
//		IK_leftUpperArm_Transform->Identity();
//		IK_leftElbow_Transform->Identity();
//		IK_leftLowerArm_Transform->Identity();
//		IK_leftHand_Transform->Identity();
//
//
//
//		displayFixedFoots_Model();
//		renderWindow->Render();
//
//	}
//}
//void EventQtSlotConnect::fixedRightFoot()
//{
//	cout << "Fixed Right Foot and Free Left Foot with End Effectors IK Enabled" << endl;
//	if (skeleton_biped == 1)
//	{
//
//		ffIK_both = 0;
//		ffIK_RF = 1;
//		ffIK_LF = 0;
//		
//		renderer->RemoveActor(stickModel_pelvisActor);
//		renderer->RemoveActor(stickModel_chest_0_Actor);
//		renderer->RemoveActor(stickModel_chest_1_Actor);
//		renderer->RemoveActor(stickModel_chest_2_Actor);
//		renderer->RemoveActor(stickModel_chest_3_Actor);
//		renderer->RemoveActor(stickModel_head_Actor);
//		renderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperArm_Actor);
//		renderer->RemoveActor(stickModel_rightElbow_Actor);
//		renderer->RemoveActor(stickModel_rightLowerArm_Actor);
//		renderer->RemoveActor(stickModel_rightHand_Actor);
//		renderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperArm_Actor);
//		renderer->RemoveActor(stickModel_leftElbow_Actor);
//		renderer->RemoveActor(stickModel_leftLowerArm_Actor);
//		renderer->RemoveActor(stickModel_leftHand_Actor);
//		renderer->RemoveActor(stickModel_rightLegJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_rightKnee_Actor);
//		renderer->RemoveActor(stickModel_rightLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_rightFoot_Actor);
//		renderer->RemoveActor(stickModel_leftLegJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_leftKnee_Actor);
//		renderer->RemoveActor(stickModel_leftLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_leftFoot_Actor);
//
//
//		this->fullbodyIK_checkBox->setChecked(0);
//		this->rhIK_checkBox->setChecked(0);
//		this->lhIK_checkBox->setChecked(0);
//		this->rfIK_checkBox->setChecked(0);
//		this->lfIK_checkBox->setChecked(0);
//		IKflag_Status = 0;
//		renderer->RemoveActor(rh_outlineActor);
//		rhIK_flag = 0;
//		renderer->RemoveActor(lh_outlineActor);
//		lhIK_flag = 0;
//		renderer->RemoveActor(rf_outlineActor);
//		rfIK_flag = 0;
//		renderer->RemoveActor(lf_outlineActor);
//		lfIK_flag = 0;
//			   
//			   		 
//
//
//		renderer->RemoveActor(IK_rightFoot_Actor);
//		renderer->RemoveActor(ffIK_rf_outlineActor);
//		renderer->RemoveActor(IK_rightLowerLeg_Actor);
//		renderer->RemoveActor(IK_rightKnee_Actor);
//		renderer->RemoveActor(IK_rightUpperLeg_Actor);
//		renderer->RemoveActor(IK_rightLegJoint_Actor);
//		renderer->RemoveActor(IK_leftFoot_Actor);
//		renderer->RemoveActor(ffIK_lf_outlineActor);
//		renderer->RemoveActor(IK_leftLowerLeg_Actor);
//		renderer->RemoveActor(IK_leftKnee_Actor);
//		renderer->RemoveActor(IK_leftUpperLeg_Actor);
//		renderer->RemoveActor(IK_leftLegJoint_Actor);
//		renderer->RemoveActor(IK_pelvisActor);
//		renderer->RemoveActor(IK_chest_0_Actor);
//		renderer->RemoveActor(IK_chest_1_Actor);
//		renderer->RemoveActor(IK_chest_2_Actor);
//		renderer->RemoveActor(IK_chest_3_Actor);
//		renderer->RemoveActor(IK_head_Actor);
//		renderer->RemoveActor(IK_rightShoulderJoint_Actor);
//		renderer->RemoveActor(IK_rightUpperArm_Actor);
//		renderer->RemoveActor(IK_rightElbow_Actor);
//		renderer->RemoveActor(IK_rightLowerArm_Actor);
//		renderer->RemoveActor(IK_rightHand_Actor);
//		renderer->RemoveActor(IK_leftShoulderJoint_Actor);
//		renderer->RemoveActor(IK_leftUpperArm_Actor);
//		renderer->RemoveActor(IK_leftElbow_Actor);
//		renderer->RemoveActor(IK_leftLowerArm_Actor);
//		renderer->RemoveActor(IK_leftHand_Actor);
//
//		renderer->RemoveActor(IK_freeRightFoot_Actor);
//		renderer->RemoveActor(IK_freeRightLowerLeg_Actor);
//		renderer->RemoveActor(IK_freeRightKnee_Actor);
//		renderer->RemoveActor(IK_freeRightUpperLeg_Actor);
//		renderer->RemoveActor(IK_freeRightLegJoint_Actor);
//
//
//		IK_rightFoot_Transform->Identity();
//		ffIK_rf_outlineTransform->Identity();
//		IK_rightLowerLeg_Transform->Identity();
//		IK_rightKnee_Transform->Identity();
//		IK_rightUpperLeg_Transform->Identity();
//		IK_rightLegJoint_Transform->Identity();
//
//		IK_pelvisTransform->Identity();
//
//		IK_leftFoot_Transform->Identity();
//		ffIK_lf_outlineTransform->Identity();
//		IK_leftLowerLeg_Transform->Identity();
//		IK_leftKnee_Transform->Identity();
//		IK_leftUpperLeg_Transform->Identity();
//		IK_leftLegJoint_Transform->Identity();
//
//		IK_chest_0_Transform->Identity();
//		IK_chest_1_Transform->Identity();
//		IK_chest_2_Transform->Identity();
//		IK_chest_3_Transform->Identity();
//		IK_head_Transform->Identity();
//
//		IK_rightShoulderJoint_Transform->Identity();
//		IK_rightUpperArm_Transform->Identity();
//		IK_rightElbow_Transform->Identity();
//		IK_rightLowerArm_Transform->Identity();
//		IK_rightHand_Transform->Identity();
//
//		IK_leftShoulderJoint_Transform->Identity();
//		IK_leftUpperArm_Transform->Identity();
//		IK_leftElbow_Transform->Identity();
//		IK_leftLowerArm_Transform->Identity();
//		IK_leftHand_Transform->Identity();
//
//		IK_freeLeftFoot_Transform->Identity();
//		IK_freeLeftLowerLeg_Transform->Identity();
//		IK_freeLeftKnee_Transform->Identity();
//		IK_freeLeftUpperLeg_Transform->Identity();
//		IK_freeLeftLegJoint_Transform->Identity();
//
//
//		displayFixedRightFoot_Model();
//		renderWindow->Render();
//	}
//}
//void EventQtSlotConnect::fixedLeftFoot()
//{
//	cout << "Fixed Left Foot and Free Right Foot with End Effectors IK Enabled" << endl;
//	if (skeleton_biped == 1)
//	{
//
//		ffIK_both = 0;
//		ffIK_RF = 0;
//		ffIK_LF = 1;
//
//
//		renderer->RemoveActor(stickModel_pelvisActor);
//		renderer->RemoveActor(stickModel_chest_0_Actor);
//		renderer->RemoveActor(stickModel_chest_1_Actor);
//		renderer->RemoveActor(stickModel_chest_2_Actor);
//		renderer->RemoveActor(stickModel_chest_3_Actor);
//		renderer->RemoveActor(stickModel_head_Actor);
//		renderer->RemoveActor(stickModel_rightShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperArm_Actor);
//		renderer->RemoveActor(stickModel_rightElbow_Actor);
//		renderer->RemoveActor(stickModel_rightLowerArm_Actor);
//		renderer->RemoveActor(stickModel_rightHand_Actor);
//		renderer->RemoveActor(stickModel_leftShoulderJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperArm_Actor);
//		renderer->RemoveActor(stickModel_leftElbow_Actor);
//		renderer->RemoveActor(stickModel_leftLowerArm_Actor);
//		renderer->RemoveActor(stickModel_leftHand_Actor);
//		renderer->RemoveActor(stickModel_rightLegJoint_Actor);
//		renderer->RemoveActor(stickModel_rightUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_rightKnee_Actor);
//		renderer->RemoveActor(stickModel_rightLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_rightFoot_Actor);
//		renderer->RemoveActor(stickModel_leftLegJoint_Actor);
//		renderer->RemoveActor(stickModel_leftUpperLeg_Actor);
//		renderer->RemoveActor(stickModel_leftKnee_Actor);
//		renderer->RemoveActor(stickModel_leftLowerLeg_Actor);
//		renderer->RemoveActor(stickModel_leftFoot_Actor);
//		
//		this->fullbodyIK_checkBox->setChecked(0);
//		this->rhIK_checkBox->setChecked(0);
//		this->lhIK_checkBox->setChecked(0);
//		this->rfIK_checkBox->setChecked(0);
//		this->lfIK_checkBox->setChecked(0);
//		IKflag_Status = 0;
//		renderer->RemoveActor(rh_outlineActor);
//		rhIK_flag = 0;
//		renderer->RemoveActor(lh_outlineActor);
//		lhIK_flag = 0;
//		renderer->RemoveActor(rf_outlineActor);
//		rfIK_flag = 0;
//		renderer->RemoveActor(lf_outlineActor);
//		lfIK_flag = 0;
//
//
//		
//
//		
//
//		renderer->RemoveActor(IK_rightFoot_Actor);
//		renderer->RemoveActor(ffIK_rf_outlineActor);
//		renderer->RemoveActor(IK_rightLowerLeg_Actor);
//		renderer->RemoveActor(IK_rightKnee_Actor);
//		renderer->RemoveActor(IK_rightUpperLeg_Actor);
//		renderer->RemoveActor(IK_rightLegJoint_Actor);
//		renderer->RemoveActor(IK_leftFoot_Actor);
//		renderer->RemoveActor(ffIK_lf_outlineActor);
//		renderer->RemoveActor(IK_leftLowerLeg_Actor);
//		renderer->RemoveActor(IK_leftKnee_Actor);
//		renderer->RemoveActor(IK_leftUpperLeg_Actor);
//		renderer->RemoveActor(IK_leftLegJoint_Actor);
//		renderer->RemoveActor(IK_pelvisActor);
//		renderer->RemoveActor(IK_chest_0_Actor);
//		renderer->RemoveActor(IK_chest_1_Actor);
//		renderer->RemoveActor(IK_chest_2_Actor);
//		renderer->RemoveActor(IK_chest_3_Actor);
//		renderer->RemoveActor(IK_head_Actor);
//		renderer->RemoveActor(IK_rightShoulderJoint_Actor);
//		renderer->RemoveActor(IK_rightUpperArm_Actor);
//		renderer->RemoveActor(IK_rightElbow_Actor);
//		renderer->RemoveActor(IK_rightLowerArm_Actor);
//		renderer->RemoveActor(IK_rightHand_Actor);
//		renderer->RemoveActor(IK_leftShoulderJoint_Actor);
//		renderer->RemoveActor(IK_leftUpperArm_Actor);
//		renderer->RemoveActor(IK_leftElbow_Actor);
//		renderer->RemoveActor(IK_leftLowerArm_Actor);
//		renderer->RemoveActor(IK_leftHand_Actor);
//
//		renderer->RemoveActor(IK_freeLeftFoot_Actor);
//		renderer->RemoveActor(IK_freeLeftLowerLeg_Actor);
//		renderer->RemoveActor(IK_freeLeftKnee_Actor);
//		renderer->RemoveActor(IK_freeLeftUpperLeg_Actor);
//		renderer->RemoveActor(IK_freeLeftLegJoint_Actor);
//
//
//		IK_leftFoot_Transform->Identity();
//		ffIK_lf_outlineTransform->Identity();
//		IK_leftLowerLeg_Transform->Identity();
//		IK_leftKnee_Transform->Identity();
//		IK_leftUpperLeg_Transform->Identity();
//		IK_leftLegJoint_Transform->Identity();
//
//		IK_pelvisTransform->Identity();
//
//		IK_rightFoot_Transform->Identity();
//		ffIK_rf_outlineTransform->Identity();
//		IK_rightLowerLeg_Transform->Identity();
//		IK_rightKnee_Transform->Identity();
//		IK_rightUpperLeg_Transform->Identity();
//		IK_rightLegJoint_Transform->Identity();
//
//		IK_chest_0_Transform->Identity();
//		IK_chest_1_Transform->Identity();
//		IK_chest_2_Transform->Identity();
//		IK_chest_3_Transform->Identity();
//		IK_head_Transform->Identity();
//
//		IK_rightShoulderJoint_Transform->Identity();
//		IK_rightUpperArm_Transform->Identity();
//		IK_rightElbow_Transform->Identity();
//		IK_rightLowerArm_Transform->Identity();
//		IK_rightHand_Transform->Identity();
//
//		IK_leftShoulderJoint_Transform->Identity();
//		IK_leftUpperArm_Transform->Identity();
//		IK_leftElbow_Transform->Identity();
//		IK_leftLowerArm_Transform->Identity();
//		IK_leftHand_Transform->Identity();
//
//
//		IK_freeRightFoot_Transform->Identity();
//		IK_freeRightLowerLeg_Transform->Identity();
//		IK_freeRightKnee_Transform->Identity();
//		IK_freeRightUpperLeg_Transform->Identity();
//		IK_freeRightLegJoint_Transform->Identity();
//
//		displayFixedLeftFoot_Model();
//		renderWindow->Render();
//	}
//}
//
//
//
//void EventQtSlotConnect::addUMs_sfq()
//{
//	QString addSFQ_umFilename = QFileDialog::getOpenFileName(this, "Open Motion File", "c:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/motionDB/sensedMotion/unitMotions"); // SRQ Unit Motions
//	QFileInfo sfq_fileInfo(addSFQ_umFilename);
//	QString sfqUM_fname = sfq_fileInfo.fileName();
//	QMessageBox::information(this, "Motion File", sfqUM_fname);
//
//	string sfqUM_fnameInString = addSFQ_umFilename.toStdString();
//	const char *sfqUM_fnameInChar = sfqUM_fnameInString.c_str();
//
//}
//void EventQtSlotConnect::addUMs_srq()
//{
//	QString addSRQ_umFilename = QFileDialog::getOpenFileName(this, "Open Motion File", "c:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/motionDB/sensedMotion/unitMotions"); // SRQ Unit Motions
//	QFileInfo srq_fileInfo(addSRQ_umFilename);
//	QString srqUM_fname = srq_fileInfo.fileName();
//	QMessageBox::information(this, "Motion File", srqUM_fname);
//
//	string srqUM_fnameInString = addSRQ_umFilename.toStdString();
//	const char *srqUM_fnameInChar = srqUM_fnameInString.c_str();
//
//	std::ifstream file(srqUM_fnameInChar);
//	std::string str;
//	int srqUMfile_lineCount = 0;
//	copyUM_tofile.open("C:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/build/unitMotions/copyUM_tofile.txt");
//	
//	if (srqUM_fileCount == 0)
//	{
//		while (std::getline(file, str)) {
//
//			if (srqUMfile_lineCount == 0 || srqUMfile_lineCount == 1)
//			{
//
//			}
//			else
//			{
//				copyUM_tofile << str << "\n";
//		
//			}
//			srqUMfile_lineCount++;
//		}
//	}
//	else
//	{
//		while (std::getline(file, str)) {
//		
//			if (srqUMfile_lineCount == 0 || srqUMfile_lineCount == 1 || srqUMfile_lineCount ==2)
//			{
//
//			}
//			else
//			{
//				copyUM_tofile << str << "\n";
//			
//			}
//			srqUMfile_lineCount++;
//		}
//	}
//	copyUM_tofile.close();
//	srqUM_fileCount++;
//
//	std::ifstream ifile("C:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/build/unitMotions/copyUM_tofile.txt");
//	std::ofstream ofile("C:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/build/unitMotions/allUMs_tofile.txt", std::ios::app);
//
//
//
//
//	//check to see that the input file exists:
//	if (!ifile.is_open()) {
//		//file not open (i.e. not found, access denied, etc). Print an error message or do something else...
//	}
//	//check to see that the output file exists:
//	else if (!ofile.is_open()) {
//		//file not open (i.e. not created, access denied, etc). Print an error message or do something else...
//	}
//	else {
//		ofile << ifile.rdbuf();
//		//then add more lines to the file if need be...
//	}
//	ofile.close();
//		
//
//
//}
//
//void unitMotion_integrationDialog::blendUMs()
//{
//
//	cout << unitMotion_Dialog->sequentialBlending->isChecked();
//	if (unitMotion_Dialog->sequentialBlending->isChecked())
//	{
//		
//	
//	}
//}
//unitMotion_integrationDialog::unitMotion_integrationDialog(QWidget *parent): QMainWindow(parent), unitMotion_Dialog(new Ui::unitMotion_integrationDialog)
//{
//	unitMotion_Dialog->setupUi(this);
//	connect(unitMotion_Dialog->blendUM, SIGNAL(clicked()), this, SLOT(blendUMs()));
//
//}
//unitMotion_integrationDialog::~unitMotion_integrationDialog()
//{
//	delete unitMotion_Dialog;
//}
//void EventQtSlotConnect::Blend_unitMotions()
//{
//	UM_BelndingWindow->show();
//}
//
//
//void EventQtSlotConnect::authoring_mode()
//{
//	std::cout << "Authoring Mode Enabled " << endl;
//	viewMode_Button->setStyleSheet("background-color:darkRed;");
//	authorMode_Button->setStyleSheet("background-color:darkGreen;");
//
//	vtkSmartPointer<MouseInteractorStyle5> style = vtkSmartPointer<MouseInteractorStyle5>::New();
//	renderWindowInteractor->SetInteractorStyle(style);
//	style->SetDefaultRenderer(renderer);
//
//	style->pelvisActor = PlconeActor;
//	style->headActor = Head_objActor;
//	style->chestActor = CUconeActor;
//	style->Upper_chestActor = CUconeActor_upper;
//	style->RUA = RarmActor;
//	style->RLA = RforearmActor;
//	style->LUA = LarmActor;
//	style->LLA = LforearmActor;
//	style->RUL = RlulegActor;
//	style->RLL = RllegActor;
//	style->LUL = LlulegActor;
//	style->LLL = LllegActor;
//	style->LH_Actor = LeftHand_objActor;
//	style->RH_Actor = RightHand_objActor;
//	style->LL_Actor = LF_objActor;
//	style->RL_Actor = RF_objActor;
//
//
//	style->SM_pelvisActor = stickModel_pelvisActor;
//	style->SM_CH0 = stickModel_chest_0_Actor;
//	style->SM_CH1 = stickModel_chest_1_Actor;
//	style->SM_CH2 = stickModel_chest_2_Actor;
//	style->SM_CH3 = stickModel_chest_3_Actor;
//	style->SM_headActor = stickModel_head_Actor;
//	style->SM_RUA = stickModel_rightUpperArm_Actor;
//	style->SM_RLA = stickModel_rightLowerArm_Actor;
//	style->SM_RH_Actor = stickModel_rightHand_Actor;
//	style->SM_LUA = stickModel_leftUpperArm_Actor;
//	style->SM_LLA = stickModel_leftLowerArm_Actor;
//	style->SM_LH_Actor = stickModel_leftHand_Actor;
//	style->SM_RUL = stickModel_rightUpperLeg_Actor;
//	style->SM_RLL = stickModel_rightLowerLeg_Actor;
//	style->SM_RF_Actor = stickModel_rightFoot_Actor;
//	style->SM_LUL = stickModel_leftUpperLeg_Actor;
//	style->SM_LLL = stickModel_leftLowerLeg_Actor;
//	style->SM_LF_Actor = stickModel_leftFoot_Actor;
//
//
//	style->ffIK_pelvisActor = IK_pelvisActor;
//	style->ffIK_CH0 = IK_chest_0_Actor;
//	style->ffIK_CH1 = IK_chest_1_Actor;
//	style->ffIK_CH2 = IK_chest_2_Actor;
//	style->ffIK_CH3 = IK_chest_3_Actor;
//	style->ffIK_headActor = IK_head_Actor;;
//	style->ffIK_RUA = IK_rightUpperArm_Actor;
//	style->ffIK_RLA = IK_rightLowerArm_Actor;
//	style->ffIK_RH = IK_rightHand_Actor;
//	style->ffIK_LUA = IK_leftUpperArm_Actor;
//	style->ffIK_LLA = IK_leftLowerArm_Actor;
//	style->ffIK_LH = IK_leftHand_Actor;
//	style->ffIK_RUL = IK_rightUpperLeg_Actor;
//	style->ffIK_RLL = IK_rightLowerLeg_Actor;
//	style->ffIK_RF_Actor = IK_rightFoot_Actor;
//	style->ffIK_LUL = IK_leftUpperLeg_Actor;
//	style->ffIK_LLL = IK_leftLowerLeg_Actor;
//	style->ffIK_LF_Actor = IK_leftFoot_Actor;
//
//	style->freeRightUL_Actor = IK_freeRightUpperLeg_Actor;
//	style->freeRightLL_Actor = IK_freeRightLowerLeg_Actor;
//	style->freeRightFoot_Actor = IK_freeRightFoot_Actor;
//	
//	style->freeLeftUL_Actor = IK_freeLeftUpperLeg_Actor;
//	style->freeLeftLL_Actor = IK_freeLeftLowerLeg_Actor;
//	style->freeLeftFoot_Actor = IK_freeLeftFoot_Actor;
//
//
//	style->ConsProp_sphere_actor = ConstraintProp_sphere_actor;
//	style->TConsProp_sphere_actor = TConstraintProp_sphere_actor;
//	style->TConsProp_sphere_actor2 = TConstraintProp_sphere_actor2;
//	style->TConsProp_sphere_actor3 = TConstraintProp_sphere_actor3;
//
//	//style->ConsProp_line_actor = ConstraintProp_line_actor;
//	style->ConsProp_line_actor = ConstraintProp_line_actor1;
//	style->TConsProp_line_actor = TConstraintProp_line_actor1;
//	style->TConsProp_line_actor2 = TConstraintProp_line_actor2;
//	style->TConsProp_line_actor3 = TConstraintProp_line_actor3;
//
//	style->ConsProp_plane_actor = ConstraintProp_plane_actor;
//	style->ConsProp_cube_actor = ConstraintProp_cube_actor;
//
//
//}
//
//void EventQtSlotConnect::viewing_mode()
//{
//	std::cout << "Viewing Mode Enabled" << endl;
//	viewMode_Button->setStyleSheet("background-color:darkGreen;");
//	authorMode_Button->setStyleSheet("background-color:darkRed;");
//
//	vtkSmartPointer<vtkInteractorStyleTrackballCamera> style =
//		vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New(); //like paravie
//	renderWindowInteractor->SetInteractorStyle(style);
//}
//
//void EventQtSlotConnect::reset()
//{
//	QMessageBox::StandardButton reset_Reply = QMessageBox::question(this, "Reset Alert", "Are You Sure?",
//		QMessageBox::Yes | QMessageBox::No);
//	
//	if (reset_Reply == QMessageBox::Yes)
//	{
//		// To Reset CaptureCounter and LCD 
//		captureCount = 0;
//		this->KF_lcdNumber->display(0);
//
//
//		// Reset Text Degree Indicator 
//		dummy1 = dummy2 = dummy3 = 0;
//		std::string tA1 = "( ";
//		std::string tA2 = std::to_string(dummy1);
//		std::string tA3 = " ,";
//		std::string tA4 = std::to_string(dummy2);
//		std::string tA5 = " ,";
//		std::string tA6 = std::to_string(dummy3);
//		std::string tA7 = " )";
//
//		std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
//		const char *text = tA.data();
//
//		textActor->SetInput(text);
//
//		// To Reset IK Solver Prferences
//		this->fullbodyIK_checkBox->setChecked(0);
//		this->rhIK_checkBox->setChecked(0);
//		this->lhIK_checkBox->setChecked(0);
//		this->rfIK_checkBox->setChecked(0);
//		this->lfIK_checkBox->setChecked(0);
//		renderer->RemoveActor(rh_outlineActor);
//		renderer->RemoveActor(lh_outlineActor);
//		renderer->RemoveActor(rf_outlineActor);
//		renderer->RemoveActor(lf_outlineActor);
//		rhIK_flag = 0;
//		lhIK_flag = 0;
//		rfIK_flag = 0;
//		lfIK_flag = 0;
//		IKflag_Status = 0;
//
//		// Reset the OBJ Models
//		PlconeTransform->Identity();
//		PlconeTransform->Translate(pelvisObj_xpos, pelvisObj_ypos, pelvisObj_zpos);
//
//		CUconeTransform->Identity();
//		CUconeTransform->Translate(chestObj_xpos, chestObj_ypos, chestObj_zpos);
//		CUconeTransform->RotateWXYZ(0, 1, 1, 1);
//
//		Head_ObjReader_Transform->Identity();
//		Head_ObjReader_Transform->Translate(head_NeckObj_xpos, head_NeckObj_ypos, head_NeckObj_zpos);
//		Head_ObjReader_Transform->RotateWXYZ(0, 1, 1, 1);
//		
//		RarmTransform->Identity();
//		RarmTransform->Translate(ruaObj_xpos, ruaObj_ypos, ruaObj_zpos);
//		RarmTransform->RotateWXYZ(-4, 0, 0, 1);
//
//		RforearmTransform->Identity();
//		RforearmTransform->Translate(rlaObj_xpos, rlaObj_ypos, rlaObj_zpos);
//		RforearmTransform->RotateWXYZ(0, 1, 1, 1);
//
//		LarmTransform->Identity();
//		LarmTransform->Translate(luaObj_xpos, luaObj_ypos, luaObj_zpos);
//		LarmTransform->RotateWXYZ(4, 0, 0, 1);
//		
//		LforearmTransform->Identity();
//		LforearmTransform->Translate(llaObj_xpos, llaObj_ypos, llaObj_zpos);
//		LforearmTransform->RotateWXYZ(0, 1, 1, 1);
//
//		RlulegTransform->Identity();
//		RlulegTransform->Translate(rulObj_xpos, rulObj_ypos, rulObj_zpos);
//		RlulegTransform->RotateWXYZ(0, 1, 1, 1);
//
//		RllegTransform->Identity();
//		RllegTransform->Translate(rllObj_xpos, rllObj_ypos, rllObj_zpos);
//		RllegTransform->RotateWXYZ(0, 1, 1, 1);
//
//		LlulegTransform->Identity();
//		LlulegTransform->Translate(lulObj_xpos, lulObj_ypos, lulObj_zpos);;
//		LlulegTransform->RotateWXYZ(0, 1, 1, 1);
//
//		LllegTransform->Identity();
//		LllegTransform->Translate(lllObj_xpos, lllObj_ypos, lllObj_zpos);
//		LllegTransform->RotateWXYZ(0, 1, 1, 1);
//
//		PlconeActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//		CUconeActor->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//		CUconeActor_upper->GetProperty()->SetColor(colors->GetColor3d("DarkTurquoise").GetData());
//		Head_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//		LeftHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//		RightHand_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//		LF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//		RF_objActor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//		RarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//		RforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//		LarmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//		LforearmActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//		RlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//		RllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//		LlulegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//		LllegActor->GetProperty()->SetColor(colors->GetColor3d("Crimson").GetData());
//
//
//		stickModel_chest_0_Transform->Identity();
//		stickModel_chest_0_Transform->Translate(CH0_x, CH0_y, 0);
//		stickModel_chest_0_Transform->RotateWXYZ(0, 1, 1, 1);
//		stickModel_chest_0_Transform->Translate(-CH0_x, -CH0_y, 0);
//
//		stickModel_rightShoulderJoint_Transform->Identity();
//		stickModel_rightShoulderJoint_Transform->Translate(Shoulder_x, Shoulder_y, 0);
//		stickModel_rightShoulderJoint_Transform->RotateWXYZ(-8, 0, 0, 1);
//		stickModel_rightShoulderJoint_Transform->Translate(-Shoulder_x, -Shoulder_y, 0);
//
//		stickModel_rightUpperArm_Transform->Identity();
//		stickModel_rightUpperArm_Transform->Translate(smUA_x, smUA_y, 0);
//		stickModel_rightUpperArm_Transform->RotateWXYZ(0, 1, 1,1);
//		stickModel_rightUpperArm_Transform->Translate(-smUA_x, -smUA_y, 0);
//
//		stickModel_rightLowerArm_Transform->Identity();
//		stickModel_rightLowerArm_Transform->Translate(smLA_x, smLA_y, 0);
//		stickModel_rightLowerArm_Transform->RotateWXYZ(0, 1, 1, 1);
//		stickModel_rightLowerArm_Transform->Translate(-smLA_x, -smLA_y, 0);
//
//		stickModel_rightHand_Transform->Identity();
//		stickModel_rightHand_Transform->Translate(smH_x, smH_y, 0);
//		stickModel_rightHand_Transform->RotateWXYZ(0, 1, 0, 0);
//
//		stickModel_leftShoulderJoint_Transform->Identity();
//		stickModel_leftShoulderJoint_Transform->Translate(-Shoulder_x, Shoulder_y, 0);
//		stickModel_leftShoulderJoint_Transform->RotateWXYZ(8, 0, 0, 1);
//		stickModel_leftShoulderJoint_Transform->Translate(Shoulder_x, -Shoulder_y, 0);
//
//		stickModel_leftUpperArm_Transform->Identity();
//		stickModel_leftUpperArm_Transform->Translate(-smUA_x, smUA_y, 0);
//		stickModel_leftUpperArm_Transform->RotateWXYZ(0, 1, 1, 1);
//		stickModel_leftUpperArm_Transform->Translate(smUA_x, -smUA_y, 0);
//		
//		stickModel_leftLowerArm_Transform->Identity();
//		stickModel_leftLowerArm_Transform->Translate(-smLA_x, smLA_y, 0);
//		stickModel_leftLowerArm_Transform->RotateWXYZ(0, 1, 1, 1);
//		stickModel_leftLowerArm_Transform->Translate(smLA_x, -smLA_y, 0);
//		
//		stickModel_leftHand_Transform->Identity();
//		stickModel_leftHand_Transform->Translate(-smH_x, smH_y, 0);
//		stickModel_leftHand_Transform->RotateWXYZ(0, 1, 0, 0);
//
//		stickModel_rightUpperLeg_Transform->Identity();
//		stickModel_rightUpperLeg_Transform->Translate(smUL_x, smUL_y, 0);
//		stickModel_rightUpperLeg_Transform->RotateWXYZ(0, 1, 1, 1);
//		stickModel_rightUpperLeg_Transform->Translate(-smUL_x, -smUL_y, 0);
//
//		stickModel_rightLowerLeg_Transform->Identity();
//		stickModel_rightLowerLeg_Transform->Translate(smLL_x, smLL_y, 0);
//		stickModel_rightLowerLeg_Transform->RotateWXYZ(0, 1, 1, 1);
//		stickModel_rightLowerLeg_Transform->Translate(-smLL_x, -smLL_y, 0);
//
//		stickModel_rightFoot_Transform->Identity();
//		stickModel_rightFoot_Transform->Translate(smF_x, smF_y, 0);
//		stickModel_rightFoot_Transform->RotateWXYZ(0, 1, 1, 1);
//
//
//		stickModel_leftUpperLeg_Transform->Identity();
//		stickModel_leftUpperLeg_Transform->Translate(-smUL_x, smUL_y, 0);
//		stickModel_leftUpperLeg_Transform->RotateWXYZ(0, 1, 1, 1);
//		stickModel_leftUpperLeg_Transform->Translate(smUL_x, -smUL_y, 0);
//
//
//		stickModel_leftLowerLeg_Transform->Identity();
//		stickModel_leftLowerLeg_Transform->Translate(-smLL_x, smLL_y, 0);
//		stickModel_leftLowerLeg_Transform->RotateWXYZ(0, 1, 1, 1);
//		stickModel_leftLowerLeg_Transform->Translate(smLL_x, -smLL_y, 0);
//
//		stickModel_leftFoot_Transform->Identity();
//		stickModel_leftFoot_Transform->Translate(-smF_x, smF_y, 0);
//		stickModel_leftFoot_Transform->RotateWXYZ(0, 1, 1, 1);
//		
//		stickModel_pelvisActor->GetProperty()->SetColor(colors->GetColor3d("DimGray").GetData());
//		stickModel_chest_0_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_chest_1_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_chest_2_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_chest_3_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_head_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//		stickModel_rightUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_rightLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_rightHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//		stickModel_leftUpperArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_leftLowerArm_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_leftHand_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//		stickModel_rightUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_rightLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_rightFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//		stickModel_leftUpperLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_leftLowerLeg_Actor->GetProperty()->SetColor(colors->GetColor3d("Gray").GetData());
//		stickModel_leftFoot_Actor->GetProperty()->SetColor(colors->GetColor3d("Moccasin").GetData());
//
//		renderWindow->Render();
//
//		// Reset keyframe Slider
//		this->keyframes_Slider->setValue(0);
//
//		remove("C:/Users/Bharatesh/Documents/Visual Studio 2017/Projects/VTK_Projects/From April 2021/vtkQT Projects/moMAP/build/unitMotions/allUMs_tofile.txt");
//
//		// To Reset all quaternion Computations
//		for (int i = 0; i < 14; i++)
//		{
//			qp[i].setW(1); qp[i].setX(0); qp[i].setY(0); qp[i].setZ(0);
//			qx[i].setW(1); qx[i].setX(0); qx[i].setY(0); qx[i].setZ(0);
//			qy[i].setW(1); qy[i].setX(0); qy[i].setY(0); qy[i].setZ(0);
//			qz[i].setW(1); qz[i].setX(0); qz[i].setY(0); qz[i].setZ(0);
//
//			xaxisQP[i].setW(1); xaxisQP[i].setX(0); xaxisQP[i].setY(0); xaxisQP[i].setZ(0);
//			xaxisQX[i].setW(1); xaxisQX[i].setX(0); xaxisQX[i].setY(0); xaxisQX[i].setZ(0);
//			xaxisQY[i].setW(1); xaxisQY[i].setX(0); xaxisQY[i].setY(0); xaxisQY[i].setZ(0);
//			xaxisQZ[i].setW(1); xaxisQZ[i].setX(0); xaxisQZ[i].setY(0); xaxisQZ[i].setZ(0);
//
//			yaxisQP[i].setW(1); yaxisQP[i].setX(0); zaxisQP[i].setY(0); zaxisQP[i].setZ(0);
//			yaxisQX[i].setW(1); yaxisQX[i].setX(0); zaxisQX[i].setY(0); zaxisQX[i].setZ(0);
//			yaxisQY[i].setW(1); yaxisQY[i].setX(0); zaxisQY[i].setY(0); zaxisQY[i].setZ(0);
//			yaxisQZ[i].setW(1); yaxisQZ[i].setX(0); zaxisQZ[i].setY(0); zaxisQZ[i].setZ(0);
//
//			zaxisQP[i].setW(1); zaxisQP[i].setX(0); zaxisQP[i].setY(0); zaxisQP[i].setZ(0);
//			zaxisQX[i].setW(1); zaxisQX[i].setX(0); zaxisQX[i].setY(0); zaxisQX[i].setZ(0);
//			zaxisQY[i].setW(1); zaxisQY[i].setX(0); zaxisQY[i].setY(0); zaxisQY[i].setZ(0);
//			zaxisQZ[i].setW(1); zaxisQZ[i].setX(0); zaxisQZ[i].setY(0); zaxisQZ[i].setZ(0);
//
//
//			// For Inverse kinematics 
//			qpIK[i].setW(1); qpIK[i].setX(0); qpIK[i].setY(0); qpIK[i].setZ(0);
//			qxIK[i].setW(1); qxIK[i].setX(0); qxIK[i].setY(0); qxIK[i].setZ(0);
//			qyIK[i].setW(1); qyIK[i].setX(0); qyIK[i].setY(0); qyIK[i].setZ(0);
//			qzIK[i].setW(1); qzIK[i].setX(0); qzIK[i].setY(0); qzIK[i].setZ(0);
//
//			xaxisQP_IK[i].setW(1); xaxisQP_IK[i].setX(0); xaxisQP_IK[i].setY(0); xaxisQP_IK[i].setZ(0);
//			xaxisQX_IK[i].setW(1); xaxisQX_IK[i].setX(0); xaxisQX_IK[i].setY(0); xaxisQX_IK[i].setZ(0);
//			xaxisQY_IK[i].setW(1); xaxisQY_IK[i].setX(0); xaxisQY_IK[i].setY(0); xaxisQY_IK[i].setZ(0);
//			xaxisQZ_IK[i].setW(1); xaxisQZ_IK[i].setX(0); xaxisQZ_IK[i].setY(0); xaxisQZ_IK[i].setZ(0);
//			yaxisQP_IK[i].setW(1); yaxisQP_IK[i].setX(0); zaxisQP_IK[i].setY(0); zaxisQP_IK[i].setZ(0);
//			yaxisQX_IK[i].setW(1); yaxisQX_IK[i].setX(0); zaxisQX_IK[i].setY(0); zaxisQX_IK[i].setZ(0);
//			yaxisQY_IK[i].setW(1); yaxisQY_IK[i].setX(0); zaxisQY_IK[i].setY(0); zaxisQY_IK[i].setZ(0);
//			yaxisQZ_IK[i].setW(1); yaxisQZ_IK[i].setX(0); zaxisQZ_IK[i].setY(0); zaxisQZ_IK[i].setZ(0);
//			zaxisQP_IK[i].setW(1); zaxisQP_IK[i].setX(0); zaxisQP_IK[i].setY(0); zaxisQP_IK[i].setZ(0);
//			zaxisQX_IK[i].setW(1); zaxisQX_IK[i].setX(0); zaxisQX_IK[i].setY(0); zaxisQX_IK[i].setZ(0);
//			zaxisQY_IK[i].setW(1); zaxisQY_IK[i].setX(0); zaxisQY_IK[i].setY(0); zaxisQY_IK[i].setZ(0);
//			zaxisQZ_IK[i].setW(1); zaxisQZ_IK[i].setX(0); zaxisQZ_IK[i].setY(0); zaxisQZ_IK[i].setZ(0);
//		}
//	}
//
//
//}
//
//void EventQtSlotConnect::slot_clicked(vtkObject*, unsigned long, void*, void*)
//{
//  std::cout << "Clicked." << std::endl;
//}
