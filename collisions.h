#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <QGraphicsPixmapItem>
#include "personnage.h"
#include "fantome.h"
#include "pacman.h"

class Collisions
{
public:
    Collisions();
    bool colliding(Pacman *obj1, Fantome *obj2);
    void colliding(Personnage *obj1,Labyrinthe *obj2);

};

#endif // COLLISIONS_H
