#ifndef PARTICLEEXPLOSION_SWARM_H
#define PARTICLEEXPLOSION_SWARM_H

#include "Particle.h"

class Swarm {
private:
    const int swarmSize;
    Particle *pParticles;
    int lastTime;
public:
    Swarm(int swarmSize);
    virtual ~Swarm();
    const Particle* const getParticles() { return pParticles;}
    int getSwarmSize() { return swarmSize;}
    void update(int timestamp);
};


#endif //PARTICLEEXPLOSION_SWARM_H
