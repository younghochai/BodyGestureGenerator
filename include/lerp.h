#pragma once
#include <math.h>
#include <iostream>
#define M_PI 3.14159265359

using namespace std;

class lerp
{
	double x, y, z;


public:
	lerp();
	~lerp();
	
	
	lerp LERP(lerp& a, lerp& b, const float t);
	lerp(double x, double y, double z);


	void setXpos(double val);
	void setYpos(double val);
	void setZpos(double val);

	double getXpos();
	double getYpos();
	double getZpos();
};
