#include "Character.h"
Character::Character() : Sprite() {
    points = 0;
    health = 3;
    speed = 7;
}
Character::Character(int x, int y, float scale) : Sprite(x, y) {
    points = 0;
    health = 3;
    speed = 7;
    this->scale = scale;

}
Character::~Character() {}
void Character::Move_Character(Direction key, int WidghtLimit, int UpLimit) {
    if (key == Direction::Up) { dx = 0;  dy = -1; indexY = 3; LastKey = key; }
    if (key == Direction::Down) { dx = 0;  dy = 1;  indexY = 0; LastKey = key; }
    if (key == Direction::Left) { dx = -1; dy = 0;  indexY = 1; LastKey = key; }
    if (key == Direction::Right) { dx = 1;  dy = 0;  indexY = 2; LastKey = key; }
    if (key == Direction::None) {
        switch (LastKey) {
        case Direction::Up: indexY = 3; indexX = 0; break;
        case Direction::Down: indexY = 0; indexX = 0; break;
        case Direction::Left: indexY = 1; indexX = 0; break;
        case Direction::Right: indexY = 2; indexX = 0; break;
        }
    }
    if (key != Direction::None) {
        indexX++;
        if (indexX >= columns) indexX = 0;

        x += dx * speed;
        y += dy * speed;

        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x > WidghtLimit - drawW()) x = WidghtLimit - drawW();
        if (y > UpLimit - drawH()) y = UpLimit - drawH();
    }
}
void Character::Draw_Character(Graphics^ canvas) {
    Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));

    Rectangle cuadroOrigen = Rectangle(
        indexX * width,
        indexY * height,
        width,
        height
    );

    Rectangle cuadroDestino = Rectangle(
        x+ajusteX,
        y+ajusteY,
        width * scale,
        height * scale
    );

    canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
    delete bitmap;
}
void Character::Draw(Graphics^ canvas) {
    Draw_Character(canvas);
}
void Character::Move(Direction key, int WidghtLimit, int UpLimit) {
    Move_Character(key,WidghtLimit,UpLimit);
}
void Character::Hit(int damage) {
    if (Inmune())return;
    health -= damage;
    if (health < 0)health = 0;
    BeInmune(std::chrono::milliseconds(2000));
}
void Character::BeInmune(std::chrono::milliseconds dur) {
    inmune = true;
    timer = std::chrono::steady_clock::now() + dur;
}
bool Character::Inmune() {
    if (!inmune)return false;
    if (std::chrono::steady_clock::now() >= timer) {
        inmune = false;
        return false;
    }
    return true;
}
int Character::getHealth() { return health; }
int Character::getPoints() { return points; }
void Character::setHealth(int health) { this->health = health; }
void Character::setPoints(int points) { this->points = points; }
