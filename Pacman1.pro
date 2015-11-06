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
    Graphics/affichage.cpp \
    pacman.cpp

HEADERS  += mainwindow.h \
    Graphics/affichage.h \
    pacman.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    pacmansprites2.png

RESOURCES += \
    sprites.qrc

