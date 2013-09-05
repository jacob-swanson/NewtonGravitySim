#include <QCoreApplication>
#include <iostream>

#include "model/entity.h"
#include "model/universe.h"

int main(int argc, char *argv[])
{

    //QCoreApplication a(argc, argv);

    Entity* sun = new Entity(QVector3D(0.0, 0.0, 0.0), QVector3D(0.0, 0.0, 0.0), 1.9891e30, false);
    Entity* earth = new Entity(QVector3D(149600000000, 0.0, 0.0), QVector3D(0.0, 0, 0.0), 5.97219e24, true);

    Universe u;
    u.addEntity(sun);
    u.addEntity(earth);

    u.simulate();

    //return a.exec();
}
