#include "mainwindow.h"
#include "Graphics/affichage.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    this->setFocus();    
    width=ui->graphicsView->width();
    height=ui->graphicsView->height();
    t_xoffset=t_yoffset=xperc=yperc=0;
    dpac=Personnage::none;    
    a=new Affichage(ui->graphicsView->width(),ui->graphicsView->height());
    c=new Collisions();
    time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(tick()));
    time->start(40);
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->graphicsView->setSceneRect(0,0,1,1);
}

void MainWindow::tick(){
    a->pos();
    c->colliding(a->getPac(),a->getLab());
    c->colliding(a->getFan(),a->getLab());
    //pour tous les fantômes
    if(c->colliding(a->getPac(),a->getFan()))
        a->reinit();
}

void MainWindow::showEvent(QShowEvent *){
    xperc+=a->getxoffset()/(float)a->getw();
    yperc+=a->getyoffset()/(float)a->geth();
    t_xoffset=xperc*(float)ui->graphicsView->width();
    t_yoffset=yperc*(float)ui->graphicsView->height();
    a->getPac()->setxoffset(t_xoffset);
    a->getPac()->setyoffset(t_yoffset);
    width=ui->graphicsView->width();
    height=ui->graphicsView->height();
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->graphicsView->setSceneRect(0,0,1,1);
    a->resize(width,height);
    ui->graphicsView->setScene(a->getscene());
}

void MainWindow::resizeEvent(QResizeEvent *){        
    xperc+=a->getPac()->getxoffset()/(float)a->getw();
    yperc+=a->getPac()->getyoffset()/(float)a->geth();
    t_xoffset=xperc*(float)ui->graphicsView->width();
    t_yoffset=yperc*(float)ui->graphicsView->height();
    a->getPac()->setxoffset(t_xoffset);
    a->getPac()->setyoffset(t_yoffset);
    width=ui->graphicsView->width();
    height=ui->graphicsView->height();    
    a->resize(width,height);
    ui->graphicsView->setScene(a->getscene());
}

void MainWindow::keyPressEvent(QKeyEvent *e){    
    switch(e->key()){
    case Qt::Key_Right:
        a->getPac()->setdir(Personnage::right);
        break;
    case Qt::Key_Left:
        a->getPac()->setdir(Personnage::left);
        break;
    case Qt::Key_Up:
        a->getPac()->setdir(Personnage::up);
        break;
    case Qt::Key_Down:
        a->getPac()->setdir(Personnage::down);
        break;
    case Qt::Key_D:
        a->getFan()->setdir(Personnage::right);
        break;
    case Qt::Key_Q:
        a->getFan()->setdir(Personnage::left);
        break;
    case Qt::Key_Z:
        a->getFan()->setdir(Personnage::up);
        break;
    case Qt::Key_S:
        a->getFan()->setdir(Personnage::down);
        break;
    case Qt::Key_Escape:
        qApp->quit();
        break;
    case Qt::Key_C:
        qDebug() << a->getPac()->getx() << " " << a->getw();
        qDebug() << a->getPac()->gety() << " " << a->geth();
        break;
    }
}


void MainWindow::mousePressEvent(QMouseEvent *){
    this->setFocus();
}


MainWindow::~MainWindow()
{
    delete ui;
}
