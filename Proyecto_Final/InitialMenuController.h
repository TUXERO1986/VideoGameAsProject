#pragma once
#include "Background.h"
#include "Character.h"
class InitialMenuController 
{
private:
	int width;
	int height;
	Background* background;
	Character* character;
public:
	InitialMenuController(int width, int height);
	void StartPersonaje(Character* picked);
	void DrawAll(Graphics^canvas);
	void SetBackGroundBottom(char* route, int width, int height, Graphics^ canvas);
	void LoadBackground(char* ruta, int width, int height);
	Character* getCharacter();
};

