

//---------------------------------------------------------------------------
//#include <vcl.h>
#define _USE_MATH_DEFINES


#include <math.h>
#include <stdio.h>
//#pragma hdrstop

//#include "../../Tools/CFileConfig.h"
#include "TImageData.h"




//---------------------------------------------------------------------------

//#pragma package(smart_init)
//---------------------------------------------------------------------------

TImageData *ImageData = new TImageData();
//---------------------------------------------------------------------------

float  TImageData::ComputeCenterAngle(float AngleStartPoint
	, float AngleEndPoint)
{
	float tmpAngle;

	if(AngleEndPoint < AngleStartPoint)
	{
		if(AngleStartPoint < 0.0)
			AngleStartPoint += (2.0 * M_PI);
		if(AngleEndPoint < 0.0)
			AngleEndPoint += (2.0 * M_PI);
	}
	tmpAngle = (AngleEndPoint - AngleStartPoint) / 2.0 + AngleStartPoint;

	//else
	//{
	//        tmpAngle = (AngleEndPoint + AngleStartPoint) / 2.0;
	//}

	if(tmpAngle > M_PI)
		tmpAngle -= (2.0 * M_PI);

	return tmpAngle;
}

TImageData::TImageData(void)
{
	ImageWidth = 640;
	ImageHeight = 480;

	xImageCenter = 320;
	yImageCenter = 240;

	ColorDeep = 256;

	AngularToRadian = M_PI / 180.0;
	RadianToAngular = 180.0 / M_PI;

	GlobalScanMagnEnd = 237;
	//--- Model Unit
	hsvBlueRange = new ColorRange;
	hsvBlueRange->HueMax = 1.0;
	hsvBlueRange->HueMin = 0.0;
	hsvBlueRange->SaturationMax = 1.0;
	hsvBlueRange->SaturationMin = 0.0;
	hsvBlueRange->BrightnessMax = 1.0;
	hsvBlueRange->BrightnessMin = 0.0;

	hsvBlackRange = new ColorRange;
	hsvBlackRange->HueMax = 1.0;
	hsvBlackRange->HueMin = 0.0;
	hsvBlackRange->SaturationMax = 1.0;
	hsvBlackRange->SaturationMin = 0.0;
	hsvBlackRange->BrightnessMax = 1.0;
	hsvBlackRange->BrightnessMin = 0.0;

	hsvGreenRange = new ColorRange;
	hsvGreenRange->HueMax = 1.0;
	hsvGreenRange->HueMin = 0.0;
	hsvGreenRange->SaturationMax = 1.0;
	hsvGreenRange->SaturationMin = 0.0;
	hsvGreenRange->BrightnessMax = 1.0;
	hsvGreenRange->BrightnessMin = 0.0;

	hsvOrangeRange = new ColorRange;
	hsvOrangeRange->HueMax = 1.0;
	hsvOrangeRange->HueMin = 0.0;
	hsvOrangeRange->SaturationMax = 1.0;
	hsvOrangeRange->SaturationMin = 0.0;
	hsvOrangeRange->BrightnessMax = 1.0;
	hsvOrangeRange->BrightnessMin = 0.0;

	hsvYellowRange = new ColorRange;
	hsvYellowRange->HueMax = 1.0;
	hsvYellowRange->HueMin = 0.0;
	hsvYellowRange->SaturationMax = 1.0;
	hsvYellowRange->SaturationMin = 0.0;
	hsvYellowRange->BrightnessMax = 1.0;
	hsvYellowRange->BrightnessMin = 0.0;

	hsvRedRange = new ColorRange;
	hsvRedRange->HueMax = 1.0;
	hsvRedRange->HueMin = 0.0;
	hsvRedRange->SaturationMax = 1.0;
	hsvRedRange->SaturationMin = 0.0;
	hsvRedRange->BrightnessMax = 1.0;
	hsvRedRange->BrightnessMin = 0.0;

	pImage = new unsigned char[3 * ImageWidth * ImageHeight];

}

TImageData::~TImageData(void)
{

	//--- Model Unit
	delete hsvBlueRange;
	delete hsvBlackRange;
	delete hsvGreenRange;
	delete hsvOrangeRange;
	delete hsvYellowRange;
	delete hsvRedRange;
}

