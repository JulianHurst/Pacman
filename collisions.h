#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <QGraphicsPixmapItem>
#include "personnage.h"
#include "fantome.h"
#include "pacman.h"
#include "billearray.h"
#include "fruit.h"
#include "porte.h"

class Collisions
{
public:
    Collisions();
    bool colliding(Pacman *obj1, Fantome *obj2);
    int colliding(Pacman *obj1, BilleArray *obj2);
    bool colliding(Pacman *obj1,Fruit *obj2);
    void colliding(Personnage *obj1,Labyrinthe *obj2);
    void colliding(Pacman *obj1, Porte *obj2);
    bool colliding(Fantome *obj1, Porte *obj2);
};

#endif // COLLISIONS_H
