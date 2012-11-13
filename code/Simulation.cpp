#include "Simulation.h"

Simulation::Simulation(Configurator* filename){

    if(filename->initialized == true)
    {
         std::cout << "Configuration Read-In OK" << std::endl;
         numcycles = filename->get_cycles();
         Simulation::setup(filename);
         std::cout << std::endl << "Initialized OK\n" << std::endl;
         config = filename;
    }
    else
    {
        std::cout << "error in config initialization\n";
    }

}

bool Simulation::setup(Configurator* configuration){
     //initialize random number function
     srand(time(NULL));
     // number of firms
     int firmcounter = 0;

     // pointer to an individual
     Individual* indiepointer;
     // iterator over a vector of individual pointers
     std::vector<Individual*>::iterator it;
     // vector of individual pointers
     std::vector<Individual*> addworkers;

     std::cout << "Starting Simulation initialization" << std::endl;
     // while the counter is less than the number of starting firms multiplied by the number of starting individuals, iterate
     for(int counter = 0; counter < (configuration->get_startfirms() * configuration->get_start_individuals()); counter++)
     {
             // add a new individual to the workforce
             workForce.push_back(new Individual());
     }
     int upperbnd = getRandomInt(1, configuration->get_startfirms());
     // while the counter is less than a random number between 1 and the starting number of firms, iterate
     for(int counter = 0; counter < upperbnd; counter++)
     {
             // add a new individual to the workforce
             workForce.push_back(new Individual());
     }

     std::cout << "Initialized workforce" << std::endl;

     // iterating integers
     int iter = 0;
     int iter2 = 0;
     // for each firm
     while(firmcounter < configuration->get_startfirms())
     {
             // for each individual
             while(iter2 < configuration->get_start_individuals())
             {
                 addworkers.push_back(workForce.at(iter));
                 iter2++;
                 iter++;
             }
             //reset iterator 2 to zero
             iter2 = 0;
             // push a new firm into the list of firms with a list of workers "addworkers"
             allFirms.push_back(new Firm(getRandomInt(0, configuration->get_avg_starting_capital() * 2), addworkers));
             // push that firms product into the market product list
             productlist.push_back(allFirms.back()->getcompanyProduct());
             std::cout << "Firm " << firmcounter + 1 << " initialization complete, productivity: " << allFirms.back()->getproductivity() << std::endl;
             // iterate firmcounter
             firmcounter++;
             // clear the addworkers vector
             addworkers.clear();
     }

     std::cout << "initialized all firms" << std::endl;

     // for everyone else; they are unemployed for the first cycle
     while(iter < workForce.size())
     {
         unemployedpeeps.push_back(workForce.at(iter));
         iter++;
     }
     std::cout << "Initialized the unemployed" << std::endl;
}

void Simulation::run(){
     // initialize an iterator
    int counter = 0;
    // create a new business cycle pointer
    BusinessCycle* cycler = new BusinessCycle(allFirms, workForce, unemployedpeeps);
    cycler->setConfigurator(config);
    std::cout << "Cycler Created" << std::endl;
    // run the first cycle
    Snapshot cyclesnap = cycler->firstcycle();
    std::cout << "Starting Cycles" << std::endl;
    // while we have not run all the cycles
    while(counter < numcycles)
    {
           cycler->cycle();
           std::cout << std::endl << "Cycle: " << counter + 1 << std::endl;
           // cycle out
           cyclesnap = cycler->cycleout();
           std::cout << "cycleout ok" << std::endl;
           // cycle in
           cycler->cyclein(cyclesnap);
           std::cout << "cyclein ok" << std::endl;
           // output to screen
           cyclesnap.print_toCSV(counter);
           std::cout << std::endl << "Cycle " << counter + 1 << " completed." << std::endl << std::endl;
           counter++;
    }
}

