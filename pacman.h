#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsPixmapItem>

class Pacman
{
public:
    Pacman(float x, float y, int w, int h);
    QGraphicsPixmapItem *getgpac();
    float getx();
    float gety();
    void setx(int x);
    void sety(int y);

private:
    QGraphicsPixmapItem *gpac;
    int x,y;
    int w,h;
};

#endif // PACMAN_H
