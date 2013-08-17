#pragma once
#include "../Segmentation.h"

#include "../stdafx.h"
#include "../ImageData/TImageData.h"
#include "../Tools/ColorFunctionUnit.h"
#include "../Tools/UtilityTool.h"
#include <math.h>

//#include ".\Info\VisionSystem\ViDefine\ViDefine.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace System::Xml;

namespace PureModelForm {

	/// <summary>
	/// ModelForm 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class ModelForm : public System::Windows::Forms::Form
	{


		
	public:
		ModelForm(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~ModelForm()
		{
			if (components)
			{
				delete components;
			}
		}
		
	protected: 
	private: System::Windows::Forms::PictureBox^  HSVDisplay_HS;
	private: System::Windows::Forms::PictureBox^  HSVDisplay_V;

	private: System::Windows::Forms::ComboBox^  HSVColorSelectComboBox;
	private: System::Windows::Forms::HScrollBar^  HSVHueMaxScrollBar;
	private: System::Windows::Forms::HScrollBar^  HSVHueMinScrollBar;
	private: System::Windows::Forms::HScrollBar^  HSVSaturationMaxScrollBar;
	private: System::Windows::Forms::HScrollBar^  HSVSaturationMinScrollBar;
	private: System::Windows::Forms::HScrollBar^  HSVBrightnessMaxScrollBar;
	private: System::Windows::Forms::HScrollBar^  HSVBrightnessMinScrollBar;












	private: System::Windows::Forms::Label^  HSVHueRange;
	private: System::Windows::Forms::Label^  HSVSaturationRange;
	private: System::Windows::Forms::Label^  HSVBrightnessRange;




	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;



	protected: 

	protected: 


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		//--- YIQ Mode
		//ColorCount *bmpSampleCount;
		//unsigned char *bmpSample;
		/*
		enum ColorLabel:int{OrangeLabel = 0x01, YellowLabel = 0x02, BlueLabel = 0x04
			, GreenLabel = 0x08, BlackLabel = 0x10, RedLabel = 0x20
			, OthersLabel = 0x80};
		*/
		String^ SampFileName;
		String^  FmdlFileName;

		//void __fastcall BMP_PreviewResult(unsigned char *pImage);
		//void __fastcall BMP_BuildingModel(unsigned char *pImage);

		//--- HSV Mode
		ColorRange *mHSVColorRange;
		unsigned char *tableBMPtoHSV;
		bool BuiltTable;

		//hui   //--------------------------------------------------------------
		//input y,i,q are all in range of 0~255
		//in the transfering step, r,g,b are all outputed in the range of 0~255
		//output h,s,v:  0.0<=H<360.0,  0.0<=S<=1.0,  0<=V<=1.0
		//for HSV use, Sto HSV Color model
		//hui   //--------------------------------------------------------------
		String ^ hsvRangeFileName;
		ColorRange *tmpColorRange;
	private: System::Windows::Forms::Button^  Save;


			 ModelForm^ mModelForm;
		

		void HSV_MainFunction(unsigned char *pImage);
		void HSV_MainFunction(unsigned char *pImage, unsigned char *ColorTable);     

		void HSV_BuildingTable(unsigned char *tableArray);
		void HSV_BuildingColorModel(unsigned char *Array);

		bool HSV_hsvCheckRange(ColorRange *hsvRange, float &hValue, float &sValue, float &vValue);
	
		


		unsigned char *hsv_dispaly_HS;
		unsigned char *hsv_dispaly_V;
		//ColorRange *mHSVColorRange;
		

		void HSV_PrintAngle(unsigned char *Image, ColorRange *pColorRange);
		void HSV_PrintBackground(unsigned char *Image, ColorRange *pColorRange);


		//about GUI
		Bitmap^ HSVbmp;
		Bitmap^ HSV_Vbmp;
	public:
		SelectRange *xyRange;
		bool GetSample;
		int GotTimes;

		void ModelMainFunction(unsigned char *pImage){

			HSV_MainFunction(pImage, tableBMPtoHSV);


		}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->HSVDisplay_HS = (gcnew System::Windows::Forms::PictureBox());
			this->HSVDisplay_V = (gcnew System::Windows::Forms::PictureBox());
			this->HSVColorSelectComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->HSVHueMaxScrollBar = (gcnew System::Windows::Forms::HScrollBar());
			this->HSVHueMinScrollBar = (gcnew System::Windows::Forms::HScrollBar());
			this->HSVSaturationMaxScrollBar = (gcnew System::Windows::Forms::HScrollBar());
			this->HSVSaturationMinScrollBar = (gcnew System::Windows::Forms::HScrollBar());
			this->HSVBrightnessMaxScrollBar = (gcnew System::Windows::Forms::HScrollBar());
			this->HSVBrightnessMinScrollBar = (gcnew System::Windows::Forms::HScrollBar());
			this->HSVHueRange = (gcnew System::Windows::Forms::Label());
			this->HSVSaturationRange = (gcnew System::Windows::Forms::Label());
			this->HSVBrightnessRange = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Save = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HSVDisplay_HS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HSVDisplay_V))->BeginInit();
			this->SuspendLayout();
			// 
			// HSVDisplay_HS
			// 
			this->HSVDisplay_HS->Location = System::Drawing::Point(12, 22);
			this->HSVDisplay_HS->Name = L"HSVDisplay_HS";
			this->HSVDisplay_HS->Size = System::Drawing::Size(128, 128);
			this->HSVDisplay_HS->TabIndex = 0;
			this->HSVDisplay_HS->TabStop = false;
			// 
			// HSVDisplay_V
			// 
			this->HSVDisplay_V->Location = System::Drawing::Point(146, 22);
			this->HSVDisplay_V->Name = L"HSVDisplay_V";
			this->HSVDisplay_V->Size = System::Drawing::Size(64, 128);
			this->HSVDisplay_V->TabIndex = 1;
			this->HSVDisplay_V->TabStop = false;
			// 
			// HSVColorSelectComboBox
			// 
			this->HSVColorSelectComboBox->FormattingEnabled = true;
			this->HSVColorSelectComboBox->Location = System::Drawing::Point(13, 185);
			this->HSVColorSelectComboBox->Name = L"HSVColorSelectComboBox";
			this->HSVColorSelectComboBox->Size = System::Drawing::Size(121, 20);
			this->HSVColorSelectComboBox->TabIndex = 3;
			this->HSVColorSelectComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ModelForm::HSVColorSelectComboBox_SelectedIndexChanged);
			// 
			// HSVHueMaxScrollBar
			// 
			this->HSVHueMaxScrollBar->LargeChange = 1;
			this->HSVHueMaxScrollBar->Location = System::Drawing::Point(13, 231);
			this->HSVHueMaxScrollBar->Maximum = 360;
			this->HSVHueMaxScrollBar->Name = L"HSVHueMaxScrollBar";
			this->HSVHueMaxScrollBar->Size = System::Drawing::Size(180, 15);
			this->HSVHueMaxScrollBar->TabIndex = 4;
			this->HSVHueMaxScrollBar->Value = 360;
			this->HSVHueMaxScrollBar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &ModelForm::HSVHueMaxScrollBar_Scroll);
			// 
			// HSVHueMinScrollBar
			// 
			this->HSVHueMinScrollBar->LargeChange = 1;
			this->HSVHueMinScrollBar->Location = System::Drawing::Point(13, 246);
			this->HSVHueMinScrollBar->Maximum = 360;
			this->HSVHueMinScrollBar->Name = L"HSVHueMinScrollBar";
			this->HSVHueMinScrollBar->Size = System::Drawing::Size(180, 15);
			this->HSVHueMinScrollBar->TabIndex = 5;
			this->HSVHueMinScrollBar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &ModelForm::HSVHueMaxScrollBar_Scroll);
			// 
			// HSVSaturationMaxScrollBar
			// 
			this->HSVSaturationMaxScrollBar->LargeChange = 1;
			this->HSVSaturationMaxScrollBar->Location = System::Drawing::Point(13, 283);
			this->HSVSaturationMaxScrollBar->Name = L"HSVSaturationMaxScrollBar";
			this->HSVSaturationMaxScrollBar->Size = System::Drawing::Size(180, 15);
			this->HSVSaturationMaxScrollBar->TabIndex = 6;
			this->HSVSaturationMaxScrollBar->Value = 100;
			this->HSVSaturationMaxScrollBar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &ModelForm::HSVHueMaxScrollBar_Scroll);
			// 
			// HSVSaturationMinScrollBar
			// 
			this->HSVSaturationMinScrollBar->LargeChange = 1;
			this->HSVSaturationMinScrollBar->Location = System::Drawing::Point(13, 298);
			this->HSVSaturationMinScrollBar->Name = L"HSVSaturationMinScrollBar";
			this->HSVSaturationMinScrollBar->Size = System::Drawing::Size(180, 15);
			this->HSVSaturationMinScrollBar->TabIndex = 7;
			this->HSVSaturationMinScrollBar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &ModelForm::HSVHueMaxScrollBar_Scroll);
			// 
			// HSVBrightnessMaxScrollBar
			// 
			this->HSVBrightnessMaxScrollBar->LargeChange = 1;
			this->HSVBrightnessMaxScrollBar->Location = System::Drawing::Point(9, 339);
			this->HSVBrightnessMaxScrollBar->Name = L"HSVBrightnessMaxScrollBar";
			this->HSVBrightnessMaxScrollBar->Size = System::Drawing::Size(180, 15);
			this->HSVBrightnessMaxScrollBar->TabIndex = 8;
			this->HSVBrightnessMaxScrollBar->Value = 100;
			this->HSVBrightnessMaxScrollBar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &ModelForm::HSVHueMaxScrollBar_Scroll);
			// 
			// HSVBrightnessMinScrollBar
			// 
			this->HSVBrightnessMinScrollBar->LargeChange = 1;
			this->HSVBrightnessMinScrollBar->Location = System::Drawing::Point(9, 354);
			this->HSVBrightnessMinScrollBar->Name = L"HSVBrightnessMinScrollBar";
			this->HSVBrightnessMinScrollBar->Size = System::Drawing::Size(180, 15);
			this->HSVBrightnessMinScrollBar->TabIndex = 9;
			this->HSVBrightnessMinScrollBar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &ModelForm::HSVHueMaxScrollBar_Scroll);
			// 
			// HSVHueRange
			// 
			this->HSVHueRange->AutoSize = true;
			this->HSVHueRange->Location = System::Drawing::Point(13, 217);
			this->HSVHueRange->Name = L"HSVHueRange";
			this->HSVHueRange->Size = System::Drawing::Size(60, 12);
			this->HSVHueRange->TabIndex = 10;
			this->HSVHueRange->Text = L"Hue Range:";
			// 
			// HSVSaturationRange
			// 
			this->HSVSaturationRange->AutoSize = true;
			this->HSVSaturationRange->Location = System::Drawing::Point(13, 271);
			this->HSVSaturationRange->Name = L"HSVSaturationRange";
			this->HSVSaturationRange->Size = System::Drawing::Size(88, 12);
			this->HSVSaturationRange->TabIndex = 11;
			this->HSVSaturationRange->Text = L"Saturation Range:";
			// 
			// HSVBrightnessRange
			// 
			this->HSVBrightnessRange->AutoSize = true;
			this->HSVBrightnessRange->Location = System::Drawing::Point(12, 324);
			this->HSVBrightnessRange->Name = L"HSVBrightnessRange";
			this->HSVBrightnessRange->Size = System::Drawing::Size(90, 12);
			this->HSVBrightnessRange->TabIndex = 12;
			this->HSVBrightnessRange->Text = L"Brightness Range:";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 167);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Color Select:";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &ModelForm::timer1_Tick);
			// 
			// Save
			// 
			this->Save->Location = System::Drawing::Point(13, 386);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(75, 23);
			this->Save->TabIndex = 18;
			this->Save->Text = L"Save";
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Click += gcnew System::EventHandler(this, &ModelForm::Save_Click);
			// 
			// ModelForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(224, 436);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->HSVBrightnessRange);
			this->Controls->Add(this->HSVSaturationRange);
			this->Controls->Add(this->HSVHueRange);
			this->Controls->Add(this->HSVBrightnessMinScrollBar);
			this->Controls->Add(this->HSVBrightnessMaxScrollBar);
			this->Controls->Add(this->HSVSaturationMinScrollBar);
			this->Controls->Add(this->HSVSaturationMaxScrollBar);
			this->Controls->Add(this->HSVHueMinScrollBar);
			this->Controls->Add(this->HSVHueMaxScrollBar);
			this->Controls->Add(this->HSVColorSelectComboBox);
			this->Controls->Add(this->HSVDisplay_V);
			this->Controls->Add(this->HSVDisplay_HS);
			this->Name = L"ModelForm";
			this->Text = L"ModelForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ModelForm::ModelForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ModelForm::ModelForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HSVDisplay_HS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HSVDisplay_V))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void GUI_HSV_Display_HS(unsigned char *Image, ColorRange *pColorRange)
			 {
				    HSV_PrintBackground(Image,pColorRange);

					IntPtr pt1(Image);
					HSVbmp = gcnew Bitmap(128,128,128*3,System::Drawing::Imaging::PixelFormat::Format24bppRgb,pt1);
					this->HSVDisplay_HS->Image = HSVbmp;

			 }
