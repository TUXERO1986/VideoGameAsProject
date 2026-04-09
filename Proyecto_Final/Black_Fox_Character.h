#pragma once
#include "Character.h"
class Black_Fox_Character : public Character
{
public:
	Black_Fox_Character();
	Black_Fox_Character(int x ,int y, float scale);
	~Black_Fox_Character();
	void Move(Direction key, int WidghtLimit, int UpLimit);
	void Draw(Graphics^ canvas) ;
};

