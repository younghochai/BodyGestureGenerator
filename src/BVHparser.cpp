/** \brief @Modular Motion Auhtoring Platform
*  *  \authors: Bharatesh chakravarthi <chakravarthi589@gmail.com>
				Ashok Kumar Patil <ashokpatil03@hotmail.com>
				Adithya Balasubramanyam <adithyakoundinya@gmail.com>
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include "BVHparser.hpp"

using namespace std;



void BVHparser::loadBVH(const char* path) 
{
	int lineNum = 0;
	int channelNum = 0;
	string channels[6];
	float offx, offy, offz;
	mPath = path;
	ifstream in;
	in.open(path, ios::in);
	if(!in)
	{
		cerr << "Cannot open "<<path<<endl; exit(1);
	}
	string line;
	getline(in, line);										//HIERARCHY
	lineNum++;

	if(line != "HIERARCHY")
	{ 
		cout << "Check the file format. The line number "<<lineNum<<" is not fit to the format"<<endl;
	}
	getline(in, line);										//ROOT Hips
	lineNum++;
	MotionNode* rootNode = new MotionNode();
	initnode = rootNode;
	
	rootNode->setRoot();
	istringstream s(line);
	string bvh_keyword;
	string bvh_nodeName;
	s >> bvh_keyword; s >> bvh_nodeName;
	if(bvh_keyword != "ROOT")
	{
		cout << "Check the file format. The line number "<<lineNum<<" is not fit to the format"<<endl;
	}
	rootNode->setName(bvh_nodeName);
	getline(in, line);										//{

	getline(in, line);										//	OFFSET 0.00 0.00 0.00
	s.str("");
	s = istringstream(line);
	s >> bvh_keyword; s >> offx; s >> offy; s >> offz;
	rootNode->setOffset(offx, offy, offz);


	getline(in, line);										//	CHANNELS 6 Xposition Yposition Zposition Xrotation Yrotation Zrotation
	s.str("");
	s = istringstream(line);
	s >> bvh_keyword; s >> channelNum;
	for(int i = 0;i << channelNum;i++)
	{
		s >> channels[i];
	}
	rootNode->setChannels(channelNum, channels);

	MotionNode* prevNode = rootNode;
	MotionNode* prevNode4NextNode = rootNode;
	getline(in, line);
	while(line!="MOTION")						
	{
		//cout<<endl;
		//cout<<line<<endl;
		s.str("");
		s = istringstream(line);
		s >> bvh_keyword; s >> bvh_nodeName;
		if(bvh_keyword == "JOINT")							//	JOINT LeftUpLeg
		{
			MotionNode *newNode = new MotionNode();
			newNode->setName(bvh_nodeName);

			//cout << bvh_nodeName <<endl;	//print to check

			getline(in, line);								//	{
			getline(in, line);								//		OFFSET 3.64953 0.00000 0.00000
			s.str("");
			s = istringstream(line);
			s >> bvh_keyword; s >> offx; s >> offy; s >> offz;
			newNode->setOffset(offx, offy, offz);

			getline(in, line);								//		CHANNELS 3 Xrotation Yrotation Zrotation
			s.str("");
			s = istringstream(line);
			s >> bvh_keyword; s >> channelNum;
			for(int i = 0;i << channelNum;i++)
			{
				s >> channels[i];
			}
			newNode->setChannels(channelNum, channels);
			newNode->setParent(prevNode);
			prevNode4NextNode->setNext(newNode);
			prevNode = newNode;
			prevNode4NextNode = newNode;
		}
		else if(bvh_keyword == "End")						//	End Site
		{
			MotionNode *newNode = new MotionNode();
			newNode->setName(bvh_nodeName);
			newNode->setEnd();
			getline(in, line);								//	{
			getline(in, line);								//		OFFSET 3.64953 0.00000 0.00000
			s.str("");
			s = istringstream(line);
			s >> bvh_keyword; s >> offx; s >> offy; s >> offz;
			newNode->setOffset(offx, offy, offz);

			newNode->setParent(prevNode);
			getline(in, line);								//	}
		}
		else if(bvh_keyword == "}")
		{
			prevNode = prevNode->getParent();
			//cout<<prevNode->getName()<<endl;
		}
		else
		{
			cout << "Check the file format." <<endl;
		}
		getline(in, line);
	}

// 	Start MotionNode										//MOTION
	string str1, str2;	//to get the string for format
	double fvalue;
	getline(in, line);										//Frames: 4692
	s.str("");
	s = istringstream(line);
	s >> str1; s >> fvalue;
	frames = fvalue;

	getline(in, line);										//Frame Time: 0.008333
	s.str("");
	s = istringstream(line);
	s >> str1; s >> str2; s >> fvalue;
	frameTime = fvalue;

	cout << "frames : " << frames <<", frame time : " << frameTime << endl;

	double f[6];
	MotionNode *curNode;
	
	for(int i = 0; i < frames; i++)
	{
		curNode = rootNode;
		getline(in, line);
		s.str("");
		s = istringstream(line);
		while(curNode != NULL)
		{
			 //cout << curNode->getName()<<endl;		//print to check

			//curNode->initData(frames);

			for(int j = 0; j < curNode->getChannelNum(); j++)
			{
				s >> f[j];
				//cout << line<< endl;
				//curNode->data[i][j] = f[j];
				// cout<< curNode->data[i][j]<<", ";
				 curNode->datatest[i][j] = f[j];
				 //cout << f[j] << ", ";
				 //cout << curNode->datatest[i][j] << "/ ";
			}
			//cout<<endl;
			curNode = curNode->getNextNode();
		}

	}
	/*curNode = rootNode;
	curNode = curNode->getNextNode();
	for (int i = 0; i < 10; i++)
	{
		curNode = rootNode;

			for (int j = 0; j < curNode->getChannelNum(); j++)
			{
				
				cout << curNode->datatest[i][j] << ", ";
			}
			cout << endl;
			
		

	}*/

}


