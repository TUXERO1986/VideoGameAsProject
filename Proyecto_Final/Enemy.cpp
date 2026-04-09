#include "Enemy.h"
Enemy::Enemy(int x, int y, float scale, int vida, int velocidad, int dano, TypeWorld typeworld) : Sprite(x, y) {
	this->scale =scale;
    this->ajusteX = 0;
    this->ajusteY = 0;
    this->vida = vida;
    this->dano = dano;
    this->velocidad = velocidad;
    this->movement = movement;
    this->dx = 1;
    this->dy = 1;
    this->cooldown_shot = 10;
    this->typeworld= typeworld;
}
Enemy::Enemy() : Sprite(){
	this->scale = 1;
    this->ajusteX = 0;
    this->ajusteY = 0;
    this->vida = 3;
    this->velocidad = 5;
    this->dano = 1;
    this->dx = 1;
    this->dy = 1;
    this->movement = 1;
    this->typeworld = TypeWorld::IA;
    this->cooldown_shot = 10;
}
void Enemy::Move(Direction key, int WidghtLimit, int UpLimit){
    if (typeworld==TypeWorld::IA) {
        indexX++;
        if (indexX >= columns)indexX = 0;
        if (x<0 || x + width * scale + dx>WidghtLimit)dx *= -1;
        x += dx * velocidad;
    }
    else if (typeworld == TypeWorld::Human) {
        indexX++;
        if (indexX >= columns) { indexX = 0; indexY++; }
        if (dy>0)indexY=0;
        if (dy<0)indexY=1;
        if (y<0 || y + height * scale + dy>UpLimit)dy *= -1;
        y += dy * velocidad;
    }
}
void Enemy::Draw(Graphics^ canvas){
    Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
    if(typeworld == TypeWorld::IA&&dx>0)bitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);
    Rectangle cuadroOrigen = Rectangle(
        indexX * width,
        indexY * height,
        width,
        height
    );

    Rectangle cuadroDestino = Rectangle(
        x + ajusteX,
        y + ajusteY,
        width * scale,
        height * scale
    );
    canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
    delete bitmap;
}
void Enemy::setMovement(int movment) {
    this->movement = movement;
}
void Enemy::setCooldownShot(int cooldownshot) { this->cooldown_shot = cooldownshot; }
bool Enemy::DetectPlayer(Rectangle prectangle) {
    Rectangle^ Up= gcnew Rectangle(x,y-height * scale *2,width * scale,height * scale *2);
    Rectangle^ Down= gcnew Rectangle(x,y+height * scale,width * scale,height * scale *2);
    Rectangle^ Left= gcnew Rectangle(x-width*scale*2,y,width * scale *2, height * scale);
    Rectangle^ Right= gcnew Rectangle(x+width * scale,y,width * scale*2,height * scale);
    bool returnable = false;
    if (Up->IntersectsWith(prectangle) || Down->IntersectsWith(prectangle)
        || Left->IntersectsWith(prectangle) || Right->IntersectsWith(prectangle)) {
        if (Up->IntersectsWith(prectangle))LastKey = Direction::Up;
        if (Down->IntersectsWith(prectangle))LastKey = Direction::Down;
        if (Left->IntersectsWith(prectangle))LastKey = Direction::Left;
        if (Right->IntersectsWith(prectangle))LastKey = Direction::Right;
        returnable= true;
    }
    delete Up;
    delete Down;
    delete Left;
    delete Right;
    return returnable;
}
int Enemy::getMovement() { return movement; }
int Enemy::getHealth() { return vida; }
int Enemy::getSpeed() { return velocidad; }
int Enemy::getDamage() { return dano; }
int Enemy::getCooldownShot() { return cooldown_shot; }