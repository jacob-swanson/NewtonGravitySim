#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "entity.h"

class Universe
{
public:
    Universe();
    void simulate();
    QList<Entity*> entities();
    void addEntity(Entity* e);

private:
    QList<Entity*> entities_;
};

#endif // UNIVERSE_H
