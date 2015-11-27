#include "affichage.h"
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QSignalMapper>
#include <QMessageBox>

using namespace std;

Affichage::Affichage(int width,int height)
{            
    w=width;
    h=height;    
    gscene=new QGraphicsScene();        
    Score=new QGraphicsTextItem("Score : 0");
    l=new Labyrinthe(0,0,width,height);
    P = new Pacman();
    Pinky = new Fantome(Fantome::pinky);
    Blinky = new Fantome(Fantome::blinky);
    Inky = new Fantome(Fantome::inky);
    Clyde = new Fantome(Fantome::clyde);        
    Lives=new QGraphicsTextItem();    
    Score->setPos(0,0);
    Score->setDefaultTextColor(Qt::red);
    Lives->setPos(w+w*0.20,0);
    Lives->setDefaultTextColor(Qt::red);
    gscene->setBackgroundBrush(Qt::black);    
    gscene->setItemIndexMethod(QGraphicsScene::NoIndex);
}

void Affichage::pos(){

    P->move(l);    
    Blinky->move(l);
    Pinky->move(l);
    Inky->move(l);
    Clyde->move(l);
}

void Affichage::reinit(){
    QString S="Vies : ";
    S.append(QString::number(P->getlives()));
    P->reinit();
    Pinky->reinit();
    Blinky->reinit();
    Inky->reinit();
    Clyde->reinit();
    Lives->setPlainText(S);
    if(P->getlives()==0){
        QMessageBox B;
        B.setText("Vous n'avez plus de vies !");
        B.setWindowTitle("Game Over");
        B.exec();
        gscene->removeItem(P->getgobj());
        P=new Pacman(w/2,h/2);
        gscene->addItem(P->getgobj());
        S="Vies : ";
        S.append(QString::number(P->getlives()));
        Lives->setPlainText(S);
    }
}

void Affichage::show(int w,int h){
    this->w=w;
    this->h=h;
    showchildren();
}

void Affichage::showchildren(){
    QString S;
    S="Vies : ";
    P=P->resize(w,h);
    Pinky=Pinky->resize(w,h);
    Blinky=Blinky->resize(w,h);
    Inky=Inky->resize(w,h);
    Clyde=Clyde->resize(w,h);
    l=l->resize(w,h);
    S.append(QString::number(P->getlives()));
    Lives->setPlainText(S);
    gscene->addItem(l->getgobj());    
    gscene->addItem(P->getgobj());
    gscene->addItem(Pinky->getgobj());
    gscene->addItem(Blinky->getgobj());
    gscene->addItem(Inky->getgobj());
    gscene->addItem(Clyde->getgobj());    
    gscene->addItem(Score);
    gscene->addItem(Lives); 
}

void Affichage::change_direction(Personnage::direction d){    
    P->setdir(d);
}

QGraphicsScene *Affichage::getscene(){
    return gscene;
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

QGraphicsTextItem *Affichage::getScore(){
    return Score;
}

QGraphicsTextItem *Affichage::getLives(){
    return Lives;
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

Affichage::~Affichage(){
    delete P;
    delete Blinky;
    delete Pinky;
    delete Inky;
    delete Clyde;
    delete Score;
    delete Lives;

}
