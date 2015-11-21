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
    Personnage(float x, float y, int w, int h);
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
    void setxoffset(int x);
    void setyoffset(int y);
    QGraphicsPixmapItem *getgobj();
    int getxoffset();
    int getyoffset();
    void reinit();
    void move(Labyrinthe *l);        
    void CollisionLab();
    virtual Personnage * resize(int w,int h){return new Personnage(0,0,w,h);}


protected:
    QGraphicsPixmapItem *gobj;
    int x,y;
    int w,h;
    int offset;
    int t_xoffset;
    int t_yoffset;
    int initx,inity;
    direction dir;
};

#endif // PERSONNAGE_H
