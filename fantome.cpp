#include "fantome.h"

Fantome::Fantome(Fantome::name N):
    Personnage()
{
    this->N=N;
    gobj=new QGraphicsPixmapItem();
}

/**
 * @brief Fantome::Fantome prépare l'affichage des fantômes
 * @param x Position sur la largeur du fantôme
 * @param y Position sur la hauteur du fantôme
 * @param w Taille en largeur du fantôme
 * @param h Taille en hauteur du fantôme
 * @param N Nom du fantôme
 */
Fantome::Fantome(float x, float y, float w, float h,name N)
    :Personnage(x,y,w,h)
{
    this->w=w*0.03; /*!< redimensionnement du fantôme en largeur*/
    this->h=0.062*h; /*!< redimensionnement du fantôme en hauteur*/
    this->y=y-this->h/20+0.06*h; /*!< Evite l'initialisation dans un mur*/
    QPixmap ghost;
    gobj = new QGraphicsPixmapItem();
    this->N=N;
    switch(this->N){
        case blinky:
            ghost.load(":/Sprites/sprites.qrc/res/blinky.png");
            this->x=x+this->w*2;
        break;
        case pinky:
            ghost.load(":/Sprites/sprites.qrc/res/pinky.png");
            this->x=x+this->w/2;
        break;
        case inky:
            ghost.load(":/Sprites/sprites.qrc/res/inky.png");
            this->x=x-this->w*1.5;
        break;
        case clyde:
            ghost.load(":/Sprites/sprites.qrc/res/clyde.png");
            this->x=x-this->w*3;
        break;
    }
    gobj->setPixmap(ghost.scaled(this->w,this->h,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    gobj->setPos(this->x,this->y);
    initx=this->x; /*!< initialisation de la position sur x*/
    inity=this->y; /*!< initialisation de la position sur y*/
}

/**
 * @brief Fantome::getName renvoie le nom du fantôme
 * @return
 */
Fantome::name Fantome::getName(){
    return N;
}

/**
 * @brief Fantome::resize redimensionnement du fantôme
 * @param w largeur du fantôme
 * @param h hauteur du fantôme
 * @return
 */
Fantome * Fantome::resize(int w,int h){
    Fantome *P=new Fantome(w/2,h/2,w,h,this->N);
    P->setdir(this->dir);
    return P;
}