private: System::Void GUI_HSV_Display_V(unsigned char *Image, ColorRange *pColorRange)
			 {
				    HSV_PrintAngle(Image,pColorRange);
					IntPtr pt2(Image);
					HSV_Vbmp = gcnew Bitmap(64,128,64*3,System::Drawing::Imaging::PixelFormat::Format24bppRgb,pt2);
					this->HSVDisplay_V->Image = HSV_Vbmp;
			 }
private: System::Void ModelForm_Load(System::Object^  sender, System::EventArgs^  e) {
				
				//--- HSV Mode
				mHSVColorRange =  NULL;
				tableBMPtoHSV = new unsigned char[3 * ImageData->ColorDeep	
					* ImageData->ColorDeep * ImageData->ColorDeep];
				BuiltTable = false;
				HSV_BuildingTable(tableBMPtoHSV);

				HSVColorSelectComboBox->Items->Add("Blue Range");
				HSVColorSelectComboBox->Items->Add("Black Range");
				HSVColorSelectComboBox->Items->Add("Green Range");
				HSVColorSelectComboBox->Items->Add("Orange Range");
				HSVColorSelectComboBox->Items->Add("Red Range");        
				HSVColorSelectComboBox->Items->Add("Yellow Range");
				

				hsv_dispaly_HS = new unsigned char [128*128*3];
				hsv_dispaly_V = new unsigned char[128*64*3];
				//---
				/*
				HSVDisplayHS->Picture->Bitmap->PixelFormat = pf24bit;
				HSVDisplayHS->Picture->Bitmap->Width = 128;
				HSVDisplayHS->Picture->Bitmap->Height = 128;
				*/
				//---
				HSVColorSelectComboBox->SelectedIndex = 0;
				//EventArgs^ e2;
				//HSVColorSelectComboBox_SelectedIndexChanged(this,e2);
		}
