#ifndef MODELEG_H
#define MODELEG_H

#include <QPointF>
#include <QGraphicsPixmapItem>
#include <qDebug>


class ModeleG
{
public:

    ModeleG(QPointF,QPixmap);
    QPointF* getPosition();
    QGraphicsPixmapItem *getImage();
private:
    QPointF* position;
    QGraphicsPixmapItem *image;
};

#endif // MODELEG_H
