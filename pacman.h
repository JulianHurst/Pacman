#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsPixmapItem>

class Pacman
{
public:
    Pacman(float x, float y);
    QGraphicsPixmapItem *getgpac();
    int getx();
    int gety();

private:
    QGraphicsPixmapItem *gpac;
    int x,y;
};

#endif // PACMAN_H
