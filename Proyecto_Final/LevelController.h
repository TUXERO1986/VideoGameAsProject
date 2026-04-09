#pragma once
#include "Blue_Fox_Character.h"
#include "Black_Fox_Character.h"
#include "Enemy.h"
#include "Background.h"
#include "Bullet.h"
#include "DialogueController.h"
#include "QuestionController.h"
#include "Resource.h"
#include "Portal.h"
#include "Ally.h"
class LevelController 
{
private:
	Character* character;
	FilesManagement* filesmanagement;
	DialogueController* dialoguecontroler;
	QuestionController* questioncontroller;
	Dialogue* dialogue;
	Question* question;
	TypeWorld typeresourcepick;
	Background* background;
	Background* commentator;
	Background* loadingscreen;
	Portal* portal;
	chrono::steady_clock::time_point timerresource;
	vector<Resource*> criticresourcesvec;
	vector<Resource*> helpfulresourcesvec;
	vector<Enemy*> robotvec;
	vector<Bullet*>bulletvec;
	vector<Ally*> alliesvector;
	bool pass;
	bool resourcepick;
	bool onResourceTimer;
	int criticresources;
	int helpfulresources;
	int enemykillscounter;
	int currentlevel;
	int hitscounter;
	int PanelWidth;
	int pnlwidth;
	int pnlheight;
	int PanelHeight;
	int answeredquestion;
	int counterloading;
	int confidence;
	bool InWin;
	bool InLost;
public:
	LevelController(int width, int height, int pnlwidth, int pnlheight, Character* fox);
	~LevelController();
	//=====IMAGES======
	void LoadCharacter(char* route, int width, int height);
	void LoadEnemy(char* route, int width, int height);
	void LoadWorld(char* route);
	void LoadCommentator(char* route,int width,int height);
	void LoadBullet(char* route,Bullet* bullet);
	void LoadAlly(char* route, int rows, int columns);
	//====MAIN-FUNCTIONS=====
	void DrawAll(Graphics^ canvas);
	void MoveAll(Direction key);
	void UpdateGame();
	void StartLevel(int commentor_width,int commentor_height);
	bool VerifyLost();
	bool VerifyWin();
	//======CLEAR-VECTOR======
	void ClearElements();
	void ClearVectors();
	//======ADDERS========
	void AddEnemy(Enemy* robot);
	void addBullet(Bullet* bullet);
	void addCriticResource(Resource* temp);
	void addHelpfulResource(Resource* temp);
	void addAllies(Ally* temp);
	//=====COLLISIONS=======
	bool BulletsCollisionsPlayer();
	bool BulletsCollisionsEnemies();
	bool ColotionPlayerEnemies();
	bool CollisionPlayerCriticResources();
	bool CollisionPlayerHelpfulResources();
	bool CollisionPlayerAlly();
	//======BACK-UPS=======
	void LoadGame();
	void SaveGame();
	//=====DIALOGUES======
	void UpdateDialogue();
	void StarRandomDialogue(TypeDialogue type);
	void DrawCommentor(Graphics^ canvas);
	//=====QUIZ==========
	void StarQuiz();
	void UpdateQuestion();
	bool getAnswerCorrect(int answer);
	//===LOADING-SCREEN===
	bool UpdateScreen(Graphics^canvas);
	//======GETTERS=======
	vector<Enemy*> getVector();
	string getCurrentDialogue();
	bool getDialogueInProcess();
	bool getQuestionInProcess();
	string getCurrentQuestion();
	Character* getCharacter();
	Dialogue* getDialogue();
	string getReflexiveQuestion();
	int getTimeResourcePick();
	bool getPass();
	int getLevel();
	int getConfidence();
	Background* getMainBackGround();
	//====SETTERS======
	void setTimeResource(int ms);
	void setPass(bool pass);
	void setInLost(bool inLost);
};