private: System::Void HSVHueMaxScrollBar_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
			if(mHSVColorRange){
				mHSVColorRange->HueMax = (float) this->HSVHueMaxScrollBar->Value	/ (float)360.0;
				mHSVColorRange->HueMin = (float) this->HSVHueMinScrollBar->Value / (float) 360.0;
				mHSVColorRange->SaturationMax =(float)HSVSaturationMaxScrollBar->Value / (float)100.0;
				mHSVColorRange->SaturationMin =(float)HSVSaturationMinScrollBar->Value / (float)100.0;
				mHSVColorRange->BrightnessMax =(float)HSVBrightnessMaxScrollBar->Value / (float)100.0;
				mHSVColorRange->BrightnessMin =(float)HSVBrightnessMinScrollBar->Value / (float)100.0;

				HSVHueRange->Text = String::Format("Hue Range: ({0:0.00} ~ {1:0.00})",  mHSVColorRange->HueMin,mHSVColorRange->HueMax);
				HSVSaturationRange->Text = String::Format("Saturation Range: ({0:0.00} ~ {1:0.00})",  mHSVColorRange->SaturationMin,mHSVColorRange->SaturationMax);
				HSVBrightnessRange->Text = String::Format("Brightness Range: ({0:0.00} ~ {1:0.00})",  mHSVColorRange->BrightnessMin,mHSVColorRange->BrightnessMax);

				GUI_HSV_Display_HS(hsv_dispaly_HS,mHSVColorRange);
				GUI_HSV_Display_V(hsv_dispaly_V,mHSVColorRange);
				

			}
		 }
