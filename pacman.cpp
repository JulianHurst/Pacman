#include "pacman.h"
#include "fantome.h"
#include <QDebug>

/**
 * @brief Pacman::Pacman constructeur par défaut de pacman
 */
Pacman::Pacman():
    Personnage()
{
    gobj = new QGraphicsPixmapItem();
}

/**
 * @brief Pacman::Pacman Constructeur avec paramètre de pacman
 * @param x position de pacman sur la largeur
 * @param y position de pacman sur la hauteur
 * @param w taille de pacman en largeur
 * @param h taille de pacman en hauteur
 */
Pacman::Pacman(float x,float y,double w,double h)
    :Personnage(x,y,w,h)
{    
    this->w=w*0.03; /*!< redimensionnement sur la largeur*/
    this->h=0.062*h; /*!< redimensionnement sur la hauteur*/
    this->x=x-this->w/2;
    this->y+=0.08*h;
    this->lives=3;    
    QPixmap pac;
    gobj = new QGraphicsPixmapItem();
    pac.load(":/Sprites/sprites.qrc/res/pac.png");
    gobj->setPixmap(pac.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x;
    inity=this->y;
}

/**
 * @brief Pacman::die réduit le nombre de vie de pacman
 */
void Pacman::die(){
    lives--;
}

/**
 * @brief Pacman::getlives renvoie le nombre de vie courante
 * @return
 */
int Pacman::getlives(){
    return lives;
}

/**
 * @brief Pacman::setlives permet d'attribuer un nombre de vie
 * @param lives
 */
void Pacman::setlives(int lives){
    this->lives=lives;
}

/**
 * @brief Pacman::resize redimensionne le pacman
 * @param w largeur de pacman
 * @param h hauteur de pacman
 * @return pacman redimensionné
 */
Pacman * Pacman::resize(int w,int h){
    Pacman *P=new Pacman(w/2,h/2+(0.15*h),w,h);
    P->setdir(this->dir);
    return P;
}

void Pacman::CollisionFantome(){
    die();    
}
