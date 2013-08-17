#pragma once

//!  The main interface.

#include <math.h>
#include "Map.h"
#include "Laser.h"
#include "Database.h"
#include "MainForm.h"
#include "Furniture/Furniture.h"
#include "Camera/Camera.h"
#include "MapEditer/MapEditer.h"

namespace SKS_VC2013 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::Text;

	using namespace System::Xml;
	using namespace System::IO;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  IP;
	protected: 
	private: System::Windows::Forms::TextBox^  IP_box;
	private: System::Windows::Forms::TextBox^  Client_box;

	private: System::Windows::Forms::Label^  Client;

	private: System::Windows::Forms::Button^  Client_set;

	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>

		String^ MSG_Str;
		delegate void SetTextDelegate();

		//!Socket
		Socket^ ClientSocket;	/**< Client Socket. */
		static int Client_already = 0;	/**< Client Check. */

		//! File.
		String^ fileName;

		//! Paint.
		Bitmap^ mBMP;
		Graphics^ mGraphic;

		//! View Form.
		Map^ mMap;
		Laser^ mLaser;
		PureModelForm::MainForm^ mVision;
		Camera^ mCamera;

		//! Set Form.
		Furniture^ mFurniture;
		MapEditer^ mMapEditer;

	private: System::Windows::Forms::ListBox^  MSG_list;
	private: System::Windows::Forms::Button^  Up_sd;
	private: System::Windows::Forms::Button^  Left_sd;
	private: System::Windows::Forms::Button^  Right_sd;
	private: System::Windows::Forms::Button^  Down_sd;
	private: System::Windows::Forms::PictureBox^  drawPB;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  View_set;
	private: System::Windows::Forms::ToolStripMenuItem^  Map_set;
	private: System::Windows::Forms::HScrollBar^  Speed_Bar;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  Speed_lab;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  R_b;
	private: System::Windows::Forms::Button^  L_b;
	private: System::Windows::Forms::CheckBox^  Map_check;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::CheckBox^  Call_back;
	private: System::Windows::Forms::ToolStripMenuItem^  visonToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  laserToolStripMenuItem;
	private: System::Windows::Forms::Button^  T_Stop;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  T_Reset;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::ToolStripMenuItem^  Setup_set;
	private: System::Windows::Forms::ToolStripMenuItem^  furnitureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  CameraToolStripMenuItem;
	private: System::Windows::Forms::Button^  TakeBall;
	private: System::Windows::Forms::Label^  Cam_lab;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::VScrollBar^  Cam_Bar;
	private: System::Windows::Forms::Label^  T_Min;
	private: System::Windows::Forms::Label^  T_Sec;
	private: System::Windows::Forms::ToolStripMenuItem^  mapEditerToolStripMenuItem;

	private: System::Windows::Forms::CheckBox^  Auto_check;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Button^  Send_Config;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->IP = (gcnew System::Windows::Forms::Label());
			this->IP_box = (gcnew System::Windows::Forms::TextBox());
			this->Client_box = (gcnew System::Windows::Forms::TextBox());
			this->Client = (gcnew System::Windows::Forms::Label());
			this->Client_set = (gcnew System::Windows::Forms::Button());
			this->MSG_list = (gcnew System::Windows::Forms::ListBox());
			this->Up_sd = (gcnew System::Windows::Forms::Button());
			this->Left_sd = (gcnew System::Windows::Forms::Button());
			this->Right_sd = (gcnew System::Windows::Forms::Button());
			this->Down_sd = (gcnew System::Windows::Forms::Button());
			this->drawPB = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->View_set = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Map_set = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->visonToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->laserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CameraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Setup_set = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->furnitureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mapEditerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Speed_Bar = (gcnew System::Windows::Forms::HScrollBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Speed_lab = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Send_Config = (gcnew System::Windows::Forms::Button());
			this->Auto_check = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Call_back = (gcnew System::Windows::Forms::CheckBox());
			this->Map_check = (gcnew System::Windows::Forms::CheckBox());
			this->Cam_lab = (gcnew System::Windows::Forms::Label());
			this->TakeBall = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Cam_Bar = (gcnew System::Windows::Forms::VScrollBar());
			this->R_b = (gcnew System::Windows::Forms::Button());
			this->L_b = (gcnew System::Windows::Forms::Button());
			this->T_Stop = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->T_Reset = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->T_Min = (gcnew System::Windows::Forms::Label());
			this->T_Sec = (gcnew System::Windows::Forms::Label());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->drawPB))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// IP
			// 
			this->IP->AutoSize = true;
			this->IP->BackColor = System::Drawing::Color::Transparent;
			this->IP->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->IP->Location = System::Drawing::Point(10, 37);
			this->IP->Name = L"IP";
			this->IP->Size = System::Drawing::Size(15, 12);
			this->IP->TabIndex = 0;
			this->IP->Text = L"IP";
			// 
			// IP_box
			// 
			this->IP_box->Location = System::Drawing::Point(25, 32);
			this->IP_box->Name = L"IP_box";
			this->IP_box->Size = System::Drawing::Size(87, 22);
			this->IP_box->TabIndex = 1;
			this->IP_box->Text = L"192.168.137.75";
			// 
			// Client_box
			// 
			this->Client_box->Location = System::Drawing::Point(146, 32);
			this->Client_box->Name = L"Client_box";
			this->Client_box->Size = System::Drawing::Size(40, 22);
			this->Client_box->TabIndex = 2;
			this->Client_box->Text = L"10373";
			// 
			// Client
			// 
			this->Client->AutoSize = true;
			this->Client->BackColor = System::Drawing::Color::Transparent;
			this->Client->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Client->Location = System::Drawing::Point(113, 37);
			this->Client->Name = L"Client";
			this->Client->Size = System::Drawing::Size(33, 12);
			this->Client->TabIndex = 4;
			this->Client->Text = L"Client";
			// 
			// Client_set
			// 
			this->Client_set->Location = System::Drawing::Point(189, 31);
			this->Client_set->Name = L"Client_set";
			this->Client_set->Size = System::Drawing::Size(39, 23);
			this->Client_set->TabIndex = 6;
			this->Client_set->Text = L"Set";
			this->Client_set->UseVisualStyleBackColor = true;
			this->Client_set->Click += gcnew System::EventHandler(this, &Form1::Client_set_Click);
			// 
			// MSG_list
			// 
			this->MSG_list->FormattingEnabled = true;
			this->MSG_list->HorizontalScrollbar = true;
			this->MSG_list->ItemHeight = 12;
			this->MSG_list->Location = System::Drawing::Point(9, 414);
			this->MSG_list->Name = L"MSG_list";
			this->MSG_list->ScrollAlwaysVisible = true;
			this->MSG_list->Size = System::Drawing::Size(218, 100);
			this->MSG_list->TabIndex = 8;
			// 
			// Up_sd
			// 
			this->Up_sd->BackColor = System::Drawing::Color::Transparent;
			this->Up_sd->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Up_sd->Location = System::Drawing::Point(59, 206);
			this->Up_sd->Name = L"Up_sd";
			this->Up_sd->Size = System::Drawing::Size(50, 50);
			this->Up_sd->TabIndex = 11;
			this->Up_sd->Text = L"↑";
			this->Up_sd->UseVisualStyleBackColor = false;
			this->Up_sd->Click += gcnew System::EventHandler(this, &Form1::Up_sd_Click);
			// 
			// Left_sd
			// 
			this->Left_sd->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Left_sd->Location = System::Drawing::Point(6, 261);
			this->Left_sd->Name = L"Left_sd";
			this->Left_sd->Size = System::Drawing::Size(50, 50);
			this->Left_sd->TabIndex = 12;
			this->Left_sd->Text = L"←";
			this->Left_sd->UseVisualStyleBackColor = true;
			this->Left_sd->Click += gcnew System::EventHandler(this, &Form1::Left_sd_Click);
			// 
			// Right_sd
			// 
			this->Right_sd->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Right_sd->Location = System::Drawing::Point(113, 261);
			this->Right_sd->Name = L"Right_sd";
			this->Right_sd->Size = System::Drawing::Size(50, 50);
			this->Right_sd->TabIndex = 13;
			this->Right_sd->Text = L"→";
			this->Right_sd->UseVisualStyleBackColor = true;
			this->Right_sd->Click += gcnew System::EventHandler(this, &Form1::Right_sd_Click);
			// 
			// Down_sd
			// 
			this->Down_sd->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Down_sd->Location = System::Drawing::Point(59, 261);
			this->Down_sd->Name = L"Down_sd";
			this->Down_sd->Size = System::Drawing::Size(50, 50);
			this->Down_sd->TabIndex = 14;
			this->Down_sd->Text = L"↓";
			this->Down_sd->UseVisualStyleBackColor = true;
			this->Down_sd->Click += gcnew System::EventHandler(this, &Form1::Down_sd_Click);
			// 
			// drawPB
			// 
			this->drawPB->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"drawPB.Image")));
			this->drawPB->Location = System::Drawing::Point(2, 60);
			this->drawPB->Name = L"drawPB";
			this->drawPB->Size = System::Drawing::Size(144, 144);
			this->drawPB->TabIndex = 15;
			this->drawPB->TabStop = false;
			this->drawPB->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::drawPB_MouseDown);
			this->drawPB->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::drawPB_MouseMove);
			this->drawPB->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::drawPB_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::DarkGray;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->View_set, this->Setup_set});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(232, 24);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// View_set
			// 
			this->View_set->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->Map_set, this->visonToolStripMenuItem, 
				this->laserToolStripMenuItem, this->CameraToolStripMenuItem});
			this->View_set->Name = L"View_set";
			this->View_set->Size = System::Drawing::Size(47, 20);
			this->View_set->Text = L"View";
			// 
			// Map_set
			// 
			this->Map_set->Name = L"Map_set";
			this->Map_set->Size = System::Drawing::Size(120, 22);
			this->Map_set->Text = L"Map";
			this->Map_set->Click += gcnew System::EventHandler(this, &Form1::Map_set_Click);
			// 
			// visonToolStripMenuItem
			// 
			this->visonToolStripMenuItem->Name = L"visonToolStripMenuItem";
			this->visonToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->visonToolStripMenuItem->Text = L"Vison";
			this->visonToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::visonToolStripMenuItem_Click);
			// 
			// laserToolStripMenuItem
			// 
			this->laserToolStripMenuItem->Name = L"laserToolStripMenuItem";
			this->laserToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->laserToolStripMenuItem->Text = L"Laser";
			this->laserToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::laserToolStripMenuItem_Click);
			// 
			// CameraToolStripMenuItem
			// 
			this->CameraToolStripMenuItem->Name = L"CameraToolStripMenuItem";
			this->CameraToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->CameraToolStripMenuItem->Text = L"Camera";
			this->CameraToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::CameraToolStripMenuItem_Click);
			// 
			// Setup_set
			// 
			this->Setup_set->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->furnitureToolStripMenuItem, 
				this->mapEditerToolStripMenuItem});
			this->Setup_set->Name = L"Setup_set";
			this->Setup_set->Size = System::Drawing::Size(53, 20);
			this->Setup_set->Text = L"Setup";
			// 
			// furnitureToolStripMenuItem
			// 
			this->furnitureToolStripMenuItem->Name = L"furnitureToolStripMenuItem";
			this->furnitureToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->furnitureToolStripMenuItem->Text = L"Furniture";
			this->furnitureToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::furnitureToolStripMenuItem_Click);
			// 
			// mapEditerToolStripMenuItem
			// 
			this->mapEditerToolStripMenuItem->Name = L"mapEditerToolStripMenuItem";
			this->mapEditerToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->mapEditerToolStripMenuItem->Text = L"MapEditer";
			this->mapEditerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mapEditerToolStripMenuItem_Click);
			// 
			// Speed_Bar
			// 
			this->Speed_Bar->Location = System::Drawing::Point(8, 29);
			this->Speed_Bar->Maximum = 409;
			this->Speed_Bar->Minimum = 100;
			this->Speed_Bar->Name = L"Speed_Bar";
			this->Speed_Bar->Size = System::Drawing::Size(80, 17);
			this->Speed_Bar->TabIndex = 17;
			this->Speed_Bar->Value = 100;
			this->Speed_Bar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::Speed_Bar_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(9, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 12);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Speed";
			// 
			// Speed_lab
			// 
			this->Speed_lab->AutoSize = true;
			this->Speed_lab->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Speed_lab->Location = System::Drawing::Point(52, 13);
			this->Speed_lab->Name = L"Speed_lab";
			this->Speed_lab->Size = System::Drawing::Size(23, 12);
			this->Speed_lab->TabIndex = 19;
			this->Speed_lab->Text = L"100";
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker2_DoWork);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::DimGray;
			this->groupBox1->Controls->Add(this->Send_Config);
			this->groupBox1->Controls->Add(this->Auto_check);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->Call_back);
			this->groupBox1->Controls->Add(this->Map_check);
			this->groupBox1->Controls->Add(this->Cam_lab);
			this->groupBox1->Controls->Add(this->TakeBall);
			this->groupBox1->Controls->Add(this->drawPB);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->Up_sd);
			this->groupBox1->Controls->Add(this->Cam_Bar);
			this->groupBox1->Controls->Add(this->Right_sd);
			this->groupBox1->Controls->Add(this->Down_sd);
			this->groupBox1->Controls->Add(this->Left_sd);
			this->groupBox1->Controls->Add(this->R_b);
			this->groupBox1->Controls->Add(this->L_b);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->groupBox1->Location = System::Drawing::Point(12, 61);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(212, 313);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			// 
			// Send_Config
			// 
			this->Send_Config->Location = System::Drawing::Point(150, 62);
			this->Send_Config->Name = L"Send_Config";
			this->Send_Config->Size = System::Drawing::Size(51, 23);
			this->Send_Config->TabIndex = 30;
			this->Send_Config->Text = L"Config";
			this->Send_Config->UseVisualStyleBackColor = true;
			this->Send_Config->Click += gcnew System::EventHandler(this, &Form1::Send_Config_Click);
			// 
			// Auto_check
			// 
			this->Auto_check->AutoSize = true;
			this->Auto_check->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Auto_check->Location = System::Drawing::Point(8, 42);
			this->Auto_check->Name = L"Auto_check";
			this->Auto_check->Size = System::Drawing::Size(98, 16);
			this->Auto_check->TabIndex = 29;
			this->Auto_check->Text = L"Auto_Simulator";
			this->Auto_check->UseVisualStyleBackColor = true;
			this->Auto_check->CheckedChanged += gcnew System::EventHandler(this, &Form1::Auto_check_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Speed_Bar);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->Speed_lab);
			this->groupBox2->Location = System::Drawing::Point(119, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(93, 54);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			// 
			// Call_back
			// 
			this->Call_back->AutoSize = true;
			this->Call_back->BackColor = System::Drawing::Color::Transparent;
			this->Call_back->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Call_back->Location = System::Drawing::Point(8, 10);
			this->Call_back->Name = L"Call_back";
			this->Call_back->Size = System::Drawing::Size(61, 16);
			this->Call_back->TabIndex = 21;
			this->Call_back->Text = L"Request";
			this->Call_back->UseVisualStyleBackColor = false;
			// 
			// Map_check
			// 
			this->Map_check->AutoSize = true;
			this->Map_check->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Map_check->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Map_check->Location = System::Drawing::Point(8, 26);
			this->Map_check->Name = L"Map_check";
			this->Map_check->Size = System::Drawing::Size(93, 16);
			this->Map_check->TabIndex = 23;
			this->Map_check->Text = L"Ctrl_Simulator";
			this->Map_check->UseVisualStyleBackColor = true;
			// 
			// Cam_lab
			// 
			this->Cam_lab->AutoSize = true;
			this->Cam_lab->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Cam_lab->Location = System::Drawing::Point(163, 109);
			this->Cam_lab->Name = L"Cam_lab";
			this->Cam_lab->Size = System::Drawing::Size(20, 12);
			this->Cam_lab->TabIndex = 28;
			this->Cam_lab->Text = L"90°";
			// 
			// TakeBall
			// 
			this->TakeBall->BackColor = System::Drawing::Color::White;
			this->TakeBall->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->TakeBall->Location = System::Drawing::Point(146, 232);
			this->TakeBall->Name = L"TakeBall";
			this->TakeBall->Size = System::Drawing::Size(41, 23);
			this->TakeBall->TabIndex = 24;
			this->TakeBall->Text = L"Ball";
			this->TakeBall->UseVisualStyleBackColor = false;
			this->TakeBall->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TakeBall_MouseDown);
			this->TakeBall->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::TakeBall_MouseUp);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Location = System::Drawing::Point(154, 92);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 12);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Camera";
			// 
			// Cam_Bar
			// 
			this->Cam_Bar->Location = System::Drawing::Point(165, 128);
			this->Cam_Bar->Maximum = 144;
			this->Cam_Bar->Minimum = 80;
			this->Cam_Bar->Name = L"Cam_Bar";
			this->Cam_Bar->Size = System::Drawing::Size(17, 80);
			this->Cam_Bar->TabIndex = 25;
			this->Cam_Bar->Value = 90;
			this->Cam_Bar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::Cam_Bar_Scroll);
			// 
			// R_b
			// 
			this->R_b->Location = System::Drawing::Point(112, 231);
			this->R_b->Name = L"R_b";
			this->R_b->Size = System::Drawing::Size(25, 25);
			this->R_b->TabIndex = 21;
			this->R_b->Text = L"R";
			this->R_b->UseVisualStyleBackColor = true;
			this->R_b->Click += gcnew System::EventHandler(this, &Form1::R_b_Click);
			// 
			// L_b
			// 
			this->L_b->Location = System::Drawing::Point(31, 231);
			this->L_b->Name = L"L_b";
			this->L_b->Size = System::Drawing::Size(25, 25);
			this->L_b->TabIndex = 22;
			this->L_b->Text = L"L";
			this->L_b->UseVisualStyleBackColor = true;
			this->L_b->Click += gcnew System::EventHandler(this, &Form1::L_b_Click);
			// 
			// T_Stop
			// 
			this->T_Stop->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->T_Stop->Location = System::Drawing::Point(139, 386);
			this->T_Stop->Name = L"T_Stop";
			this->T_Stop->Size = System::Drawing::Size(42, 23);
			this->T_Stop->TabIndex = 23;
			this->T_Stop->Text = L"Stop";
			this->T_Stop->UseVisualStyleBackColor = true;
			this->T_Stop->Click += gcnew System::EventHandler(this, &Form1::T_Stop_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(53, 394);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 12);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Min";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(116, 394);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 12);
			this->label3->TabIndex = 26;
			this->label3->Text = L"Sec";
			// 
			// T_Reset
			// 
			this->T_Reset->BackColor = System::Drawing::SystemColors::Control;
			this->T_Reset->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->T_Reset->Location = System::Drawing::Point(183, 386);
			this->T_Reset->Name = L"T_Reset";
			this->T_Reset->Size = System::Drawing::Size(42, 23);
			this->T_Reset->TabIndex = 27;
			this->T_Reset->Text = L"Reset";
			this->T_Reset->UseVisualStyleBackColor = false;
			this->T_Reset->Click += gcnew System::EventHandler(this, &Form1::T_Reset_Click);
			// 
			// timer2
			// 
			this->timer2->Interval = 997;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// T_Min
			// 
			this->T_Min->AutoSize = true;
			this->T_Min->BackColor = System::Drawing::Color::Transparent;
			this->T_Min->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->T_Min->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->T_Min->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->T_Min->Location = System::Drawing::Point(13, 379);
			this->T_Min->Name = L"T_Min";
			this->T_Min->Size = System::Drawing::Size(40, 29);
			this->T_Min->TabIndex = 28;
			this->T_Min->Text = L"10";
			// 
			// T_Sec
			// 
			this->T_Sec->AutoSize = true;
			this->T_Sec->BackColor = System::Drawing::Color::Transparent;
			this->T_Sec->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->T_Sec->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->T_Sec->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->T_Sec->Location = System::Drawing::Point(76, 379);
			this->T_Sec->Name = L"T_Sec";
			this->T_Sec->Size = System::Drawing::Size(40, 29);
			this->T_Sec->TabIndex = 29;
			this->T_Sec->Text = L"00";
			// 
			// timer3
			// 
			this->timer3->Interval = 500;
			this->timer3->Tick += gcnew System::EventHandler(this, &Form1::timer3_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Gray;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(232, 518);
			this->Controls->Add(this->T_Sec);
			this->Controls->Add(this->T_Min);
			this->Controls->Add(this->T_Reset);
			this->Controls->Add(this->T_Stop);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->MSG_list);
			this->Controls->Add(this->Client_set);
			this->Controls->Add(this->Client);
			this->Controls->Add(this->Client_box);
			this->Controls->Add(this->IP_box);
			this->Controls->Add(this->IP);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->drawPB))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		
