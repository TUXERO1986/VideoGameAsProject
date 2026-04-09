#include "InitialMenuController.h"
InitialMenuController::InitialMenuController(int width, int height) {
	this->height = height;
	this->width = width;
	character = nullptr;
	background = new Background();
}
void InitialMenuController::StartPersonaje(Character* picked) {
	if (character != nullptr)delete character;
	character = picked;
}
Character* InitialMenuController::getCharacter() {
	return character;
}
void InitialMenuController::DrawAll(Graphics^ canvas) {
	background->Draw(canvas,1,1);
}
void InitialMenuController::SetBackGroundBottom(char* route, int width, int height, Graphics^canvas) {
	Background* background = new Background();
	background->LoadImage(route, width, height);
	background->Draw(canvas,1,1);
	delete background;
}
void InitialMenuController::LoadBackground(char* ruta, int width, int height) {
	background->LoadImage(ruta, width,height);
}