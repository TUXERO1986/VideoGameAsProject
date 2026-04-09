#pragma once
#include "Sprite.h"

class Enemy : public Sprite
{
private:
	int drawW() const { return width * scale; }
	int drawH() const { return height * scale; }
	int movement;
	int dano;
	int velocidad;
	int vida;
	int cooldown_shot;
public:
	Enemy(int x, int y, float scale, int vida, int velocidad, int dano, TypeWorld typenemy);
	Enemy();
	void Move(Direction key, int WidghtLimit, int UpLimit)override;
	void Draw(Graphics^ canvas)override;
	bool DetectPlayer(Rectangle prectangle);
	void setMovement(int movement);
	void setCooldownShot(int cooldownshot);
	int getCooldownShot();
	int getMovement();
	int getSpeed();
	int getHealth();
	int getDamage();
	
};

