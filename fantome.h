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
    Fantome(float x, float y, name N);
    name getName();
    bool getblue();
    int getscore();
    Fantome * resize(int w,int h);
    void blueon();
    void blueoff();

private:
    name N;
    bool blue;
    int score;
};

#endif // FANTOME_H
