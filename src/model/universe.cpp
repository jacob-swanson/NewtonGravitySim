#include "universe.h"

#include <QMutex>
#include <iostream>

Universe::Universe()
{
    this->deltaTime_ = 1;
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
            e->move(this->deltaTime_);
        }
    }
}

QList<Entity*>& Universe::entities()
{
    return this->entities_;
}

mpf_class Universe::deltaTime()
{
    return this->deltaTime_;
}

void Universe::setDeltaTime(mpf_class deltaTime)
{
    this->deltaTime_ = deltaTime;
}
