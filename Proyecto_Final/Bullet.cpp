#include "Bullet.h"
Bullet::Bullet(int x, int y, Team team, Direction direction, int width, int height, int damage,float scale) : Sprite(x, y) {
	this->team = team;
	this->direction = direction;
	this->dx = 1;
	this->dy = 1;
	this->damage = damage;
	this->scale = scale;
}
void Bullet::Draw(Graphics^canvas) {
	Bitmap^ bitmap = gcnew Bitmap(gcnew String(image));
	if (direction == Direction::Left)bitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);
	if (direction == Direction::Down)bitmap->RotateFlip(RotateFlipType::Rotate90FlipNone);
	if (direction == Direction::Up)bitmap->RotateFlip(RotateFlipType::Rotate270FlipNone);
	Rectangle Origin(width*indexX,height*indexY,width,height);
	Rectangle Posting(x,y,width*scale,height*scale);
	canvas->DrawImage(bitmap,Posting,Origin,GraphicsUnit::Pixel);
	delete bitmap;
}
void Bullet::Move(Direction key, int WidghtLimit, int UpLimit) {
	switch (direction) {
	case Direction::Up: { y -= dy * 7; break;}
	case Direction::Down: { y += dy * 7; break;}
	case Direction::Left: { x -= dx * 7; break;}
	case Direction::Right: { x += dx * 7; break; }
	}
	if (x<0 || x>WidghtLimit)visible = false;
	if (y<0 || y>UpLimit)visible = false;

}
int Bullet::getDamage() { return damage; }
Team Bullet::getTeam() {
	return team;
}