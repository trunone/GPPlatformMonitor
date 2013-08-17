#pragma once

#include "ImageData/TImageData.h"
#include "Preview\PreviewForm.h"
#include "ModelForm\ModelForm.h"


namespace PureModelForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Xml;


	/// <summary>
	/// MainForm 的摘要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected: 
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  imageDataToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  previewToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  greenSaturationMinLB;
	private: System::Windows::Forms::Label^  greenBrightnesMaxLB;
	private: System::Windows::Forms::Label^  greenBrightnesMinLB;
	private: System::Windows::Forms::Label^  green;










	private: System::Windows::Forms::Label^  blueSaturationMaxLB;

	private: System::Windows::Forms::Label^  blueHueMinLB;






	private: System::Windows::Forms::Label^  bluseHuxMaxLB;
	private: System::Windows::Forms::Label^  greenHueMaxLB;
	private: System::Windows::Forms::Label^  greenHueMinLB;
	private: System::Windows::Forms::Label^  greenSaturationMaxLB;



	private: System::Windows::Forms::Label^  blueBrightnesMinLB;





	private: System::Windows::Forms::Label^  blueBrightnesMaxLB;


	private: System::Windows::Forms::Label^  blueSaturationMinNB;
	private: System::Windows::Forms::Label^  blue;
	private: System::Windows::Forms::Label^  Red_x;
	private: System::Windows::Forms::Label^  Red_y;






	private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		bool CallbackBuffer;
		PreviewForm^ mPreviewForm;
	private: System::Windows::Forms::Timer^  maintimer;
	private: System::Windows::Forms::Label^  redBrightnesMinLB;
	private: System::Windows::Forms::Label^  redHueMaxLB;
	private: System::Windows::Forms::Label^  redBrightnesMaxLB;
	private: System::Windows::Forms::Label^  Red;
	private: System::Windows::Forms::Label^  redSaturationMinLB;
	private: System::Windows::Forms::Label^  redSaturationMaxLB;
	private: System::Windows::Forms::Label^  redHueMinLB;
	private: System::Windows::Forms::Label^  Green_y;

	private: System::Windows::Forms::Label^  Green_x;


	private: System::Windows::Forms::Label^  Blue_y;

	private: System::Windows::Forms::Label^  Blue_x;




			 ModelForm^ mModelForm;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->redBrightnesMinLB = (gcnew System::Windows::Forms::Label());
			this->redHueMaxLB = (gcnew System::Windows::Forms::Label());
			this->redBrightnesMaxLB = (gcnew System::Windows::Forms::Label());
			this->Red = (gcnew System::Windows::Forms::Label());
			this->redSaturationMinLB = (gcnew System::Windows::Forms::Label());
			this->greenHueMaxLB = (gcnew System::Windows::Forms::Label());
			this->redSaturationMaxLB = (gcnew System::Windows::Forms::Label());
			this->greenHueMinLB = (gcnew System::Windows::Forms::Label());
			this->redHueMinLB = (gcnew System::Windows::Forms::Label());
			this->greenSaturationMaxLB = (gcnew System::Windows::Forms::Label());
			this->blueBrightnesMinLB = (gcnew System::Windows::Forms::Label());
			this->blueBrightnesMaxLB = (gcnew System::Windows::Forms::Label());
			this->blueSaturationMinNB = (gcnew System::Windows::Forms::Label());
			this->blue = (gcnew System::Windows::Forms::Label());
			this->greenSaturationMinLB = (gcnew System::Windows::Forms::Label());
			this->greenBrightnesMaxLB = (gcnew System::Windows::Forms::Label());
			this->greenBrightnesMinLB = (gcnew System::Windows::Forms::Label());
			this->green = (gcnew System::Windows::Forms::Label());
			this->blueSaturationMaxLB = (gcnew System::Windows::Forms::Label());
			this->blueHueMinLB = (gcnew System::Windows::Forms::Label());
			this->bluseHuxMaxLB = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->imageDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->previewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Green_y = (gcnew System::Windows::Forms::Label());
			this->Green_x = (gcnew System::Windows::Forms::Label());
			this->Blue_y = (gcnew System::Windows::Forms::Label());
			this->Blue_x = (gcnew System::Windows::Forms::Label());
			this->Red_y = (gcnew System::Windows::Forms::Label());
			this->Red_x = (gcnew System::Windows::Forms::Label());
			this->maintimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->redBrightnesMinLB);
			this->groupBox1->Controls->Add(this->redHueMaxLB);
			this->groupBox1->Controls->Add(this->redBrightnesMaxLB);
			this->groupBox1->Controls->Add(this->Red);
			this->groupBox1->Controls->Add(this->redSaturationMinLB);
			this->groupBox1->Controls->Add(this->greenHueMaxLB);
			this->groupBox1->Controls->Add(this->redSaturationMaxLB);
			this->groupBox1->Controls->Add(this->greenHueMinLB);
			this->groupBox1->Controls->Add(this->redHueMinLB);
			this->groupBox1->Controls->Add(this->greenSaturationMaxLB);
			this->groupBox1->Controls->Add(this->blueBrightnesMinLB);
			this->groupBox1->Controls->Add(this->blueBrightnesMaxLB);
			this->groupBox1->Controls->Add(this->blueSaturationMinNB);
			this->groupBox1->Controls->Add(this->blue);
			this->groupBox1->Controls->Add(this->greenSaturationMinLB);
			this->groupBox1->Controls->Add(this->greenBrightnesMaxLB);
			this->groupBox1->Controls->Add(this->greenBrightnesMinLB);
			this->groupBox1->Controls->Add(this->green);
			this->groupBox1->Controls->Add(this->blueSaturationMaxLB);
			this->groupBox1->Controls->Add(this->blueHueMinLB);
			this->groupBox1->Controls->Add(this->bluseHuxMaxLB);
			this->groupBox1->Location = System::Drawing::Point(18, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(175, 309);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// redBrightnesMinLB
			// 
			this->redBrightnesMinLB->AutoSize = true;
			this->redBrightnesMinLB->Location = System::Drawing::Point(38, 283);
			this->redBrightnesMinLB->Name = L"redBrightnesMinLB";
			this->redBrightnesMinLB->Size = System::Drawing::Size(84, 12);
			this->redBrightnesMinLB->TabIndex = 26;
			this->redBrightnesMinLB->Text = L"redBrightnesMin";
			// 
			// redHueMaxLB
			// 
			this->redHueMaxLB->AutoSize = true;
			this->redHueMaxLB->Location = System::Drawing::Point(38, 223);
			this->redHueMaxLB->Name = L"redHueMaxLB";
			this->redHueMaxLB->Size = System::Drawing::Size(60, 12);
			this->redHueMaxLB->TabIndex = 22;
			this->redHueMaxLB->Text = L"redHueMax";
			// 
			// redBrightnesMaxLB
			// 
			this->redBrightnesMaxLB->AutoSize = true;
			this->redBrightnesMaxLB->Location = System::Drawing::Point(38, 271);
			this->redBrightnesMaxLB->Name = L"redBrightnesMaxLB";
			this->redBrightnesMaxLB->Size = System::Drawing::Size(86, 12);
			this->redBrightnesMaxLB->TabIndex = 25;
			this->redBrightnesMaxLB->Text = L"redBrightnesMax";
			// 
			// Red
			// 
			this->Red->AutoSize = true;
			this->Red->Location = System::Drawing::Point(10, 202);
			this->Red->Name = L"Red";
			this->Red->Size = System::Drawing::Size(24, 12);
			this->Red->TabIndex = 21;
			this->Red->Text = L"Red";
			// 
			// redSaturationMinLB
			// 
			this->redSaturationMinLB->AutoSize = true;
			this->redSaturationMinLB->Location = System::Drawing::Point(38, 259);
			this->redSaturationMinLB->Name = L"redSaturationMinLB";
			this->redSaturationMinLB->Size = System::Drawing::Size(86, 12);
			this->redSaturationMinLB->TabIndex = 24;
			this->redSaturationMinLB->Text = L"redSaturationMin";
			// 
			// greenHueMaxLB
			// 
			this->greenHueMaxLB->AutoSize = true;
			this->greenHueMaxLB->Location = System::Drawing::Point(38, 126);
			this->greenHueMaxLB->Name = L"greenHueMaxLB";
			this->greenHueMaxLB->Size = System::Drawing::Size(71, 12);
			this->greenHueMaxLB->TabIndex = 20;
			this->greenHueMaxLB->Text = L"greenHueMax";
			// 
			// redSaturationMaxLB
			// 
			this->redSaturationMaxLB->AutoSize = true;
			this->redSaturationMaxLB->Location = System::Drawing::Point(38, 247);
			this->redSaturationMaxLB->Name = L"redSaturationMaxLB";
			this->redSaturationMaxLB->Size = System::Drawing::Size(88, 12);
			this->redSaturationMaxLB->TabIndex = 23;
			this->redSaturationMaxLB->Text = L"redSaturationMax";
			// 
			// greenHueMinLB
			// 
			this->greenHueMinLB->AutoSize = true;
			this->greenHueMinLB->Location = System::Drawing::Point(38, 138);
			this->greenHueMinLB->Name = L"greenHueMinLB";
			this->greenHueMinLB->Size = System::Drawing::Size(69, 12);
			this->greenHueMinLB->TabIndex = 19;
			this->greenHueMinLB->Text = L"greenHueMin";
			// 
			// redHueMinLB
			// 
			this->redHueMinLB->AutoSize = true;
			this->redHueMinLB->Location = System::Drawing::Point(38, 235);
			this->redHueMinLB->Name = L"redHueMinLB";
			this->redHueMinLB->Size = System::Drawing::Size(60, 12);
			this->redHueMinLB->TabIndex = 22;
			this->redHueMinLB->Text = L"redHueMax";
			// 
			// greenSaturationMaxLB
			// 
			this->greenSaturationMaxLB->AutoSize = true;
			this->greenSaturationMaxLB->Location = System::Drawing::Point(38, 150);
			this->greenSaturationMaxLB->Name = L"greenSaturationMaxLB";
			this->greenSaturationMaxLB->Size = System::Drawing::Size(99, 12);
			this->greenSaturationMaxLB->TabIndex = 18;
			this->greenSaturationMaxLB->Text = L"greenSaturationMax";
			// 
			// blueBrightnesMinLB
			// 
			this->blueBrightnesMinLB->AutoSize = true;
			this->blueBrightnesMinLB->Location = System::Drawing::Point(38, 90);
			this->blueBrightnesMinLB->Name = L"blueBrightnesMinLB";
			this->blueBrightnesMinLB->Size = System::Drawing::Size(89, 12);
			this->blueBrightnesMinLB->TabIndex = 17;
			this->blueBrightnesMinLB->Text = L"blueBrightnesMin";
			// 
			// blueBrightnesMaxLB
			// 
			this->blueBrightnesMaxLB->AutoSize = true;
			this->blueBrightnesMaxLB->Location = System::Drawing::Point(38, 78);
			this->blueBrightnesMaxLB->Name = L"blueBrightnesMaxLB";
			this->blueBrightnesMaxLB->Size = System::Drawing::Size(91, 12);
			this->blueBrightnesMaxLB->TabIndex = 16;
			this->blueBrightnesMaxLB->Text = L"blueBrightnesMax";
			// 
			// blueSaturationMinNB
			// 
			this->blueSaturationMinNB->AutoSize = true;
			this->blueSaturationMinNB->Location = System::Drawing::Point(38, 66);
			this->blueSaturationMinNB->Name = L"blueSaturationMinNB";
			this->blueSaturationMinNB->Size = System::Drawing::Size(91, 12);
			this->blueSaturationMinNB->TabIndex = 15;
			this->blueSaturationMinNB->Text = L"blueSaturationMin";
			// 
			// blue
			// 
			this->blue->AutoSize = true;
			this->blue->Location = System::Drawing::Point(8, 13);
			this->blue->Name = L"blue";
			this->blue->Size = System::Drawing::Size(27, 12);
			this->blue->TabIndex = 14;
			this->blue->Text = L"Blue";
			// 
			// greenSaturationMinLB
			// 
			this->greenSaturationMinLB->AutoSize = true;
			this->greenSaturationMinLB->Location = System::Drawing::Point(38, 162);
			this->greenSaturationMinLB->Name = L"greenSaturationMinLB";
			this->greenSaturationMinLB->Size = System::Drawing::Size(97, 12);
			this->greenSaturationMinLB->TabIndex = 10;
			this->greenSaturationMinLB->Text = L"greenSaturationMin";
			// 
			// greenBrightnesMaxLB
			// 
			this->greenBrightnesMaxLB->AutoSize = true;
			this->greenBrightnesMaxLB->Location = System::Drawing::Point(38, 174);
			this->greenBrightnesMaxLB->Name = L"greenBrightnesMaxLB";
			this->greenBrightnesMaxLB->Size = System::Drawing::Size(97, 12);
			this->greenBrightnesMaxLB->TabIndex = 9;
			this->greenBrightnesMaxLB->Text = L"greenBrightnesMax";
			// 
			// greenBrightnesMinLB
			// 
			this->greenBrightnesMinLB->AutoSize = true;
			this->greenBrightnesMinLB->Location = System::Drawing::Point(38, 186);
			this->greenBrightnesMinLB->Name = L"greenBrightnesMinLB";
			this->greenBrightnesMinLB->Size = System::Drawing::Size(95, 12);
			this->greenBrightnesMinLB->TabIndex = 8;
			this->greenBrightnesMinLB->Text = L"greenBrightnesMin";
			// 
			// green
			// 
			this->green->AutoSize = true;
			this->green->Location = System::Drawing::Point(6, 109);
			this->green->Name = L"green";
			this->green->Size = System::Drawing::Size(33, 12);
			this->green->TabIndex = 7;
			this->green->Text = L"Green";
			// 
			// blueSaturationMaxLB
			// 
			this->blueSaturationMaxLB->AutoSize = true;
			this->blueSaturationMaxLB->Location = System::Drawing::Point(38, 54);
			this->blueSaturationMaxLB->Name = L"blueSaturationMaxLB";
			this->blueSaturationMaxLB->Size = System::Drawing::Size(93, 12);
			this->blueSaturationMaxLB->TabIndex = 3;
			this->blueSaturationMaxLB->Text = L"blueSaturationMax";
			// 
			// blueHueMinLB
			// 
			this->blueHueMinLB->AutoSize = true;
			this->blueHueMinLB->Location = System::Drawing::Point(38, 42);
			this->blueHueMinLB->Name = L"blueHueMinLB";
			this->blueHueMinLB->Size = System::Drawing::Size(63, 12);
			this->blueHueMinLB->TabIndex = 2;
			this->blueHueMinLB->Text = L"blueHueMin";
			// 
			// bluseHuxMaxLB
			// 
			this->bluseHuxMaxLB->AutoSize = true;
			this->bluseHuxMaxLB->Location = System::Drawing::Point(38, 30);
			this->bluseHuxMaxLB->Name = L"bluseHuxMaxLB";
			this->bluseHuxMaxLB->Size = System::Drawing::Size(65, 12);
			this->bluseHuxMaxLB->TabIndex = 1;
			this->bluseHuxMaxLB->Text = L"blueHueMax";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->imageDataToolStripMenuItem, 
				this->previewToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(311, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MainForm::menuStrip1_ItemClicked);
			// 
			// imageDataToolStripMenuItem
			// 
			this->imageDataToolStripMenuItem->Name = L"imageDataToolStripMenuItem";
			this->imageDataToolStripMenuItem->Size = System::Drawing::Size(89, 20);
			this->imageDataToolStripMenuItem->Text = L"ColorModel";
			this->imageDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::imageDataToolStripMenuItem_Click);
			// 
			// previewToolStripMenuItem
			// 
			this->previewToolStripMenuItem->Name = L"previewToolStripMenuItem";
			this->previewToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->previewToolStripMenuItem->Text = L"Preview";
			this->previewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::previewToolStripMenuItem_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Green_y);
			this->groupBox2->Controls->Add(this->Green_x);
			this->groupBox2->Controls->Add(this->Blue_y);
			this->groupBox2->Controls->Add(this->Blue_x);
			this->groupBox2->Controls->Add(this->Red_y);
			this->groupBox2->Controls->Add(this->Red_x);
			this->groupBox2->Location = System::Drawing::Point(208, 27);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(84, 186);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			// 
			// Green_y
			// 
			this->Green_y->AutoSize = true;
			this->Green_y->Location = System::Drawing::Point(6, 90);
			this->Green_y->Name = L"Green_y";
			this->Green_y->Size = System::Drawing::Size(45, 12);
			this->Green_y->TabIndex = 7;
			this->Green_y->Text = L"Green_y";
			// 
			// Green_x
			// 
			this->Green_x->AutoSize = true;
			this->Green_x->Location = System::Drawing::Point(6, 78);
			this->Green_x->Name = L"Green_x";
			this->Green_x->Size = System::Drawing::Size(45, 12);
			this->Green_x->TabIndex = 6;
			this->Green_x->Text = L"Green_x";
			// 
			// Blue_y
			// 
			this->Blue_y->AutoSize = true;
			this->Blue_y->Location = System::Drawing::Point(6, 66);
			this->Blue_y->Name = L"Blue_y";
			this->Blue_y->Size = System::Drawing::Size(39, 12);
			this->Blue_y->TabIndex = 5;
			this->Blue_y->Text = L"Blue_y";
			// 
			// Blue_x
			// 
			this->Blue_x->AutoSize = true;
			this->Blue_x->Location = System::Drawing::Point(6, 54);
			this->Blue_x->Name = L"Blue_x";
			this->Blue_x->Size = System::Drawing::Size(39, 12);
			this->Blue_x->TabIndex = 4;
			this->Blue_x->Text = L"Blue_x";
			// 
			// Red_y
			// 
			this->Red_y->AutoSize = true;
			this->Red_y->Location = System::Drawing::Point(6, 42);
			this->Red_y->Name = L"Red_y";
			this->Red_y->Size = System::Drawing::Size(36, 12);
			this->Red_y->TabIndex = 3;
			this->Red_y->Text = L"Red_y";
			// 
			// Red_x
			// 
			this->Red_x->AutoSize = true;
			this->Red_x->Location = System::Drawing::Point(6, 30);
			this->Red_x->Name = L"Red_x";
			this->Red_x->Size = System::Drawing::Size(36, 12);
			this->Red_x->TabIndex = 2;
			this->Red_x->Text = L"Red_x";
			// 
			// maintimer
			// 
			this->maintimer->Interval = 50;
			this->maintimer->Tick += gcnew System::EventHandler(this, &MainForm::maintimer_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(311, 347);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void imageDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				if(mModelForm==nullptr){
				 mModelForm = gcnew ModelForm();
			 }
			mModelForm->Show();
			 }
	
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {			 
			 
			 //xml
			 XmlDocument^ doc = gcnew XmlDocument();
			 doc->Load("Robot_Config.xml");
			 //System::Diagnostics::Debug::WriteLine(doc->FirstChild->Name);
			 XmlNode^ Color = doc->SelectSingleNode("/Config/ColorModel");
			 for(int j =0;j < Color->ChildNodes->Count;j++){
				XmlNode^ node = Color->ChildNodes[j]; 
				XmlElement^ element = (XmlElement^)node;
				if(element->Name=="Blue"){
					ImageData->hsvBlueRange->HueMax= System::Convert::ToDouble(element->GetAttribute("HueMax"));
					ImageData->hsvBlueRange->HueMin=System::Convert::ToDouble(element->GetAttribute("HueMin"));
					ImageData->hsvBlueRange->SaturationMax=System::Convert::ToDouble(element->GetAttribute("SaturationMax"));
					ImageData->hsvBlueRange->SaturationMin=System::Convert::ToDouble(element->GetAttribute("SaturationMin"));
					ImageData->hsvBlueRange->BrightnessMax=System::Convert::ToDouble(element->GetAttribute("BrightnessMax"));
					ImageData->hsvBlueRange->BrightnessMin=System::Convert::ToDouble(element->GetAttribute("BrightnessMin"));
				}
				if(element->Name=="Green"){
					ImageData->hsvGreenRange->HueMax= System::Convert::ToDouble(element->GetAttribute("HueMax"));
					ImageData->hsvGreenRange->HueMin=System::Convert::ToDouble(element->GetAttribute("HueMin"));
					ImageData->hsvGreenRange->SaturationMax=System::Convert::ToDouble(element->GetAttribute("SaturationMax"));
					ImageData->hsvGreenRange->SaturationMin=System::Convert::ToDouble(element->GetAttribute("SaturationMin"));
					ImageData->hsvGreenRange->BrightnessMax=System::Convert::ToDouble(element->GetAttribute("BrightnessMax"));
					ImageData->hsvGreenRange->BrightnessMin=System::Convert::ToDouble(element->GetAttribute("BrightnessMin"));
				}
				if(element->Name=="Red"){
					ImageData->hsvRedRange->HueMax= System::Convert::ToDouble(element->GetAttribute("HueMax"));
					ImageData->hsvRedRange->HueMin=System::Convert::ToDouble(element->GetAttribute("HueMin"));
					ImageData->hsvRedRange->SaturationMax=System::Convert::ToDouble(element->GetAttribute("SaturationMax"));
					ImageData->hsvRedRange->SaturationMin=System::Convert::ToDouble(element->GetAttribute("SaturationMin"));
					ImageData->hsvRedRange->BrightnessMax=System::Convert::ToDouble(element->GetAttribute("BrightnessMax"));
					ImageData->hsvRedRange->BrightnessMin=System::Convert::ToDouble(element->GetAttribute("BrightnessMin"));
				}
				
											
			}	
			//blue
			bluseHuxMaxLB->Text = "HueMax="+ImageData->hsvBlueRange->HueMax;
			blueHueMinLB->Text = "HueMin="+ImageData->hsvBlueRange->HueMin;;
			blueSaturationMaxLB->Text="SaturationMax="+ImageData->hsvBlueRange->SaturationMax;
			blueSaturationMinNB->Text="SaturationMin="+ImageData->hsvBlueRange->SaturationMin;
			blueBrightnesMaxLB->Text="BrightnessMax="+ImageData->hsvBlueRange->BrightnessMax;
			blueBrightnesMinLB->Text="BrightnessMax="+ImageData->hsvBlueRange->BrightnessMin;
			//green
			greenHueMaxLB->Text = "HueMax="+ImageData->hsvGreenRange->HueMax;
			greenHueMinLB->Text = "HueMin="+ImageData->hsvGreenRange->HueMin;
			greenSaturationMaxLB->Text="SaturationMax="+ImageData->hsvGreenRange->SaturationMax;
			greenSaturationMinLB->Text="SaturationMin="+ImageData->hsvGreenRange->SaturationMin;
			greenBrightnesMaxLB->Text="BrightnessMax="+ImageData->hsvGreenRange->BrightnessMax;
			greenBrightnesMinLB->Text="BrightnessMax="+ImageData->hsvGreenRange->BrightnessMin;
			//red
			redHueMaxLB->Text = "HueMax="+ImageData->hsvRedRange->HueMax;
			redHueMinLB->Text = "HueMin="+ImageData->hsvRedRange->HueMin;
			redSaturationMaxLB->Text="SaturationMax="+ImageData->hsvRedRange->SaturationMax;
			redSaturationMinLB->Text="SaturationMin="+ImageData->hsvRedRange->SaturationMin;
			redBrightnesMaxLB->Text="BrightnessMax="+ImageData->hsvRedRange->BrightnessMax;
			redBrightnesMinLB->Text="BrightnessMin="+ImageData->hsvRedRange->BrightnessMin;
			

		 }


private: System::Void previewToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(mPreviewForm==nullptr){
				 mPreviewForm = gcnew PreviewForm();
			 }
			mPreviewForm->Show();
			maintimer->Start();
		 }

private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			//mPreviewForm->Visible = false;
			this->Hide();
			e->Cancel = true;

		 }

private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }
private: System::Void maintimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 
			  CallbackBuffer = false;


			 if(!CallbackBuffer)
			 {
				 if (mPreviewForm!=nullptr && mModelForm!=nullptr && mModelForm->Visible)
			 {
					mModelForm->ModelMainFunction(ImageData->pImage);
			 }
			 mPreviewForm->DisplayImage(ImageData->pImage);
		 
			}
		 }
		 

};
}