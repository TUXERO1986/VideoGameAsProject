#pragma once
#include "Sprite.h"
#include <chrono>
class Character : public Sprite
{
private:
	int drawW() const { return width * scale; }
	int drawH() const { return height * scale; }
protected:
	int points;
	int health;
	int speed;
	std::chrono::steady_clock::time_point timer;
	bool inmune;
public:
	Character();
	Character(int x, int y, float scale);
	~Character();
	void Move(Direction key, int WidghtLimit, int UpLimit)override;
	void Draw(Graphics^ canvas)override;
	virtual void Move_Character(Direction key, int WidghtLimit, int UpLimit);
	virtual void Draw_Character(Graphics^ canvas);
	int getHealth();
	int getPoints();
	void setHealth(int health);
	void setPoints(int points);
	void Hit(int damage);
	void BeInmune(std::chrono::milliseconds timer);
	bool Inmune();
};

