#include <qmath.h>

#include "entity.h"

Entity::Entity()
{
    this->position_ = QVector3D(0.0, 0.0, 0.0);
    this->velocity_ = QVector3D(0.0, 0.0, 0.0);
    this->acceleration_ = QVector3D(0.0, 0.0, 0.0);
    this->mass_ = 10;
    this->moveable_ = true;
    this->timeStep_ = 1.0;
}

QVector3D Entity::position()
{
    return this->position_;
}

void Entity::setPosition(QVector3D position)
{
    this->position_ = position;
}

QVector3D Entity::velocity()
{
    return this->velocity_;
}

void Entity::setVelocity(QVector3D velocity)
{
    this->velocity_ = velocity;
}

QVector3D Entity::accleration()
{
    return this->acceleration_;
}

void Entity::setAccleration(QVector3D acceleration)
{
    this->acceleration_ = acceleration;
}

double Entity::mass()
{
    return this->mass_;
}

void Entity::setMass(double mass)
{
    this->mass_ = mass;
}

bool Entity::moveable()
{
    return this->moveable_;
}

void Entity::setMoveable(bool moveable)
{
    this->moveable_ = moveable;
}

double Entity::timeStep()
{
    return this->timeStep_;
}

void Entity::setTimeStep(double timeStamp)
{
    this->timeStep_ = timeStamp;
}

void Entity::tick(double deltaTime, QList<Entity*> entities)
{
    calcAccleration(entities);
    move(deltaTime);
}

void Entity::calcAccleration(QList<Entity*> entities)
{
    QVector3D accTotal;
    foreach (Entity* e, entities)
    {
        if (e != this) {
            QVector3D delta = e->position() - this->position_;
            double r = delta.length();
            double f = G * (this->mass_ * e->mass()) / qPow(r, 2);
            double a = f / this->mass_;

            QVector3D accDir = delta.normalized();
            accTotal += a * accDir;
        }
    }

    this->acceleration_ = accTotal;
}

void Entity::move(double deltaTime)
{
    if (moveable_) {
        this->velocity_ += this->acceleration_;
        this->position_ += this->velocity_ * this->timeStep_ * deltaTime;
    }
}
