#include "pacman.h"
#include "fantome.h"
#include <QDebug>
#include <QPainter>
#ifndef Q_OS_WIN32
#define YAXIS 52
#else
#define YAXIS 50
#endif

Pacman::Pacman(): Personnage(){}

/**
 * @brief Pacman::Pacman Constructeur avec deux paramètre de pacman
 * @param x postion horizontale
 * @param y position verticale
 */
Pacman::Pacman(float x,float y)
    :Personnage(x,y)
{    
    this->w=8;
    this->h=8;
    this->x=x-this->w/2;
    this->y+=YAXIS;
    this->lives=3;    
    QPixmap pac;
    gobj = new QGraphicsPixmapItem();
    pac.load(":/Sprites/res/pac1.png");
    gobj->setPixmap(pac.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x;
    inity=this->y;
    animleft=animright=animup=animdown=animdying=0;
    power=false;
    powertimer=0;
}

/**
 * @brief Pacman::die réduit le nombre de vie de Pacman lorsqu'il meurt
 */
void Pacman::die(){
    lives--;
}

/**
 * @brief Pacman::getpower retourne l'état de puissance de pacman
 * @return l'état de pacman
 */
bool Pacman::getpower(){
    return power;
}

/**
 * @brief Pacman::powerup Passe le power à true, et sa durée à 50
 */
void Pacman::powerup(){
    power=true;
    powertimer=50;
}

/**
 * @brief Pacman::powerdown baisse le temps du power et le désactive lorsque celui ci est à zéro
 */
void Pacman::powerdown(){
    powertimer--;
    if(powertimer==0)
        power=false;
}

/**
 * @brief Pacman::getlives retourne le nombre de vie
 * @return nombre de vie
 */
int Pacman::getlives(){
    return lives;
}

/**
 * @brief Pacman::setlives définit le nombre de vie
 * @param lives nouveau nombre de vie
 */
void Pacman::setlives(int lives){
    this->lives=lives;
}

/**
 * @brief Pacman::resize adapte la taille de pacman
 * @param w largeur
 * @param h hauteur
 * @return pacman
 */
Pacman * Pacman::resize(int w,int h){
    Pacman *P=new Pacman(w/2,h/2);
    P->setdir(this->dir);
    return P;
}

/**
 * @brief Pacman::CollisionFantome déclenche la mort de pacman lors d'une collision avec un fantôme
 */
void Pacman::CollisionFantome(){
    if(!power)
        die();
}

/**
 * @brief Pacman::animate animation de pacman
 */
void Pacman::animate(){
    QPixmap pac;
    switch(dir){
        case left:
            if(animleft==0)
                pac.load(":/Sprites/res/pacleft1.png");
            else if(animleft==1){
                pac.load(":/Sprites/res/pacleft2.png");
                animleft=-1;
            }
            animleft++;
            break;
        case right:
            if(animright==0)
                pac.load(":/Sprites/res/pacright1.png");
            else if(animright==1){
                pac.load(":/Sprites/res/pacright2.png");
                animright=-1;
            }
            animright++;
            break;
        case up:
            if(animup==0)
                pac.load(":/Sprites/res/pacup1.png");
            else if(animup==1){
                pac.load(":/Sprites/res/pacup2.png");
                animup=-1;
            }
            animup++;
            break;
        case down:
            if(animdown==0)
                pac.load(":/Sprites/res/pacdown1.png");
            else if(animdown==1){
                pac.load(":/Sprites/res/pacdown2.png");
                animdown=-1;
            }
            animdown++;
            break;
        case none:
            animleft=animright=animup=animdown=animdying=0;
            pac.load(":/Sprites/res/pac1.png");
            break;
        default:
            animleft=animright=animup=animdown=animdying=0;
            pac.load(":/Sprites/res/pac1.png");
    }
    gobj->setPixmap(pac.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
}
