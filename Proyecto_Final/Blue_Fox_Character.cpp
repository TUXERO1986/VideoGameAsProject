#include "Blue_Fox_Character.h"
Blue_Fox_Character::Blue_Fox_Character(): Character(){
	speed = 10;
	ajusteX = 0;
	health = 5;
	points = 0;
	ajusteY = 0;
}
Blue_Fox_Character::Blue_Fox_Character(int x, int y, float scale): Character(x,y,scale){
	speed = 10;
	ajusteX = 0;
	ajusteY = 0;
	health = 5;
	points = 0;
}
Blue_Fox_Character::~Blue_Fox_Character() {}
void Blue_Fox_Character::Move(Direction key, int WidghtLimit, int UpLimit) {
    Move_Character(key, WidghtLimit, UpLimit);
}
void Blue_Fox_Character::Draw(Graphics^ canvas) {
	Draw_Character(canvas);
}