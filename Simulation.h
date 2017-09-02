//
// Created by kpokomeda on 27.08.17.
//

#ifndef PARTICLEEXPLOSION_SIMULATION_H
#define PARTICLEEXPLOSION_SIMULATION_H

#include "Screen.h"
#include "Swarm.h"
#include <math.h>

class Simulation {
private:
    Swarm *pSwarm;
    Screen *pScreen;
    bool isRunning;
    Uint32 *draw(Uint32 *pBuffer, int width, int height);
    void handleLogic();
    void start();

public:
    Simulation(Screen *screen, int swarmSize);
    ~Simulation();
    int run();
};


#endif //PARTICLEEXPLOSION_SIMULATION_H
