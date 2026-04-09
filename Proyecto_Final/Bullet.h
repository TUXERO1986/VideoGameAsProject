#pragma once
#include "Sprite.h"
enum Team {Enemies,Characters};
class Bullet : public Sprite
{
private:
	Team team;
	Direction direction;
	int damage;
public:
	Bullet(int x, int y, Team team, Direction direction, int width, int height,int damage, float scale);
	void Move(Direction key, int WidghtLimit, int UpLimit);
	void Draw(Graphics^canvas);
	Team getTeam();
	int getDamage();
};

