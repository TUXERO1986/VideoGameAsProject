#include "Ally.h"
Ally::Ally(int x, int y, float scale, TypeWorld typeworld) : Sprite(x, y) {
	this->scale = 1.5;
	this->scale = scale;
	this->dx = 1;
	this->dy = 1;
	this->typeworld = typeworld;
	this->inquestion = false;
}
void Ally::Move(Direction key, int widthlimit, int limuitheight) {
	if (inquestion)return;
	if (typeworld == TypeWorld::IA) {
		indexX++;
		if (indexX >= columns) { indexX = 0; indexY++; }
		if (indexY >= rows) { indexY = 0; }
		x += dx * 7;
		if (x<0 || x + width*scale + dx>widthlimit)dx *= -1;
	}if (typeworld == TypeWorld::Human){
		indexX++;
		if (indexX >= columns) { indexX = 0; }
		if (dy < 0 && typeworld == TypeWorld::Human)indexY = 1;
		else if (dy > 0 && typeworld == TypeWorld::Human)indexY = 0;
		y += dy * 7;
		if (y<0 || y + height*scale>limuitheight)dy *= -1;
	}
}
void Ally::Draw(Graphics^ gr) {
	Bitmap^ bmp = gcnew Bitmap(gcnew String(image));
	if(dx>0&&typeworld==TypeWorld::IA)bmp->RotateFlip(RotateFlipType::RotateNoneFlipX);
	Rectangle origin(indexX * width, indexY * height, width, height);
	Rectangle posting(x, y, width * scale, height * scale);
	gr->DrawImage(bmp, posting, origin, GraphicsUnit::Pixel);
}
void Ally::setInquesion(bool inquestion) { this->inquestion = inquestion; }
bool Ally::getInquestion() { return inquestion; }