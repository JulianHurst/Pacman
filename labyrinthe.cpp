#include "labyrinthe.h"
#include <QDebug>

Labyrinthe::Labyrinthe(float x, float y, int width, int height)
{
    this->x=x;
    this->y=y;
    w=width;
    h=height;
    QPixmap gLab;    
    lab = new QGraphicsPixmapItem();
    gLab.load(":/Sprites/sprites.qrc/res/labyrinthe_pac.png");
    lab->setPixmap(gLab.scaled(w,h,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    lab->setPos(this->x,this->y+0.08*h);
}

QGraphicsPixmapItem *Labyrinthe::getgobj()
{
    return lab;
}

Labyrinthe * Labyrinthe::resize(int w,int h){
    Labyrinthe *L = new Labyrinthe(0,0,w,h);
    return L;
}

int Labyrinthe::getX()
{
    return x;
}

int Labyrinthe::getY()
{
    return y;
}

int Labyrinthe::getW()
{
    return w;
}

int Labyrinthe::getH()
{
    return h;
}
