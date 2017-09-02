#include <iostream>
#include "Screen.h"
#include "Simulation.h"

using namespace std;

int main() {
    srand(time(NULL));
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int SWARM_SIZE = 5000;

    Screen *screen = new Screen(SCREEN_WIDTH, SCREEN_HEIGHT);
    Simulation *simulation = new Simulation(screen, SWARM_SIZE);

    int result = simulation->run();

    delete(simulation);

    return result;
}