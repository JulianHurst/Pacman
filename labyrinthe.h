#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <QGraphicsPixmapItem>

class Labyrinthe
{
public:
    Labyrinthe(float,float);
    int getX();
    int getY();
    QGraphicsPixmapItem *getLab();

private:
    int x;
    int y;
    QGraphicsPixmapItem *lab;
};

#endif // LABYRINTHE_H
