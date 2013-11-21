#include "universe.h"

#include <QMutex>
#include <iostream>
#include <ctime>

using ngs::Universe;
using ngs::Entity;

Universe::Universe()
{
    this->deltaTime_ = 1000;
}

void Universe::simulate()
{
    // Loop through all of the Entities to calculate their acceleration then update their position
    while(true) {
        simulateStep();
    }
}

void Universe::simulateStep()
{
    clock_t start = clock();
    foreach (Entity* e, this->entities_)
    {
        e->calcAccleration(this->entities_);
    }

    foreach (Entity* e, this->entities_)
    {
        e->move(this->deltaTime_);
    }
    // Calculate elapsed time
    clock_t elapsed = clock() - start;
    this->avgTickSamples_[this->avgTickSamplesIndex_] = (double)elapsed / (CLOCKS_PER_SEC * 1000);
    this->avgTickSamplesIndex_++;
    if (this->avgTickSamplesIndex_ >= SAMPLES)
        this->avgTickSamplesIndex_ = 0;
}

QList<Entity*>& Universe::entities()
{
    return this->entities_;
}

mpf_class Universe::deltaTime()
{
    return this->deltaTime_;
}

void Universe::setDeltaTime(mpf_class deltaTime)
{
    this->deltaTime_ = deltaTime;
}

double Universe::getAvgTickTime()
{
    double avg = 0.0;
    for (int i = 0; i < SAMPLES; i++)
    {
        avg += this->avgTickSamples_[i];
    }
    avg = avg / SAMPLES;
    return avg;
}

int Universe::getNumberOfThreads()
{
    return this->numThreads_;
}

void Universe::setNumberOfThreads(int threads)
{
    this->numThreads_ = threads;
}

