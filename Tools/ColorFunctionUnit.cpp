//---------------------------------------------------------------------------
//#include <vcl.h>
#include <math.h>

#pragma hdrstop

//#include "../stdafx.h"
#include "ColorFunctionUnit.h"

//---------------------------------------------------------------------------
// RGB to YUV functions
//      Y = 0.299R + 0.587G + 0.114B
//      U =-0.147R - 0.289G + 0.436B
//	  = 0.492(B - Y)
//      V = 0.615R - 0.515G - 0.100B
//	  = 0.877(R - Y)
// YUV to RGB functions
//      R = Y + 1.140V
//      G = Y - 0.394U - 0.581V
//      B = Y + 2.032U

// RGB to YIQ functions
//      Y = 0.299R + 0.587G + 0.114B
//      I = 0.736(R - Y) - 0.268(B - Y)
//	  = 0.596R - 0.275G - 0.321B
//      Q = 0.478(R - Y) + 0.413(B - Y)
//	  = 0.212R - 0.523G + 0.311B
// YIQ to RGB functions
//      R = Y + 0.956I + 0.620Q
//      G = Y - 0.272I - 0.647Q
//      B = Y - 1.108I + 1.705Q
//made by Silent Knox, 01/04/2006
//---------------------------------------------------------------------------
TColorTransform *ColorTransform = new TColorTransform();
//---------------------------------------------------------------------------

 TColorTransform::TColorTransform(void)
{
        UofRGBtoYUV_Max = 111.18;
        VofRGBtoYUV_Max = 156.825;
        IofRGBtoYIQ_Max = 151.98;
        QofRGBtoYIQ_Max = 133.365;
        UofRGBtoYUV_Parameter = 255.0 / (2.0 * UofRGBtoYUV_Max);
        VofRGBtoYUV_Parameter = 255.0 / (2.0 * VofRGBtoYUV_Max);
        IofRGBtoYIQ_Parameter = 255.0 / (2.0 * IofRGBtoYIQ_Max);
        QofRGBtoYIQ_Parameter = 255.0 / (2.0 * QofRGBtoYIQ_Max);

        maxHSV = 0.0;
        minHSV = 0.0;

        RtmpValue = 0.0;
        GtmpValue = 0.0;
        BtmpValue = 0.0;
        HtmpValue = 0.0;
        StmpValue = 0.0;
        VtmpValue = 0.0;
}
//---------------------------------------------------------------------------

 TColorTransform::~TColorTransform(void)
{}
//---------------------------------------------------------------------------

float  TColorTransform::YofRGBtoYUV(float rValue, float gValue
        , float bValue)
{
        // Y = 0.299R + 0.587G + 0.114B
        // 0<=Y<=1, 0<=R<=1, 0<=G<=1, 0<=B<=1
        return (0.299 * rValue + 0.587 * gValue + 0.114 * bValue);
}
//---------------------------------------------------------------------------

float  TColorTransform::UofRGBtoYUV(float rValue, float gValue
        , float bValue)
{
        // U = -0.147R - 0.289G + 0.436B
        // 0<=U<=1, 0<=R<=1, 0<=G<=1, 0<=B<=1
        return (-0.147 * rValue - 0.289 * gValue  + 0.436 * bValue);
}
//---------------------------------------------------------------------------

