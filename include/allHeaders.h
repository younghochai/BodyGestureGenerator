#pragma once

#include "vtkGenericOpenGLRenderWindow.h"
#include <vtkEventQtSlotConnect.h>
#include <qpixmap.h>
#include <qpropertyanimation.h>
#include <qtimer.h>
#include <qmessagebox.h>
#include <qfiledialog.h>


#include <vtkInteractorStyleTrackballActor.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>
#include <vtkJPEGReader.h>
#include <vtkTextureMapToPlane.h>
#include <vtkPlaneSource.h>
#include <vtkTexture.h>
#include <vtkTransform.h>
#include <vtkConeSource.h>
#include <vtkCubeSource.h>
#include <vtkCylinderSource.h>
#include <vtkCallbackCommand.h>
#include <vtkCommand.h>
#include <vtkInteractorStyleSwitch.h>
#include <vtkInteractorStyleTrackballActor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkOutlineFilter.h>
#include <vtkCommand.h>
#include <vtkCamera.h>
#include <vtkWindowToImageFilter.h>
#include <vtkPNGWriter.h>
#include <vtkAxesActor.h>
#include <iostream> 
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include<ctime>
#include <cstdlib>
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkAnnotatedCubeActor.h>
#include <vtkTextWidget.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkTextRepresentation.h>
#include <vtkCoordinate.h>
#include <vtkLight.h>
#include <vtkLightActor.h>
#include <vtkArrowSource.h>
#include <vtkOBJReader.h>
#include <vtkRegularPolygonSource.h>
#include <vtkPolyDataSilhouette.h>
#include <vtkLineSource.h>
#include <vtkTexture.h>
#include <vtkTextureMapToSphere.h>
#include <vtkImageReader2Factory.h>
#include <vtkImageReader.h>
#include <vtkTexturedSphereSource.h>
#include <vtkTransformTextureCoords.h>

//#include <vtkMath.h>
#include <array>
#include <vtkMinimalStandardRandomSequence.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkJPEGReader.h>
#include <vtkPropPicker.h>
#include <vtkCallbackCommand.h>
#include <vtkParametricSuperEllipsoid.h>
#include <vtkParametricFunctionSource.h>
#include <vtkGenericOpenGLRenderWindow.h>

#include "vtkCollisionDetectionFilter.h"
#include "vtkMatrix4x4.h"

#include "Quaternion.h"
#include "BVHparser.hpp"
#include "lerp.h"
#include "SphereUtility.h"
#include "quaternion1.h"


#define clickCount 2048
#define PI 3.14159265359
#define USER_MATRIX


#if VTK_VERSION_NUMBER >= 89000000000ULL
#define VTK890 1
#endif

//InversKinematices Variables
vtkSmartPointer<vtkPoints> targetLinePoints;
double inverseKinematices_Theta_0 = 0;
double inverseKinematices_Theta_1 = 0;
double inverseKinematices_Theta_2 = 0;

int drawIdx = 1;
bool b_leftHand = true;
bool b_rightHand = true;
bool b_rightFoot = true;
bool b_draw_endPose = true;

class VitruvianAvatar
{
public:
	static msAvatar vitruvianAvatarUpdate;
	static bool isLoaded;
	static double humanHeight;
public:
	static void  initializeVetruvianVtkAvatar();
public:
	void startVetruvianAvatar();
	vtkSmartPointer<vtkRenderer> getVitruvianAvatarRenderer();
};

msAvatar VitruvianAvatar::vitruvianAvatarUpdate;
SphereUtility vitruvian_su;
bool bReadFile = false;
int trajCount = 0;
bool VitruvianAvatar::isLoaded = false;
VitruvianAvatar vAvatar;

int totalAngleOfRUA = 0;
int totalAngleOfRLA = 0;

int totalAngleOfRUA_z = 0;
//int totalAngleOfRLA_z = 0;

vtkNew<vtkNamedColors> colors;
vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
vtkNew<vtkRenderer> renderer;
vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;

vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow;
vtkSmartPointer<vtkRenderer> mRenderer;
vtkSmartPointer<QVTKInteractor> mInteractor;
vtkSmartPointer<vtkInteractorStyle> mInteractorStyle;



//***************************************************************************************************  Robot Model *******************************//


vtkSmartPointer<vtkSphereSource> targetSphere = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> targetMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> targetTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> targetActor = vtkSmartPointer<vtkActor>::New();


// Grid Surface
vtkSmartPointer<vtkPlaneSource> planeSource = vtkSmartPointer<vtkPlaneSource>::New();
vtkSmartPointer<vtkTransform> PlaneTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> planeActor = vtkSmartPointer<vtkActor>::New();

// Pelvis
std::string Pelvis_objFilename /*= "Pelvis.obj"*/;
//std::string Pelvis_objFilename = "Pelvis_Stick.obj";

vtkSmartPointer<vtkOBJReader> Pelvis_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkConeSource> Plcone = vtkSmartPointer<vtkConeSource>::New();
vtkSmartPointer<vtkPolyDataMapper> PlconeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> PlconeTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> PlconeActor = vtkSmartPointer<vtkActor>::New();


// chest under cone 
std::string Chest_objFilename /*= "Chest.obj"*/;
vtkSmartPointer<vtkOBJReader> Chest_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkConeSource> CUcone = vtkSmartPointer<vtkConeSource>::New();
vtkSmartPointer<vtkPolyDataMapper> CUconeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> CUconeTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> CUconeActor = vtkSmartPointer<vtkActor>::New();


// chest 
vtkSmartPointer<vtkConeSource> CUcone_upper = vtkSmartPointer<vtkConeSource>::New();
vtkSmartPointer<vtkPolyDataMapper> CUconeMapper_upper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> CUconeTransform_upper = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> CUconeActor_upper = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkCubeSource> forechest = vtkSmartPointer<vtkCubeSource>::New();
vtkSmartPointer<vtkPolyDataMapper> forechestMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> forechestTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> forechestActor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkCubeSource> Lforechest = vtkSmartPointer<vtkCubeSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LforechestMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> LforechestTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LforechestActor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkCubeSource> Rforechest = vtkSmartPointer<vtkCubeSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RforechestMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> RforechestTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RforechestActor = vtkSmartPointer<vtkActor>::New();


const char* headTexture_filename = "../BodyGestureGenerator/data/headmap.jpg";
std::string headNeck_objFilename /*= "humanHead1.obj"*/;
vtkSmartPointer<vtkOBJReader> Head_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkPolyDataMapper> Head_ObjReader_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>Head_ObjReader_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> Head_objActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkOBJReader> headNeck_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkTexture> head_texture = vtkSmartPointer<vtkTexture>::New();
vtkSmartPointer<vtkJPEGReader> headTexture_reader = vtkSmartPointer<vtkJPEGReader>::New();


vtkSmartPointer<vtkSphereSource> LShoulder = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LShoulderMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> LShoulderTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LShoulderActor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkCylinderSource> Larm = vtkSmartPointer<vtkCylinderSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LarmMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> LarmTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LarmActor = vtkSmartPointer<vtkActor>::New();

std::string LUA_objFilename /*= "LUA.obj"*/;
vtkSmartPointer<vtkOBJReader> LUA_ObjReader = vtkSmartPointer<vtkOBJReader>::New();




vtkSmartPointer<vtkSphereSource> Lelbow = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LelbowMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> LelbowTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LelbowActor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkCylinderSource> Lforearm = vtkSmartPointer<vtkCylinderSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LforearmMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> LforearmTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LforearmActor = vtkSmartPointer<vtkActor>::New();


std::string LLA_objFilename /*= "LLA.obj"*/;
vtkSmartPointer<vtkOBJReader> LLA_ObjReader = vtkSmartPointer<vtkOBJReader>::New();



//std::string LeftHand_objFilename = "handL.obj";
//vtkSmartPointer<vtkOBJReader> LeftHand_ObjReader = vtkSmartPointer<vtkOBJReader>::New();

std::string LH_objFilename /*= "LH.obj"*/;
vtkSmartPointer<vtkOBJReader> LH_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkPolyDataMapper> LeftHand_ObjReader_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>LeftHand_ObjReader_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LeftHand_objActor = vtkSmartPointer<vtkActor>::New();


vtkSmartPointer<vtkSphereSource> RShoulder = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RShoulderMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> RShoulderTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RShoulderActor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkCylinderSource> Rarm = vtkSmartPointer<vtkCylinderSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RarmMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> RarmTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RarmActor = vtkSmartPointer<vtkActor>::New();

std::string RUA_objFilename /*= "RUA.obj"*/;
vtkSmartPointer<vtkOBJReader> RUA_ObjReader = vtkSmartPointer<vtkOBJReader>::New();


vtkSmartPointer<vtkSphereSource> Relbow = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RelbowMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> RelbowTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RelbowActor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkCylinderSource> Rforearm = vtkSmartPointer<vtkCylinderSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RforearmMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> RforearmTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RforearmActor = vtkSmartPointer<vtkActor>::New();

std::string RLA_objFilename /*= "RLA.obj"*/;
vtkSmartPointer<vtkOBJReader> RLA_ObjReader = vtkSmartPointer<vtkOBJReader>::New();

//
//std::string RightHand_objFilename = "handR.obj";
//vtkSmartPointer<vtkOBJReader> RightHand_ObjReader = vtkSmartPointer<vtkOBJReader>::New();


std::string RH_objFilename /*= "RH.obj"*/;
vtkSmartPointer<vtkOBJReader> RH_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkPolyDataMapper> RightHand_ObjReader_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>RightHand_ObjReader_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RightHand_objActor = vtkSmartPointer<vtkActor>::New();


vtkSmartPointer<vtkSphereSource> Llujoint = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LlujointMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> LlujointTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LlujointActor = vtkSmartPointer<vtkActor>::New();


std::string LUL_objFilename /*= "LUL.obj"*/;
vtkSmartPointer<vtkOBJReader> LUL_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkCylinderSource> Lluleg = vtkSmartPointer<vtkCylinderSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LlulegMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> LlulegTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LlulegActor = vtkSmartPointer<vtkActor>::New();


vtkSmartPointer<vtkSphereSource> Lknee = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LkneeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> LkneeTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LkneeActor = vtkSmartPointer<vtkActor>::New();


std::string LLL_objFilename /*= "LLL.obj"*/;
vtkSmartPointer<vtkOBJReader> LLL_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkCylinderSource> Llleg = vtkSmartPointer<vtkCylinderSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LllegMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> LllegTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LllegActor = vtkSmartPointer<vtkActor>::New();


//std::string leftfoot_objFilename = "nfootL.obj";

std::string LF_objFilename /*= "LF.obj"*/;
vtkSmartPointer<vtkOBJReader> LF_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkPolyDataMapper> LF_ObjReader_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>LF_ObjReader_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LF_objActor = vtkSmartPointer<vtkActor>::New();



vtkSmartPointer<vtkSphereSource> Rlujoint = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RlujointMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> RlujointTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RlujointActor = vtkSmartPointer<vtkActor>::New();



std::string RUL_objFilename /*= "RUL.obj"*/;
vtkSmartPointer<vtkOBJReader> RUL_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkCylinderSource> Rluleg = vtkSmartPointer<vtkCylinderSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RlulegMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> RlulegTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RlulegActor = vtkSmartPointer<vtkActor>::New();


vtkSmartPointer<vtkSphereSource> Rknee = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RkneeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> RkneeTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RkneeActor = vtkSmartPointer<vtkActor>::New();



std::string RLL_objFilename /*= "RLL.obj"*/;
vtkSmartPointer<vtkOBJReader> RLL_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkCylinderSource> Rlleg = vtkSmartPointer<vtkCylinderSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RllegMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> RllegTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RllegActor = vtkSmartPointer<vtkActor>::New();



//std::string rightfoot_objFilename = "nfootR.obj";
std::string RF_objFilename /*= "RF.obj"*/;
vtkSmartPointer<vtkOBJReader> RF_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkPolyDataMapper> RF_ObjReader_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>RF_ObjReader_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RF_objActor = vtkSmartPointer<vtkActor>::New();



vtkSmartPointer<vtkAxesActor> axes = vtkSmartPointer<vtkAxesActor>::New();
vtkSmartPointer<vtkTransform> axis_Transform = vtkSmartPointer<vtkTransform>::New();

vtkSmartPointer<vtkArrowSource> X_axis_Source = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkTransform> X_axisTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkPolyDataMapper> X_axis_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor> X_axisActor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkArrowSource> Y_axis_Source = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkTransform> Y_axisTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkPolyDataMapper> Y_axis_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor> Y_axisActor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkArrowSource> Z_axis_Source = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkTransform> Z_axisTransform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkPolyDataMapper> Z_axis_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor> Z_axisActor = vtkSmartPointer<vtkActor>::New();


//===================================================JOINT SPHERES=============================================

vtkSmartPointer<vtkSphereSource> pelvisJS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> pelvisJS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  pelvisJS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> pelvisJS_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkSphereSource> chestJS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> chestJS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  chestJS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> chestJS_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkSphereSource> LUA_JS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LUA_JS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  LUA_JS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor>LUA_JS_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkSphereSource> LLA_JS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LLA_JS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  LLA_JS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LLA_JS_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkSphereSource> RUA_JS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RUA_JS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  RUA_JS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RUA_JS_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkSphereSource> RLA_JS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RLA_JS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  RLA_JS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RLA_JS_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkSphereSource> LUL_JS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LUL_JS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  LUL_JS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LUL_JS_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkSphereSource> LLL_JS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LLL_JS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  LLL_JS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LLL_JS_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkSphereSource> RUL_JS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RUL_JS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  RUL_JS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RUL_JS_actor = vtkSmartPointer<vtkActor>::New();


vtkSmartPointer<vtkSphereSource> RLL_JS = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RLL_JS_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  RLL_JS_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RLL_JS_actor = vtkSmartPointer<vtkActor>::New();


vtkSmartPointer<vtkSphereSource> LL_AJ_Source = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> LL_AJ_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  LL_AJ_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> LL_AJ_actor = vtkSmartPointer<vtkActor>::New();


vtkSmartPointer<vtkSphereSource> RL_AJ_Source = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> RL_AJ_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>  RL_AJ_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> RL_AJ_actor = vtkSmartPointer<vtkActor>::New();

//========================================================================================================================

// ruaJS_popupWindow Sphere
vtkNew<vtkGenericOpenGLRenderWindow> ruaJS_renderWindow;
vtkNew<vtkRenderer> ruaJS_renderer;
vtkNew<vtkRenderWindowInteractor> ruaJS_renderWindowInteractor;

vtkNew<vtkSphereSource> ruaJS_sphereSource;
vtkNew<vtkPolyDataMapper> ruaJS_sphereMapper;
vtkNew<vtkActor> ruaJS_sphereActor;


//motionSphere Window 
vtkNew<vtkGenericOpenGLRenderWindow> motionSphere_renderWindow;
vtkNew<vtkRenderer> motionSphere_renderer;
vtkNew<vtkRenderWindowInteractor> motionSphere_renderWindowInteractor;


struct Avatar {
	Quaternion b0, b1, b2, b3, b4, b5, b6, b7, b8, b9;
};

struct Axis
{
	double x, y, z;
	double angleX = 0, angleY = 0, angleZ = 0;
}axis;



struct  Avatar avatar[clickCount];
Quaternion qx[14], qy[14], qz[14], qsf[14], qp[14];
Quaternion qxIK[14], qyIK[14], qzIK[14], qsfIK[14], qpIK[14];

Quaternion xaxisQX[14], xaxisQY[14], xaxisQZ[14], xaxisQP[14];
Quaternion yaxisQX[14], yaxisQY[14], yaxisQZ[14], yaxisQP[14];
Quaternion zaxisQX[14], zaxisQY[14], zaxisQZ[14], zaxisQP[14];

Quaternion xaxisQX_IK[14], xaxisQY_IK[14], xaxisQZ_IK[14], xaxisQP_IK[14];
Quaternion yaxisQX_IK[14], yaxisQY_IK[14], yaxisQZ_IK[14], yaxisQP_IK[14];
Quaternion zaxisQX_IK[14], zaxisQY_IK[14], zaxisQZ_IK[14], zaxisQP_IK[14];

lerp pos[14];
ofstream posfile;

// Model Values

double pelvisObj_xpos/* = 0*/;
double pelvisObj_ypos /*= 50*/;
double pelvisObj_zpos /*= 0*/;
double pelvisObj_scale /*= 50*/;

double chestObj_xpos/* = 0*/;
double chestObj_ypos/* = 2.5*/;
double chestObj_zpos /*= 0*/;
double chestObj_scale/* = 50*/;

double CH_xrot_circle_pos/* = 0*/;
double CH_yrot_circle_pos/* = 2.5*/;
double CH_zrot_circle_pos /*= 0*/;
//double chestObj_scale/* = 50*/;

double head_NeckObj_xpos/* = 0*/;
double head_NeckObj_ypos/* = 26.0*/;
double head_NeckObj_zpos /*= -3.0*/;
double head_NeckObj_scale /*= 8*/;

double Head_xrot_circle_pos/* = 0*/;
double Head_yrot_circle_pos/* = 26.0*/;
double Head_zrot_circle_pos /*= -3.0*/;


double ruaObj_xpos /*= -10.5*/;
double ruaObj_ypos /*= 20.0*/;
double ruaObj_zpos /*= -2.5*/;
double ruaObj_scale /*= 50*/;

double RUA_xrot_circle_pos/* = 0*/;
double RUA_yrot_circle_pos/* = 26.0*/;
double RUA_zrot_circle_pos /*= -3.0*/;

double rlaObj_xpos /*= 0.0*/;
double rlaObj_ypos/* = -14.0*/;
double rlaObj_zpos /*= 1.0*/;
double rlaObj_scale /*= 50*/;

double RLA_xrot_circle_pos/* = 0*/;
double RLA_yrot_circle_pos/* = 26.0*/;
double RLA_zrot_circle_pos /*= -3.0*/;

double RHObj_xpos /*= -0.5*/;
double RHObj_ypos /*= -12.75*/;
double RHObj_zpos /*= 0.5*/;
double RHObj_scale /*= 40*/;

double RH_xrot_circle_pos/* = 0*/;
double RH_yrot_circle_pos/* = 26.0*/;
double RH_zrot_circle_pos /*= -3.0*/;

double luaObj_xpos /*= 10.50*/;
double luaObj_ypos /*= 20.0*/;
double luaObj_zpos /*= -2.5*/;
double luaObj_scale /*= 50*/;

double LUA_xrot_circle_pos/* = 0*/;
double LUA_yrot_circle_pos/* = 26.0*/;
double LUA_zrot_circle_pos /*= -3.0*/;

double llaObj_xpos /*= 0.5*/;
double llaObj_ypos /*= -14.0*/;
double llaObj_zpos /*= 0.5*/;
double llaObj_scale /*= 50*/;

