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
    QList<Entity*>& entities();

private:
    QList<Entity*> entities_;
};

#endif // UNIVERSE_H
