#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <QGraphicsScene>
#include "../pacman.h"
#include "../fantome.h"
#include "../labyrinthe.h"
#include <QTimer>

class Affichage : public QObject
{
    Q_OBJECT
public:
    Affichage(int width, int height);
    QGraphicsScene *getscene();
    void change_direction(Personnage::direction d);
    int getxoffset();
    int getyoffset();
    Pacman *getPac();
    Fantome *getFan();
    Labyrinthe *getLab();
    Personnage::direction getdpac();
    int getw();
    int geth();
    void reinit();
    void pos();
    void resize(int w,int h);
    //void resizechild(Personnage *P);
    void resizechildren();

/*public slots:
    static void pos();*/

private:
    QGraphicsScene *gscene;    
    Pacman *P;
    Fantome *F;
    Labyrinthe *l;
    Personnage::direction dpac;
    int offset;
    int t_yoffset;
    int t_xoffset;
    int w;
    int h;
    QTimer *time;
};

#endif // AFFICHAGE_H
