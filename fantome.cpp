#include "fantome.h"

Fantome::Fantome(float x, float y, float w, float h,name N)
    :Personnage(x,y,w,h)
{
    this->w=w*0.03;
    this->h=0.062*h;
    this->y=y-this->h/20+0.06*h;
    QPixmap ghost;
    gobj = new QGraphicsPixmapItem();
    this->N=N;
    switch(this->N){
        case blinky:
            ghost.load(":/Sprites/sprites.qrc/res/blinky.png");
            this->x=x+this->w*2;
        break;
        case pinky:
            ghost.load(":/Sprites/sprites.qrc/res/pinky.png");
            this->x=x+this->w/2;
        break;
        case inky:
            ghost.load(":/Sprites/sprites.qrc/res/inky.png");
            this->x=x-this->w*1.5;
        break;
        case clyde:
            ghost.load(":/Sprites/sprites.qrc/res/clyde.png");
            this->x=x-this->w*3;
        break;
    }
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x;
    inity=this->y;
}

Fantome::name Fantome::getName(){
    return N;
}

Fantome * Fantome::resize(int w,int h){
    Fantome *P=new Fantome(w/2+t_xoffset,h/2+t_yoffset,w,h,this->N);
    P->setdir(this->dir);
    return P;
}
