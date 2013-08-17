#pragma once
#include "../ImageData/TImageData.h"
#include "../Tools/ColorFunctionUnit.h"

#include "../ModelForm/ModelForm.h"
#include <math.h>
#include "../Database.h"

namespace PureModelForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Net::Sockets;

	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// PreviewForm 的摘要
	/// </summary>
	public ref class PreviewForm : public System::Windows::Forms::Form
	{
	public:
		PreviewForm(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			//this->Width = ImageData->ImageWidth;
			//this->Height = ImageData->ImageHeight;
			mWidth = ImageData->ImageWidth+10;
			mHeight = ImageData->ImageHeight+30;
			//實際測試後最佳值，在640*480條件下
			this->Width=mWidth;
			this->Height=mHeight;


			//this->MaximumSize.Width = mWidth;
			//this->MaximumSize.Height = mHeight;



			previewPB->Width = ImageData->ImageWidth;
			System::Diagnostics::Debug::WriteLine("ImageData->ImageWidth="+ImageData->ImageWidth+",ImageData->ImageHeight="+ImageData->ImageHeight);
			previewPB->Height = ImageData->ImageHeight;

			if(DispImage==NULL)		DispImage = new unsigned char[3 * ImageData->ImageWidth	* ImageData->ImageHeight];


			System::EventArgs ^e ;
			//loadImageFromPath("I:\\ImageTeam\\FIRA2013\\Debug\\DistancePic\\1.bmp");
			//loadImageFromPath("1.jpg");
		
		}

		void DisplayImage(unsigned char *inImageData){
			//if(DispRGB->Checked)
			//{
			unsigned char yValue, iValue, qValue;
			unsigned char *DataPoint, *inDataPoint;

			DataPoint = DispImage;
			inDataPoint = inImageData;
			for(int i=0 ; i<ImageData->ImageWidth ; i++)
			{
				for(int j=0 ; j<ImageData->ImageHeight ; j++)
				{
					qValue = *inDataPoint++;
					iValue = *inDataPoint++;
					yValue = *inDataPoint++;

					*DataPoint++ = ColorTransform->BofYUVtoRGB(yValue, iValue, qValue);
					*DataPoint++ = ColorTransform->GofYUVtoRGB(yValue, iValue, qValue);
					*DataPoint++ = ColorTransform->RofYUVtoRGB(yValue, iValue, qValue);
				}
			}
			IntPtr pt1(DispImage);

			mBitmap = gcnew Bitmap(ImageData->ImageWidth, ImageData->ImageHeight, ImageData->ImageWidth*3,Drawing::Imaging::PixelFormat::Format24bppRgb,pt1);
			previewPB->Image = mBitmap;
			Server_ch=1;
		}

		/*
		void __fastcall TPreviewForm::SetPixels(unsigned char *byArray)
		{
			HDC hdc = GetDC(Handle);
			static HBITMAP nhBmp = bitmap->Handle;
			static HBITMAP ohBmp = SelectObject(hdc, nhBmp);
			SetDIBits(hdc, nhBmp, 0, bmi->bmiHeader.biHeight, byArray
				, bmi, DIB_RGB_COLORS);
			SelectObject(hdc, ohBmp);
			ReleaseDC(Handle, hdc);
		}*/



	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~PreviewForm()
		{
			if (components)
			{
				delete components;
			}

			 delete[] DispImage;

		}
	private: System::Windows::Forms::PictureBox^  previewPB;
	private: System::ComponentModel::IContainer^  components;

	private: System::Windows::Forms::Timer^  mainFormTimer;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		
		Bitmap^ mBitmap;
		unsigned char *DispImage;
		int mWidth ;


		 int mHeight ;
		 unsigned char* bmpImage;

		 bool CallbackBuffer;


		 ModelForm^ mModelForm;

		 void loadImageFromPath(Image^ fName){

			 Bitmap^ bitmap = gcnew Bitmap(fName,640,480);
			 //previewPB->Image = bitmap;

			 /*if(bitmap->Height != ImageData->ImageHeight
				 || bitmap->Width != ImageData->ImageWidth){
					 MessageBox::Show("Open File Width or Height not fit!!");
			 }else{*/
				 unsigned char *tmpHere;
				 unsigned char rValue, gValue, bValue;

				 if(bmpImage == NULL)
					 bmpImage = new unsigned char[3 * ImageData->ImageHeight* ImageData->ImageWidth];

				 System::Drawing::Rectangle rect =  System::Drawing::Rectangle(0,0,bitmap->Width,bitmap->Height);
				 //System::Drawing::Rectangle rect =  System::Drawing::Rectangle(0,0,bitmap->Width,bitmap->Height);
				 System::Drawing::Imaging::BitmapData^ bmpData = bitmap->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadOnly, bitmap->PixelFormat );

				 IntPtr ptr = bmpData->Scan0;

				 int bytes = Math::Abs(bmpData->Stride) * bitmap->Height;

				 array<Byte> ^TempArr2=gcnew array<Byte>(bytes); 

				 System::Runtime::InteropServices::Marshal::Copy( ptr, TempArr2, 0, bytes );
				 bitmap->UnlockBits(bmpData);


				 pin_ptr<unsigned char> tPinPtr = &TempArr2[0];
				 unsigned char* tPtr = (unsigned char*)tPinPtr;

				 tmpHere = bmpImage;
				 for(int j=0 ; j<ImageData->ImageHeight ; j++)
				 {
					 for(int i=0 ; i<ImageData->ImageWidth ; i++)
					 {
						 /*bValue = *tPtr;
						 gValue = *(tPtr+1);
						 rValue = *(tPtr+2);*/
						 bValue = bitmap->GetPixel(i,j).B;
						 gValue = bitmap->GetPixel(i,j).G;
						 rValue = bitmap->GetPixel(i,j).R;


						 *tmpHere++ = ColorTransform->VofRGBtoYUV(rValue,gValue, bValue);
						 *tmpHere++ = ColorTransform->UofRGBtoYUV(rValue,gValue, bValue);
						 *tmpHere++ = ColorTransform->YofRGBtoYUV(rValue,gValue, bValue);

						 tPtr = tPtr +3;
					 }
				 }
			 //}

			 int BufferSize;
			 unsigned char *tmpOriginal, *tmpNew;
			 BufferSize = ImageData->ImageHeight * ImageData->ImageWidth;
			 tmpOriginal = bmpImage;
			 tmpNew = ImageData->pImage;
			 for(int i=0 ; i<BufferSize ; i++)
			 {
				 *tmpNew++ = *tmpOriginal++;
				 *tmpNew++ = *tmpOriginal++;
				 *tmpNew++ = *tmpOriginal++;
			 }
			 Server_check = 1;


			 
		 }

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->previewPB = (gcnew System::Windows::Forms::PictureBox());
			this->mainFormTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->previewPB))->BeginInit();
			this->SuspendLayout();
			// 
			// previewPB
			// 
			this->previewPB->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->previewPB->Location = System::Drawing::Point(0, 0);
			this->previewPB->Name = L"previewPB";
			this->previewPB->Size = System::Drawing::Size(640, 480);
			this->previewPB->TabIndex = 0;
			this->previewPB->TabStop = false;
			// 
			// mainFormTimer
			// 
			this->mainFormTimer->Interval = 200;
			this->mainFormTimer->Tick += gcnew System::EventHandler(this, &PreviewForm::mainFormTimer_Tick);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &PreviewForm::backgroundWorker1_DoWork);
			// 
			// PreviewForm
			// 
			this->ClientSize = System::Drawing::Size(646, 488);
			this->Controls->Add(this->previewPB);
			this->Name = L"PreviewForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->Text = L"Preview";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PreviewForm::PreviewForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &PreviewForm::PreviewForm_Load);
			this->Resize += gcnew System::EventHandler(this, &PreviewForm::PreviewForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->previewPB))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		int Server_check,Server_ch;
		int counter;
	private: System::Void PreviewForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 //mModelForm->Visible=false;
				 this->Hide();
				 e->Cancel = true;
			 }
	private: System::Void PreviewForm_Resize(System::Object^  sender, System::EventArgs^  e) {
				 //System::Diagnostics::Debug::WriteLine("width= " + this->Width + ",height="+this->Width);
				 this->Width = mWidth;
				 this->Height = mHeight;
			 }

