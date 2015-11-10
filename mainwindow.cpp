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
    t_xoffset=t_yoffset=xperc=yperc=0;
    dpac=Affichage::none;
    a=new Affichage(ui->graphicsView->width(),ui->graphicsView->height(),dpac,0,0);
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
    qDebug() << "Touche appuyee : " << e->text() << endl;
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
    case Qt::Key_Escape:
        qApp->quit();
        break;        
    }
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
