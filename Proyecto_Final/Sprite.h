#pragma once
using namespace System;
using namespace System::Drawing;

enum Direction { Right, Left, Up, Down, None };
enum TypeWorld { IA, Human };
class Sprite
{
protected:
	int x, y;
	int dx, dy;
	int indexX, indexY;
	int width, height;
	int rows, columns;
    int ajusteX;
    int ajusteY;
    float scale;
    bool visible;
	char* image;
	Direction LastKey;
    TypeWorld typeworld;
public:
	Sprite(int x, int y);
	Sprite();
    virtual ~Sprite();
    virtual void LoadImage(char* route,int rows, int columns);
    virtual void Move(Direction key, int WidghtLimit, int UpLimit) = 0;
    virtual void Draw(Graphics^ canvas) = 0;

    int getX();
    int getY();
    int getDX();
    int getDY();
    float getScale();
    int getWidth();
    int getHeight();
    int getRows();
    int getColumns();
    bool getVisible();
    char* getImage();
    Rectangle getRectangle();
    Direction getLaskey();
    TypeWorld getTypeWorld();
    void setX(int x);
    void setY(int y);
    void setDX(int dx);
    void setDY(int dy);
    void setImage(char* image);
    void setVisible(bool visible);
};