double LLA_xrot_circle_pos/* = 0*/;
double LLA_yrot_circle_pos/* = 26.0*/;
double LLA_zrot_circle_pos /*= -3.0*/;

double LHObj_xpos /*= -0.5*/;
double LHObj_ypos /*= -12.75*/;
double LHObj_zpos /*= 0.5*/;
double LHObj_scale /*= 40*/;

double LH_xrot_circle_pos/* = 0*/;
double LH_yrot_circle_pos/* = 26.0*/;
double LH_zrot_circle_pos /*= -3.0*/;


double rulObj_xpos /*= -3.40*/;
double rulObj_ypos /*= -2.125*/;
double rulObj_zpos /*= 0.0*/;
double rulObj_scale /*= 50*/;

double RUL_xrot_circle_pos/* = 0*/;
double RUL_yrot_circle_pos/* = 26.0*/;
double RUL_zrot_circle_pos /*= -3.0*/;

double rllObj_xpos /*= -0.25*/;
double rllObj_ypos /*= -21.0*/;
double rllObj_zpos /*= 0.0*/;
double rllObj_scale /*= 50*/;

double RLL_xrot_circle_pos/* = 0*/;
double RLL_yrot_circle_pos/* = 26.0*/;
double RLL_zrot_circle_pos /*= -3.0*/;


double RFObj_xpos/* = 0.7*/;
double RFObj_ypos /*= -19.25*/;
double RFObj_zpos /*= -2.10*/;
double RFObj_scale /*= 50*/;

double RF_xrot_circle_pos/* = 0*/;
double RF_yrot_circle_pos/* = 26.0*/;
double RF_zrot_circle_pos /*= -3.0*/;



double lulObj_xpos /*= 3.90*/;
double lulObj_ypos /*= -2.125*/;
double lulObj_zpos/* = 0.0*/;
double lulObj_scale /*= 50*/;

double LUL_xrot_circle_pos/* = 0*/;
double LUL_yrot_circle_pos/* = 26.0*/;
double LUL_zrot_circle_pos /*= -3.0*/;

double lllObj_xpos /*= 1.0*/;
double lllObj_ypos /*= -21.0*/;
double lllObj_zpos /*= -0.75*/;
double lllObj_scale /*= 50*/;

double LLL_xrot_circle_pos/* = 0*/;
double LLL_yrot_circle_pos/* = 26.0*/;
double LLL_zrot_circle_pos /*= -3.0*/;

double LFObj_xpos /*= 0.0*/;
double LFObj_ypos /*= -19.25*/;
double LFObj_zpos /*= -2.10*/;
double LFObj_scale /*= 50*/;

double LF_xrot_circle_pos/* = 0*/;
double LF_yrot_circle_pos/* = 26.0*/;
double LF_zrot_circle_pos /*= -3.0*/;



// --------------------------------------------------------------------------------
int plCone_Ypos = 48;

double PlconeRadius = 6;
double PlconeHeight = 4;


double CuconeRadius = 2.45;
double chestHeight = 12;

double CUcone_upperRadius = 2.45;
//double chestHeight = 17.5/ ;

double forechestXlength = 15.50;
double forechestYlength = 1.90;
double forechestZlength = 2;
//double forechestHeight = 0.5;

double LforechestXlength = 7.0;
double LforechestYlength = 2.0;
double LforechestZlength = 2.0;
double LforechestXTrans = -8.0;
double LforechestYTrans = 2.0;
double LforechestZTrans = 0.0;

double RforechestXlength = 7.0;
double RforechestYlength = 2.0;
double RforechestZlength = 2.0;
double RforechestXTrans = 8.0;
double RforechestYTrans = 2.0;
double RforechestZTrans = 0.0;


double neckRadius = 3;
double neckHeight = 10;

//double headRadius = 5;
double headScale = 0.60;
double head_Xtrans = 0;
double head_Ytrans = 75.0;
double head_Ztrans = 0.5;

double LShoulderRadius = 1.5;

double LupperarmRadius = 1.3;
double LupperarmHeight = 11.5;

double LelbowRadius = 1.45;

double LforearmRadius = 1.2;
double LforearmHeight = 11;

//double LhandRadius = 3;
double	LhandScale = 8;
double	Lhand_Xtrans = 9.15;
double	Lhand_Ytrans = 48.05;
double	Lhand_Ztrans = 0.625;

double RShoulderRadius = 1.5;

double RupperarmRadius = 1.3;
double RupperarmHeight = 11.5;

double RelbowRadius = 1.45;

double RforearmRadius = 1.2;
double RforearmHeight = 11;

//double RhandRadius = 3;
double	RhandScale = 8.0;
double	Rhand_Xtrans = -9.15;
double	Rhand_Ytrans = 48.05;
double	Rhand_Ztrans = 0.625;

double LlujointRadius = 1.5;

double LlulegRadius = 1.5;
double LlulegHeight = 18.0;

double LkneeRadius = 1.5;

double LllegRadius = 1.5;
double LllegHeight = 17.5;
double LL_AJ_SourceRadius = 1.3;

double LfootXlength = 3;
double LfootYlength = 2.0;
double LfootZlength = 10.0;

double LfootXTrans = 1.4;
double LfootYTrans = -3.0;
double LfootZTrans = 4.450;
double LfootScale = 20.0;

double RlujointRadius = 1.5;
double RlulegRadius = 1.5;
double RlulegHeight = 18.0;
double RkneeRadius = 1.5;
double RllegRadius = 1.5;
double RllegHeight = 17.5;
double RL_AJ_SourceRadius = 1.3;


double RfootXlength = 3;
double RfootYlength = 2.0;
double RfootZlength = 10.0;

double RfootXTrans = -1.35;
double RfootYTrans = -3.0;
double RfootZTrans = 4.450;
double RfootScale = 20.0;


double axis_Yposition = 50.0;
double axes_Xlength = 25.0;
double axes_Ylength = 25.0;
double axes_Zlength = 25.0;

double axisShaft_radius = 0.10;
double x_y_z_translateVal = 50;
double xaxis_scaleVal = 25.0;
double yaxis_scaleVal = 7.0;
double zaxis_scaleVal = 7.0;

double SphereRadius = 6.0;

double chest;
double Upperchest;
double arm_X;
double arm_Y;
double arm_Y2;
double leg_X;
double leg_Y;
double leg_Y2;

double footHeight;


char axis_flag;
int boneID;
int flag;

int pelvis_angle = 0, pelvis_x = 0, pelvis_y = 0, pelvis_z = 0;
int anim_pelvis_angle = 0, anim_pelvis_x = 0, anim_pelvis_y = 0, anim_pelvis_z = 0;

int chest_angle = 0, chest_x = 0, chest_y = 0, chest_z = 0;
int anim_chest_angle = 0, anim_chest_x = 0, anim_chest_y = 0, anim_chest_z = 0;

int chest_angleX = 0, chest_angleY = 0, chest_angleZ = 0;
int anim_chest_angleX = 0, anim_chest_angleY = 0, anim_chest_angleZ = 0;

int Upperchest_angle = 0, Upperchest_x = 0, Upperchest_y = 0, Upperchest_z = 0;
int anim_Upperchest_angle = 0, anim_Upperchest_x = 0, anim_Upperchest_y = 0, anim_Upperchest_z = 0;

int head_angle = 0, head_x = 0, head_y = 0, head_z = 0;
int anim_head_angle = 0, anim_head_x = 0, anim_head_y = 0, anim_head_z = 0;

int LH_angle = 0, LH_x = 0, LH_y = 0, LH_z = 0;
int anim_LH_angle = 0, anim_LH_x = 0, anim_LH_y = 0, anim_LH_z = 0;

int RH_angle = 0, RH_x = 0, RH_y = 0, RH_z = 0;
int anim_RH_angle = 0, anim_RH_x = 0, anim_RH_y = 0, anim_RH_z = 0;

int RL_angle = 0, RL_x = 0, RL_y = 0, RL_z = 0;
int anim_RL_angle = 0, anim_RL_x = 0, anim_RL_y = 0, anim_RL_z = 0;

int LL_angle = 0, LL_x = 0, LL_y = 0, LL_z = 0;
int anim_LL_angle = 0, anim_LL_x = 0, anim_LL_y = 0, anim_LL_z = 0;

int rua_angle = 0, rua_x = 0, rua_y = 0, rua_z = 0;
int anim_rua_angle = 0, anim_rua_x = 0, anim_rua_y = 0, anim_rua_z = 0;

int rua_angleX = 0, rua_angleY = 0, rua_angleZ = 0;
int anim_rua_angleX = 0, anim_rua_angleY, anim_rua_anglez;

int rla_angle = 0, rla_x = 0, rla_y = 0, rla_z = 0;
int anim_rla_angle = 0, anim_rla_x = 0, anim_rla_y = 0, anim_rla_z = 0;

int rla_angleX = 0, rla_angleY = 0, rla_angleZ = 0;
int anim_rla_angleX = 0, anim_rla_angleY, anim_rla_anglez;


int rul_angle = 0, rul_x = 0, rul_y = 0, rul_z = 0;
int anim_rul_angle = 0, anim_rul_x = 0, anim_rul_y = 0, anim_rul_z = 0;

int rul_angleX = 0, rul_angleY = 0, rul_angleZ = 0;
int anim_rul_angleX = 0, anim_rul_angleY = 0, anim_rul_angleZ = 0;


int rll_angle = 0, rll_x = 0, rll_y = 0, rll_z = 0;
int anim_rll_angle = 0, anim_rll_x = 0, anim_rll_y = 0, anim_rll_z = 0;

int rll_angleX = 0, rll_angleY = 0, rll_angleZ = 0;
int anim_rll_angleX = 0, anim_rll_angleY = 0, anim_rll_angleZ = 0;


int lua_angle = 0, lua_x = 0, lua_y = 0, lua_z = 0;
int anim_lua_angle = 0, anim_lua_x = 0, anim_lua_y = 0, anim_lua_z = 0;

int lua_angleX = 0, lua_angleY = 0, lua_angleZ = 0;
int anim_lua_angleX = 0, anim_lua_angleY = 0, anim_lua_angleZ = 0;

int lla_angle = 0, lla_x = 0, lla_y = 0, lla_z = 0;
int anim_lla_angle = 0, anim_lla_x = 0, anim_lla_y = 0, anim_lla_z = 0;

int lla_angleX = 0, lla_angleY = 0, lla_angleZ = 0;
int anim_lla_angleX = 0, anim_lla_angleY = 0, anim_lla_angleZ = 0;


int lul_angle = 0, lul_x = 0, lul_y = 0, lul_z = 0;
int anim_lul_angle = 0, anim_lul_x = 0, anim_lul_y = 0, anim_lul_z = 0;

int lul_angleX = 0, lul_angleY = 0, lul_angleZ = 0;
int anim_lul_angleX = 0, anim_lul_angleY = 0, anim_lul_angleZ = 0;

int lll_angle = 0, lll_x = 0, lll_y = 0, lll_z = 0;
int anim_lll_angle = 0, anim_lll_x = 0, anim_lll_y = 0, anim_lll_z = 0;

int lll_angleX = 0, lll_angleY = 0, lll_angleZ = 0;
int anim_lll_angleX = 0, anim_lll_angleY = 0, anim_lll_angleZ = 0;

int i_ = 0;


vtkSmartPointer<vtkTextWidget> textWidget =
vtkSmartPointer<vtkTextWidget>::New();
vtkSmartPointer<vtkTextActor> textActor = vtkSmartPointer<vtkTextActor>::New();
vtkSmartPointer<vtkTextRepresentation> textRepresentation =
vtkSmartPointer<vtkTextRepresentation>::New();

int dummy1 = 0;  int dummy2 = 0; int dummy3 = 0;
std::string tA1 = "( ";
std::string tA2 = std::to_string(dummy1);
std::string tA3 = " ,";
std::string tA4 = std::to_string(dummy2);
std::string tA5 = " ,";
std::string tA6 = std::to_string(dummy3);
std::string tA7 = " )";


std::string tA = tA1 + tA2 + tA3 + tA4 + tA5 + tA6 + tA7;
const char* text = tA.data();

int timerCount = 0;

int sliderDiff;
int sliderTemp = 0;
int sliderPrev = 0;

bool playPause = false;

double changeHeight_val;
double changeHeight_val_Ratio;

int variable_plCone_Ypos;
double variable_PlconeRadius, variable_PlconeHeight, variable_Plcone_Ypos;

double variable_CuconeRadius;
double variable_chestHeight;

double variable_CUcone_upperRadius;
//double variable_chestHeight  ;

double variable_forechestXlength;
double variable_forechestYlength;
double variable_forechestZlength;
double variable_forechestHeight;



double variable_LforechestXlength;
double variable_LforechestYlength;
double variable_LforechestZlength;
double variable_LforechestXTrans;
double variable_LforechestYTrans;
double variable_LforechestZTrans;

double variable_RforechestXlength;
double variable_RforechestYlength;
double variable_RforechestZlength;
double variable_RforechestXTrans;
double variable_RforechestYTrans;
double variable_RforechestZTrans;

double variable_neckRadius;
double variable_neckHeight;

//double variable_headRadius;
double variable_headScale;

double  variable_head_Xtrans = 0;
double  variable_head_Ytrans = 88.0;
double  variable_head_Ztrans = 1.0;


double variable_LShoulderRadius;

double variable_LupperarmRadius;
double variable_LupperarmHeight;

double variable_LelbowRadius;

double variable_LforearmRadius;
double variable_LforearmHeight;

//double variable_LhandRadius;
double	variable_LhandScale;
double	variable_Lhand_Xtrans;
double	variable_Lhand_Ytrans;
double	variable_Lhand_Ztrans;


double variable_RShoulderRadius;

double variable_RupperarmRadius;
double variable_RupperarmHeight;

double variable_RelbowRadius;

double variable_RforearmRadius;
double variable_RforearmHeight;

//double variable_RhandRadius;
double	variable_RhandScale;
double	variable_Rhand_Xtrans;
double	variable_Rhand_Ytrans;
double	variable_Rhand_Ztrans;

double variable_LlujointRadius;
double variable_LlulegRadius;
double variable_LlulegHeight;

double variable_LkneeRadius;

double variable_LllegRadius;
double variable_LllegHeight;

double variable_LL_AJ_SourceRadius;

double variable_LfootXlength;
double variable_LfootYlength;
double variable_LfootZlength;
double variable_LfootScale;

double variable_LfootXTrans;
double variable_LfootYTrans;
double variable_LfootZTrans;

double variable_RlujointRadius;
double variable_RlulegRadius;
double variable_RlulegHeight;
double variable_RkneeRadius;
double variable_RllegRadius;
double variable_RllegHeight;

double variable_RL_AJ_SourceRadius;

double variable_RfootXlength;
double variable_RfootYlength;
double variable_RfootZlength;

double variable_RfootXTrans;
double variable_RfootYTrans;
double variable_RfootZTrans;
double variable_RfootScale;

//double  variable_axis_Yposition;
//double  variable_axes_Xlength; 
//double  variable_axes_Ylength; 
//double  variable_axes_Zlength; 

double variable_axisShaft_radius;
double variable_x_y_z_translateVal;
double variable_xaxis_scaleVal;
double variable_yaxis_scaleVal;
double variable_zaxis_scaleVal;


double variable_SphereRadius;

int kf_ID = 1;
int kfImage_count = 0;

QStringList boneSegment_name;


int prev_xpos = 0;
int prev_ypos = 0;
int prev_zpos = 0;

int temp_xpos = 0;
int temp_ypos = 0;
int temp_zpos = 0;

int xpos_diff;
int ypos_diff;
int zpos_diff;

int xpos_val = 0;
int ypos_val = 0;
int zpos_val = 0;

int xslider_val;
int yslider_val;
int temp_yslider_val;
int zslider_val;

int kfTable_rowCount = 0;

string str_pel_w, str_pel_x, str_pel_y, str_pel_z;
string str_chest_w, str_chest_x, str_chest_y, str_chest_z;
string str_rua_w, str_rua_x, str_rua_y, str_rua_z;
string str_rla_w, str_rla_x, str_rla_y, str_rla_z;
string str_lua_w, str_lua_x, str_lua_y, str_lua_z;
string str_lla_w, str_lla_x, str_lla_y, str_lla_z;
string str_rul_w, str_rul_x, str_rul_y, str_rul_z;
string str_rll_w, str_rll_x, str_rll_y, str_rll_z;
string str_lul_w, str_lul_x, str_lul_y, str_lul_z;
string str_lll_w, str_lll_x, str_lll_y, str_lll_z;


string concat_str_pel, concat_str_chest, concat_str_rua, concat_str_rla, concat_str_lua, concat_str_lla, concat_str_rul,
concat_str_rll, concat_str_lul, concat_str_ll;


QString tb_pel_quat, tb_chest_quat, tb_rua_quat, tb_rla_quat, tb_lua_quat,
tb_lla_quat, tb_rul_quat, tb_rll_quat, tb_lul_quat, tb_lll_quat;

string str_x_pelPos, str_y_pelPos, str_z_pelPos;

string concat_xyz_pelvisPos;
QString tb_pelPos_value;

// Maximum of 25 key frames shall be capture - Shall be increased too 
Quaternion  slerp_pelvis_kf[25], slerp_chest_kf[25], slerp_rua_kf[25], slerp_rla_kf[25],
slerp_lua_kf[25], slerp_lla_kf[25], slerp_rul_kf[25], slerp_rll_kf[25], slerp_lul_kf[25], slerp_lll_kf[25];

// Maximum of 25 "Inversre Kinematics (IK)" key frames shall be capture - Shall be increased too
Quaternion  slerpIK_pelvis_kf[25], slerpIK_chest_kf[25], slerpIK_rua_kf[25], slerpIK_rla_kf[25],
slerpIK_lua_kf[25], slerpIK_lla_kf[25], slerpIK_rul_kf[25], slerpIK_rll_kf[25], slerpIK_lul_kf[25], slerpIK_lll_kf[25];

lerp keypositions[25];

// For All keyframes Generation
//Keyframe file
ofstream keyframeFile;
//keyposition file
ofstream keyposFile;


//UM Integration 
ofstream copyUM_tofile;
ofstream Blend_UMs_File;

//========================================================================================================================================================
// For All keyframes file
ofstream all_KFs_file;
ofstream all_KPs_file;

//int noOfFrames_betweenKF = 100;
//int Total_noOfFrames = 100;
//float slerpT = 0.0;

Quaternion temp_pelvisFrames[1024], temp_chestFrames[1024], temp_ruaFrames[1024], temp_rlaFrames[1024], temp_luaFrames[1024], temp_llaFrames[1024],
temp_rulFrames[1024], temp_rllFrames[1024], temp_lulFrames[1024], temp_lllFrames[1024];

Quaternion pelvisFrames[1024], chestFrames[1024], ruaFrames[1024], rlaFrames[1024], luaFrames[1024], llaFrames[1024],
rulFrames[1024], rllFrames[1024], lulFrames[1024], lllFrames[1024];

