#include "fantome.h"

Fantome::Fantome(float x, float y, int w, int h)
    :Personnage(x,y,w,h)
{
    this->w=w*0.04;
    this->h=0.072*h;
    this->x=x-this->w/2;
    QPixmap ghost;
    gobj = new QGraphicsPixmapItem();
    ghost.load(":/Sprites/sprites.qrc/res/ghost.png");
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    gobj->setPos(this->x,this->y);

}

