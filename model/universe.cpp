#include "universe.h"

#include <QMutex>
#include <iostream>

Universe::Universe()
{
}

void Universe::simulate()
{
    std::cout << "Simulating " << this->entities_.length() << " entities" << std::endl;
    while (true) {
        foreach (Entity* e, this->entities_)
        {
            e->tick(this->entities_);
        }
    }
}

QList<Entity*> Universe::entities()
{
    return this->entities_;
}

void Universe::addEntity(Entity *e)
{
    this->entities_.push_back(e);
}