bool postest_rcm = false;
bool load_rcm = false;

bool indexreset_rcm = false;

int current_frames_rcm = 0;
int loadframes_rcm;
int ID_rcm;
int mx_rcm = 0;


vtkTransform* transform_rcm[10] = { nullptr };
NodeManage Quatnode_rcm;
NodeManage Quatenode_AddUM;

//NodeManage Quatnode_rcm;
PositionManage Posnode_rcm;

//file loading 
vtkTransform* transform_test[10] = { nullptr };
NodeManage Quatnode_test;
PositionManage Posnode_test;

int current_frames_test = 0;
int loadframes_tests = 0;

bool authorMode;
bool fileMode;

//==================================================================================================================================================================================
// For All IK_keyframes file
ofstream all_IK_KFs_file;
ofstream all_IK_KPs_file;

//==================================
// if noOfFrames_betweenKF, Total_noOfFrames set to 100 then keep slerpTT as 0.0101
// if noOfFrames_betweenKF, Total_noOfFrames set to 50 then keep slerpTT as 0.0202
//==================================
int noOfFrames_betweenKF = 50; // 50
int Total_noOfFrames = 50; // 50
double slerpT = 0.0;
double slerpTT = 0.0202; // 50->0.0202 // 100->0.0101

int IK_noOfFrames_betweenKF = 50; // 50
int IK_Total_noOfFrames = 50; // 50
double IK_slerpT = 0.0;
double IK_slerpTT = 0.0202; // 50->0.0202 // 100->0.0101

Quaternion IK_temp_pelvisFrames[1024], IK_temp_chestFrames[1024], IK_temp_ruaFrames[1024], IK_temp_rlaFrames[1024], IK_temp_luaFrames[1024], IK_temp_llaFrames[1024],
IK_temp_rulFrames[1024], IK_temp_rllFrames[1024], IK_temp_lulFrames[1024], IK_temp_lllFrames[1024];

Quaternion IK_pelvisFrames[1024], IK_chestFrames[1024], IK_ruaFrames[1024], IK_rlaFrames[1024], IK_luaFrames[1024], IK_llaFrames[1024],
IK_rulFrames[1024], IK_rllFrames[1024], IK_lulFrames[1024], IK_lllFrames[1024];





//==================================================================================================================================================================================
// unit motion input variables
int umID;
int startPose;
double PL_A, PL_X, PL_Y, PL_Z;
double CH_A, CH_X, CH_Y, CH_Z;
double RUA_A, RUA_X, RUA_Y, RUA_Z;
double RLA_A, RLA_X, RLA_Y, RLA_Z;
double LUA_A, LUA_X, LUA_Y, LUA_Z;
double LLA_A, LLA_X, LLA_Y, LLA_Z;
double RUL_A, RUL_X, RUL_Y, RUL_Z;
double RLL_A, RLL_X, RLL_Y, RLL_Z;
double LUL_A, LUL_X, LUL_Y, LUL_Z;
double LLL_A, LLL_X, LLL_Y, LLL_Z;
int timeValue_count;

Quaternion umA_qx[14], umA_qy[14], umA_qz[14];

Quaternion  slerp_pelvis_umaKF[18], slerp_chest_umaKF[18], slerp_rua_umaKF[18], slerp_rla_umaKF[18],
slerp_lua_umaKF[18], slerp_lla_umaKF[18], slerp_rul_umaKF[18], slerp_rll_umaKF[18], slerp_lul_umaKF[18], slerp_lll_umaKF[18];

Quaternion temp_umakf1_pelvis[1024], temp_umakf1_chest[1024], temp_umakf1_rua[1024], temp_umakf1_rla[1024], temp_umakf1_lua[1024], temp_umakf1_lla[1024],
temp_umakf1_rul[1024], temp_umakf1_rll[1024], temp_umakf1_lul[1024], temp_umakf1_lll[1024];

Quaternion umakf1_pelvis[1024], umakf1_chest[1024], umakf1_rua[1024], umakf1_rla[1024], umakf1_lua[1024], umakf1_lla[1024],
umakf1_rul[1024], umakf1_rll[1024], umakf1_lul[1024], umakf1_lll[1024];

bool PL_status;
bool CH_status;
bool rua_status;
bool rla_status;
bool lua_status;
bool lla_status;
bool rul_status;
bool rll_status;
bool lul_status;
bool lll_status;

struct uma_PL_Axis
{
	double uma_PL_x, uma_PL_y, uma_PL_z;
	double uma_PL_angleX = 0, uma_PL_angleY = 0, uma_PL_angleZ = 0;
}uma_PL_axis;

Quaternion umA_PLQuat_qw[1024], umA_PLQuat_qx[1024], umA_PLQuat_qy[1024], umA_PLQuat_qz[1024];

double umAPLQuat_w[1024];
double umAPLQuat_x[1024];
double umAPLQuat_y[1024];
double umAPLQuat_z[1024];


struct uma_CH_Axis
{
	double uma_CH_x, uma_CH_y, uma_CH_z;
	double uma_CH_angleX = 0, uma_CH_angleY = 0, uma_CH_angleZ = 0;
}uma_CH_axis;

Quaternion umA_CHQuat_qw[1024], umA_CHQuat_qx[1024], umA_CHQuat_qy[1024], umA_CHQuat_qz[1024];

double umACHQuat_w[1024];
double umACHQuat_x[1024];
double umACHQuat_y[1024];
double umACHQuat_z[1024];


struct uma_rua_Axis
{
	double uma_rua_x, uma_rua_y, uma_rua_z;
	double uma_rua_angleX = 0, uma_rua_angleY = 0, uma_rua_angleZ = 0;
}uma_rua_axis;

Quaternion umA_ruaQuat_qw[1024], umA_ruaQuat_qx[1024], umA_ruaQuat_qy[1024], umA_ruaQuat_qz[1024];

double umAruaQuat_w[1024];
double umAruaQuat_x[1024];
double umAruaQuat_y[1024];
double umAruaQuat_z[1024];


struct uma_rla_Axis
{
	double uma_rla_x, uma_rla_y, uma_rla_z;
	double uma_rla_angleX = 0, uma_rla_angleY = 0, uma_rla_angleZ = 0;
}uma_rla_axis;

Quaternion umA_rlaQuat_qw[1024], umA_rlaQuat_qx[1024], umA_rlaQuat_qy[1024], umA_rlaQuat_qz[1024];

double umArlaQuat_w[1024];
double umArlaQuat_x[1024];
double umArlaQuat_y[1024];
double umArlaQuat_z[1024];


struct uma_lua_Axis
{
	double uma_lua_x, uma_lua_y, uma_lua_z;
	double uma_lua_angleX = 0, uma_lua_angleY = 0, uma_lua_angleZ = 0;
}uma_lua_axis;

Quaternion umA_luaQuat_qw[1024], umA_luaQuat_qx[1024], umA_luaQuat_qy[1024], umA_luaQuat_qz[1024];

double umAluaQuat_w[1024];
double umAluaQuat_x[1024];
double umAluaQuat_y[1024];
double umAluaQuat_z[1024];


struct uma_lla_Axis
{
	double uma_lla_x, uma_lla_y, uma_lla_z;
	double uma_lla_angleX = 0, uma_lla_angleY = 0, uma_lla_angleZ = 0;
}uma_lla_axis;

Quaternion umA_llaQuat_qw[1024], umA_llaQuat_qx[1024], umA_llaQuat_qy[1024], umA_llaQuat_qz[1024];

double umAllaQuat_w[1024];
double umAllaQuat_x[1024];
double umAllaQuat_y[1024];
double umAllaQuat_z[1024];


struct uma_rul_Axis
{
	double uma_rul_x, uma_rul_y, uma_rul_z;
	double uma_rul_angleX = 0, uma_rul_angleY = 0, uma_rul_angleZ = 0;
}uma_rul_axis;

Quaternion umA_rulQuat_qw[1024], umA_rulQuat_qx[1024], umA_rulQuat_qy[1024], umA_rulQuat_qz[1024];

double umArulQuat_w[1024];
double umArulQuat_x[1024];
double umArulQuat_y[1024];
double umArulQuat_z[1024];

struct uma_rll_Axis
{
	double uma_rll_x, uma_rll_y, uma_rll_z;
	double uma_rll_angleX = 0, uma_rll_angleY = 0, uma_rll_angleZ = 0;
}uma_rll_axis;

Quaternion umA_rllQuat_qw[1024], umA_rllQuat_qx[1024], umA_rllQuat_qy[1024], umA_rllQuat_qz[1024];

double umArllQuat_w[1024];
double umArllQuat_x[1024];
double umArllQuat_y[1024];
double umArllQuat_z[1024];

struct uma_lul_Axis
{
	double uma_lul_x, uma_lul_y, uma_lul_z;
	double uma_lul_angleX = 0, uma_lul_angleY = 0, uma_lul_angleZ = 0;
}uma_lul_axis;

Quaternion umA_lulQuat_qw[1024], umA_lulQuat_qx[1024], umA_lulQuat_qy[1024], umA_lulQuat_qz[1024];

double umAlulQuat_w[1024];
double umAlulQuat_x[1024];
double umAlulQuat_y[1024];
double umAlulQuat_z[1024];

struct uma_lll_Axis
{
	double uma_lll_x, uma_lll_y, uma_lll_z;
	double uma_lll_angleX = 0, uma_lll_angleY = 0, uma_lll_angleZ = 0;
}uma_lll_axis;

Quaternion umA_lllQuat_qw[1024], umA_lllQuat_qx[1024], umA_lllQuat_qy[1024], umA_lllQuat_qz[1024];

double umAlllQuat_w[1024];
double umAlllQuat_x[1024];
double umAlllQuat_y[1024];
double umAlllQuat_z[1024];


ofstream umA_file;

int temp_fileRead_Count = 0;
ofstream ss_blending_file;

float umPL_slerp_inc = 0.0;
float umCH_slerp_inc = 0.0;
float umrua_slerp_inc = 0.0;
float umrla_slerp_inc = 0.0;
float umlua_slerp_inc = 0.0;
float umlla_slerp_inc = 0.0;
float umrul_slerp_inc = 0.0;
float umrll_slerp_inc = 0.0;
float umlul_slerp_inc = 0.0;
float umlll_slerp_inc = 0.0;

double ssB_pelvis_w;
double ssB_pelvis_x;
double ssB_pelvis_y;
double ssB_pelvis_z;

double ssB_chest_w;
double ssB_chest_x;
double ssB_chest_y;
double ssB_chest_z;

double ssB_rua_w;
double ssB_rua_x;
double ssB_rua_y;
double ssB_rua_z;

double ssB_rla_w;
double ssB_rla_x;
double ssB_rla_y;
double ssB_rla_z;

double ssB_lua_w;
double ssB_lua_x;
double ssB_lua_y;
double ssB_lua_z;


double ssB_lla_w;
double ssB_lla_x;
double ssB_lla_y;
double ssB_lla_z;


double ssB_rul_w;
double ssB_rul_x;
double ssB_rul_y;
double ssB_rul_z;


double ssB_rll_w;
double ssB_rll_x;
double ssB_rll_y;
double ssB_rll_z;

double ssB_lul_w;
double ssB_lul_x;
double ssB_lul_y;
double ssB_lul_z;

double ssB_lll_w;
double ssB_lll_x;
double ssB_lll_y;
double ssB_lll_z;

Quaternion  slerp_pelvis_ssBKF[1024], slerp_chest_ssBKF[1024], slerp_rua_ssBKF[1024], slerp_rla_ssBKF[1024],
slerp_lua_ssBKF[1024], slerp_lla_ssBKF[1024], slerp_rul_ssBKF[1024], slerp_rll_ssBKF[1024], slerp_lul_ssBKF[1024], slerp_lll_ssBKF[1024];



bool male_biped, vitruvian_biped, skeleton_biped;


vtkSmartPointer<vtkArrowSource> none_xaxis_arrowSource = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkPolyDataMapper> none_xaxis_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>none_xaxis_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> none_xaxis_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkArrowSource> none_yaxis_arrowSource = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkPolyDataMapper> none_yaxis_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>none_yaxis_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> none_yaxis_actor = vtkSmartPointer<vtkActor>::New();


vtkSmartPointer<vtkArrowSource> none_zaxis_arrowSource = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkPolyDataMapper> none_zaxis_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>none_zaxis_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> none_zaxis_actor = vtkSmartPointer<vtkActor>::New();


double rightHand_pos = 27.0;
double rh_x, rh_y, rh_z;
double rua_length = 14.0;
double rla_length = 12.75;
double rua_in_theta, rua_in_theta_Deg;
double rla_in_theta, rla_in_theta_Deg;

double RF_xaxis_actor_Zpos;


double rul_lenght = 22.0;
double rll_length = 22.0;
double pelvis_position /*= 43.95*/;
double perimeter, semiperimeter;
double herons_area;
double rul_height, rll_height, pelvis_pos_height;

double Aaplha, Bbeta, Ssigma;
double Inradius;
double circumRadius;
double rua_Median, rla_Median, Pelvis_pos_Median;

vtkSmartPointer<vtkSphereSource> ConstraintProp_sphereSource = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> ConstraintProp_sphere_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> ConstraintProp_sphere_transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> ConstraintProp_sphere_actor = vtkSmartPointer<vtkActor>::New();
int consProp_sphere_x, consProp_sphere_y, consProp_sphere_z;
double consProp_sphere_size = 5.0;

vtkSmartPointer<vtkSphereSource> TConstraintProp_sphereSource = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> TConstraintProp_sphere_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> TConstraintProp_sphere_transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> TConstraintProp_sphere_actor = vtkSmartPointer<vtkActor>::New();
int TconsProp_sphere_x, TconsProp_sphere_y, TconsProp_sphere_z;
double TconsProp_sphere_size = 5.0;




vtkSmartPointer<vtkSphereSource> TConstraintProp_sphereSource2 = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> TConstraintProp_sphere_mapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> TConstraintProp_sphere_transform2 = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> TConstraintProp_sphere_actor2 = vtkSmartPointer<vtkActor>::New();
int TconsProp_sphere_x2, TconsProp_sphere_y2, TconsProp_sphere_z2;
double TconsProp_sphere_size2 = 5.0;


vtkSmartPointer<vtkSphereSource> TConstraintProp_sphereSource3 = vtkSmartPointer<vtkSphereSource>::New();
vtkSmartPointer<vtkPolyDataMapper> TConstraintProp_sphere_mapper3 = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> TConstraintProp_sphere_transform3 = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> TConstraintProp_sphere_actor3 = vtkSmartPointer<vtkActor>::New();
int TconsProp_sphere_x3, TconsProp_sphere_y3, TconsProp_sphere_z3;
double TconsProp_sphere_size3 = 5.0;



vtkSmartPointer<vtkLineSource> ConstraintProp_lineSource = vtkSmartPointer<vtkLineSource>::New();
vtkSmartPointer<vtkPolyDataMapper> ConstraintProp_line_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> ConstraintProp_line_transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> ConstraintProp_line_actor = vtkSmartPointer<vtkActor>::New();
int consProp_line_x, consProp_line_y, consProp_line_z;
double consProp_line_p0x = 50; double consProp_line_p0y = 0; double consProp_line_p0z = 0;;
double consProp_line_p1x = 50; double consProp_line_p1y = 50; double consProp_line_p1z = 0;
// Create two points, P0 and P1
double lineSource_p0[3] = { consProp_line_p0x, consProp_line_p0y, consProp_line_p0z };
double lineSource_p1[3] = { consProp_line_p1x, consProp_line_p1y, consProp_line_p1z };


vtkSmartPointer<vtkArrowSource> ConstraintProp_lineSource1 = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkPolyDataMapper> ConstraintProp_line_mapper1 = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> ConstraintProp_line_transform1 = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> ConstraintProp_line_actor1 = vtkSmartPointer<vtkActor>::New();


vtkSmartPointer<vtkArrowSource> TConstraintProp_lineSource1 = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkPolyDataMapper> TConstraintProp_line_mapper1 = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> TConstraintProp_line_transform1 = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> TConstraintProp_line_actor1 = vtkSmartPointer<vtkActor>::New();
int TconsProp_line_x, TconsProp_line_y, TconsProp_line_z;

vtkSmartPointer<vtkArrowSource> TConstraintProp_lineSource2 = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkPolyDataMapper> TConstraintProp_line_mapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> TConstraintProp_line_transform2 = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> TConstraintProp_line_actor2 = vtkSmartPointer<vtkActor>::New();
int TconsProp_line_x2, TconsProp_line_y2, TconsProp_line_z2;

vtkSmartPointer<vtkArrowSource> TConstraintProp_lineSource3 = vtkSmartPointer<vtkArrowSource>::New();
vtkSmartPointer<vtkPolyDataMapper> TConstraintProp_line_mapper3 = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> TConstraintProp_line_transform3 = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> TConstraintProp_line_actor3 = vtkSmartPointer<vtkActor>::New();
int TconsProp_line_x3, TconsProp_line_y3, TconsProp_line_z3;

//int consProp_line_x, consProp_line_y, consProp_line_z;

vtkSmartPointer<vtkPlaneSource> ConstraintProp_planeSource = vtkSmartPointer<vtkPlaneSource>::New();
vtkSmartPointer<vtkPolyDataMapper> ConstraintProp_plane_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> ConstraintProp_plane_transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> ConstraintProp_plane_actor = vtkSmartPointer<vtkActor>::New();
int consProp_plane_x, consProp_plane_y, consProp_plane_z;
double consProp_plane_p1x = 30; double consProp_plane_p1y = 0; double consProp_plane_p1z = 0;
double consProp_plane_p2x = 0; double consProp_plane_p2y = 30; double consProp_plane_p2z = 0;


vtkSmartPointer<vtkCubeSource> ConstraintProp_cubeSource = vtkSmartPointer<vtkCubeSource>::New();
vtkSmartPointer<vtkPolyDataMapper> ConstraintProp_cube_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform> ConstraintProp_cube_transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> ConstraintProp_cube_actor = vtkSmartPointer<vtkActor>::New();
int consProp_cube_x, consProp_cube_y, consProp_cube_z;
int consProp_cube_xlength = 10; int consProp_cube_ylength = 10; int consProp_cube_zlength = 10;

int consProp_selectionID;
int temp_consProp_selectionID;

int constXrot_slider; int constXrot_slider_Diff;  int temp_constXrot_slider = 0; int prev_constXrot_slider = 0;
int constYrot_slider; int constYrot_slider_Diff;  int temp_constYrot_slider = 0; int prev_constYrot_slider = 0;
int constZrot_slider; int constZrot_slider_Diff;  int temp_constZrot_slider = 0; int prev_constZrot_slider = 0;

