#ifndef ENTITY_H
#define ENTITY_H

#include <QList>
#include <QElapsedTimer>

#include "vector.h"

#define G 6.67e-11

class Entity
{
public:
    Entity();
    Entity(Vector position, Vector velocity, QString mass, bool moveable);

    Vector position();
    void setPosition(Vector position);

    Vector velocity();
    void setVelocity(Vector velocity);

    Vector accleration();
    void setAccleration(Vector acceleration);

    mpf_class mass();
    void setMass(double mass);

    bool moveable();
    void setMoveable(bool moveable);

    mpf_class timeStep();
    void setTimeStep(QString timeStep);

    void tick(QList<Entity*> entities);

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

    void calcAccleration(QList<Entity*> entities);
    void move();

};

#endif // ENTITY_H