private: System::Void HSVColorSelectComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 switch(HSVColorSelectComboBox->SelectedIndex)
			 {
			 case 0:
				 mHSVColorRange = ImageData->hsvBlueRange;
				 break;
			 case 1:
				 mHSVColorRange = ImageData->hsvBlackRange;
				 break;
			 case 2:
				 mHSVColorRange = ImageData->hsvGreenRange;
				 break;
			 case 3:
				 mHSVColorRange = ImageData->hsvOrangeRange;
				 break;
			 case 4:
				 mHSVColorRange = ImageData->hsvRedRange;
				 break;
			 case 5:
				 mHSVColorRange = ImageData->hsvYellowRange;
			 }

			 HSVHueMaxScrollBar->Value = (int)(mHSVColorRange->HueMax
				 * (float)HSVHueMaxScrollBar->Maximum);
			 HSVHueMinScrollBar->Value = (int)(mHSVColorRange->HueMin
				 * (float)HSVHueMinScrollBar->Maximum);
			 HSVSaturationMaxScrollBar->Value = (int)(mHSVColorRange->SaturationMax
				 * (float)HSVSaturationMaxScrollBar->Maximum);
			 HSVSaturationMinScrollBar->Value = (int)(mHSVColorRange->SaturationMin
				 * (float)HSVSaturationMinScrollBar->Maximum);
			 HSVBrightnessMaxScrollBar->Value = (int)(mHSVColorRange->BrightnessMax
				 * (float)HSVBrightnessMaxScrollBar->Maximum);
			 HSVBrightnessMinScrollBar->Value = (int)(mHSVColorRange->BrightnessMin
				 * (float)HSVBrightnessMinScrollBar->Maximum);

			 GUI_HSV_Display_HS(hsv_dispaly_HS, mHSVColorRange);
			 GUI_HSV_Display_V(hsv_dispaly_V, mHSVColorRange);
		 
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			// switch (this->HSVColorSelectComboBox->Items->)
		 }

