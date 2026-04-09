#include "LevelController.h"
LevelController::LevelController(int width, int height, int pnlwidth,int pnlheight,Character* fox){
	PanelHeight = height;
	PanelWidth = width;
	character = fox;
	this->hitscounter = 0;
	this->criticresources = 0;
	this->helpfulresources = 0;
	this->enemykillscounter = 0;
	this->answeredquestion = 0;
	this->currentlevel = 1;
	this->counterloading = 0;
	this->confidence = 100;
	this->pass = true;
	this->pnlheight = pnlheight;
	this->pnlwidth = pnlwidth;
	filesmanagement = new FilesManagement();
	dialoguecontroler = new DialogueController();
	dialoguecontroler->StarDialogue(dynamic_cast<Blue_Fox_Character*>(character) ? "Texts\\Dialogues1.txt" : "Texts\\Dialogues2.txt");
	questioncontroller = new QuestionController();
	dialogue = new Dialogue();
	background = new Background();
	commentator = new Background();
	loadingscreen = new Background();
	loadingscreen->LoadImage("Images\\LoadingScreen.png",width,height);
	portal = nullptr;
	question = nullptr;
	resourcepick = false;
	onResourceTimer = false;
	InLost = false;
	InWin = false;
}
LevelController::~LevelController(){
	for (auto a : robotvec)delete a;
	for (auto a : criticresourcesvec)delete a;
	for (auto a : helpfulresourcesvec)delete a;
	for (auto a : bulletvec)delete a;
	criticresourcesvec.clear();
	helpfulresourcesvec.clear();
	bulletvec.clear();
	robotvec.clear();
	//delete character;
	delete background;
	delete dialogue;
	delete filesmanagement;
	delete dialoguecontroler;
	delete commentator;
	delete portal;
}
//=====IMAGES=========
void LevelController::LoadCharacter(char* route, int width, int height) {
	character->LoadImage(route, width, height);
}
void LevelController::LoadEnemy(char* route, int width, int height) {
	for (auto a : robotvec) a->LoadImage(route, width, height);
}
void LevelController::LoadWorld(char* route) {
	background->LoadImage(route, PanelWidth, PanelHeight);
}
void LevelController::LoadCommentator(char* route, int width, int height) {
	commentator->LoadImage(route, width, height);
}
void LevelController::LoadBullet(char* route, Bullet* bullet) {
	bullet->LoadImage(route, 1, 1);
}
void LevelController::LoadAlly(char* route,int rows,int columns) {
	for (auto a : alliesvector)a->LoadImage(route,rows,columns);
}
//=====MAIN-FUNCTIONS========
void LevelController::MoveAll(Direction key) {
	character->Move(key,PanelWidth,PanelHeight);
	if(portal!=nullptr)portal->Move(key, 0, 0);
	for (auto a : robotvec) {
		a->Move(key, PanelWidth, PanelHeight);
		if (a->DetectPlayer(character->getRectangle())) {
			if (a->getCooldownShot() > 15) {
				if (a->getTypeWorld() == TypeWorld::IA) {
					Bullet* temp = new Bullet(a->getX(), a->getY(),
						Team::Enemies, a->getLaskey(), a->getWidth(), a->getHeight(), 1, 1);
					LoadBullet("Images\\Enemy1Bullet.png", temp);
					addBullet(temp);
				}
				else if(a->getTypeWorld() == TypeWorld::Human) {
					Bullet* temp = new Bullet(a->getX(), a->getY(),
						Team::Enemies, a->getLaskey(), a->getWidth(), a->getHeight(), 1, 1);
					LoadBullet("Images\\Enemy2Bullet.png", temp);
					addBullet(temp);
				}
				a->setCooldownShot(0);
			}
			else a->setCooldownShot(a->getCooldownShot() + 1);
		}
	}
	for (auto a : bulletvec)a->Move(key,PanelWidth,PanelHeight);
	for (auto a : criticresourcesvec)a->Move(key,PanelWidth,PanelHeight);
	for (auto a : helpfulresourcesvec)a->Move(key,PanelWidth,PanelHeight);
	for (auto a : alliesvector)a->Move(key,PanelWidth,PanelHeight);
	if(dialogue->getInProgress())commentator->MoveBackGround(2, 2);
	if(question!=nullptr&&question->getInProgress())commentator->MoveBackGround(2, 2);
}
void LevelController::DrawAll(Graphics^ canvas1) {
	
	background->Draw(canvas1, 1, 1);
	if (portal != nullptr)portal->Draw(canvas1);
	if(!InLost&&!InWin)character->Draw(canvas1);
	for (auto a : robotvec)a->Draw(canvas1);
	for (auto a : bulletvec)a->Draw(canvas1);
	for (auto a : criticresourcesvec)a->Draw(canvas1);
	for (auto a : helpfulresourcesvec)a->Draw(canvas1);
	for (auto a : alliesvector)a->Draw(canvas1);
}
void LevelController::StartLevel(int commentor_width, int commentor_height) {
	if (!pass)return;
	if (currentlevel == 1) {
		if (dynamic_cast<Blue_Fox_Character*>(character))
			character->setHealth(5);
		else character->setHealth(10);
		ClearVectors();
		char* WorldRoute = "Images\\Level1World.png";
		for (int i = 0; i < 5; i++) {
			Enemy* temp = new Enemy(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), 0.3, 1, 5, 1, TypeWorld::IA);
			temp->LoadImage("Images\\Enemy1.png", 1, 5);
			AddEnemy(temp);
		}
		for (int i = 0; i < 3; i++) {
			Resource* temp1 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), TypeWorld::IA);
			temp1->LoadImage("Images\\CriticResource1.png", 2, 2);
			Resource* temp2 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), TypeWorld::IA);
			temp2->LoadImage("Images\\HelpfulResource1.png", 2, 2);
			addCriticResource(temp1);
			addHelpfulResource(temp2);
		}
		for (int i = 0; i < 3; i++)
		addAllies(new Ally(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), 1.5, TypeWorld::IA));
		LoadAlly("Images\\Ally1.png",3,2);
		LoadWorld(WorldRoute);
		pass = false;
	}
	else if (currentlevel == 2) {
		if (dynamic_cast<Blue_Fox_Character*>(character))
			character->setHealth(5);
		else character->setHealth(10);
		ClearVectors();
		char* WorldRoute = "Images\\Level2World.png";
		for (int i = 0; i < 5; i++) {
			Enemy* temp = new Enemy(rand() % (PanelWidth - 100), rand() % (PanelHeight - 100), 0.3, 1, 5, 1, TypeWorld::Human);
			temp->LoadImage("Images\\Enemy2.png", 2, 4);
			AddEnemy(temp);
		}
		for (int i = 0; i < 3; i++) {
			Resource* temp1 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), TypeWorld::Human);
			temp1->LoadImage("Images\\CriticResource2.png", 2, 2);
			Resource* temp2 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), TypeWorld::Human);
			temp2->LoadImage("Images\\HelpfulResource2.png", 2, 2);
			addCriticResource(temp1);
			addHelpfulResource(temp2);
		}
		for (int i = 0; i < 3; i++)addAllies(new Ally(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), 0.4, TypeWorld::Human));
		LoadAlly("Images\\Ally2.png",2,4);
		LoadWorld(WorldRoute);
		pass = false;
	}
	else if (currentlevel == 3) {
		if (dynamic_cast<Blue_Fox_Character*>(character))
			character->setHealth(5);
		else character->setHealth(10);
		ClearVectors();
		char* WorldRoute = "Images\\Level3World.png";
		for (int i = 0; i < 3; i++) {
			Enemy* temp1 = new Enemy(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), 0.3, 1, 5, 1, TypeWorld::IA);
			Enemy* temp2 = new Enemy(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), 0.3, 1, 5, 1, TypeWorld::Human);
			temp1->LoadImage("Images\\Enemy1.png", 1, 5);
			temp2->LoadImage("Images\\Enemy2.png", 2, 4);
			AddEnemy(temp1);
			AddEnemy(temp2);
		}
		for (int i = 0; i < 2; i++) {
			Resource* temp1 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), TypeWorld::IA);
			temp1->LoadImage("Images\\CriticResource1.png", 2, 2);
			Resource* temp2 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), TypeWorld::IA);
			temp2->LoadImage("Images\\HelpfulResource1.png", 2, 2);
			addCriticResource(temp1);
			addHelpfulResource(temp2);
		}
		for (int i = 0; i < 2; i++) {
			Resource* temp1 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), TypeWorld::Human);
			temp1->LoadImage("Images\\CriticResource2.png", 2, 2);
			Resource* temp2 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), TypeWorld::Human);
			temp2->LoadImage("Images\\HelpfulResource2.png", 2, 2);
			addCriticResource(temp1);
			addHelpfulResource(temp2);
		}
		for (int i = 0; i < 2; i++) {
			Ally* temp = new Ally(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), 1.5, TypeWorld::IA);
			temp->LoadImage("Images\\Ally1.png", 3, 2);
			addAllies(temp);
		}

		for (int i = 0; i < 2; i++) {
			Ally* temp = new Ally(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), 0.4, TypeWorld::Human);
			temp->LoadImage("Images\\Ally2.png", 2, 4);
			addAllies(temp);
		}
		LoadWorld(WorldRoute);
		pass = false;
	}
}
bool LevelController::VerifyLost() {
	if (character->getHealth() <= 0||(confidence<20&&currentlevel>3)) {
		if ((confidence < 20 && currentlevel>3))currentlevel=3;
		background->LoadImage("Images\\LostScreen.png", PanelWidth, PanelHeight);
		InLost = true;
		return true;
	}
	else {
		return false;
	}
	return false;
}
bool LevelController::VerifyWin() {
	if (currentlevel > 3&&confidence>=20) {
		background->LoadImage("Images\\WinScreen.jpg", PanelWidth, PanelHeight);
		InWin = true;
		return true;
	}
	else {
		return false;
	}
}
void LevelController::UpdateGame() {
	if (portal != nullptr) {
		if (portal->getRectangle().IntersectsWith(character->getRectangle())) {
			portal = nullptr;
			currentlevel++;
			pass = true;
			return;
		}
		return;
	}
	if (pass||InLost||InWin)return;
	if (currentlevel == 1) {
		for (auto a : robotvec) if (a) return;
		for (auto a : alliesvector) if (a)return;
		portal = new Portal(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200));
		portal->LoadImage("Images\\Portal.png", 2, 2);
	}
	if (currentlevel == 2) {
		for (auto a : robotvec) if (a) return;
		for (auto a : alliesvector) if (a)return;
		portal = new Portal(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200));
		portal->LoadImage("Images\\Portal.png", 2, 2);
	}
	if (currentlevel == 3) {
		for (auto a : robotvec) if (a) return;
		for (auto a : alliesvector) if (a)return;
		portal = new Portal(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200));
		portal->LoadImage("Images\\Portal.png", 2, 2);
	}

}
//=====CLEAR-VECTOR=======
void LevelController::ClearElements() {
	for (auto it = bulletvec.begin(); it != bulletvec.end();) {
		Bullet* b = *it;
		if (!b->getVisible()) {
			delete b;
			it = bulletvec.erase(it);
		}
		else it++;
	}
	for (auto it = robotvec.begin(); it != robotvec.end();) {
		Enemy* e = *it;
		if (!e->getVisible()) {
			delete e;
			it = robotvec.erase(it);
		}
		else it++;
	}
	for (auto it = criticresourcesvec.begin(); it != criticresourcesvec.end();) {
		Resource* e = *it;
		if (!e->getVisible()) {
			delete e;
			it = criticresourcesvec.erase(it);
		}
		else it++;
	}
	for (auto it = helpfulresourcesvec.begin(); it != helpfulresourcesvec.end();) {
		Resource* e = *it;
		if (!e->getVisible()) {
			delete e;
			it = helpfulresourcesvec.erase(it);
		}
		else it++;
	}
	for (auto it = alliesvector.begin(); it != alliesvector.end();) {
		Ally* e = *it;
		if (!e->getVisible()) {
			delete e;
			it = alliesvector.erase(it);
		}
		else it++;
	}
}
void LevelController::ClearVectors() {
	for (auto a : robotvec) delete a;
	robotvec.clear();
	for (auto a : alliesvector) delete a;
	alliesvector.clear();
	for (auto a : criticresourcesvec) delete a;
	criticresourcesvec.clear();
	for (auto a : helpfulresourcesvec) delete a;
	helpfulresourcesvec.clear();
	for (auto a : bulletvec) delete a;
	bulletvec.clear();
}
//=======ADDERS=========
void LevelController::AddEnemy(Enemy* robot) {
	robotvec.push_back(robot);
}
void LevelController::addBullet(Bullet* bullet) {
	bulletvec.push_back(bullet);
}
void LevelController::addCriticResource(Resource* temp) {
	criticresourcesvec.push_back(temp);
}
void LevelController::addHelpfulResource(Resource* temp) {
	helpfulresourcesvec.push_back(temp);
}
void LevelController::addAllies(Ally* temp) {
	alliesvector.push_back(temp);
}
//=====COLLISIONS======
bool LevelController::BulletsCollisionsPlayer() {
	for (auto b : bulletvec) {

		for (auto e : robotvec) {
			if (b->getTeam() == Team::Enemies)break;
			if (e->getRectangle().IntersectsWith(b->getRectangle())) {
				b->setVisible(false);
				e->setVisible(false);
				character->setPoints(character->getPoints()+5);
				enemykillscounter++;
				return true;
			}
		}
	}
	return false;
}
bool LevelController::BulletsCollisionsEnemies() {

	for (auto b : bulletvec) {
		if (character->getRectangle().IntersectsWith(b->getRectangle()) &&
			b->getTeam() != Team::Characters) {
			character->Hit(b->getDamage());
			b->setVisible(false);
			return true;
		}
	}
	return false;
}
bool LevelController::ColotionPlayerEnemies() {

	for (auto a : robotvec) {
		if (a->getRectangle().IntersectsWith(character->getRectangle())) {
			character->Hit(a->getDamage());
			return true;
		}
	}
	return false;
}
bool LevelController::CollisionPlayerCriticResources() {
	if (resourcepick)return false;
	for (auto a : criticresourcesvec) {
		if (a->getRectangle().IntersectsWith(character->getRectangle())) {
			a->setVisible(false);
			typeresourcepick = a->getTypeWorld();
			setTimeResource(5000);
			resourcepick = true;
			onResourceTimer = true;
			criticresources++;
			return true;
		}
	}
	return false;
}
bool LevelController::CollisionPlayerHelpfulResources() {

	for (auto a : helpfulresourcesvec) {
		if (a->getRectangle().IntersectsWith(character->getRectangle())) {
			a->setVisible(false);
			switch (rand() % 2) {
			case 0:character->setHealth(character->getHealth() + 1); Console::Write("VIDA AUMENTADA"); break;
			case 1: character->BeInmune(chrono::milliseconds(5000)); Console::Write("INMUNE"); break;
			}
			helpfulresources++;
			return true;
		}
	}
	return false;
}
bool LevelController::CollisionPlayerAlly() {
	if (!resourcepick||character->Inmune())return false;
	for (auto a : alliesvector) {
		if (a->getRectangle().IntersectsWith(character->getRectangle())) {
			if (a->getTypeWorld() == typeresourcepick) {
				onResourceTimer = false;
				a->setInquesion(true);
				if (a->getTypeWorld()==TypeWorld::IA) {
					LoadCommentator("Images\\Ally1Commentor.png", pnlwidth, pnlheight);
				}
				else LoadCommentator("Images\\Ally2Commentor.png", pnlwidth, pnlheight);
				return true;
			}
		}
	}
	return false;
}
//=======BACK-UPS===========
void LevelController::LoadGame() {
	ClearVectors();
	filesmanagement->LoadGame(character, robotvec, background, criticresourcesvec, helpfulresourcesvec, alliesvector, currentlevel);
}
void LevelController::SaveGame() {
	filesmanagement->SaveGame(character, robotvec, background,criticresourcesvec,helpfulresourcesvec,alliesvector,currentlevel);
}
//=======DIALOGUES=========
void LevelController::UpdateDialogue() {
	if (!dialogue->Update()) {
		commentator->setIndexX(0); commentator->setIndexY(0);
	}
}
void LevelController::StarRandomDialogue(TypeDialogue type) {
	if (dynamic_cast<Blue_Fox_Character*>(character)) {
		LoadCommentator("Images\\RedCommentor.png", pnlwidth, pnlheight);
	}
	else LoadCommentator("Images\\BLueCommentor.png", pnlwidth, pnlheight);
	int dialogueindex = 0;
	Hierarchy hierarchy;
	switch (type) {
	case TypeDialogue::hits:dialogueindex = 0 + (hitscounter % 10); hierarchy = Hierarchy::Low; break;
	case TypeDialogue::killenemy:dialogueindex = 10 + (enemykillscounter % 10); hierarchy = Hierarchy::Low; break;
	case TypeDialogue::helpfulresource:dialogueindex = 20 + (helpfulresources % 10); hierarchy = Hierarchy::Medium; break;
	case TypeDialogue::criticresource:dialogueindex = 30 + (criticresources % 10); hierarchy = Hierarchy::Medium; break;
	case TypeDialogue::passlevel:dialogueindex = 0 + (hitscounter % 10); hierarchy = Hierarchy::High; break;
	case TypeDialogue::story:dialogueindex = 0 + (hitscounter % 10); hierarchy = Hierarchy::High; break;
	}
	string current = dialoguecontroler->getDialogue(dialogueindex);
	hitscounter++;
	dialogue->Start(current,type,hierarchy);
}
void LevelController::DrawCommentor(Graphics^ canvas) {
	commentator->Draw(canvas, 2, 2);
}
//=========QUIZ==========
void LevelController::UpdateQuestion() {
	question->Update();
}
void LevelController::StarQuiz() {
	TypeWorld allytype;
	for (auto a : alliesvector) {
		if (a->getInquestion()) {
			allytype = a->getTypeWorld();
			break;
			
		}
	}
	int indexquestion = 0 + (answeredquestion % 10);
	answeredquestion++;
	switch (allytype) {
	case TypeWorld::IA:questioncontroller->StartQuiz("Texts\\Quiz1.txt"); break;
	case TypeWorld::Human:questioncontroller->StartQuiz("Texts\\Quiz2.txt"); break;
	}
	question = questioncontroller->getCurrentQuestion(indexquestion);
	question->setInProgress(true);
}
//===LOADING-SCREEN===
bool LevelController::UpdateScreen(Graphics^canvas) {
	if (!pass||(InWin||InLost))return false;
	if (counterloading > 60) {
		counterloading = 0;
		return false;
	}
	else {
		loadingscreen->MoveBackGround(2,2);
		loadingscreen->Draw(canvas,2,2);
		counterloading++;
		return true;
	}
}
string LevelController::getReflexiveQuestion(){
string reflexivequestion = "";
	if (currentlevel == 1) {
		reflexivequestion= ("\t\tAI World \n\nWill you earn trust the way machines demand it :" 
			"through consistency, proof, and decisions you can defend ? ");
		return reflexivequestion;
	}
	else if (currentlevel == 2) {
		reflexivequestion = ("\t\tHuman World \n\nCan you win trust from people not by being"
			"right, but by being present, empathetic, and reliable when it matters ?");
		return reflexivequestion;
	}
	else if (currentlevel == 3) {
		reflexivequestion = ("\t\tAI Human World \n\nWhen logic and emotion pull in opposite directions, "
			"can you become the bridge they both choose to trust ? ");
		return reflexivequestion;
	}
	return reflexivequestion;
}
//======GETTERS=========
string LevelController::getCurrentDialogue() {return dialogue->getCurrenttext();}
bool LevelController::getDialogueInProcess() {return dialogue->getInProgress();}
string LevelController::getCurrentQuestion() {return question->getCurrentText();}
bool LevelController::getQuestionInProcess() { if (question == nullptr)return false; return question->getInProgress();}
bool LevelController::getAnswerCorrect(int answer) {
	if (question == nullptr)return false;
	if (question->CorrecAnswer(answer)) {
		for (auto a : alliesvector) {
			if (a->getInquestion()) { a->setVisible(false); break; }
		}
		confidence += 1 * (10)/answeredquestion;
		character->setPoints(character->getPoints() + 5);
		character->BeInmune(chrono::milliseconds(2000));
		question = nullptr;
		resourcepick = false;
		return true;
	}
	else { 
		for (auto a : alliesvector) {
			if (a->getInquestion()) { a->setInquesion(false); break; }
		}
		confidence -= 1;
		Resource* temp1 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), typeresourcepick);
		criticresourcesvec.push_back(temp1);
		if (typeresourcepick == TypeWorld::Human)temp1->LoadImage("Images\\CriticResource2.png", 2, 2);
		else if (typeresourcepick == TypeWorld::IA)temp1->LoadImage("Images\\CriticResource1.png", 2, 2);
		resourcepick = false;
		character->Hit(1);
		question = nullptr; 
		return true; 
	}
	return false;
}
int LevelController::getTimeResourcePick() {
	if (!onResourceTimer)return 0;
	auto remaining = chrono::duration_cast<std::chrono::milliseconds>(timerresource - chrono::steady_clock::now()).count();
	int time = (int)((remaining + 999) / 1000);;
	if (time<=0) {
		resourcepick = false;
		onResourceTimer = false;
		confidence -= 1;
		Resource* temp1 = new Resource(rand() % (PanelWidth - 200), rand() % (PanelHeight - 200), typeresourcepick);
		if (typeresourcepick == TypeWorld::Human)temp1->LoadImage("Images\\CriticResource2.png", 2, 2);
		else if(typeresourcepick == TypeWorld::IA)temp1->LoadImage("Images\\CriticResource1.png", 2, 2);
		criticresourcesvec.push_back(temp1);
		return 0;
	}
	else {
		return time;
	}
}
Dialogue* LevelController::getDialogue() { return dialogue; }
bool LevelController::getPass() { return pass; }
int LevelController::getLevel() { return currentlevel; }
int LevelController::getConfidence() { return confidence; }
std::vector<Enemy*> LevelController::getVector() {return robotvec;}
Character* LevelController::getCharacter() { return character; }
Background* LevelController::getMainBackGround() { return background; }
//======setters======
void LevelController::setTimeResource(int ms) {
	onResourceTimer = true;
	timerresource= chrono::steady_clock::now() + chrono::milliseconds(ms);
}
void LevelController::setPass(bool pass) {
	this->pass = pass;
}
void LevelController::setInLost(bool InLost) {
	this->InLost = InLost;
}