#pragma endregion

//! First Load Code.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 drawPB->Width  = Radar_Width;
				 drawPB->Height = Radar_Height;

				 D_Time->Minute = 10;
				 D_Time->Second = 0;
				 T_Min->Text = System::Convert::ToString(D_Time->Minute);
				 T_Sec->Text = "0"+System::Convert::ToString(D_Time->Second);

				 D_Order->Camera = 90;
				 D_Order->TakeBall = 0;

				 Radar_Basic(RaderCenter_x , RaderCenter_y);

				 mCamera = gcnew Camera();

				 Read_Object();
				 Rest_Request();
			 }

//! Connection Set.
/**<Client Code. */
	void waitAcceptSocket(){
		while(true)
		{
			int byteNum=0;
			array<unsigned char> ^recvBytes = gcnew array<unsigned char>(74460);

			FileInfo^ fg = gcnew FileInfo( "Back_Status.xml" );

			while(true)
			{
				if(ClientSocket->Connected){
					Client_already = 1;
				}else{
					Client_already = 0;
				}
					
				byteNum =ClientSocket->Receive(recvBytes,recvBytes->Length,static_cast<SocketFlags>(0)); /**< Wait Message. */
				
				//!Receive area.
				if(byteNum==0) break;
				Encoding ^encoder= Encoding::UTF8;

				if (fg->Exists)	fg->Delete();

				FileStream^ MSG_back = fg->Create();

				String ^recvstring =encoder->GetString(recvBytes,0,byteNum);

				array<Byte> ^ss = gcnew array<Byte>(byteNum);
				int i;

				for(i=0; i < byteNum ; i++) ss[i] = recvBytes[i];

				array<Byte>^info = ss ;
				MSG_back->Write( ss, 0, ss->Length );

				MSG_back->Close();

				Read_Status();

				/*MSG_Str = recvstring;
				Thread ^setTextThread =gcnew Thread(gcnew ThreadStart(this,&Form1::ThreadProcSafe));
				setTextThread->Start();*/
			}
			ClientSocket->Close();
			System::Diagnostics::Debug::WriteLine("Form1::waitAcceptSocket");
		}
	}