std::string boxingBag_objFilename = "boxingBag.obj";
vtkSmartPointer<vtkOBJReader> boxingBag_ObjReader = vtkSmartPointer<vtkOBJReader>::New();
vtkSmartPointer<vtkPolyDataMapper> boxingBag_ObjReader_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>boxingBag_ObjReader_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> boxingBag_objActor = vtkSmartPointer<vtkActor>::New();
int consProp_boxingBag_x, consProp_boxingBag_y, consProp_boxingBag_z;



const char* motionSphereTexture_fname = "mmgrs.jpg";
vtkSmartPointer<vtkTexturedSphereSource> motionSphere_Source = vtkSmartPointer<vtkTexturedSphereSource>::New();
vtkSmartPointer<vtkImageReader2Factory> readerFactory = vtkSmartPointer<vtkImageReader2Factory>::New();
vtkSmartPointer<vtkImageReader2> imageReader;
vtkSmartPointer<vtkTexture> motionSphere_texture = vtkSmartPointer<vtkTexture>::New();
vtkSmartPointer<vtkTransformTextureCoords> transformTexture = vtkSmartPointer<vtkTransformTextureCoords>::New();
vtkNew<vtkPolyDataMapper>motionSphere_Mapper;
vtkNew<vtkActor> motionSphere_Actor;


// Horizontal Plane, Frontal Plane, Sagittal plane
vtkSmartPointer<vtkPlaneSource> hP_source = vtkSmartPointer<vtkPlaneSource>::New();
vtkSmartPointer<vtkPolyDataMapper> hP_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkTransform>hP_Transform = vtkSmartPointer<vtkTransform>::New();
vtkSmartPointer<vtkActor> hP_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkPlaneSource> fP_source = vtkSmartPointer<vtkPlaneSource>::New();
vtkSmartPointer<vtkPolyDataMapper> fP_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor> fP_actor = vtkSmartPointer<vtkActor>::New();

vtkSmartPointer<vtkPlaneSource> sP_source = vtkSmartPointer<vtkPlaneSource>::New();
vtkSmartPointer<vtkPolyDataMapper> sP_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor> sP_actor = vtkSmartPointer<vtkActor>::New();


//Anatomical input variables for Euler Angle Calculations
int eulerFramesCount;
double 	plspX_value, plspY_value, plspZ_value;
double 	plepX_value, plepY_value, plepZ_value;
double 	chspX_value, chspY_value, chspZ_value;
double 	chepX_value, chepY_value, chepZ_value;

double 	ruaspX_value, ruaspY_value, ruaspZ_value;
double 	ruaepX_value, ruaepY_value, ruaepZ_value;
double 	rlaspX_value, rlaspY_value, rlaspZ_value;
double 	rlaepX_value, rlaepY_value, rlaepZ_value;

double 	luaspX_value, luaspY_value, luaspZ_value;
double 	luaepX_value, luaepY_value, luaepZ_value;
double 	llaspX_value, llaspY_value, llaspZ_value;
double 	llaepX_value, llaepY_value, llaepZ_value;

double 	rulspX_value, rulspY_value, rulspZ_value;
double 	rulepX_value, rulepY_value, rulepZ_value;
double 	rllspX_value, rllspY_value, rllspZ_value;
double 	rllepX_value, rllepY_value, rllepZ_value;

double 	lulspX_value, lulspY_value, lulspZ_value;
double 	lulepX_value, lulepY_value, lulepZ_value;
double 	lllspX_value, lllspY_value, lllspZ_value;
double 	lllepX_value, lllepY_value, lllepZ_value;

int timerRange = 1000;



//===================================================== For Stick Model===================================================
// To  Create stickModel_Pelvis
vtkNew<vtkSphereSource> stickModel_pelvisSource;
vtkNew<vtkPolyDataMapper> stickModel_pelvisMapper;
vtkNew<vtkTransform> stickModel_pelvisTransform;
vtkNew<vtkActor> stickModel_pelvisActor;
double PL_x, PL_y, PL_z;

// To Create stickModel_Chest Links 
vtkNew<vtkSphereSource> stickModel_chest_0_Source;
vtkNew<vtkPolyDataMapper> stickModel_chest_0_Mapper;
vtkNew<vtkTransform> stickModel_chest_0_Transform;
vtkNew<vtkActor> stickModel_chest_0_Actor;
double CH0_x, CH0_y, CH0_z;

vtkNew<vtkSphereSource> stickModel_chest_1_Source;
vtkNew<vtkPolyDataMapper> stickModel_chest_1_Mapper;
vtkNew<vtkTransform> stickModel_chest_1_Transform;
vtkNew<vtkActor> stickModel_chest_1_Actor;
double CH1_x, CH1_y, CH1_z;

vtkNew<vtkSphereSource> stickModel_chest_2_Source;
vtkNew<vtkPolyDataMapper> stickModel_chest_2_Mapper;
vtkNew<vtkTransform>stickModel_chest_2_Transform;
vtkNew<vtkActor> stickModel_chest_2_Actor;
double CH2_x, CH2_y, CH2_z;

vtkNew<vtkSphereSource> stickModel_chest_3_Source;
vtkNew<vtkPolyDataMapper> stickModel_chest_3_Mapper;
vtkNew<vtkTransform> stickModel_chest_3_Transform;
vtkNew<vtkActor> stickModel_chest_3_Actor;
double CH3_x, CH3_y, CH3_z;

// To Create stickModel_head
std::string  stickModel_head_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader>  stickModel_head_Reader;
vtkNew<vtkPolyDataMapper>  stickModel_head_Mapper;
vtkNew<vtkTransform> stickModel_head_Transform;
vtkNew<vtkActor>  stickModel_head_Actor;
vtkNew<vtkTexture> stickModel_head_Texture;
vtkNew<vtkJPEGReader> stickModel_headTexture_Reader;
double H_x, H_y, H_z;


// To Create stickModel_rightShoulderJoint
vtkNew<vtkSphereSource> stickModel_rightShoulderJoint_Source;
vtkNew<vtkPolyDataMapper> stickModel_rightShoulderJoint_Mapper;
vtkNew<vtkTransform> stickModel_rightShoulderJoint_Transform;
vtkNew<vtkActor> stickModel_rightShoulderJoint_Actor;
double Shoulder_x, Shoulder_y, Shoulder_z;

// To Create stickModel_rightUpperArm
vtkNew<vtkCylinderSource> stickModel_rightUpperArm_Source;
vtkNew<vtkPolyDataMapper> stickModel_rightUpperArm_Mapper;
vtkNew<vtkTransform> stickModel_rightUpperArm_Transform;
vtkNew<vtkActor> stickModel_rightUpperArm_Actor;
double smUA_x, smUA_y, smUA_z;

// To Create stickModel_rightElbow
vtkNew<vtkSphereSource> stickModel_rightElbow_Source;
vtkNew<vtkPolyDataMapper>  stickModel_rightElbow_Mapper;
vtkNew<vtkTransform>  stickModel_rightElbow_Transform;
vtkNew<vtkActor>  stickModel_rightElbow_Actor;


// To Create stickModel_rightLowerArm
vtkNew<vtkCylinderSource> stickModel_rightLowerArm_Source;
vtkNew<vtkPolyDataMapper> stickModel_rightLowerArm_Mapper;
vtkNew<vtkTransform> stickModel_rightLowerArm_Transform;
vtkNew<vtkActor> stickModel_rightLowerArm_Actor;
double smLA_x, smLA_y, smLA_z;


// To Create stickModel_rightHand
std::string stickModel_rightHand_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader> stickModel_rightHand_Reader;
vtkNew<vtkPolyDataMapper> stickModel_rightHand_Mapper;
vtkNew<vtkTransform> stickModel_rightHand_Transform;
vtkNew<vtkActor> stickModel_rightHand_Actor;
double smH_x, smH_y, smH_z;

// To Create the right hand outliner for IK
vtkSmartPointer<vtkOutlineFilter> rh_outlineFilter = vtkSmartPointer<vtkOutlineFilter>::New();
vtkSmartPointer<vtkPolyDataMapper>  rh_outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor>  rh_outlineActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform>  rh_outlineTransform = vtkSmartPointer<vtkTransform>::New();

// To Create stickModel_leftShoulderJoint
vtkNew<vtkSphereSource>stickModel_leftShoulderJoint_Source;
vtkNew<vtkPolyDataMapper>stickModel_leftShoulderJoint_Mapper;
vtkNew<vtkTransform> stickModel_leftShoulderJoint_Transform;
vtkNew<vtkActor> stickModel_leftShoulderJoint_Actor;

// To Create stickModel_leftUpperArm
vtkNew<vtkCylinderSource> stickModel_leftUpperArm_Source;
vtkNew<vtkPolyDataMapper> stickModel_leftUpperArm_Mapper;
vtkNew<vtkTransform> stickModel_leftUpperArm_Transform;
vtkNew<vtkActor> stickModel_leftUpperArm_Actor;

// To Create stickModel_leftElbow
vtkNew<vtkSphereSource> stickModel_leftElbow_Source;
vtkNew<vtkPolyDataMapper>  stickModel_leftElbow_Mapper;
vtkNew<vtkTransform>  stickModel_leftElbow_Transform;
vtkNew<vtkActor>  stickModel_leftElbow_Actor;

// To Create stickModel_leftLowerArm
vtkNew<vtkCylinderSource> stickModel_leftLowerArm_Source;
vtkNew<vtkPolyDataMapper> stickModel_leftLowerArm_Mapper;
vtkNew<vtkTransform> stickModel_leftLowerArm_Transform;
vtkNew<vtkActor>stickModel_leftLowerArm_Actor;

// To Create stickModel_leftHand
std::string stickModel_leftHand_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader> stickModel_leftHand_Reader;
vtkNew<vtkPolyDataMapper> stickModel_leftHand_Mapper;
vtkNew<vtkTransform>stickModel_leftHand_Transform;
vtkNew<vtkActor> stickModel_leftHand_Actor;

// To Create the left hand outliner for IK
vtkSmartPointer<vtkOutlineFilter> lh_outlineFilter = vtkSmartPointer<vtkOutlineFilter>::New();
vtkSmartPointer<vtkPolyDataMapper>  lh_outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor>  lh_outlineActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform>  lh_outlineTransform = vtkSmartPointer<vtkTransform>::New();


// To Create stickModel_rightLegJoint
vtkNew<vtkSphereSource> stickModel_rightLegJoint_Source;
vtkNew<vtkPolyDataMapper> stickModel_rightLegJoint_Mapper;
vtkNew<vtkTransform> stickModel_rightLegJoint_Transform;
vtkNew<vtkActor> stickModel_rightLegJoint_Actor;


// To Create stickModel_rightUpperLeg
vtkNew<vtkCylinderSource> stickModel_rightUpperLeg_Source;
vtkNew<vtkPolyDataMapper> stickModel_rightUpperLeg_Mapper;
vtkNew<vtkTransform> stickModel_rightUpperLeg_Transform;
vtkNew<vtkActor> stickModel_rightUpperLeg_Actor;
double smUL_x, smUL_y, smUL_z;

// To Create stickModel_rightKnee
vtkNew<vtkSphereSource>  stickModel_rightKnee_Source;
vtkNew<vtkPolyDataMapper>  stickModel_rightKnee_Mapper;
vtkNew<vtkTransform>   stickModel_rightKnee_Transform;
vtkNew<vtkActor>   stickModel_rightKnee_Actor;


// To Create stickModel_rightLowerLeg
vtkNew<vtkCylinderSource> stickModel_rightLowerLeg_Source;
vtkNew<vtkPolyDataMapper> stickModel_rightLowerLeg_Mapper;
vtkNew<vtkTransform>stickModel_rightLowerLeg_Transform;
vtkNew<vtkActor> stickModel_rightLowerLeg_Actor;
double smLL_x, smLL_y, smLL_z;

// To Create stickModel_rightFoot
std::string stickModel_rightFoot_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader> stickModel_rightFoot_Reader;
vtkNew<vtkPolyDataMapper> stickModel_rightFoot_Mapper;
vtkNew<vtkTransform> stickModel_rightFoot_Transform;
vtkNew<vtkActor> stickModel_rightFoot_Actor;
double smF_x, smF_y, smF_z;

// To Create the right foot outliner for IK
vtkSmartPointer<vtkOutlineFilter> rf_outlineFilter = vtkSmartPointer<vtkOutlineFilter>::New();
vtkSmartPointer<vtkPolyDataMapper>  rf_outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor>  rf_outlineActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform>  rf_outlineTransform = vtkSmartPointer<vtkTransform>::New();


// To Create stickModel_leftLegJoint
vtkNew<vtkSphereSource> stickModel_leftLegJoint_Source;
vtkNew<vtkPolyDataMapper>stickModel_leftLegJoint_Mapper;
vtkNew<vtkTransform> stickModel_leftLegJoint_Transform;
vtkNew<vtkActor>stickModel_leftLegJoint_Actor;

// To Create stickModel_leftUpperLeg
vtkNew<vtkCylinderSource> stickModel_leftUpperLeg_Source;
vtkNew<vtkPolyDataMapper> stickModel_leftUpperLeg_Mapper;
vtkNew<vtkTransform> stickModel_leftUpperLeg_Transform;
vtkNew<vtkActor> stickModel_leftUpperLeg_Actor;

// To Create stickModel_leftKnee
vtkNew<vtkSphereSource>  stickModel_leftKnee_Source;
vtkNew<vtkPolyDataMapper>  stickModel_leftKnee_Mapper;
vtkNew<vtkTransform>   stickModel_leftKnee_Transform;
vtkNew<vtkActor>   stickModel_leftKnee_Actor;

// To Create stickModel_leftLowerLeg
vtkNew<vtkCylinderSource> stickModel_leftLowerLeg_Source;
vtkNew<vtkPolyDataMapper> stickModel_leftLowerLeg_Mapper;
vtkNew<vtkTransform> stickModel_leftLowerLeg_Transform;
vtkNew<vtkActor> stickModel_leftLowerLeg_Actor;

// To Create stickModel_leftFoot
std::string stickModel_leftFoot_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader> stickModel_leftFoot_Reader;
vtkNew<vtkPolyDataMapper> stickModel_leftFoot_Mapper;
vtkNew<vtkTransform>stickModel_leftFoot_Transform;
vtkNew<vtkActor> stickModel_leftFoot_Actor;

// To Create the left foot outliner for IK
vtkSmartPointer<vtkOutlineFilter> lf_outlineFilter = vtkSmartPointer<vtkOutlineFilter>::New();
vtkSmartPointer<vtkPolyDataMapper>  lf_outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor>  lf_outlineActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform>  lf_outlineTransform = vtkSmartPointer<vtkTransform>::New();

int SMpl_angleX, SMpl_angleY, SMpl_angleZ;
int SManim_pl_angleX, SManim_pl_angleY, SManim_pl_angleZ;
int SMpl_x, SMpl_y, SMpl_z;

int SMch0_angleX, SMch0_angleY, SMch0_angleZ;
int SManim_ch0_angleX, SManim_ch0_angleY, SManim_ch0_angleZ;
int SMch0_x, SMch0_y, SMch0_z;

int SMrua_angleX, SMrua_angleY, SMrua_angleZ;
int SManim_rua_angleX, SManim_rua_angleY, SManim_rua_angleZ;
int SMrua_x, SMrua_y, SMrua_z;

int SMrla_angleX, SMrla_angleY, SMrla_angleZ;
int SManim_rla_angleX, SManim_rla_angleY, SManim_rla_angleZ;
int SMrla_x, SMrla_y, SMrla_z;

int SMrh_angleX, SMrh_angleY, SMrh_angleZ;
int SManim_rh_angleX, SManim_rh_angleY, SManim_rh_angleZ;
int SMrh_x, SMrh_y, SMrh_z;
bool rhIK_flag = 0;

int SMlua_angleX, SMlua_angleY, SMlua_angleZ;
int SManim_lua_angleX, SManim_lua_angleY, SManim_lua_angleZ;
int SMlua_x, SMlua_y, SMlua_z;

int SMlla_angleX, SMlla_angleY, SMlla_angleZ;
int SManim_lla_angleX, SManim_lla_angleY, SManim_lla_angleZ;
int SMlla_x, SMlla_y, SMlla_z;

int SMlh_angleX, SMlh_angleY, SMlh_angleZ;
int SManim_lh_angleX, SManim_lh_angleY, SManim_lh_angleZ;
int SMlh_x, SMlh_y, SMlh_z;
bool lhIK_flag = 0;

int SMrul_angleX, SMrul_angleY, SMrul_angleZ;
int SManim_rul_angleX = 0, SManim_rul_angleY, SManim_rul_angleZ;
int SMrul_x, SMrul_y, SMrul_z;

int SMrll_angleX, SMrll_angleY, SMrll_angleZ;
int SManim_rll_angleX, SManim_rll_angleY, SManim_rll_angleZ;
int SMrll_x, SMrll_y, SMrll_z;

int SMrf_angleX, SMrf_angleY, SMrf_angleZ;
int SManim_rf_angleX, SManim_rf_angleY, SManim_rf_angleZ;
int SMrf_x, SMrf_y, SMrf_z;
bool rfIK_flag = 0;

int SMlul_angleX, SMlul_angleY, SMlul_angleZ;
int SManim_lul_angleX = 0, SManim_lul_angleY, SManim_lul_angleZ;
int SMlul_x, SMlul_y, SMlul_z;

int SMlll_angleX, SMlll_angleY, SMlll_angleZ;
int SManim_lll_angleX, SManim_lll_angleY, SManim_lll_angleZ;
int SMlll_x, SMlll_y, SMlll_z;

int SMlf_angleX, SMlf_angleY, SMlf_angleZ;
int SManim_lf_angleX, SManim_lf_angleY, SManim_lf_angleZ;
int SMlf_x, SMlf_y, SMlf_z;
bool lfIK_flag = 0;

int captureCount = 0;

// for RightHand Inverse Kinematics
int rhIK_Targetx = 31;
int rhIK_Targety = 0;
int rhIK_Targetz = 0;

int lhIK_Targetx = 31;
int lhIK_Targety = 0;

int rfIK_Targetx = 31;
int rfIK_Targety = 0;

int lfIK_Targetx = 31;
int lfIK_Targety = 0;



//===============================================

int ffIK_rfTargetx = 31;
int ffIK_rfTargety = 0;

int ffIK_lfTargetx = 31;
int ffIK_lfTargety = 0;

int ffIK_rhTargetX = 31;
int ffIK_rhTargetY = 0;

int ffIK_lhTargetX = 31;
int ffIK_lhTargetY = 0;

int freeLF_Targetx = 31;
int freeLF_Targety = 0;

int freeRF_Targetx = 31;
int freeRF_Targety = 0;


const double epsilon = 0.0001;

int rhIK_screenX, rhIK_screenY;
int rhIK_screenDiff, rhIK_screenTemp, rhIK_screenPrev;

