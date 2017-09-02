#include <cstdlib>
#include <cmath>
#include "Particle.h"
#include <iostream>

Particle::Particle():
        xValue(0),
        yValue(0),
        rSpeed(0.05 * (1.0 - (1.0 * rand()/RAND_MAX))),
        phi(M_PI * ((2.0 * rand()/RAND_MAX) - 1)),
        tSpeed(0.0001 + (0.00001 * rand()/RAND_MAX)) {
    rSpeed *= rSpeed*rSpeed;
}

Particle::~Particle() {

}

void Particle::update(int timeElapsed) {
    double dPhi = tSpeed * timeElapsed;
    double dRadius = rSpeed * timeElapsed;

    // radial transformation;
    xValue += dRadius * cos(phi);
    yValue += dRadius * sin(phi);

    // tangent transformation
    double newX = xValue * cos(dPhi) - yValue * sin(dPhi);
    yValue = yValue * cos(dPhi) + xValue * sin(dPhi);
    xValue = newX;
//    phi += dPhi;

    if ( xValue < -1 || xValue >=1 || yValue < -1 || yValue >=1) {
        xValue = 0;
        yValue = 0;
        rSpeed = 0.04 * (1.0 - (1.0 * rand()/RAND_MAX));
        phi = M_PI * ((2.0 * rand()/RAND_MAX) - 1);
        tSpeed = 0.00006 + (0.00004 * rand()/RAND_MAX);
    }
}
