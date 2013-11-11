#include <Polycode.h>
#include <PolycodeView.h>
#include <iostream>
#include <string>

#include "graphics/app.h"

int main(int argc, char *argv[])
{
    bool random = false;
    int randomValue = 0;
    int numThreads = 1;
    for (int i = 1; i < argc; i++) {
        if (argv[i] == std::string("--random") || argv[i] == std::string("-r"))
        {
            random = true;
            randomValue = atoi(argv[i+1]);
            i++;
        }
        else if (argv[i] == std::string("--threads") || argv[i] == std::string("-t"))
        {
            numThreads = atoi(argv[i+1]);
            i++;
        }
        else if (argv[i] == std::string("--help") || argv[i] == std::string("-h"))
        {
            std::cout << "Usage: " << argv[0] << "[options]" << std::endl
                      << "Options:" << std::endl
                      << "  --random -r (n) \tGenerate a random universe with n Entities" << std::endl
                      << "  --threads -t (n) \t Use n threads for calculation" << std::endl
                      << "  --help -h \tShow this help" << std::endl;

            return 0;
        }
        else
        {
            std::cout << argv[i] << " option unknown" << std::endl;
        }
    }

    Polycode::PolycodeView* view = new Polycode::PolycodeView("NewtonGravitySim");
    App* app = new App(view, random, randomValue, numThreads);

    while (app->update()) {}

    return 0;
}
