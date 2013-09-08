#include <qmath.h>
#include <iostream>
#include <iomanip>

#include "entity.h"

int Entity::sampleStep_ = 10000;

Entity::Entity()
{
    // Create an Earth sized object at 0, 0, 0
    this->position_ = Vector("0", "0", "0");
    this->velocity_ = Vector("0", "0", "0");
    this->acceleration_ = Vector("0", "0", "0");
    this->mass_ = "5.97219e24";
    this->moveable_ = true;
    this->curStep_ = 0;
}

Entity::Entity(Vector position, Vector velocity, QString mass, bool moveable)
{
    this->position_ = position;
    this->velocity_ = velocity;
    this->acceleration_ = Vector("0", "0", "0");
    this->mass_ = mass.toStdString();
    this->moveable_ = moveable;
    this->curStep_ = 0;
}

Vector Entity::position()
{
    return this->position_;
}

void Entity::setPosition(Vector position)
{
    this->position_ = position;
}

Vector Entity::velocity()
{
    return this->velocity_;
}

void Entity::setVelocity(Vector velocity)
{
    this->velocity_ = velocity;
}

Vector Entity::accleration()
{
    return this->acceleration_;
}

void Entity::setAccleration(Vector acceleration)
{
    this->acceleration_ = acceleration;
}

mpf_class Entity::mass()
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

void Entity::calcAccleration(QList<Entity*> entities)
{
    // Calculate acceleration from all other Entities
    Vector accTotal;
    foreach (Entity* e, entities)
    {
        if (e != this) {
            // Calc distance between the two Entities
            Vector delta = e->position() - this->position();
            //std::cout << "Delta: " << delta.x() << " " << delta.y() << std::endl;

            // Get the length of the distance
            mpf_class r = delta.length();
            //std::cout << "Length: " << r << std::endl;

            // Square it
            mpf_class r2 = r * r;
            //std::cout << "Length^2: " << r2 << std::endl;

            // Calculate the force from gravity
            mpf_class f = G * (this->mass_ * e->mass()) / r2;
            //std::cout << "Force: " << f << std::endl;

            // Calculate the acceleration due to gravity
            mpf_class a = f / this->mass_;
            //std::cout << "Acceleration: " << a << std::endl;

            // Get the direction of the acceleration
            Vector accDir = delta.normalized();
            //std::cout << "Acceleration Dir: " << accDir.x() << " " << accDir.y() << std::endl;

            // Add the acceleration to the pool
            accTotal += accDir * a;
        }
    }

    // Set the acceleration
    this->acceleration_ = accTotal;
    //std::cout << "Total Acceleration: " << this->accleration().x() << " " << this->accleration().y() << std::endl;
}

void Entity::move(mpf_class deltaTime)
{
    // If the Entity can be moved, move it
    if (moveable_) {
        // Add acceleration to the velocity
        this->velocity_ += this->acceleration_ * deltaTime;
        // Add the velocity to the position
        this->position_ += this->velocity_ * deltaTime;

        // Output the position for visualization purposes every sampleStep calculations
        if (this->curStep_ >= this->sampleStep_) {
            std::cout << std::setprecision(12) << this->position_.x() << " " << this->position().y() << std::endl;
            this->curStep_ = 0;
        }

        this->curStep_++;
    }
}
