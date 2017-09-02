#include <cstdlib>
#include <cmath>
#include "Particle.h"
#include <iostream>

Particle::Particle():
        xValue(0),
        yValue(0),
        rSpeed(0.001 * (1.0 - (1.0 * rand()/RAND_MAX))),
        phi(M_PI * ((2.0 * rand()/RAND_MAX) - 1)),
        tSpeed(0.006 + (0.004 * rand()/RAND_MAX)) {
}

Particle::~Particle() {

}

void Particle::update() {
    // radial transformation;
    xValue += rSpeed * cos(phi);
    yValue += rSpeed * sin(phi);

    // tangent transformation
    double newX = xValue * cos(tSpeed) - yValue * sin(tSpeed);
    yValue = yValue * cos(tSpeed) + xValue * sin(tSpeed);
    xValue = newX;
    phi += tSpeed;


//    rSpeed = rSpeed * 0.99999999;
//    if (rSpeed < 0) {
//        std::cout << rSpeed << std::endl;
//    }

//    std::cout << (xValue * xValue + yValue * yValue) << std::endl;
}
