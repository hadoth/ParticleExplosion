#include <cstdlib>
#include <cmath>
#include "Particle.h"

Particle::Particle(): speed(0.006 + (0.004 * rand()/RAND_MAX)) {
    xValue = (3.0 * rand()/RAND_MAX) - 1.5;
    yValue = (3.0 * rand()/RAND_MAX) - 1.5;
}

Particle::~Particle() {

}

void Particle::update() {
    double newX = xValue * cos(speed) - yValue * sin(speed);
    yValue = yValue * cos(speed) + xValue * sin(speed);
    xValue = newX;
}
