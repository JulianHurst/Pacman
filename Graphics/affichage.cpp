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
    Pinky = new Fantome(width/2,height/2,width,height,Fantome::pinky);
    Blinky = new Fantome((width/2)-(0.1*width),height/2,width,height,Fantome::blinky);
    Inky = new Fantome((width/2)-(0.1*width),height/2,width,height,Fantome::inky);
    Clyde = new Fantome((width/2)-(0.1*width),height/2,width,height,Fantome::clyde);
    gscene->setBackgroundBrush(Qt::black);
    gscene->setItemIndexMethod(QGraphicsScene::NoIndex);    
    gscene->addItem(l->getgobj());
    gscene->addItem(P->getgobj());
    gscene->addItem(Pinky->getgobj());
    gscene->addItem(Blinky->getgobj());
    gscene->addItem(Inky->getgobj());
    gscene->addItem(Clyde->getgobj());
}

void Affichage::pos(){

    P->move(l);    
    Blinky->move(l);
    Pinky->move(l);
    Inky->move(l);
    Clyde->move(l);
}

void Affichage::reinit(){
    P->reinit();
    Pinky->reinit();
    Blinky->reinit();
    Inky->reinit();
    Clyde->reinit();
}

void Affichage::resize(int w,int h){
    this->w=w;
    this->h=h;
    resizechildren();
}

void Affichage::resizechildren(){
    gscene->removeItem(P->getgobj());
    gscene->removeItem(Pinky->getgobj());
    gscene->removeItem(Blinky->getgobj());
    gscene->removeItem(Inky->getgobj());
    gscene->removeItem(Clyde->getgobj());
    gscene->removeItem(l->getgobj());
    P=P->resize(w,h);
    Pinky=Pinky->resize(w,h);
    Blinky=Blinky->resize(w,h);
    Inky=Inky->resize(w,h);
    Clyde=Clyde->resize(w,h);
    l=l->resize(w,h);
    gscene->addItem(P->getgobj());
    gscene->addItem(Pinky->getgobj());
    gscene->addItem(Blinky->getgobj());
    gscene->addItem(Inky->getgobj());
    gscene->addItem(Clyde->getgobj());
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

Fantome *Affichage::getFan(Fantome::name N){
    if(Blinky->getName()==N)
        return Blinky;
    else if(Pinky->getName()==N)
        return Pinky;
    else if(Inky->getName()==N)
        return Inky;
    else
        return Clyde;
}

Labyrinthe *Affichage::getLab(){
    return l;
}

Fantome *Affichage::getPinky(){
    return Pinky;
}

Fantome *Affichage::getBlinky(){
    return Blinky;
}

Fantome *Affichage::getInky(){
    return Inky;
}

Fantome *Affichage::getClyde(){
    return Clyde;
}

Personnage::direction Affichage::getdpac(){
    return dpac;
}
