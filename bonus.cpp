#include "bonus.h"

Bonus::Bonus(QPixmap map,QPointF position,int nbPoint)
{
  this->modeleGraphique=new ModeleG(position,map);
  this->nbPoint=nbPoint;
}

Bonus::Bonus()
{

}

ModeleG* Bonus::getModeleG()
{
    return modeleGraphique;
}

int Bonus::getNbPoint()
{
    return nbPoint;
}
