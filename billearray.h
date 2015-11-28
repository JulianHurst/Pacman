#ifndef BILLEARRAY_H
#define BILLEARRAY_H

#include "bille.h"
#include "pacman.h"
#include "labyrinthe.h"

class BilleArray
{
public:
    BilleArray(float x, float y, float xoffset, float yoffset, Labyrinthe *l, Pacman *P, Fantome *F);
    ~BilleArray();
    Bille *at(int i);
    int getlength();
    void rearrange(int i);

private:
    Bille **B;
    int length;
};

#endif // BILLEARRAY_H
