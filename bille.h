#ifndef BILLE_H
#define BILLE_H

#include <QGraphicsPixmapItem>

class Bille
{
public:
    Bille(float x, float y);
    QGraphicsPixmapItem *getgobj();
    float getx();
    float gety();
    void setx(float x);
    void sety(float y);

private:
    float x,y;
    QGraphicsPixmapItem *gobj;
};

#endif // BILLE_H
