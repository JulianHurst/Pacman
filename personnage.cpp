#include "personnage.h"
#include <QDebug>

Personnage::Personnage(float x, float y, int w, int h)
{
    if(w<=h)
        offset=0.02*w;
    else
        offset=0.02*h;
    t_xoffset=t_yoffset=0;
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
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

void Personnage::setxoffset(int x){
    t_xoffset=x;
}

void Personnage::setyoffset(int y){
    t_yoffset=y;
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

int Personnage::getxoffset(){
    return t_xoffset;
}

int Personnage::getyoffset(){
    return t_yoffset;
}

void Personnage::reinit(){
    x=initx;
    y=inity;
    t_xoffset=t_yoffset=0;
    setdir(none);
    getgobj()->setPos(x,y);
}

void Personnage::move(Labyrinthe *l){
    int width,height;
    width=l->getW();
    height=l->getH();
    switch(dir){
        case right:
            if(x+offset<width){
                x+=offset;
                t_xoffset+=offset;
            }
            else{
                x=0;
                t_xoffset-=width;
            }                     
            break;
        case left:
            if(x-offset>0){
                x-=offset;
                t_xoffset-=offset;
            }
            else{
                qDebug() << "hi";
                x=width;
                t_xoffset+=width;
            }            
            break;
        case up:
            if(y-offset>0){
                y-=offset;
                t_yoffset-=offset;
            }
            else{
                y=height;
                t_yoffset+=height;
            }            
            break;
        case down:
            if(y+offset<height){
                y+=offset;
                t_yoffset+=offset;
            }
            else{
                y=0;
                t_yoffset-=height;
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
            t_xoffset--;
            break;
        case left:
            x++;
            t_xoffset++;
            break;
        case up:
            y++;
            t_yoffset++;
            break;
        case down:
            y--;
            t_yoffset--;
            break;
        case none:
            break;
    }
    getgobj()->setPos(x,y);
}

