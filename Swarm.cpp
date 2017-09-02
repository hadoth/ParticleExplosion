#include "Swarm.h"

Swarm::Swarm(int swarmSize): swarmSize(swarmSize), lastTime(-1) {
    pParticles = new Particle[swarmSize];
}

Swarm::~Swarm() {
    delete [] pParticles;
}

void Swarm::update(int timestamp) {
    if (lastTime == -1) {
        lastTime = timestamp;
    }
    for (int i = 0; i < this->swarmSize; i++) {
        pParticles[i].update(timestamp - lastTime);
    }

    lastTime = timestamp;
}
