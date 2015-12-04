#include "affichage.h"
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QSignalMapper>
#include <QMessageBox>

using namespace std;

/**
 * @brief Affichage::Affichage Prépare l'affichage du jeu
 * @param width Largeur de la fenêtre
 * @param height Hauteur de la fenêtre
 */
Affichage::Affichage(int width,int height)
{            
    w=width;
    h=height;    
    gscene=new QGraphicsScene();            
    l=new Labyrinthe(0,0,width,height);
    P = new Pacman();
    Pinky = new Fantome(Fantome::pinky);
    Blinky = new Fantome(Fantome::blinky);
    Inky = new Fantome(Fantome::inky);
    Clyde = new Fantome(Fantome::clyde);
    F=new Fruit();
    D=new Porte(w/2,h/2);
    Lives=new QGraphicsTextItem();
    Score=new QGraphicsTextItem();
    Score->setPos(0,0);
    Score->setDefaultTextColor(Qt::red);
    Lives->setPos(w+w*0.20,0);
    Lives->setDefaultTextColor(Qt::red);
    gscene->setBackgroundBrush(Qt::black);    
    gscene->setItemIndexMethod(QGraphicsScene::NoIndex);
}

/**
 * @brief Affichage::pos
 */
void Affichage::pos(){

    P->move(l);    
    Blinky->move(l);
    Pinky->move(l);
    Inky->move(l);
    Clyde->move(l);
}

/**
 * @brief Affichage::reinit réinitialise la position des Fantômes, et de Pacman
 * @return Vrai si il reste encore des vies, sinon faux
 */
bool Affichage::reinit(){
    QString S="Vies : ";
    S.append(QString::number(P->getlives()));
    P->reinit();
    Pinky->reinit();
    Blinky->reinit();
    Inky->reinit();
    Clyde->reinit();
    Lives->setPlainText(S);
    if(P->getlives()==0){
        for(int i=0;i<B->getlength();i++)
            gscene->removeItem(B->at(i)->getgobj());
        B=new BilleArray(104,26,8.3,10,l,P,Blinky);
        for(int i=0;i<B->getlength();i++)
            gscene->addItem(B->at(i)->getgobj());
        QMessageBox M;
        M.setText("Vous n'avez plus de vies !\nScore : "+QString::number(score));
        M.setWindowTitle("Game Over");
        M.exec();
        gscene->removeItem(P->getgobj());
        P=new Pacman(w/2,h/2);
        gscene->addItem(P->getgobj());
        S="Vies : ";
        S.append(QString::number(P->getlives()));
        Lives->setPlainText(S);
        S="Score : ";
        S.append(QString::number(0));
        Score->setPlainText(S);
        return true;
    }
    return false;
}

/**
 * @brief Affichage::reset remet l'affichage à zéro
 */
void Affichage::reset(){    
    Pinky->reinit();
    Blinky->reinit();
    Inky->reinit();
    Clyde->reinit();
    QString S;
    gscene->removeItem(P->getgobj());
    gscene->removeItem(Blinky->getgobj());
    gscene->removeItem(Pinky->getgobj());
    gscene->removeItem(Inky->getgobj());
    gscene->removeItem(Clyde->getgobj());
    P=new Pacman(w/2,h/2);
    B=new BilleArray(104,26,8.3,10,l,P,Blinky);
    for(int i=0;i<B->getlength();i++){
        gscene->addItem(B->at(i)->getgobj());
    }
    gscene->addItem(P->getgobj());
    gscene->addItem(Blinky->getgobj());
    gscene->addItem(Pinky->getgobj());
    gscene->addItem(Inky->getgobj());
    gscene->addItem(Clyde->getgobj());
    S="Vies : ";
    S.append(QString::number(P->getlives()));
    Lives->setPlainText(S);
    S="Score : ";
    S.append(QString::number(0));
    Score->setPlainText(S);
    blueghost(false);
}

/**
 * @brief Affichage::show affiche la scène
 * @param w Largeur
 * @param h Hauteur
 */
void Affichage::show(int w,int h){
    this->w=w;
    this->h=h;
    showchildren();
}

/**
 * @brief Affichage::showchildren Prépare la scene
 */
void Affichage::showchildren(){
    QString S;
    S="Vies : ";
    P=P->resize(w,h);
    Pinky=Pinky->resize(w,h);
    Blinky=Blinky->resize(w,h);
    Inky=Inky->resize(w,h);
    Clyde=Clyde->resize(w,h);
    l=l->resize(w,h);
    D=new Porte(w/2,h/2);
    S.append(QString::number(P->getlives()));
    Lives->setPlainText(S);
    S="Score : ";
    S.append(QString::number(0));
    Score->setPlainText(S);
    gscene->addItem(l->getgobj());
    B=new BilleArray(104,26,8.3,10,l,P,Blinky);
    for(int i=0;i<B->getlength();i++)
        gscene->addItem(B->at(i)->getgobj());
    gscene->addItem(D->getgobj());
    gscene->addItem(P->getgobj());
    gscene->addItem(Pinky->getgobj());
    gscene->addItem(Blinky->getgobj());
    gscene->addItem(Inky->getgobj());
    gscene->addItem(Clyde->getgobj());
    gscene->addItem(Score);
    gscene->addItem(Lives);
}

/**
 * @brief Affichage::showfruit Ajoute les fruits à la scene
 * @param n nom du fruit
 */
void Affichage::showfruit(Fruit::name n){
    F=new Fruit(w/2,h/2,n,100);
    gscene->addItem(F->getgobj());
}

