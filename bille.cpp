#include "bille.h"
#include <QPixmap>

Bille::Bille(float x,float y)
{
    this->x=x;
    this->y=y;
    QPixmap B;
    B.load(":/Sprites/sprites.qrc/res/bille.png");
    gobj=new QGraphicsPixmapItem();
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

void Bille::setx(float x){
    this->x=x;
}

void Bille::sety(float y){
    this->y=y;
}
