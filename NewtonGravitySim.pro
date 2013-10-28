#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T20:45:47
#
#-------------------------------------------------

QT += core

TARGET = NewtonGravitySim
CONFIG += console
CONFIG -= app_bundle

# Polycode stuff
POLYCODE_DIR = ../Polycode/Release/Linux/Framework
INCLUDEPATH += $${POLYCODE_DIR}/Core/Dependencies/include $${POLYCODE_DIR}/Core/Dependencies/include/AL $${POLYCODE_DIR}/Core/include $${POLYCODE_DIR}/Modules/include $${POLYCODE_DIR}/Modules/Dependencies/include $${POLYCODE_DIR}/Modules/Dependencies/include/bullet
QMAKE_LIBDIR += $${POLYCODE_DIR}/Core/lib/ $${POLYCODE_DIR}/Modules/lib/
LIBS += $${POLYCODE_DIR}/Core/lib/libPolycore.a $${POLYCODE_DIR}/Core/Dependencies/lib/libfreetype.a $${POLYCODE_DIR}/Core/Dependencies/lib/liblibvorbisfile.a $${POLYCODE_DIR}/Core/Dependencies/lib/liblibvorbis.a $${POLYCODE_DIR}/Core/Dependencies/lib/liblibogg.a $${POLYCODE_DIR}/Core/Dependencies/lib/libopenal.so $${POLYCODE_DIR}/Core/Dependencies/lib/libphysfs.a $${POLYCODE_DIR}/Core/Dependencies/lib/libpng15.a $${POLYCODE_DIR}/Core/Dependencies/lib/libz.a $${POLYCODE_DIR}/Modules/lib/libPolycode2DPhysics.a $${POLYCODE_DIR}/Modules/Dependencies/lib/libBox2D.a $${POLYCODE_DIR}/Modules/lib/libPolycode3DPhysics.a $${POLYCODE_DIR}/Modules/Dependencies/lib/libBulletDynamics.a $${POLYCODE_DIR}/Modules/Dependencies/lib/libBulletCollision.a $${POLYCODE_DIR}/Modules/Dependencies/lib/libLinearMath.a
LIBS += -lgmpxx -lgmp
LIBS += -lrt -ldl -lpthread
LIBS += -lGL -lGLU -lSDL -lX11

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
