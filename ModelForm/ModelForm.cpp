#include "ModelForm.h"

#include "../ImageData/TImageData.h"

using namespace PureModelForm;

enum{OrangeLabel = 0x01, YellowLabel = 0x02, BlueLabel = 0x04
	, GreenLabel = 0x08, BlackLabel = 0x10, RedLabel = 0x20
	, OthersLabel = 0x80};
//Generate the [image] based on the specific [pColorRange]
void ModelForm::HSV_PrintAngle(unsigned char *Image, ColorRange *pColorRange)
{
	int Line;
	int rValue, gValue, bValue;
	float Angle, Magn, Brightness;
	float tmpAngle;

				

	tmpAngle = ImageData->ComputeCenterAngle(pColorRange->HueMax, pColorRange->HueMin);
	tmpAngle *= (float)2.0 * (float)Math::PI *ImageData->RadianToAngular;
	for(int jValue=0 ; jValue<128 ; jValue++)
	{
							
			for(int iValue=0 ; iValue<64 ; iValue++)
			{
				Line =(jValue*64+iValue)*3 ;
					if(2 * iValue + jValue < 128)
					{
							/**Line++ = 0xff;
							*Line++ = 0xff;
							*Line++ = 0xff;*/
							Image[Line] = 255;
							Image[Line + 1] = 255;
							Image[Line + 2] = 255;
					}
					else
					{
							Magn = (float)iValue / (float)63.0;
							Brightness = (float)jValue / (float)127.0;

							if(Magn >= pColorRange->SaturationMin
									&& Magn <= pColorRange->SaturationMax
									&& Brightness >= pColorRange->BrightnessMin
									&& Brightness <= pColorRange->BrightnessMax)
									Angle = tmpAngle;
							else
									if(tmpAngle > 180.0)
											Angle = tmpAngle - (float)180.0;
									else
											Angle = tmpAngle + (float)180.0;

							rValue = (unsigned char)(255.0
									*ColorTransform->RofHSVtoRGB(Angle, Magn, Brightness));
							gValue = (unsigned char)(255.0
									*ColorTransform->GofHSVtoRGB(Angle, Magn, Brightness));
							bValue = (unsigned char)(255.0
									*ColorTransform->BofHSVtoRGB(Angle, Magn, Brightness));
							/**Line++ = bValue;
							*Line++ = gValue;
							*Line++ = rValue;*/
							Image[Line] = bValue;
							Image[Line + 1] = gValue;
							Image[Line + 2] = rValue;
					}
			}
	}
}

//Generate the [image] based on the specific [pColorRange]
void ModelForm::HSV_PrintBackground(unsigned char *Image, ColorRange *pColorRange)
{
	int tmpValue;
	int rValue, gValue, bValue;
	float angle, magn, Brightness;
	int Line;

	tmpValue = 128 / 2 - 1;
	for(int jValue=0 ; jValue<128 ; jValue++)
	{
							
			for(int iValue=0 ; iValue<128 ; iValue++)
			{
				Line = (jValue*128 + iValue)*3;
					magn = (float) hypot((double)(jValue - tmpValue)
							, (double)(iValue - tmpValue));
					magn /= (float)(tmpValue);
					if(magn > 1.0)
					{
							Image[Line] = 255;
							Image[Line + 1] = 255;
							Image[Line + 2] = 255;
					}
					else
					{
							if((iValue - tmpValue) == 0)
							{
									if((jValue - tmpValue) < 0)
											angle = 0.25;
									else
											angle = 0.75;
							}
							else
							{
									angle = atan2((float)(jValue - tmpValue)
											, (float)(iValue - tmpValue));
									angle = angle / (float)Math::PI * (float)0.5 + (float)0.5;
									if(angle >= 1.0)
											angle = 0.0;
							}

							if(pColorRange->SaturationMax >= magn
									&& pColorRange->SaturationMin <= magn)
							{
									if(pColorRange->HueMax >= pColorRange->HueMin
											&& pColorRange->HueMax >= angle
											&& pColorRange->HueMin <= angle)
											Brightness = (float)0.9;
									else if(pColorRange->HueMax < pColorRange->HueMin
											&& (pColorRange->HueMax >= angle
											|| pColorRange->HueMin <= angle))
											Brightness = (float)0.9;
									else
											Brightness = (float)0.1;
							}
							else
									Brightness = 0.1;
							angle = angle * (float)360.0;

							rValue = (unsigned char)(255.0
									* ColorTransform->RofHSVtoRGB(angle, magn, Brightness));
							gValue = (unsigned char)(255.0
									* ColorTransform->GofHSVtoRGB(angle, magn, Brightness));
							bValue = (unsigned char)(255.0
									* ColorTransform->BofHSVtoRGB(angle, magn, Brightness));
							/**Line++ = bValue;
							*Line++ = gValue;
							*Line++ = rValue;*/
							Image[Line] = bValue;
							Image[Line + 1] = gValue;
							Image[Line + 2] = rValue;
					}
			}
	}

}

