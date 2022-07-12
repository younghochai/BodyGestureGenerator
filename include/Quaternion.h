#pragma once
#include <math.h>
#include <iostream>
#define M_PI 3.14159265359

using namespace std;


class  Quaternion
{
	double w, x, y, z;


public:
	double mData[4];
	double axisangle[4];

public:
	double angle, axisX, axisY, axisZ;
	Quaternion(double w, double x, double y, double z);
	Quaternion();
	~Quaternion();
	void toEulerAngle(double& roll, double& pitch, double& yaw);
	Quaternion toQuaternion(double yaw, double pitch, double roll);
	void copyQuaternion(Quaternion src, Quaternion dest);
	Quaternion inverse();
	Quaternion multiply(Quaternion q2);
	void toAxisAngles();
	Quaternion SLERP( Quaternion& a,  Quaternion& b, const float t);
	void Normalize();
	void setPrecisionOfValues();

	void setW(double val);
	void setX(double val);
	void setY(double val);
	void setZ(double val);

	double getW();
	double getX();
	double getY();
	double getZ();


private:

};