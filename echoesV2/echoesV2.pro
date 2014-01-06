#-------------------------------------------------
#
# Project created by QtCreator 2014-01-06T22:56:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = echoesV2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../echoes/iopool.cpp

HEADERS  += mainwindow.h \
    ../echoes/iopool.h \
    ../echoes/function.hpp

FORMS    += mainwindow.ui

INCLUDEPATH += E:/lib/boost
INCLUDEPATH += C:/OpenSSL/include

