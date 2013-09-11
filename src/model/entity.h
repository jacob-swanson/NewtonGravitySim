#ifndef ENTITY_H
#define ENTITY_H

#include <QList>
#include <Polycode.h>

#include "vector.h"

#define G 6.67e-11
#define SCALE 10000000

namespace ngs
{
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
    Entity(Vector position, Vector velocity, QString mass, QString diameter, QString name, bool moveable);

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
     * @brief diameter Get the diameter of the Entity in meters
     * @return
     */
    mpf_class diameter();

    /**
     * @brief setDiameter Set the diameter fo the Entity in meters
     * @param diameter
     */
    void setDiameter(mpf_class diameter);

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
    void move(mpf_class deltaTime);

    /**
     * @brief getRenderComponent Get the rendering component used by Polycode
     * @return
     */
    Polycode::ScenePrimitive* renderComponent();

    /**
     * @brief getRenderCoords Get the rendering coordinates, which are scaled down by a large factor
     * @return
     */
    Polycode::Vector3 renderCoords();

    /**
     * @brief getName Get the name of the Entity
     * @return
     */
    QString name();


private:
    Vector position_;
    Vector velocity_;
    Vector acceleration_;
    mpf_class mass_;
    bool moveable_;
    static unsigned long sampleTick_;
    static unsigned short outputPrecision_;
    unsigned long currentTick_;
    mpf_class diameter_;
    QString name_;
    Polycode::ScenePrimitive* renderComponent_;

};
}

#endif // ENTITY_H
