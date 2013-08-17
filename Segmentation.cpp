#include "StdAfx.h"
#include "Segmentation.h"

Segmentation::Segmentation(void)  //初始化
{
	this->Xmax = 0;
	this->Xmin = 0;
	this->Ymax = 0;
	this->Ymin = 0;
}
System::Void Segmentation::SegmentationInit(int Xvalue, int Yvalue)  //初始化 push第一個為0
{
	SegmentLocation node;
	node.x = Xvalue;
	node.y = Yvalue;
	LocationList.push_back(node);   
	this->Xmax = Xvalue; 
	this->Xmin = Xvalue;
	this->Ymax = Yvalue;
	this->Ymin = Yvalue;
	this->PointCnt = 0;
}
System::Void Segmentation::SegmentationInsert(int Xvalue, int Yvalue)
{
	SegmentLocation node;
	node.x = Xvalue;
	node.y = Yvalue;
	LocationList.push_back(node);
	if(Xvalue > this->Xmax)	this->Xmax = Xvalue;  //XY最大最小值
	if(Xvalue < this->Xmin)	this->Xmin = Xvalue;
	if(Yvalue > this->Ymax)	this->Ymax = Yvalue;
	if(Yvalue < this->Ymin)	this->Ymin = Yvalue;
	this->PointCnt++;
}