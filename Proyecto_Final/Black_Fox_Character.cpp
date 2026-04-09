#include "Black_Fox_Character.h"
Black_Fox_Character::Black_Fox_Character(): Character() {
	points = 0;
	speed = 7;
	health = 10;
	ajusteX = 0;
	ajusteY = 0;

}
Black_Fox_Character::Black_Fox_Character(int x , int y, float scale): Character(x,y,scale) {
	speed = 7;
	points = 0;
	health = 10;
	ajusteX = 0;
	ajusteY = 0;

}
Black_Fox_Character::~Black_Fox_Character(){}
void Black_Fox_Character::Move(Direction key, int WidghtLimit, int UpLimit) {
    Move_Character(key, WidghtLimit, UpLimit);
}
void Black_Fox_Character::Draw(Graphics^canvas) {
    Draw_Character(canvas);
}
