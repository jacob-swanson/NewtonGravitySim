#include "universe.h"

#include <QMutex>
#include <iostream>
#include <omp.h>

#include <sys/time.h>
// copied from mpbench
#define TIMER_CLEAR     (tv1.tv_sec = tv1.tv_usec = tv2.tv_sec = tv2.tv_usec = 0)
#define TIMER_START     gettimeofday(&tv1, (struct timezone*)0)
#define TIMER_ELAPSED   ((tv2.tv_usec-tv1.tv_usec)+((tv2.tv_sec-tv1.tv_sec)*1000000))
#define TIMER_STOP      gettimeofday(&tv2, (struct timezone*)0)
struct timeval tv1,tv2;

using ngs::Universe;
using ngs::Entity;

Universe::Universe()
{
    this->deltaTime_ = 10;
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
    // Start recording time
    TIMER_CLEAR;
    TIMER_START;
#pragma omp parallel num_threads(this->numThreads_)
    {
#pragma omp for
    for (int i = 0; i < this->entities_.length(); i++)
    {
        this->entities_.at(i)->calcAccleration(this->entities_);
    }
    }

    foreach (Entity* e, this->entities_)
    {
        e->move(this->deltaTime_);
    }
    // Calculate elapsed time
    // Stop timer
    TIMER_STOP;

    this->avgTickSamples_[this->avgTickSamplesIndex_] = (float)TIMER_ELAPSED/1000.0;
    this->avgTickSamplesIndex_++;
    if (this->avgTickSamplesIndex_ >= SAMPLES)
        this->avgTickSamplesIndex_ = 0;
}

QList<Entity*>& Universe::entities()
{
    return this->entities_;
}

double Universe::deltaTime()
{
    return this->deltaTime_;
}

void Universe::setDeltaTime(double deltaTime)
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

