#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Graphics/MoteurPhysique.h"

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

private:
    Ui::MainWindow *ui;    
    MoteurPhysique *a;
    float xperc;
    float yperc;
    float t_xoffset;
    float t_yoffset;
    MoteurPhysique::direction dpac;
};

#endif // MAINWINDOW_H