//!Client Set.
	void establishSendSocket(){
		try{
			IPAddress ^hostAddr = IPAddress::Parse(IP_box->Text);

			IPEndPoint ^host = gcnew IPEndPoint(hostAddr, System::Convert::ToInt32(Client_box->Text));
			ClientSocket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

			ClientSocket->Connect(host);
			System::Diagnostics::Debug::WriteLine("successfully't connect to echo server");
		}catch(SocketException^){}
	}
	private: System::Void Client_set_Click(System::Object^  sender, System::EventArgs^  e) {
				 establishSendSocket();
				 backgroundWorker2->RunWorkerAsync();
				 
				 timer2->Start();
				 timer3->Start();
			 }
	private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				 waitAcceptSocket();
			 }
/**View Message. */
	void ThreadProcSafe()
	{
		if (MSG_list->InvokeRequired){
			SetTextDelegate^ d = gcnew SetTextDelegate(this, &Form1::ThreadProcSafe);
			this->Invoke(d, gcnew array<Object^> { });
		}
		else{
			this->MSG_list->Items->Add( "Recive: " + MSG_Str + "\r\n");
			MSG_list->SelectedIndex = MSG_list->Items->Count-1;
		}
	}



//!Furniture Xml.
		void Read_Object(){
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Robot_Config.xml");
			XmlNode^ Manual = doc->SelectSingleNode("/Config/DirectionObject");

			for(int i =0 ;i < Manual->ChildNodes->Count;i++){
				XmlNode^ node = Manual->ChildNodes[i];
				XmlElement^ element=(XmlElement^)node;
				if(element->Name =="LivingRM_Sofa"){
					D_Furniture->M_LivingRM.Sofa.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_LivingRM.Sofa.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_LivingRM.Sofa.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_LivingRM.Sofa.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_LivingRM.Sofa.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="LivingRM_Table"){
					D_Furniture->M_LivingRM.Table.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_LivingRM.Table.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_LivingRM.Table.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_LivingRM.Table.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_LivingRM.Table.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="LivingRM_Cabinet"){
					D_Furniture->M_LivingRM.Cabinet.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_LivingRM.Cabinet.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_LivingRM.Cabinet.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_LivingRM.Cabinet.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_LivingRM.Cabinet.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="DiningRM_Table"){
					D_Furniture->M_DiningRM.Table.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_DiningRM.Table.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_DiningRM.Table.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_DiningRM.Table.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_DiningRM.Table.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="DiningRM_Chair"){
					D_Furniture->M_DiningRM.Chair.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_DiningRM.Chair.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_DiningRM.Chair.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_DiningRM.Chair.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_DiningRM.Chair.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="Library_Desk"){
					D_Furniture->M_Library.Desk.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_Library.Desk.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_Library.Desk.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_Library.Desk.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_Library.Desk.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="Library_Chair"){
					D_Furniture->M_Library.Chair.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_Library.Chair.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_Library.Chair.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_Library.Chair.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_Library.Chair.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="Library_Cabinet"){
					D_Furniture->M_Library.Cabinet.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_Library.Cabinet.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_Library.Cabinet.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_Library.Cabinet.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_Library.Cabinet.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="BedRM_Bed"){
					D_Furniture->M_BedRM.Bed.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_BedRM.Bed.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_BedRM.Bed.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_BedRM.Bed.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_BedRM.Bed.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="DiningRM_door"){
					D_Furniture->M_DiningRM.door.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_DiningRM.door.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_DiningRM.door.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_DiningRM.door.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_DiningRM.door.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="BedRM_door"){
					D_Furniture->M_BedRM.door.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_BedRM.door.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_BedRM.door.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_BedRM.door.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_BedRM.door.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="ChargeArea"){
					D_Furniture->M_ChargeArea.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_ChargeArea.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_ChargeArea.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_ChargeArea.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_ChargeArea.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="EndArea"){
					D_Furniture->M_EndArea.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_EndArea.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_EndArea.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_EndArea.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_EndArea.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}
			}
		}
		void Rest_Request(){
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Robot_Request.xml");
			XmlNode^ Manual = doc->SelectSingleNode("/Request"); //選擇節點
			Manual->RemoveAll();
			doc->Save("Robot_Request.xml");
		}

