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
    t_xoffset=t_yoffset=0;
    ppac.xperc=ppac.yperc=0;
    pblinky.xperc=pblinky.yperc=0;
    ppinky.xperc=ppinky.yperc=0;
    pinky.xperc=pinky.yperc=0;
    pclyde.xperc=pclyde.yperc=0;
    dpac=Personnage::none;    
    a=new Affichage(ui->graphicsView->width(),ui->graphicsView->height());
    c=new Collisions();
    time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(tick()));
    time->start(40);
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->graphicsView->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    //ui->graphicsView->setScene(a->getscene());
    ghost=1;
    resizing=false;
}

void MainWindow::tick(){
    if(!resizing){
        //qDebug() << "move";
        a->pos();
        c->colliding(a->getPac(),a->getLab());
        //pour tous les fantômes
        c->colliding(a->getPinky(),a->getLab());
        c->colliding(a->getBlinky(),a->getLab());
        c->colliding(a->getInky(),a->getLab());
        c->colliding(a->getClyde(),a->getLab());
        if(c->colliding(a->getPac(),a->getBlinky()) || c->colliding(a->getPac(),a->getPinky()) || c->colliding(a->getPac(),a->getInky()) || c->colliding(a->getPac(),a->getClyde()))
            a->reinit();
    }
}

void MainWindow::showEvent(QShowEvent *){
    QRectF bounds = a->getscene()->itemsBoundingRect();
    ui->graphicsView->fitInView(bounds);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->centerOn(0,0);
    width=ui->graphicsView->width();
    height=ui->graphicsView->height();

    width=ui->graphicsView->width();
    height=ui->graphicsView->height();
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->graphicsView->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    a->resize(width,height);
    ui->graphicsView->setScene(a->getscene());
}

void MainWindow::resizeEvent(QResizeEvent *){
    QRectF bounds = a->getscene()->itemsBoundingRect();
    ui->graphicsView->fitInView(bounds);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->centerOn(0,0);
    width=ui->graphicsView->width();
    height=ui->graphicsView->height();        
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
    case Qt::Key_1:
        ghost=1;
        break;
    case Qt::Key_2:
        ghost=2;
        break;
    case Qt::Key_3:
        ghost=3;
        break;
    case Qt::Key_4:
        ghost=4;
        break;
    case Qt::Key_Escape:
        qApp->quit();
        break;
    case Qt::Key_C:
        qDebug() << a->getPinky()->getx() << " " << a->getw();
        qDebug() << a->getPinky()->gety() << " " << a->geth();
        break;
    default:
        if(ghost==1)
            moveGhost(e,Fantome::blinky);
        else if(ghost==2)
            moveGhost(e,Fantome::pinky);
        else if(ghost==3)
            moveGhost(e,Fantome::inky);
        else
            moveGhost(e,Fantome::clyde);
        break;
    }
}

void MainWindow::moveGhost(QKeyEvent *e,Fantome::name N){
    switch(e->key()){
        case Qt::Key_D:
            a->getFan(N)->setdir(Personnage::right);
            break;
        case Qt::Key_Q:
            a->getFan(N)->setdir(Personnage::left);
            break;
        case Qt::Key_Z:
            a->getFan(N)->setdir(Personnage::up);
            break;
            case Qt::Key_S:
            a->getFan(N)->setdir(Personnage::down);
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
