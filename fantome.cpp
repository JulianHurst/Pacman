#include "fantome.h"
#ifndef Q_OS_WIN32
#define YAXIS 9
#else
#define YAXIS 11
#endif

Fantome::Fantome(Fantome::name N):
    Personnage()
{
    this->N=N;
}

Fantome::Fantome(float x, float y,name N)
    :Personnage(x,y)
{
    this->w=8;//w*0.03;
    this->h=8;//0.062*h;
    this->y-=YAXIS;//y-this->h/20+0.06*h;
    QPixmap ghost;
    gobj = new QGraphicsPixmapItem();
    this->N=N;
    switch(this->N){
        case blinky:
            ghost.load(":/Sprites/res/blinky.png");
            this->x+=10;
        break;
        case pinky:
            ghost.load(":/Sprites/res/pinky.png");
        break;
        case inky:
            ghost.load(":/Sprites/res/inky.png");
            this->x-=9;
        break;
        case clyde:
            ghost.load(":/Sprites/res/clyde.png");
            this->x-=19;
        break;
    }    
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x;
    inity=this->y;
    blue=false;
    score=100;
}

int Fantome::getscore(){
    return score;
}

Fantome::name Fantome::getName(){
    return N;
}

Fantome * Fantome::resize(int w,int h){
    Fantome *P=new Fantome(w/2,h/2,this->N);
    P->setdir(this->dir);
    return P;
}

bool Fantome::getblue(){
    return blue;
}

void Fantome::blueon(){
    blue=true;
    QPixmap ghost;
    ghost.load(":/Sprites/res/blueghost.png");
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
}

void Fantome::blueoff(){
    blue=false;
    QPixmap ghost;
    switch(this->N){
        case blinky:
            ghost.load(":/Sprites/res/blinky.png");
        break;
        case pinky:
            ghost.load(":/Sprites/res/pinky.png");
        break;
        case inky:
            ghost.load(":/Sprites/res/inky.png");
        break;
        case clyde:
            ghost.load(":/Sprites/res/clyde.png");
        break;
    }
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
}
