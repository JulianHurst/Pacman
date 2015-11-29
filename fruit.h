#ifndef FRUIT_H
#define FRUIT_H

#include "bonus.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>

class Fruit : public Bonus
{
public:
    enum name{
        cherry,
        strawberry,
        orange,
        apple,
        grapes,
        galaxian,
        bell,
        key
    };
    Fruit();
    Fruit(float x, float y,name n,int score);

private:
    float x,y;
    int w,h;
    name N;
};

#endif // FRUIT_H
