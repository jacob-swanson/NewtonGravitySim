#include "app.h"

App::App(PolycodeView* view) : EventHandler()
{
    core = new POLYCODE_CORE(view, 1280, 720, false, false, 0, 0, 90);

    CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

    scene = new Scene();
    CoreServices::getInstance()->getRenderer()->setClippingPlanes(0.1f, 1000000000.f);

    ngs::Entity* sun = new ngs::Entity(ngs::Vector("0", "0", "0"), ngs::Vector("0", "0", "0"), "1.9891e30", "1391000000", false);
    ngs::Entity* earth = new ngs::Entity(ngs::Vector("149600000000", "0", "0"), ngs::Vector("0", "29780", "0"), "5.97219e24", "12742000", true);
    ngs::Entity* moon = new ngs::Entity(ngs::Vector("149984400000", "0", "0"), ngs::Vector("0", "30802", "0"), "7.34767309e22", "3474800", true);
    ngs::Entity* mars = new ngs::Entity(ngs::Vector("227900000000", "0", "0"), ngs::Vector("0", "24077", "0"), "639e21", "6779000", true);
    ngs::Entity* mercury = new ngs::Entity(ngs::Vector("57910000000", "0", "0"), ngs::Vector("0", "47870", "0"), "328.5e21", "4879000", true);

    scene->addEntity(sun->getRenderComponent());
    scene->addEntity(earth->getRenderComponent());
    scene->addEntity(moon->getRenderComponent());
    scene->addEntity(mars->getRenderComponent());
    scene->addEntity(mercury->getRenderComponent());

    universe = new ngs::Universe();
    universe->entities().push_back(sun);
    universe->entities().push_back(earth);
    universe->entities().push_back(moon);
    universe->entities().push_back(mars);
    universe->entities().push_back(mercury);

    scene->getDefaultCamera()->setPosition(0, 0, 400);
    scene->getDefaultCamera()->lookAt(Vector3(0, 0, 0));
}

App::~App()
{
}

bool App::update()
{
    universe->simulateStep();

    return core->updateAndRender();
}
