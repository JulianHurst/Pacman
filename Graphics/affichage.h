#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <QGraphicsScene>
#include "../pacman.h"
#include "../fantome.h"
#include "../billearray.h"
#include "../fruit.h"
#include "../labyrinthe.h"
#include "../porte.h"
#include <QTimer>

class Affichage : public QObject
{
    Q_OBJECT
public:
    Affichage(int width, int height);
    ~Affichage();
    QGraphicsScene *getscene();
    bool removeBille(int i, int score);
    void removeFruit();
    void change_direction(Personnage::direction d);
    Pacman *getPac();
    BilleArray *getBilleArray();
    Fantome *getFan(Fantome::name N);
    Fantome *getPinky();
    Fantome *getBlinky();
    Fantome *getInky();
    Fantome *getClyde();
    Fruit *getFruit();
    Labyrinthe *getLab();
    Porte *getDoor();
    QGraphicsTextItem *getScore();
    QGraphicsTextItem *getLives();
    Personnage::direction getdpac();
    int getw();
    int geth();
    bool reinit();
    void pos();
    void show(int w,int h);
    void showchildren();
    void showscores(std::vector<int> score);
    void reset();
    void animate();
    void blueghost(bool blue);
    void updatescore(int score);
    void showfruit(Fruit::name n);
    void showdoor();
    void hidedoor();

private:
    QGraphicsScene *gscene;
    QGraphicsTextItem *Score;
    QGraphicsTextItem *Lives;
    Pacman *P;
    Fantome *Pinky;
    Fantome *Blinky;
    Fantome *Inky;
    Fantome *Clyde;
    BilleArray *B;
    Fruit *F;
    Labyrinthe *l;
    Porte *D;
    int w;
    int h;    
    int score;
};

#endif // AFFICHAGE_H
