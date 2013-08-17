#pragma once
#include <vector>
#include <stdio.h>
#include "windows.h"
#ifndef SegmentationH
#define SegmentationH
using namespace std ;

struct SegmentLocation
{
	int x, y;
};

 class Segmentation
{
public:
	Segmentation(void);
	int Xmax, Xmin, Ymax, Ymin;
	int PointCnt;
	SegmentLocation center;
	System::Void SegmentationInit(int Xvalue, int Yvalue);
	System::Void SegmentationInsert(int Xvalue, int Yvalue);
	vector<SegmentLocation> LocationList;
};
#endif