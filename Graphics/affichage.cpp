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
        offset=0.02*width;
    else
        offset=0.02*height;
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
    time->start(40);
}

void Affichage::pos(){
    QImage img(l->getLab()->pixmap().toImage());
    QColor col1,col2,col3;
    switch(dpac){
        case right:
        col1=img.pixel(P->getx()+offset+P->getw(),P->gety()+P->geth()/2);
        col2=img.pixel(P->getx()+offset+P->getw(),P->gety());
        col3=img.pixel(P->getx()+offset+P->getw(),P->gety()+P->geth());
            if(P->getx()+offset<w){
                if(col1.blue()==0 && col2.blue()==0 && col3.blue()==0)
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
            col1=img.pixel(P->getx()-offset,P->gety()+P->geth()/2);
            col2=img.pixel(P->getx()-offset,P->gety());
            col3=img.pixel(P->getx()-offset,P->gety()+P->geth());
            if(P->getx()-offset>0){
                if(col1.blue()==0 && col2.blue()==0 && col3.blue()==0)
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
            col1=img.pixel(P->getx(),P->gety()-offset);
            col2=img.pixel(P->getx()+P->getw()/2,P->gety()-offset);
            col3=img.pixel(P->getx()+P->getw(),P->gety()-offset);
            if(P->gety()-offset>0){
                if(col1.blue()==0 && col2.blue()==0 && col3.blue()==0)
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
            col1=img.pixel(P->getx(),P->gety()+offset+P->geth());
            col2=img.pixel(P->getx()+P->getw()/2,P->gety()+offset+P->geth());
            col3=img.pixel(P->getx()+P->getw(),P->gety()+offset+P->geth());
            if(P->gety()+offset<h){
                if(col1.blue()==0 && col2.blue()==0 && col3.blue()==0)
                    P->sety(P->gety()+offset);

                t_yoffset+=offset;
            }
            else{
                P->sety(0);
                t_yoffset-=h;
            }
            P->getgobj()->setPos(P->getx(),P->gety());
            /*if(P->getgobj()->collidesWithItem(W->getgobj())){
                P->sety(P->gety()-offset);
                P->getgobj()->setPos(P->getx(),P->gety());
            }*/
            break;
        case none:
            break;
    }
    if(P->getgobj()->collidesWithItem(F->getgobj())){
        P->die();
        if(P->getlives()<0)
            qApp->quit();
        int lives=P->getlives();
        l=new Labyrinthe(0,0,w,h);
        P = new Pacman(w/2,h/2+(0.15*h),w,h);
        P->setlives(lives);
        F = new Fantome(w/2,h/2,w,h);
        gscene->setBackgroundBrush(Qt::black);
        gscene->setItemIndexMethod(QGraphicsScene::NoIndex);
        gscene->addItem(l->getLab());
        gscene->addItem(P->getgobj());
        gscene->addItem(F->getgobj());
        dpac=none;
        t_xoffset=t_yoffset=0;
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
