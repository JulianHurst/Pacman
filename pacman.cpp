#include "pacman.h"
#include "fantome.h"
#include <QDebug>
#include <QPainter>
#ifndef Q_OS_WIN32
#define YAXIS 53
#else
#define YAXIS 50
#endif

Pacman::Pacman():
    Personnage()
{
    gobj = new QGraphicsPixmapItem();
}

Pacman::Pacman(float x,float y)
    :Personnage(x,y)
{    
    this->w=8;
    this->h=8;
    this->x=x-this->w/2;
    this->y+=YAXIS;
    this->lives=3;    
    QPixmap pac;
    gobj = new QGraphicsPixmapItem();
    pac.load(":/Sprites/res/pac1.png");
    gobj->setPixmap(pac.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x;
    inity=this->y;
    animleft=animright=animup=animdown=animdying=0;
    power=false;
    powertimer=0;
}

void Pacman::die(){
    lives--;
}

bool Pacman::getpower(){
    return power;
}

void Pacman::powerup(){
    power=true;
    powertimer=50;
}

void Pacman::powerdown(){
    powertimer--;
    if(powertimer==0)
        power=false;
}

int Pacman::getlives(){
    return lives;
}

void Pacman::setlives(int lives){
    this->lives=lives;
}

Pacman * Pacman::resize(int w,int h){
    Pacman *P=new Pacman(w/2,h/2);
    P->setdir(this->dir);
    return P;
}

void Pacman::CollisionFantome(){
    if(!power)
        die();
}

void Pacman::animate(){
    QPixmap pac;
    switch(dir){
        case left:
            if(animleft==0)
                pac.load(":/Sprites/res/pacleft1.png");
            else if(animleft==1){
                pac.load(":/Sprites/res/pacleft2.png");
                animleft=-1;
            }
            animleft++;
            break;
        case right:
            if(animright==0)
                pac.load(":/Sprites/res/pacright1.png");
            else if(animright==1){
                pac.load(":/Sprites/res/pacright2.png");
                animright=-1;
            }
            animright++;
            break;
        case up:
            if(animup==0)
                pac.load(":/Sprites/res/pacup1.png");
            else if(animup==1){
                pac.load(":/Sprites/res/pacup2.png");
                animup=-1;
            }
            animup++;
            break;
        case down:
            if(animdown==0)
                pac.load(":/Sprites/res/pacdown1.png");
            else if(animdown==1){
                pac.load(":/Sprites/res/pacdown2.png");
                animdown=-1;
            }
            animdown++;
            break;
        case none:
            animleft=animright=animup=animdown=animdying=0;
            pac.load(":/Sprites/res/pac1.png");
            break;
        default:
            animleft=animright=animup=animdown=animdying=0;
            pac.load(":/Sprites/res/pac1.png");
    }
    gobj->setPixmap(pac.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
}