//!Callback Status Xml.
public:	void Read_Status(){
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Back_Status.xml");
			XmlNode^ Manual = doc->SelectSingleNode("/Status");
			if(Manual!=nullptr){
				for(int i=0;i < Manual->ChildNodes->Count;i++){
					XmlNode^ Manual2 = Manual->ChildNodes[i];
					XmlElement^ element=(XmlElement^)Manual2;
					if(element->Name == "Movement"){
						R_Robot->X= System::Convert::ToDouble(element->GetAttribute("x"));
						R_Robot->Y= System::Convert::ToDouble(element->GetAttribute("y"));
						R_Robot->Radian= System::Convert::ToDouble(element->GetAttribute("sita"));
					}else if (element->Name == "Laser"){
						for(int i=0;i<element->ChildNodes->Count;i++){
							XmlNode^ b = element->ChildNodes[i];
							XmlElement^ a = (XmlElement^) b;

							R_Laser[i].Angle = 90-(2.5*i);
							R_Laser[i].Distance = System::Convert::ToDouble(a->GetAttribute("d")) / 10;
						}
					}else if(element->Name == "Position"){
						R_Position->x= System::Convert::ToDouble(element->GetAttribute("x"));
						R_Position->y= System::Convert::ToDouble(element->GetAttribute("y"));
						R_Position->ang= System::Convert::ToDouble(element->GetAttribute("sita"))*180/PI;
					}else if(element->Name == "Camera_Angle"){
						R_Robot->Camera_Angle = System::Convert::ToDouble(element->GetAttribute("ang"));
					}
				}
			}
		}

