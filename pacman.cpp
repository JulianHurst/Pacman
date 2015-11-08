#include "pacman.h"

Pacman::Pacman(float x,float y)
{
    this->x=x;
    this->y=y;
    QPixmap pac;
    gpac = new QGraphicsPixmapItem();    
    pac.load(":/Sprites/sprites.qrc/pac.png");
    gpac->setPixmap(pac);
    gpac->setPos(this->x,this->y);
}

QGraphicsPixmapItem *Pacman::getgpac(){
    return gpac;
}

void Pacman::setx(int x){
    this->x=x;
}

void Pacman::sety(int y){
    this->y=y;
}

float Pacman::getx(){
    return x;
}

float Pacman::gety(){
    return y;
}

