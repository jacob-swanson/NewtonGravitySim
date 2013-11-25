#ifndef APP_H
#define APP_H

#include <Polycode.h>
#include <PolycodeView.h>
#include "../model/universe.h"

#define DELTA_SIZE 7

using namespace Polycode;

class App : public EventHandler
{
public:
    App(PolycodeView* view, bool random, int randomValue, int numThreads);
    ~App();

    bool update();
    void handleEvent(Event* e);

private:
    Core* core;
    Scene* scene;
    Screen* screen;
    ScreenLabel* velocityLabel;
    ScreenLabel* targetLabel;
    ScreenLabel* timeLabel;
    ScreenLabel* deltaTimeLabel;

    ngs::Universe* universe;
    ngs::Entity* viewTarget;
    Vector3 camOffset;
    bool mouseDown;
    int deltaTimes[DELTA_SIZE] = { 1, 10, 100, 1000, 10000, 1000000, 10000000 };
    int deltaIndex = 0;
};

#endif // APP_H