double rhIK_angle1;  // Angle of bone 1
double  rhIK_angle2;   // Angle of bone 2
bool rhIK_solvePosAngle2; // Solve for positive angle 2 instead of negative angle 2
double rhIK_length1 = 17;      // Length of bone 1. Assumed to be >= zero
double rhIK_length2 = 14;      // Length of bone 2. Assumed to be >= zero
double rhIK_target_X;     // Target x position for the bones to reach
double rhIK_target_Y;    // Target y position for the bones to reach

//const double epsilon = 0.0001;// used to prevent division by small numbers
double rhIK_targetDistSqr;
double rhIK_sinAngle2;
double rhIK_cosAngle2;
double rhIK_cosAngle2_denom;
bool rhIK_foundValidSolution = true;

//========================================= SRQ DATA - Sensed Raw Quaternions to Hierarchical Data =====================================

SphereUtility rawQuatFile;

//Quaternion raw data
quaternion  QuatData_PL[1024], QuatData_CH[1024],
QuatData_RUA[1024], QuatData_RLA[1024],
QuatData_LUA[1024], QuatData_LLA[1024],
QuatData_RUL[1024], QuatData_RLL[1024],
QuatData_LUL[1024], QuatData_LLL[1024];

//Quaternion SFQ data
quaternion sfq_QuatData_PL[1024], sfq_QuatData_CH[1024],
sfq_QuatData_RUA[1024], sfq_QuatData_RLA[1024],
sfq_QuatData_LUA[1024], sfq_QuatData_LLA[1024],
sfq_QuatData_RUL[1024], sfq_QuatData_RLL[1024],
sfq_QuatData_LUL[1024], sfq_QuatData_LLL[1024];

//Quaternion first inverse
quaternion firstQuat_Pelvis, firstQuat_Chest,
firstQuat_RightUpperArm, firstQuat_RightLowerArm,
firstQuat_LeftUpperArm, firstQuat_LeftLowerArm,
firstQuat_RightUpperLeg, firstQuat_RightLowerLeg,
firstQuat_LeftUpperLeg, firstQuat_LeftLowerLeg;

//Quaternion first inverse
quaternion firstInvQuat_Pelvis, firstInvQuat_Chest,
firstInvQuat_RightUpperArm, firstInvQuat_RightLowerArm,
firstInvQuat_LeftUpperArm, firstInvQuat_LeftLowerArm,
firstInvQuat_RightUpperLeg, firstInvQuat_RightLowerLeg,
firstInvQuat_LeftUpperLeg, firstInvQuat_LeftLowerLeg;

quaternion qInit = { 0,0,0,1 };
ofstream sfqQuat_dataFile;

vtkTransform* transform_srq[10] = { nullptr };
NodeManage Quatnode_srq;
int current_frames_srq = 0;
int loadframes_srq;
int ID_srq;
int mx_srq = 0;

bool IKflag_Status = 0;

bool fullbodyMS_Status = 1;


// For Stickmodel With both Foots Fixed 
// To Create IK_rightFoot

int ffIK_both, ffIK_RF, ffIK_LF = 0;

std::string IK_rightFoot_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader> IK_rightFoot_Reader;
vtkNew<vtkPolyDataMapper> IK_rightFoot_Mapper;
vtkNew<vtkTransform> IK_rightFoot_Transform;
vtkNew<vtkActor> IK_rightFoot_Actor;
double ffIK_F_x, ffIK_F_y, ffIK_F_z;

// To Create the right foot outliner for fixedFoots_IK
vtkSmartPointer<vtkOutlineFilter> ffIK_rf_outlineFilter = vtkSmartPointer<vtkOutlineFilter>::New();
vtkSmartPointer<vtkPolyDataMapper>  ffIK_rf_outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor>  ffIK_rf_outlineActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform>  ffIK_rf_outlineTransform = vtkSmartPointer<vtkTransform>::New();

// To Create IK_rightLowerLeg
vtkNew<vtkCylinderSource> IK_rightLowerLeg_Source;
vtkNew<vtkPolyDataMapper> IK_rightLowerLeg_Mapper;
vtkNew<vtkTransform>IK_rightLowerLeg_Transform;
vtkNew<vtkActor> IK_rightLowerLeg_Actor;
double ffIK_LL_x, ffIK_LL_y, ffIK_LL_z;

// To Create IK_rightKnee
vtkNew<vtkSphereSource>  IK_rightKnee_Source;
vtkNew<vtkPolyDataMapper>  IK_rightKnee_Mapper;
vtkNew<vtkTransform>   IK_rightKnee_Transform;
vtkNew<vtkActor>   IK_rightKnee_Actor;

// To Create IK_rightUpperLeg
vtkNew<vtkCylinderSource> IK_rightUpperLeg_Source;
vtkNew<vtkPolyDataMapper> IK_rightUpperLeg_Mapper;
vtkNew<vtkTransform> IK_rightUpperLeg_Transform;
vtkNew<vtkActor> IK_rightUpperLeg_Actor;
double ffIK_UL_x, ffIK_UL_y, ffIK_UL_z;

// To Create IK_rightLegJoint
vtkNew<vtkSphereSource> IK_rightLegJoint_Source;
vtkNew<vtkPolyDataMapper> IK_rightLegJoint_Mapper;
vtkNew<vtkTransform> IK_rightLegJoint_Transform;
vtkNew<vtkActor> IK_rightLegJoint_Actor;


// To Create IK_leftFoot
std::string IK_leftFoot_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader> IK_leftFoot_Reader;
vtkNew<vtkPolyDataMapper> IK_leftFoot_Mapper;
vtkNew<vtkTransform> IK_leftFoot_Transform;
vtkNew<vtkActor> IK_leftFoot_Actor;

// To Create the left foot outliner for fixedFoots_IK
vtkSmartPointer<vtkOutlineFilter> ffIK_lf_outlineFilter = vtkSmartPointer<vtkOutlineFilter>::New();
vtkSmartPointer<vtkPolyDataMapper>  ffIK_lf_outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor>  ffIK_lf_outlineActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform>  ffIK_lf_outlineTransform = vtkSmartPointer<vtkTransform>::New();


// To Create IK_leftLowerLeg
vtkNew<vtkCylinderSource> IK_leftLowerLeg_Source;
vtkNew<vtkPolyDataMapper> IK_leftLowerLeg_Mapper;
vtkNew<vtkTransform>IK_leftLowerLeg_Transform;
vtkNew<vtkActor> IK_leftLowerLeg_Actor;



// To Create IK_leftKnee
vtkNew<vtkSphereSource>  IK_leftKnee_Source;
vtkNew<vtkPolyDataMapper>  IK_leftKnee_Mapper;
vtkNew<vtkTransform>   IK_leftKnee_Transform;
vtkNew<vtkActor>   IK_leftKnee_Actor;

// To Create IK_leftUpperLeg
vtkNew<vtkCylinderSource> IK_leftUpperLeg_Source;
vtkNew<vtkPolyDataMapper> IK_leftUpperLeg_Mapper;
vtkNew<vtkTransform> IK_leftUpperLeg_Transform;
vtkNew<vtkActor> IK_leftUpperLeg_Actor;


// To Create IK_leftLegJoint
vtkNew<vtkSphereSource> IK_leftLegJoint_Source;
vtkNew<vtkPolyDataMapper> IK_leftLegJoint_Mapper;
vtkNew<vtkTransform> IK_leftLegJoint_Transform;
vtkNew<vtkActor> IK_leftLegJoint_Actor;

// To  IK_Create Pelvis
vtkNew<vtkSphereSource> IK_pelvisSource;
vtkNew<vtkPolyDataMapper> IK_pelvisMapper;
vtkNew<vtkTransform> IK_pelvisTransform;
vtkNew<vtkActor> IK_pelvisActor;
double ffIK_PL_x, ffIK_PL_y, ffIK_PL_z;

// To Create IK_Chest Links 
vtkNew<vtkSphereSource> IK_chest_0_Source;
vtkNew<vtkPolyDataMapper> IK_chest_0_Mapper;
vtkNew<vtkTransform> IK_chest_0_Transform;
vtkNew<vtkActor> IK_chest_0_Actor;
double ffIK_CH0_x, ffIK_CH0_y, ffIK_CH0_z;

vtkNew<vtkSphereSource> IK_chest_1_Source;
vtkNew<vtkPolyDataMapper> IK_chest_1_Mapper;
vtkNew<vtkTransform> IK_chest_1_Transform;
vtkNew<vtkActor> IK_chest_1_Actor;
double ffIK_CH1_x, ffIK_CH1_y, ffIK_CH1_z;

vtkNew<vtkSphereSource> IK_chest_2_Source;
vtkNew<vtkPolyDataMapper> IK_chest_2_Mapper;
vtkNew<vtkTransform> IK_chest_2_Transform;
vtkNew<vtkActor> IK_chest_2_Actor;
double ffIK_CH2_x, ffIK_CH2_y, ffIK_CH2_z;

vtkNew<vtkSphereSource> IK_chest_3_Source;
vtkNew<vtkPolyDataMapper> IK_chest_3_Mapper;
vtkNew<vtkTransform> IK_chest_3_Transform;
vtkNew<vtkActor> IK_chest_3_Actor;
double ffIK_CH3_x, ffIK_CH3_y, ffIK_CH3_z;

// To Create IK_head
std::string  IK_head_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader>  IK_head_Reader;
vtkNew<vtkPolyDataMapper>  IK_head_Mapper;
vtkNew<vtkTransform> IK_head_Transform;
vtkNew<vtkActor>  IK_head_Actor;
vtkNew<vtkTexture> IK_head_Texture;
vtkNew<vtkJPEGReader> IK_headTexture_Reader;


// To Create IK_rightShoulderJoint
vtkNew<vtkSphereSource> IK_rightShoulderJoint_Source;
vtkNew<vtkPolyDataMapper> IK_rightShoulderJoint_Mapper;
vtkNew<vtkTransform> IK_rightShoulderJoint_Transform;
vtkNew<vtkActor> IK_rightShoulderJoint_Actor;
double ffIK_Shoulder_x, ffIK_Shoulder_y, ffIK_Shoulder_z;

// To Create  IK_rightUpperArm
vtkNew<vtkCylinderSource>  IK_rightUpperArm_Source;
vtkNew<vtkPolyDataMapper>  IK_rightUpperArm_Mapper;
vtkNew<vtkTransform>  IK_rightUpperArm_Transform;
vtkNew<vtkActor>  IK_rightUpperArm_Actor;
double ffIK_UA_x, ffIK_UA_y, ffIK_UA_z;

// To Create rightElbow
vtkNew<vtkSphereSource>  IK_rightElbow_Source;
vtkNew<vtkPolyDataMapper>   IK_rightElbow_Mapper;
vtkNew<vtkTransform>   IK_rightElbow_Transform;
vtkNew<vtkActor>  IK_rightElbow_Actor;

// To Create rightLowerArm
vtkNew<vtkCylinderSource>  IK_rightLowerArm_Source;
vtkNew<vtkPolyDataMapper>  IK_rightLowerArm_Mapper;
vtkNew<vtkTransform>  IK_rightLowerArm_Transform;
vtkNew<vtkActor>  IK_rightLowerArm_Actor;
double ffIK_LA_x, ffIK_LA_y, ffIK_LA_z;

// To Create rightHand
std::string  IK_rightHand_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader>  IK_rightHand_Reader;
vtkNew<vtkPolyDataMapper>  IK_rightHand_Mapper;
vtkNew<vtkTransform>  IK_rightHand_Transform;
vtkNew<vtkActor>  IK_rightHand_Actor;
double ffIK_H_x, ffIK_H_y, ffIK_H_z;

// To Create the right hand outliner for fixedFoots_IK
vtkSmartPointer<vtkOutlineFilter> ffIK_rh_outlineFilter = vtkSmartPointer<vtkOutlineFilter>::New();
vtkSmartPointer<vtkPolyDataMapper>  ffIK_rh_outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor>  ffIK_rh_outlineActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform>  ffIK_rh_outlineTransform = vtkSmartPointer<vtkTransform>::New();

// To Create leftShoulderJoint
vtkNew<vtkSphereSource> IK_leftShoulderJoint_Source;
vtkNew<vtkPolyDataMapper> IK_leftShoulderJoint_Mapper;
vtkNew<vtkTransform>  IK_leftShoulderJoint_Transform;
vtkNew<vtkActor>  IK_leftShoulderJoint_Actor;
double ffIK_LShoulder_x, ffIK_LShoulder_y, ffIK_LShoulder_z;

// To Create leftUpperArm
vtkNew<vtkCylinderSource>  IK_leftUpperArm_Source;
vtkNew<vtkPolyDataMapper>  IK_leftUpperArm_Mapper;
vtkNew<vtkTransform>  IK_leftUpperArm_Transform;
vtkNew<vtkActor>  IK_leftUpperArm_Actor;
double ffIK_LUA_x, ffIK_LUA_y, ffIK_LUA_z;

// To Create leftElbow
vtkNew<vtkSphereSource>  IK_leftElbow_Source;
vtkNew<vtkPolyDataMapper>   IK_leftElbow_Mapper;
vtkNew<vtkTransform>   IK_leftElbow_Transform;
vtkNew<vtkActor>   IK_leftElbow_Actor;

// To Create leftLowerArm
vtkNew<vtkCylinderSource>  IK_leftLowerArm_Source;
vtkNew<vtkPolyDataMapper>  IK_leftLowerArm_Mapper;
vtkNew<vtkTransform>  IK_leftLowerArm_Transform;
vtkNew<vtkActor> IK_leftLowerArm_Actor;
double ffIK_LLA_x, ffIK_LLA_y, ffIK_LLA_z;

// To Create leftHand
std::string  IK_leftHand_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader>  IK_leftHand_Reader;
vtkNew<vtkPolyDataMapper>  IK_leftHand_Mapper;
vtkNew<vtkTransform> IK_leftHand_Transform;
vtkNew<vtkActor>  IK_leftHand_Actor;


// To Create the left hand outliner for fixedFoots_IK
vtkSmartPointer<vtkOutlineFilter> ffIK_lh_outlineFilter = vtkSmartPointer<vtkOutlineFilter>::New();
vtkSmartPointer<vtkPolyDataMapper>  ffIK_lh_outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor>  ffIK_lh_outlineActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform>  ffIK_lh_outlineTransform = vtkSmartPointer<vtkTransform>::New();

int ffIKpl_angleX, ffIKpl_angleY, ffIKpl_angleZ;
int ffIKanim_pl_angleX, ffIKanim_pl_angleY, ffIKanim_pl_angleZ;
int ffIKpl_x, ffIKpl_y, ffIKpl_z;

int ffIKch0_angleX, ffIKch0_angleY, ffIKch0_angleZ;
int ffIKanim_ch0_angleX, ffIKanim_ch0_angleY, ffIKanim_ch0_angleZ;
int ffIKch0_x, ffIKch0_y, ffIKch0_z;



int ffIKrua_angleX, ffIKrua_angleY, ffIKrua_angleZ;
int ffIKanim_rua_angleX, ffIKanim_rua_angleY, ffIKanim_rua_angleZ;
int ffIKrua_x, ffIKrua_y, ffIKrua_z;

int ffIKrla_angleX, ffIKrla_angleY, ffIKrla_angleZ;
int ffIKanim_rla_angleX, ffIKanim_rla_angleY, ffIKanim_rla_angleZ;
int ffIKrla_x, ffIKrla_y, ffIKrla_z;

int ffIKrh_angleX, ffIKrh_angleY, ffIKrh_angleZ;
int ffIKanim_rh_angleX, ffIKanim_rh_angleY, ffIKanim_rh_angleZ;
int ffIKrh_x, ffIKrh_y, ffIKrh_z;


int ffIKlua_angleX, ffIKlua_angleY, ffIKlua_angleZ;
int ffIKanim_lua_angleX, ffIKanim_lua_angleY, ffIKanim_lua_angleZ;
int ffIKlua_x, ffIKlua_y, ffIKlua_z;

int ffIKlla_angleX, ffIKlla_angleY, ffIKlla_angleZ;
int ffIKanim_lla_angleX, ffIKanim_lla_angleY, ffIKanim_lla_angleZ;
int ffIKlla_x, ffIKlla_y, ffIKlla_z;

int ffIKlh_angleX, ffIKlh_angleY, ffIKlh_angleZ;
int ffIKanim_lh_angleX, ffIKanim_lh_angleY, ffIKanim_lh_angleZ;
int ffIKlh_x, ffIKlh_y, ffIKlh_z;

int ffIKrul_angleX, ffIKrul_angleY, ffIKrul_angleZ;
int ffIKanim_rul_angleX = 0, ffIKanim_rul_angleY, ffIKanim_rul_angleZ;
int ffIKrul_x, ffIKrul_y, ffIKrul_z;

int ffIKrll_angleX, ffIKrll_angleY, ffIKrll_angleZ;
int ffIKanim_rll_angleX, ffIKanim_rll_angleY, ffIKanim_rll_angleZ;
int ffIKrll_x, ffIKrll_y, ffIKrll_z;

int ffIKrf_angleX, ffIKrf_angleY, ffIKrf_angleZ;
int ffIKanim_rf_angleX, ffIKanim_rf_angleY, ffIKanim_rf_angleZ;
int ffIKrf_x, ffIKrf_y, ffIKrf_z;

int ffIKlul_angleX, ffIKlul_angleY, ffIKlul_angleZ;
int ffIKanim_lul_angleX = 0, ffIKanim_lul_angleY, ffIKanim_lul_angleZ;
int ffIKlul_x, ffIKlul_y, ffIKlul_z;

int ffIKlll_angleX, ffIKlll_angleY, ffIKlll_angleZ;
int ffIKanim_lll_angleX, ffIKanim_lll_angleY, ffIKanim_lll_angleZ;
int ffIKlll_x, ffIKlll_y, ffIKlll_z;

int ffIKlf_angleX, ffIKlf_angleY, ffIKlf_angleZ;
int ffIKanim_lf_angleX, ffIKanim_lf_angleY, ffIKanim_lf_angleZ;
int ffIKlf_x, ffIKlf_y, ffIKlf_z;


// To Create IK_freeLeftFoot
std::string IK_freeLeftFoot_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader> IK_freeLeftFoot_Reader;
vtkNew<vtkPolyDataMapper> IK_freeLeftFoot_Mapper;
vtkNew<vtkTransform> IK_freeLeftFoot_Transform;
vtkNew<vtkActor> IK_freeLeftFoot_Actor;
int freeLF_x, freeLF_y, freeLF_z;

// To Create IK_freeLeftLowerLeg
vtkNew<vtkCylinderSource> IK_freeLeftLowerLeg_Source;
vtkNew<vtkPolyDataMapper> IK_freeLeftLowerLeg_Mapper;
vtkNew<vtkTransform>IK_freeLeftLowerLeg_Transform;
vtkNew<vtkActor> IK_freeLeftLowerLeg_Actor;
double freefootLLL_x, freefootLLL_y, freefootLLL_z;

