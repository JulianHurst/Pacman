#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsPixmapItem>
#include "personnage.h"

class Pacman : public Personnage
{
public:
    Pacman(float x, float y, int w, int h);
    void die();
    int getlives();
    void setlives(int lives);

private:
    int lives;
};

#endif // PACMAN_H