//!Command Xml.
public:	void Write_Robot(){
			double Unit_x,Unit_y;

			if(D_Touch->X > Rader_Radius){	Unit_x = 1;}
			else if(D_Touch->X < -1*Rader_Radius){	Unit_x = -1;}
			else{	Unit_x = D_Touch->X / Rader_Radius;}
		
			if(D_Touch->Y > Rader_Radius){	Unit_y = 1;}
			else if(D_Touch->Y < -1*Rader_Radius){	Unit_y = -1;}
			else{	Unit_y = D_Touch->Y / Rader_Radius;}

		
			if(D_mos->Right == 0){
				D_Touch->Radian = 0;
			}else{
				Unit_x = 0;
				Unit_y = 0;
			}
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Robot_Command.xml");
			XmlNode^ Manual = doc->SelectSingleNode("/Command/ManualDirection"); //選擇節點

			int Sim_t=0;

			for(int i =0 ;i < Manual->ChildNodes->Count;i++){
				XmlNode^ node = Manual->ChildNodes[i];
				XmlElement^ element=(XmlElement^)node;
				if(element->Name == "Vector"){
					element->SetAttribute("x",System::Convert::ToString(Unit_x * Speed_Bar->Value));
					element->SetAttribute("y",System::Convert::ToString(Unit_y * Speed_Bar->Value));
				}else if(element->Name == "Rotate"){
					element->SetAttribute("w",System::Convert::ToString(D_Touch->Radian));
				}else if(element->Name == "Camera"){
					element->SetAttribute("ang",System::Convert::ToString(D_Order->Camera));
				}else if(element->Name == "TakeBall"){
					element->SetAttribute("ballFlag",System::Convert::ToString(D_Order->TakeBall));
				}else if(element->Name == "Sim_flag"){
					Sim_t = 1;
				}
			}

			if(Auto_check->Checked){
				if(Sim_t==0){
					XmlElement^ Distance = doc->CreateElement("Sim_flag");
					Manual->AppendChild(Distance);
				}
			}else{
				if(Sim_t==1)	Manual->RemoveChild(Manual->SelectSingleNode("Sim_flag"));
			}


			doc->Save("Robot_Command.xml");
			if(Map_check->Checked){
				D_Order->X = Unit_x * Speed_Bar->Value;
				D_Order->Y = Unit_y * Speed_Bar->Value;
				D_Order->Radian = D_Touch->Radian;
				mMap->drawRobot();
			}
		}
