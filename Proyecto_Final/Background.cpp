#include "Background.h"
#include <cstring>

Background::Background() {
    Image = new char[100];
    Image[0] = '\0';
    width = 0;
    height = 0;
    this->indexX = 0;
    this->indexY = 0;
}

Background::Background(int width, int height, char* route) {
    Image = new char[100];
    strcpy_s(Image, 100, route);
    this->width = width;
    this->height = height;
}

Background::~Background() {
    if (Image != nullptr) {
        delete[] Image;
    }
}

void Background::LoadImage(char* ruta, int width, int height) {
    strcpy_s(Image, 100, ruta);
    this->width = width;
    this->height = height;
}

void Background::Draw(Graphics^ canvas, int rows, int columns) {
    if (width == 0 || height == 0) return;
    if (Image == nullptr || strlen(Image) == 0) return;

    System::String^ ruta = gcnew System::String(Image);
    Bitmap^ bitmap = gcnew Bitmap(ruta);
    int width_image = bitmap->Width / columns;
    int heigjt_image = bitmap->Height / rows;
    Rectangle origin(width_image *indexX, heigjt_image*indexY, width_image, heigjt_image);
    Rectangle posting(0, 0, width, height);
    canvas->DrawImage(bitmap, posting, origin,GraphicsUnit::Pixel);
    delete bitmap;
}

void Background::MoveBackGround(int rows, int columns) {
    indexX++;
    if (indexX >= columns) { indexX = 0; indexY++; }
    if (indexY >= rows)indexY = 0;
}

char* Background::getImage() {
    return Image;
}

int Background::getwidth() {
    return width;
}

int Background::getheight() {
    return height;
}
int Background::getIndexX() { return indexX; }
int Background::getIndexY() { return indexY; }
void Background::setIndexX(int indexX) { this->indexX=indexX; }
void Background::setIndexY(int indexY) { this->indexY=indexY; }