// To Create IK_freeLeftKnee
vtkNew<vtkSphereSource>  IK_freeLeftKnee_Source;
vtkNew<vtkPolyDataMapper>  IK_freeLeftKnee_Mapper;
vtkNew<vtkTransform>   IK_freeLeftKnee_Transform;
vtkNew<vtkActor>   IK_freeLeftKnee_Actor;

// To Create IK_freeLeftUpperLeg
vtkNew<vtkCylinderSource> IK_freeLeftUpperLeg_Source;
vtkNew<vtkPolyDataMapper> IK_freeLeftUpperLeg_Mapper;
vtkNew<vtkTransform> IK_freeLeftUpperLeg_Transform;
vtkNew<vtkActor> IK_freeLeftUpperLeg_Actor;
double freefootLUL_x, freefootLUL_y, freefootLUL_z;

// To Create IK_freeLeftLegJoint
vtkNew<vtkSphereSource> IK_freeLeftLegJoint_Source;
vtkNew<vtkPolyDataMapper> IK_freeLeftLegJoint_Mapper;
vtkNew<vtkTransform> IK_freeLeftLegJoint_Transform;
vtkNew<vtkActor> IK_freeLeftLegJoint_Actor;


// To Create IK_freefreeRightFoot
std::string IK_freeRightFoot_objFile /*= "RH.obj"*/;
vtkNew<vtkOBJReader> IK_freeRightFoot_Reader;
vtkNew<vtkPolyDataMapper> IK_freeRightFoot_Mapper;
vtkNew<vtkTransform> IK_freeRightFoot_Transform;
vtkNew<vtkActor> IK_freeRightFoot_Actor;
int freeRF_x, freeRF_y, freeRF_z;

// To Create IK_freefreeRightLowerLeg
vtkNew<vtkCylinderSource> IK_freeRightLowerLeg_Source;
vtkNew<vtkPolyDataMapper> IK_freeRightLowerLeg_Mapper;
vtkNew<vtkTransform>IK_freeRightLowerLeg_Transform;
vtkNew<vtkActor> IK_freeRightLowerLeg_Actor;
double freefootRLL_x, freefootRLL_y, freefootRLL_z;

// To Create IK_freefreeRightKnee
vtkNew<vtkSphereSource>  IK_freeRightKnee_Source;
vtkNew<vtkPolyDataMapper>  IK_freeRightKnee_Mapper;
vtkNew<vtkTransform>   IK_freeRightKnee_Transform;
vtkNew<vtkActor>   IK_freeRightKnee_Actor;

// To Create IK_freefreeRightUpperLeg
vtkNew<vtkCylinderSource> IK_freeRightUpperLeg_Source;
vtkNew<vtkPolyDataMapper> IK_freeRightUpperLeg_Mapper;
vtkNew<vtkTransform> IK_freeRightUpperLeg_Transform;
vtkNew<vtkActor> IK_freeRightUpperLeg_Actor;
double freefootRUL_x, freefootRUL_y, freefootRUL_z;

// To Create IK_freefreeRightLegJoint
vtkNew<vtkSphereSource> IK_freeRightLegJoint_Source;
vtkNew<vtkPolyDataMapper> IK_freeRightLegJoint_Mapper;
vtkNew<vtkTransform> IK_freeRightLegJoint_Transform;
vtkNew<vtkActor> IK_freeRightLegJoint_Actor;

int srqUM_fileCount = 0;



auto RUA_collide = vtkSmartPointer<vtkCollisionDetectionFilter>::New();
auto matrix1 = vtkSmartPointer<vtkMatrix4x4>::New();
int contactMode = 2;

ofstream quatTo_posFile;


// Male Biped Model
void FOOT(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//CUconeTransform->Identity();
	RF_ObjReader_Transform->Translate(0, chest, 0);
	RF_ObjReader_Transform->RotateWXYZ(A, x, y, z);
	RF_ObjReader_Transform->Translate(0, -chest, 0);
	mRenderWindow->Render();
}
void HAND(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//CUconeTransform->Identity();
	RightHand_ObjReader_Transform->Translate(0, chest, 0);
	RightHand_ObjReader_Transform->RotateWXYZ(A, x, y, z);
	RightHand_ObjReader_Transform->Translate(0, -chest, 0);
	mRenderWindow->Render();
}
void HEAD(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//CUconeTransform->Identity();
	Head_ObjReader_Transform->Translate(0, chest, 0);
	Head_ObjReader_Transform->RotateWXYZ(A, x, y, z);
	Head_ObjReader_Transform->Translate(0, -chest, 0);
	mRenderWindow->Render();
}

void CHEST(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//CUconeTransform->Identity();
	CUconeTransform->Translate(0, chest, 0);
	CUconeTransform->RotateWXYZ(A, x, y, z);
	CUconeTransform->Translate(0, -chest, 0);
	mRenderWindow->Render();
}



void rua(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//RarmTransform->Identity();
	RarmTransform->Translate(-arm_X, arm_Y, 0);
	RarmTransform->RotateWXYZ(A, x, y, z);
	RarmTransform->Translate(arm_X, -arm_Y, 0);
	//RarmTransform->Identity();
	mRenderWindow->Render();
}
void rla(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//RarmTransform->Identity();
	RforearmTransform->Translate(-arm_X, arm_Y2, 0);
	RforearmTransform->RotateWXYZ(A, x, y, z);
	RforearmTransform->Translate(arm_X, -arm_Y2, 0);
	//RarmTransform->Identity();
	mRenderWindow->Render();
}

void inverseKinematicesRH(double ruaA, double rlaA, int x, int y, int z)
{
	//int angle1 = 0;
	//int angle2 = 0;

	//if (x != 0)
	//{
	//	std::cout << "input X " << std::endl;
	//	if (ruaA > totalAngleOfRUA)
	//	{
	//		angle1 = ruaA - totalAngleOfRUA;

	//		totalAngleOfRUA += angle1;
	//	}

	//	if (ruaA < totalAngleOfRUA)
	//	{
	//		angle1 = totalAngleOfRUA - ruaA;

	//		totalAngleOfRUA -= angle1;

	//		angle1 *= -1;
	//	}

	//	if (rlaA > totalAngleOfRLA)
	//	{
	//		angle2 = rlaA - totalAngleOfRLA;
	//		totalAngleOfRLA += angle2;

	//	}

	//	if (rlaA < totalAngleOfRLA)
	//	{
	//		angle2 = totalAngleOfRLA - rlaA;
	//		totalAngleOfRLA -= angle2;

	//		angle1 *= -1;
	//	}
	//}



	//std::cout << totalAngleOfRUA << std::endl;
	//std::cout << totalAngleOfRLA << std::endl;

	mRenderWindow->Render();
	//RarmTransform->Identity();
	RarmTransform->Translate(-arm_X, arm_Y, 0);
	RarmTransform->RotateWXYZ(ruaA, x, y, z);
	RarmTransform->Translate(arm_X, -arm_Y, 0);
	//RarmTransform->Identity();
	mRenderWindow->Render();
	

	mRenderWindow->Render();
	//RforearmTransform->Identity();
	RforearmTransform->Translate(-arm_X, arm_Y2, 0);
	RforearmTransform->RotateWXYZ(rlaA, x, y, z);
	RforearmTransform->Translate(arm_X, -arm_Y2, 0);
	//RforearmTransform->Identity();
	mRenderWindow->Render();

}

void lua(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//RarmTransform->Identity();
	LarmTransform->Translate(arm_X, arm_Y, 0);
	LarmTransform->RotateWXYZ(A, x, y, z);
	LarmTransform->Translate(-arm_X, -arm_Y, 0);
	//RarmTransform->Identity();
	mRenderWindow->Render();
}
void lla(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//RarmTransform->Identity();
	LforearmTransform->Translate(arm_X, arm_Y2, 0);
	LforearmTransform->RotateWXYZ(A, x, y, z);
	LforearmTransform->Translate(-arm_X, -arm_Y2, 0);
	//RarmTransform->Identity();
	mRenderWindow->Render();
}

void rul(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//RarmTransform->Identity();
	RlulegTransform->Translate(-leg_X, leg_Y, 0);
	RlulegTransform->RotateWXYZ(A, x, y, z);
	RlulegTransform->Translate(leg_X, -leg_Y, 0);
	//RarmTransform->Identity();
	mRenderWindow->Render();
}
void rll(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//RarmTransform->Identity();
	RllegTransform->Translate(-leg_X, leg_Y2, 0);
	RllegTransform->RotateWXYZ(A, x, y, z);
	RllegTransform->Translate(leg_X, -leg_Y2, 0);
	//RarmTransform->Identity();
	mRenderWindow->Render();
}

void lul(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//RarmTransform->Identity();
	LlulegTransform->Translate(leg_X, leg_Y, 0);
	LlulegTransform->RotateWXYZ(A, x, y, z);
	LlulegTransform->Translate(-leg_X, -leg_Y, 0);
	//RarmTransform->Identity();
	mRenderWindow->Render();
}
void lll(int A, int x, int y, int z)
{
	mRenderWindow->Render();
	//RarmTransform->Identity();
	LllegTransform->Translate(leg_X, leg_Y2, 0);
	LllegTransform->RotateWXYZ(A, x, y, z);
	LllegTransform->Translate(-leg_X, -leg_Y2, 0);
	//RarmTransform->Identity();
	mRenderWindow->Render();
}

// To animate Free Left Foot and Free Right Foot
void animateFreeLF(double lulA, double lllA, int x, int y, int z)
{
	IK_freeLeftUpperLeg_Transform->Identity();
	IK_freeLeftUpperLeg_Transform->Translate(-freefootLUL_x, freefootLUL_y, 0);
	IK_freeLeftUpperLeg_Transform->RotateWXYZ(lulA, x, y, z);
	IK_freeLeftUpperLeg_Transform->Translate(freefootLUL_x, -freefootLUL_y, 0);


	IK_freeLeftLowerLeg_Transform->Identity();
	IK_freeLeftLowerLeg_Transform->Translate(-freefootLLL_x, freefootLLL_y, 0);
	IK_freeLeftLowerLeg_Transform->RotateWXYZ(lllA, x, y, z);
	IK_freeLeftLowerLeg_Transform->Translate(freefootLLL_x, -freefootLLL_y, 0);
	mRenderWindow->Render();
}
void animateFreeRF(double rulA, double rllA, int x, int y, int z)
{
	IK_freeRightUpperLeg_Transform->Identity();
	IK_freeRightUpperLeg_Transform->Translate(-freefootRUL_x, freefootRUL_y, 0);
	IK_freeRightUpperLeg_Transform->RotateWXYZ(rulA, x, y, z);
	IK_freeRightUpperLeg_Transform->Translate(freefootRUL_x, -freefootRUL_y, 0);


	IK_freeRightLowerLeg_Transform->Identity();
	IK_freeRightLowerLeg_Transform->Translate(-freefootRLL_x, freefootRLL_y, 0);
	IK_freeRightLowerLeg_Transform->RotateWXYZ(rllA, x, y, z);
	IK_freeRightLowerLeg_Transform->Translate(freefootRLL_x, -freefootRLL_y, 0);
	mRenderWindow->Render();
}

// animation for skeleton Model 
void animateSM_CH0(int A, int x, int y, int z)
{
	//stickModel_chest_0_Transform->Identity();
	stickModel_chest_0_Transform->Translate(CH0_x, CH0_y, 0);
	stickModel_chest_0_Transform->RotateWXYZ(A, x, y, z);
	stickModel_chest_0_Transform->Translate(-CH0_x, -CH0_y, 0);
	mRenderWindow->Render();
}

void animateSM_RUA(int A, int x, int y, int z)
{
	//stickModel_rightUpperArm_Transform->Identity();
	stickModel_rightUpperArm_Transform->Translate(smUA_x, smUA_y, 0);
	stickModel_rightUpperArm_Transform->RotateWXYZ(A, x, y, z);
	stickModel_rightUpperArm_Transform->Translate(-smUA_x, -smUA_y, 0);
	mRenderWindow->Render();

}
void animateSM_RLA(int A, int x, int y, int z)
{
	//stickModel_rightLowerArm_Transform->Identity();
	stickModel_rightLowerArm_Transform->Translate(smLA_x, smLA_y, 0);
	stickModel_rightLowerArm_Transform->RotateWXYZ(A, x, y, z);
	stickModel_rightLowerArm_Transform->Translate(-smLA_x, -smLA_y, 0);
	mRenderWindow->Render();
}
void animateSM_ikRH(double ruaA, double rlaA, int x, int y, int z)
{
	//stickModel_rightUpperArm_Transform->Identity();
	//stickModel_rightUpperArm_Transform->Translate(smUA_x, smUA_y, 0);
	//stickModel_rightUpperArm_Transform->RotateWXYZ(ruaA, x, y, z);
	//stickModel_rightUpperArm_Transform->Translate(-smUA_x, -smUA_y, 0);
	//mRenderWindow->Render();

	//stickModel_rightLowerArm_Transform->Identity();
	//stickModel_rightLowerArm_Transform->Translate(smLA_x, smLA_y, 0);
	//stickModel_rightLowerArm_Transform->RotateWXYZ(rlaA, x, y, z);
	//stickModel_rightLowerArm_Transform->Translate(-smLA_x, -smLA_y, 0);
	//mRenderWindow->Render();

	RarmTransform->Identity();
	RarmTransform->Translate(smUA_x, smUA_y, 0);
	RarmTransform->RotateWXYZ(ruaA, x, y, z);
	RarmTransform->Translate(-smUA_x, -smUA_y, 0);
	mRenderWindow->Render();

	RforearmTransform->Identity();
	RforearmTransform->Translate(smLA_x, smLA_y, 0);
	RforearmTransform->RotateWXYZ(rlaA, x, y, z);
	RforearmTransform->Translate(-smLA_x, -smLA_y, 0);
	mRenderWindow->Render();


}
void animateSM_RH(int X)
{
	stickModel_rightHand_Transform->Identity();
	stickModel_rightHand_Transform->Translate(smH_x, smH_y, 0);
	stickModel_rightHand_Transform->RotateWXYZ(X, 1, 0, 0);

	mRenderWindow->Render();
}

void animateSM_LUA(int A, int x, int y, int z)
{
	//stickModel_leftUpperArm_Transform->Identity();
	stickModel_leftUpperArm_Transform->Translate(-smUA_x, smUA_y, 0);
	stickModel_leftUpperArm_Transform->RotateWXYZ(A, x, y, z);
	stickModel_leftUpperArm_Transform->Translate(smUA_x, -smUA_y, 0);
	mRenderWindow->Render();

}
void animateSM_LLA(int A, int x, int y, int z)
{
	//stickModel_leftLowerArm_Transform->Identity();
	stickModel_leftLowerArm_Transform->Translate(-smLA_x, smLA_y, 0);
	stickModel_leftLowerArm_Transform->RotateWXYZ(A, x, y, z);
	stickModel_leftLowerArm_Transform->Translate(smLA_x, -smLA_y, 0);
	mRenderWindow->Render();
}
void animateSM_ikLH(double luaA, double llaA, int x, int y, int z)
{
	stickModel_leftUpperArm_Transform->Identity();
	stickModel_leftUpperArm_Transform->Translate(-smUA_x, smUA_y, 0);
	stickModel_leftUpperArm_Transform->RotateWXYZ(luaA, x, y, z);
	stickModel_leftUpperArm_Transform->Translate(smUA_x, -smUA_y, 0);
	mRenderWindow->Render();

	stickModel_leftLowerArm_Transform->Identity();
	stickModel_leftLowerArm_Transform->Translate(-smLA_x, smLA_y, 0);
	stickModel_leftLowerArm_Transform->RotateWXYZ(llaA, x, y, z);
	stickModel_leftLowerArm_Transform->Translate(smLA_x, -smLA_y, 0);
	mRenderWindow->Render();
}
void animateSM_LH(int X)
{
	stickModel_leftHand_Transform->Identity();
	stickModel_leftHand_Transform->Translate(-smH_x, smH_y, 0);
	stickModel_leftHand_Transform->RotateWXYZ(X, 1, 0, 0);

	mRenderWindow->Render();
}

void animateSM_RUL(int A, int x, int y, int z)
{
	//stickModel_rightUpperLeg_Transform->Identity();
	stickModel_rightUpperLeg_Transform->Translate(smUL_x, smUL_y, 0);
	stickModel_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
	stickModel_rightUpperLeg_Transform->Translate(-smUL_x, -smUL_y, 0);
	mRenderWindow->Render();

}
void animateSM_RLL(int A, int x, int y, int z)
{
	//stickModel_rightLowerLeg_Transform->Identity();
	stickModel_rightLowerLeg_Transform->Translate(smLL_x, smLL_y, 0);
	stickModel_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
	stickModel_rightLowerLeg_Transform->Translate(-smLL_x, -smLL_y, 0);
	mRenderWindow->Render();
}
void animateSM_ikRF(double ruaA, double rlaA, int x, int y, int z)
{
	stickModel_rightUpperLeg_Transform->Identity();
	stickModel_rightUpperLeg_Transform->Translate(smUL_x, smUL_y, 0);
	stickModel_rightUpperLeg_Transform->RotateWXYZ(ruaA, x, y, z);
	stickModel_rightUpperLeg_Transform->Translate(-smUL_x, -smUL_y, 0);
	mRenderWindow->Render();

	stickModel_rightLowerLeg_Transform->Identity();
	stickModel_rightLowerLeg_Transform->Translate(smLL_x, smLL_y, 0);
	stickModel_rightLowerLeg_Transform->RotateWXYZ(rlaA, x, y, z);
	stickModel_rightLowerLeg_Transform->Translate(-smLL_x, -smLL_y, 0);
	mRenderWindow->Render();
}
void animateSM_RF(int X)
{
	stickModel_rightFoot_Transform->Identity();
	stickModel_rightFoot_Transform->Translate(smF_x, smF_y, 0);
	stickModel_rightFoot_Transform->RotateWXYZ(X, 1, 0, 0);
	mRenderWindow->Render();
}

void animateSM_LUL(int A, int x, int y, int z)
{
	//stickModel_leftUpperLeg_Transform->Identity();
	stickModel_leftUpperLeg_Transform->Translate(-smUL_x, smUL_y, 0);
	stickModel_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
	stickModel_leftUpperLeg_Transform->Translate(smUL_x, -smUL_y, 0);
	mRenderWindow->Render();

}
void animateSM_LLL(int A, int x, int y, int z)
{
	//stickModel_leftLowerLeg_Transform->Identity();
	stickModel_leftLowerLeg_Transform->Translate(-smLL_x, smLL_y, 0);
	stickModel_leftLowerLeg_Transform->RotateWXYZ(A, x, y, z);
	stickModel_leftLowerLeg_Transform->Translate(smLL_x, -smLL_y, 0);
	mRenderWindow->Render();
}
void animateSM_ikLF(double ruaA, double rlaA, int x, int y, int z)
{
	stickModel_leftUpperLeg_Transform->Identity();
	stickModel_leftUpperLeg_Transform->Translate(-smUL_x, smUL_y, 0);
	stickModel_leftUpperLeg_Transform->RotateWXYZ(ruaA, x, y, z);
	stickModel_leftUpperLeg_Transform->Translate(smUL_x, -smUL_y, 0);
	mRenderWindow->Render();

	stickModel_leftLowerLeg_Transform->Identity();
	stickModel_leftLowerLeg_Transform->Translate(-smLL_x, smLL_y, 0);
	stickModel_leftLowerLeg_Transform->RotateWXYZ(rlaA, x, y, z);
	stickModel_leftLowerLeg_Transform->Translate(smLL_x, -smLL_y, 0);
	mRenderWindow->Render();
}
void animateSM_LF(int X)
{
	stickModel_leftFoot_Transform->Identity();
	stickModel_leftFoot_Transform->Translate(-smF_x, smF_y, 0);
	stickModel_leftFoot_Transform->RotateWXYZ(X, 1, 0, 0);
	mRenderWindow->Render();
}