void ModelForm::HSV_MainFunction(unsigned char *pImage)
{
	unsigned char yMask, iMask, qMask;
	unsigned char yValue, iValue, qValue;
	float rValue, gValue, bValue;
	float hValue, sValue, vValue;
	unsigned char *tmpHere;

	if(mHSVColorRange != NULL)
	{
		switch(HSVColorSelectComboBox->SelectedIndex)
		{
		case 0:         //--- Blue Masks
			qMask = 255;
			iMask = 255;
			yMask = 0;
			break;
		case 1:         //--- Black Masks
			qMask = 255;
			iMask = 255;
			yMask = 255;
			break;
		case 2:         //--- Green Masks
			qMask = 255;
			iMask = 0;
			yMask = 255;
			break;
		case 3:         //--- Orange Masks
			qMask = 0;
			iMask = 255;
			yMask = 0;
			break;
		case 4:         //--- Red Masks
			qMask = 0;
			iMask = 255;
			yMask = 255;
			break;
		case 5:         //--- Yellow Masks
			qMask = 0;
			iMask = 0;
			yMask = 255;
		}

		tmpHere = pImage;
		for(int j=0 ; j<ImageData->ImageHeight ; j++)
		{
			for(int i=0 ; i<ImageData->ImageWidth ; i++)
			{
				if(hypot((double)(i - ImageData->xImageCenter)
					, (double)(j - ImageData->yImageCenter))
					< ImageData->GlobalScanMagnEnd)
				{
					qValue = *tmpHere;
					iValue = *(tmpHere + 1);
					yValue = *(tmpHere + 2);

					rValue = (float)ColorTransform->RofYUVtoRGB(yValue
						, iValue, qValue) / 255.0;
					gValue = (float)ColorTransform->GofYUVtoRGB(yValue
						, iValue, qValue) / 255.0;
					bValue = (float)ColorTransform->BofYUVtoRGB(yValue
						, iValue, qValue) / 255.0;

					vValue = ColorTransform->VofRGBtoHSV(rValue
						, gValue, bValue);
					sValue = ColorTransform->SofRGBtoHSV(rValue
						, gValue, bValue);
					hValue = ColorTransform->HofRGBtoHSV(rValue
						, gValue, bValue);

					hValue /= 360.0;
					if(HSV_hsvCheckRange(mHSVColorRange
						, hValue, sValue, vValue))
					{
						*tmpHere++ = qMask;
						*tmpHere++ = iMask;
						*tmpHere++ = yMask;
					}
					else
						tmpHere += 3;
				}
				else
					tmpHere += 3;
			}
		}
	}
}
void ModelForm::HSV_MainFunction(unsigned char *pImage, unsigned char *ColorTable)
{
	unsigned char yMask, iMask, qMask;
	unsigned char rValue, gValue, bValue;
	float hValue, sValue, vValue;
	unsigned char *tmpHere, *tmpTable;

	if(mHSVColorRange != NULL)
	{
		switch(HSVColorSelectComboBox->SelectedIndex)
		{
		case 0:         //--- Blue Masks
			qMask = 255;
			iMask = 255;
			yMask = 0;
			break;
		case 1:         //--- Black Masks
			qMask = 255;
			iMask = 255;
			yMask = 255;
			break;
		case 2:         //--- Green Masks
			qMask = 255;
			iMask = 0;
			yMask = 255;
			break;
		case 3:         //--- Orange Masks
			qMask = 0;
			iMask = 255;
			yMask = 0;
			break;
		case 4:         //--- Red Masks
			qMask = 0;
			iMask = 255;
			yMask = 255;
			break;
		case 5:         //--- Yellow Masks
			qMask = 0;
			iMask = 0;
			yMask = 255;
		}

		tmpHere = pImage;
		for(int j=0 ; j<ImageData->ImageHeight ; j++)
		{
			for(int i=0 ; i<ImageData->ImageWidth ; i++)
			{
				
					bValue = *tmpHere;
					gValue = *(tmpHere + 1);
					rValue = *(tmpHere + 2);

					tmpTable = ColorTable + 3 * (rValue
						* ImageData->ColorDeep * ImageData->ColorDeep
						+ gValue * ImageData->ColorDeep + bValue);

					hValue = (*tmpTable++) / 255.0;
					sValue = (*tmpTable++) / 255.0;
					vValue = (*tmpTable++) / 255.0;

					if(HSV_hsvCheckRange(mHSVColorRange
						, hValue, sValue, vValue))
					{
						*tmpHere++ = qMask;
						*tmpHere++ = iMask;
						*tmpHere++ = yMask;
					}
					else
						tmpHere += 3;
				
				
			}
		}
	}
}

