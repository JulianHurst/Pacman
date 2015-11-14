#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Graphics/affichage.h"

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
    void keyReleaseEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);

public slots:
    void actiontrigger(QAction *action);

private:
    Ui::MainWindow *ui;    
    Affichage *a;
    float xperc;
    float yperc;
    float t_xoffset;
    float t_yoffset;
    Affichage::direction dpac;
    QMenu *menu;
};

#endif // MAINWINDOW_H