/*
 TImageData::TImageData(void)
{
		
        //--- Global
		configPath = CONFIG_DEFAULT_PATH;
		configFileName = CONFIG_FILE;
        ImageWidth = 640;
        ImageHeight = 480;
        ArrowAngle = 0.0;
        ColorDeep = 256;
        AngularToRadian = M_PI / 180.0;
        RadianToAngular = 180.0 / M_PI;
		TargetDistance =NULL;
        LoadiniFile();
        pImage = new unsigned char[3 * ImageWidth * ImageHeight];

        Ball = new PatternInfo;
        Ball->PointCounter = 0;

        BlueGoal = new PatternInfo;
        BlueGoal->PointCounter = 0;

        YellowGoal = new PatternInfo;
        YellowGoal->PointCounter = 0;

        CylinderA = new PatternInfo;
        CylinderA->PointCounter = 0;

        CylinderB = new PatternInfo;
        CylinderB->PointCounter = 0;

        CylinderC = new PatternInfo;
        CylinderC->PointCounter = 0;

        CylinderD = new PatternInfo;
        CylinderD->PointCounter = 0;

        BlackObstacleGap = 24;
        BlackObstacleAngle = 2.0 * M_PI / (float)BlackObstacleGap;
        BlackObstacle = new int[BlackObstacleGap];

        //--- Model Unit
        yiqColorModel = NULL;
        hsvBlueRange = new ColorRange;
        hsvBlueRange->HueMax = 1.0;
        hsvBlueRange->HueMin = 0.0;
        hsvBlueRange->SaturationMax = 1.0;
        hsvBlueRange->SaturationMin = 0.0;
        hsvBlueRange->BrightnessMax = 1.0;
        hsvBlueRange->BrightnessMin = 0.0;
        
        hsvBlackRange = new ColorRange;
        hsvBlackRange->HueMax = 1.0;
        hsvBlackRange->HueMin = 0.0;
        hsvBlackRange->SaturationMax = 1.0;
        hsvBlackRange->SaturationMin = 0.0;
        hsvBlackRange->BrightnessMax = 1.0;
        hsvBlackRange->BrightnessMin = 0.0;

        hsvGreenRange = new ColorRange;
        hsvGreenRange->HueMax = 1.0;
        hsvGreenRange->HueMin = 0.0;
        hsvGreenRange->SaturationMax = 1.0;
        hsvGreenRange->SaturationMin = 0.0;
        hsvGreenRange->BrightnessMax = 1.0;
        hsvGreenRange->BrightnessMin = 0.0;

        hsvOrangeRange = new ColorRange;
        hsvOrangeRange->HueMax = 1.0;
        hsvOrangeRange->HueMin = 0.0;
        hsvOrangeRange->SaturationMax = 1.0;
        hsvOrangeRange->SaturationMin = 0.0;
        hsvOrangeRange->BrightnessMax = 1.0;
        hsvOrangeRange->BrightnessMin = 0.0;

        hsvYellowRange = new ColorRange;
        hsvYellowRange->HueMax = 1.0;
        hsvYellowRange->HueMin = 0.0;
        hsvYellowRange->SaturationMax = 1.0;
        hsvYellowRange->SaturationMin = 0.0;
        hsvYellowRange->BrightnessMax = 1.0;
        hsvYellowRange->BrightnessMin = 0.0;

        hsvRedRange = new ColorRange;
        hsvRedRange->HueMax = 1.0;
        hsvRedRange->HueMin = 0.0;
        hsvRedRange->SaturationMax = 1.0;
        hsvRedRange->SaturationMin = 0.0;
        hsvRedRange->BrightnessMax = 1.0;
        hsvRedRange->BrightnessMin = 0.0;

        //--- Tracking Unit
        LocalAngleScanGap = AngularToRadian;
        LocalMagnScanGap = 1;

        //--- CommunicationUnit
        EmptyConstant = -999;
        xPosition = EmptyConstant;
        yPosition = EmptyConstant;

		setupForm_Visible = false;
		
}
//---------------------------------------------------------------------------

 TImageData::~TImageData(void)
{
        //--- Model Unit
        delete hsvBlueRange;
        delete hsvBlackRange;
        delete hsvGreenRange;
        delete hsvOrangeRange;
        delete hsvYellowRange;
        delete hsvRedRange;
        if(yiqColorModel != NULL)
                delete[] yiqColorModel;
        delete TargetDistance;
        if(GlobalScanPoint != NULL)
                delete[] GlobalScanPoint;        
        delete[] BlackObstacle;
        delete CylinderA;
        delete CylinderB;
        delete CylinderC;
        delete CylinderD;        
        delete YellowGoal;
        delete BlueGoal;
        delete Ball;

        delete[] pImage;
}
//---------------------------------------------------------------------------

void  TImageData::LoadModelFromFile(std::string FileString)
{
        FILE *fp;

        fp = fopen(FileString.c_str(), "r+");
        if(fp != NULL)
        {
                if(yiqColorModel == NULL)
                        yiqColorModel = new unsigned char[ColorDeep * ColorDeep
                                * ColorDeep];

                fread(yiqColorModel, sizeof(unsigned char), ColorDeep
                        * ColorDeep * ColorDeep, fp);
                fclose(fp);
        }
}
//---------------------------------------------------------------------------

void  TImageData::LoadModelFromFile(unsigned char *SampleArray)
{
        unsigned char *tmpHere;

        tmpHere = yiqColorModel;
        for(int i=0 ; i<ColorDeep ; i++)
                for(int j=0 ; j<ColorDeep ; j++)
                        for(int k=0 ; k<ColorDeep ; k++)
                                *tmpHere++ = *SampleArray++;
}
//---------------------------------------------------------------------------

unsigned char  TImageData::ColorSegmentation(unsigned char yValue
        , unsigned char uValue, unsigned char vValue)
{
        if(yiqColorModel == NULL)
                return 0x00;

        return yiqColorModel[yValue * ColorDeep * ColorDeep + uValue * ColorDeep
                + vValue];
}
//---------------------------------------------------------------------------


void  TImageData::LoadiniFile(void)
{
        //TIniFile *iniInput;
        //iniInput = new TIniFile(ExtractFilePath(Application->ExeName) + "Configuration.ini");

	CFileConfig fcIn;
	fcIn.Load(configPath + configFileName);
    //--- Global
	fcIn.Get("[Global]", "xImageCenter", 320) >> xImageCenter;
	fcIn.Get("[Global]", "yImageCenter", 240)>> yImageCenter;
	fcIn.Get("[Global]", "xRadiusScale", 80) >> xRadiusScale;
	fcIn.Get("[Global]", "yRadiusScale", 40) >> yRadiusScale;
	ZoomScale = (float)xRadiusScale / (float)yRadiusScale;
	fcIn.Get("[Global]", "ArrowAngle", (float)0.0) >> ArrowAngle;

    //--- TrackingUnit
    fcIn.Get("[TrackingUnit]", "GlobalScanMagnNearGap", 20)							>> GlobalScanMagnNearGap;
    fcIn.Get("[TrackingUnit]", "GlobalScanMagnMiddleGap", 12)						>> GlobalScanMagnMiddleGap;
    fcIn.Get("[TrackingUnit]", "GlobalScanMagnFarGap", 5)							>> GlobalScanMagnFarGap;
    fcIn.Get("[TrackingUnit]", "GlobalScanMagnNearStart", 50)						>> GlobalScanMagnNearStart;
    fcIn.Get("[TrackingUnit]", "GlobalScanMagnMiddleStart", 124)					>> GlobalScanMagnMiddleStart;
    fcIn.Get("[TrackingUnit]", "GlobalScanMagnFarStart", 184)						>> GlobalScanMagnFarStart;
    fcIn.Get("[TrackingUnit]", "GlobalScanMagnEnd", 300)							>> GlobalScanMagnEnd;

	fcIn.Get("[TrackingUnit]", "GlobalScanAngleNearGap", (float)10.0 * AngularToRadian)    >> GlobalScanAngleNearGap;
    fcIn.Get("[TrackingUnit]", "GlobalScanAngleMiddleGap", (float) 4.0 * AngularToRadian)	>> GlobalScanAngleMiddleGap;
    fcIn.Get("[TrackingUnit]", "GlobalScanAngleFarGap", (float) 2.0 * AngularToRadian)		>> GlobalScanAngleFarGap;
    //--- [TrackingUnit] EstimateDistance
    fcIn.Get("[TrackingUnit]", "TargetDistanceMax", 20) >> TargetDistanceMax;
    fcIn.Get("[TrackingUnit]", "TargetDistanceGap", 20) >> TargetDistanceGap;
    if(TargetDistance != NULL)        {
		delete[] TargetDistance;
	}
    TargetDistance = new int[TargetDistanceMax];
    for(int tmp=0 ; tmp<TargetDistanceMax ; tmp++){
                fcIn.Get("[TrackingUnit]", "TargetDistance[" + UtilityTool::int2stdstring(tmp)  + "]",(float) 20 * tmp) >> TargetDistance[tmp];
	}
    //--- CommunicationUnit
    fcIn.Get("[CommunicationUnit]", "LocalPort", 300) >> LocalPort;
    fcIn.Get("[CommunicationUnit]", "RemotePort", 301) >> RemotePort;
    fcIn.Get("[CommunicationUnit]", "RemoteHost", "127.0.0.1") >> RemoteHost;
    fcIn.Get("[CommunicationUnit]", "EmptyConstant", -999) >> EmptyConstant;

    //GlobalScanPointBuild();

    //delete fcIn;
}
//---------------------------------------------------------------------------
void  TImageData::SaveiniFile(void)
{
        //TIniFile *iniOutput;
        //iniOutput = new TIniFile(ExtractFilePath(Application->ExeName) + "Configuration.ini");
		
		CFileConfig fcOut;
		fcOut.Load( UtilityTool::net2StdString(CONFIG_DEFAULT_PATH + CONFIG_FILE));

        //--- Global
        fcOut.Set("[Global]", "xImageCenter", xImageCenter);
        fcOut.Set("[Global]", "yImageCenter", yImageCenter);
        fcOut.Set("[Global]", "xRadiusScale", xRadiusScale);
        fcOut.Set("[Global]", "yRadiusScale", yRadiusScale);
        fcOut.Set("[Global]", "ArrowAngle", ArrowAngle);

        //--- TrackingUnit
        fcOut.Set("[TrackingUnit]", "GlobalScanMagnNearGap", GlobalScanMagnNearGap);
        fcOut.Set("[TrackingUnit]", "GlobalScanMagnMiddleGap", GlobalScanMagnMiddleGap);
        fcOut.Set("[TrackingUnit]", "GlobalScanMagnFarGap", GlobalScanMagnFarGap);
        fcOut.Set("[TrackingUnit]", "GlobalScanMagnNearStart", GlobalScanMagnNearStart);
        fcOut.Set("[TrackingUnit]", "GlobalScanMagnMiddleStart", GlobalScanMagnMiddleStart);
        fcOut.Set("[TrackingUnit]", "GlobalScanMagnFarStart", GlobalScanMagnFarStart);
        fcOut.Set("[TrackingUnit]", "GlobalScanMagnEnd", GlobalScanMagnEnd);
        fcOut.Set("[TrackingUnit]", "GlobalScanAngleNearGap", GlobalScanAngleNearGap);
        fcOut.Set("[TrackingUnit]", "GlobalScanAngleMiddleGap", GlobalScanAngleMiddleGap);
        fcOut.Set("[TrackingUnit]", "GlobalScanAngleFarGap", GlobalScanAngleFarGap);

        //--- TrackingUnit, EstimateDistance
        fcOut.Set("[TrackingUnit]", "TargetDistanceMax", TargetDistanceMax);
        fcOut.Set("[TrackingUnit]", "TargetDistanceGap", TargetDistanceGap);
        for(int tmp=0 ; tmp<TargetDistanceMax ; tmp++)
                fcOut.Set("[TrackingUnit]", "TargetDistance[" + UtilityTool::int2stdstring(tmp) + "]",TargetDistance[tmp]);

        //--- CommunicationUnit
        fcOut.Set("[CommunicationUnit]", "LocalPort", LocalPort);
        fcOut.Set("[CommunicationUnit]", "RemotePort", RemotePort);
        fcOut.Set("[CommunicationUnit]", "RemoteHost", RemoteHost);
        fcOut.Set("[CommunicationUnit]", "EmptyConstant", EmptyConstant);

		fcOut.Save();
        //delete fcOut;
}
//---------------------------------------------------------------------------

void  TImageData::LoadColorRagneFormFile(std::string FileString)
{
	CFileConfig fcIn;
	fcIn.Load(FileString);

	fcIn.Get("[Blue Range]", "Hue Max", (float)0.0)			>> hsvBlueRange->HueMax;
	fcIn.Get("[Blue Range]", "Hue Min", (float)0.0)			>> hsvBlueRange->HueMin;
	fcIn.Get("[Blue Range]", "Saturation Max", (float)0.0)	>> hsvBlueRange->SaturationMax;
	fcIn.Get("[Blue Range]", "Saturation Min", (float)0.0)	>> hsvBlueRange->SaturationMin;
	fcIn.Get("[Blue Range]", "Brightness Max", (float)0.0)	>> hsvBlueRange->BrightnessMax;
	fcIn.Get("[Blue Range]", "Brightness Min", (float)0.0)	>> hsvBlueRange->BrightnessMin;

	fcIn.Get("[Black Range]", "Hue Max", "0")			>> hsvBlackRange->HueMax;
	fcIn.Get("[Black Range]", "Hue Min", "0")			>> hsvBlackRange->HueMin ;
	fcIn.Get("[Black Range]", "Saturation Max", "0")  >> hsvBlackRange->SaturationMax ;
	fcIn.Get("[Black Range]", "Saturation Min","0")  >> hsvBlackRange->SaturationMin;
	fcIn.Get("[Black Range]", "Brightness Max", "0")  >> hsvBlackRange->BrightnessMax;
	fcIn.Get("[Black Range]", "Brightness Min","0")  >> hsvBlackRange->BrightnessMin;

	fcIn.Get("[Green Range]", "Hue Max", "0")			>> hsvGreenRange->HueMax;
	fcIn.Get("[Green Range]", "Hue Min", "0")			>> hsvGreenRange->HueMin;
	fcIn.Get("[Green Range]", "Saturation Max", "0")  >> hsvGreenRange->SaturationMax;
	fcIn.Get("[Green Range]", "Saturation Min", "0")  >> hsvGreenRange->SaturationMin;
	fcIn.Get("[Green Range]", "Brightness Max", "0")  >> hsvGreenRange->BrightnessMax;
	fcIn.Get("[Green Range]", "Brightness Min", "0")  >> hsvGreenRange->BrightnessMin ;

    fcIn.Get("[Orange Range]", "Hue Max", "0")		>> hsvOrangeRange->HueMax;
    fcIn.Get("[Orange Range]", "Hue Min", "0")		>> hsvOrangeRange->HueMin;
    fcIn.Get("[Orange Range]", "Saturation Max", "0") >> hsvOrangeRange->SaturationMax;
    fcIn.Get("[Orange Range]", "Saturation Min", "0") >> hsvOrangeRange->SaturationMin;
    fcIn.Get("[Orange Range]", "Brightness Max", "0") >> hsvOrangeRange->BrightnessMax;
    fcIn.Get("[Orange Range]", "Brightness Min", "0") >> hsvOrangeRange->BrightnessMin;

    fcIn.Get("[Yellow Range]", "Hue Max", "0")		>> hsvYellowRange->HueMax;
    fcIn.Get("[Yellow Range]", "Hue Min", "0")		>> hsvYellowRange->HueMin;
    fcIn.Get("[Yellow Range]", "Saturation Max", "0") >> hsvYellowRange->SaturationMax;
    fcIn.Get("[Yellow Range]", "Saturation Min", "0") >> hsvYellowRange->SaturationMin;
    fcIn.Get("[Yellow Range]", "Brightness Max", "0") >> hsvYellowRange->BrightnessMax;
    fcIn.Get("[Yellow Range]", "Brightness Min", "0") >> hsvYellowRange->BrightnessMin;

    fcIn.Get("[Red Range]", "Hue Max", "0")			>> hsvRedRange->HueMax;
    fcIn.Get("[Red Range]", "Hue Min", "0")			>> hsvRedRange->HueMin;
    fcIn.Get("[Red Range]", "Saturation Max", "0")	>> hsvRedRange->SaturationMax;
    fcIn.Get("[Red Range]", "Saturation Min", "0")	>> hsvRedRange->SaturationMin;
    fcIn.Get("[Red Range]", "Brightness Max", "0")	>> hsvRedRange->BrightnessMax;
    fcIn.Get("[Red Range]", "Brightness Min", "0")	>> hsvRedRange->BrightnessMin;

    //delete fcIn;
}
//---------------------------------------------------------------------------

void  TImageData::SaveColorRagneFormFile(std::string FileString)
{
	CFileConfig fcOut;
	//fcOut.Load(FileString);
	//kartik:need default file
	fcOut.Load( UtilityTool::net2StdString(CONFIG_DEFAULT_PATH + HSV_COLOR_RANGE_FILE));

	fcOut.Set("[Blue Range]", "Hue Max", hsvBlueRange->HueMax);
	fcOut.Set("[Blue Range]", "Hue Min", hsvBlueRange->HueMin);
	fcOut.Set("[Blue Range]", "Saturation Max", hsvBlueRange->SaturationMax);
	fcOut.Set("[Blue Range]", "Saturation Min", hsvBlueRange->SaturationMin);
	fcOut.Set("[Blue Range]", "Brightness Max", hsvBlueRange->BrightnessMax);
	fcOut.Set("[Blue Range]", "Brightness Min", hsvBlueRange->BrightnessMin);

	fcOut.Set("[Black Range]", "Hue Max", hsvBlackRange->HueMax);
	fcOut.Set("[Black Range]", "Hue Min", hsvBlackRange->HueMin);
	fcOut.Set("[Black Range]", "Saturation Max", hsvBlackRange->SaturationMax);
	fcOut.Set("[Black Range]", "Saturation Min", hsvBlackRange->SaturationMin);
	fcOut.Set("[Black Range]", "Brightness Max", hsvBlackRange->BrightnessMax);
	fcOut.Set("[Black Range]", "Brightness Min", hsvBlackRange->BrightnessMin);

	fcOut.Set("[Green  Range]", "Hue Max", hsvGreenRange->HueMax);
	fcOut.Set("[Green  Range]", "Hue Min", hsvGreenRange->HueMin);
	fcOut.Set("[Green  Range]", "Saturation Max", hsvGreenRange->SaturationMax);
	fcOut.Set("[Green  Range]", "Saturation Min", hsvGreenRange->SaturationMin);
	fcOut.Set("[Green  Range]", "Brightness Max", hsvGreenRange->BrightnessMax);
	fcOut.Set("[Green  Range]", "Brightness Min", hsvGreenRange->BrightnessMin);

	fcOut.Set("[Orange  Range]", "Hue Max", hsvOrangeRange->HueMax);
	fcOut.Set("[Orange  Range]", "Hue Min", hsvOrangeRange->HueMin);
	fcOut.Set("[Orange  Range]", "Saturation Max", hsvOrangeRange->SaturationMax);
	fcOut.Set("[Orange  Range]", "Saturation Min", hsvOrangeRange->SaturationMin);
	fcOut.Set("[Orange  Range]", "Brightness Max", hsvOrangeRange->BrightnessMax);
	fcOut.Set("[Orange  Range]", "Brightness Min", hsvOrangeRange->BrightnessMin);

	fcOut.Set("[Yellow Range]", "Hue Max", hsvYellowRange->HueMax);
	fcOut.Set("[Yellow Range]", "Hue Min", hsvYellowRange->HueMin);
	fcOut.Set("[Yellow Range]", "Saturation Max", hsvYellowRange->SaturationMax);
	fcOut.Set("[Yellow Range]", "Saturation Min", hsvYellowRange->SaturationMin);
	fcOut.Set("[Yellow Range]", "Brightness Max", hsvYellowRange->BrightnessMax);
	fcOut.Set("[Yellow Range]", "Brightness Min", hsvYellowRange->BrightnessMin);

	fcOut.Set("[Red Range]", "Hue Max", hsvRedRange->HueMax);
	fcOut.Set("[Red Range]", "Hue Min", hsvRedRange->HueMin);
	fcOut.Set("[Red Range]", "Saturation Max", hsvRedRange->SaturationMax);
	fcOut.Set("[Red Range]", "Saturation Min", hsvRedRange->SaturationMin);
	fcOut.Set("[Red Range]", "Brightness Max", hsvRedRange->BrightnessMax);
	fcOut.Set("[Red Range]", "Brightness Min", hsvRedRange->BrightnessMin);

	fcOut.Save(FileString);
    //delete fcOut;
}
//---------------------------------------------------------------------------

void  TImageData::GlobalScanPointBuild(void)
{
        bool ContinuesFlag;
        int xValue, yValue;
        float sinValue, cosValue;
        float MagnGap, AngleGap;
        unsigned char *tmpValue;

        int *GlobalScanPointHere;

        GlobalScanPointCounter = 0;
        AngleGap = GlobalScanAngleNearGap;
        MagnGap = GlobalScanMagnNearGap;
        for(float Angle=M_PI*(-1.0) ; Angle<M_PI ; Angle+=AngleGap)
        {
                sinValue = sin(Angle);
                cosValue = cos(Angle);
                ContinuesFlag = true;
                for(int Magn=GlobalScanMagnNearStart
                        ; Magn<GlobalScanMagnMiddleStart && ContinuesFlag
                        ; Magn+=MagnGap)
                {
                        xValue = (int)((float)Magn * cosValue + 0.5
                                + (float)xImageCenter);
                        yValue = (int)((float)Magn * sinValue + 0.5
                                + (float)yImageCenter);

                        if(xValue>=0 && xValue<ImageWidth
                                && yValue>=0 && yValue<ImageHeight)
                                GlobalScanPointCounter++;
                        else
                                ContinuesFlag = false;
                }
        }

        AngleGap = GlobalScanAngleMiddleGap;
        MagnGap = GlobalScanMagnMiddleGap;
        for(float Angle=M_PI*(-1.0) ; Angle<M_PI ; Angle+=AngleGap)
        {
                sinValue = sin(Angle);
                cosValue = cos(Angle);
                ContinuesFlag = true;
                for(int Magn=GlobalScanMagnMiddleStart
                        ; Magn<GlobalScanMagnFarStart && ContinuesFlag
                        ; Magn+=MagnGap)
                {
                        xValue = (int)((float)Magn * cosValue + 0.5
                                + (float)xImageCenter);
                        yValue = (int)((float)Magn * sinValue + 0.5
                                + (float)yImageCenter);

                        if(xValue>=0 && xValue<ImageWidth && yValue>=0
                                && yValue<ImageHeight)
                                GlobalScanPointCounter++;
                        else
                                ContinuesFlag = false;
                }
        }

        AngleGap = GlobalScanAngleFarGap;
        MagnGap = GlobalScanMagnFarGap;
        for(float Angle=M_PI*(-1.0) ; Angle<M_PI ; Angle+=AngleGap)
        {
                sinValue = sin(Angle);
                cosValue = cos(Angle);
                ContinuesFlag = true;
                for(int Magn=GlobalScanMagnFarStart
                        ; Magn<GlobalScanMagnEnd && ContinuesFlag
                        ; Magn+=MagnGap)
                {
                        xValue = (int)((float)Magn * cosValue + 0.5
                                + (float)xImageCenter);
                        yValue = (int)((float)Magn * sinValue + 0.5
                                + (float)yImageCenter);

                        if(xValue>=0 && xValue<ImageWidth && yValue>=0
                                && yValue<ImageHeight)
                                GlobalScanPointCounter++;
                        else
                                ContinuesFlag = false;
                }
        }
		//kartik-not implement
        //if(GlobalScanPoint != NULL)               delete[] GlobalScanPoint;
        GlobalScanPoint = new int[GlobalScanPointCounter * 2];
        GlobalScanPointHere = GlobalScanPoint;

        AngleGap = GlobalScanAngleNearGap;
        MagnGap = GlobalScanMagnNearGap;
        for(float Angle=M_PI*(-1.0) ; Angle<M_PI ; Angle+=AngleGap)
        {
                sinValue = sin(Angle);
                cosValue = cos(Angle);
                ContinuesFlag = true;
                for(int Magn=GlobalScanMagnNearStart
                        ; Magn<GlobalScanMagnMiddleStart && ContinuesFlag
                        ; Magn+=MagnGap)
                {
                        xValue = (int)((float)Magn * cosValue + 0.5
                                + (float)xImageCenter);
                        yValue = (int)((float)Magn * sinValue + 0.5
                                + (float)yImageCenter);

                        if(xValue>=0 && xValue<ImageWidth && yValue>=0
                                && yValue<ImageHeight)
                        {
                                *GlobalScanPointHere++ = xValue;
                                *GlobalScanPointHere++ = yValue;
                        }
                        else
                                ContinuesFlag = false;
                }
        }

        AngleGap = GlobalScanAngleMiddleGap;
        MagnGap = GlobalScanMagnMiddleGap;
        for(float Angle=M_PI*(-1.0) ; Angle<M_PI ; Angle+=AngleGap)
        {
                sinValue = sin(Angle);
                cosValue = cos(Angle);
                ContinuesFlag = true;
                for(int Magn=GlobalScanMagnMiddleStart
                        ; Magn<GlobalScanMagnFarStart && ContinuesFlag
                        ; Magn+=MagnGap)
                {
                        xValue = (int)((float)Magn * cosValue + 0.5
                                + (float)xImageCenter);
                        yValue = (int)((float)Magn * sinValue + 0.5
                                + (float)yImageCenter);

                        if(xValue>=0 && xValue<ImageWidth && yValue>=0
                                && yValue<ImageHeight)
                        {
                                *GlobalScanPointHere++ = xValue;
                                *GlobalScanPointHere++ = yValue;
                        }
                        else
                                ContinuesFlag = false;
                }
        }

        AngleGap = GlobalScanAngleFarGap;
        MagnGap = GlobalScanMagnFarGap;
        for(float Angle=M_PI*(-1.0) ; Angle<M_PI ; Angle+=AngleGap)
        {
                sinValue = sin(Angle);
                cosValue = cos(Angle);
                ContinuesFlag = true;
                for(int Magn=GlobalScanMagnFarStart
                        ; Magn<GlobalScanMagnEnd && ContinuesFlag
                        ; Magn+=MagnGap)
                {
                        xValue = (int)((float)Magn * cosValue + 0.5
                                + (float)xImageCenter);
                        yValue = (int)((float)Magn * sinValue + 0.5
                                + (float)yImageCenter);

                        if(xValue>=0 && xValue<ImageWidth && yValue>=0
                                && yValue<ImageHeight)
                        {
                                *GlobalScanPointHere++ = xValue;
                                *GlobalScanPointHere++ = yValue;
                        }
                        else
                                ContinuesFlag = false;
                }
        }
}
//---------------------------------------------------------------------------

float  TImageData::ComputeCenterAngle(float AngleStartPoint
        , float AngleEndPoint)
{
        float tmpAngle;

        if(AngleEndPoint < AngleStartPoint)
        {
                if(AngleStartPoint < 0.0)
                        AngleStartPoint += (2.0 * M_PI);
                if(AngleEndPoint < 0.0)
                        AngleEndPoint += (2.0 * M_PI);
        }
        tmpAngle = (AngleEndPoint - AngleStartPoint) / 2.0 + AngleStartPoint;

        //else
        //{
        //        tmpAngle = (AngleEndPoint + AngleStartPoint) / 2.0;
        //}
       
        if(tmpAngle > M_PI)
                tmpAngle -= (2.0 * M_PI);

        return tmpAngle;
}
//---------------------------------------------------------------------------

float  TImageData::SubtractAngle(float aAngle, float bAngle)
{
        float tmpValue;

        if(aAngle < 0.0)
                aAngle += (2.0 * M_PI);
        if(bAngle < 0.0)
                bAngle += (2.0 * M_PI);

        tmpValue = aAngle - bAngle;

        if(tmpValue > M_PI)
                tmpValue -= (M_PI * 2.0);
        if(tmpValue < (M_PI * (-1.0)))
                tmpValue += (M_PI * 2.0);

        return tmpValue;
}
*/
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
