#include "collisions.h"

#include <QDebug>

/**
 * @brief Collisions::Collisions constructeur par défaut
 */
Collisions::Collisions()
{

}

/**
 * @brief Collisions::colliding collision entre Pacman et les fantomes
 * @param obj1 pointer vers Pacman
 * @param obj2 pointer vers Fantôme
 * @return Vrai si collision, faux sinon
 */
bool Collisions::colliding(Pacman *obj1,Fantome *obj2){
    if(obj1->getgobj()->collidesWithItem(obj2->getgobj(),Qt::IntersectsItemBoundingRect)){
        obj1->CollisionFantome();
        return true;
    }
    return false;
}

/**
 * @brief Collisions::colliding Collision entre pacman et les croquettes
 * @param obj1 pointer vers Pacman
 * @param obj2 pointer vers Croquette
 * @return retourne le numéro de la bille avec laquelle il y a collision sinon
 */
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

/**
 * @brief Collisions::colliding Collision entre Pacman et un fruit
 * @param obj1
 * @param obj2
 * @return
 */
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



