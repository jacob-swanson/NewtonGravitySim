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


SOURCES += src/main.cpp \
    src/model/entity.cpp \
    src/model/universe.cpp \
    src/model/vector.cpp

HEADERS += \
    src/model/entity.h \
    src/model/universe.h \
    src/model/vector.h
