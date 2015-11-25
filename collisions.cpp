#include "collisions.h"

#include <QDebug>

Collisions::Collisions()
{

}

/**
 * @brief Collisions::colliding Gestion de la collision entre Pacman et les Fanômes
 * @param obj1 Pointe vers Pacman
 * @param obj2 Pointe vers un des fantômes
 * @return
 */
bool Collisions::colliding(Pacman *obj1,Fantome *obj2){
    if(obj1->getgobj()->collidesWithItem(obj2->getgobj(),Qt::IntersectsItemBoundingRect)){
        obj1->CollisionFantome();
        return true;
    }
    return false;
}

/**
 * @brief Collisions::colliding Gestion de la collision entre les personnages et le mur
 * @param obj1 Pointe vers le personnage à tester (Pacman, Fantômes)
 * @param obj2 Pointe vers le labyrinthe
 */
void Collisions::colliding(Personnage *obj1, Labyrinthe *obj2){    
    while(obj1->getgobj()->collidesWithItem(obj2->getgobj(),Qt::IntersectsItemBoundingRect))
        obj1->CollisionLab();
}

