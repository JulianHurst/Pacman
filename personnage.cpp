#include "personnage.h"
#include <QDebug>

Personnage::Personnage(){
    this->dir=none;
}

/**
 * @brief Personnage::Personnage Constructeur
 * @param x Position horizontale
 * @param y Position verticale
 * @param w Largeur du personnage
 * @param h Hauteru du personnage
 */
Personnage::Personnage(float x, float y, int w, int h)
{
    if(w<=h)
        offset=0.02*w;
    else
        offset=0.02*h;    
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    dir=none;    
}

//Mutateur
void Personnage::setx(float x){
    this->x=x;
}

void Personnage::sety(float y){
    this->y=y;
}

void Personnage::setw(int w){
    this->w=w;
}

void Personnage::seth(int h){
    this->h=h;
}

void Personnage::setdir(direction dir){
    this->dir=dir;
}

//Accesseur
float Personnage::getx(){
    return x;
}

float Personnage::gety(){
    return y;
}

int Personnage::getw(){
    return w;
}

int Personnage::geth(){
    return h;
}

Personnage::direction Personnage::getdir(){
    return dir;
}

QGraphicsPixmapItem *Personnage::getgobj(){
    return gobj;
}

/**
 * @brief Personnage::reinit
 */
void Personnage::reinit(){
    x=initx;
    y=inity;    
    setdir(none);
    getgobj()->setPos(x,y);
}

/**
 * @brief Personnage::move Permet de le déplacement du personnage en fonction du labyrinthe
 * @param l le labyrinthe courant
 */
void Personnage::move(Labyrinthe *l){
    int width,height;
    width=l->getW();
    height=l->getH();
    switch(dir){
        case right:
            if(x+offset<width){
                x+=offset;                
            }
            else{
                x=0;                
            }                     
            break;
        case left:
            if(x-offset>0){
                x-=offset;                
            }
            else{                
                x=width;                
            }            
            break;
        case up:
            if(y-offset>0){
                y-=offset;                
            }
            else{
                y=height;                
            }            
            break;
        case down:
            if(y+offset<height){
                y+=offset;                
            }
            else{
                y=0;                
            }            
            break;
        case none:
            break;
    }
    getgobj()->setPos(x,y);  
}

/**
 * @brief Personnage::CollisionLab Permet la gestion des collisions avec les murs du labyrinthe
 */
void Personnage::CollisionLab(){
    switch(dir){
        case right:
            x--;
            break;
        case left:
            x++;            
            break;
        case up:
            y++;            
            break;
        case down:
            y--;            
            break;
        case none:
            break;
    }
    getgobj()->setPos(x,y);
}
