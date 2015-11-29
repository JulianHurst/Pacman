#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsPixmapItem>

class Bonus
{
public:
    Bonus(){}
    Bonus(int score);
    QGraphicsPixmapItem *getgobj();
    int getscore();

protected:
    int score;
    QGraphicsPixmapItem *gobj;
};

#endif // BONUS_H
