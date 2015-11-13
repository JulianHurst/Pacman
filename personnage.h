#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QGraphicsPixmapItem>

class Personnage
{
public:
    Personnage(float x, float y, int w, int h);
    float getx();
    float gety();
    int getw();
    int geth();
    void setx(float x);
    void sety(float y);
    void setw(int w);
    void seth(int h);
    QGraphicsPixmapItem *getgobj();

protected:
    QGraphicsPixmapItem *gobj;
    int x,y;
    int w,h;
};

#endif // PERSONNAGE_H
