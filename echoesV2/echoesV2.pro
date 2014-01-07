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
    http.cpp \
    reader.cpp \
    ../echoes/Http.cpp \
    ../echoes/Cookie.cpp \
    ../echoes/Iopool.cpp \
    ../echoes/File.cpp \
    ../echoes/Client.cpp \
    ../echoes/Reader.cpp \
    ../echoes/Request.cpp \
    ../echoes/Respone.cpp \
    ../echoes/Url.cpp

HEADERS  += mainwindow.h \
    ../echoes/function.hpp \
    http.h \
    reader.h \
    ../echoes/common.hpp \
    ../echoes/Http.h \
    ../echoes/Cookie.h \
    ../echoes/Iopool.h \
    ../echoes/File.h \
    ../echoes/Client.h \
    ../echoes/Url.h \
    ../echoes/Respone.h \
    ../echoes/Request.h \
    ../echoes/Reader.h

FORMS    += mainwindow.ui

INCLUDEPATH += E:/lib/boost
INCLUDEPATH += C:/OpenSSL/include

