#-------------------------------------------------
#
# Project created by QtCreator 2013-09-08T22:07:58
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_newtongravitysimtest
CONFIG   += console
CONFIG   -= app_bundle
LIBS += -lgmpxx -lgmp

TEMPLATE = app


SOURCES += src/model/vector.cpp \
    src/test/main.cpp \
    src/test/testvector.cpp
DEFINES += SRCDIR=\\\"$$PWD/src\\\"

HEADERS += \
    src/model/vector.h \
    src/test/testvector.h
