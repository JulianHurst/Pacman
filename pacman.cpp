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
    this->w=8;
    this->h=8;
    this->x=x-this->w/2;
    this->y+=50;
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
    Pacman *P=new Pacman(w/2,h/2);
    P->setdir(this->dir);
    return P;
}

void Pacman::CollisionFantome(){
    die();    
}
