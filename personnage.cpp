#include "personnage.h"
#include <QDebug>


Personnage::Personnage(){
    this->dir=none;
    gobj=new QGraphicsPixmapItem();
}

Personnage::Personnage(float x, float y)
{
    if(w<=h)
        offset=2;
    else
        offset=2;
    this->x=x;
    this->y=y;   
    dir=none;    
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

void Personnage::setdir(direction dir){
    this->dir=dir;
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

Personnage::direction Personnage::getdir(){
    return dir;
}

QGraphicsPixmapItem *Personnage::getgobj(){
    return gobj;
}

void Personnage::reinit(){
    x=initx;
    y=inity;    
    setdir(none);
    getgobj()->setPos(x,y);
}

void Personnage::move(Labyrinthe *l){
    switch(dir){
        case right:
            if(x+offset<l->getW()-w){
                x+=offset;                
            }
            else{
                x=l->getX();
            }                     
            break;
        case left:
            if(x-offset>l->getX()){
                x-=offset;                
            }
            else{                
                x=l->getW();
            }            
            break;
        case up:
            if(y-offset>l->getY()+h){
                y-=offset;                
            }
            else{
                y=l->getH();
            }            
            break;
        case down:
            if(y+offset<l->getH()){
                y+=offset;                
            }
            else{
                y=l->getY()+h;
            }            
            break;
        case none:
            break;
    }
    getgobj()->setPos(x,y);  
}

void Personnage::CollisionLab(){
    switch(dir){
        case right:
            x--;
            break;
        case left:
            x++;            
            break;
        case up:
            y++;            
            break;
        case down:
            y--;            
            break;
        case none:
            break;
    }
    getgobj()->setPos(x,y);
}
