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
    gscene=new QGraphicsScene();
    P = new Pacman(width/2,height/2);
    gscene->setBackgroundBrush(Qt::black);
    gscene->setItemIndexMethod(QGraphicsScene::NoIndex);    
    gscene->addItem(P->getgpac());
    time.setInterval(500);
    time.start();
    //connect(&time,&QTimer::timeout,signalMapper,&QSignalMapper::map);
    //connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(pos(int)));
    connect(&time,SIGNAL(timeout()),this,SLOT(pos()));

}

void Affichage::pos(){    
    switch(dpac){
        case right:            
            P->getgpac()->setPos(P->getx()+offset,P->gety());
            break;
        case left:
            break;
        case up:
            break;
        case down:
            break;

    }
    time.start();
}

void Affichage::change_direction(direction d){   
    dpac=d;
    offset=100;
}

QGraphicsScene *Affichage::getscene(){
    return gscene;
}
