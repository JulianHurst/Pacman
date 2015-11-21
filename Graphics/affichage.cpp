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
    t_xoffset=t_yoffset=0;
    w=width;
    h=height;    
    gscene=new QGraphicsScene();    
    l=new Labyrinthe(0,0,width,height);
    P = new Pacman(width/2,height/2+(0.15*height),width,height);
    F = new Fantome(width/2,height/2,width,height);
    gscene->setBackgroundBrush(Qt::black);
    gscene->setItemIndexMethod(QGraphicsScene::NoIndex);    
    gscene->addItem(l->getgobj());
    gscene->addItem(P->getgobj());
    gscene->addItem(F->getgobj());    
}

void Affichage::pos(){

    P->move(l);    
    F->move(l);
}

void Affichage::reinit(){
    P->reinit();
    F->reinit();
}

void Affichage::resize(int w,int h){
    this->w=w;
    this->h=h;
    resizechildren();
}

void Affichage::resizechildren(){
    gscene->removeItem(P->getgobj());
    gscene->removeItem(F->getgobj());
    gscene->removeItem(l->getgobj());
    P=P->resize(w,h);
    F=F->resize(w,h);
    l=l->resize(w,h);
    gscene->addItem(P->getgobj());
    gscene->addItem(F->getgobj());
    gscene->addItem(l->getgobj());
}

void Affichage::change_direction(Personnage::direction d){    
    P->setdir(d);
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

Labyrinthe *Affichage::getLab(){
    return l;
}

Fantome *Affichage::getFan(){
    return F;
}

Personnage::direction Affichage::getdpac(){
    return dpac;
}
