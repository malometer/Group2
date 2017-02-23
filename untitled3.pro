#-------------------------------------------------
#
# Project created by QtCreator 2017-02-09T16:48:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled3
TEMPLATE = app


#SOURCES += main.cpp\
#        mainwindow.cpp \
 #   ../Archive/circle.cpp \
 #   ../Archive/gauss.cpp \
 #   ../Archive/jacobi.cpp \
 #   ../Archive/line.cpp \
#    ../Archive/sor.cpp \
#    ../Archive/task2.cpp \
#    mysquare.cpp

SOURCES += main.cpp\
        mainwindow.cpp \
    circle.cpp \
    gauss.cpp \
    jacobi.cpp \
    line.cpp \
    sor.cpp \
    mysquare.cpp \
    create_box.cpp \
    diagonal.cpp \
    multigridQT.cpp

HEADERS  += mainwindow.h \
    mysquare.h

FORMS    += mainwindow.ui

DISTFILES += \
    test.gnu \
    radar.gif
