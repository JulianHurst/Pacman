#include "porte.h"
#ifndef Q_OS_WIN32
#define YAXIS 18.2
#else
#define YAXIS 22.2
#endif

Porte::Porte(float x,float y)
{
    this->w=12;
    this->h=2;
    this->x=x-6.5;
    this->y=y-YAXIS;
    QPixmap door;
    gobj = new QGraphicsPixmapItem();
    door.load(":/Sprites/res/porte.png");
    gobj->setPixmap(door.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
}

QGraphicsPixmapItem *Porte::getgobj(){
    return gobj;
}
