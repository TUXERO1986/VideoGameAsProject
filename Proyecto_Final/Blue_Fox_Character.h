#pragma once
#include "Character.h"
class Blue_Fox_Character : public Character
{
public:
	Blue_Fox_Character();
	Blue_Fox_Character(int x, int y,float scale);
	~Blue_Fox_Character();
	void Move(Direction key, int WidghtLimit, int UpLimit);
	void Draw(Graphics^ canvas);
};

