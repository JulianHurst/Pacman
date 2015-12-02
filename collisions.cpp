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

int Collisions::colliding(Pacman *obj1,BilleArray *obj2){
    for(int i=0;i<obj2->getlength();i++){
        if(obj1->getgobj()->collidesWithItem(obj2->at(i)->getgobj(),Qt::IntersectsItemBoundingRect)){
            if(obj2->at(i)->getpower())
                obj1->powerup();
            return i;
        }
    }
    return -1;
}

bool Collisions::colliding(Pacman *obj1,Fruit *obj2){
    return obj1->getgobj()->collidesWithItem(obj2->getgobj());
}

void Collisions::colliding(Pacman *obj1, Porte *obj2){
    bool collision=false;
    while(obj1->getgobj()->collidesWithItem(obj2->getgobj(),Qt::IntersectsItemBoundingRect)){
        obj1->CollisionLab();
        collision=true;
    }
    if(collision)
        obj1->setdir(Personnage::none);
}

bool Collisions::colliding(Fantome *obj1, Porte *obj2){
    return obj1->getgobj()->collidesWithItem(obj2->getgobj());
}

void Collisions::colliding(Personnage *obj1, Labyrinthe *obj2){    
    bool collision=false;
    while(obj1->getgobj()->collidesWithItem(obj2->getgobj(),Qt::IntersectsItemBoundingRect)){
        obj1->CollisionLab();
        collision=true;
    }
    if(collision)
        obj1->setdir(Personnage::none);
}



