#include "fantome.h"
#ifndef Q_OS_WIN32
#define YAXIS 9
#else
#define YAXIS 11
#endif

/**
 * @brief Fantome::Fantome Constructeur de fantôme avec 1 paramètre
 * @param N Nom du fantôme
 */
Fantome::Fantome(Fantome::name N):
    Personnage()
{
    this->N=N;
}

/**
 * @brief Fantome::Fantome Constructeur de fantôme avec 3 paramètre
 * @param x position horizontale
 * @param y position veticale
 * @param N nom du fantôme
 */
Fantome::Fantome(float x, float y,name N)
    :Personnage(x,y)
{
    this->w=8;//w*0.03;
    this->h=8;//0.062*h;
    this->y-=YAXIS;//y-this->h/20+0.06*h;
    QPixmap ghost;
    gobj = new QGraphicsPixmapItem();
    this->N=N;
    switch(this->N){
        case blinky:
            ghost.load(":/Sprites/res/blinky.png");
            this->x+=10;
        break;
        case pinky:
            ghost.load(":/Sprites/res/pinky.png");
        break;
        case inky:
            ghost.load(":/Sprites/res/inky.png");
            this->x-=9;
        break;
        case clyde:
            ghost.load(":/Sprites/res/clyde.png");
            this->x-=19;
        break;
    }    
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x;
    inity=this->y;
    blue=false;
    score=100;
}

int Fantome::getscore(){
    return score;
}

/**
 * @brief Fantome::getName retourne le nom du fantôme
 * @return nom du fantôme
 */
Fantome::name Fantome::getName(){
    return N;
}

/**
 * @brief Fantome::resize Adapte la taille du fantôme
 * @param w largeur
 * @param h hauteur
 * @return
 */
Fantome * Fantome::resize(int w,int h){
    Fantome *P=new Fantome(w/2,h/2,this->N);
    P->setdir(this->dir);
    return P;
}

/**
 * @brief Fantome::getblue retourne l'état du fantôme
 * @return  l'état du fantôme
 */
bool Fantome::getblue(){
    return blue;
}

/**
 * @brief Fantome::blueon charge l'image du fantôme vulnérable
 */
void Fantome::blueon(){
    blue=true;
    QPixmap ghost;
    ghost.load(":/Sprites/res/blueghost.png");
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
}

/**
 * @brief Fantome::blueoff charge l'image du fantôme dans son état normal
 */
void Fantome::blueoff(){
    blue=false;
    QPixmap ghost;
    switch(this->N){
        case blinky:
            ghost.load(":/Sprites/res/blinky.png");
        break;
        case pinky:
            ghost.load(":/Sprites/res/pinky.png");
        break;
        case inky:
            ghost.load(":/Sprites/res/inky.png");
        break;
        case clyde:
            ghost.load(":/Sprites/res/clyde.png");
        break;
    }
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
}
