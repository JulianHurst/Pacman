#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <QGraphicsPixmapItem>

class Labyrinthe
{
public:
    Labyrinthe(float, float, int, int);
    int getX();
    int getY();
    QGraphicsPixmapItem *getLab();
    QColor getCouleur();

private:
    int x;
    int y;
    QGraphicsPixmapItem *lab;
    QColor couleurMur;
};

#endif // LABYRINTHE_H
