#pragma once
using namespace System;
using namespace System::Drawing;

class Background {
private:
    char* Image;
    int width;
    int height;
    int indexX;
    int indexY;
public:
    Background();
    Background(int width, int height, char* route);
    ~Background();

    void LoadImage(char* ruta, int width, int height);
    void Draw(Graphics^ canvas, int rows, int columns);
    void MoveBackGround(int rows, int columns);
    char* getImage();
    int getwidth();
    int getheight();
    int getIndexX();
    int getIndexY();
    void setIndexX(int indexX);
    void setIndexY(int indexY);
};
