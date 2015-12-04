#include "labyrinthe.h"
#include <QDebug>

/**
 * @brief Labyrinthe::Labyrinthe constructeur avec 4 paramètre du labyrinthe
 * @param x position horizontale
 * @param y position verticale
 * @param width largeur
 * @param height hauteur
 */
Labyrinthe::Labyrinthe(float x, float y, int width, int height)
{
    this->x=x;
    this->y=y;
    w=width/2;
    h=height-20;
    QPixmap gLab;    
    lab = new QGraphicsPixmapItem();
    gLab.load(":/Sprites/res/maze.png");
    lab->setPixmap(gLab.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    this->x+=w/2;
    this->y+=0.05*h;
    lab->setPos(this->x,this->y);
    w=this->x+w;
    h=this->y+h-10;

}

/**
 * @brief Labyrinthe::getgobj retourne le labyrinthe
 * @return labyrinthe
 */
QGraphicsPixmapItem *Labyrinthe::getgobj()
{
    return lab;
}

/**
 * @brief Labyrinthe::resize adapte la taille du labyrinthe
 * @param w largeur
 * @param h hauteur
 * @return  Le labyrinthe mis à la bonne taille
 */
Labyrinthe * Labyrinthe::resize(int w,int h){
    Labyrinthe *L = new Labyrinthe(0,0,w,h);
    return L;
}

/**
 * @brief Labyrinthe::getX retourne la position horizontale
 * @return  position horizontale
 */
int Labyrinthe::getX()
{
    return x;
}

/**
 * @brief Labyrinthe::getY retourne la position verticale
 * @return position verticale
 */
int Labyrinthe::getY()
{
    return y;
}

/**
 * @brief Labyrinthe::getW retourne la largeur du labyrinthe
 * @return largeur
 */
int Labyrinthe::getW()
{
    return w;
}

/**
 * @brief Labyrinthe::getH retourne la hauteur du Labyrinthe
 * @return hauteur
 */
int Labyrinthe::getH()
{
    return h;
}
