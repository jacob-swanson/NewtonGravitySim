#include <QCoreApplication>
#include <iostream>

#include "model/entity.h"
#include "model/universe.h"

int main(int argc, char *argv[])
{

    //QCoreApplication a(argc, argv);

    Entity* sun = new Entity(Vector("0", "0", "0"), Vector("0", "0", "0"), "1.9891e30", false);
    Entity* earth = new Entity(Vector("149600000000", "0", "0"), Vector("0", "29780", "0"), "5.97219e24", true);

    Universe u;
    u.addEntity(sun);
    u.addEntity(earth);

    std::cout << "0 0" << std::endl;

    u.simulate();

    //return a.exec();
}
