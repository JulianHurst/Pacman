#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T11:31:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = Pacman1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Graphics/affichage.cpp \
    pacman.cpp \
    labyrinthe.cpp \
    personnage.cpp \
    fantome.cpp \
    collisions.cpp \
    bille.cpp \
    billearray.cpp \
    sound.cpp \
    fruit.cpp \
    bonus.cpp \
    porte.cpp

HEADERS  += mainwindow.h \
    Graphics/affichage.h \
    pacman.h \
    labyrinthe.h \
    personnage.h \
    fantome.h \
    collisions.h \
    bille.h \
    billearray.h \
    sound.h \
    fruit.h \
    bonus.h \
    porte.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    pacmansprites2.png

RESOURCES += \
    sprites.qrc
	
RC_FILE = Pacman.rc

