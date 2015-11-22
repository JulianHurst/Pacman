#ifndef MoteurPhysique_H
#define MoteurPhysique_H
#include <QGraphicsScene>
#include "../pacman.h"
#include "../fantome.h"
#include "../labyrinthe.h"
#include "../croquette.h"
#include <QTimer>
#include <vector>

class MoteurPhysique : public QObject
{
    Q_OBJECT
public:
    enum direction{
        right,
        left,
        up,
        down,
        none
    };
    MoteurPhysique(int width, int height, direction dpac, float i_xoffset, float i_yoffset);
    QGraphicsScene *getscene();
    void change_direction(direction d);
    void initialiseBonus();
    int getxoffset();
    int getyoffset();
    Pacman *getPac();
    direction getdpac();
    QPixmap labyrinthe;
    int detecteCouleur(direction);
    int getw();
    int geth();

public slots:
    void pos();

private:
    QGraphicsScene *gscene;    
    Pacman *P;
    Fantome *F;
    Labyrinthe *l;
    std::vector <Croquette*> listeCroquette;
    direction dpac;
    int offset;
    int t_yoffset;
    int t_xoffset;
    int w;
    int h;
    QTimer *time;
};

#endif // MoteurPhysique_H
