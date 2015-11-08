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
    Affichage(int width, int height);
    QGraphicsScene *getscene();
    enum direction{
        right,
        left,
        up,
        down
    };
    void change_direction(direction d);

public slots:
    void pos();

private:
    QGraphicsScene *gscene;    
    Pacman *P;
    Labyrinthe *l;
    direction dpac;
    int offset;
    QTimer *time;
};

#endif // AFFICHAGE_H
