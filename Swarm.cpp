#include "Swarm.h"

Swarm::Swarm(int swarmSize): swarmSize(swarmSize) {
    pParticles = new Particle[swarmSize];
}

Swarm::~Swarm() {
    delete [] pParticles;
}

void Swarm::update() {
    for (int i = 0; i < this->swarmSize; i++) {
        pParticles[i].update();
    }
}
