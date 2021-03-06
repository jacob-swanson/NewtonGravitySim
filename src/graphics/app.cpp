#include "app.h"
#include <math.h>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <cmath>

App::App(PolycodeView* view, bool random, int randomValue, int numThreads) : EventHandler()
{
    // Create Universe
    universe = new ngs::Universe();
    universe->setNumberOfThreads(numThreads);

    core = new POLYCODE_CORE(view, 1280, 720, false, false, 0, 0, 60);

    // Add content
    CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

    // Create scene, set clipping planes (culling distant objects)
    screen = new Screen;
    scene = new Scene();
    CoreServices::getInstance()->getRenderer()->setClippingPlanes(0.1f, 1000000000.f);

    if (!random)
    {
        // Create simulation entities
        ngs::Entity* sun = new ngs::Entity(ngs::Vector("0", "0", "0"), ngs::Vector("0", "0", "0"), "1.9891e30", "1391000000", "sun", true);
        ngs::Entity* earth = new ngs::Entity(ngs::Vector("149600000000", "0", "0"), ngs::Vector("0", "29780", "0"), "5.97219e24", "12742000", "earth", true);
        ngs::Entity* moon = new ngs::Entity(ngs::Vector("149984400000", "0", "0"), ngs::Vector("0", "30802", "0"), "7.34767309e22", "3474800", "moon", true);
        ngs::Entity* mars = new ngs::Entity(ngs::Vector("227900000000", "0", "0"), ngs::Vector("0", "24077", "0"), "639e21", "6779000", "mars", true);
        ngs::Entity* mercury = new ngs::Entity(ngs::Vector("57910000000", "0", "0"), ngs::Vector("0", "47870", "0"), "328.5e21", "4879000", "mercury", true);

        // Add the rendering components to the scene
        scene->addEntity(sun->renderComponent());
        scene->addEntity(earth->renderComponent());
        scene->addEntity(moon->renderComponent());
        scene->addEntity(mars->renderComponent());
        scene->addEntity(mercury->renderComponent());

        // Set the initial target for the camera
        this->viewTarget = sun;

        // Add the Entities to the simulation
        universe->entities().push_back(sun);
        universe->entities().push_back(earth);
        universe->entities().push_back(moon);
        universe->entities().push_back(mars);
        universe->entities().push_back(mercury);
    }
    else
    {
        gmp_randclass r(gmp_randinit_default);
        for (int i = 0; i < randomValue; i++)
        {
            mpf_class x;
            x = r.get_f();
            x = x * 384400000000;

            mpf_class y;
            y = r.get_f();
            y = y * 384400000000;

            mpf_class z;
            z = r.get_f();
            z = z * 384400000000;

            mpf_class mass;
            mass = r.get_f();
            mass = mass * 7.34767309e22;

            // Calculate diameter using very small density
            mpf_class diameter;
            diameter = (3 * mass)/(4 * PI * 0.00000001);
            double tmp = diameter.get_d();
            diameter = std::pow(tmp, 0.3);

            ngs::Entity* e = new ngs::Entity(ngs::Vector(x,y,z), ngs::Vector(0,0,0), mass, diameter, QString::number(i), true);

            scene->addEntity(e->renderComponent());
            universe->entities().push_back(e);
        }
        this->viewTarget = universe->entities().at(0);
    }

    // Set initial deltaTime
    this->universe->setDeltaTime(this->deltaTimes[this->deltaIndex]);

    // Set the initial camera position
    this->camOffset.x = 400;
    scene->getDefaultCamera()->setPosition(0, 0, 400);
    scene->getDefaultCamera()->lookAt(Vector3(0, 0, 0));

    // Create labels
    targetLabel = new ScreenLabel("<ENTITY>", 32, "sans", Label::ANTIALIAS_FULL);
    targetLabel->setPosition(15, 15);
    screen->addChild(targetLabel);

    velocityLabel = new ScreenLabel("<VELOCITY>", 32, "sans", Label::ANTIALIAS_FULL);
    velocityLabel->setPosition(15, 45);
    screen->addChild(velocityLabel);

    timeLabel = new ScreenLabel("<VELOCITY>", 32, "sans", Label::ANTIALIAS_FULL);
    timeLabel->setPosition(15, 75);
    screen->addChild(timeLabel);

    deltaTimeLabel = new ScreenLabel("<VELOCITY>", 32, "sans", Label::ANTIALIAS_FULL);
    deltaTimeLabel->setPosition(15, 105);
    screen->addChild(deltaTimeLabel);

    // Add input listeners
    core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEWHEEL_UP);
    core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEWHEEL_DOWN);
    core->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
    core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEMOVE);
    core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEDOWN);
    core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEUP);

    this->mouseDown = false;
}

