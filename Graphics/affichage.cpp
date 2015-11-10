#include "affichage.h"
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QSignalMapper>

using namespace std;

Affichage::Affichage(int width,int height,direction dpac,float i_xoffset,float i_yoffset)
{        
    t_xoffset=t_yoffset=0;
    w=width;
    h=height;
    offset=0.01*width;
    this->dpac=dpac;
    l=new Labyrinthe(0,0,width,height);
    gscene=new QGraphicsScene();
    P = new Pacman(width/2+i_xoffset,height/2+i_yoffset);
    gscene->setBackgroundBrush(Qt::black);
    gscene->setItemIndexMethod(QGraphicsScene::NoIndex);    
    gscene->addItem(l->getLab());
    gscene->addItem(P->getgpac());
    time=new QTimer(this);
    //connect(&time,&QTimer::timeout,signalMapper,&QSignalMapper::map);
    //connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(pos(int)));
    connect(time,SIGNAL(timeout()),this,SLOT(pos()));
    time->start(250);
}

void Affichage::pos(){    
    switch(dpac){
        case right:
            if(P->getx()+offset<w){
                P->setx(P->getx()+offset);
                t_xoffset+=offset;
            }
            else{
                P->setx(0);
                t_xoffset-=w;
            }
            P->getgpac()->setPos(P->getx(),P->gety());            
            break;
        case left:
            if(P->getx()-offset>0){
                P->setx(P->getx()-offset);
                t_xoffset-=offset;
            }
            else{
                P->setx(w);
                t_xoffset+=w;
            }
            P->getgpac()->setPos(P->getx(),P->gety());

            break;
        case up:
            if(P->gety()-offset>0){
                P->sety(P->gety()-offset);
                t_yoffset-=offset;
            }
            else{
                P->sety(h);
                t_yoffset+=h;
            }
            P->getgpac()->setPos(P->getx(),P->gety());            
            break;
        case down:
            if(P->gety()+offset<h){
                P->sety(P->gety()+offset);
                t_yoffset+=offset;
            }
            else{
                P->sety(0);
                t_yoffset-=h;
            }
            P->getgpac()->setPos(P->getx(),P->gety());            
            break;
        case none:
            break;
    }    
}

void Affichage::change_direction(direction d){   
    dpac=d;    
}

QGraphicsScene *Affichage::getscene(){
    return gscene;
}

int Affichage::getxoffset(){
    return t_xoffset;
}

int Affichage::getyoffset(){
    return t_yoffset;
}

int Affichage::getw(){
    return w;
}

int Affichage::geth(){
    return h;
}

Pacman *Affichage::getPac(){
    return P;
}

Affichage::direction Affichage::getdpac(){
    return dpac;
}
