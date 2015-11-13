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
    if(width<=height)
        offset=0.03*width;
    else
        offset=0.03*height;
    this->dpac=dpac;
    l=new Labyrinthe(0,0,width,height);
    gscene=new QGraphicsScene();
    P = new Pacman(width/2+i_xoffset,height/2+(0.15*h)+i_yoffset,w,h);
    F = new Fantome(width/2,height/2,w,h);
    gscene->setBackgroundBrush(Qt::black);
    gscene->setItemIndexMethod(QGraphicsScene::NoIndex);    
    gscene->addItem(l->getLab());
    gscene->addItem(P->getgobj());
    gscene->addItem(F->getgobj());
    time=new QTimer(this);   
    connect(time,SIGNAL(timeout()),this,SLOT(pos()));
    time->start(60);
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
            P->getgobj()->setPos(P->getx(),P->gety());
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
            P->getgobj()->setPos(P->getx(),P->gety());

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
            P->getgobj()->setPos(P->getx(),P->gety());
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
            P->getgobj()->setPos(P->getx(),P->gety());
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
