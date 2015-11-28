#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QGraphicsPixmapItem>
#include "labyrinthe.h"

class Personnage
{
public:
    enum direction{
        right,
        left,
        up,
        down,
        none
    };
    Personnage();
    virtual ~Personnage(){delete gobj;}
    Personnage(float x, float y);
    float getx();
    float gety();
    int getw();
    int geth();
    direction getdir();
    void setx(float x);
    void sety(float y);
    void setw(int w);
    void seth(int h);
    void setdir(direction dir);
    QGraphicsPixmapItem *getgobj();    
    void reinit();
    void move(Labyrinthe *l);        
    void CollisionLab();
    virtual Personnage * resize(int w,int h){return new Personnage(w/2,h/2);}


protected:
    QGraphicsPixmapItem *gobj;
    float x,y;
    int w,h;
    int offset;
    int initx,inity;
    direction dir;
};

#endif // PERSONNAGE_H
