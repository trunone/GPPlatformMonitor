//---------------------------------------------------------------------------

#ifndef ColorFunctionUnitH
#define ColorFunctionUnitH
//---------------------------------------------------------------------------
class TColorTransform
{

private:        //User declarations
        float UofRGBtoYUV_Max, VofRGBtoYUV_Max;
        float IofRGBtoYIQ_Max, QofRGBtoYIQ_Max;
        float UofRGBtoYUV_Parameter, VofRGBtoYUV_Parameter;
        float IofRGBtoYIQ_Parameter, QofRGBtoYIQ_Parameter;

        // HSV to RGB Conversion
        float maxHSV, minHSV;
        void  ExecuteMaxMin(float &rValue, float &gValue
                , float &bValue);

        // RGB to HSV Conversion
        float RtmpValue, GtmpValue, BtmpValue;
        float HtmpValue, StmpValue, VtmpValue;
        void  HSVtoRGB(float hValue, float sValue, float vValue);

public:         //User declarations
         TColorTransform(void);
         ~TColorTransform(void);

        // RGB to YUV Conversion
        float  YofRGBtoYUV(float rValue, float gValue
                , float bValue);
        float  UofRGBtoYUV(float rValue, float gValue
                , float bValue);
        float  VofRGBtoYUV(float rValue, float gValue
                , float bValue);
        unsigned char  YofRGBtoYUV(unsigned char rValue
                , unsigned char gValue
                , unsigned char bValue);
        unsigned char  UofRGBtoYUV(unsigned char rValue
                , unsigned char gValue, unsigned char bValue);
        unsigned char  VofRGBtoYUV(unsigned char rValue
                , unsigned char gValue, unsigned char bValue);

        // YUV to RGB Conversion
        float  RofYUVtoRGB(float yValue, float uValue
                , float vValue);
        float  GofYUVtoRGB(float yValue, float uValue
                , float vValue);
        float  BofYUVtoRGB(float yValue, float uValue
                , float vValue);
        unsigned char  RofYUVtoRGB(unsigned char yValue
                , unsigned char uValue, unsigned char vValue);
        unsigned char  GofYUVtoRGB(unsigned char yValue
                , unsigned char uValue, unsigned char vValue);
        unsigned char  BofYUVtoRGB(unsigned char yValue
                , unsigned char uValue, unsigned char vValue);

        // RGB to YIQ Conversion
        float  YofRGBtoYIQ(float rValue, float gValue
                , float bValue);
        float  IofRGBtoYIQ(float rValue, float gValue
                , float bValue);
        float  QofRGBtoYIQ(float rValue, float gValue
                , float bValue);
        unsigned char  YofRGBtoYIQ(unsigned char rValue
                , unsigned char gValue, unsigned char bValue);
        unsigned char  IofRGBtoYIQ(unsigned char rValue
                , unsigned char gValue, unsigned char bValue);
        unsigned char  QofRGBtoYIQ(unsigned char rValue
                , unsigned char gValue, unsigned char bValue);

        // YIQ to RGB Conversion
        float  RofYIQtoRGB(float yValue, float iValue
                , float qValue);
        float  GofYIQtoRGB(float yValue, float iValue
                , float qValue);
        float  BofYIQtoRGB(float yValue, float iValue
                , float qValue);
        unsigned char  RofYIQtoRGB(unsigned char yValue
                , unsigned char iValue, unsigned char qValue);
        unsigned char  GofYIQtoRGB(unsigned char yValue
                , unsigned char iValue, unsigned char qValue);
        unsigned char  BofYIQtoRGB(unsigned char yValue
                , unsigned char iValue, unsigned char qValue);

        // RGB to HSV Conversion
        float  HofRGBtoHSV(float rValue, float gValue
                , float bValue);
        float  SofRGBtoHSV(float rValue, float gValue
                , float bValue);
        float  VofRGBtoHSV(float rValue, float gValue
                , float bValue);

        // HSV to RGB Conversion
        float  RofHSVtoRGB(float hValue, float sValue
                , float vValue);
        float  GofHSVtoRGB(float hValue, float sValue
                , float vValue);
        float  BofHSVtoRGB(float hValue, float sValue
                , float vValue);
};
//---------------------------------------------------------------------------
extern TColorTransform *ColorTransform;
//---------------------------------------------------------------------------
#endif
