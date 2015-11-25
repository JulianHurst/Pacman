#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <QGraphicsPixmapItem>
#include <QImage>

class Labyrinthe
{
public:
    Labyrinthe(float, float, int, int);
    int getX();
    int getY();
<<<<<<< HEAD
    QGraphicsPixmapItem *getLab();
    void openImage();
=======
    int getW();
    int getH();
    QGraphicsPixmapItem *getgobj();
    Labyrinthe * resize(int w,int h);
>>>>>>> 0010544ea39580fd112fb525f4821e95dbdde665

private:
    int x;
    int y;
    int w;
    int h;
    QGraphicsPixmapItem *lab;
};

#endif // LABYRINTHE_H
