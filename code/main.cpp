#include "Simulation.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
    //std::cout << argv[1] << std::endl;
    if(argc < 2)
            std::cout << "Please provide the simulation configuration filename" << std::endl;
    else{
         Configurator* config = new Configurator(argv[1]);
         Simulation * sim = new Simulation(config);
         sim->run();
    }
    std::cin.get();
    return EXIT_SUCCESS;
}