bool ModelForm::HSV_hsvCheckRange(ColorRange *hsvRange, float &hValue
	, float &sValue, float &vValue)
{
	if(hsvRange->HueMax >= hsvRange->HueMin)
	{
		if(hsvRange->HueMax >= hValue && hsvRange->HueMin <= hValue
			&& hsvRange->SaturationMax >= sValue
			&& hsvRange->SaturationMin <= sValue
			&& hsvRange->BrightnessMax >= vValue
			&& hsvRange->BrightnessMin <= vValue)
			return true;
	}
	else
	{
		if((hsvRange->HueMax >= hValue || hsvRange->HueMin <= hValue)
			&& hsvRange->SaturationMax >= sValue
			&& hsvRange->SaturationMin <= sValue
			&& hsvRange->BrightnessMax >= vValue
			&& hsvRange->BrightnessMin <= vValue)
			return true;
	}

	return false;
}

void ModelForm::HSV_BuildingTable(unsigned char *tableArray)
{
	unsigned char *tmpHere;
	float rValue, gValue, bValue;

	tmpHere = tableArray;
	for(int yValue=0 ; yValue<ImageData->ColorDeep ; yValue++)
	{
		for(int iValue=0 ; iValue<ImageData->ColorDeep ; iValue++)
		{
			for(int qValue=0 ; qValue<ImageData->ColorDeep ; qValue++)
			{
				rValue = (float)ColorTransform->RofYUVtoRGB((unsigned char)yValue
					, (unsigned char)iValue, (unsigned char)qValue) / 255.0;
				gValue = (float)ColorTransform->GofYUVtoRGB((unsigned char)yValue
					, (unsigned char)iValue, (unsigned char)qValue) / 255.0;
				bValue = (float)ColorTransform->BofYUVtoRGB((unsigned char)yValue
					, (unsigned char)iValue, (unsigned char)qValue) / 255.0;

				*tmpHere++ = (unsigned char)
					(ColorTransform->HofRGBtoHSV(rValue
					, gValue, bValue) / 360.0 * 255.0);
				*tmpHere++ = (unsigned char)
					(ColorTransform->SofRGBtoHSV(rValue
					, gValue, bValue) * 255.0);
				*tmpHere++ = (unsigned char)
					(ColorTransform->VofRGBtoHSV(rValue
					, gValue, bValue) * 255.0);
			}
		}
	}
	BuiltTable = true;
}

void ModelForm::HSV_BuildingColorModel(unsigned char *Array)
{
	unsigned char *tmpHere;
	float hValue, sValue, vValue;
	float rValue, gValue, bValue;

	tmpHere = Array;
	for(int yValue=0 ; yValue<ImageData->ColorDeep ; yValue++)
	{
		for(int iValue=0 ; iValue<ImageData->ColorDeep ; iValue++)
		{
			for(int qValue=0 ; qValue<ImageData->ColorDeep ; qValue++)
			{
				rValue = (float)ColorTransform->RofYUVtoRGB((unsigned char)yValue
					, (unsigned char)iValue, (unsigned char)qValue) / 255.0;
				gValue = (float)ColorTransform->GofYUVtoRGB((unsigned char)yValue
					, (unsigned char)iValue, (unsigned char)qValue) / 255.0;
				bValue = (float)ColorTransform->BofYUVtoRGB((unsigned char)yValue
					, (unsigned char)iValue, (unsigned char)qValue) / 255.0;

				hValue = (ColorTransform->HofRGBtoHSV(rValue
					, gValue, bValue) / 360.0);
				sValue = ColorTransform->SofRGBtoHSV(rValue
					, gValue, bValue);
				vValue = ColorTransform->VofRGBtoHSV(rValue
					, gValue, bValue);

				if(HSV_hsvCheckRange(ImageData->hsvBlackRange
					, hValue, sValue, vValue))
					*tmpHere++ = BlackLabel;
				else if(HSV_hsvCheckRange(ImageData->hsvBlueRange
					, hValue, sValue, vValue))
					*tmpHere++ = BlueLabel;
				else if(HSV_hsvCheckRange(ImageData->hsvOrangeRange
					, hValue, sValue, vValue))
					*tmpHere++ = OrangeLabel;
				else if(HSV_hsvCheckRange(ImageData->hsvYellowRange
					, hValue, sValue, vValue))
					*tmpHere++ = YellowLabel;
				else if(HSV_hsvCheckRange(ImageData->hsvGreenRange
					, hValue, sValue, vValue))
					*tmpHere++ = GreenLabel;
				else if(HSV_hsvCheckRange(ImageData->hsvRedRange
					, hValue, sValue, vValue))
					*tmpHere++ = RedLabel;
				else
					*tmpHere++ = 0x00;
			}
		}
	}
}
//--