#ifndef UNIVERSE_H
#define UNIVERSE_H

#define SAMPLES 60

#include "entity.h"

namespace ngs
{
/**
 * @brief The Universe class
 */
class Universe
{
public:
    /**
     * @brief Universe Create an empty Universe
     */
    Universe();

    /**
     * @brief simulate Begin the simulation of the Universe, this blocks infinitely
     */
    void simulate();

    /**
     * @brief simulateStep Simulate a single iteration of the Universe
     */
    void simulateStep();

    /**
     * @brief entities Get the list of Entities in the Universe
     * @return
     */
    QList<Entity*>& entities();

    /**
     * @brief deltaTime Get the deltaTime used for moving the Entities
     * @return
     */
    mpf_class deltaTime();

    /**
     * @brief setDeltaTime Set the deltaTime for moving the Entities
     * @param deltaTime
     */
    void setDeltaTime(mpf_class deltaTime);

    /**
     * @brief getAvgTickTime Get the average tick time
     * @return
     */
    double getAvgTickTime();

    /**
     * @brief getNumberOfThreads Get the number of threads used
     * @return
     */
    int getNumberOfThreads();

    /**
     * @brief setNumberOfThreads Set the number of threads used
     * @param threads
     */
    void setNumberOfThreads(int threads);

private:
    QList<Entity*> entities_;
    mpf_class deltaTime_;
    double avgTickSamples_[SAMPLES];
    int avgTickSamplesIndex_;
    int numThreads_;
};
}

#endif // UNIVERSE_H
