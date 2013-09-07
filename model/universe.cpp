#include "universe.h"

#include <QMutex>
#include <iostream>

Universe::Universe()
{
}

void Universe::simulate()
{
    for (long i = 0; i < ((31536000L * 100)*0.5); i++) {
        foreach (Entity* e, this->entities_)
        {
            e->calcAccleration(this->entities_);
        }

        foreach (Entity* e, this->entities_)
        {
            e->move();
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
