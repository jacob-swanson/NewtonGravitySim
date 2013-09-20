#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T20:45:47
#
#-------------------------------------------------

QT += core

TARGET = NewtonGravitySim
CONFIG += console
CONFIG -= app_bundle
LIBS += -lgmpxx -lgmp

# Polycode stuff
POLYCODE_DIR = ../Polycode/Release/Linux/Framework
INCLUDEPATH += $${POLYCODE_DIR}/Core/Dependencies/include $${POLYCODE_DIR}/Core/Dependencies/include/AL $${POLYCODE_DIR}/Core/include $${POLYCODE_DIR}/Modules/include $${POLYCODE_DIR}/Modules/Dependencies/include $${POLYCODE_DIR}/Modules/Dependencies/include/bullet
QMAKE_LIBDIR += $${POLYCODE_DIR}/Core/lib/ $${POLYCODE_DIR}/Modules/lib/
LIBS += -lrt -ldl -lpthread -lPolycore -lfreetype -lvorbisfile -lvorbis -logg -lopenal -lphysfs -lpng -lz -lGL -lGLU -lSDL -lPolycode2DPhysics -lBox2D -lPolycode3DPhysics -lBulletDynamics -lBulletCollision -lLinearMath

TEMPLATE = app

SOURCES += src/main.cpp \
    src/model/entity.cpp \
    src/model/universe.cpp \
    src/model/vector.cpp \
    src/graphics/app.cpp

HEADERS += \
    src/model/entity.h \
    src/model/universe.h \
    src/model/vector.h \
    src/graphics/app.h
