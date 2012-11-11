#include "Simulation.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
    char* path;
    if(argc < 2){
            path = "C:\\Users\\parrotch\\Desktop\\config.cfg";
            /*
            // taking this out for now.
            std::cout << "Please provide the simulation configuration filename" << std::endl;
            std::cin >> path;
            */
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
