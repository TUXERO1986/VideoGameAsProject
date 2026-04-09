#pragma once
#include "LevelController.h"
namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmCharacterPick
	/// </summary>
	public ref class FrmCharacterPick : public System::Windows::Forms::Form
	{
	public:
		FrmCharacterPick(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			character_1 = new Blue_Fox_Character(0,0,0.3);
			char AshRoute[] = "Images\\BlueCharacter.png";
			character_1->LoadImage(AshRoute, 4, 4);
			character_2 = new Black_Fox_Character(0, 0, 0.3);
			char mashRoute[] = "Images\\RedCharacter.png";
			character_2->LoadImage(mashRoute,4, 4);
			picked = new Blue_Fox_Character(256,256,1);
			route_character = "Images\\BlueCharacter.png";
		}
		Character* GetRespuesta() { return picked; }
		char* GetRuta() { return route_character; }
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmCharacterPick()
		{
			if (components)
			{
				delete character_1;
				delete character_2;
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pan_character1;
	private: System::Windows::Forms::Panel^ pan_character2;
	protected:

	protected:


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		Blue_Fox_Character* character_1;
		Black_Fox_Character* character_2;
		char* route_character;
		Character* picked;
	private: System::Windows::Forms::Button^ btn_char1;


	private: System::Windows::Forms::Button^ btn_char2;

	private: System::Windows::Forms::Timer^ timer1;
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pan_character1 = (gcnew System::Windows::Forms::Panel());
			this->pan_character2 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_char1 = (gcnew System::Windows::Forms::Button());
			this->btn_char2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// pan_character1
			// 
			this->pan_character1->BackColor = System::Drawing::Color::MediumTurquoise;
			this->pan_character1->Location = System::Drawing::Point(383, 309);
			this->pan_character1->Name = L"pan_character1";
			this->pan_character1->Size = System::Drawing::Size(136, 131);
			this->pan_character1->TabIndex = 0;
			// 
			// pan_character2
			// 
			this->pan_character2->BackColor = System::Drawing::Color::Red;
			this->pan_character2->Location = System::Drawing::Point(93, 309);
			this->pan_character2->Name = L"pan_character2";
			this->pan_character2->Size = System::Drawing::Size(128, 119);
			this->pan_character2->TabIndex = 1;
			this->pan_character2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmCharacterPick::pan_character2_Paint);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmCharacterPick::timer1_Tick);
			// 
			// btn_char1
			// 
			this->btn_char1->Location = System::Drawing::Point(381, 230);
			this->btn_char1->Name = L"btn_char1";
			this->btn_char1->Size = System::Drawing::Size(138, 59);
			this->btn_char1->TabIndex = 3;
			this->btn_char1->UseVisualStyleBackColor = true;
			this->btn_char1->Click += gcnew System::EventHandler(this, &FrmCharacterPick::btn_char1_Click);
			this->btn_char1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmCharacterPick::btn_char1_Paint);
			// 
			// btn_char2
			// 
			this->btn_char2->Location = System::Drawing::Point(93, 230);
			this->btn_char2->Name = L"btn_char2";
			this->btn_char2->Size = System::Drawing::Size(128, 59);
			this->btn_char2->TabIndex = 4;
			this->btn_char2->UseVisualStyleBackColor = true;
			this->btn_char2->Click += gcnew System::EventHandler(this, &FrmCharacterPick::btn_char2_Click);
			this->btn_char2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmCharacterPick::btn_char2_Paint);
			// 
			// FrmCharacterPick
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 531);
			this->Controls->Add(this->btn_char2);
			this->Controls->Add(this->btn_char1);
			this->Controls->Add(this->pan_character2);
			this->Controls->Add(this->pan_character1);
			this->Name = L"FrmCharacterPick";
			this->Text = L"FrmCharacterPick";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmCharacterPick::FrmCharacterPick_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		character_1->Move(Direction::Right, pan_character1->Width, pan_character1->Height);
		Graphics^ canvas1 = pan_character1->CreateGraphics();
		BufferedGraphicsContext^ Buffer_area1 = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer1 = Buffer_area1->Allocate(canvas1, pan_character1->ClientRectangle);
		buffer1->Graphics->Clear(pan_character1->BackColor);
		character_1->Draw(buffer1->Graphics);
		buffer1->Render(canvas1);
		delete canvas1;
		delete buffer1;

		character_2->Move(Direction::Right,pan_character2->Width, pan_character2->Height);
		Graphics^ canvas2 = pan_character2->CreateGraphics();
		BufferedGraphicsContext^ Buffer_area2 = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer2 = Buffer_area2->Allocate(canvas2, pan_character2->ClientRectangle);
		buffer2->Graphics->Clear(pan_character2->BackColor);
		character_2->Draw(buffer2->Graphics);
		buffer2->Render(canvas2);
		delete canvas2;
		delete buffer2;
	}
	private: System::Void pan_character2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btn_char1_Click(System::Object^ sender, System::EventArgs^ e) {
	delete picked;
	picked = new Blue_Fox_Character(256,256,0.2);
	route_character = "Images\\BlueCharacter.png";
	this->Close();
}
private: System::Void btn_char2_Click(System::Object^ sender, System::EventArgs^ e) {
	delete picked;
	picked = new Black_Fox_Character(256, 256,0.22);
	route_character = "Images\\RedCharacter.png";
	this->Close();
}
private: System::Void btn_char1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Bitmap^ bmp = gcnew Bitmap("Images\\DorianSelectCharacter.png");
	e->Graphics->DrawImage(bmp,0,0,btn_char1->Width, btn_char1->Height);
}
private: System::Void btn_char2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Bitmap^ bmp = gcnew Bitmap("Images\\Kirov_SelectCharacter.png");
	e->Graphics->DrawImage(bmp, 0, 0, btn_char2->Width, btn_char2->Height);
}
private: System::Void FrmCharacterPick_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Bitmap^ bmp = gcnew Bitmap("Images\\SelectCharacterBackground.jpg");
	e->Graphics->DrawImage(bmp, 0, 0, this->Width, this->Height);
}
};
}