void NodeManage::loadQuaternion(const char* path)
{
	int lineNum = 0;
	int channelNum = 0;
	string channels[6];
	float offx, offy, offz;

	ifstream in;
	in.open(path, ios::in);
	if (!in)
	{
		cerr << "Cannot open " << path << endl; exit(1);
	}
	string line;


	istringstream s(line);


	// 	Start MotionNode										//MOTION
	string str1, str2;	//to get the string for format
	double fvalue;
	getline(in, line);										//UPPERBODY 2
	s.str("");
	s = istringstream(line);
	s >> str1; s >> fvalue;


	getline(in, line);										//Frames: 144
	s.str("");
	s = istringstream(line);
	s >> str1;  s >> fvalue;
	frames = fvalue;

	cout << "frames : " << frames << endl;

	double f[4];


	for (int i = 0; i < frames; i++)
	{

		getline(in, line);
		s.str("");
		s = istringstream(line);
		for (int k = 0; k < 10; k++)
		{
			//cout << curNode->getName()<<endl;		//print to check

		   //curNode->initData(frames);

			for (int j = 0; j < 4; j++)
			{
				s >> f[j];
				//cout << line<< endl;
				//curNode->data[i][j] = f[j];
				// cout<< curNode->data[i][j]<<", ";
				nodelist[k]->datatest[i][j] = f[j];
				// k : node index , i : frame index , j : quaternion index
				//cout << f[j] << ", ";
				//cout << curNode->datatest[i][j] << "/ ";
			}
			//cout<<endl;

		}

	}


}
void NodeManage::loadEuler(const char* path)
{
	int lineNum = 0;
	int channelNum = 0;
	string channels[6];
	float offx, offy, offz;

	ifstream in;
	in.open(path, ios::in);
	if (!in)
	{
		cerr << "Cannot open " << path << endl; exit(1);
	}
	string line;


	istringstream s(line);


	// 	Start MotionNode										//MOTION
	string str1, str2;	//to get the string for format
	double fvalue;
	getline(in, line);										//UPPERBODY 2
	s.str("");
	s = istringstream(line);
	s >> str1; s >> fvalue;


	getline(in, line);										//Frames: 144
	s.str("");
	s = istringstream(line);
	s >> str1;  s >> fvalue;
	frames = fvalue;

	//cout << "frames : " << frames << endl;

	double f[4];

	double buf_E[3];
	for (int i = 0; i < frames; i++)
	{

		getline(in, line);
		s.str("");
		s = istringstream(line);
		for (int k = 0; k < 9; k++)
		{
			//cout << curNode->getName()<<endl;		//print to check

		   //curNode->initData(frames);

			for (int j = 0; j < 3; j++)
			{
				s >> f[j];
				//cout << line<< endl;
				//curNode->data[i][j] = f[j];
				// cout<< curNode->data[i][j]<<", ";
				buf_E[j]= f[j];
				// k : node index , i : frame index , j : quaternion index
				//cout << f[j] << ", ";
				//cout << curNode->datatest[i][j] << "/ ";
			}

			nodelist[k]->eulerangle[i][0] = buf_E[0];
			nodelist[k]->eulerangle[i][1] = buf_E[1];
			nodelist[k]->eulerangle[i][2] = buf_E[2];
			//cout<<endl;

		}

	}


}

