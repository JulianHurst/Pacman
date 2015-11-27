#ifndef BILLEARRAY_H
#define BILLEARRAY_H

#include "bille.h"
#include "labyrinthe.h"

class BilleArray
{
public:
    BilleArray(float x, float y, float xoffset, float yoffset, Labyrinthe *l);
    ~BilleArray();
    Bille *at(int i);
    int getlength();

private:
    Bille **B;
    int length;
};

#endif // BILLEARRAY_H
