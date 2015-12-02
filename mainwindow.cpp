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
    a=new Affichage(ui->graphicsView->width(),ui->graphicsView->height());
    c=new Collisions();
    s=new Sound();
    time=new QTimer(this);
    animtimer=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(tick()));
    connect(animtimer,SIGNAL(timeout()),this,SLOT(animtick()));
    time->start(40);
    animtimer->start(200);
    ui->graphicsView->setAlignment(Qt::AlignCenter);
    ui->graphicsView->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());    
    ghost=1;    
    partie=0;
    nbghostseaten=0;
    ghostmul=1;
    fruit=0;
    fruittimer=0;    
    score.resize(partie+1,0);    
    ui->graphicsView->setScene(a->getscene());
    s->playintro();
}

void MainWindow::tick(){
    int i;    
    a->pos();
    c->colliding(a->getPac(),a->getLab());
    //pour tous les fantômes
    c->colliding(a->getPinky(),a->getLab());
    c->colliding(a->getBlinky(),a->getLab());
    c->colliding(a->getInky(),a->getLab());
    c->colliding(a->getClyde(),a->getLab());

    c->colliding(a->getPac(),a->getDoor());
    //pour tous les fantômes
    if(c->colliding(a->getPinky(),a->getDoor()) || c->colliding(a->getBlinky(),a->getDoor()) ||
            c->colliding(a->getInky(),a->getDoor()) || c->colliding(a->getClyde(),a->getDoor()))
        a->hidedoor();
    else
        a->showdoor();
    if(c->colliding(a->getPac(),a->getBlinky()) || c->colliding(a->getPac(),a->getPinky()) || c->colliding(a->getPac(),a->getInky()) || c->colliding(a->getPac(),a->getClyde())){
        if(a->getPac()->getpower()){
            if(c->colliding(a->getPac(),a->getBlinky()))
                a->getBlinky()->reinit();
            if(c->colliding(a->getPac(),a->getPinky()))
                a->getPinky()->reinit();
            if(c->colliding(a->getPac(),a->getInky()))
                 a->getInky()->reinit();
            if(c->colliding(a->getPac(),a->getClyde()))
                 a->getClyde()->reinit();
            score[partie]+=a->getBlinky()->getscore()*ghostmul;
            nbghostseaten++;
            ghostmul*=2;
            a->updatescore(score[partie]);
        }
        else{
            s->playdying();
            if(fruittimer!=0){
                fruittimer=0;
                a->removeFruit();
                fruit=0;
            }
            if(a->reinit()){            
                partie++;
                score.resize(partie+1,0);
            }
        }
    }
    if((i=c->colliding(a->getPac(),a->getBilleArray()))!=-1){
        s->setchomploop(2);
        if(s->getchomp()->isFinished())
            s->playchomp();
        if(a->getPac()->getpower())
            a->blueghost(true);                            
        score[partie]+=a->getBilleArray()->at(i)->getscore();
        if(a->removeBille(i,score[partie])){
            if(fruittimer!=0){
                fruittimer=0;
                a->removeFruit();
                fruit=0;
            }
            partie++;
            score.resize(partie+1,0);
        }
    }
    else
        s->setchomploop(0);
    if(fruittimer!=0 && c->colliding(a->getPac(),a->getFruit())){
        s->playfruit();
        a->removeFruit();
        fruit++;
        fruittimer=0;
        score[partie]+=a->getFruit()->getscore();
        a->updatescore(score[partie]);
    }
    if(fruittimer==0){
        if(score[partie]%500==0 && score[partie]!=0){
            switch(fruit){
                case 0:
                    a->showfruit(Fruit::cherry);
                    break;
                case 1:
                    a->showfruit(Fruit::strawberry);
                    break;
                case 2:
                    a->showfruit(Fruit::orange);
                    break;
                case 3:
                    a->showfruit(Fruit::apple);
                    break;
                case 4:
                    a->showfruit(Fruit::grapes);
                    break;
                case 5:
                    a->showfruit(Fruit::galaxian);
                    break;
                case 6:
                    a->showfruit(Fruit::bell);
                    break;
                case 7:
                    a->showfruit(Fruit::key);
                    break;
                default:
                    a->showfruit(Fruit::cherry);
            }
            fruittimer=50;
        }
    }
}

void MainWindow::animtick(){
    a->animate();
    if(a->getPac()->getpower()){
        a->getPac()->powerdown();
        if(!a->getPac()->getpower())
            a->blueghost(false);
    }
    if(fruittimer!=0){
        fruittimer--;
        if(fruittimer==0){
            a->removeFruit();
            fruit=0;
        }
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
    ui->graphicsView->setAlignment(Qt::AlignCenter);
    ui->graphicsView->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    a->show(width,height);
}

void MainWindow::resizeEvent(QResizeEvent *){
    QRectF bounds = a->getscene()->itemsBoundingRect();
    ui->graphicsView->fitInView(bounds,Qt::KeepAspectRatio);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->centerOn(0,0);
    width=ui->graphicsView->width();
    height=ui->graphicsView->height();        
}

void MainWindow::keyPressEvent(QKeyEvent *e){
    if(s->getintro()->isFinished() && s->getdying()->isFinished()){
        Personnage::direction d=a->getPac()->getdir();
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
        case Qt::Key_Return:
            time->stop();
            animtimer->stop();
            a->showscores(score);
            time->start();
            animtimer->start();
            break;
        case Qt::Key_Escape:
            qApp->quit();
            break;
        case Qt::Key_C:
            qDebug() << a->getPac()->getx() << " " << a->getw();
            qDebug() << a->getPac()->gety() << " " << a->geth();
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
        if(d!=a->getPac()->getdir())
            a->animate();
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
    delete a;
    delete c;
    delete s;
    delete time;
    delete animtimer;
    delete ui;
}
