#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T20:45:47
#
#-------------------------------------------------

QT       += core gui

TARGET = NewtonGravitySim
CONFIG   += console
CONFIG   -= app_bundle
LIBS += -lgmpxx -lgmp

QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2

QMAKE_CXXFLAGS_RELEASE *= -O3



TEMPLATE = app


SOURCES += main.cpp \
    model/entity.cpp \
    model/universe.cpp \
    model/vector.cpp

HEADERS += \
    model/entity.h \
    model/universe.h \
    model/vector.h
