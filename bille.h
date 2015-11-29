#ifndef BILLE_H
#define BILLE_H

#include "bonus.h"
#include <QGraphicsPixmapItem>

class Bille : public Bonus
{
public:
    Bille(float x, float y, bool power, int score);
    float getx();
    float gety();
    bool getpower();    
    void setx(float x);
    void sety(float y);

private:
    float x,y;    
    bool power;    
};

#endif // BILLE_H
