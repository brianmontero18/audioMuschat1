#-------------------------------------------------
#
# Project created by QtCreator 2015-05-05T11:25:58
#
#-------------------------------------------------

QT += core gui
QT += network
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = audio

CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    audiocall/audioplayer.cpp

HEADERS  += mainwindow.h \
    audiocall/audioplayer.h

FORMS    += mainwindow.ui
