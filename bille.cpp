#include "bille.h"
#include <QPixmap>

Bille::Bille(float x,float y,bool power)
{
    this->x=x;
    this->y=y;
    this->power=power;
    QPixmap B;
    B.load(":/Sprites/res/bille.png");
    gobj=new QGraphicsPixmapItem();
    if(power)
        gobj->setPixmap(B.scaled(4,4,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    else
        gobj->setPixmap(B.scaled(2,2,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    gobj->setPos(x,y);
}

QGraphicsPixmapItem *Bille::getgobj(){
    return gobj;
}

float Bille::getx(){
    return x;
}

float Bille::gety(){
    return y;
}

bool Bille::getpower(){
    return power;
}

void Bille::setx(float x){
    this->x=x;
}

void Bille::sety(float y){
    this->y=y;
}
