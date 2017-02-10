#-------------------------------------------------
#
# Project created by QtCreator 2017-02-09T16:48:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../Archive/circle.cpp \
    ../Archive/gauss.cpp \
    ../Archive/jacobi.cpp \
    ../Archive/line.cpp \
    ../Archive/sor.cpp \
    ../Archive/task2.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
