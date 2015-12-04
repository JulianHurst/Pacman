#include "fruit.h"
#ifndef Q_OS_WIN32
#define YAXIS 52
#else
#define YAXIS 50
#endif

Fruit::Fruit():
Bonus()
{
    gobj=new QGraphicsPixmapItem();
}

/**
 * @brief Fruit::Fruit constructeur de fruit avec 4 paramètres
 * @param x position horizontale
 * @param y position verticale
 * @param n nom du fruit
 * @param score
 */
Fruit::Fruit(float x, float y, name n, int score):
    Bonus(score)
{
    w=8;
    h=8;
    this->x=x-4;
    this->y=y+YAXIS;
    QPixmap fruit;
    gobj=new QGraphicsPixmapItem();
    switch(n){
        case cherry:
            fruit.load(":/Sprites/res/cherry.png");
            break;
        case strawberry:
            fruit.load(":/Sprites/res/strawberry.png");
            this->score+=200;
            break;
        case orange:
            fruit.load(":/Sprites/res/orange.png");
            this->score+=400;
            break;
        case apple:
            fruit.load(":/Sprites/res/apple.png");
            this->score+=600;
            break;
        case grapes:
            fruit.load(":/Sprites/res/grapes.png");
            this->score+=900;
            break;
        case galaxian:
            fruit.load(":/Sprites/res/galaxian.png");
            this->score+=1900;
            break;
        case bell:
            fruit.load(":/Sprites/res/bell.png");
            this->score+=2900;
            break;
        case key:
            fruit.load(":/Sprites/res/key.png");
            this->score+=4900;
            break;
    }
    gobj->setPixmap(fruit.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gobj->setPos(this->x,this->y);
}