App::~App()
{
}

bool App::update()
{
    // Simulate one step of the universe
    universe->simulateStep();

    // Update the camera's position
    Vector3 camPos = viewTarget->renderCoords();
    Vector3 camOffsetNorm;
    camOffsetNorm.x = this->camOffset.x * sin(this->camOffset.y) * cos(this->camOffset.z);
    camOffsetNorm.y = this->camOffset.x * sin(this->camOffset.y) * sin(this->camOffset.z);
    camOffsetNorm.z = this->camOffset.x * cos(this->camOffset.y);
    camPos += camOffsetNorm;

    // Set the camera's position
    scene->getDefaultCamera()->setPosition(camPos);
    scene->getDefaultCamera()->lookAt(this->viewTarget->renderCoords(), Vector3(0,0,1));

    // Update the text label
    QString targetText = "Target: "
            + this->viewTarget->name();
    QString velocityText = "Velocity: "
            + QString::number(this->viewTarget->velocity().length().get_d())
            + " m/s";
    QString timeText = "Avg Tick: "
            + QString::number(this->universe->getAvgTickTime());
    QString deltaTimeText = "DeltaTime: "
            + QString::number(this->universe->deltaTime());

    targetLabel->setText(targetText.toStdString());
    velocityLabel->setText(velocityText.toStdString());
    timeLabel->setText(timeText.toStdString());
    deltaTimeLabel->setText(deltaTimeText.toStdString());

    // Render a frame
    return core->updateAndRender();
}

void App::handleEvent(Event *e)
{
    // Handle the input
    if (e->getDispatcher() == core->getInput())
    {
        InputEvent* inputEvent = (InputEvent*)e;

        if (e->getEventCode() == InputEvent::EVENT_MOUSEWHEEL_UP)
        {
            // Zoomin by 10%
            this->camOffset.x -= this->camOffset.x * 0.1;
            if (this->camOffset.x < 0)
                this->camOffset.x = 0;
        }
        else if (e->getEventCode() == InputEvent::EVENT_MOUSEWHEEL_DOWN)
        {
            // Zoomout by 10%
            this->camOffset.x += this->camOffset.x * 0.1;
        }
        else if (e->getEventCode() == InputEvent::EVENT_KEYDOWN)
        {
            if (inputEvent->keyCode() == KEY_LEFT)
            {
                // Cycle to the left
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
                // Cycle to the right
                int index = universe->entities().indexOf(this->viewTarget);
                int size = universe->entities().size();

                if (index == size - 1)
                    index = 0;
                else
                    index += 1;

                this->viewTarget = universe->entities().at(index);
            }
            else if (inputEvent->keyCode() == KEY_UP)
            {
                // Increase time simulated
                if (deltaIndex < DELTA_SIZE - 1)
                    deltaIndex++;
                this->universe->setDeltaTime(this->deltaTimes[this->deltaIndex]);
            }
            else if (inputEvent->keyCode() == KEY_DOWN)
            {
                // Decrease time simulated
                if (deltaIndex > 0)
                    this->deltaIndex--;
                this->universe->setDeltaTime(this->deltaTimes[this->deltaIndex]);
            }
        }
        else if (e->getEventCode() == InputEvent::EVENT_MOUSEDOWN)
        {
            // Right mouse button is held
            if (inputEvent->getMouseButton() == CoreInput::MOUSE_BUTTON2)
                this->mouseDown = true;
        }
        else if (e->getEventCode() == InputEvent::EVENT_MOUSEUP)
        {
            // Right mouse button is no longer held
            if (inputEvent->getMouseButton() == CoreInput::MOUSE_BUTTON2)
                this->mouseDown = false;
        }
        else if (e->getEventCode() == InputEvent::EVENT_MOUSEMOVE)
        {
            // Move the camera offset
            if (this->mouseDown)
            {
                Vector2 delta = this->core->getInput()->getMouseDelta();

                this->camOffset.y += -1 * PI * delta.y * 0.001;
                this->camOffset.z += -1 * PI * delta.x * 0.001;

                // Clamp theta to [0,PI]
                if (this->camOffset.y > PI)
                    this->camOffset.y = PI;
                else if (this->camOffset.y < 0)
                    this->camOffset.y = 0;

                // Allow phi to wrap around from [0,2*PI]
                if (this->camOffset.z < 0)
                    this->camOffset.z = 2 * PI;
                else if (this->camOffset.z > 2 * PI)
                    this->camOffset.z = 0;
            }
        }
    }
}
