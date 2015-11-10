#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <QGraphicsScene>
#include "../pacman.h"
#include "../labyrinthe.h"
#include <QTimer>

class Affichage : public QObject
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
    Affichage(int width, int height, direction dpac, float i_xoffset, float i_yoffset);
    QGraphicsScene *getscene();
    void change_direction(direction d);
    int getxoffset();
    int getyoffset();
    Pacman *getPac();
    direction getdpac();
    int getw();
    int geth();

public slots:
    void pos();

private:
    QGraphicsScene *gscene;    
    Pacman *P;
    Labyrinthe *l;
    direction dpac;
    int offset;
    int t_yoffset;
    int t_xoffset;
    int w;
    int h;
    QTimer *time;
};

#endif // AFFICHAGE_H
