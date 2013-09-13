#include <qmath.h>
#include <iostream>
#include <iomanip>

#include "entity.h"

using ngs::Entity;
using ngs::Vector;

unsigned long Entity::sampleTick_ = 10000;
unsigned short Entity::outputPrecision_ = 12;

Entity::Entity()
{
    // Create an Earth sized object at 0, 0, 0
    this->position_ = Vector("0", "0", "0");
    this->velocity_ = Vector("0", "0", "0");
    this->acceleration_ = Vector("0", "0", "0");
    this->mass_ = "5.97219e24";
    this->diameter_ = "40075000";
    this->moveable_ = true;
    this->currentTick_ = 1;

    this->renderComponent_ = new Polycode::ScenePrimitive(Polycode::ScenePrimitive::TYPE_SPHERE, this->diameter_.get_d() / SCALE, 16, 16);
    this->renderComponent_->setColor(0,1,0,1);
}

Entity::Entity(Vector position, Vector velocity, QString mass, QString diameter, QString name, bool moveable)
{
    this->position_ = position;
    this->velocity_ = velocity;
    this->acceleration_ = Vector("0", "0", "0");
    this->mass_ = mass.toStdString();
    this->diameter_ = diameter.toStdString();
    this->name_ = name;
    this->moveable_ = moveable;
    this->currentTick_ = 1;

        this->renderComponent_ = new Polycode::ScenePrimitive(Polycode::ScenePrimitive::TYPE_BOX, 1, 1, 1);
//    this->renderComponent_ = new Polycode::ScenePrimitive(Polycode::ScenePrimitive::TYPE_SPHERE, this->diameter_.get_d() / SCALE, 16, 16);
//    this->renderComponent_ = new Polycode::ScenePrimitive(Polycode::ScenePrimitive::TYPE_SPHERE, 1, 16, 16);
    this->renderComponent_->setColor(0,1,0,1);
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

mpf_class Entity::diameter()
{
    return this->diameter_;
}

void Entity::setDiameter(mpf_class diameter)
{
    this->diameter_ = diameter;
}

QString Entity::name()
{
    return this->name_;
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
        Polycode::Vector3 renderPos = this->renderCoords();
        this->renderComponent_->setPosition(renderPos.x, renderPos.y, renderPos.z);

        // Output the position for visualization purposes every sampleStep calculations
//        if ((this->sampleTick_ % this->currentTick_) > 0) {
//            std::cout << std::setprecision(this->outputPrecision_) << this->position_.x() << " " << this->position().y() << std::endl;
//        }

        this->currentTick_++;
    }
}

Polycode::ScenePrimitive* Entity::renderComponent()
{
    return this->renderComponent_;
}

Polycode::Vector3 Entity::renderCoords()
{
    Polycode::Vector3 renderPos(this->position_.x().get_d() / SCALE,
                                this->position_.y().get_d() / SCALE,
                                this->position_.z().get_d() / SCALE);
    return renderPos;
}
