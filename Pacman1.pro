#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T11:31:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pacman1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pacman.cpp \
    labyrinthe.cpp \
    personnage.cpp \
    fantome.cpp \
    bonus.cpp \
    modeleg.cpp \
    Graphics/MoteurPhysique.cpp \
    croquette.cpp

HEADERS  += mainwindow.h \
    pacman.h \
    labyrinthe.h \
    personnage.h \
    fantome.h \
    bonus.h \
    modeleg.h \
    Graphics/MoteurPhysique.h \
    croquette.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    pacmansprites2.png

RESOURCES += \
    sprites.qrc