private: System::Void mainFormTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 counter++;
		 }
private: System::Void modelFormBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(mModelForm==nullptr){
			 mModelForm = gcnew ModelForm();
			 }
			 mModelForm->Show();
		 }
private: System::Void PreviewForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 Server_check = 1;
			 Server_ch = 1;
			 counter = 0;
			 //loadImageFromPath("1.jpg");
			 backgroundWorker1->RunWorkerAsync();
			 mainFormTimer->Start();
			 
		 }
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 TcpListener ^myListener = gcnew TcpListener(System::Convert::ToInt32(13140));
			 myListener->Start();
			 System::Diagnostics::Debug::WriteLine("Echo Server has been establish successful");
			 System::Diagnostics::Debug::WriteLine("Waiting for client connection...");

			 while (true)
			 {
				 Socket^ ServerSocket = myListener->AcceptSocket();	//等待的變數
				 array<Byte> ^recvBytes = gcnew array<Byte>(1024);
				 array<Byte> ^jpg = gcnew array<Byte>(102400);
				 int byteNum = 0;
				 int recvByteNum = 0;
				 do {
					 byteNum = ServerSocket->Receive(recvBytes);
					 recvBytes->CopyTo(jpg, recvByteNum);
					 
					 recvByteNum += byteNum;
				 }
				 while(byteNum != 0);
				 ServerSocket->Close();
				 
				 /*bmpImage = new unsigned char[3 * ImageData->ImageHeight* ImageData->ImageWidth];
				 for(int i=0;i<recvByteNum;i++){
					 bmpImage[i] = jpg[i];
				 }*/

				 
				 /*pictureBox1->Image = Image::FromStream(kk);*/
				 //kk->Close();
				 if(Server_check==1 && Server_ch==1 && counter>10){
					MemoryStream^ kk = gcnew MemoryStream(jpg);
					counter = 0;
					Server_check = 0;
					Server_ch = 0;
					loadImageFromPath(Image::FromStream(kk));
				 }
			 }
		 }

};
}
