#pragma once
#include "Sprite.h"
class Resource : public Sprite
{
private:
public:
	Resource(int x, int y,TypeWorld typeworld);
	void Draw(Graphics^gr);
	void Move(Direction direction,int widthlimit, int heightlimit);
};

