#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>


#include "anatomicalinputs.h"
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <QVTKInteractor.h>
#include <vtkInteractorStyle.h>



struct JointMove
{
	float chest[3];
	float rua[3];
	float rla[3];
	float lua[3];
	float lla[3];
	float rul[3];
	float rll[3];
	float lul[3];
	float lll[3];

};



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
	Ui::MainWindow *ui;

	//anatomicalInputs* eulerInput_Window = new anatomicalInputs(this);

	void displayRobot_Model(int rotate);
	void displayFixedFoots_Model();
	void displayStick_Model();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

	std::vector<JointMove> savedPoses;



	

public slots:
	void addPose();
	void selectList();
	void selectModel(int ID);
	void enableFixedFoots();
	void onDrawSphereClick();
	void authoring_mode();
	void viewing();

	void saveImage();
	void drawTrajectory();


};

#endif // MAINWINDOW_H
