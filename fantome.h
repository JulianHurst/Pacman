#ifndef FANTOME_H
#define FANTOME_H

#include "personnage.h"

class Fantome : public Personnage
{
public:
    enum name{
        blinky,
        pinky,
        inky,
        clyde
    };
    Fantome(name N);
    Fantome(float x, float y, float w, float h, name N);
    name getName();
    Fantome * resize(int w,int h);

private:
    name N;
};

#endif // FANTOME_H
