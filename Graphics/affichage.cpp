#include "affichage.h"
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QSignalMapper>

using namespace std;

Affichage::Affichage(int width,int height)
{    
    l=new Labyrinthe(0,0);
    gscene=new QGraphicsScene();
    P = new Pacman(width/2,height/2);
    gscene->setBackgroundBrush(Qt::black);
    gscene->setItemIndexMethod(QGraphicsScene::NoIndex);    
    gscene->addItem(l->getLab());
    gscene->addItem(P->getgpac());
    time=new QTimer(this);
    //connect(&time,&QTimer::timeout,signalMapper,&QSignalMapper::map);
    //connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(pos(int)));
    connect(time,SIGNAL(timeout()),this,SLOT(pos()));
    time->start(500);

}

void Affichage::pos(){    
    switch(dpac){
        case right:
            P->setx(P->getx()+offset);
            P->getgpac()->setPos(P->getx(),P->gety());
            break;
        case left:
            P->setx(P->getx()-offset);
            P->getgpac()->setPos(P->getx(),P->gety());
            break;
        case up:
            P->sety(P->gety()-offset);
            P->getgpac()->setPos(P->getx(),P->gety());
            break;
        case down:
            P->sety(P->gety()+offset);
            P->getgpac()->setPos(P->getx(),P->gety());
            break;
    }    
}

void Affichage::change_direction(direction d){   
    dpac=d;
    offset=10;
}

QGraphicsScene *Affichage::getscene(){
    return gscene;
}
