#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsPixmapItem>
#include "personnage.h"

class Pacman : public Personnage
{
public:
    Pacman(float x, float y, int w, int h);
};

#endif // PACMAN_H
