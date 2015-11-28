#ifndef BILLE_H
#define BILLE_H

#include <QGraphicsPixmapItem>

class Bille
{
public:
    Bille(float x, float y, bool power);
    QGraphicsPixmapItem *getgobj();
    float getx();
    float gety();
    bool getpower();
    void setx(float x);
    void sety(float y);

private:
    float x,y;
    QGraphicsPixmapItem *gobj;
    bool power;
};

#endif // BILLE_H
