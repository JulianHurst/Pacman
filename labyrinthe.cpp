#include "labyrinthe.h"

Labyrinthe::Labyrinthe(float x, float y)
{
    this->x=x;
    this->y=y;
    QPixmap gLab;
    lab = new QGraphicsPixmapItem();
    gLab.load(":/Sprites/sprites.qrc/labyrinthe_pac.png");
    lab->setPixmap(gLab);
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

