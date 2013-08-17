#pragma once

#include <math.h>
#include "../Database.h"

namespace SKS_VC2013 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Xml;
	/// <summary>
	/// Camera 的摘要
	/// </summary>
	public ref class Camera : public System::Windows::Forms::Form
	{
	public:
		Camera(void)
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
		~Camera()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::PictureBox^  Camera_Pb;
	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


		/*************畫圖***************/
		Bitmap^ mBMP;
		Bitmap^ mBMP_2;
		Bitmap^ mBMP_3;
	private: System::Windows::Forms::Label^  Cam_lab;
	private: System::Windows::Forms::CheckBox^  Re_Camera;
	private: System::Windows::Forms::Timer^  timer1;






			 Graphics^ mGraphic;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Camera_Pb = (gcnew System::Windows::Forms::PictureBox());
			this->Cam_lab = (gcnew System::Windows::Forms::Label());
			this->Re_Camera = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Camera_Pb))->BeginInit();
			this->SuspendLayout();
			// 
			// Camera_Pb
			// 
			this->Camera_Pb->Location = System::Drawing::Point(0, 1);
			this->Camera_Pb->Name = L"Camera_Pb";
			this->Camera_Pb->Size = System::Drawing::Size(150, 150);
			this->Camera_Pb->TabIndex = 1;
			this->Camera_Pb->TabStop = false;
			// 
			// Cam_lab
			// 
			this->Cam_lab->AutoSize = true;
			this->Cam_lab->Location = System::Drawing::Point(120, 7);
			this->Cam_lab->Name = L"Cam_lab";
			this->Cam_lab->Size = System::Drawing::Size(20, 12);
			this->Cam_lab->TabIndex = 2;
			this->Cam_lab->Text = L"90°";
			// 
			// Re_Camera
			// 
			this->Re_Camera->AutoSize = true;
			this->Re_Camera->Location = System::Drawing::Point(4, 3);
			this->Re_Camera->Name = L"Re_Camera";
			this->Re_Camera->Size = System::Drawing::Size(60, 16);
			this->Re_Camera->TabIndex = 3;
			this->Re_Camera->Text = L"Camera";
			this->Re_Camera->UseVisualStyleBackColor = true;
			this->Re_Camera->CheckedChanged += gcnew System::EventHandler(this, &Camera::Re_Camera_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &Camera::timer1_Tick);
			// 
			// Camera
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(152, 151);
			this->Controls->Add(this->Re_Camera);
			this->Controls->Add(this->Cam_lab);
			this->Controls->Add(this->Camera_Pb);
			this->Name = L"Camera";
			this->Text = L"Camera";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Camera::Camera_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Camera::Camera_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Camera_Pb))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:	void Rotate_Camera(int ang){
			Color P_Color;
			int i,j;
			double x,y;
			double d = (ang-90)*PI/180;
			mBMP  = gcnew Bitmap("Camera.png");
			mBMP_2 = gcnew Bitmap(150,150);

			for(i=-75 ; i<75 ; i++){
				for(j=-75 ; j<75 ; j++){
					x = cos(d)*(i)-sin(d)*(j);
					y = cos(d)*(j)+sin(d)*(i);

					if(x>-75 && x<75 && y>=-75 && y<75){
						P_Color = mBMP->GetPixel(x+75,y+75);
					}
					mBMP_2->SetPixel(i+75,j+75,P_Color);
				}
			}

			Camera_Pb->Image = mBMP_2;
			Cam_lab->Text = System::Convert::ToString(ang) + "°";
		}
	private: System::Void Camera_Load(System::Object^  sender, System::EventArgs^  e) {
				 Rotate_Camera(D_Order->Camera);
				 R_Robot->Camera_Angle = 90;
				 Cam_lab->Text = System::Convert::ToString(R_Robot->Camera_Angle) + "°";
				 timer1->Start();
			 }
	private: System::Void Camera_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 this->Hide();
				 e->Cancel = true;
			 }
private: System::Void Re_Camera_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 Robot_Request("Camera_Angle");
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(Re_Camera->Checked){
				 Rotate_Camera(R_Robot->Camera_Angle);
			 }
		 }
};
}
