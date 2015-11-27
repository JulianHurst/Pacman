#include "fantome.h"

Fantome::Fantome(Fantome::name N):
    Personnage()
{
    this->N=N;
    gobj=new QGraphicsPixmapItem();
}

Fantome::Fantome(float x, float y,name N)
    :Personnage(x,y)
{
    this->w=8;//w*0.03;
    this->h=8;//0.062*h;
    this->y-=8;//y-this->h/20+0.06*h;
    QPixmap ghost;
    gobj = new QGraphicsPixmapItem();
    this->N=N;
    switch(this->N){
        case blinky:
            ghost.load(":/Sprites/sprites.qrc/res/blinky.png");
            this->x+=10;
        break;
        case pinky:
            ghost.load(":/Sprites/sprites.qrc/res/pinky.png");
            //this->x;
        break;
        case inky:
            ghost.load(":/Sprites/sprites.qrc/res/inky.png");
            this->x-=9;
        break;
        case clyde:
            ghost.load(":/Sprites/sprites.qrc/res/clyde.png");
            this->x=x-this->w*2.2;
        break;
    }
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x;
    inity=this->y;
}

Fantome::name Fantome::getName(){
    return N;
}

Fantome * Fantome::resize(int w,int h){
    Fantome *P=new Fantome(w/2,h/2,this->N);
    P->setdir(this->dir);
    return P;
}
