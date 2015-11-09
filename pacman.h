#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsPixmapItem>

class Pacman
{
public:
    Pacman(float x, float y);
    QGraphicsPixmapItem *getgpac();
    float getx();
    float gety();
    void setx(int x);
    void sety(int y);

private:
    QGraphicsPixmapItem *gpac;
    int x,y;
};

#endif // PACMAN_H
