#include "bonus.h"

Bonus::Bonus(int score)
{
    this->score=score;
}

QGraphicsPixmapItem *Bonus::getgobj(){
    return gobj;
}

int Bonus::getscore(){
    return score;
}
