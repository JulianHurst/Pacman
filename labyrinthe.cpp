#include "labyrinthe.h"
#include <QDebug>

Labyrinthe::Labyrinthe(float x, float y, int width, int height)
{
    QRgb pixel;
    this->x=x;
    this->y=y;
    QPixmap gLab;    
    lab = new QGraphicsPixmapItem();
    gLab.load(":/Sprites/sprites.qrc/res/labyrinthe_pac.png");
    lab->setPixmap(gLab.scaled(width,height,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    lab->setPos(this->x,this->y);
    pixel=gLab.toImage().pixel(0,0);
    couleurMur.setRgb(pixel);
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
<<<<<<< HEAD

QColor Labyrinthe::getCouleur()
{
    return couleurMur;
}

=======
>>>>>>> master
