#include "personnage.h"

Personnage::Personnage(float x, float y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
}

void Personnage::setx(float x){
    this->x=x;
}

void Personnage::sety(float y){
    this->y=y;
}

void Personnage::setw(int w){
    this->w=w;
}

void Personnage::seth(int h){
    this->h=h;
}


float Personnage::getx(){
    return x;
}

float Personnage::gety(){
    return y;
}

int Personnage::getw(){
    return w;
}

int Personnage::geth(){
    return h;
}

QGraphicsPixmapItem *Personnage::getgobj(){
    return gobj;
}

