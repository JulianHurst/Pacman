#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Graphics/affichage.h"
#include "collisions.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent *);    
    void mousePressEvent(QMouseEvent *);
    void moveGhost(QKeyEvent *e,Fantome::name N);

public slots:
    void tick();

private:
    Ui::MainWindow *ui;    
    Affichage *a;
    Collisions *c;
    float t_xoffset;
    float t_yoffset;    
    QTimer *time;
    int width, height;
    int ghost;    
};

#endif // MAINWINDOW_H
