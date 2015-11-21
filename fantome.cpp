#include "fantome.h"

Fantome::Fantome(float x, float y, float w, float h)
    :Personnage(x,y,w,h)
{
    this->w=w*0.04;
    this->h=0.072*h;
    this->x=x-this->w/2;
    QPixmap ghost;
    gobj = new QGraphicsPixmapItem();
    ghost.load(":/Sprites/sprites.qrc/res/pinky.png");
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x;
    inity=this->y;
}

Fantome * Fantome::resize(int w,int h){
    Fantome *P=new Fantome(w/2+t_xoffset,h/2+t_yoffset,w,h);
    P->setdir(this->dir);
    return P;
}
