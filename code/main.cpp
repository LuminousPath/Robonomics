#include <cstdlib>
#include <iostream>
#include "Simulation.h"

int main(int argc, char *argv[])
{
    Simulation * sim = new Simulation(12,12,.2);
    system("PAUSE");
    return EXIT_SUCCESS;
}