/**
 * @brief Affichage::removeBille Enlève une croquette du plateau
 * @param i numéro de la croquette
 * @param score
 * @return vrai si plus de bille, faux sinon
 */
bool Affichage::removeBille(int i,int score){
    gscene->removeItem(B->at(i)->getgobj());
    B->rearrange(i);    
    updatescore(score);
    this->score=score;
    if(B->getlength()==0){
        QMessageBox M;
        M.setText("Gagné !\nScore : "+QString::number(score));
        M.setWindowTitle("Victoire !");
        M.exec();
        reset();        
        return true;
    }
    return false;
}

/**
 * @brief Affichage::removeFruit Enlève le fruit de l'affichage
 */
void Affichage::removeFruit(){
    gscene->removeItem(F->getgobj());
}

/**
 * @brief Affichage::updatescore Mets à jour l'affichage du score
 * @param score
 */
void Affichage::updatescore(int score){
    QString S;
    S="Score : ";
    S.append(QString::number(score));
    Score->setPlainText(S);
}

/**
 * @brief Affichage::showscores affiche le score
 * @param score
 */
void Affichage::showscores(std::vector<int> score){
    QMessageBox M;
    QString S="";
    S.append(QString::number(score[0]));
    for(unsigned int i=1;i<score.size();i++){
        S.append("\n");
        S.append(QString::number(score[i]));
    }
    M.setText("Scores :\n"+S);
    M.setWindowTitle("Scores");
    M.exec();
}

void Affichage::animate(){
 P->animate();
}

/**
 * @brief Affichage::blueghost Change l'affichage des fantômes celon leur état
 * @param blue vari si vulnérable donc bleu, et faux sinon.
 */
void Affichage::blueghost(bool blue){
    if(blue){
        Blinky->blueon();
        Pinky->blueon();
        Inky->blueon();
        Clyde->blueon();
    }
    else{
        Blinky->blueoff();
        Pinky->blueoff();
        Inky->blueoff();
        Clyde->blueoff();
    }
}

/**
 * @brief Affichage::change_direction Change la direction
 * @param d nouvelle direction
 */
void Affichage::change_direction(Personnage::direction d){    
    P->setdir(d);
}

/**
 * @brief Affichage::getscene retourne la scène
 * @return scène courante
 */
QGraphicsScene *Affichage::getscene(){
    return gscene;
}

/**
 * @brief Affichage::getw retourne la largeur
 * @return Largeur courante
 */
int Affichage::getw(){
    return w;
}

/**
 * @brief Affichage::geth retourne la hauteur
 * @return hauteur courante
 */
int Affichage::geth(){
    return h;
}

/**
 * @brief Affichage::getPac retourne le Pacman
 * @return Pacman
 */
Pacman *Affichage::getPac(){
    return P;
}

/**
 * @brief Affichage::getFruit retourne le fruit courant
 * @return fruit courant
 */
Fruit *Affichage::getFruit(){
    return F;
}

/**
 * @brief Affichage::getBilleArray retourne le tableau de croquette présentes sur le plateau
 * @return tableau de croquettes
 */
BilleArray *Affichage::getBilleArray(){
    return B;
}

/**
 * @brief Affichage::getScore retourne le score courant
 * @return score courant
 */
QGraphicsTextItem *Affichage::getScore(){
    return Score;
}

/**
 * @brief Affichage::getLives retourne le nombre de vie
 * @return vie courante
 */
QGraphicsTextItem *Affichage::getLives(){
    return Lives;
}

/**
 * @brief Affichage::getFan retourne le fantômes voulue
 * @param N nom du fantôme que l'on veut récupérer
 * @return le fantôme courant selectionné
 */
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

/**
 * @brief Affichage::getLab retourne le labyrinthe courant
 * @return labyrinthe courant
 */
Labyrinthe *Affichage::getLab(){
    return l;
}

Porte *Affichage::getDoor(){
    return D;
}

/**
 * @brief Affichage::showdoor affiche la porte qui bloque l'entrée de la chambre des fantômes
 */
void Affichage::showdoor(){
    QList<QGraphicsItem*> L = gscene->items();
    if(!L.contains(D->getgobj()))
        gscene->addItem(D->getgobj());
}

/**
 * @brief Affichage::hidedoor masque la porte de la chambre des fantômes
 */
void Affichage::hidedoor(){
    QList<QGraphicsItem*> L = gscene->items();
    if(L.contains(D->getgobj()))
        gscene->removeItem(D->getgobj());
}
/**
 * @brief Affichage::getPinky retourne pinky
 * @return pinky
 */
Fantome *Affichage::getPinky(){
    return Pinky;
}

/**
 * @brief Affichage::getBlinky retourne blinky
 * @return blinky
 */
Fantome *Affichage::getBlinky(){
    return Blinky;
}

/**
 * @brief Affichage::getInky retourne Inky
 * @return Inky
 */
Fantome *Affichage::getInky(){
    return Inky;
}

/**
 * @brief Affichage::getClyde retourne Clyde
 * @return Clyde
 */
Fantome *Affichage::getClyde(){
    return Clyde;
}

/**
 * @brief Affichage::~Affichage supresseur
 */
Affichage::~Affichage(){
    delete P;
    delete Blinky;
    delete Pinky;
    delete Inky;
    delete Clyde;
    delete B;
    delete F;
    delete l;
    delete Score;
    delete Lives;
    delete gscene;
}
