#include <QCoreApplication>
#include <iostream>

#include "model/entity.h"
#include "model/universe.h"

int main(int argc, char *argv[])
{

    //QCoreApplication a(argc, argv);

    Entity* sun = new Entity(Vector("0", "0", "0"), Vector("0", "0", "0"), "1.9891e30", false);
    Entity* earth = new Entity(Vector("149600000000", "0", "0"), Vector("0", "29780", "0"), "5.97219e24", true);
    Entity* moon = new Entity(Vector("149984400000", "0", "0"), Vector("0", "30802", "0"), "7.34767309e22", true);
    Entity* mars = new Entity(Vector("227900000000", "0", "0"), Vector("0", "24077", "0"), "639e21", true);
    Entity* mercury = new Entity(Vector("57910000000", "0", "0"), Vector("0", "47870", "0"), "328.5e21", true);


    Universe u;
    u.entities().push_back(sun);
    u.entities().push_back(earth);
    u.entities().push_back(moon);
    u.entities().push_back(mars);
    u.entities().push_back(mercury);

    std::cout << "0 0" << std::endl;
    //std::cout << "149600000000 0" << std::endl;


    u.simulate();

    //return a.exec();
}
