#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <vector>
#include <string>

#include "Matrices.h"

#include "Vectors.h"
//#include "Quaternion.h"
#include "quaternion1.h"
#include <vtkPointData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>

using namespace std;
class MotionNode
{
	string name;
	bool isRoot;
	bool isEnd;
	MotionNode* parent;
	vector<MotionNode*> childs;
	float offset[3];
	string channels[6];
	
	MotionNode* next;
public:
	double **data;
	double datatest[50000][6];
	double height[50000];
	double writeQuat[50000][4];
	double eulerangle[50000][3];
	double axisangle[50000][4];
	int channelNum;
	vtkPoints * pts;
	vtkPolyData *polydata;
	vtkPolyDataMapper* mapper;
	
	MotionNode()
	{
		name = "";
		isRoot = false;
		isEnd = false;
		parent = NULL;
		next = NULL;
		childs = vector<MotionNode*>();

		pts = vtkPoints::New();
		polydata = vtkPolyData::New();
		mapper = vtkPolyDataMapper::New();

		channelNum = 0;
		for (int i = 0; i < 6; i++)
		{
			channels[i] = "";
		}
	}
	MotionNode* getParent()
	{
		return parent;
	}
	vector<MotionNode*> getChilds()
	{
		return childs;
	}
	void setParent(MotionNode* pnode)
	{
		parent = pnode;
		pnode->addChild(this);
	}
	void addChild(MotionNode* cnode)
	{
		childs.push_back(cnode);
	}
	void setRoot()
	{
		isRoot = true;
	}
	void setEnd()
	{
		isEnd = true;
	}
	void setName(string mname)
	{
		name = mname;
	}
	void setOffset(float x, float y, float z)
	{
		offset[0] = x;
		offset[1] = y;
		offset[2] = z;
	}
	void setChannels(int num, string* mChannels)
	{
		channelNum = num;
		for (int i = 0; i < num; i++)
		{
			channels[i] = mChannels[i];
		}
	}
	void setNext(MotionNode *nextNode)
	{
		next = nextNode;
	}
	string getName()
	{
		return name;
	}
	int getChannelNum()
	{
		return channelNum;
	}
	MotionNode* getNextNode()
	{
		return next;
	}
	void initData(int frames)
	{
		data = new double*[frames];
		for (int i = 0; i < frames; i++)
		{
			data[i] = new double[channelNum];
		}
	}

};
class BVHparser
{
	const char* mPath;
	double** data;
public :
	BVHparser() {};
	void loadBVH(const char* path);
	//void loadQuaternion(const char* path);
	vector<string> usrSettings;
	MotionNode* initnode;
	MotionNode* nodelist[30];
	float frames;
	float frameTime;
	void quattoeuler()
	{
		double pi = 3.141592653589793238462643383279502884e+0;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < frames; j++)
			{
				double roll, pitch, yaw;
				double q0, q1, q2, q3;
				q0 = nodelist[i]->datatest[j][0];
				q1 = nodelist[i]->datatest[j][1];
				q2 = nodelist[i]->datatest[j][2];
				q3 = nodelist[i]->datatest[j][3];
			


				roll = atan2(2 * (q0* q1 + q2 * q3), q0*q0 - q1 * q1 - q2 * q2 + q3 * q3);
				pitch = asin(2 * (q0*q2 - q1 * q3));
				yaw = atan2(2 * (q0* q3 + q1 * q2), q0*q0 + q1 * q1 - q2 * q2 - q3 * q3);


				if (pitch == pi / 2)
				{
					roll = 0;
					yaw = -2 * atan2(q1, q0);

				}
				else if (pitch == -pi / 2)
				{
					roll = 0;
					yaw = 2 * atan2(q1, q0);

				}

				nodelist[i]->eulerangle[j][0] = roll;
				nodelist[i]->eulerangle[j][1] = pitch;
				nodelist[i]->eulerangle[j][2] = yaw;
			}
		}
	}

	
	void nodelistmatching()
	{
		MotionNode *curNode;
		curNode = initnode;
		int i = 0;
		while (i != 30)
		{
			nodelist[i] = curNode;
			curNode = curNode->getNextNode();
			cout << i << endl;
			i++;
		}
	}
};
class NodeManage
{
	const char* mPath;
	double** data;
public:
	NodeManage() {};
	void loadQuaternion(const char* path);
	void loadEuler(const char* path);
	vector<string> usrSettings;
	MotionNode* initnode;
	MotionNode* nodelist[10];
	float frames;
	float frameTime;
	float writeframes;

