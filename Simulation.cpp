#include "Simulation.h"

Simulation::Simulation(Screen *screen, int swarmSize): pScreen(screen) {
    this->isRunning = false;
    this->pSwarm = new Swarm(swarmSize);
}


Simulation::~Simulation() {
    delete(pScreen);
    delete(pSwarm);
}

int Simulation::run() {
    cout << "INIT\n" << endl;
    this->pScreen->setup();

    if (this->pScreen->getResult() == 0){
        cout << "\nRUN" << endl;
        cout << "Program is running..." << endl;
        this->start();
    } else {
        cout << "Program encountered unexpected problems!" << endl;
    }

    cout << "\nCLOSE" << endl;
    return this->pScreen->close();
}

void Simulation::handleLogic() {

    int elapsed = SDL_GetTicks();
    Uint8 red = (Uint8)(128.0 * (1.0 + sin(elapsed * 0.0005 + 2*M_PI/3)));
    Uint8 green = (Uint8)(128.0 * (1.0 + sin(elapsed * 0.0005 + M_PI)));
    Uint8 blue = (Uint8)(128.0 * (1.0 + sin(elapsed * 0.0005)));

    const Particle * const pParticles = this->pSwarm->getParticles();

    pScreen->reset();
    pSwarm->update();

    for (int i = 0; i < this->pSwarm->getSwarmSize(); i++) {
        Particle particle = pParticles[i];

        int x = (int)((particle.getX() + 1) * (this->pScreen->getWidth()/2));
        int y = (int)((particle.getY() + 1) * (this->pScreen->getHeight()/2));

        this->pScreen->setPixelColor(x, y, red, green, blue);
    }
//    Uint32 *pBufferToDraw = this->draw(
//            this->pScreen->getBuffer(),
//            this->pScreen->getWidth(),
//            this->pScreen->getHeight()
//    );
//
//    this->pScreen->setBuffer(pBufferToDraw);
}

void Simulation::start() {
    this->isRunning = true;
    SDL_Event event;

    while (this->isRunning) {
        this->isRunning = this->pScreen->handleEvents(&event);
        this->handleLogic();
        this->pScreen->handleRendering();
    }
}

Uint32* Simulation::draw(Uint32 *pBuffer, int width, int height) {
    int elapsed = SDL_GetTicks();

    Uint8 red = (Uint8)(128.0 * (1.0 + sin(elapsed * 0.0005)));
    Uint8 green = (Uint8)(128.0 * (1.0 + sin(elapsed * 0.0005)));
    Uint8 blue = (Uint8)(128.0 * (1.0 + sin(elapsed * 0.0005)));
    Uint8 alpha = 0xFF;

    Uint32 color;
    color = red << 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += alpha;

    Uint32 *pResult = new Uint32[width * height];

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            pResult[j * width + i] = color;
        }
    }

    return pResult;
}
