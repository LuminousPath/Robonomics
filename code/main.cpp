#include "Simulation.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
    //std::cout << argv[1] << std::endl;
    char* path = "C:\\Users\\parrotch\\Desktop\\config.cfg";
    if(argc < 2){
            std::cout << "Please provide the simulation configuration filename" << std::endl;
            std::cin.get();
            std::cout << path;
    }
    else{
         path = argv[1];
    }
    Configurator* config = new Configurator(path);
    Simulation * sim = new Simulation(config);
    sim->run();
    system("pause");
    return EXIT_SUCCESS;
}
