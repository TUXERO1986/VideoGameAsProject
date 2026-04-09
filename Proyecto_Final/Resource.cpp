#include "Resource.h"
Resource::Resource(int x, int y,TypeWorld typeworld) : Sprite(x,y) {
	this->typeworld = typeworld;
	this->scale = 1;
}
void Resource::Draw(Graphics^ gr) {
	Bitmap^ bmp = gcnew Bitmap(gcnew String(image));
	Rectangle origin(width * indexX, height * indexY, width, height);
	Rectangle posting(x, y, width, height);
	gr->DrawImage(bmp,posting,origin,GraphicsUnit::Pixel);
	delete bmp;
}
void Resource::Move(Direction direction, int widthlimit, int heightlimit) {
	indexX++;
	if (indexX >= columns) { indexX = 0; indexY++; }
	if (indexY >= rows) { indexY = 0; }
}