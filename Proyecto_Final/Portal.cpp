#include "Portal.h"
Portal::Portal(int x, int y): Sprite(x,y){
	this->scale = 0.2;
}
void Portal::Draw(Graphics^ gr) {
	Bitmap^ bmp = gcnew Bitmap(gcnew String(image));
	Rectangle origin(indexX * width, indexY * height, width, height);
	Rectangle posting(x, y, width*scale, height*scale);
	gr->DrawImage(bmp, posting, origin, GraphicsUnit::Pixel);
	delete bmp;
}
void Portal::Move(Direction direction, int widthlimit, int heightlimit) {
	indexX++;
	if (indexX >= columns) { indexX = 0; indexY++; }
	if (indexY >= rows)indexY = 0;
}