#ifndef ENTITY_H
#define ENTITY_H

#include <QVector3D>
#include <QList>

#define G 6.67e-11

class Entity
{
public:
    Entity();

    QVector3D position();
    void setPosition(QVector3D position);

    QVector3D velocity();
    void setVelocity(QVector3D velocity);

    QVector3D accleration();
    void setAccleration(QVector3D acceleration);

    double mass();
    void setMass(double mass);

    bool moveable();
    void setMoveable(bool moveable);

    double timeStep();
    void setTimeStep(double timeStep);

    void tick(double deltaTime, QList<Entity*> entities);

private:

    QVector3D position_;
    QVector3D velocity_;
    QVector3D acceleration_;
    double mass_;
    bool moveable_;
    double timeStep_;

    void calcAccleration(QList<Entity*> entities);
    void move(double deltaTime);

};

#endif // ENTITY_H
