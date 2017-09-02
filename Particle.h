#ifndef PARTICLEEXPLOSION_PARTICLE_H
#define PARTICLEEXPLOSION_PARTICLE_H


class Particle {
private:
    double xValue;
    double yValue;
    double rSpeed;
    double phi;
    double tSpeed;
public:
    Particle();
    virtual ~Particle();
    double getX() {return xValue;}
    double getY() {return yValue;}
    void update(int timeElapsed);
};


#endif //PARTICLEEXPLOSION_PARTICLE_H
