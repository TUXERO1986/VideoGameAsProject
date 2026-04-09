#include "Sprite.h"
#include <string>
Sprite::Sprite(int x , int y){
    this->x = x;
    this->y = y;
    dx = 0;
    dy = 0;
    indexX = 0;
    indexY = 0;
    width = 0;
    height = 0;
    rows= 0;
    columns = 0;
    visible = true;
    image = new char[100];
}
Sprite::Sprite() {
    x = 0;
    y = 0;
    dx = 0;
    dy = 0;
    indexX = 0;
    indexY = 0;
    width = 0;
    height = 0;
    rows = 0;
    columns = 0;
    visible = true;
    image = new char[100];
}
Sprite::~Sprite() {
    if (image != nullptr)delete[] image;
}
void Sprite::LoadImage(char* route,int rows, int columns) {
    strcpy_s(image, 100, route);
    this->rows= rows;
    this->columns = columns;

    Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
    width = bitmap->Width / columns;
    height = bitmap->Height / rows;
    delete bitmap;
}
int Sprite::getX() { return x; }
int Sprite::getY() { return y; }
int Sprite::getWidth() { return width; }
int Sprite::getHeight() { return height; }
int Sprite::getRows() { return rows; }
int Sprite::getColumns() { return columns; }
int Sprite::getDX() { return dx; }
int Sprite::getDY() { return dy; }
float Sprite::getScale() { return scale; }
bool Sprite::getVisible() { return visible; }
char* Sprite::getImage() { return image; }
Rectangle Sprite::getRectangle() {
    int widthColision = (int)(width*scale * 0.6);
    int heightColision = (int)(height*scale * 0.6);

    int desplazamientoX = (width*scale - widthColision) / 2;
    int desplazamientoY = (height*scale - heightColision) / 2;

    return Rectangle(x + desplazamientoX, y + desplazamientoY, widthColision, heightColision);
}
Direction Sprite::getLaskey(){return LastKey;}
void Sprite::setX(int x) { this->x = x; }
void Sprite::setY(int y) { this->y = y; }
void Sprite::setDX(int dx) { this->dx = dx; }
void Sprite::setDY(int dy) { this->dy = dy; }
void Sprite::setVisible(bool visible) { this->visible=visible; }
void Sprite::setImage(char* image) { strcpy_s(this->image,100,image); }
TypeWorld Sprite::getTypeWorld() { return typeworld; }