	void nodelistmatching()
	{
		MotionNode *curNode;
		curNode = initnode;
		int i = 0;
		while (i != 10)
		{
			nodelist[i] = curNode;
			curNode = curNode->getNextNode();
			//cout << i << endl;
			i++;
		}
	}
	void rotateaxis()
	{
		/*double pi = 3.141592653589793238462643383279502884e+0;
		Quaternion quat_axis1;
		quat_axis1.set(Vector3(1.0, 0.0, 0.0), pi / 2);
		Quaternion quat_axis2;
		quat_axis2.set(Vector3(0.0, 1.0, 0.0), -pi / 2);
		Quaternion quat_total;
		Quaternion quat_total_inverse;

		quat_total = quat_axis1* quat_axis2 ;

		quat_total_inverse = quat_axis1 * quat_axis2;
		quat_total_inverse.conjugate();
*/
		double quat[4];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < frames; j++)
			{



				quat[0] = nodelist[i]->datatest[j][0];
				quat[1] = nodelist[i]->datatest[j][1];
				quat[2] = nodelist[i]->datatest[j][2];
				quat[3] = nodelist[i]->datatest[j][3];

				//quat = quat_total_inverse * quat*quat_total;



				nodelist[i]->datatest[j][0] = quat[0];
				nodelist[i]->datatest[j][1] = quat[1];
				nodelist[i]->datatest[j][2] = quat[3];
				nodelist[i]->datatest[j][3] = -quat[2];

			}
		}
	}
	void quattoeuler()
	{
		double pi = 3.141592653589793238462643383279502884e+0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < frames; j++)
			{
				double roll, pitch, yaw;
				double q0, q1, q2, q3;
				q0 = nodelist[i]->datatest[j][0];
				q1 = nodelist[i]->datatest[j][1];
				q2 = nodelist[i]->datatest[j][2];
				q3 = nodelist[i]->datatest[j][3];

				//Z-> Y ->  X

				roll = atan2(2 * (q0* q1 + q2 * q3), q0*q0 - q1 * q1 - q2 * q2 + q3 * q3);
				pitch = asin(2 * (q0*q2 - q1 * q3));
				yaw = atan2(2 * (q0* q3 + q1 * q2), q0*q0 + q1 * q1 - q2 * q2 - q3 * q3);

				if (pitch == 3.141592 / 2)
				{
					roll = 0;
					yaw = -2 * atan2(q1, q0);

				}
				else if (pitch == -3.141592 / 2)
				{
					roll = 0;
					yaw = 2 * atan2(q1, q0);

				}
				nodelist[i]->eulerangle[j][0] = roll * 180 / pi;
				nodelist[i]->eulerangle[j][1] = pitch * 180 / pi;
				nodelist[i]->eulerangle[j][2] = yaw * 180 / pi;
			}
		}
	}
	void quattoHeight()
	{
		double height_r;
		double height_l;
		double height_tot;
		double vectorM[3] = { 0,1,0 };

		//quaternion pelvis;
		//quaternion leg;
		//quaternion cal;
		double pi = 3.141592653589793238462643383279502884e+0;
		for (int i = 6; i < 10; i++)
		{
			for (int j = 0; j < frames; j++)
			{
				double Rotaxis_X, Rotaxis_Y, Rotaxis_Z;
				double Rotaxis_X1, Rotaxis_Y1, Rotaxis_Z1;
				double q0, q1, q2, q3;
				double q_0, q_1, q_2, q_3;
				double s;
				
				//pelvis = quaternion(nodelist[0]->datatest[j][1], nodelist[0]->datatest[j][2], nodelist[0]->datatest[j][3], nodelist[0]->datatest[j][0]);
				//leg = quaternion(nodelist[i]->datatest[j][1], nodelist[i]->datatest[j][2], nodelist[i]->datatest[j][3], nodelist[i]->datatest[j][0]);
				//cal = pelvis.mutiplication(leg);
				if (i == 7)
				{
					q_0 = nodelist[i-1]->datatest[j][0];
					q_1 = nodelist[i-1]->datatest[j][1];
					q_2 = nodelist[i-1]->datatest[j][2];
					q_3 = nodelist[i-1]->datatest[j][3];
				}
				if (i == 6)
				{
					q_0 = nodelist[0]->datatest[j][0];
					q_1 = nodelist[0]->datatest[j][1];
					q_2 = nodelist[0]->datatest[j][2];
					q_3 = nodelist[0]->datatest[j][3];
				}


				q0 = nodelist[i]->datatest[j][0];
				q1 = nodelist[i]->datatest[j][1];
				q2 = nodelist[i]->datatest[j][2];
				q3 = nodelist[i]->datatest[j][3];
				if (i == 7||i==6)
				{
					q0 = q_0 * q0 - q_1 * q1 - q_2 * q2 - q_3 * q3;
					q1 = q_0 * q1 + q_1 * q0 + q_2 * q3 - q_3 * q2;
					q2 = q_0 * q2 + q_2 * q0 + q_3 * q1 - q_1 * q3;
					q3 = q_0 * q3 + q_3 * q0 + q_1 * q2 - q_2 * q1;
				}
				Rotaxis_X1 = vectorM[0] * (2 * q0*q0 - 1 + 2 * q1* q1) + vectorM[1] * (2 * q2*q1 - 2 * q0* q3) + vectorM[2] * (2 * q1*q3 + 2 * q0* q2);
				Rotaxis_Y1 = vectorM[0] * (2 * q1*q2 + 2 * q0*q3) + vectorM[1] * (2 * q0*q0 - 1 + 2 * q2*q2) + vectorM[2] * (2 * q2*q3 - 2 * q0*q1);
				Rotaxis_Z1 = vectorM[0] * (2 * q1*q3 - 2 * q0* q2) + vectorM[1] * (2 * q2*q3 + 2 * q0* q1) + vectorM[2] * (2 * q0*q0 - 1 + 2 * q3* q3);

				s = sqrt(Rotaxis_X1*Rotaxis_X1 + Rotaxis_Y1 * Rotaxis_Y1 + Rotaxis_Z1 * Rotaxis_Z1);

				Rotaxis_X1 = Rotaxis_X1 / s;
				Rotaxis_Y1 = Rotaxis_Y1 / s;
				Rotaxis_Z1 = Rotaxis_Z1 / s;
						 
				double height;
				
				//Z-> Y ->  X
				double angle;
				Rotaxis_X = 2 * q2*q1 -2*q0* q3;
				Rotaxis_Y = 2*q0*q0-1+2*q2*q2;
				Rotaxis_Z = 2*q2*q3+2*q1*q0;

				s = sqrt(Rotaxis_X*Rotaxis_X + Rotaxis_Y * Rotaxis_Y + Rotaxis_Z * Rotaxis_Z);

				Rotaxis_X = Rotaxis_X / s;
				Rotaxis_Y = Rotaxis_Y / s;
				Rotaxis_Z = Rotaxis_Z / s;


				// Quat Vector method
				//angle = acos(Rotaxis_Y);
				//nodelist[i]->height[j] = (1 - cos(angle / 2));
				
				
				// Axis angle Method
				angle = nodelist[i]->axisangle[j][0];
				//nodelist[i]->height[j] = angle * 180 / pi / 108 ;

				nodelist[i]->height[j] = Rotaxis_Y1;
				//nodelist[i]->height[j] = (1 - cos((angle - 20)*pi / 180 / 1.64));
				//-34 * (1 - cos((Quatnode.nodelist[6]->axisangle[i][0] - 20)*PI / 180 / 1.64)) 
				//	- 36 * (1 - cos((Quatnode.nodelist[7]->axisangle[i][0] - 20)* PI / 180 / 1.64));
				/*if (i == 6)
					nodelist[3]->height[j] = angle/2  * 180 / pi ;
				if (i == 7)
					nodelist[4]->height[j] = angle / 2 * 180 / pi;
				if (i == 8)
					nodelist[5]->height[j] = angle / 2 * 180 / pi;*/
					//cout << angle/2*180/pi<< endl;
			}
			

			
		}

		for (int j = 0; j < frames; j++)
		{
			/*height_r = -34 *nodelist[6]->height[j]  -36 *nodelist[7]->height[j];
			height_l = -34 *nodelist[8]->height[j]  -36 *nodelist[9]->height[j];*/
			
			//nodelist[5]->height[j] = (height_r + height_l)/2;

			/*nodelist[3]->height[j] = height_r ;
			nodelist[4]->height[j] =  height_l;
			nodelist[5]->height[j] = height_r> height_l ? height_r : height_l;*/
			//cout << nodelist[6]->height[j]<<" ,  " <<nodelist[7]->height[j] << endl;
		}
		//transform[0]->Translate(0, -32 * Quatnode.nodelist[6]->height[i] - 36 * Quatnode.nodelist[7]->height[i], 0);



	}

	void quattoaxisangle()
	{
		double pi = 3.141592653589793238462643383279502884e+0;
		 // method in pdf
		//for (int i = 0; i < 10; i++)
		//{
		//	for (int j = 0; j < frames; j++)
		//	{
		//		double angle, x_axis, y_axis,z_axis;
		//		double q0, q1, q2, q3;
		//		q0 = nodelist[i]->datatest[j][0];
		//		q1 = nodelist[i]->datatest[j][1];
		//		q2 = nodelist[i]->datatest[j][2];
		//		q3 = nodelist[i]->datatest[j][3];

		//		//Z-> Y ->  X
		//		if (q0 == 1)
		//		{
		//			angle = 0;
		//			x_axis = 1;
		//			y_axis = 0;
		//			z_axis = 0;
		//		}
		//		else {
		//			angle = 2 * acos(q0);
		//			x_axis = q1 / sin(angle / 2);
		//			y_axis = q2 / sin(angle / 2);
		//			z_axis = q3 / sin(angle / 2);
		//		}

		//		nodelist[i]->axisangle[j][0] = angle;
		//		nodelist[i]->axisangle[j][1] = x_axis;
		//		nodelist[i]->axisangle[j][2] = y_axis;
		//		nodelist[i]->axisangle[j][3] = z_axis;
		//	}
		//}
		// method in Maths
		double firstangle;


		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < frames; j++)
			{
				double angle, x_axis, y_axis, z_axis;
				double q0, q1, q2, q3;
				q0 = nodelist[i]->datatest[j][0];
				q1 = nodelist[i]->datatest[j][1];
				q2 = nodelist[i]->datatest[j][2];
				q3 = nodelist[i]->datatest[j][3];
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

				nodelist[i]->axisangle[j][0] = angle;
				nodelist[i]->axisangle[j][1] = x_axis;
				nodelist[i]->axisangle[j][2] = y_axis;
				nodelist[i]->axisangle[j][3] = z_axis;

				/*if (i == 6 || i == 7)
				{
					if(j==0)
					firstangle = angle;

					nodelist[i]->height[j] = (1 - cos((angle-firstangle)*pi/180));

					nodelist[i]->height[j] = q0;

				}*/
			


			}
		}
	}
	void Calpts()
	{


		double pi = 3.141592653589793238462643383279502884e+0;

		//double vectorM[3];
		double vectorM[3] = { 0,	1,	0 };
		//double pi = 3.14159265358993238462643383279502884e+0;
		for (int i = 0; i < 10; i++)
		{
			if (i == 2)
				vectorM[1] = -1;
			for (int j = 0; j < frames; j++)
			{
				double Rotaxis_X, Rotaxis_Y, Rotaxis_Z;
				double q0, q1, q2, q3;
				//double q_0, q_1, q_2, q_3;
				double x_axis, y_axis, z_axis;
				//double q00, q01, q02, q03;
				q0 = nodelist[i]->datatest[j][0];
				q1 = nodelist[i]->datatest[j][1];
				q2 = nodelist[i]->datatest[j][2];
				q3 = nodelist[i]->datatest[j][3];

				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;

				
				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;
				double height;
				double s;


				// mixed vector ( 0.57735 0.57735 0.57735 )

				double vectorM[3] = { 0, -1, 0 };

				Rotaxis_X = vectorM[0] * (2 * q0*q0 - 1 + 2 * q1* q1) 
					+ vectorM[1] * (2 * q2*q1 - 2 * q0* q3)
					+ vectorM[2] * (2 * q1*q3 + 2 * q0* q2);

				Rotaxis_Y = vectorM[0] * (2 * q1*q2 + 2 * q0*q3)
					+ vectorM[1] * (2 * q0*q0 - 1 + 2 * q2*q2) 
					+ vectorM[2] * (2 * q2*q3 - 2 * q0*q1);

				Rotaxis_Z = vectorM[0] * (2 * q1*q3 - 2 * q0* q2) 
					+ vectorM[1] * (2 * q2*q3 + 2 * q0* q1) 
					+ vectorM[2] * (2 * q0*q0 - 1 + 2 * q3* q3);



				s = sqrt(Rotaxis_X*Rotaxis_X + Rotaxis_Y * Rotaxis_Y + Rotaxis_Z * Rotaxis_Z);

				Rotaxis_X = Rotaxis_X / s;
				Rotaxis_Y = Rotaxis_Y / s;
				Rotaxis_Z = Rotaxis_Z / s;
				/*if (Rotaxis_Z < 0.000001)
					Rotaxis_Z = 0;*/

					//cout <<"!!!!" <<Rotaxis_X << Rotaxis_Y << Rotaxis_Z << endl;

				nodelist[i]->pts->InsertNextPoint(Rotaxis_X, Rotaxis_Y, Rotaxis_Z);


			}
			//vtkSmartPointer<vtkPolyDataMapper> pointmapper =vtkSmartPointer<vtkPolyDataMapper>::New();
			//nodelist[i]->mapper = pointmapper;

			nodelist[i]->polydata->SetPoints(nodelist[i]->pts);
			nodelist[i]->mapper->SetInputData(nodelist[i]->polydata);

			//nodelist[i]->mapper->SetInputData(polyData);
		}
	}

	void nodecreate()
	{

		for (int i = 0; i < 10; i++)
		{
			MotionNode *newNode = new MotionNode();
			nodelist[i] = newNode;


		}
	}

};

