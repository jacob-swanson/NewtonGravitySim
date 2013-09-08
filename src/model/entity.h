#ifndef ENTITY_H
#define ENTITY_H

#include <QList>
#include <QElapsedTimer>

#include "vector.h"

#define G 6.67e-11

/**
 * @brief The Entity class
 */
class Entity
{
public:
    /**
     * @brief Entity Create an Entity for earth
     */
    Entity();

    /**
     * @brief Entity Create a custom Entity
     * @param position Initial Position of the Entity in meters
     * @param velocity Initial velocity of the Entity in meters per second
     * @param mass Mass of the Entity in kilograms
     * @param moveable True if Entity will move, false otherwise
     */
    Entity(Vector position, Vector velocity, QString mass, bool moveable);

    /**
     * @brief position Get the current position of the Entity in meters
     * @return
     */
    Vector position();

    /**
     * @brief setPosition Set the current position of the Entity in meters
     * @param position
     */
    void setPosition(Vector position);

    /**
     * @brief velocity Get the current velocity of the Entity in meters per second
     * @return
     */
    Vector velocity();

    /**
     * @brief setVelocity Set the current velocity of the Entity in meters per second
     * @param velocity
     */
    void setVelocity(Vector velocity);

    /**
     * @brief accleration Get the current acceleration of the Entity in meters per second^2
     * @return
     */
    Vector accleration();

    /**
     * @brief setAccleration Set the current acceleration of the Entity in meters per second^2
     * @param acceleration
     */
    void setAccleration(Vector acceleration);

    /**
     * @brief mass Get the current mass of the Entity in kilograms
     * @return
     */
    mpf_class mass();

    /**
     * @brief setMass Set the current mass of the Entity in kilograms
     * @param mass
     */
    void setMass(double mass);

    /**
     * @brief moveable Get whether the Entity can move.
     * @return If false, no acceleration or movement will occur for this Entity. If true, acceleration and movement will occur.
     */
    bool moveable();

    /**
     * @brief setMoveable Set whether the Entity can move
     * @param moveable If false, no acceleration or movement will occur for this Entity. If true, acceleration and movement will occur.
     */
    void setMoveable(bool moveable);

    mpf_class timeStep();
    void setTimeStep(QString timeStep);

    void tick(QList<Entity*> entities);
    /**
     * @brief calcAccleration Calculate acceleration due to gravity from all forces in the Universe.
     * move() should always be called after calcAccleration().
     * @param entities All entities in the Universe.
     */
    void calcAccleration(QList<Entity*> entities);

    /**
     * @brief move Update the Entity's position and velocity based on acceleration calculated in calcAcceleration.
     * This call should alway follow a call to calcAcceleration.
     */
    void move();


private:
    Vector position_;
    Vector velocity_;
    Vector acceleration_;
    mpf_class mass_;
    bool moveable_;
    mpf_class timeStep_;
    static int sampleStep_;
    int curStep_;
    QElapsedTimer timer_;


};

#endif // ENTITY_H
