#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsPixmapItem>
#include "personnage.h"
#include "fantome.h"

class Pacman : public Personnage
{
public:
    Pacman();
    Pacman(float x, float y);
    void die();
    int getlives();
    void setlives(int lives);    
    void CollisionFantome();
    Pacman * resize(int w,int h);

private:
    int lives;    
};

#endif // PACMAN_H