public:	void Read_Robot(){
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Robot_Command.xml");
			XmlNode^ Manual = doc->SelectSingleNode("/Command/ManualDirection");

			for(int i =0 ;i < Manual->ChildNodes->Count;i++){
				XmlNode^ node = Manual->ChildNodes[i];

				XmlElement^ element=(XmlElement^)node;
				if(element->Name == "Vector"){
					D_Vector->X= System::Convert::ToDouble(element->GetAttribute("x"));
					D_Vector->Y= System::Convert::ToDouble(element->GetAttribute("y"));
				}else if(element->Name == "Rotate"){
					D_Vector->Radian= System::Convert::ToDouble(element->GetAttribute("w"));
				}
			}
		}

//!Ladar Drawing.
	void Radar_Basic(double x , double y){
		Pen^ blackPen = gcnew Pen(Color::Black, 3);

		mBMP  = gcnew Bitmap(Radar_Width, Radar_Height); //背景和框繪製區
		mGraphic   = Graphics::FromImage(mBMP);
		mBMP  = gcnew Bitmap("Radar.png");
		mGraphic   = Graphics::FromImage(mBMP);
		drawPoint(x -2,y -2);
		mGraphic->DrawLine(blackPen , (int)RaderCenter_x , (int)RaderCenter_y , (int)x , (int)y);
		
	}
