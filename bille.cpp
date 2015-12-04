#include "bille.h"
#include <QPixmap>

/**
 * @brief Bille::Bille Constructeur avec paramètre d'une croquette
 * @param x Position horizontale de la croquette
 * @param y Position verticale de la croquette
 * @param power état de la croquette
 * @param score
 */
Bille::Bille(float x,float y,bool power,int score):
    Bonus(score)
{
    this->x=x;
    this->y=y;
    this->power=power;
    QPixmap B;
    B.load(":/Sprites/res/bille.png");
    gobj=new QGraphicsPixmapItem();
    if(power){
        gobj->setPixmap(B.scaled(4,4,Qt::IgnoreAspectRatio,Qt::FastTransformation));
        this->score+=40;
    }
    else{
        gobj->setPixmap(B.scaled(2,2,Qt::IgnoreAspectRatio,Qt::FastTransformation));        
    }
    gobj->setPos(x,y);
}

/**
 * @brief Bille::getx retourne position horizontale de la croquette
 * @return position horizontale
 */
float Bille::getx(){
    return x;
}

/**
 * @brief Bille::gety retourne la position verticale de la croquette
 * @return position verticale
 */
float Bille::gety(){
    return y;
}

/**
 * @brief Bille::getpower retourne l'état de la croquette
 * @return état de la croquette
 */
bool Bille::getpower(){
    return power;
}

/**
 * @brief Bille::setx modifie la position à l'horizontale de la croquette
 * @param x nouvelle position
 */
void Bille::setx(float x){
    this->x=x;
}

/**
 * @brief Bille::sety modifie la position à la verticale de la croquette
 * @param y nouvelle position à la verticale
 */
void Bille::sety(float y){
    this->y=y;
}
