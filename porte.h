#ifndef PORTE_H
#define PORTE_H

#include <QGraphicsPixmapItem>

class Porte
{
public:
    Porte(float x, float y);
    QGraphicsPixmapItem *getgobj();

private:
    float x,y;
    int w,h;
    QGraphicsPixmapItem *gobj;
};

#endif // PORTE_H
