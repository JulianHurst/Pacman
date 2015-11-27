#include "pacman.h"
#include "fantome.h"
#include <QDebug>

Pacman::Pacman():
    Personnage()
{
    gobj = new QGraphicsPixmapItem();
}

Pacman::Pacman(float x,float y)
    :Personnage(x,y)
{    
    this->w=13;//w*0.03;
    this->h=13;//0.062*h;
    this->x=x-this->w/2;
    this->y+=20;
    this->lives=3;    
    QPixmap pac;
    gobj = new QGraphicsPixmapItem();
    pac.load(":/Sprites/sprites.qrc/res/pac.png");
    gobj->setPixmap(pac.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x;
    inity=this->y;
}

void Pacman::die(){
    lives--;
}

int Pacman::getlives(){
    return lives;
}

void Pacman::setlives(int lives){
    this->lives=lives;
}

Pacman * Pacman::resize(int w,int h){
    Pacman *P=new Pacman(w/2,h/2+(0.15*h));
    P->setdir(this->dir);
    return P;
}

void Pacman::CollisionFantome(){
    die();    
}
