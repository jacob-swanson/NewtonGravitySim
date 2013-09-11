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

private:
    Core* core;
    Scene* scene;

    ngs::Universe* universe;
};

#endif // APP_H