class PositionManage
{
	const char* mPath;
	double** data;
public:
	PositionManage() {};
	

	MotionNode* nodelist;
	float frames;
	float frameTime;

	
	
	void loadQuaternion(const char* path);
	
	void nodecreate()
	{
			MotionNode *newNode = new MotionNode();
			nodelist = newNode;

	}

};

class RowdataManage
{
	const char* mPath;
	double** data;
public:
	RowdataManage() {};
	
	vtkIdType pidn[5000];
	MotionNode* nodelist[10];
	float frames;
	float frameTime;



	void loadRow(const char* path);
	void nodecreate()
	{

		for (int i = 0; i < 10; i++)
		{
			MotionNode *newNode = new MotionNode();
			nodelist[i] = newNode;
		/*	vtkSmartPointer<vtkPoints> point = vtkSmartPointer<vtkPoints>::New();
			nodelist[i]->pts = point;
				
			nodelist[i]->polydata= vtkSmartPointer<vtkPolyData>::New();
			nodelist[i]->mapper= vtkSmartPointer<vtkPolyDataMapper>::New();*/
		}
	}
	void quattoHeight()
	{
		double height_r;
		double height_l;
		double height_tot;
		double pi = 3.141592653589793238462643383279502884e+0;



		//			double q_init_upper[4];
		//
		//			q_init_upper[0] = nodelist[6]->datatest[0][0];
		//			q_init_upper[1] = -nodelist[6]->datatest[0][1];
		//			q_init_upper[2] = -nodelist[6]->datatest[0][2];
		//			q_init_upper[3] = -nodelist[6]->datatest[0][3];
		//
		//			double q_init_lower[4];
		//			q_init_lower[0] = nodelist[7]->datatest[0][0];
		//			q_init_lower[1] = -nodelist[7]->datatest[0][1];
		//			q_init_lower[2] = -nodelist[7]->datatest[0][2];
		//			q_init_lower[3] = -nodelist[7]->datatest[0][3];
		//			//cout << q_init[0] << " " << q_init[1] << " " << q_init[2] << " " << q_init[3] << endl;
		//
		//			for (int j = 0; j < frames; j++)
		//			{
		//				double Rotaxis_X, Rotaxis_Y, Rotaxis_Z;
		//				double q0, q1, q2, q3;
		//				double ql0, ql1, ql2, ql3;
		//				double q_0, q_1, q_2, q_3;
		//				double ql_0, ql_1, ql_2, ql_3;
		//
		//				q_0 = nodelist[6]->datatest[j][0];
		//				q_1 = nodelist[6]->datatest[j][1];
		//				q_2 = nodelist[6]->datatest[j][2];
		//				q_3 = nodelist[6]->datatest[j][3];
		//
		//				ql_0 = nodelist[7]->datatest[j][0];
		//				ql_1 = nodelist[7]->datatest[j][1];
		//				ql_2 = nodelist[7]->datatest[j][2];
		//				ql_3 = nodelist[7]->datatest[j][3];
		//								
		//				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;
		//
		//				//upper
		//				q0 = q_0 * q_init_upper[0] - q_1 * q_init_upper[1] - q_2 * q_init_upper[2] - q_3 * q_init_upper[3];
		//				q1 = q_0 * q_init_upper[1] + q_1 * q_init_upper[0] + q_2 * q_init_upper[3] - q_3 * q_init_upper[2];
		//				q2 = q_0 * q_init_upper[2] + q_2 * q_init_upper[0] + q_3 * q_init_upper[1] - q_1 * q_init_upper[3];
		//				q3 = q_0 * q_init_upper[3] + q_3 * q_init_upper[0] + q_1 * q_init_upper[2] - q_2 * q_init_upper[1];
		//
		//				//lower
		//				ql0 = ql_0 * q_init_lower[0] - ql_1 * q_init_lower[1] - ql_2 * q_init_lower[2] - ql_3 * q_init_lower[3];
		//				ql1 = ql_0 * q_init_lower[1] + ql_1 * q_init_lower[0] + ql_2 * q_init_lower[3] - ql_3 * q_init_lower[2];
		//				ql2 = ql_0 * q_init_lower[2] + ql_2 * q_init_lower[0] + ql_3 * q_init_lower[1] - ql_1 * q_init_lower[3];
		//				ql3 = ql_0 * q_init_lower[3] + ql_3 * q_init_lower[0] + ql_1 * q_init_lower[2] - ql_2 * q_init_lower[1];
		//
		//				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;
		//				double height;
		//				double s;
		//				//Z-> Y ->  X
		//				double angle;
		//				/*Rotaxis_X = 2 * q2*q1 -2*q0* q3;
		//				Rotaxis_Y = 2 * q0*q0 - 1 + 2 * q2*q2;
		//				Rotaxis_Z = 2 * q2*q3+ 2*q0* q1;*/
		//
		//				//X-Rot
		//				/*Rotaxis_X = 2 * q0*q0-1 + 2 * q1* q1;
		//				Rotaxis_Y = 2 * q1*q2 + 2 * q0*q3;
		//				Rotaxis_Z = 2 * q1*q3 -2 * q0* q2;*/
		//
		//				angle = 2 * acos(q1*ql1 + q2 * ql2 + q3 * ql3 + q0*ql0)*180/pi;
		//
		//				//Z-rot
		//				/*Rotaxis_X = 2 * q1*q3 + 2 * q0* q2;
		//				Rotaxis_Y = 2 * q2*q3 - 2 * q0*q1;
		//				Rotaxis_Z = 2 * q0*q0 - 1 + 2 * q3* q3;
		//
		//				
		//
		//				s = sqrt(Rotaxis_X*Rotaxis_X + Rotaxis_Y * Rotaxis_Y + Rotaxis_Z * Rotaxis_Z);
		//
		//				Rotaxis_X = Rotaxis_X / s;
		//				Rotaxis_Y = Rotaxis_Y / s;
		//				Rotaxis_Z = Rotaxis_Z / s;
		//*/
		//				//angle = acos(Rotaxis_Z);
		//
		//				nodelist[3]->height[j] = -angle*35/180+1;
		//				// 22 
		//
		//				cout << nodelist[3]->height[j]<< endl;
		//			
		//
		////			
		//		for (int i = 0; i < 10; i++)
		//		{
		//			for (int j = 0; j < frames; j++)
		//			{
		//				double angle, x_axis, y_axis, z_axis;
		//				double q0, q1, q2, q3;
		//				q0 = nodelist[i]->datatest[j][0];
		//				q1 = nodelist[i]->datatest[j][1];
		//				q2 = nodelist[i]->datatest[j][2];
		//				q3 = nodelist[i]->datatest[j][3];
		//				double s;
		//				s = sqrt(1 - q0 * q0);
		//				angle = 2 * acos(q0);
		//				angle = angle * 180 / pi;
		//				//Z-> Y ->  X
		//				if (s < 0.001)
		//				{
		//					x_axis = q1;
		//					y_axis = q2;
		//					z_axis = q3;
		//				}
		//				else {
		//					x_axis = q1 / s;
		//					y_axis = q2 / s;
		//					z_axis = q3 / s;
		//				}
		//
		//				nodelist[i]->axisangle[j][0] = angle;
		//				nodelist[i]->axisangle[j][1] = x_axis;
		//				nodelist[i]->axisangle[j][2] = y_axis;
		//				nodelist[i]->axisangle[j][3] = z_axis;
		//			}
		//		}
		double firstangle;
		double angle;
		double angle_1;
		//0.40824829	0.40824829	0.816496581

		//double vectorM[3];
		double vectorM[3] = { 0,	0,	1		};
		//double pi = 3.141592653589793238462643383279502884e+0;
		for (int i = 0; i < 10; i++)
		{
			/*vtkSmartPointer<vtkPoints> vertexpts =
				vtkSmartPointer<vtkPoints>::New();
			nodelist[i]->pts = vertexpts;*/


			double q_init[4];
			q_init[0] = nodelist[i]->datatest[0][0];
			q_init[1] = -nodelist[i]->datatest[0][1];
			q_init[2] = -nodelist[i]->datatest[0][2];
			q_init[3] = -nodelist[i]->datatest[0][3];
			//cout << q_init[0] << " " << q_init[1] << " " << q_init[2] << " " << q_init[3] << endl;

			for (int j = 0; j < frames; j++)
			{
				double Rotaxis_X, Rotaxis_Y, Rotaxis_Z;
				double q0, q1, q2, q3;
				double q_0, q_1, q_2, q_3;
				double x_axis, y_axis, z_axis;

				q_0 = nodelist[i]->datatest[j][0];
				q_1 = nodelist[i]->datatest[j][1];
				q_2 = nodelist[i]->datatest[j][2];
				q_3 = nodelist[i]->datatest[j][3];

				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;

				q0 = q_0 * q_init[0] - q_1 * q_init[1] - q_2 * q_init[2] - q_3 * q_init[3];
				q1 = q_0 * q_init[1] + q_1 * q_init[0] + q_2 * q_init[3] - q_3 * q_init[2];
				q2 = q_0 * q_init[2] + q_2 * q_init[0] + q_3 * q_init[1] - q_1 * q_init[3];
				q3 = q_0 * q_init[3] + q_3 * q_init[0] + q_1 * q_init[2] - q_2 * q_init[1];

				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;
				double height;
				double s;
				//Z-> Y ->  X
				//cout << "   " << q0 << endl;


				s = sqrt(1 - q0 * q0);

				if (1 - q0 < 0.0001)
				{
					angle_1 = 0;
				}
				else
				{
					angle_1 = 2 * acos(q0);
				}
				//angle_1 = angle_1;//* 180 / pi;

				if (j == 0)
					firstangle = angle_1;

				//Z-> Y ->  X
				if (s < 0.001)
				{
					x_axis = q1;
					y_axis = q2;
					z_axis = q3;
					//angle_1 = 0;
				}
				else {
					x_axis = q1 / s;
					y_axis = q2 / s;
					z_axis = q3 / s;
				}
				//if (i == 6)
					//cout << "   "<<angle_1 << endl;
				/*Rotaxis_X = 2 * q2*q1 -2*q0* q3;
				Rotaxis_Y = 2 * q0*q0 - 1 + 2 * q2*q2;
				Rotaxis_Z = 2 * q2*q3+ 2*q0* q1;*/

				//X-Rot
				/*Rotaxis_X = 2 * q0*q0-1 + 2 * q1* q1;
				Rotaxis_Y = 2 * q1*q2 + 2 * q0*q3;
				Rotaxis_Z = 2 * q1*q3 -2 * q0* q2;*/

				////Z-rot
				/*Rotaxis_X = 2 * q1*q3  + 2 * q0* q2;
				Rotaxis_Y = 2 * q2*q3 - 2 * q0*q1;
				Rotaxis_Z = 2 * q0*q0-1+ 2 * q3* q3;*/

				// mixed vector ( 0.57735 0.57735 0.57735 )
				Rotaxis_X =vectorM[0]*( 2 * q0*q0 - 1 + 2 * q1* q1)+ vectorM[1]*(2 * q2*q1 - 2 * q0* q3)+ vectorM[2]*(2 * q1*q3 + 2 * q0* q2);
				Rotaxis_Y = vectorM[0] *(2 * q1*q2 + 2 * q0*q3)+ vectorM[1] * (2 * q0*q0 - 1 + 2 * q2*q2) + vectorM[2] * (2 * q2*q3 - 2 * q0*q1);
				Rotaxis_Z = vectorM[0] *(2 * q1*q3 - 2 * q0* q2)+ vectorM[1] * (2 * q2*q3 + 2 * q0* q1) + vectorM[2] * (2 * q0*q0 - 1 + 2 * q3* q3);

				

				s = sqrt(Rotaxis_X*Rotaxis_X + Rotaxis_Y * Rotaxis_Y + Rotaxis_Z * Rotaxis_Z);

				Rotaxis_X = Rotaxis_X / s;
				Rotaxis_Y = Rotaxis_Y / s;
				Rotaxis_Z = Rotaxis_Z / s;

				//angle = acos(Rotaxis_X*vectorM[0] +Rotaxis_Y * vectorM[1] + Rotaxis_Z * vectorM[2]) ;

				nodelist[i]->height[j] = Rotaxis_Z;

				//nodelist[i]->height[j] = 1- cos(angle);
				//nodelist[i]->height[j] =angle;

				//nodelist[i]->height[j] =(angle_1)*180/pi;

				//nodelist[i]->height[j] = 1 - cos(angle_1);
				nodelist[i]->axisangle[j][1] = x_axis;
				nodelist[i]->axisangle[j][2] = y_axis;
				nodelist[i]->axisangle[j][3] = z_axis;

				//vertexpts->InsertNextPoint(Rotaxis_X, Rotaxis_Y, Rotaxis_Z);
				
				/*if (i == 6)
					nodelist[3]->height[j] = angle_1  *180 / pi;
				if (i == 7)
					nodelist[4]->height[j] = angle_1  *180 / pi;*/
				/*if (i == 6)
					nodelist[4]->height[j] = angle * 0.277;*/


				// 22 
				/*if(i==6)
				nodelist[4]->height[j] = angle * 0.277;*/
				//cout << nodelist[i]->axisangle[j][0] << endl;
			}

		}


		//for (int j = 0; j < frames; j++)
		//{
		//	height_r = -32 * nodelist[6]->height[j] + -36 * nodelist[7]->height[j];
		//	height_l = -32 * nodelist[8]->height[j] + -36 * nodelist[9]->height[j];


		//	nodelist[3]->height[j] = (height_r+height_l) / 2;

		//	nodelist[4]->height[j] = (height_r);
		//	nodelist[5]->height[j] = (height_l);

		//	//nodelist[4]->height[j] = nodelist[6]->height[j];
		//	//nodelist[5]->height[j] = nodelist[7]->height[j];
		//	/*nodelist[4]->height[j] = -30.5* nodelist[6]->height[j];
		//	nodelist[5]->height[j] = -50 * nodelist[7]->height[j];*/
		//	//cout << -65 * nodelist[7]->height[j] << endl;
		//}
		//cout << nodelist[3]->height[0] << endl;

	


	}
	void Calpts()
	{
		
	
		double pi = 3.141592653589793238462643383279502884e+0;
		
		//double vectorM[3];
		double vectorM[3] = {0,	-1,	0	};
		//double pi = 3.14159265358993238462643383279502884e+0;
		for (int i = 0; i < 10; i++)
		{
			//vtkSmartPointer<vtkPoints> vertexpts = vtkSmartPointer<vtkPoints>::New();
			//nodelist[i]->pts = vertexpts;
			//vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
			//nodelist[i]->polydata = polyData;

			double q_init[4];
			q_init[0] = nodelist[i]->datatest[0][0];
			q_init[1] = -nodelist[i]->datatest[0][1];
			q_init[2] = -nodelist[i]->datatest[0][2];
			q_init[3] = -nodelist[i]->datatest[0][3];
			//cout << q_init[0] << " " << q_init[1] << " " << q_init[2] << " " << q_init[3] << endl;

			for (int j = 0; j < frames; j++)
			{
				double Rotaxis_X, Rotaxis_Y, Rotaxis_Z;
				double q0, q1, q2, q3;
				double q_0, q_1, q_2, q_3;
				double x_axis, y_axis, z_axis;
				double q00, q01, q02, q03;
				q_0 = nodelist[i]->datatest[j][0];
				q_1 = nodelist[i]->datatest[j][1];
				q_2 = nodelist[i]->datatest[j][2];
				q_3 = nodelist[i]->datatest[j][3];

				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;

				q00 = q_0 * q_init[0] - q_1 * q_init[1] - q_2 * q_init[2] - q_3 * q_init[3];
				q01 = q_0 * q_init[1] + q_1 * q_init[0] + q_2 * q_init[3] - q_3 * q_init[2];
				q02 = q_0 * q_init[2] + q_2 * q_init[0] + q_3 * q_init[1] - q_1 * q_init[3];
				q03 = q_0 * q_init[3] + q_3 * q_init[0] + q_1 * q_init[2] - q_2 * q_init[1];

				q0 = q00;
				q1 = q01;
				q2 = q03;
				q3 = -q02;
				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;
				double height;
				double s;
			

				// mixed vector ( 0.57735 0.57735 0.57735 )
				Rotaxis_X = vectorM[0] * (2 * q0*q0 - 1 + 2 * q1* q1) + vectorM[1] * (2 * q2*q1 - 2 * q0* q3) + vectorM[2] * (2 * q1*q3 + 2 * q0* q2);
				Rotaxis_Y = vectorM[0] * (2 * q1*q2 + 2 * q0*q3) + vectorM[1] * (2 * q0*q0 - 1 + 2 * q2*q2) + vectorM[2] * (2 * q2*q3 - 2 * q0*q1);
				Rotaxis_Z = vectorM[0] * (2 * q1*q3 - 2 * q0* q2) + vectorM[1] * (2 * q2*q3 + 2 * q0* q1) + vectorM[2] * (2 * q0*q0 - 1 + 2 * q3* q3);



				s = sqrt(Rotaxis_X*Rotaxis_X + Rotaxis_Y * Rotaxis_Y + Rotaxis_Z * Rotaxis_Z);

				Rotaxis_X = Rotaxis_X / s;
				Rotaxis_Y = Rotaxis_Y / s;
				Rotaxis_Z = Rotaxis_Z / s;
				/*if (Rotaxis_Z < 0.000001)
					Rotaxis_Z = 0;*/

				//cout <<"!!!!" <<Rotaxis_X << Rotaxis_Y << Rotaxis_Z << endl;

				nodelist[i]->pts->InsertNextPoint(Rotaxis_X, Rotaxis_Y, Rotaxis_Z);


			}
			//vtkSmartPointer<vtkPolyDataMapper> pointmapper =vtkSmartPointer<vtkPolyDataMapper>::New();
			//nodelist[i]->mapper = pointmapper;
			
			nodelist[i]->polydata->SetPoints(nodelist[i]->pts);
			nodelist[i]->mapper->SetInputData(nodelist[i]->polydata);

			//nodelist[i]->mapper->SetInputData(polyData);
		}
	}


		




	
	void write_pose(double (*t)[5000], double(*a)[4],double(*b)[4])
	{
		for (int j = 0; j < frames; j++)
		{
			t[0][j]= nodelist[3]->height[j];
			t[1][j]= nodelist[4]->height[j];
			t[2][j]= nodelist[5]->height[j];

			a[j][0] = nodelist[6]->axisangle[j][0];
			a[j][1] = nodelist[6]->axisangle[j][1];
			a[j][2] = nodelist[6]->axisangle[j][2];
			a[j][3] = nodelist[6]->axisangle[j][3];

			b[j][0] = nodelist[7]->axisangle[j][0];
			b[j][1] = nodelist[7]->axisangle[j][1];
			b[j][2] = nodelist[7]->axisangle[j][2];
			b[j][3] = nodelist[7]->axisangle[j][3];



		}

	}
	void quattoHeightIni()
	{
		double height_r;
		double height_l;
		double height_tot;


	

		double pi = 3.141592653589793238462643383279502884e+0;
		for (int i = 6; i < 8; i++)
		{
			double q_init[4];
			q_init[0] = nodelist[i]->datatest[0][0];
			q_init[1] = -nodelist[i]->datatest[0][1];
			q_init[2] = -nodelist[i]->datatest[0][2];
			q_init[3] = -nodelist[i]->datatest[0][3];
			//cout << q_init[0] << " " << q_init[1] << " " << q_init[2] << " " << q_init[3] << endl;

			for (int j = 0; j < frames; j++)
			{
				double Rotaxis_X, Rotaxis_Y, Rotaxis_Z;
				double q0, q1, q2, q3;
				double q_0, q_1, q_2, q_3;


				q_0 = nodelist[i]->datatest[j][0];
				q_1 = nodelist[i]->datatest[j][1];
				q_2 = nodelist[i]->datatest[j][2];
				q_3 = nodelist[i]->datatest[j][3];

				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;

				q0 = q_0 * q_init[0] - q_1 * q_init[1] - q_2 * q_init[2] - q_3 * q_init[3];
				q1 = q_0 * q_init[1] + q_1 * q_init[0] + q_2 * q_init[3] - q_3 * q_init[2];
				q2 = q_0 * q_init[2] + q_2 * q_init[0] + q_3 * q_init[1] - q_1 * q_init[3];
				q3 = q_0 * q_init[3] + q_3 * q_init[0] + q_1 * q_init[2] - q_2 * q_init[1];

				//cout << q0 << " " << q1 << " " << q2 << " " << q3 << endl;
				double height;
				double s;
				//Z-> Y ->  X
				double angle;
				Rotaxis_X = 2 * q2*q1 + q3;
				Rotaxis_Y = 2 * q0*q0 - 1 + 2 * q2*q2;
				Rotaxis_Z = 2 * q2*q3 - q1;

				s = sqrt(Rotaxis_X*Rotaxis_X + Rotaxis_Y * Rotaxis_Y + Rotaxis_Z * Rotaxis_Z);

				Rotaxis_X = Rotaxis_X / s;
				Rotaxis_Y = Rotaxis_Y / s;
				Rotaxis_Z = Rotaxis_Z / s;

				angle = acos(Rotaxis_Y);
				if(i==6)
				nodelist[i]->height[j] = -15 * (1 - cos(angle));

				//cout << nodelist[i]->height[j] << endl;
			}


			for (int j = 0; j < frames; j++)
			{
				height_r = nodelist[6]->height[j] + nodelist[7]->height[j];
				//height_l = nodelist[8]->height[j] + nodelist[9]->height[j];
				nodelist[3]->height[j] = height_r;

			}
		}






	}
};