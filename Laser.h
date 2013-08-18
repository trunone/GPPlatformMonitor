#pragma once

#include <math.h>
#include "Database.h"

namespace SKS_VC2013 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Xml;
	/// <summary>
	/// Laser 的摘要
	/// </summary>
	public ref class Laser : public System::Windows::Forms::Form
	{
	public:
		Laser(void)
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
		~Laser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  R_Laser_check;
	private: System::Windows::Forms::PictureBox^  Laser_PB;
	protected: 

	protected: 

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  R_Robot_Check;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  Position_ang;

	private: System::Windows::Forms::Label^  Position_y;

	private: System::Windows::Forms::Label^  Position_x;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>

		Bitmap^ mBMP;
	private: System::Windows::Forms::Label^  Laser_Dis;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
			 Graphics^ mGraphic;
	



#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Laser::typeid));
			this->R_Laser_check = (gcnew System::Windows::Forms::CheckBox());
			this->Laser_PB = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Position_ang = (gcnew System::Windows::Forms::Label());
			this->Position_y = (gcnew System::Windows::Forms::Label());
			this->Position_x = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->R_Robot_Check = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Laser_Dis = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Laser_PB))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// R_Laser_check
			// 
			this->R_Laser_check->AutoSize = true;
			this->R_Laser_check->Location = System::Drawing::Point(12, 12);
			this->R_Laser_check->Name = L"R_Laser_check";
			this->R_Laser_check->Size = System::Drawing::Size(49, 16);
			this->R_Laser_check->TabIndex = 0;
			this->R_Laser_check->Text = L"Laser";
			this->R_Laser_check->UseVisualStyleBackColor = true;
			this->R_Laser_check->CheckedChanged += gcnew System::EventHandler(this, &Laser::R_Laser_check_CheckedChanged);
			// 
			// Laser_PB
			// 
			this->Laser_PB->BackColor = System::Drawing::Color::Transparent;
			this->Laser_PB->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Laser_PB.Image")));
			this->Laser_PB->Location = System::Drawing::Point(12, 34);
			this->Laser_PB->Name = L"Laser_PB";
			this->Laser_PB->Size = System::Drawing::Size(500, 500);
			this->Laser_PB->TabIndex = 1;
			this->Laser_PB->TabStop = false;
			this->Laser_PB->MouseEnter += gcnew System::EventHandler(this, &Laser::Laser_PB_MouseEnter);
			this->Laser_PB->MouseLeave += gcnew System::EventHandler(this, &Laser::Laser_PB_MouseLeave);
			this->Laser_PB->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Laser::Laser_PB_MouseMove);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->R_Robot_Check);
			this->groupBox1->Location = System::Drawing::Point(518, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(114, 522);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Location = System::Drawing::Point(6, 252);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(104, 228);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"搜尋";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label17->Location = System::Drawing::Point(6, 70);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(27, 12);
			this->label17->TabIndex = 2;
			this->label17->Text = L"Blue";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::SpringGreen;
			this->label16->Location = System::Drawing::Point(6, 45);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(33, 12);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Green";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::HotPink;
			this->label15->Location = System::Drawing::Point(6, 20);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(24, 12);
			this->label15->TabIndex = 0;
			this->label15->Text = L"Red";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->Position_ang);
			this->groupBox2->Controls->Add(this->Position_y);
			this->groupBox2->Controls->Add(this->Position_x);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(6, 38);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(104, 193);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Robot";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(82, 170);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(11, 12);
			this->label14->TabIndex = 13;
			this->label14->Text = L"0";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(82, 145);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(11, 12);
			this->label13->TabIndex = 12;
			this->label13->Text = L"0";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(82, 120);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(11, 12);
			this->label12->TabIndex = 11;
			this->label12->Text = L"0";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 170);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(47, 12);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Wheel３";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 145);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(47, 12);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Wheel２";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 120);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(47, 12);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Wheel１";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(82, 95);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(11, 12);
			this->label8->TabIndex = 7;
			this->label8->Text = L"0";
			// 
			// Position_ang
			// 
			this->Position_ang->AutoSize = true;
			this->Position_ang->Location = System::Drawing::Point(82, 70);
			this->Position_ang->Name = L"Position_ang";
			this->Position_ang->Size = System::Drawing::Size(11, 12);
			this->Position_ang->TabIndex = 6;
			this->Position_ang->Text = L"0";
			// 
			// Position_y
			// 
			this->Position_y->AutoSize = true;
			this->Position_y->Location = System::Drawing::Point(82, 45);
			this->Position_y->Name = L"Position_y";
			this->Position_y->Size = System::Drawing::Size(11, 12);
			this->Position_y->TabIndex = 5;
			this->Position_y->Text = L"0";
			// 
			// Position_x
			// 
			this->Position_x->AutoSize = true;
			this->Position_x->Location = System::Drawing::Point(82, 20);
			this->Position_x->Name = L"Position_x";
			this->Position_x->Size = System::Drawing::Size(11, 12);
			this->Position_x->TabIndex = 4;
			this->Position_x->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 12);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Rotate";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Angle";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Ｙ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ｘ";
			// 
			// R_Robot_Check
			// 
			this->R_Robot_Check->AutoSize = true;
			this->R_Robot_Check->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->R_Robot_Check->Location = System::Drawing::Point(6, 17);
			this->R_Robot_Check->Name = L"R_Robot_Check";
			this->R_Robot_Check->Size = System::Drawing::Size(61, 16);
			this->R_Robot_Check->TabIndex = 0;
			this->R_Robot_Check->Text = L"Position";
			this->R_Robot_Check->UseVisualStyleBackColor = true;
			this->R_Robot_Check->CheckedChanged += gcnew System::EventHandler(this, &Laser::R_Robot_Check_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Laser::timer1_Tick);
			// 
			// Laser_Dis
			// 
			this->Laser_Dis->AllowDrop = true;
			this->Laser_Dis->AutoSize = true;
			this->Laser_Dis->BackColor = System::Drawing::Color::White;
			this->Laser_Dis->Location = System::Drawing::Point(245, 421);
			this->Laser_Dis->Name = L"Laser_Dis";
			this->Laser_Dis->Size = System::Drawing::Size(11, 12);
			this->Laser_Dis->TabIndex = 3;
			this->Laser_Dis->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(371, 286);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(23, 12);
			this->label5->TabIndex = 4;
			this->label5->Text = L"255";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(467, 286);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 12);
			this->label6->TabIndex = 5;
			this->label6->Text = L"490";
			// 
			// Laser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(637, 540);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Laser_Dis);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Laser_PB);
			this->Controls->Add(this->R_Laser_check);
			this->Name = L"Laser";
			this->Text = L"Laser";
			this->Load += gcnew System::EventHandler(this, &Laser::Laser_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Laser_PB))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Laser_Load(System::Object^  sender, System::EventArgs^  e) {
				 Laser_PB->Height = Laser_Height;
				 Laser_PB->Width = Laser_Width;
				 for(int i=0 ;i<73;i++){
					 R_Laser[i].Angle = 0;
					 R_Laser[i].Distance = 0;
				 }
				 R_Position->x = 0;
				 R_Position->y = 0;
				 R_Position->ang = 0;
				 timer1->Start();
			 }
	void draw_Distance(){
		mBMP  = gcnew Bitmap("Laser_Base.bmp"); //背景和框繪製區
		mGraphic   = Graphics::FromImage(mBMP);
		double x,y;
		Pen^ redPen = gcnew Pen(Color::Red, 1);

		for(int i =0 ;i<73;i++){
			x = 250 + (R_Laser[i].Distance*Laser_Width/2/(Map_Width-D_Robot->R)*cos((R_Laser[i].Angle+90)*PI/180));
			y = 250 - (R_Laser[i].Distance*Laser_Width/2/(Map_Width-D_Robot->R)*sin((R_Laser[i].Angle+90)*PI/180));
			mGraphic->DrawLine(redPen,250, 250 , (int)x, (int)y);
		}
		Laser_PB->Image = mBMP;
	}