void PositionManage::loadQuaternion(const char* path)
{
	int lineNum = 0;
	int channelNum = 0;
	
	

	ifstream in;
	in.open(path, ios::in);
	if (!in)
	{
		cerr << "Cannot open " << path << endl; exit(1);
	}
	string line;


	istringstream s(line);


	//// 	Start MotionNode										//MOTION
	//string str1, str2;	//to get the string for format
	//double fvalue;
	//getline(in, line);										//UPPERBODY 2
	//s.str("");
	//s = istringstream(line);
	//s >> str1; s >> fvalue;


	//getline(in, line);										//Frames: 144
	//s.str("");
	//s = istringstream(line);
	//s >> str1;  s >> fvalue;
	//frames = fvalue;

	
	int i = 0;
	double f[4];


	//for (int i = 0; i < frames; i++)
	while (s)
	{

		getline(in, line);
		s.str("");
		s = istringstream(line);
		

			for (int j = 0; j < 3; j++)
			{
				s >> f[j];
				//cout << line<< endl;
				//curNode->data[i][j] = f[j];
				// cout<< curNode->data[i][j]<<", ";
				nodelist->datatest[i][j] = f[j];
				// k : node index , i : frame index , j : quaternion index
				//cout << f[j] << ", ";
				//cout << curNode->datatest[i][j] << "/ ";
			}
			//cout<<endl;
			i++;

	}
	frames = i;
	cout << "frames : " << frames << endl;

}

void RowdataManage::loadRow(const char* path)
{
	int lineNum = 0;
	int channelNum = 0;
	string channels[6];
	float offx, offy, offz;

	ifstream in;
	in.open(path, ios::in);
	if (!in)
	{
		cerr << "Cannot open " << path << endl; exit(1);
	}
	string line;


	istringstream s(line);


	// 	Start MotionNode										//MOTION
	string str1, str2;	//to get the string for format
	double fvalue;
	getline(in, line);										//UPPERBODY 2
	s.str("");
	s = istringstream(line);
	s >> str1; s >> fvalue;


	getline(in, line);										//Frames: 144
	s.str("");
	s = istringstream(line);
	s >> str1;  s >> fvalue;
	frames = fvalue;

	cout << "frames : " << frames << endl;

	double f[4];

	
	
	for (int i = 0; i < frames; i++)
	{
		pidn[i] = i;
		getline(in, line);
		s.str("");
		s = istringstream(line);
		for (int k = 0; k < 10; k++)
		{
			//cout << curNode->getName()<<endl;		//print to check

		   //curNode->initData(frames);

			for (int j = 0; j < 4; j++)
			{
				s >> f[j];
				//cout << line<< endl;
				//curNode->data[i][j] = f[j];
				// cout<< curNode->data[i][j]<<", ";
				nodelist[k]->datatest[i][j] = f[j];
				// k : node index , i : frame index , j : quaternion index
				//cout << f[j] << ", ";
				//cout << curNode->datatest[i][j] << "/ ";
			}
			//cout<<endl;

		}

	}


}