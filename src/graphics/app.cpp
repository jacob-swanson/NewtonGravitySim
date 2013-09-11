#include "app.h"

App::App(PolycodeView* view) : EventHandler()
{
    core = new POLYCODE_CORE(view, 1280, 720, false, false, 0, 0, 60);

    CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

    scene = new Scene();
    CoreServices::getInstance()->getRenderer()->setClippingPlanes(0.1f, 1000000000.f);

    ngs::Entity* sun = new ngs::Entity(ngs::Vector("0", "0", "0"), ngs::Vector("0", "0", "0"), "1.9891e30", "1391000000", "sun", true);
    ngs::Entity* earth = new ngs::Entity(ngs::Vector("149600000000", "0", "0"), ngs::Vector("0", "29780", "0"), "5.97219e24", "12742000", "earth", true);
    ngs::Entity* moon = new ngs::Entity(ngs::Vector("149984400000", "0", "0"), ngs::Vector("0", "30802", "0"), "7.34767309e22", "3474800", "moon", true);
    ngs::Entity* mars = new ngs::Entity(ngs::Vector("227900000000", "0", "0"), ngs::Vector("0", "24077", "0"), "639e21", "6779000", "mars", true);
    ngs::Entity* mercury = new ngs::Entity(ngs::Vector("57910000000", "0", "0"), ngs::Vector("0", "47870", "0"), "328.5e21", "4879000", "mercury", true);

    scene->addEntity(sun->renderComponent());
    scene->addEntity(earth->renderComponent());
    scene->addEntity(moon->renderComponent());
    scene->addEntity(mars->renderComponent());
    scene->addEntity(mercury->renderComponent());

    this->viewTarget = sun;

    universe = new ngs::Universe();
    universe->entities().push_back(sun);
    universe->entities().push_back(earth);
    universe->entities().push_back(moon);
    universe->entities().push_back(mars);
    universe->entities().push_back(mercury);

    scene->getDefaultCamera()->setPosition(0, 0, 400);
    scene->getDefaultCamera()->lookAt(Vector3(0, 0, 0));

    screen = new Screen;
    label = new ScreenLabel("<ENTITY NAME>", 32, "sans", Label::ANTIALIAS_FULL);
    label->setPosition(15, 15);
    label->setText("Target: " + this->viewTarget->name().toStdString());
    screen->addChild(label);

    core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEWHEEL_UP);
    core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEWHEEL_DOWN);
    core->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
}

App::~App()
{
}

bool App::update()
{
    universe->simulateStep();

    Vector3 camPos = viewTarget->renderCoords();
    scene->getDefaultCamera()->setPositionX(camPos.x);
    scene->getDefaultCamera()->setPositionY(camPos.y);
    scene->getDefaultCamera()->lookAt(this->viewTarget->renderCoords());

    QString labelText = "Target: " + this->viewTarget->name() + " Velocity: " + QString::number(this->viewTarget->velocity().length().get_d()) + " m/s";
    label->setText(labelText.toStdString());

    return core->updateAndRender();
}

void App::handleEvent(Event *e)
{
    if (e->getDispatcher() == core->getInput())
    {
        InputEvent* inputEvent = (InputEvent*)e;

        if (e->getEventCode() == InputEvent::EVENT_MOUSEWHEEL_UP)
        {
            Vector3 camPos = scene->getDefaultCamera()->getPosition();
            scene->getDefaultCamera()->setPositionZ(camPos.z - (camPos.z * 0.1));
        }
        else if (e->getEventCode() == InputEvent::EVENT_MOUSEWHEEL_DOWN)
        {
            Vector3 camPos = scene->getDefaultCamera()->getPosition();
            scene->getDefaultCamera()->setPositionZ(camPos.z + (camPos.z * 0.1));
        }
        else if (e->getEventCode() == InputEvent::EVENT_KEYDOWN)
        {
            if (inputEvent->keyCode() == KEY_LEFT)
            {
                int index = universe->entities().indexOf(this->viewTarget);
                int size = universe->entities().size();

                if (index == 0)
                    index = size - 1;
                else
                    index -= 1;

                this->viewTarget = universe->entities().at(index);
            }
            else if (inputEvent->keyCode() == KEY_RIGHT)
            {
                int index = universe->entities().indexOf(this->viewTarget);
                int size = universe->entities().size();

                if (index == size - 1)
                    index = 0;
                else
                    index += 1;

                this->viewTarget = universe->entities().at(index);
            }
        }
    }
}