// animation for FixedFoot IK model
void animateffIK_xPL(double ULangle, double LLangle, int x, int y, int z)
{

	mRenderWindow->Render();
	IK_rightLowerLeg_Transform->Identity();
	IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
	IK_rightLowerLeg_Transform->RotateWXYZ(ULangle, x, y, z);
	IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);

	IK_rightUpperLeg_Transform->Identity();
	IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
	IK_rightUpperLeg_Transform->RotateWXYZ(LLangle, x, y, z);
	IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);


	IK_leftLowerLeg_Transform->Identity();
	IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
	IK_leftLowerLeg_Transform->RotateWXYZ(ULangle, x, y, z);
	IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);

	IK_leftUpperLeg_Transform->Identity();
	IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
	IK_leftUpperLeg_Transform->RotateWXYZ(LLangle, x, y, z);
	IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);


}
void animateffIK_PL(double ULangle, double LLangle, int x, int y, int z)
{

	/*mRenderWindow->Render();*/
	IK_chest_0_Transform->Identity();
	IK_chest_0_Transform->Translate(ffIK_CH0_x, ffIK_CH0_y, 0);
	IK_chest_0_Transform->RotateWXYZ(ULangle * 2.5, x, y, z);
	IK_chest_0_Transform->Translate(-ffIK_CH0_x, -ffIK_CH0_y, 0);

	IK_rightLowerLeg_Transform->Identity();
	IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
	IK_rightLowerLeg_Transform->RotateWXYZ(ULangle, x, y, z);
	IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);

	IK_rightUpperLeg_Transform->Identity();
	IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
	IK_rightUpperLeg_Transform->RotateWXYZ(LLangle, x, y, z);
	IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);


	IK_leftLowerLeg_Transform->Identity();
	IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
	IK_leftLowerLeg_Transform->RotateWXYZ(ULangle, x, y, z);
	IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);

	IK_leftUpperLeg_Transform->Identity();
	IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
	IK_leftUpperLeg_Transform->RotateWXYZ(LLangle, x, y, z);
	IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);

	mRenderWindow->Render();

}
void animateffIK_CH0(int A, int x, int y, int z)
{
	//IK_chest_0_Transform->Identity();
	IK_chest_0_Transform->Translate(ffIK_CH0_x, ffIK_CH0_y, 0);
	IK_chest_0_Transform->RotateWXYZ(A, x, y, z);
	IK_chest_0_Transform->Translate(-ffIK_CH0_x, -ffIK_CH0_y, 0);
	mRenderWindow->Render();
}

void animateffIK_RUA(int A, int x, int y, int z)
{
	//IK_rightUpperArm_Transform->Identity();
	IK_rightUpperArm_Transform->Translate(ffIK_UA_x, ffIK_UA_y, 0);
	IK_rightUpperArm_Transform->RotateWXYZ(A, x, y, z);
	IK_rightUpperArm_Transform->Translate(-ffIK_UA_x, -ffIK_UA_y, 0);
	mRenderWindow->Render();
}
void animateffIK_RLA(int A, int x, int y, int z)
{
	//IK_rightLowerArm_Transform->Identity();
	IK_rightLowerArm_Transform->Translate(ffIK_LA_x, ffIK_LA_y, 0);
	IK_rightLowerArm_Transform->RotateWXYZ(A, x, y, z);
	IK_rightLowerArm_Transform->Translate(-ffIK_LA_x, -ffIK_LA_y, 0);
	mRenderWindow->Render();
}
void animateffIK_RH(double ruaA, double rlaA, int x, int y, int z)
{

	IK_rightUpperArm_Transform->Identity();
	IK_rightUpperArm_Transform->Translate(ffIK_UA_x, ffIK_UA_y, 0);
	IK_rightUpperArm_Transform->RotateWXYZ(ruaA, x, y, z);
	IK_rightUpperArm_Transform->Translate(-ffIK_UA_x, -ffIK_UA_y, 0);


	IK_rightLowerArm_Transform->Identity();
	IK_rightLowerArm_Transform->Translate(ffIK_LA_x, ffIK_LA_y, 0);
	IK_rightLowerArm_Transform->RotateWXYZ(rlaA, x, y, z);
	IK_rightLowerArm_Transform->Translate(-ffIK_LA_x, -ffIK_LA_y, 0);
	mRenderWindow->Render();


}

void animateffIK_LUA(int A, int x, int y, int z)
{
	//IK_leftUpperArm_Transform->Identity();
	IK_leftUpperArm_Transform->Translate(ffIK_LUA_x, ffIK_LUA_y, 0);
	IK_leftUpperArm_Transform->RotateWXYZ(A, x, y, z);
	IK_leftUpperArm_Transform->Translate(-ffIK_LUA_x, -ffIK_LUA_y, 0);
	mRenderWindow->Render();
}
void animateffIK_LLA(int A, int x, int y, int z)
{
	//IK_leftLowerArm_Transform->Identity();
	IK_leftLowerArm_Transform->Translate(ffIK_LLA_x, ffIK_LLA_y, 0);
	IK_leftLowerArm_Transform->RotateWXYZ(A, x, y, z);
	IK_leftLowerArm_Transform->Translate(-ffIK_LLA_x, -ffIK_LLA_y, 0);
	mRenderWindow->Render();
}
void animateffIK_LH(double ruaA, double rlaA, int x, int y, int z)
{
	IK_leftUpperArm_Transform->Identity();
	IK_leftUpperArm_Transform->Translate(ffIK_UA_x, ffIK_UA_y, 0);
	IK_leftUpperArm_Transform->RotateWXYZ(ruaA, x, y, z);
	IK_leftUpperArm_Transform->Translate(-ffIK_UA_x, -ffIK_UA_y, 0);


	IK_leftLowerArm_Transform->Identity();
	IK_leftLowerArm_Transform->Translate(ffIK_LA_x, ffIK_LA_y, 0);
	IK_leftLowerArm_Transform->RotateWXYZ(rlaA, x, y, z);
	IK_leftLowerArm_Transform->Translate(-ffIK_LA_x, -ffIK_LA_y, 0);
	mRenderWindow->Render();
}


void animateffIK_RUL(int A, int x, int y, int z)
{

	if (ffIK_both == 1)
	{
		//IK_rightUpperLeg_Transform->Identity();
		IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
		IK_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);

		IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
		IK_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
		mRenderWindow->Render();

	}
	if (ffIK_RF == 1)
	{
		//IK_rightUpperLeg_Transform->Identity();
		IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
		IK_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
	}
	if (ffIK_LF == 1)
	{
		IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, ffIK_UL_y, 0);
		IK_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, -ffIK_UL_y, 0);
		mRenderWindow->Render();
	}
}
void animateffIK_RLL(int A, int x, int y, int z)
{
	if (ffIK_both == 1)
	{
		//IK_leftLowerLeg_Transform->Identity();
		IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
		IK_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);

		IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
		IK_leftLowerLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);

		mRenderWindow->Render();
	}
	if (ffIK_RF == 1)
	{
		//IK_leftLowerLeg_Transform->Identity();
		IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
		IK_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);

		mRenderWindow->Render();
	}
	if (ffIK_LF == 1)
	{
		IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, -ffIK_LL_y, 0);
		IK_leftLowerLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, ffIK_LL_y, 0);

		mRenderWindow->Render();
	}

}


