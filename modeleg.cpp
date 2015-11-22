#include "modeleg.h"

ModeleG::ModeleG(QPointF position,QPixmap mapImage)
{
    this->position=new QPointF(position);
    image=new QGraphicsPixmapItem();
    image->setPixmap(mapImage.scaled(0,0,Qt::IgnoreAspectRatio,Qt::FastTransformation));
    image->setPos(position.rx(),position.ry());

}

QGraphicsPixmapItem* ModeleG::getImage()
{
    return image;
}

QPointF* ModeleG::getPosition()
{
    return position;
}
