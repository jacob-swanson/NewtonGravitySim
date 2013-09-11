#include <QCoreApplication>
#include <iostream>

#include "model/entity.h"
#include "model/universe.h"

int main(int argc, char *argv[])
{

    //QCoreApplication a(argc, argv);

    ngs::Entity* sun = new ngs::Entity(ngs::Vector("0", "0", "0"), ngs::Vector("0", "0", "0"), "1.9891e30", false);
    ngs::Entity* earth = new ngs::Entity(ngs::Vector("149600000000", "0", "0"), ngs::Vector("0", "29780", "0"), "5.97219e24", true);
    ngs::Entity* moon = new ngs::Entity(ngs::Vector("149984400000", "0", "0"), ngs::Vector("0", "30802", "0"), "7.34767309e22", true);
    ngs::Entity* mars = new ngs::Entity(ngs::Vector("227900000000", "0", "0"), ngs::Vector("0", "24077", "0"), "639e21", true);
    ngs::Entity* mercury = new ngs::Entity(ngs::Vector("57910000000", "0", "0"), ngs::Vector("0", "47870", "0"), "328.5e21", true);


    ngs::Universe u;
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
