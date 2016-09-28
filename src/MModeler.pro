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
    visualization/glface.cpp \
    algebra/vec2.cpp \
    gui/objectsmanager.cpp \
    gui/cmd_interpreter/command.cpp \
    gui/cmd_interpreter/commandinterpreter.cpp \
    gui/cmd_interpreter/insert.cpp \
    gui/cmd_interpreter/select.cpp \
    gui/cmd_interpreter/deselect.cpp \
    gui/cmd_interpreter/delete.cpp \
    gui/cmd_interpreter/translate.cpp \
    gui/cmd_interpreter/rotate.cpp \
    gui/cmd_interpreter/scale.cpp \
    objects/sphere.cpp \
    objects/rbpyramid.cpp \
    objects/rbprism.cpp \
    objects/ocnode.cpp \
    objects/object.cpp \
    objects/boundingbox.cpp \
    algebra/mtx2x2.cpp \
    algebra/mtx3x3.cpp

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
    visualization/glface.h \
    algebra/vec2.h \
    gui/objectsmanager.h \
    gui/cmd_interpreter/command.h \
    gui/cmd_interpreter/commandinterpreter.h \
    gui/cmd_interpreter/insert.h \
    gui/cmd_interpreter/select.h \
    gui/cmd_interpreter/deselect.h \
    gui/cmd_interpreter/delete.h \
    gui/cmd_interpreter/translate.h \
    gui/cmd_interpreter/rotate.h \
    gui/cmd_interpreter/scale.h \
    objects/sphere.h \
    objects/rbpyramid.h \
    objects/rbprism.h \
    objects/ocnode.h \
    objects/object.h \
    objects/boundingbox.h \
    algebra/mtx2x2.h \
    algebra/mtx3x3.h

FORMS    += gui/mainwindow.ui
