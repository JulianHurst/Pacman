#include "mainwindow.h"
#include "Graphics/affichage.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <unistd.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    menu=new QMenu(this);
    menu->addAction("Exit");        
    ui->setupUi(this);
    this->setFocus();
    t_xoffset=t_yoffset=xperc=yperc=0;
    dpac=Affichage::none;
    a=new Affichage(ui->graphicsView->width(),ui->graphicsView->height(),dpac,0,0);
    connect(menu,SIGNAL(triggered(QAction*)),this,SLOT(actiontrigger(QAction*)));
}

void MainWindow::showEvent(QShowEvent *){
    xperc+=a->getxoffset()/(float)a->getw();
    yperc+=a->getyoffset()/(float)a->geth();
    t_xoffset=xperc*(float)ui->graphicsView->width();
    t_yoffset=yperc*(float)ui->graphicsView->height();
    dpac=a->getdpac();
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->graphicsView->setSceneRect(0,0,1,1);
    a=new Affichage(ui->graphicsView->width(),ui->graphicsView->height(),dpac,t_xoffset,t_yoffset);
    ui->graphicsView->setScene(a->getscene());
}

void MainWindow::resizeEvent(QResizeEvent *){        
    xperc+=a->getxoffset()/(float)a->getw();
    yperc+=a->getyoffset()/(float)a->geth();
    t_xoffset=xperc*(float)ui->graphicsView->width();
    t_yoffset=yperc*(float)ui->graphicsView->height();
    dpac=a->getdpac();
    a=new Affichage(ui->graphicsView->width(),ui->graphicsView->height(),dpac,t_xoffset,t_yoffset);
    ui->graphicsView->setScene(a->getscene());
}

void MainWindow::keyPressEvent(QKeyEvent *e){    
    qDebug() << "Touche appuyee : " << e->text();
    switch(e->key()){
    case Qt::Key_Right:
        a->change_direction(Affichage::right);
        break;
    case Qt::Key_Left:
        a->change_direction(Affichage::left);
        break;
    case Qt::Key_Up:
        a->change_direction(Affichage::up);
        break;
    case Qt::Key_Down:
        a->change_direction(Affichage::down);
        break;
    case Qt::Key_C:
        qDebug() << a->getPac()->getx() << " " << a->getw();
        qDebug() << a->getPac()->gety() << " " << a->geth();
        break;
    case Qt::Key_Escape:
        QList<QGraphicsItem *> list;
        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
        effect->setOpacity(0.5);
        list=ui->graphicsView->items();
        list.first()->setGraphicsEffect(effect);
        menu->exec(ui->graphicsView->mapToGlobal(QPoint(ui->graphicsView->width()/2,ui->graphicsView->height()/2)));
        //qApp->quit();
        break;
    }
}

void MainWindow::actiontrigger(QAction *action){
    if(action->text().compare("Exit")==0)
        qApp->quit();
}

void MainWindow::keyReleaseEvent(QKeyEvent *){
    a->change_direction(Affichage::none);
}

void MainWindow::mousePressEvent(QMouseEvent *){
    this->setFocus();
}


MainWindow::~MainWindow()
{
    delete ui;
}
