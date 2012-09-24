#include "Simulation.h"
#include <stdlib.h>
#include <time.h>



Simulation::Simulation(Configurator* filename){
    if(filename->initialized == true)
    {
         Simulation::setup(filename);
         std::cout << "Initialized OK\n";
    }
    else
    {
        std::cout << "error in config initialization\n";
    }

}

void Simulation::setup(Configurator* configuration){
     int firmcounter = 0;
     
     for(int counter = 0; counter < (configuration->get_startfirms() * configuration->get_start_individuals()); counter++)
     {
             workForce.push_back(new Individual());
     }
     
     while(firmcounter < configuration->get_startfirms())
     {
             srand(time(NULL));
             allFirms.push_back(new Firm(configuration->get_avg_starting_capital(), configuration->get_start_individuals()));
             std::cout << allFirms.at(firmcounter)->getproductivity();
             firmcounter++;
     }
}

void Simulation::run(){
}
