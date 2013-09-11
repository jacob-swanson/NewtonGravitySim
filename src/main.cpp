#include <Polycode.h>
#include <PolycodeView.h>

#include "graphics/app.h"

int main(int argc, char *argv[])
{
    Polycode::PolycodeView* view = new Polycode::PolycodeView("NewtonGravitySim");
    App* app = new App(view);

    while (app->update()) {}

    return 0;
}
