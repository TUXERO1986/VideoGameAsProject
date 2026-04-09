#pragma once
#include "Sprite.h"
class Ally : public Sprite
{
private:
	bool inquestion;
public:
	Ally(int x,int y, float scale, TypeWorld typeworld);
	void Move(Direction key, int widthlimit, int limuitheight);
	void Draw(Graphics^gr);
	void setInquesion(bool inquestion);
	bool getInquestion();
};

