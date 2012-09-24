#include "Simulation.h"
#include "Snapshot.h"
#include "BusinessCycle.h"
#include <stdlib.h>
#include <time.h>
#include <vector>



Simulation::Simulation(Configurator* filename){
    if(filename->initialized == true)
    {
         numcycles = filename->get_cycles();
         Simulation::setup(filename);
         std::cout << "Initialized OK\n";
    }
    else
    {
        std::cout << "error in config initialization\n";
    }

}

bool Simulation::setup(Configurator* configuration){
     int firmcounter = 0;
     std::vector<Individual*>::iterator it;
     std::vector<Individual*> addworkers;

     for(int counter = 0; counter < (configuration->get_startfirms() * configuration->get_start_individuals()); counter++)
     {
             workForce.push_back(new Individual());
     }

     for(it = workForce.begin(); it < it + configuration->get_start_individuals(); it++)
     {
         addworkers.push_back(*it);
     }

     while(firmcounter < configuration->get_startfirms())
     {
             for(; it < it + configuration->get_start_individuals(); it++)
             {
                 addworkers.push_back(*it);
             }
             srand(time(NULL));
             allFirms.push_back(new Firm(getRandomInt(0, configuration->get_avg_starting_capital() * 2), addworkers));
             std::cout << allFirms.at(firmcounter)->getproductivity();
             firmcounter++;
             addworkers.clear();
     }


}

void Simulation::run(){
    int counter = 0;
    Snapshot cyclesnap;
    BusinessCycle* cycler = new BusinessCycle(allFirms, workForce);
    cyclesnap = cycler->firstcycle();
    while(counter < numcycles)
    {
           cyclesnap = cycler->cycleout();
           cycler->cyclein(cyclesnap);
    }
}