float  TColorTransform::VofRGBtoYUV(float rValue, float gValue
        , float bValue)
{
        // V = 0.615R - 0.515G - 0.100B
        // 0<=V<=1, 0<=R<=1, 0<=G<=1, 0<=B<=1
        return (0.615 * rValue - 0.515 * gValue + 0.100 * bValue);
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::YofRGBtoYUV(unsigned char rValue
        , unsigned char gValue, unsigned char bValue)
{
        // Y = 0.299R + 0.587G + 0.114B
        // 0<=Y<=255, 0<=R<=255, 0<=G<=255, 0<=B<=255
        float yValue;

        yValue = YofRGBtoYUV((float)rValue, (float)gValue, (float)bValue);
//        yValue += 0.5;
        if(yValue > 255.0)
                return 255;
        if(yValue < 0.0)
                return 0.0;

        return (unsigned char)yValue;
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::UofRGBtoYUV(unsigned char rValue
        , unsigned char gValue, unsigned char bValue)
{
        // U = -0.147R - 0.289G + 0.436B
        // 0<=U<=255, 0<=R<=255, 0<=G<=255, 0<=B<=255
        float uValue;

        uValue = UofRGBtoYUV((float)rValue, (float)gValue, (float)bValue);
        uValue = (uValue + UofRGBtoYUV_Max) * UofRGBtoYUV_Parameter;
//        uValue += 0.5;
        if(uValue > 255.0)
                return 255;
        if(uValue < 0.0)
                return 0.0;

        return (unsigned char)uValue;
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::VofRGBtoYUV(unsigned char rValue
        , unsigned char gValue, unsigned char bValue)
{
        // V = 0.615R - 0.515G - 0.100B
        // 0<=Q<=255, 0<=R<=255, 0<=G<=255, 0<=B<=255
        float vValue;

        vValue = VofRGBtoYUV((float)rValue, (float)gValue, (float)bValue);
        vValue = (vValue + VofRGBtoYUV_Max) * VofRGBtoYUV_Parameter;
//        vValue += 0.5;
        if(vValue > 255.0)
                return 255;
        if(vValue < 0.0)
                return 0;

        return (unsigned char)vValue;
}
//---------------------------------------------------------------------------

float  TColorTransform::RofYUVtoRGB(float yValue, float uValue
        , float vValue)
{
        // R = Y + 1.140V
        // 0<=R<=1, 0<=Y<=1, 0<=U<=1, 0<=V<=1
        return (yValue + 1.140 * vValue);
}
//---------------------------------------------------------------------------

float  TColorTransform::GofYUVtoRGB(float yValue, float uValue
        , float vValue)
{
        // G = Y - 0.394U - 0.581V
        // 0<=R<=1, 0<=Y<=1, 0<=U<=1, 0<=V<=1
        return (yValue - 0.394 * uValue - 0.581 * vValue);
}
//---------------------------------------------------------------------------

float  TColorTransform::BofYUVtoRGB(float yValue, float uValue
        , float vValue)
{
        // B = Y + 2.032U
        // 0<=R<=1, 0<=Y<=1, 0<=U<=1, 0<=V<=1
        return (yValue + 2.032 * uValue);
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::RofYUVtoRGB(unsigned char yValue
        , unsigned char uValue, unsigned char vValue)
{
        // R = Y + 1.140V
        // 0<=R<=255, 0<=Y<=255, 0<=I<=255, 0<=Q<=255
        float rValue;
        float UtmpValue, VtmpValue;

        UtmpValue = (float)uValue / UofRGBtoYUV_Parameter - UofRGBtoYUV_Max;
        VtmpValue = (float)vValue / VofRGBtoYUV_Parameter - VofRGBtoYUV_Max;
        rValue = RofYUVtoRGB((float)yValue, UtmpValue, VtmpValue);
//        rValue += 0.5;
        if(rValue > 255.0)
                return 255;
        if(rValue < 0.0)
                return 0;

        return (unsigned char)rValue;
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::GofYUVtoRGB(unsigned char yValue
        , unsigned char uValue, unsigned char vValue)
{
        // G = Y - 0.394U - 0.581V
        // 0<=R<=255, 0<=Y<=255, 0<=I<=255, 0<=Q<=255
        float gValue;
        float UtmpValue, VtmpValue;

        UtmpValue = (float)uValue / UofRGBtoYUV_Parameter - UofRGBtoYUV_Max;
        VtmpValue = (float)vValue / VofRGBtoYUV_Parameter - VofRGBtoYUV_Max;
        gValue = GofYUVtoRGB((float)yValue, UtmpValue, VtmpValue);
//        gValue += 0.5;
        if(gValue > 255.0)
                return 255;
        if(gValue < 0.0)
                return 0;

        return (unsigned char)gValue;
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::BofYUVtoRGB(unsigned char yValue
        , unsigned char uValue, unsigned char vValue)
{
        // B = Y - 2.032U
        // 0<=R<=255, 0<=Y<=255, 0<=I<=255, 0<=Q<=255
        float bValue;
        float UtmpValue, VtmpValue;

        UtmpValue = (float)uValue / UofRGBtoYUV_Parameter - UofRGBtoYUV_Max;
        VtmpValue = (float)vValue / VofRGBtoYUV_Parameter - VofRGBtoYUV_Max;
        bValue = BofYUVtoRGB((float)yValue, UtmpValue, VtmpValue);
//        bValue += 0.5;
        if(bValue > 255.0)
                return 255;
        if(bValue < 0.0)
                return 0;

        return (unsigned char)bValue;
}
//---------------------------------------------------------------------------

float  TColorTransform::YofRGBtoYIQ(float rValue, float gValue
        , float bValue)
{
        // Y = 0.299R + 0.587G + 0.114B
        // 0<=Y<=1, 0<=R<=1, 0<=G<=1, 0<=B<=1
        return (0.299 * rValue + 0.587 * gValue + 0.114 * bValue);
}
//---------------------------------------------------------------------------

float  TColorTransform::IofRGBtoYIQ(float rValue, float gValue
        , float bValue)
{
        // I = 0.596R - 0.275G - 0.321B
        // 0<=I<=1, 0<=R<=1, 0<=G<=1, 0<=B<=1
        return (0.596 * rValue - 0.275 * gValue - 0.321 * bValue);
}
//---------------------------------------------------------------------------

float  TColorTransform::QofRGBtoYIQ(float rValue, float gValue
        , float bValue)
{
        // Q = 0.212R - 0.523G + 0.311B
        // 0<=Q<=1, 0<=R<=1, 0<=G<=1, 0<=B<=1
        return (0.212 * rValue - 0.523 * gValue + 0.311 * bValue);
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::YofRGBtoYIQ(unsigned char rValue
        , unsigned char gValue, unsigned char bValue)
{
        // Y = 0.299R + 0.587G + 0.114B
        // 0<=Y<=255, 0<=R<=255, 0<=G<=255, 0<=B<=255
        float yValue;

        yValue = YofRGBtoYIQ((float)rValue, (float)gValue, (float)bValue);
//        yValue += 0.5;
        if(yValue > 255.0)
                return 255;
        if(yValue < 0.0)
                return 0.0;

        return (unsigned char)yValue;
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::IofRGBtoYIQ(unsigned char rValue
        , unsigned char gValue, unsigned char bValue)
{
        // I = 0.596R - 0.275G - 0.321B
        // 0<=I<=255, 0<=R<=255, 0<=G<=255, 0<=B<=255
        float iValue;

        iValue = IofRGBtoYIQ((float)rValue, (float)gValue, (float)bValue);
        iValue = (iValue + IofRGBtoYIQ_Max) * IofRGBtoYIQ_Parameter;
//        iValue += 0.5;
        if(iValue > 255.0)
                return 255;
        if(iValue < 0.0)
                return 0.0;

        return (unsigned char)iValue;
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::QofRGBtoYIQ(unsigned char rValue
        , unsigned char gValue, unsigned char bValue)
{
        // Q = 0.212R - 0.523G + 0.311B
        // 0<=Q<=255, 0<=R<=255, 0<=G<=255, 0<=B<=255
        float qValue;

        qValue = QofRGBtoYIQ((float)rValue, (float)gValue, (float)bValue);
        qValue = (qValue + QofRGBtoYIQ_Max) * QofRGBtoYIQ_Parameter;
//        qValue += 0.5;
        if(qValue > 255.0)
                return 255;
        if(qValue < 0.0)
                return 0;

        return (unsigned char)qValue;
}
//---------------------------------------------------------------------------

float  TColorTransform::RofYIQtoRGB(float yValue, float iValue
        , float qValue)
{
        // R = Y + 0.956I + 0.620Q
        // 0<=R<=1, 0<=Y<=1, 0<=I<=1, 0<=Q<=1
        return (yValue + 0.956 * iValue + 0.620 * qValue);
}
//---------------------------------------------------------------------------

float  TColorTransform::GofYIQtoRGB(float yValue, float iValue
        , float qValue)
{
        // G = Y - 0.272I - 0.647Q
        // 0<=G<=1, 0<=Y<=1, 0<=I<=1, 0<=Q<=1
        return (yValue - 0.272 * iValue - 0.647 * qValue);
}
//---------------------------------------------------------------------------

float  TColorTransform::BofYIQtoRGB(float yValue, float iValue
        , float qValue)
{
        // B = Y - 1.108I + 1.705Q
        // 0<=B<=1, 0<=Y<=1, 0<=I<=1, 0<=Q<=1
        return (yValue - 1.108 * iValue + 1.705 * qValue);
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::RofYIQtoRGB(unsigned char yValue
        , unsigned char iValue, unsigned char qValue)
{
        // R = Y + 0.956I + 0.620Q
        // 0<=R<=255, 0<=Y<=255, 0<=I<=255, 0<=Q<=255

        float rValue;
        float ItmpValue, QtmpValue;

        ItmpValue = (float)iValue / IofRGBtoYIQ_Parameter - IofRGBtoYIQ_Max;
        QtmpValue = (float)qValue / QofRGBtoYIQ_Parameter - IofRGBtoYIQ_Max;
        rValue = RofYIQtoRGB((float)yValue, ItmpValue, QtmpValue);
//        rValue += 0.5;
        if(rValue > 255.0)
                return 255;
        if(rValue < 0.0)
                return 0;

        return (unsigned char)rValue;
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::GofYIQtoRGB(unsigned char yValue
        , unsigned char iValue, unsigned char qValue)
{
        // G = Y - 0.272I - 0.647Q
        // 0<=G<=255, 0<=Y<=255, 0<=I<=255, 0<=Q<=255
        float gValue;
        float ItmpValue, QtmpValue;

        ItmpValue = (float)iValue / IofRGBtoYIQ_Parameter - IofRGBtoYIQ_Max;
        QtmpValue = (float)qValue / QofRGBtoYIQ_Parameter - IofRGBtoYIQ_Max;
        gValue = GofYIQtoRGB((float)yValue, ItmpValue, QtmpValue);
//        qValue += 0.5;
        if(gValue > 255.0)
                return 255;
        if(gValue < 0.0)
                return 0;

        return (unsigned char)gValue;
}
//---------------------------------------------------------------------------

unsigned char  TColorTransform::BofYIQtoRGB(unsigned char yValue
        , unsigned char iValue, unsigned char qValue)
{
        // B = Y - 1.108I + 1.705Q
        // 0<=B<=255, 0<=Y<=255, 0<=I<=255, 0<=Q<=255
        float bValue;
        float ItmpValue, QtmpValue;

        ItmpValue = (float)iValue / IofRGBtoYIQ_Parameter - IofRGBtoYIQ_Max;
        QtmpValue = (float)qValue / QofRGBtoYIQ_Parameter - IofRGBtoYIQ_Max;
        bValue = BofYIQtoRGB((float)yValue, ItmpValue, QtmpValue);
//        bValue += 0.5;
        if(bValue > 255.0)
                return 255;
        if(bValue < 0.0)
                return 0;

        return (unsigned char)bValue;
}
//---------------------------------------------------------------------------

float  TColorTransform::HofRGBtoHSV(float rValue, float gValue
        , float bValue)
{
        // 0.0<=H<360.0, 0.0<=R<=1.0, 0.0<=G<=1.0, 0.0<=B<=1.0
        float HueValue;
        float tmpValue;

        ExecuteMaxMin(rValue, gValue, bValue);
        tmpValue = maxHSV - minHSV;

        if(tmpValue == 0.0)     // maxHSV == minHSV
                return 0.0;

        if(rValue == maxHSV)
        {
                HueValue = 60.0 * (gValue - bValue) / tmpValue;
                if(gValue < bValue)
                        HueValue += 360.0;
        }
        else if(gValue == maxHSV)
                HueValue = 60.0 * (bValue - rValue) / tmpValue + 120.0;
        else    // bValue == maxValue
                HueValue = 60.0 * (rValue - gValue) / tmpValue + 240.0;

        if(HueValue >= 360.0)
                HueValue -= 360.0;
        if(HueValue < 0.0)
                HueValue += 360.0;

        return HueValue;
}
//---------------------------------------------------------------------------

float  TColorTransform::SofRGBtoHSV(float rValue, float gValue
        , float bValue)
{
        // 0.0<=S<=1.0, 0.0<=R<=1.0, 0.0<=G<=1.0, 0.0<=B<=1.0
        ExecuteMaxMin(rValue, gValue, bValue);
        if(maxHSV == minHSV)
                return 0.0;
        else if(maxHSV == 0.0)
                return 0.0;

        return ((maxHSV - minHSV) / maxHSV);
}
//---------------------------------------------------------------------------

float  TColorTransform::VofRGBtoHSV(float rValue, float gValue
        , float bValue)
{
        // 0<=V<=1, 0<=R<=1, 0<=G<=1, 0<=B<=1
        ExecuteMaxMin(rValue, gValue, bValue);

        return maxHSV;
}
//---------------------------------------------------------------------------

void  TColorTransform::ExecuteMaxMin(float &rValue, float &gValue
        , float &bValue)
{
        if(rValue > gValue)                     // R > G
                if(rValue > bValue)             // R > G && R > B
                {
                        maxHSV = rValue;
                        if(gValue > bValue)     // R > G > B
                                minHSV = bValue;
                        else                    // R > B > G
                                minHSV = gValue;
                }
                else                            // B > R > G
                {
                        maxHSV = bValue;
                        minHSV = gValue;
                }
        else                                    // G > R
                if(gValue > bValue)             // G > R && G > B
                {
                        maxHSV = gValue;
                        if(rValue > bValue)     // G > R > B
                                minHSV = bValue;
                        else                    // G > B > R
                                minHSV = rValue;
                }
                else                            // B > G > R
                {
                        maxHSV = bValue;
                        minHSV = rValue;
                }
}
//---------------------------------------------------------------------------

float  TColorTransform::RofHSVtoRGB(float hValue, float sValue
        , float vValue)
{
        if(hValue==HtmpValue && sValue==StmpValue && vValue==VtmpValue)
                return RtmpValue;
        HSVtoRGB(hValue, sValue, vValue);

        return RtmpValue;
}
//---------------------------------------------------------------------------

float  TColorTransform::GofHSVtoRGB(float hValue, float sValue
        , float vValue)
{
        if(hValue==HtmpValue && sValue==StmpValue && vValue==VtmpValue)
                return GtmpValue;
        HSVtoRGB(hValue, sValue, vValue);

        return GtmpValue;
}
//---------------------------------------------------------------------------

float  TColorTransform::BofHSVtoRGB(float hValue, float sValue
        , float vValue)
{
        if(hValue==HtmpValue && sValue==StmpValue && vValue==VtmpValue)
                return BtmpValue;
        HSVtoRGB(hValue, sValue, vValue);

        return BtmpValue;
}
//---------------------------------------------------------------------------

void  TColorTransform::HSVtoRGB(float hValue, float sValue
        , float vValue)
{
        if(sValue == 0.0)
        {
                RtmpValue = vValue;
                GtmpValue = vValue;
                BtmpValue = vValue;
        }
        else
        {
                int HueInt;
                float Huefloat;
                float pValue, qValue, tValue;

                HueInt = ((int)hValue / 60) % 6;
                Huefloat = (hValue / 60.0) - (float)HueInt;
                pValue = vValue * (1.0 - sValue);
                qValue = vValue * (1.0 - Huefloat * sValue);
                tValue = vValue * (1.0 - (1.0 - Huefloat) * sValue);
                switch(HueInt)
                {
                        case 1:
                        {
                                RtmpValue = qValue;
                                GtmpValue = vValue;
                                BtmpValue = pValue;
                                break;
                        }
                        case 2:
                        {
                                RtmpValue = pValue;
                                GtmpValue = vValue;
                                BtmpValue = tValue;
                                break;
                        }
                        case 3:
                        {
                                RtmpValue = pValue;
                                GtmpValue = qValue;
                                BtmpValue = vValue;
                                break;
                        }
                        case 4:
                        {
                                RtmpValue = tValue;
                                GtmpValue = pValue;
                                BtmpValue = vValue;
                                break;
                        }
                        case 5:
                        {
                                RtmpValue = vValue;
                                GtmpValue = pValue;
                                BtmpValue = qValue;
                                break;
                        }
                        default:        // HueInt == 0
                        {
                                RtmpValue = vValue;
                                GtmpValue = tValue;
                                BtmpValue = pValue;
                                break;
                        }
                }
        }
        HtmpValue = hValue;
        StmpValue = sValue;
        VtmpValue = vValue;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

