#include "Simulation.h"
#include "Snapshot.h"
#include "BusinessCycle.h"
#include <stdlib.h>
#include <time.h>
#include <vector>



Simulation::Simulation(Configurator* filename){

    if(filename->initialized == true)
    {
         std::cout << "Configuration Read-In OK" << std::endl;
         numcycles = filename->get_cycles();
         Simulation::setup(filename);
         std::cout << std::endl << "Initialized OK\n" << std::endl;
    }
    else
    {
        std::cout << "error in config initialization\n";
    }

}

bool Simulation::setup(Configurator* configuration){
     srand(time(NULL));
     int firmcounter = 0;
     int iter = 0;
     Individual* indiepointer;
     std::vector<Individual*>::iterator it;
     std::vector<Individual*> addworkers;

     std::cout << "Starting Simulation initialization" << std::endl;

     for(int counter = 0; counter < (configuration->get_startfirms() * configuration->get_start_individuals()); counter++)
     {
             workForce.push_back(new Individual());
             //std::cout << workForce.back()->getage() << std::endl;
             //std::cout << counter << std::endl;
     }
     for(int counter = 0; counter < getRandomInt(1, configuration->get_startfirms()); counter++)
     {
             workForce.push_back(new Individual());
     }

     std::cout << "Initialized workforce" << std::endl;

     iter = 0;
     int iter2 = 0;
     while(firmcounter < configuration->get_startfirms())
     {
             while(iter2 < configuration->get_start_individuals())
             {
                 addworkers.push_back(workForce.at(iter));
                 //std::cout << addworkers.back()->getage() << std::endl;
                 iter2++;
                 iter++;
             }
             iter2 = 0;
             srand(time(NULL));
             allFirms.push_back(new Firm(getRandomInt(0, configuration->get_avg_starting_capital() * 2), addworkers));
             productlist.push_back(allFirms.back()->getcompanyProduct());
             std::cout << "Firm " << firmcounter + 1 << " initialization complete, productivity: " << allFirms.back()->getproductivity() << std::endl;
             firmcounter++;
             addworkers.clear();
     }

     std::cout << "initialized all firms" << std::endl;


     while(iter < workForce.size())
     {
         unemployedpeeps.push_back(workForce.at(iter));
         iter++;
     }

     std::cout << "Initialized the homeless" << std::endl;


}

void Simulation::run(){

    int counter = 0;
    BusinessCycle* cycler = new BusinessCycle(allFirms, workForce, unemployedpeeps);
    std::cout << "Cycler Created" << std::endl;
    Snapshot cyclesnap = cycler->firstcycle();
    std::cout << "Starting Cycles" << std::endl;
    while(counter < numcycles)
    {
           std::cout << std::endl << "Cycle: " << counter + 1 << std::endl;
           cyclesnap = cycler->cycleout();
           std::cout << "cycleout ok" << std::endl;
           cycler->cyclein(cyclesnap);
           std::cout << "cyclein ok" << std::endl;
           cyclesnap.print_toscreen();
           std::cout << std::endl << "Cycle " << counter + 1 << " completed." << std::endl << std::endl;
           counter++;
    }
}

