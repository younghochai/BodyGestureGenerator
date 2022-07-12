
#pragma once
#include <math.h>
struct TVec3 {
	double _x;
	double _y;
	double _z;
};

struct IntVec3 {
	int _x;
	int _y;
	int _z;
};



class quaternion
{

public:
double mData[4];
double axisangle[4];
public:
	quaternion();
	quaternion(double x, double y, double z, double w);
	quaternion(TVec3 complex, double real);
	~quaternion();

	double  real() const;
	void real(double r);

	TVec3 complex() const;
	void complex(const TVec3& c);

	double norm(quaternion q);
	double norm();
	void normalize();
	//quaternion normalize(quaternion q);
	quaternion Conjugate(void) const;
	quaternion Conjugate(quaternion Q) ;
	quaternion Conjugate();

	quaternion Inverse(quaternion Q) ;
	quaternion Inverse();

	quaternion mutiplication(quaternion Q);
	TVec3 quternionMatrices(quaternion Q,  TVec3 vecPoint);
	void quaternionToEulerAngles(quaternion Q, TVec3& vecPoint);
	void setPrecisionOfValues();
	quaternion EulerAngleToQuaternion(double yaw, double pitch, double roll);
	void quattoaxisangle()
	{
		double pi = 3.141592653589793238462643383279502884e+0;
		
	 
				double angle, x_axis, y_axis, z_axis;
				double q0, q1, q2, q3;
				q0 = mData[3];
				q1 = mData[0];
				q2 = mData[2];// rotate axis
				q3 = -mData[1];
				double s;
				s = sqrt(1 - q0 * q0);
				angle = 2 * acos(q0);
				angle = angle * 180 / pi;
				//Z-> Y ->  X
				if (s < 0.001)
				{
					x_axis = q1;
					y_axis = q2;
					z_axis = q3;
				}
				else {
					x_axis = q1 / s;
					y_axis = q2 / s;
					z_axis = q3 / s;
				}

				axisangle[0] = angle;
				axisangle[1] = x_axis;
				axisangle[2] = y_axis;
				axisangle[3] = z_axis;
		
	}
};

