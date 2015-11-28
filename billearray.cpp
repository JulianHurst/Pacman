#include "billearray.h"
#include <QDebug>

BilleArray::BilleArray(float x, float y, float xoffset,float yoffset, Labyrinthe *l,Pacman *P,Fantome *F)
{
    int i=0;
    int j=217;
    B=new Bille*[j];
    float inity=y;
    Bille *tmp;
    while(x<l->getW()){
        while(y<l->getH()){
            tmp=new Bille(x,y);
            while((tmp->getgobj()->collidesWithItem(l->getgobj()) || tmp->getgobj()->collidesWithItem(P->getgobj()) ||
                   (F->gety()-8<y && F->gety()+8>y && F->getx()-30<x && F->getx()+16>x)) && y<l->getH()){
                y+=yoffset;
                tmp->sety(y);
                tmp->getgobj()->setPos(x,y);
            }
            if(y<l->getH()){                
                B[i]= new Bille(tmp->getx(),tmp->gety());
                i++;
                y+=yoffset;

            }
        }
        y=inity;
        x+=xoffset;
    }
    length=i;    
}

Bille *BilleArray::at(int i){    
    return B[i];
}

void BilleArray::rearrange(int i){
    int j;
    for(j=i+1;j<length;j++,i++)
        B[i]=B[j];
    B[j]=NULL;
    length--;
}

int BilleArray::getlength(){
    return length;
}

BilleArray::~BilleArray(){
    for(int i=0;i<length;i++)
        delete[] B[i];
    delete[] B;
}
