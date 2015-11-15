#include "labyrinthe.h"
#include <QDebug>

Labyrinthe::Labyrinthe(float x, float y, int width, int height)
{
    this->x=x;
    this->y=y;
    QPixmap gLab;    
    lab = new QGraphicsPixmapItem();
    gLab.load(":/Sprites/sprites.qrc/res/labyrinthe_pac_port.png");
    lab->setPixmap(gLab.scaled(width,height,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    lab->setPos(this->x,this->y);
}

QGraphicsPixmapItem *Labyrinthe::getLab()
{
    return lab;
}

int Labyrinthe::getX()
{
    return x;
}

int Labyrinthe::getY()
{
    return y;
}