void animateffIK_LUL(int A, int x, int y, int z)
{

	if (ffIK_both == 1)
	{
		//IK_leftUpperLeg_Transform->Identity();
		IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
		IK_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);

		//IK_rightUpperLeg_Transform->Identity();
		IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
		IK_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);

		mRenderWindow->Render();
	}
	if (ffIK_RF == 1)
	{
		//IK_rightUpperLeg_Transform->Identity();
		IK_rightUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
		IK_rightUpperLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_rightUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);

		mRenderWindow->Render();

	}
	if (ffIK_LF == 1)
	{
		//IK_leftUpperLeg_Transform->Identity();
		IK_leftUpperLeg_Transform->Translate(ffIK_UL_x, ffIK_UL_y, 0);
		IK_leftUpperLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_leftUpperLeg_Transform->Translate(-ffIK_UL_x, -ffIK_UL_y, 0);

		mRenderWindow->Render();
	}

}
void animateffIK_LLL(int A, int x, int y, int z)
{

	if (ffIK_both == 1)
	{
		//IK_leftLowerLeg_Transform->Identity();
		IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
		IK_leftLowerLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);

		//IK_leftLowerLeg_Transform->Identity();
		IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
		IK_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);

		mRenderWindow->Render();
	}
	if (ffIK_RF == 1)
	{
		//IK_leftLowerLeg_Transform->Identity();
		IK_rightLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
		IK_rightLowerLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_rightLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);

		mRenderWindow->Render();
	}
	if (ffIK_LF == 1)
	{
		//IK_leftLowerLeg_Transform->Identity();
		IK_leftLowerLeg_Transform->Translate(-ffIK_LL_x, -ffIK_LL_y, 0);
		IK_leftLowerLeg_Transform->RotateWXYZ(A, x, y, z);
		IK_leftLowerLeg_Transform->Translate(ffIK_LL_x, ffIK_LL_y, 0);

		mRenderWindow->Render();

	}

}
void computeSM_ikRH(int temptarget_X, int temptarget_Y, int x, int y, int z, int boneID)
{
	rhIK_target_X = temptarget_X;
	rhIK_target_Y = temptarget_Y;
	rhIK_targetDistSqr = (rhIK_target_X * rhIK_target_X + rhIK_target_Y * rhIK_target_Y);
	rhIK_cosAngle2_denom = 2 * rhIK_length1 * rhIK_length2;
	std::cout << "rhIK_cosAngle2_denom " << rhIK_cosAngle2_denom << std::endl;
	std::cout << "rhIK_targetDistSqr " << rhIK_targetDistSqr << std::endl;

	if (rhIK_cosAngle2_denom > epsilon)
	{
		rhIK_cosAngle2 = (rhIK_targetDistSqr - rhIK_length1 * rhIK_length1 - rhIK_length2 * rhIK_length2) / (rhIK_cosAngle2_denom);
		if ((rhIK_cosAngle2 < -1.0) || (rhIK_cosAngle2 > 1.0))
		{
			rhIK_foundValidSolution = false;
		}
		double rhIK_tempMin;
		rhIK_tempMin = min(1.0, rhIK_cosAngle2);
		rhIK_cosAngle2 = max(-1.0, rhIK_tempMin);
		rhIK_angle2 = acos(rhIK_cosAngle2);
		if (!rhIK_solvePosAngle2)
		{
			rhIK_angle2 = -rhIK_angle2;
		}
		rhIK_sinAngle2 = sin(rhIK_angle2);

	}
	else
	{
		double rhIK_totalLenSqr = (rhIK_length1 + rhIK_length2) * (rhIK_length1 + rhIK_length2);
		if (rhIK_targetDistSqr < (rhIK_totalLenSqr - epsilon) || rhIK_targetDistSqr >(rhIK_totalLenSqr + epsilon))
		{
			rhIK_foundValidSolution = false;
		}
		rhIK_angle2 = 0.0;
		rhIK_cosAngle2 = 1.0;
		rhIK_sinAngle2 = 0.0;
	}

	double rhIK_triAdjacent = rhIK_length1 + rhIK_length2 * rhIK_cosAngle2;
	double rhIK_triOpposite = rhIK_length2 * rhIK_sinAngle2;

	double rhIK_tanY = rhIK_target_Y * rhIK_triAdjacent - rhIK_target_X * rhIK_triOpposite;
	double rhIK_tanX = rhIK_target_X * rhIK_triAdjacent + rhIK_target_Y * rhIK_triOpposite;
	rhIK_angle1 = atan2(rhIK_tanY, rhIK_tanX);


	double rhIK_theta1 = rhIK_angle1 * 180 / PI;
	double rhIK_theta2 = rhIK_angle2 * 180 / PI;

	inverseKinematices_Theta_1 = rhIK_theta1;
	inverseKinematices_Theta_2 = rhIK_theta2;
	//cout <<"  theta1=" << rhIK_theta1 << "\t" << "theta2=" << rhIK_theta2 << endl;
	//cout << rhIK_Targetz << "testTargetx:" << rhIK_Targetx << "\t" << "testTargety:" << rhIK_Targety << "\t" << "theta1=" << rhIK_theta1 << "\t" << "theta2=" << rhIK_theta2 << endl;

	if (boneID == 10)
	{
		//animateSM_ikRH(rhIK_theta1, rhIK_theta2, x, y, z);


		std::cout << "inverse Kinematices In " << x << " " << y << " " << z << std::endl;

		if (b_draw_endPose)
			inverseKinematicesRH(rhIK_theta1, rhIK_theta2, x, y, z);

		// rightUpperArm
		qxIK[2].setW(cos(-rhIK_theta1 * PI / 180 / 2));
		qxIK[2].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
		qxIK[2].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
		qxIK[2].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

		xaxisQX_IK[2].setW(cos(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[2].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[2].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[2].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

		xaxisQY_IK[2].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[2].setX(0);
		xaxisQY_IK[2].setY(sin(0 / 2));
		xaxisQY_IK[2].setZ(sin(0 / 2));

		xaxisQZ_IK[2].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[2].setX(0);
		xaxisQZ_IK[2].setY(sin(0 / 2));
		xaxisQZ_IK[2].setZ(sin(0 / 2));

		xaxisQP_IK[2] = xaxisQX_IK[2].multiply(xaxisQY_IK[2].multiply(xaxisQZ_IK[2]));

		//rightLowerArm
		qxIK[3].setW(cos(-rhIK_theta2 * PI / 180 / 2));
		qxIK[3].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
		qxIK[3].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
		qxIK[3].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

		xaxisQX_IK[3].setW(cos(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[3].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[3].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[3].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

		xaxisQY_IK[3].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[3].setX(0);
		xaxisQY_IK[3].setY(sin(0 / 2));
		xaxisQY_IK[3].setZ(sin(0 / 2));

		xaxisQZ_IK[3].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[3].setX(0);
		xaxisQZ_IK[3].setY(sin(0 / 2));
		xaxisQZ_IK[3].setZ(sin(0 / 2));

		xaxisQP_IK[3] = xaxisQX_IK[3].multiply(xaxisQY_IK[3].multiply(xaxisQZ_IK[3]));
	}
	if (boneID == 15)
	{
		animateSM_ikLH(rhIK_theta1, rhIK_theta2, x, y, z);

		// leftUpperArm
		qxIK[4].setW(cos(-rhIK_theta1 * PI / 180 / 2));
		qxIK[4].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
		qxIK[4].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
		qxIK[4].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

		xaxisQX_IK[4].setW(cos(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[4].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[4].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[4].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

		xaxisQY_IK[4].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[4].setX(0);
		xaxisQY_IK[4].setY(sin(0 / 2));
		xaxisQY_IK[4].setZ(sin(0 / 2));

		xaxisQZ_IK[4].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[4].setX(0);
		xaxisQZ_IK[4].setY(sin(0 / 2));
		xaxisQZ_IK[4].setZ(sin(0 / 2));

		xaxisQP_IK[4] = xaxisQX_IK[4].multiply(xaxisQY_IK[4].multiply(xaxisQZ_IK[4]));

		//LeftLowerArm
		qxIK[5].setW(cos(-rhIK_theta2 * PI / 180 / 2));
		qxIK[5].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
		qxIK[5].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
		qxIK[5].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

		xaxisQX_IK[5].setW(cos(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[5].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[5].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[5].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

		xaxisQY_IK[5].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[5].setX(0);
		xaxisQY_IK[5].setY(sin(0 / 2));
		xaxisQY_IK[5].setZ(sin(0 / 2));

		xaxisQZ_IK[5].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[5].setX(0);
		xaxisQZ_IK[5].setY(sin(0 / 2));
		xaxisQZ_IK[5].setZ(sin(0 / 2));

		xaxisQP_IK[5] = xaxisQX_IK[5].multiply(xaxisQY_IK[5].multiply(xaxisQZ_IK[5]));

	}
	if (boneID == 16)
	{
		animateSM_ikRF(-rhIK_theta1, -rhIK_theta2, x, y, z);

		// rightUpperLeg
		qxIK[6].setW(cos(-rhIK_theta1 * PI / 180 / 2));
		qxIK[6].setX(1 * sin(rhIK_theta1 * PI / 180 / 2));
		qxIK[6].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
		qxIK[6].setZ(0 * sin(rhIK_theta1 * PI / 180 / 2));

		xaxisQX_IK[6].setW(cos(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[6].setX(1 * sin(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[6].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[6].setZ(0 * sin(rhIK_theta1 * PI / 180 / 2));

		xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[6].setX(0);
		xaxisQY_IK[6].setY(sin(0 / 2));
		xaxisQY_IK[6].setZ(sin(0 / 2));

		xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[6].setX(0);
		xaxisQZ_IK[6].setY(sin(0 / 2));
		xaxisQZ_IK[6].setZ(sin(0 / 2));

		xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));

		//rightLowerLeg
		qxIK[7].setW(cos(rhIK_theta2 * PI / 180 / 2));
		qxIK[7].setX(1 * sin(rhIK_theta2 * PI / 180 / 2));
		qxIK[7].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
		qxIK[7].setZ(0 * sin(rhIK_theta2 * PI / 180 / 2));

		xaxisQX_IK[7].setW(cos(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[7].setX(1 * sin(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[7].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[7].setZ(0 * sin(rhIK_theta2 * PI / 180 / 2));

		xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[7].setX(0);
		xaxisQY_IK[7].setY(sin(0 / 2));
		xaxisQY_IK[7].setZ(sin(0 / 2));

		xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[7].setX(0);
		xaxisQZ_IK[7].setY(sin(0 / 2));
		xaxisQZ_IK[7].setZ(sin(0 / 2));

		xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));

	}
	if (boneID == 21)
	{
		animateSM_ikLF(-rhIK_theta1, -rhIK_theta2, x, y, z);

		// leftUpperLeg
		qxIK[8].setW(cos(rhIK_theta1 * PI / 180 / 2));
		qxIK[8].setX(1 * sin(rhIK_theta1 * PI / 180 / 2));
		qxIK[8].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
		qxIK[8].setZ(0 * sin(rhIK_theta1 * PI / 180 / 2));

		xaxisQX_IK[8].setW(cos(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[8].setX(1 * sin(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[8].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[8].setZ(0 * sin(rhIK_theta1 * PI / 180 / 2));

		xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[8].setX(0);
		xaxisQY_IK[8].setY(sin(0 / 2));
		xaxisQY_IK[8].setZ(sin(0 / 2));

		xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[8].setX(0);
		xaxisQZ_IK[8].setY(sin(0 / 2));
		xaxisQZ_IK[8].setZ(sin(0 / 2));

		xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));

		//leftLowerLeg
		qxIK[9].setW(cos(rhIK_theta2 * PI / 180 / 2));
		qxIK[9].setX(1 * sin(rhIK_theta2 * PI / 180 / 2));
		qxIK[9].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
		qxIK[9].setZ(0 * sin(rhIK_theta2 * PI / 180 / 2));

		xaxisQX_IK[9].setW(cos(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[9].setX(1 * sin(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[9].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[9].setZ(0 * sin(rhIK_theta2 * PI / 180 / 2));

		xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[9].setX(0);
		xaxisQY_IK[9].setY(sin(0 / 2));
		xaxisQY_IK[9].setZ(sin(0 / 2));

		xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[9].setX(0);
		xaxisQZ_IK[9].setY(sin(0 / 2));
		xaxisQZ_IK[9].setZ(sin(0 / 2));

		xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
	}



	//=======================================================================================================================================================================
	if (boneID == 500)
	{
		if (flag == 1)
		{
			animateffIK_PL(rhIK_theta1, rhIK_theta2, x, y, z);


			// rightUpperLeg
			qxIK[1].setW(cos((-rhIK_theta1 * 2.5) * PI / 180 / 2));
			qxIK[1].setX(1 * sin((-rhIK_theta1 * 2.5) * PI / 180 / 2));
			qxIK[1].setY(0 * sin((-rhIK_theta1 * 2.5) * PI / 180 / 2));
			qxIK[1].setZ(0 * sin((-rhIK_theta1 * 2.5) * PI / 180 / 2));

			xaxisQX_IK[1].setW(cos((-rhIK_theta1 * 2.5) * PI / 180 / 2));
			xaxisQX_IK[1].setX(1 * sin((-rhIK_theta1 * 2.5) * PI / 180 / 2));
			xaxisQX_IK[1].setY(0 * sin((-rhIK_theta1 * 2.5) * PI / 180 / 2));
			xaxisQX_IK[1].setZ(0 * sin((-rhIK_theta1 * 2.5) * PI / 180 / 2));

			xaxisQY_IK[1].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQY_IK[1].setX(0);
			xaxisQY_IK[1].setY(sin(0 / 2));
			xaxisQY_IK[1].setZ(sin(0 / 2));

			xaxisQZ_IK[1].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQZ_IK[1].setX(0);
			xaxisQZ_IK[1].setY(sin(0 / 2));
			xaxisQZ_IK[1].setZ(sin(0 / 2));

			xaxisQP_IK[1] = xaxisQX_IK[1].multiply(xaxisQY_IK[1].multiply(xaxisQZ_IK[1]));

			if (ffIK_both == 1)
			{

				// rightUpperLeg
				qxIK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
				qxIK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
				qxIK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
				qxIK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

				xaxisQX_IK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

				xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQY_IK[6].setX(0);
				xaxisQY_IK[6].setY(sin(0 / 2));
				xaxisQY_IK[6].setZ(sin(0 / 2));

				xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQZ_IK[6].setX(0);
				xaxisQZ_IK[6].setY(sin(0 / 2));
				xaxisQZ_IK[6].setZ(sin(0 / 2));

				xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));

				//rightLowerLeg
				qxIK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
				qxIK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
				qxIK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
				qxIK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

				xaxisQX_IK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

				xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQY_IK[7].setX(0);
				xaxisQY_IK[7].setY(sin(0 / 2));
				xaxisQY_IK[7].setZ(sin(0 / 2));

				xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQZ_IK[7].setX(0);
				xaxisQZ_IK[7].setY(sin(0 / 2));
				xaxisQZ_IK[7].setZ(sin(0 / 2));

				xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));


				// leftUpperLeg
				qxIK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
				qxIK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
				qxIK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
				qxIK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

				xaxisQX_IK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

				xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQY_IK[8].setX(0);
				xaxisQY_IK[8].setY(sin(0 / 2));
				xaxisQY_IK[8].setZ(sin(0 / 2));

				xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQZ_IK[8].setX(0);
				xaxisQZ_IK[8].setY(sin(0 / 2));
				xaxisQZ_IK[8].setZ(sin(0 / 2));

				xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));

				//leftLowerLeg
				qxIK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
				qxIK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
				qxIK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
				qxIK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

				xaxisQX_IK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

				xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQY_IK[9].setX(0);
				xaxisQY_IK[9].setY(sin(0 / 2));
				xaxisQY_IK[9].setZ(sin(0 / 2));

				xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQZ_IK[9].setX(0);
				xaxisQZ_IK[9].setY(sin(0 / 2));
				xaxisQZ_IK[9].setZ(sin(0 / 2));

				xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
			}
			if (ffIK_RF == 1)
			{

				// rightUpperLeg
				qxIK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
				qxIK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
				qxIK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
				qxIK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

				xaxisQX_IK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

				xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQY_IK[6].setX(0);
				xaxisQY_IK[6].setY(sin(0 / 2));
				xaxisQY_IK[6].setZ(sin(0 / 2));

				xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQZ_IK[6].setX(0);
				xaxisQZ_IK[6].setY(sin(0 / 2));
				xaxisQZ_IK[6].setZ(sin(0 / 2));

				xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));

				//rightLowerLeg
				qxIK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
				qxIK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
				qxIK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
				qxIK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

				xaxisQX_IK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

				xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQY_IK[7].setX(0);
				xaxisQY_IK[7].setY(sin(0 / 2));
				xaxisQY_IK[7].setZ(sin(0 / 2));

				xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQZ_IK[7].setX(0);
				xaxisQZ_IK[7].setY(sin(0 / 2));
				xaxisQZ_IK[7].setZ(sin(0 / 2));

				xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));

			}
			if (ffIK_LF == 1)
			{
				// leftUpperLeg
				qxIK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
				qxIK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
				qxIK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
				qxIK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

				xaxisQX_IK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
				xaxisQX_IK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

				xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQY_IK[8].setX(0);
				xaxisQY_IK[8].setY(sin(0 / 2));
				xaxisQY_IK[8].setZ(sin(0 / 2));

				xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQZ_IK[8].setX(0);
				xaxisQZ_IK[8].setY(sin(0 / 2));
				xaxisQZ_IK[8].setZ(sin(0 / 2));

				xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));

				//leftLowerLeg
				qxIK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
				qxIK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
				qxIK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
				qxIK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

				xaxisQX_IK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
				xaxisQX_IK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

				xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQY_IK[9].setX(0);
				xaxisQY_IK[9].setY(sin(0 / 2));
				xaxisQY_IK[9].setZ(sin(0 / 2));

				xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
				xaxisQZ_IK[9].setX(0);
				xaxisQZ_IK[9].setY(sin(0 / 2));
				xaxisQZ_IK[9].setZ(sin(0 / 2));

				xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
			}





		}
		if (flag == 2)
		{
			animateffIK_xPL(rhIK_theta1, rhIK_theta2, x, y, z);


			// rightUpperLeg
			qxIK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
			qxIK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
			qxIK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
			qxIK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

			xaxisQX_IK[6].setW(cos(-rhIK_theta2 * PI / 180 / 2));
			xaxisQX_IK[6].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
			xaxisQX_IK[6].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
			xaxisQX_IK[6].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

			xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQY_IK[6].setX(0);
			xaxisQY_IK[6].setY(sin(0 / 2));
			xaxisQY_IK[6].setZ(sin(0 / 2));

			xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQZ_IK[6].setX(0);
			xaxisQZ_IK[6].setY(sin(0 / 2));
			xaxisQZ_IK[6].setZ(sin(0 / 2));

			xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));

			//rightLowerLeg
			qxIK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
			qxIK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
			qxIK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
			qxIK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

			xaxisQX_IK[7].setW(cos(-rhIK_theta1 * PI / 180 / 2));
			xaxisQX_IK[7].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
			xaxisQX_IK[7].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
			xaxisQX_IK[7].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

			xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQY_IK[7].setX(0);
			xaxisQY_IK[7].setY(sin(0 / 2));
			xaxisQY_IK[7].setZ(sin(0 / 2));

			xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQZ_IK[7].setX(0);
			xaxisQZ_IK[7].setY(sin(0 / 2));
			xaxisQZ_IK[7].setZ(sin(0 / 2));

			xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));


			// leftUpperLeg
			qxIK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
			qxIK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
			qxIK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
			qxIK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

			xaxisQX_IK[8].setW(cos(-rhIK_theta2 * PI / 180 / 2));
			xaxisQX_IK[8].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
			xaxisQX_IK[8].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
			xaxisQX_IK[8].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

			xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQY_IK[8].setX(0);
			xaxisQY_IK[8].setY(sin(0 / 2));
			xaxisQY_IK[8].setZ(sin(0 / 2));

			xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQZ_IK[8].setX(0);
			xaxisQZ_IK[8].setY(sin(0 / 2));
			xaxisQZ_IK[8].setZ(sin(0 / 2));

			xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));

			//leftLowerLeg
			qxIK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
			qxIK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
			qxIK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
			qxIK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

			xaxisQX_IK[9].setW(cos(-rhIK_theta1 * PI / 180 / 2));
			xaxisQX_IK[9].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
			xaxisQX_IK[9].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
			xaxisQX_IK[9].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

			xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQY_IK[9].setX(0);
			xaxisQY_IK[9].setY(sin(0 / 2));
			xaxisQY_IK[9].setZ(sin(0 / 2));

			xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
			xaxisQZ_IK[9].setX(0);
			xaxisQZ_IK[9].setY(sin(0 / 2));
			xaxisQZ_IK[9].setZ(sin(0 / 2));

			xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
		}

	}

	if (boneID == 510)
	{
		animateffIK_RH(rhIK_theta1, rhIK_theta2, x, y, z);
		// rightUpperArm
		qxIK[2].setW(cos(-rhIK_theta1 * PI / 180 / 2));
		qxIK[2].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
		qxIK[2].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
		qxIK[2].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

		xaxisQX_IK[2].setW(cos(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[2].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[2].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[2].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

		xaxisQY_IK[2].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[2].setX(0);
		xaxisQY_IK[2].setY(sin(0 / 2));
		xaxisQY_IK[2].setZ(sin(0 / 2));

		xaxisQZ_IK[2].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[2].setX(0);
		xaxisQZ_IK[2].setY(sin(0 / 2));
		xaxisQZ_IK[2].setZ(sin(0 / 2));

		xaxisQP_IK[2] = xaxisQX_IK[2].multiply(xaxisQY_IK[2].multiply(xaxisQZ_IK[2]));

		//rightLowerArm
		qxIK[3].setW(cos(-rhIK_theta2 * PI / 180 / 2));
		qxIK[3].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
		qxIK[3].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
		qxIK[3].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

		xaxisQX_IK[3].setW(cos(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[3].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[3].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[3].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

		xaxisQY_IK[3].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[3].setX(0);
		xaxisQY_IK[3].setY(sin(0 / 2));
		xaxisQY_IK[3].setZ(sin(0 / 2));

		xaxisQZ_IK[3].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[3].setX(0);
		xaxisQZ_IK[3].setY(sin(0 / 2));
		xaxisQZ_IK[3].setZ(sin(0 / 2));

		xaxisQP_IK[3] = xaxisQX_IK[3].multiply(xaxisQY_IK[3].multiply(xaxisQZ_IK[3]));


	}
	if (boneID == 511)
	{
		animateffIK_LH(rhIK_theta1, rhIK_theta2, x, y, z);

		// leftUpperArm
		qxIK[4].setW(cos(-rhIK_theta1 * PI / 180 / 2));
		qxIK[4].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
		qxIK[4].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
		qxIK[4].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

		xaxisQX_IK[4].setW(cos(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[4].setX(1 * sin(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[4].setY(0 * sin(-rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[4].setZ(0 * sin(-rhIK_theta1 * PI / 180 / 2));

		xaxisQY_IK[4].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[4].setX(0);
		xaxisQY_IK[4].setY(sin(0 / 2));
		xaxisQY_IK[4].setZ(sin(0 / 2));

		xaxisQZ_IK[4].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[4].setX(0);
		xaxisQZ_IK[4].setY(sin(0 / 2));
		xaxisQZ_IK[4].setZ(sin(0 / 2));

		xaxisQP_IK[4] = xaxisQX_IK[4].multiply(xaxisQY_IK[4].multiply(xaxisQZ_IK[4]));

		//LeftLowerArm
		qxIK[5].setW(cos(-rhIK_theta2 * PI / 180 / 2));
		qxIK[5].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
		qxIK[5].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
		qxIK[5].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

		xaxisQX_IK[5].setW(cos(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[5].setX(1 * sin(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[5].setY(0 * sin(-rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[5].setZ(0 * sin(-rhIK_theta2 * PI / 180 / 2));

		xaxisQY_IK[5].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[5].setX(0);
		xaxisQY_IK[5].setY(sin(0 / 2));
		xaxisQY_IK[5].setZ(sin(0 / 2));

		xaxisQZ_IK[5].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[5].setX(0);
		xaxisQZ_IK[5].setY(sin(0 / 2));
		xaxisQZ_IK[5].setZ(sin(0 / 2));

		xaxisQP_IK[5] = xaxisQX_IK[5].multiply(xaxisQY_IK[5].multiply(xaxisQZ_IK[5]));
	}

	//========================================================================================================================================================================



	if (boneID == 1003)
	{
		animateFreeLF(-rhIK_theta1, -rhIK_theta2, x, y, z);

		// leftUpperLeg
		qxIK[8].setW(cos(rhIK_theta1 * PI / 180 / 2));
		qxIK[8].setX(1 * sin(rhIK_theta1 * PI / 180 / 2));
		qxIK[8].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
		qxIK[8].setZ(0 * sin(rhIK_theta1 * PI / 180 / 2));

		xaxisQX_IK[8].setW(cos(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[8].setX(1 * sin(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[8].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[8].setZ(0 * sin(rhIK_theta1 * PI / 180 / 2));

		xaxisQY_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[8].setX(0);
		xaxisQY_IK[8].setY(sin(0 / 2));
		xaxisQY_IK[8].setZ(sin(0 / 2));

		xaxisQZ_IK[8].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[8].setX(0);
		xaxisQZ_IK[8].setY(sin(0 / 2));
		xaxisQZ_IK[8].setZ(sin(0 / 2));

		xaxisQP_IK[8] = xaxisQX_IK[8].multiply(xaxisQY_IK[8].multiply(xaxisQZ_IK[8]));

		//leftLowerLeg
		qxIK[9].setW(cos(rhIK_theta2 * PI / 180 / 2));
		qxIK[9].setX(1 * sin(rhIK_theta2 * PI / 180 / 2));
		qxIK[9].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
		qxIK[9].setZ(0 * sin(rhIK_theta2 * PI / 180 / 2));

		xaxisQX_IK[9].setW(cos(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[9].setX(1 * sin(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[9].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[9].setZ(0 * sin(rhIK_theta2 * PI / 180 / 2));

		xaxisQY_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[9].setX(0);
		xaxisQY_IK[9].setY(sin(0 / 2));
		xaxisQY_IK[9].setZ(sin(0 / 2));

		xaxisQZ_IK[9].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[9].setX(0);
		xaxisQZ_IK[9].setY(sin(0 / 2));
		xaxisQZ_IK[9].setZ(sin(0 / 2));

		xaxisQP_IK[9] = xaxisQX_IK[9].multiply(xaxisQY_IK[9].multiply(xaxisQZ_IK[9]));
	}
	if (boneID == 2003)
	{
		animateFreeRF(-rhIK_theta1, -rhIK_theta2, x, y, z);

		// rightUpperLeg
		qxIK[6].setW(cos(rhIK_theta1 * PI / 180 / 2));
		qxIK[6].setX(1 * sin(rhIK_theta1 * PI / 180 / 2));
		qxIK[6].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
		qxIK[6].setZ(0 * sin(rhIK_theta1 * PI / 180 / 2));

		xaxisQX_IK[6].setW(cos(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[6].setX(1 * sin(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[6].setY(0 * sin(rhIK_theta1 * PI / 180 / 2));
		xaxisQX_IK[6].setZ(0 * sin(rhIK_theta1 * PI / 180 / 2));

		xaxisQY_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[6].setX(0);
		xaxisQY_IK[6].setY(sin(0 / 2));
		xaxisQY_IK[6].setZ(sin(0 / 2));

		xaxisQZ_IK[6].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[6].setX(0);
		xaxisQZ_IK[6].setY(sin(0 / 2));
		xaxisQZ_IK[6].setZ(sin(0 / 2));

		xaxisQP_IK[6] = xaxisQX_IK[6].multiply(xaxisQY_IK[6].multiply(xaxisQZ_IK[6]));

		//rightLowerLeg
		qxIK[7].setW(cos(rhIK_theta2 * PI / 180 / 2));
		qxIK[7].setX(1 * sin(rhIK_theta2 * PI / 180 / 2));
		qxIK[7].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
		qxIK[7].setZ(0 * sin(rhIK_theta2 * PI / 180 / 2));

		xaxisQX_IK[7].setW(cos(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[7].setX(1 * sin(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[7].setY(0 * sin(rhIK_theta2 * PI / 180 / 2));
		xaxisQX_IK[7].setZ(0 * sin(rhIK_theta2 * PI / 180 / 2));

		xaxisQY_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQY_IK[7].setX(0);
		xaxisQY_IK[7].setY(sin(0 / 2));
		xaxisQY_IK[7].setZ(sin(0 / 2));

		xaxisQZ_IK[7].setW(cos(0.000000000000001 / 2 * PI / 180));
		xaxisQZ_IK[7].setX(0);
		xaxisQZ_IK[7].setY(sin(0 / 2));
		xaxisQZ_IK[7].setZ(sin(0 / 2));

		xaxisQP_IK[7] = xaxisQX_IK[7].multiply(xaxisQY_IK[7].multiply(xaxisQZ_IK[7]));

	}
	//========================================================================================================================================================================



	if (ffIK_both == 0 && ffIK_RF == 0 && ffIK_LF == 0)
	{
		qxIK[1] = qx[1];
		xaxisQP_IK[1] = xaxisQP[1];


		/*	qxIK[2] = qx[2];
			xaxisQP_IK[2] = xaxisQP[2];*/
	}



}
