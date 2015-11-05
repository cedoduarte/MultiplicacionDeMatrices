#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T07:49:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MultiplicacionDeMatrices
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    NumeroRealSpinBoxDelegate.cpp

HEADERS  += Widget.h \
    NumeroRealSpinBoxDelegate.h

FORMS    += Widget.ui

QMAKE_CXXFLAGS += -std=gnu++14
