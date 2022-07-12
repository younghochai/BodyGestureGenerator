
/** \brief @Modular Motion Auhtoring Platform
*  *  \authors: Bharatesh chakravarthi <chakravarthi589@gmail.com>
				Ashok Kumar Patil <ashokpatil03@hotmail.com>
				Adithya Balasubramanyam <adithyakoundinya@gmail.com>
*
*
*/

#include "lerp.h"

using namespace std;

lerp::lerp()
{

}

lerp::lerp(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

lerp::~lerp()
{

}

void lerp::setXpos(double val)
{
	this->x = val;
}

void lerp::setYpos(double val)
{
	this->y = val;
}

void lerp::setZpos(double val)
{
	this->z = val;
}

double lerp::getXpos()
{
	return this->x;
}

double lerp::getYpos()
{
	return this->y;
}

double lerp::getZpos()
{
	return this->z;
}

lerp lerp::LERP(lerp& a, lerp& b, const float t)
{
	lerp R;
	float t_ = 1 - t;
	R.x = (t_)*a.getXpos() + t * b.getXpos() ;
	R.y = (t_)*a.getYpos() + t * b.getYpos();
	R.z = (t_)*a.getZpos() + t * b.getZpos();
	return R;
}
