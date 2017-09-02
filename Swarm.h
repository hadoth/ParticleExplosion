#ifndef PARTICLEEXPLOSION_SWARM_H
#define PARTICLEEXPLOSION_SWARM_H

#include "Particle.h"

class Swarm {
private:
    const int swarmSize;
    Particle *pParticles;
public:
    Swarm(int swarmSize);
    virtual ~Swarm();
    const Particle* const getParticles() { return pParticles;}
    int getSwarmSize() { return swarmSize;}
    void update();
};


#endif //PARTICLEEXPLOSION_SWARM_H
