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
         std::cout << "Initialized OK\n";
    }
    else
    {
        std::cout << "error in config initialization\n";
    }

}

bool Simulation::setup(Configurator* configuration){
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
     
     std::cout << "Initialized workforce" << std::endl;
    
     iter = 0;
     while(firmcounter < configuration->get_startfirms())
     {
             while(iter < configuration->get_start_individuals())
             {
                 addworkers.push_back(workForce.at(iter));
                 iter++;
             }
             srand(time(NULL));
             allFirms.push_back(new Firm(getRandomInt(0, configuration->get_avg_starting_capital() * 2), addworkers));
             productlist.push_back(allFirms.back()->getcompanyProduct());
             //std::cout << allFirms.back()->getemployees().back()->getage() << std::endl;
             std::cout << "Firm " << firmcounter + 1 << " initialization complete, productivity: " << allFirms.back()->getproductivity() << std::endl;
             firmcounter++;
             addworkers.clear();
     }
     
     std::cout << "initialized all firms" << std::endl;


}

void Simulation::run(){
    int counter = 0;
    Snapshot cyclesnap;
    BusinessCycle* cycler = new BusinessCycle(allFirms, workForce);
    cyclesnap = cycler->firstcycle();
    std::cout << "Starting Cycles" << std::endl;
    while(counter < numcycles)
    {
           cyclesnap = cycler->cycleout();
           cycler->cyclein(cyclesnap);
           cyclesnap.print_toscreen();
           std::cout << std::endl << "Cycle " << counter + 1 << " completed." << std::endl << std::endl;
    }
}

