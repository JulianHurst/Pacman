#include "labyrinthe.h"
#include <QDebug>
#include <qdebug.h>

Labyrinthe::Labyrinthe(float x, float y, int width, int height)
{
    this->x=x;
    this->y=y;
    QPixmap gLab;    
    lab = new QGraphicsPixmapItem();
    gLab.load(":/Sprites/sprites.qrc/labyrinthe_pac.png");    
    lab->setPixmap(gLab.scaled(width,height,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    lab->setPos(this->x,this->y);
}

QGraphicsPixmapItem *Labyrinthe::getLab()
{
    return lab;
}

int Labyrinthe::getX()
{
    return x;
}

int Labyrinthe::getY()
{
    return y;
}

/**
 * @brief Labyrinthe::openImage ouvre une image
 * @bug non testé sur l'application pacman du à un bug bloquant le programme lors de l'appel.
 */
void Labyrinthe::openImage(){
    QImage img(":/Sprites/sprites.qrc/labyrinthe_pac.png");
    //hauteur
    for (int i = 0; i < img.height(); i++){
        QRgb* rgb = (QRgb*)img.scanLine(i); //Stock la ligne courante
        //Largeur
        for (int j = 0; j < img.width(); j++){
            //Exemple de traitement par couleur
            rgb[j] = qRgba((qRed(rgb[j])*2)%255, (qGreen(rgb[j])*2)%255, (qBlue(rgb[j])+25)%255, qAlpha(rgb[j]));
        }
    }
}