/**<Red Point. */
	private: void drawPoint(double x , double y){
				 Pen^ redPen = gcnew Pen(Color::Red, 6);
				 mGraphic->DrawEllipse(redPen,x,y,3,3);
				 drawPB->Image = mBMP;
			 }
/**<ArcInt. */
	private: void DrawArcInt(double length,double ang){
			Pen^ blackPen = gcnew Pen( Color::Black,3 );		/**<Black Pen. */
			SolidBrush^ skyblueBrush = gcnew SolidBrush( Color::SkyBlue );

			double x = RaderCenter_x-length;
			double y = RaderCenter_y-length;
			double width = length+length;
			double height = length+length;

			double startAngle = 270;

			while(ang>180)ang = ang - 360;
			while(ang<-180)ang = ang + 360;
			double sweepAngle = ang;
			if(width>0 && height>0){
				mGraphic->FillPie(skyblueBrush,(int)x,(int)y,(int) width,(int)height,(int) startAngle,(int) sweepAngle );
				mGraphic->DrawArc(blackPen,(int)x,(int)y,(int) width,(int)height,(int) startAngle,(int) sweepAngle );
			}
			
			drawPB->Image = mBMP;
		}

//! Control and Send.
public:	void send(){
			if(Client_already){
				fileName = "Robot_Command.xml";
				ClientSocket->SendFile(fileName);
			}
		
			MSG_list->Items->Add( "Robot"+ "\r\n");
			MSG_list->Items->Add( "user_x : " + (int)D_Vector->X + "\r\n");
			MSG_list->Items->Add( "user_y : " + (int)D_Vector->Y + "\r\n");
			MSG_list->Items->Add( "user_tar : " + (int)D_Vector->Radian + "\r\n");
			MSG_list->Items->Add( "user_Came : " + (int)D_Order->Camera + "\r\n");
			MSG_list->Items->Add( "user_TakeBall : " + (int)D_Order->TakeBall + "\r\n");

			MSG_list->SelectedIndex = MSG_list->Items->Count-1;   //跟隨卷軸往下
			//MSG_list->TopIndex = MSG_list->Items->Count-1;		//跟隨卷軸往下(2)
		}
	private: System::Void Down_sd_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = 0;
			 D_Touch->Y = Rader_Radius/-10;
			 D_Touch->Radian = 0;
			 D_mos->Right = 0;
			 Write_Robot();
			 Read_Robot();
			 send();
		 }
	private: System::Void Up_sd_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = 0;
			 D_Touch->Y = Rader_Radius/10;
			 D_Touch->Radian = 0;
			 D_mos->Right = 0;
			 Write_Robot();
			 Read_Robot();
			 send();
		 }
	private: System::Void Left_sd_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = Rader_Radius/-10;
			 D_Touch->Y = 0;
			 D_Touch->Radian = 0;
			 D_mos->Right = 0;
			 Write_Robot();
			 Read_Robot();
			 send();
		 }
	private: System::Void Right_sd_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = Rader_Radius/10;
			 D_Touch->Y = 0;
			 D_Touch->Radian = 0;
			 D_mos->Right = 0;
			 Write_Robot();
			 Read_Robot();
			 send();
		 }
	private: System::Void R_b_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = 0;
			 D_Touch->Y = 0;
			 D_Touch->Radian = 10*PI/180;
			 D_mos->Right = 1;
			 Write_Robot();
			 Read_Robot();
			 send();
		 }
	private: System::Void L_b_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = 0;
			 D_Touch->Y = 0;
			 D_Touch->Radian = -10*PI/180;
			 D_mos->Right = 1;
			 Write_Robot();
			 Read_Robot();
			 send();
		 }
	void drawPB_mos(System::Windows::Forms::MouseEventArgs^  e){
		D_mos->X = e->X;
		D_mos->Y = e->Y;
		D_mos->Right = 0;

		D_Touch->X = D_mos->X - RaderCenter_x;
		D_Touch->Y = RaderCenter_y - D_mos->Y;
		D_Touch->Length = sqrt(pow(D_Touch->X,2)+pow(D_Touch->Y,2));
		D_Touch->Radian = atan2(D_Touch->X,D_Touch->Y);			//弧度
		D_Touch->Angle = D_Touch->Radian*180/PI;				//角度

		if(D_mos->Touch == 0){
			Radar_Basic(RaderCenter_x , RaderCenter_y);
		}else if(D_mos->Touch == 1){
			if(D_Touch->Length < Rader_Radius){
				Radar_Basic(D_mos->X , D_mos->Y);

				if(e->Button == System::Windows::Forms::MouseButtons::Right){
					DrawArcInt(D_Touch->Length,D_Touch->Angle);
					D_mos->Right = 1;
				}
			}else{
				double x_Bor;		//雷達邊界x
				double y_Bor;		//雷達邊界y

				x_Bor = RaderCenter_x + Rader_Radius*sin(D_Touch->Radian);
				y_Bor = RaderCenter_y - Rader_Radius*cos(D_Touch->Radian);

				Radar_Basic(x_Bor , y_Bor);

				D_Touch->X = x_Bor - RaderCenter_x;
				D_Touch->Y = RaderCenter_y - y_Bor;

				double Radian_Bor = atan2(D_Touch->X , D_Touch->Y);			//弧度
				double Angle = Radian_Bor*180/PI;				//角度

				if(e->Button == System::Windows::Forms::MouseButtons::Right){
					DrawArcInt(Rader_Radius,Angle);
					D_Touch->Radian = Radian_Bor;
					D_mos->Right = 1;
				}
			}
			Write_Robot();
			Read_Robot();
			send();
		}
	}
	private: System::Void drawPB_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(D_mos->Touch == 0)	 Radar_Basic(RaderCenter_x , RaderCenter_y);
			 else if(D_mos->Touch == 1)  drawPB_mos(e);
		 }
	private: System::Void drawPB_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 D_mos->Touch = 1;									//確認滑鼠按下
			 drawPB_mos(e);
		 }
	private: System::Void drawPB_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 D_mos->Touch = 0;
			 D_mos->Right = 0;
			 D_Touch->X = 0;
			 D_Touch->Y = 0;
			 D_Touch->Radian = 0;
			 Write_Robot();
			 Read_Robot();
			 send();
		 }
	private: System::Void Speed_Bar_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
			 Speed_lab->Text = System::Convert::ToString(Speed_Bar->Value);
		 }

