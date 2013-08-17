//---------------------------------------------------------------------------

#ifndef TImageDataH
#define TImageDataH
//---------------------------------------------------------------------------
//using namespace std;
#include <string>

#define M_PI       3.14159265358979323846


struct SelectRange
{
	int xMax;
	int xMin;
	int yMax;
	int yMin;
};

//---------------------------------------------------------------------------

struct ColorRange
{
	float HueMax;
	float HueMin;
	float SaturationMax;
	float SaturationMin;
	float BrightnessMax;
	float BrightnessMin;
};
//---------------------------------------------------------------------------

class TImageData
{
private:	// User declarations
public:		// User declarations
	//--- Global
	int ImageWidth, ImageHeight;

	unsigned char *pImage;

	int xPosition, yPosition;

    

	//--- ModelUnit
	ColorRange *hsvBlueRange, *hsvBlackRange, *hsvGreenRange, *hsvOrangeRange
		, *hsvYellowRange, *hsvRedRange;

	int ColorDeep;

	int xImageCenter, yImageCenter;
	int GlobalScanMagnEnd;

	float AngularToRadian,RadianToAngular;


	 TImageData(void);
	 ~TImageData(void);

	float ComputeCenterAngle(float AngleStartPoint, float AngleEndPoint);
	//float SubtractAngle(float aAngle, float bAngle);

};
//---------------------------------------------------------------------------
extern TImageData *ImageData;
//---------------------------------------------------------------------------
#endif
