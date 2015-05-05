#-------------------------------------------------
#
# Project created by QtCreator 2015-05-05T11:25:58
#
#-------------------------------------------------

QT       += core gui
QT += network
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = audio
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    udpplayer.cpp

HEADERS  += mainwindow.h \
    udpplayer.h

FORMS    += mainwindow.ui
