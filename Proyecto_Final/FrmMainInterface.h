#pragma once
#include "FrmLevel1.h"
#include "FrmCharacterPick.h"
#include "InitialMenuController.h"
#include <string>
namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMainInterface
	/// </summary>
	public ref class FrmMainInterface : public System::Windows::Forms::Form
	{
	public:
		FrmMainInterface(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			btn_play->UseVisualStyleBackColor = false;
			btn_play->FlatStyle = FlatStyle::Flat;
			btn_play->FlatAppearance->BorderSize = 0;
			btn_opt->UseVisualStyleBackColor = false;
			btn_opt->FlatStyle = FlatStyle::Flat;
			btn_opt->FlatAppearance->BorderSize = 0;
			btn_ext->UseVisualStyleBackColor = false;
			btn_ext->FlatStyle = FlatStyle::Flat;
			btn_ext->FlatAppearance->BorderSize = 0;
			initialmenu = new InitialMenuController(this->Width,this->Height);
			initialmenu->StartPersonaje(new Blue_Fox_Character(256, 256,0.2));
			route_character = "Images\\BlueCharacter.png";
			btnplayroute = "Images\\BtnPlayBackGround.png";
			btnoptionsroute = "Images\\btnOptionsBackGround.png";
			btnexitroute = "Images\\BtnExitBackGround.png";
			initialmenu->LoadBackground("Images\\MenuInitiaBackGround.jpg", this->Width,this->Height);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMainInterface()
		{
			if (components)
			{
				delete components;
				delete initialmenu;
			}
		}



	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		InitialMenuController* initialmenu;
		char* btnplayroute;
		char* btnoptionsroute;
		char* btnexitroute;
		char* route_character;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btn_play;
	private: System::Windows::Forms::Button^ btn_opt;
	private: System::Windows::Forms::Button^ btn_ext;


	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->btn_opt = (gcnew System::Windows::Forms::Button());
			this->btn_ext = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMainInterface::timer1_Tick);
			// 
			// btn_play
			// 
			this->btn_play->Location = System::Drawing::Point(209, 388);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(266, 73);
			this->btn_play->TabIndex = 1;
			this->btn_play->Text = L"Play";
			this->btn_play->UseVisualStyleBackColor = true;
			this->btn_play->Click += gcnew System::EventHandler(this, &FrmMainInterface::btn_play_Click);
			this->btn_play->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMainInterface::btn_play_Paint);
			// 
			// btn_opt
			// 
			this->btn_opt->Location = System::Drawing::Point(209, 486);
			this->btn_opt->Name = L"btn_opt";
			this->btn_opt->Size = System::Drawing::Size(266, 77);
			this->btn_opt->TabIndex = 2;
			this->btn_opt->Text = L"Options";
			this->btn_opt->UseVisualStyleBackColor = true;
			this->btn_opt->Click += gcnew System::EventHandler(this, &FrmMainInterface::btn_opt_Click);
			this->btn_opt->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMainInterface::btn_opt_Paint);
			// 
			// btn_ext
			// 
			this->btn_ext->Location = System::Drawing::Point(209, 586);
			this->btn_ext->Name = L"btn_ext";
			this->btn_ext->Size = System::Drawing::Size(266, 74);
			this->btn_ext->TabIndex = 3;
			this->btn_ext->Text = L"Exit";
			this->btn_ext->UseVisualStyleBackColor = true;
			this->btn_ext->Click += gcnew System::EventHandler(this, &FrmMainInterface::btn_ext_Click);
			this->btn_ext->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMainInterface::btn_ext_Paint);
			// 
			// FrmMainInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 663);
			this->Controls->Add(this->btn_play);
			this->Controls->Add(this->btn_ext);
			this->Controls->Add(this->btn_opt);
			this->Name = L"FrmMainInterface";
			this->Text = L"FrmMainInterface";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMainInterface::FrmMainInterface_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_play_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		FrmLevel1^ lvl1 = gcnew FrmLevel1(initialmenu->getCharacter(),route_character);
		lvl1->ShowDialog();
		this->Show();
		delete lvl1;
	}
	private: System::Void btn_opt_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		FrmCharacterPick^ char_pick = gcnew FrmCharacterPick();
		char_pick->ShowDialog();
		initialmenu->StartPersonaje(char_pick->GetRespuesta());
		route_character = char_pick->GetRuta();
		this->Show();
		delete char_pick;
	}
private: System::Void btn_ext_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void FrmMainInterface_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ canvas = CreateGraphics();
	BufferedGraphicsContext^ buffer_area = BufferedGraphicsManager::Current;
	BufferedGraphics^ buffer = buffer_area->Allocate(canvas, this->ClientRectangle);
	initialmenu->DrawAll(buffer->Graphics);
	buffer->Render(canvas);
	delete buffer;
	delete canvas;
}
private: System::Void btn_play_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	initialmenu->SetBackGroundBottom(btnplayroute, btn_play->Width, btn_play->Height, e->Graphics);
}
private: System::Void btn_opt_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	initialmenu->SetBackGroundBottom(btnoptionsroute, btn_opt->Width, btn_opt->Height, e->Graphics);
}
private: System::Void btn_ext_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	initialmenu->SetBackGroundBottom(btnexitroute, btn_ext->Width, btn_ext->Height, e->Graphics);
}
};
}