//! Form Area
private: System::Void Map_set_Click(System::Object^  sender, System::EventArgs^  e) {
			 mMap = gcnew Map();
			 mMap->Show();
		 }
private: System::Void visonToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 mVision = gcnew PureModelForm::MainForm();
			 mVision->Show();
		 }
///////////////////////////回傳控制區/////////////////////////////////////
private: System::Void laserToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 mLaser = gcnew Laser();
			 mLaser->Show();
		 }
private: System::Void furnitureToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 mFurniture = gcnew Furniture();
			 mFurniture->Show();
		 }
private: System::Void CameraToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(mCamera==nullptr){
				mCamera = gcnew Camera();
			 }
			 mCamera->Show();
		 }
private: System::Void mapEditerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(mMapEditer==nullptr){
				 mMapEditer = gcnew MapEditer();
			 }
			 mMapEditer->Show();
		 }

private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(Client_already){
				 if (Call_back->Checked){
					 fileName = "Robot_Request.xml";
					 ClientSocket->SendFile(fileName);
				 }
				 if (Auto_check->Checked){
					 fileName = "Robot_Command.xml";
					 ClientSocket->SendFile(fileName);

					 FileInfo^ fg = gcnew FileInfo("Robot_Simulator.xml");
					 FileStream^ fs = fg->OpenRead();

					 if(fs->CanRead){
						 fs->Close();
						 fileName = "Robot_Simulator.xml";
						 ClientSocket->SendFile(fileName);
					 }
					 
					 D_Order->X = R_Robot->X;
					 D_Order->Y = R_Robot->Y;
					 D_Order->Radian = R_Robot->Radian;
				 }
			 }
		 }
//! Timing Set
private: System::Void T_Stop_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(timer2->Enabled)
			 timer2->Stop();
			 else
			 timer2->Start();
		 }
private: System::Void T_Reset_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Time->Minute = 10;
			 D_Time->Second = 0;
			 T_Min->Text = System::Convert::ToString(D_Time->Minute);
			 T_Sec->Text = "0"+System::Convert::ToString(D_Time->Second);
		 }
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(Client_already){
				 if(D_Time->Second == 0){
					 if(D_Time->Minute == 0){
						 D_Time->Minute = 10;
						 D_Time->Second = 0;
					 }
					 D_Time->Minute -= 1;
					 D_Time->Second = 59;
				 }else{
					 D_Time->Second -= 1;
				 }
			 }
			 if(D_Time->Minute<10)	 T_Min->Text = "0"+System::Convert::ToString(D_Time->Minute);
			 else T_Min->Text = System::Convert::ToString(D_Time->Minute);
			 if(D_Time->Second<10)	 T_Sec->Text = "0"+System::Convert::ToString(D_Time->Second);
			 else T_Sec->Text = System::Convert::ToString(D_Time->Second);
		 }

//////////////////////////收放球區////////////////////////////////////////
private: System::Void TakeBall_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(e->Button == System::Windows::Forms::MouseButtons::Right){
				 TakeBall->BackColor = System::Drawing::Color::SpringGreen;
				 TakeBall->Text = "Put";
				 D_Order->TakeBall = 2;
			 }else{
				 TakeBall->BackColor = System::Drawing::Color::DeepPink;
				 TakeBall->Text = "Take";
				 D_Order->TakeBall = 1;
			 }
			 Write_Robot();
			 Read_Robot();
			 send();
		 }
private: System::Void TakeBall_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 TakeBall->BackColor = System::Drawing::Color::White;
			 D_Order->TakeBall = 0;
			 TakeBall->Text = "Ball";
		 	 Write_Robot();
			 Read_Robot();
			 send();
		 }

/////////////////////////攝影機控制///////////////////////////////////////
private: System::Void Cam_Bar_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
			 Cam_lab->Text = System::Convert::ToString(Cam_Bar->Value)+"°";
			 D_Order->Camera = Cam_Bar->Value;
			 Write_Robot();
			 Read_Robot();
			 send();
			 mCamera->Rotate_Camera(D_Order->Camera);
		 }

private: System::Void Auto_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 Write_Robot();
		 }

private: System::Void Send_Config_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(Client_already){
				 fileName = "Robot_ReloadConfig.xml";
				 ClientSocket->SendFile(fileName);
			 }
		 }
};
}

