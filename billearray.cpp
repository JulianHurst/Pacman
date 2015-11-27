#include "billearray.h"
#include <QDebug>

BilleArray::BilleArray(float x, float y, float xoffset,float yoffset, Labyrinthe *l)
{
    int i=0;
    int j=271;
    B=new Bille*[j];
    float inity=y;
    Bille *tmp;
    while(x<l->getW()){
        while(y<l->getH()){
            tmp=new Bille(x,y);
            while(tmp->getgobj()->collidesWithItem(l->getgobj()) && y<l->getH()){
                //qDebug() << "i :" << i;
                y+=yoffset;
                tmp->sety(y);
                tmp->getgobj()->setPos(x,y);
            }            
            if(y<l->getH()){
                /*x-=xoffset/3;
                tmp->setx(x);
                tmp->getgobj()->setPos(x,y);
                if(tmp->getgobj()->collidesWithItem(l->getgobj())){
                    while(tmp->getgobj()->collidesWithItem(l->getgobj()) || tmp->getgobj()->collidesWithItem(B[i-1]->getgobj())){
                        x++;
                        tmp->setx(x);
                        tmp->getgobj()->setPos(x,y);
                    }
                    x+=xoffset/2;
                }
                else
                    x+=xoffset/3;

                x+=xoffset/3;
                tmp->setx(x);
                tmp->getgobj()->setPos(x,y);
                if(tmp->getgobj()->collidesWithItem(l->getgobj())){
                    while(tmp->getgobj()->collidesWithItem(l->getgobj())){
                        x--;
                        tmp->setx(x);
                        tmp->getgobj()->setPos(x,y);
                    }
                    x-=xoffset/2;
                }
                else
                    x-=xoffset/3;*/


                //tmp->setx(x);
                //tmp->getgobj()->setPos(x,y);
                B[i]= new Bille(tmp->getx(),tmp->gety());
                i++;
                y+=yoffset;

            }
        }
        y=inity;
        x+=xoffset;
    }
    length=i;
    qDebug() << i;
}

Bille *BilleArray::at(int i){
    //qDebug() << B[i]->getx() << i;
    return B[i];
}

int BilleArray::getlength(){
    return length;
}

BilleArray::~BilleArray(){
    for(int i=0;i<length;i++)
        delete[] B[i];
    delete[] B;
}
