#pragma once
#include "LevelController.h"
#include <iostream>
namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmLevel1
	/// </summary>
	public ref class FrmLevel1 : public System::Windows::Forms::Form
	{
	public:
		FrmLevel1(Character* character,char* route_character)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			srand(time(NULL));
			btn_exit->UseVisualStyleBackColor = false;
			btn_exit->FlatStyle = FlatStyle::Flat;
			btn_exit->FlatAppearance->BorderSize = 0;
			btn_reset->UseVisualStyleBackColor = false;
			btn_reset->FlatStyle = FlatStyle::Flat;
			btn_reset->FlatAppearance->BorderSize = 0;
			btn_return->UseVisualStyleBackColor = false;
			btn_return->FlatStyle = FlatStyle::Flat;
			btn_return->FlatAppearance->BorderSize = 0;
			this->KeyPreview = true;          
			pnl_game->TabStop = true;         
			btn_exit->TabStop = false;        
			btn_reset->TabStop = false;
			counter = 0;
			KeyBlueFox = Direction::None;
			lvl1 = new LevelController(pnl_game->Width, pnl_game->Height, pnl_dialogue->Width, pnl_dialogue->Height,character);
			lvl1->getCharacter()->LoadImage(route_character, 4, 4);
			tipo_dialogo = 0;
			questioninprogress = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmLevel1()
		{
			if (components)
			{
				delete components;
				delete lvl1;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;



	protected:

	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		LevelController* lvl1;
		Direction KeyBlueFox;
		int tipo_dialogo;
		bool questioninprogress;
		int counter;
	private: System::Windows::Forms::Label^ lbl_dialogue;
	private: System::Windows::Forms::Panel^ pnl_game;
	private: System::Windows::Forms::Label^ lbl_timer_resource;
	private: System::Windows::Forms::Label^ lbl_rflquestion;
	private: System::Windows::Forms::Button^ btn_exit;
	private: System::Windows::Forms::Button^ btn_reset;
	private: System::Windows::Forms::Label^ lbl_health;
	private: System::Windows::Forms::Button^ btn_return;
	private: System::Windows::Forms::Label^ lbl_confidence;
	private: System::Windows::Forms::Label^ lbl_points;





	private: System::Windows::Forms::Panel^ pnl_dialogue;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_dialogue = (gcnew System::Windows::Forms::Label());
			this->pnl_dialogue = (gcnew System::Windows::Forms::Panel());
			this->pnl_game = (gcnew System::Windows::Forms::Panel());
			this->lbl_points = (gcnew System::Windows::Forms::Label());
			this->lbl_timer_resource = (gcnew System::Windows::Forms::Label());
			this->lbl_health = (gcnew System::Windows::Forms::Label());
			this->lbl_confidence = (gcnew System::Windows::Forms::Label());
			this->btn_return = (gcnew System::Windows::Forms::Button());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->lbl_rflquestion = (gcnew System::Windows::Forms::Label());
			this->pnl_game->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmLevel1::timer1_Tick);
			// 
			// lbl_dialogue
			// 
			this->lbl_dialogue->BackColor = System::Drawing::Color::Gray;
			this->lbl_dialogue->Font = (gcnew System::Drawing::Font(L"Cambria", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_dialogue->ForeColor = System::Drawing::Color::Red;
			this->lbl_dialogue->Location = System::Drawing::Point(177, 527);
			this->lbl_dialogue->Name = L"lbl_dialogue";
			this->lbl_dialogue->Size = System::Drawing::Size(1251, 155);
			this->lbl_dialogue->TabIndex = 0;
			this->lbl_dialogue->Visible = false;
			this->lbl_dialogue->Click += gcnew System::EventHandler(this, &FrmLevel1::label1_Click);
			// 
			// pnl_dialogue
			// 
			this->pnl_dialogue->BackColor = System::Drawing::Color::Black;
			this->pnl_dialogue->Location = System::Drawing::Point(12, 528);
			this->pnl_dialogue->Name = L"pnl_dialogue";
			this->pnl_dialogue->Size = System::Drawing::Size(153, 154);
			this->pnl_dialogue->TabIndex = 1;
			this->pnl_dialogue->Visible = false;
			this->pnl_dialogue->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmLevel1::pnl_dialogue_Paint);
			// 
			// pnl_game
			// 
			this->pnl_game->Controls->Add(this->lbl_points);
			this->pnl_game->Controls->Add(this->lbl_timer_resource);
			this->pnl_game->Controls->Add(this->lbl_health);
			this->pnl_game->Controls->Add(this->lbl_confidence);
			this->pnl_game->Controls->Add(this->btn_return);
			this->pnl_game->Controls->Add(this->btn_reset);
			this->pnl_game->Controls->Add(this->btn_exit);
			this->pnl_game->Controls->Add(this->lbl_rflquestion);
			this->pnl_game->Location = System::Drawing::Point(-2, 0);
			this->pnl_game->Name = L"pnl_game";
			this->pnl_game->Size = System::Drawing::Size(1445, 705);
			this->pnl_game->TabIndex = 2;
			// 
			// lbl_points
			// 
			this->lbl_points->AutoSize = true;
			this->lbl_points->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_points->Location = System::Drawing::Point(433, 9);
			this->lbl_points->Name = L"lbl_points";
			this->lbl_points->Size = System::Drawing::Size(53, 20);
			this->lbl_points->TabIndex = 6;
			this->lbl_points->Text = L"label1";
			// 
			// lbl_timer_resource
			// 
			this->lbl_timer_resource->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_timer_resource->Location = System::Drawing::Point(1203, 9);
			this->lbl_timer_resource->Name = L"lbl_timer_resource";
			this->lbl_timer_resource->Size = System::Drawing::Size(227, 30);
			this->lbl_timer_resource->TabIndex = 3;
			// 
			// lbl_health
			// 
			this->lbl_health->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_health->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_health->Location = System::Drawing::Point(883, 9);
			this->lbl_health->Name = L"lbl_health";
			this->lbl_health->Size = System::Drawing::Size(139, 30);
			this->lbl_health->TabIndex = 4;
			this->lbl_health->Text = L"<";
			// 
			// lbl_confidence
			// 
			this->lbl_confidence->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_confidence->Location = System::Drawing::Point(14, 9);
			this->lbl_confidence->Name = L"lbl_confidence";
			this->lbl_confidence->Size = System::Drawing::Size(183, 30);
			this->lbl_confidence->TabIndex = 5;
			this->lbl_confidence->Text = L"Confidence";
			// 
			// btn_return
			// 
			this->btn_return->Enabled = false;
			this->btn_return->Location = System::Drawing::Point(516, 301);
			this->btn_return->Name = L"btn_return";
			this->btn_return->Size = System::Drawing::Size(446, 158);
			this->btn_return->TabIndex = 3;
			this->btn_return->UseVisualStyleBackColor = true;
			this->btn_return->Visible = false;
			this->btn_return->Click += gcnew System::EventHandler(this, &FrmLevel1::btn_return_Click);
			this->btn_return->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmLevel1::btn_return_Paint);
			// 
			// btn_reset
			// 
			this->btn_reset->Enabled = false;
			this->btn_reset->Location = System::Drawing::Point(860, 392);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(362, 143);
			this->btn_reset->TabIndex = 2;
			this->btn_reset->UseVisualStyleBackColor = true;
			this->btn_reset->Visible = false;
			this->btn_reset->Click += gcnew System::EventHandler(this, &FrmLevel1::button2_Click);
			this->btn_reset->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmLevel1::button2_Paint);
			// 
			// btn_exit
			// 
			this->btn_exit->Enabled = false;
			this->btn_exit->Location = System::Drawing::Point(233, 392);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(330, 143);
			this->btn_exit->TabIndex = 1;
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Visible = false;
			this->btn_exit->Click += gcnew System::EventHandler(this, &FrmLevel1::button1_Click);
			this->btn_exit->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmLevel1::button1_Paint);
			// 
			// lbl_rflquestion
			// 
			this->lbl_rflquestion->BackColor = System::Drawing::Color::Black;
			this->lbl_rflquestion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_rflquestion->ForeColor = System::Drawing::Color::White;
			this->lbl_rflquestion->Location = System::Drawing::Point(339, 172);
			this->lbl_rflquestion->Name = L"lbl_rflquestion";
			this->lbl_rflquestion->Size = System::Drawing::Size(786, 156);
			this->lbl_rflquestion->TabIndex = 0;
			// 
			// FrmLevel1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1440, 694);
			this->Controls->Add(this->pnl_dialogue);
			this->Controls->Add(this->lbl_dialogue);
			this->Controls->Add(this->pnl_game);
			this->Name = L"FrmLevel1";
			this->Text = L"FrmLevel1";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmLevel1::FrmLevel1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmLevel1::FrmLevel1_KeyUp);
			this->pnl_game->ResumeLayout(false);
			this->pnl_game->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ canvas = pnl_game->CreateGraphics();
		BufferedGraphicsContext^ buffer_area = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = buffer_area->Allocate(canvas, pnl_game->ClientRectangle);
		lbl_health->Text = "HEALTH: " + lvl1->getCharacter()->getHealth();
		lbl_timer_resource->Text = "RESOURCE TIMER: "+lvl1->getTimeResourcePick().ToString() + " s";
		lbl_confidence->Text = "CONFIDENCE: "+lvl1->getConfidence().ToString();
		lbl_points->Text = "POINTS: "+lvl1->getCharacter()->getPoints().ToString();
		if (lvl1->VerifyWin()) {
			lvl1->ClearVectors();
			btn_return->Visible = true;
			btn_return->Enabled = true;
			pnl_dialogue->Visible = false;
			lbl_dialogue->Visible = false;
		}
		if (lvl1->VerifyLost()) {
			lvl1->ClearVectors();
			btn_exit->Enabled = true;
			btn_reset->Enabled = true;
			btn_reset->Visible = true;
			btn_exit->Visible = true;
			pnl_dialogue->Visible = false;
			lbl_dialogue->Visible = false;
		}
		if (lvl1->UpdateScreen(buffer->Graphics)) {
			if (!lbl_rflquestion->Visible)lbl_rflquestion->Visible = true;
			lbl_rflquestion->Text = gcnew String(lvl1->getReflexiveQuestion().c_str());
			buffer->Render(canvas);
			return;
		}
		else {
			if (lbl_rflquestion->Visible)lbl_rflquestion->Visible = false;
		}
		lvl1->StartLevel(pnl_dialogue->Width,pnl_dialogue->Height);
		lvl1->UpdateGame();
		lvl1->ClearElements();
		if (!lbl_dialogue->Visible && !pnl_dialogue->Visible) {
			bool Collision1 = lvl1->ColotionPlayerEnemies();
			bool Collision2 = lvl1->CollisionPlayerCriticResources();
			bool Collision3 = lvl1->CollisionPlayerHelpfulResources();
			bool Collision4 = lvl1->BulletsCollisionsPlayer();
			bool Collision5 = lvl1->CollisionPlayerAlly();
			if (dynamic_cast<Blue_Fox_Character*>(lvl1->getCharacter())) {
				lbl_dialogue->ForeColor = Color::Red;
			}
			else lbl_dialogue->ForeColor = Color::Cyan;
			if (Collision1) {
				lvl1->StarRandomDialogue(TypeDialogue::hits);
				lbl_dialogue->Visible = true;
				pnl_dialogue->Visible = true;
				tipo_dialogo = 1;
			}
			else if (Collision2) {
				lvl1->StarRandomDialogue(TypeDialogue::criticresource);
				lbl_dialogue->Visible = true;
				pnl_dialogue->Visible = true;
				tipo_dialogo = 1;
			}
			else if (Collision3) {
				lvl1->StarRandomDialogue(TypeDialogue::helpfulresource);
				lbl_dialogue->Visible = true;
				pnl_dialogue->Visible = true;
				tipo_dialogo = 1;
			}
			else if (Collision4) {
				lvl1->StarRandomDialogue(TypeDialogue::killenemy);
				lbl_dialogue->Visible = true;
				pnl_dialogue->Visible = true;
				tipo_dialogo = 1;
			}
			else if (Collision5) {
				lvl1->StarQuiz();
				questioninprogress = true;
				lbl_dialogue->Visible = true;
				pnl_dialogue->Visible = true;
				tipo_dialogo = 2;
			}
		}
		if (lvl1->getDialogueInProcess()) {
			pnl_dialogue->Invalidate();
			lvl1->UpdateDialogue();
			string currenttext = lvl1->getCurrentDialogue();
			lbl_dialogue->Text = gcnew String(currenttext.c_str());
		}
		else if (lbl_dialogue->Visible && pnl_dialogue->Visible && !lvl1->getDialogueInProcess()&&tipo_dialogo==1) {
			counter++;
			if (counter > 15) {
				counter = 0;
				lbl_dialogue->Visible = false;
				pnl_dialogue->Visible = false;
			}
			
		}
		if (lvl1->getQuestionInProcess()) {
			pnl_dialogue->Invalidate();
			lvl1->UpdateQuestion();
			string currenttext = lvl1->getCurrentQuestion();
			lbl_dialogue->Text = gcnew String(currenttext.c_str());
		}
		else if (lbl_dialogue->Visible && pnl_dialogue->Visible && !lvl1->getQuestionInProcess()&&tipo_dialogo==2) {
			if (!questioninprogress) {
				lbl_dialogue->Visible = false;
				pnl_dialogue->Visible = false;
			}
		}
		lvl1->BulletsCollisionsPlayer();
		lvl1->BulletsCollisionsEnemies();
		lvl1->ColotionPlayerEnemies();
		lvl1->MoveAll(KeyBlueFox);

		lvl1->DrawAll(buffer->Graphics);
		buffer->Render(canvas);

		delete canvas;
		delete buffer;
	}

	private: System::Void FrmLevel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		e->SuppressKeyPress = true; 
		e->Handled = true;
		switch (e->KeyCode) {
		case Keys::Up: {
			KeyBlueFox = Direction::Up; break;
		}
		case Keys::Down: {
			KeyBlueFox = Direction::Down; break;
		}
		case Keys::Left: {
			KeyBlueFox = Direction::Left; break;
		}
		case Keys::Right: {
			KeyBlueFox = Direction::Right; break;
		}
		case Keys::F: {
			Character* player = lvl1->getCharacter();
			Bullet* temp = new Bullet(lvl1->getCharacter()->getX(), lvl1->getCharacter()->getY(), 
				Team::Characters, lvl1->getCharacter()->getLaskey(),lvl1->getCharacter()->getWidth(), lvl1->getCharacter()->getHeight(),1,1);
			lvl1->addBullet(temp);
			if(dynamic_cast<Blue_Fox_Character*>(player))lvl1->LoadBullet("Images\\BlueCharacterBullet.png", temp);
			else if(dynamic_cast<Black_Fox_Character*>(player))lvl1->LoadBullet("Images\\RedCharacterBullet.png", temp);
			break;
		}
		case Keys::S: {
			lvl1->SaveGame();
			break;
		}
		case Keys::L: {
			lvl1->LoadGame();
			break;
		}
		case Keys::D1: {
			if (lvl1->getAnswerCorrect(0))questioninprogress = false;
			break;
		}
		case Keys::D2: {
			if (lvl1->getAnswerCorrect(1))questioninprogress = false;
			break;
		}
		case Keys::D3: {
			if (lvl1->getAnswerCorrect(2))questioninprogress = false;
			break;
		}
		case Keys::D4: {
			if (lvl1->getAnswerCorrect(3))questioninprogress = false;
			break;
		}
		}
	}
	private: System::Void FrmLevel1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		KeyBlueFox = Direction::None;
	}
	private: System::Void Panel_lvl1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}

	private: System::Void pnl_dialogue_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		btn_exit->Enabled = false;
		btn_reset->Enabled = false;
		btn_reset->Visible = false;
		btn_exit->Visible = false;
		e->Graphics->Clear(Color::Black);
		lvl1->DrawCommentor(e->Graphics);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		btn_exit->Enabled = false;
		btn_reset->Enabled = false;
		btn_reset->Visible = false;
		btn_exit->Visible = false;
		lvl1->setPass(true);
		lvl1->setInLost(false);
		lvl1->StartLevel(pnl_dialogue->Width, pnl_dialogue->Height);
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	btn_exit->Enabled = false;
	btn_reset->Enabled = false;
	btn_reset->Visible = false;
	btn_exit->Visible = false;
	this->Close();
}
private: System::Void button1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Bitmap^ bmp = gcnew Bitmap("Images\\Exit_Butoom.jpg");
	e->Graphics->DrawImage(bmp, 0, 0, btn_exit->Width, btn_exit->Height);
	delete bmp;
}
private: System::Void button2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Bitmap^ bmp = gcnew Bitmap("Images\\ResetButtom.png");
	e->Graphics->DrawImage(bmp, 0, 0, btn_reset->Width, btn_reset->Height);
	delete bmp;
}
private: System::Void btn_return_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btn_return_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Bitmap^ bmp = gcnew Bitmap("Images\\return_buttom.jpg");
	e->Graphics->DrawImage(bmp, 0, 0, btn_return->Width, btn_return->Height);
	delete bmp;
}
};
}
