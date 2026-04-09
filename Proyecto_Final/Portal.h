#pragma once
#include "Sprite.h"
class Portal : public Sprite
{
public:
	Portal(int x, int y);
	void Draw(Graphics^ gr);
	void Move(Direction direction, int widthlimit, int heightlimit);
};

