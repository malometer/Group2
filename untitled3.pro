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
    mysquare.cpp \
    jacobi.cpp \
    multigrid.cpp \
    SOR.cpp \
    gauss_seidel.cpp \
    create_box.cpp \
    closeness.cpp \
    circle_bound.cpp \
    simple_bound.cpp

HEADERS  += mainwindow.h \
    mysquare.h

FORMS    += mainwindow.ui

DISTFILES += \
    laplotter.sh \
    lageneric_gnu.gp \
    test.gnu \
    test.sh \
    interact.gp \
    plot1.jpg
