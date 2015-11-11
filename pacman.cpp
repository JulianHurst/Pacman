#include "pacman.h"

Pacman::Pacman(float x,float y,int w,int h)
{
    this->w=w*0.03;
    this->h=0.062*h;
    this->x=x-this->w/2;
    this->y=y;
    QPixmap pac;
    gpac = new QGraphicsPixmapItem();    
    pac.load(":/Sprites/sprites.qrc/pac.png");    
    gpac->setPixmap(pac.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::FastTransformation));
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

