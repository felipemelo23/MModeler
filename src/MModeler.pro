#-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T20:07:06
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MModeler
TEMPLATE = app


SOURCES += main.cpp\
        gui/mainwindow.cpp \
    gui/gldisplaywidget.cpp \
    algebra/mtx.cpp \
    algebra/mtxnxn.cpp \
    algebra/vecn.cpp

HEADERS  += gui/mainwindow.h \
    gui/gldisplaywidget.h \
    algebra/mtx.h \
    algebra/mtxnxn.h \
    algebra/vecn.h

FORMS    += gui/mainwindow.ui
