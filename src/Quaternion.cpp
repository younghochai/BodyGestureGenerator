/** \brief @Modular Motion Auhtoring Platform
*  *  \authors: Bharatesh chakravarthi <chakravarthi589@gmail.com>
				Ashok Kumar Patil <ashokpatil03@hotmail.com>
				Adithya Balasubramanyam <adithyakoundinya@gmail.com>
*
*
*/

#include "Quaternion.h"


using namespace std;
Quaternion::Quaternion()
{
	//DO NOTHING
}

Quaternion::Quaternion(double w, double x, double y, double z)
{
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

Quaternion::~Quaternion()
{
}

void Quaternion::toEulerAngle(double& roll, double& pitch, double& yaw)
{
	//------------------------------------------ Wikipedia --------------------------------------------

	/* roll (x-axis rotation)*/
	double sinr_cosp = +2.0 * (this->getW() * this->getX() + this->getY() * this->getZ());
	double cosr_cosp = +1.0 - 2.0 * (this->getX() * this->getX() + this->getY() * this->getY());
	roll = atan2(sinr_cosp, cosr_cosp);

	// pitch (y-axis rotation)
	double sinp = +2.0 * (this->getW() * this->getY() - this->getZ() * this->getX());
	if (fabs(sinp) >= 1)
		pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	else
		pitch = asin(sinp);

	// yaw (z-axis rotation)
	double siny_cosp = +2.0 * (this->getW() * this->getZ() + this->getX() * this->getY());
	double cosy_cosp = +1.0 - 2.0 * (this->getY() * this->getY() + this->getZ() * this->getZ());
	yaw = atan2(siny_cosp, cosy_cosp);
	//------------------------------------------ Wikipedia --------------------------------------------

	//------------------------------------------ ZXZ --------------------------------------------
	//double sinr_cosp = +2.0 * (this->getX() * this->getZ() + this->getW() * this->getY());
	//double cosr_cosp = - 2.0 * (this->getY() * this->getZ() - this->getW() * this->getX());
	//roll = atan2(sinr_cosp, cosr_cosp);

	//// pitch (y-axis rotation)
	//double sinp = (this->getW() * this->getW() - this->getX() * this->getX()- this->getY() * this->getY()+ this->getZ() * this->getZ());
	////if (fabs(sinp) >= 1)
	////	pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	////else
	//	pitch = acos(sinp);

	//// yaw (z-axis rotation)
	//double siny_cosp = +2.0 * (this->getX() * this->getZ() - this->getW() * this->getY());
	//double cosy_cosp = 2.0 * (this->getY() * this->getZ() + this->getW() * this->getX());
	//yaw = atan2(siny_cosp, cosy_cosp);
	//------------------------------------------ ZXZ --------------------------------------------
	//------------------------------------------ ZYX --------------------------------------------
	////roll (x-axis rotation)
	//double sinr_cosp = +2.0 * (this->getX() * this->getY() + this->getW() * this->getZ());
	//double cosr_cosp = (this->getW() * this->getW() + this->getX() * this->getX()- this->getY() * this->getY()- this->getZ() * this->getZ());
	//roll = atan2(sinr_cosp, cosr_cosp);

	//// pitch (y-axis rotation)
	//double sinp = -2.0 * (this->getX() * this->getZ() - this->getW() * this->getY());
	//if (fabs(sinp) >= 1)
	//	pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	//else
	//	pitch = asin(sinp);

	//// yaw (z-axis rotation)
	//double siny_cosp = +2.0 * (this->getY() * this->getZ() + this->getW() * this->getX());
	//double cosy_cosp = (this->getW() * this->getW() - this->getX() * this->getX()- this->getY() * this->getY()+ this->getZ() * this->getZ());
	//yaw = atan2(siny_cosp, cosy_cosp);
	//------------------------------------------ ZYX --------------------------------------------

	//------------------------------------------ XYZ --------------------------------------------

	

	//double sinr_cosp = -2.0 * (this->getY() * this->getZ() - this->getW() * this->getX());
	//double cosr_cosp = (this->getW() * this->getW() - this->getX() * this->getX() - this->getY() * this->getY() + this->getZ() * this->getZ());
	//roll = atan2(sinr_cosp, cosr_cosp);

	// pitch (y-axis rotation)
	//double sinp = 2.0 * (this->getX() * this->getZ() + this->getW() * this->getY());
	//if (fabs(sinp) >= 1)
	//	pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	//else
	//	pitch = asin(sinp);

	// yaw (z-axis rotation)
	//double siny_cosp = -2.0 * (this->getX() * this->getY() - this->getW() * this->getZ());
	//double cosy_cosp = (this->getW() * this->getW() + this->getX() * this->getX() - this->getY() * this->getY() - this->getZ() * this->getZ());
	//yaw = atan2(siny_cosp, cosy_cosp);



	//------------------------------------------ XYZ --------------------------------------------

}

void Quaternion::toAxisAngles()
{
	this->angle = acos(this->getW()) * 2;
	this->axisX = this->getX() / sin(this->angle / 2);
	this->axisY = this->getY() / sin(this->angle / 2);
	this->axisZ = this->getZ() / sin(this->angle / 2);
}

Quaternion Quaternion::toQuaternion(double yaw, double pitch, double roll) // yaw (Z), pitch (Y), roll (X)
{
	// Abbreviations for the various angular functions
	double cy = cos(yaw * 0.5);
	double sy = sin(yaw * 0.5);
	double cp = cos(pitch * 0.5);
	double sp = sin(pitch * 0.5);
	double cr = cos(roll * 0.5);
	double sr = sin(roll * 0.5);

	Quaternion q;
	q.w = cy * cp * cr + sy * sp * sr;
	q.x = cy * cp * sr - sy * sp * cr;
	q.y = sy * cp * sr + cy * sp * cr;
	q.z = sy * cp * cr - cy * sp * sr;
	return q;
}

void Quaternion::copyQuaternion(Quaternion src, Quaternion dest)
{
	dest.w = src.w;
	dest.x = src.x;
	dest.y = src.y;
	dest.z = src.z;
}

Quaternion Quaternion::inverse()
{
	Quaternion inverse;
	inverse.setW(this->getW());
	inverse.setX(-this->getX());
	inverse.setY(-this->getY());
	inverse.setZ(-this->getZ());
	return inverse;
}

Quaternion Quaternion::multiply(Quaternion q2)
{
	Quaternion result;
	result.setW(this->getW()*q2.getW() - this->getX()*q2.getX() - this->getY()*q2.getY() - this->getZ()*q2.getZ());
	result.setX(this->getW()*q2.getX() + this->getX()*q2.getW() + this->getY()*q2.getZ() - this->getZ()*q2.getY());
	result.setY(this->getW()*q2.getY() + this->getY()*q2.getW() + this->getZ()*q2.getX() - this->getX()*q2.getZ());
	result.setZ(this->getW()*q2.getZ() + this->getZ()*q2.getW() + this->getX()*q2.getY() - this->getY()*q2.getX());

	return result;

	
	return Quaternion();
}
void Quaternion::Normalize()
{
	double fnorm = sqrt(this->getW()*this->getW() + this->getX()*this->getX() + this->getY()*this->getY() + this->getZ()*this->getZ());
	this->setW(this->getW() / fnorm);
	this->setX(this->getX() / fnorm);
	this->setY(this->getY() / fnorm);
	this->setZ(this->getZ() / fnorm);
}
Quaternion Quaternion::SLERP( Quaternion& a,  Quaternion& b, const float t)
{
	Quaternion r;
	float t_ = 1 - t;
	float Wa, Wb;
	float theta = acos(a.getX()*b.getX() + a.getY()*b.getY() + a.getZ()*b.getZ() + a.getW()*b.getW());
	float sn = sin(theta);
	Wa = sin(t_*theta) / sn;
	Wb = sin(t*theta) / sn;
	r.x = Wa * a.getX() + Wb * b.getX();
	r.y = Wa * a.getY() + Wb * b.getY();
	r.z = Wa * a.getZ() + Wb * b.getZ();
	r.w = Wa * a.getW() + Wb * b.getW();
	r.Normalize();
	return r;
}


void Quaternion:: setPrecisionOfValues()
{
	this->setW((int)(100 * this->getW()) / 100.0);
	this->setX((int)(100 * this->getX()) / 100.0);
	this->setY((int)(100 * this->getY()) / 100.0);
	this->setZ((int)(100 * this->getZ()) / 100.0);
}
void Quaternion::setW(double val)
{
	this->w = val;
}

void Quaternion::setX(double val)
{
	this->x = val;
}

void Quaternion::setY(double val)
{
	this->y = val;
}

void Quaternion::setZ(double val)
{
	this->z = val;
}

double Quaternion::getW()
{
	return this->w;
}

double Quaternion::getX()
{
	return this->x;
}

double Quaternion::getY()
{
	return this->y;
}

double Quaternion::getZ()
{
	return this->z;
}
