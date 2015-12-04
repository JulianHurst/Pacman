#include "personnage.h"
#include <QDebug>


Personnage::Personnage(){
    this->dir=none;
    gobj=new QGraphicsPixmapItem();
}
/**
 * @brief Personnage::Personnage constructeur avec paramètre de personnage
 * @param x position horizontale
 * @param y position verticale
 */
Personnage::Personnage(float x, float y)
{
    if(w<=h)
        offset=2;
    else
        offset=2;
    this->x=x;
    this->y=y;   
    dir=none;    
}

/**
 * @brief Personnage::setx modifie la position horizontale
 * @param x nouvelle position horizontale
 */
void Personnage::setx(float x){
    this->x=x;
}

/**
 * @brief Personnage::sety modifie la position verticale
 * @param y nouvelle position verticale
 */
void Personnage::sety(float y){
    this->y=y;
}

/**
 * @brief Personnage::setw modifie la largeur
 * @param w largeur
 */
void Personnage::setw(int w){
    this->w=w;
}

/**
 * @brief Personnage::seth modifie hauteur
 * @param h hauteur
 */
void Personnage::seth(int h){
    this->h=h;
}

/**
 * @brief Personnage::setdir change la direction
 * @param dir nouvelle direction
 */
void Personnage::setdir(direction dir){
    this->dir=dir;
}

/**
 * @brief Personnage::getx
 * @return position horizontale
 */
float Personnage::getx(){
    return x;
}

/**
 * @brief Personnage::gety
 * @return position verticale
 */
float Personnage::gety(){
    return y;
}

/**
 * @brief Personnage::getw
 * @return largeur
 */
int Personnage::getw(){
    return w;
}

/**
 * @brief Personnage::geth
 * @return hauteur
 */
int Personnage::geth(){
    return h;
}

/**
 * @brief Personnage::getdir
 * @return direction
 */
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
 * @brief Personnage::move gère le déplacement d'un personnage dans le labyrinthe
 * @param l pointeur vers le labyrinthe
 */
void Personnage::move(Labyrinthe *l){
    switch(dir){
        case right:
            if(x+offset<l->getW()-w){
                x+=offset;                
            }
            else{
                x=l->getX();
            }                     
            break;
        case left:
            if(x-offset>l->getX()){
                x-=offset;                
            }
            else{                
                x=l->getW();
            }            
            break;
        case up:
            if(y-offset>l->getY()+h){
                y-=offset;                
            }
            else{
                y=l->getH();
            }            
            break;
        case down:
            if(y+offset<l->getH()){
                y+=offset;                
            }
            else{
                y=l->getY()+h;
            }            
            break;
        case none:
            break;
    }
    getgobj()->setPos(x,y);  
}

/**
 * @brief Personnage::CollisionLab gestion de la position du personnage en cas de collision avec un mur du labyrinthe
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
