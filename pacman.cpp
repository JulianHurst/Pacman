#include "pacman.h"

Pacman::Pacman(float x,float y,int w,int h)
    :Personnage(x,y,w,h)
{    
    this->w=w*0.03;
    this->h=0.062*h;
    this->x=x-this->w/2;    
    QPixmap pac;
    gobj = new QGraphicsPixmapItem();
    pac.load(":/Sprites/sprites.qrc/res/pac.png");
    gobj->setPixmap(pac.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    gobj->setPos(this->x,this->y);
}



