#-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T20:07:06
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MModeler
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        gui/mainwindow.cpp \
    gui/gldisplaywidget.cpp \
    algebra/mtx.cpp \
    algebra/mtxnxn.cpp \
    algebra/vecn.cpp \
    algebra/vec4.cpp \
    algebra/vec3.cpp \
    algebra/mtx4x4.cpp \
    visualization/globject.cpp \
    visualization/glscene.cpp \
    visualization/gloctreeadapter.cpp \
    visualization/glface.cpp

HEADERS  += gui/mainwindow.h \
    gui/gldisplaywidget.h \
    algebra/mtx.h \
    algebra/mtxnxn.h \
    algebra/vecn.h \
    algebra/vec4.h \
    algebra/vec3.h \
    algebra/mtx4x4.h \
    visualization/globject.h \
    visualization/glscene.h \
    visualization/gloctreeadapter.h \
    visualization/glface.h

FORMS    += gui/mainwindow.ui
