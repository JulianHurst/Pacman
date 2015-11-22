#include "MoteurPhysique.h"
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QSignalMapper>

using namespace std;

MoteurPhysique::MoteurPhysique(int width,int height,direction dpac,float i_xoffset,float i_yoffset)
{        

    t_xoffset=t_yoffset=0;
    w=width;
    h=height;
    if(width<=height)
        offset=0.02*width;
    else
        offset=0.02*height;
    this->dpac=dpac;
    l=new Labyrinthe(0,0,width,height);
    gscene=new QGraphicsScene();    
    P = new Pacman(width/2+i_xoffset,height/2+(0.15*h)+i_yoffset,w,h);
    F = new Fantome(width/2,height/2,w,h);
    QGraphicsPixmapItem* teste=F->getgobj();
    teste->setPos(50,50);
    gscene->setBackgroundBrush(Qt::black);
    gscene->setItemIndexMethod(QGraphicsScene::NoIndex);    
    gscene->addItem(l->getLab());
    gscene->addItem(P->getgobj());
    gscene->addItem(F->getgobj());
    gscene->addItem(teste);
    initialiseBonus();
    for(vector<Croquette*>::iterator i = listeCroquette.begin(); i != listeCroquette.end();++i){
        gscene->addItem();
    }
    time=new QTimer(this);   
    connect(time,SIGNAL(timeout()),this,SLOT(pos()));
    time->start(40);
}

void MoteurPhysique::pos(){
    QImage img(l->getLab()->pixmap().toImage());
    QColor col1,col2,col3;
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
            while(P->getgobj()->collidesWithItem(l->getLab(),Qt::IntersectsItemBoundingRect)){
                P->setx(P->getx()-1);
                t_xoffset--;
                P->getgobj()->setPos(P->getx(),P->gety());
            }
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
            while(P->getgobj()->collidesWithItem(l->getLab(),Qt::IntersectsItemBoundingRect)){
                P->setx(P->getx()+1);
                t_xoffset++;
                P->getgobj()->setPos(P->getx(),P->gety());
            }
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
            while(P->getgobj()->collidesWithItem(l->getLab(),Qt::IntersectsItemBoundingRect)){
                P->sety(P->gety()+1);
                t_yoffset++;
                P->getgobj()->setPos(P->getx(),P->gety());
            }
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
            while(P->getgobj()->collidesWithItem(l->getLab(),Qt::IntersectsItemBoundingRect)){
                P->sety(P->gety()-1);
                t_yoffset--;
                P->getgobj()->setPos(P->getx(),P->gety());
            }
            break;
        case none:
            break;
    }
    if(P->getgobj()->collidesWithItem(F->getgobj())){
        P->die();
        if(P->getlives()<0)
            qApp->quit();
        int lives=P->getlives();
        gscene->removeItem(P->getgobj());
        gscene->removeItem(F->getgobj());
        P = new Pacman(w/2,h/2+(0.15*h),w,h);
        P->setlives(lives);
        F = new Fantome(w/2,h/2,w,h);        
        gscene->setBackgroundBrush(Qt::black);
        gscene->setItemIndexMethod(QGraphicsScene::NoIndex);        
        gscene->addItem(P->getgobj());
        gscene->addItem(F->getgobj());
        dpac=none;
        t_xoffset=t_yoffset=0;
    }
}

void MoteurPhysique::change_direction(direction d){
    dpac=d;    
}

QGraphicsScene *MoteurPhysique::getscene(){
    return gscene;
}

int MoteurPhysique::getxoffset(){
    return t_xoffset;
}

int MoteurPhysique::getyoffset(){
    return t_yoffset;
}

int MoteurPhysique::getw(){
    return w;
}

int MoteurPhysique::geth(){
    return h;
}

Pacman *MoteurPhysique::getPac(){
    return P;
}

MoteurPhysique::direction MoteurPhysique::getdpac(){
    return dpac;
}

void MoteurPhysique::initialiseBonus()
{
    QImage labImage=l->getLab()->pixmap().toImage();
    QColor couleurCase;
    for(int i=0;i<labImage.width();i++)
    {
        for(int j=0;j<labImage.height();j++)
        {
            couleurCase=labImage.pixel(i,j);
            if(couleurCase.value()==0)
            {
              QPointF point(i,j);
              Croquette* croquetteTest=new Croquette(point);
              listeCroquette.push_back(croquetteTest);

            }
        }
    }
}
