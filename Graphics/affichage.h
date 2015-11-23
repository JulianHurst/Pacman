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
    ~Affichage();
    QGraphicsScene *getscene();
    void change_direction(Personnage::direction d);
    Pacman *getPac();
    Fantome *getFan(Fantome::name N);
    Fantome *getPinky();
    Fantome *getBlinky();
    Fantome *getInky();
    Fantome *getClyde();
    Labyrinthe *getLab();
    QGraphicsTextItem *getScore();
    QGraphicsTextItem *getLives();
    Personnage::direction getdpac();
    int getw();
    int geth();
    void reinit();
    void pos();
    void show(int w,int h);
    void showchildren();

private:
    QGraphicsScene *gscene;
    QGraphicsTextItem *Score;
    QGraphicsTextItem *Lives;
    Pacman *P;
    Fantome *Pinky;
    Fantome *Blinky;
    Fantome *Inky;
    Fantome *Clyde;
    Labyrinthe *l;     
    int w;
    int h;
    QTimer *time;
};

#endif // AFFICHAGE_H
