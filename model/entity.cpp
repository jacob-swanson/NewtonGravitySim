#include <qmath.h>
#include <iostream>

#include "entity.h"

Entity::Entity()
{
    this->position_ = QVector3D(0.0, 0.0, 0.0);
    this->velocity_ = QVector3D(0.0, 0.0, 0.0);
    this->acceleration_ = QVector3D(0.0, 0.0, 0.0);
    this->mass_ = 10;
    this->moveable_ = true;
    this->timeStep_ = 1000000.0;
}

Entity::Entity(QVector3D position, QVector3D velocity, double mass, bool moveable)
{
    this->position_ = position;
    this->velocity_ = velocity;
    this->acceleration_ = QVector3D(0.0, 0.0, 0.0);
    this->mass_ = mass;
    this->moveable_ = moveable;
    this->timeStep_ = 1000000.0;
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

void Entity::tick(QList<Entity*> entities)
{
    calcAccleration(entities);
    move();
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

void Entity::move()
{
    if (moveable_) {
        //double deltaTime = ((double) this->timer_.restart()) / 1000.0;
        this->velocity_ += this->acceleration_;
        //this->position_ += this->velocity_ * this->timeStep_ * deltaTime;
        this->position_ += this->velocity_ * this->timeStep_;

    }

    std::cout << this->position_.x() << " " << this->position_.y() << std::endl;

}
