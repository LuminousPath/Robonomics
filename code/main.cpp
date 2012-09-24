#include "Simulation.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
            std::cout << "Please provide the simulation configuration filename" << std::endl;
    else{
         Configurator* config = new Configurator(argv[1]);
         Simulation * sim = new Simulation(config);
         sim->run();
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
