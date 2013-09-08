#include "universe.h"

#include <QMutex>
#include <iostream>

Universe::Universe()
{
}

void Universe::simulate()
{
    // Loop through all of the Entities to calculate their acceleration then update their position
    while(true) {
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

QList<Entity*>& Universe::entities()
{
    return this->entities_;
}