private: System::Void R_Laser_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 Robot_Request("Laser");
		 }
private: System::Void R_Robot_Check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 Robot_Request("Position");
		 }
	void viewPosition(){
		Position_x->Text = System::Convert::ToString(R_Position->x);
		Position_y->Text = System::Convert::ToString(R_Position->y);
		Position_ang->Text = System::Convert::ToString(R_Position->ang)+"°";
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			if(R_Laser_check->Checked){
				draw_Distance();
			}else{
				mBMP  = gcnew Bitmap("Laser_Base.bmp"); //背景和框繪製區
				Laser_PB->Image = mBMP;
			}
			if(R_Robot_Check->Checked){
				viewPosition();
			}else{
				R_Position->x = 0;
				R_Position->y = 0;
				R_Position->ang = 0;
			}
		 }
private: System::Void Laser_PB_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 Laser_Dis->Visible = true;
		 }
private: System::Void Laser_PB_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 Laser_Dis->Visible = false;
		 }
private: System::Void Laser_PB_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 double mos_x = e->X-250;
			 double mos_y = e->Y-250;

			 int d = sqrt(pow(mos_x,2)+pow(mos_y,2));
			 
			 d = d*2*(Map_Width-D_Robot->R)/Laser_Width;

			 Laser_Dis->Text = System::Convert::ToString(d);
			 Laser_Dis->Location = Point(e->X+12,e->Y+20);
		 }
};
}
