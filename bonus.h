#ifndef BONUS_H
#define BONUS_H
#include "modeleg.h"

class Bonus
{
public:
    Bonus(QPixmap,QPointF,int);
    Bonus();
    ModeleG* getModeleG();
    int getNbPoint();
protected:
    ModeleG* modeleGraphique;
    int nbPoint;


};

#endif // BONUS_H
