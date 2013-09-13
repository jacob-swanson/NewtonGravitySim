#ifndef APP_H
#define APP_H

#include <Polycode.h>
#include <PolycodeView.h>
#include "../model/universe.h"

using namespace Polycode;

class App : public EventHandler
{
public:
    App(PolycodeView* view);
    ~App();

    bool update();
    void handleEvent(Event* e);

private:
    Core* core;
    Scene* scene;
    Screen* screen;
    ScreenLabel* label;

    ngs::Universe* universe;
    ngs::Entity* viewTarget;
    Vector3 camOffset;
    bool mouseDown;
};

#endif // APP_H
