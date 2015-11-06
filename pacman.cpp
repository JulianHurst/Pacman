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

int Pacman::getx(){
    return x;
}

int Pacman::gety(){
    return y;
}
