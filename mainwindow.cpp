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

}

void MainWindow::showEvent(QShowEvent *){
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->graphicsView->setSceneRect(0,0,1,1);
    a=new Affichage(ui->graphicsView->width(),ui->graphicsView->height());      //+ LE DÉPLACEMENT TOTAL
    ui->graphicsView->setScene(a->getscene());

}

void MainWindow::resizeEvent(QResizeEvent *){
    a=new Affichage(ui->graphicsView->width(),ui->graphicsView->height());      //+ LE DÉPLACEMENT TOTAL
    ui->graphicsView->setScene(a->getscene());
}

void MainWindow::keyPressEvent(QKeyEvent *e){    
    qDebug() << "Touche appuyee : " << e->text() << endl;
    switch(e->key()){
    case Qt::Key_Right:
        a->change_direction(Affichage::right);
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
