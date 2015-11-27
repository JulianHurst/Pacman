#include "labyrinthe.h"
#include <QDebug>

Labyrinthe::Labyrinthe(float x, float y, int width, int height)
{
    this->x=x;
    this->y=y;
    w=width/2;
    h=height-20;
    QPixmap gLab;    
    lab = new QGraphicsPixmapItem();
    gLab.load(":/Sprites/sprites.qrc/res/maze1.png");
    lab->setPixmap(gLab.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    lab->setPos(this->x+w/2,this->y+0.05*h);
    w=this->x+w/2+w;
    h=this->y+0.05*h+h-10;

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
