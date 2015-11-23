#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <QGraphicsPixmapItem>

class Labyrinthe
{
public:
    Labyrinthe(float, float, int, int);
    int getX();
    int getY();
    int getW();
    int getH();
    QGraphicsPixmapItem *getgobj();
    Labyrinthe * resize(int w,int h);

private:
    int x;
    int y;
    int w;
    int h;
    QGraphicsPixmapItem *lab;
};

#endif // LABYRINTHE_H
