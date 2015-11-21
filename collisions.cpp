#include "collisions.h"

#include <QDebug>

Collisions::Collisions()
{

}

bool Collisions::colliding(Pacman *obj1,Fantome *obj2){
    if(obj1->getgobj()->collidesWithItem(obj2->getgobj(),Qt::IntersectsItemBoundingRect)){
        obj1->CollisionFantome();
        return true;
    }
    return false;
}

void Collisions::colliding(Personnage *obj1, Labyrinthe *obj2){
    while(obj1->getgobj()->collidesWithItem(obj2->getgobj(),Qt::IntersectsItemBoundingRect))
        obj1->CollisionLab();
}

