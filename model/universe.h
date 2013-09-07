#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "entity.h"

/**
 * @brief The Universe class
 */
class Universe
{
public:
    /**
     * @brief Universe Create an empty Universe
     */
    Universe();

    /**
     * @brief simulate Begin the simulation of the Universe, this blocks infinitely
     */
    void simulate();

    /**
     * @brief entities Get the list of Entities in the Universe
     * @return
     */
    QList<Entity*> entities();

    /**
     * @brief addEntity Add an Entity to the Universe
     * @param e
     */
    void addEntity(Entity* e);

private:
    QList<Entity*> entities_;
};

#endif // UNIVERSE_H
