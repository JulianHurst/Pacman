#ifndef FANTOME_H
#define FANTOME_H

#include "personnage.h"

class Fantome : public Personnage
{
public:
    Fantome(float x, float y, float w, float h);
    Fantome * resize(int w,int h);
};

#endif // FANTOME_H
