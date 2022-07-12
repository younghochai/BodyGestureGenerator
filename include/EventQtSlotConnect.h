//#ifndef EventQtSlotConnect_H
//#define EventQtSlotConnect_H
//
//#include "ui_EventQtSlotConnect.h"
//#include <QMainWindow>
//
//#include <vtkSmartPointer.h>
//#include <vtkObject.h>
//class vtkEventQtSlotConnect;
//
//class EventQtSlotConnect : public QMainWindow, private Ui::EventQtSlotConnect
//{
//  Q_OBJECT
//public:
//
//  EventQtSlotConnect();
//
//
//public slots:
//
//  void slot_clicked(vtkObject*, unsigned long, void*, void*);
//
//  void selectModel(int);
//
//  void viewing_mode();
//  void authoring_mode();
//  void reset();
//
//  void kf_caputre();
//  void allKF_Slerping();
//
//  void allkeyFrames_sliderMove(int);
//  void allKeyFrames_playPause();
//  void timerFunction();
//
//  void eulerInputsWindow();
//  void motionSphereWindow();
//  void timerSettingsWindow();
//  void jointSphereOptions();
//
//  void load_sensedData();
//  void load_AuthoredData();
//
//  void enableIK(bool);
//  void resetIK();
//
//  void enableFreeFoots();
//  void enableFixedFoots();
//  void fixedRightFoot();
//  void fixedLeftFoot();
//
//  void Blend_unitMotions();
//  void addUMs_srq();
//  void addUMs_sfq();
//
//  void take_snapShot();
//  void propsWindow();
//
//private:
//	QTimer *timer;
//
//	//anatomicalInputs *eulerInput_Window = new anatomicalInputs(this);
//	//motionSphere_dialog *motionSphere_Window = new motionSphere_dialog(this);
//	//timerSettings_Window *timerSettings_Dialog = new timerSettings_Window(this);
//	//jointSphere_Dialog *jointSphere_Window = new jointSphere_Dialog(this);
//	//unitMotion_integrationDialog *UM_BelndingWindow = new unitMotion_integrationDialog(this);
//	//constraintProps *constraintProps_Window = new constraintProps(this);
//
//  vtkSmartPointer<vtkEventQtSlotConnect> Connections;
//};
//
//#endif