private: System::Void ModelForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			//mModelForm->Visible=false;
			this->Hide();
			e->Cancel = true;			

			 }
private: System::Void Save_Click(System::Object^  sender, System::EventArgs^  e) {
			 XmlDocument^ doc = gcnew XmlDocument();
			 doc->Load("Robot_Config.xml");
			 XmlNode^ Manual = doc->SelectSingleNode("/Config/ColorModel"); //選擇節點

			 for(int i =0 ;i < Manual->ChildNodes->Count;i++){
				 XmlNode^ node = Manual->ChildNodes[i];
				 XmlElement^ element=(XmlElement^)node;
				 if(element->Name == "Blue"){
					 element->SetAttribute("HueMax",System::Convert::ToString(ImageData->hsvBlueRange->HueMax));
					 element->SetAttribute("HueMin",System::Convert::ToString(ImageData->hsvBlueRange->HueMin));
					 element->SetAttribute("SaturationMax",System::Convert::ToString(ImageData->hsvBlueRange->SaturationMax));
					 element->SetAttribute("SaturationMin",System::Convert::ToString(ImageData->hsvBlueRange->SaturationMin));
					 element->SetAttribute("BrightnessMax",System::Convert::ToString(ImageData->hsvBlueRange->BrightnessMax));
					 element->SetAttribute("BrightnessMin",System::Convert::ToString(ImageData->hsvBlueRange->BrightnessMin));
				 }else if(element->Name=="Green"){
					 element->SetAttribute("HueMax",System::Convert::ToString(ImageData->hsvGreenRange->HueMax));
					 element->SetAttribute("HueMin",System::Convert::ToString(ImageData->hsvGreenRange->HueMin));
					 element->SetAttribute("SaturationMax",System::Convert::ToString(ImageData->hsvGreenRange->SaturationMax));
					 element->SetAttribute("SaturationMin",System::Convert::ToString(ImageData->hsvGreenRange->SaturationMin));
					 element->SetAttribute("BrightnessMax",System::Convert::ToString(ImageData->hsvGreenRange->BrightnessMax));
					 element->SetAttribute("BrightnessMin",System::Convert::ToString(ImageData->hsvGreenRange->BrightnessMin));
				 }else if(element->Name=="Red"){
					 element->SetAttribute("HueMax",System::Convert::ToString(ImageData->hsvRedRange->HueMax));
					 element->SetAttribute("HueMin",System::Convert::ToString(ImageData->hsvRedRange->HueMin));
					 element->SetAttribute("SaturationMax",System::Convert::ToString(ImageData->hsvRedRange->SaturationMax));
					 element->SetAttribute("SaturationMin",System::Convert::ToString(ImageData->hsvRedRange->SaturationMin));
					 element->SetAttribute("BrightnessMax",System::Convert::ToString(ImageData->hsvRedRange->BrightnessMax));
					 element->SetAttribute("BrightnessMin",System::Convert::ToString(ImageData->hsvRedRange->BrightnessMin));
				 }
			 }
			 doc->Save("Robot_Config.xml");

			
		 }
};
}
