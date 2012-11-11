#include "BusinessCycle.h"

BusinessCycle::BusinessCycle(std::vector<Firm*> fi, std::vector<Individual*> ii, std::vector<Individual*> transients)
{
     firmindex = fi;
     all_the_peoples = ii;
     unemployed=transients;
}

Snapshot BusinessCycle::firstcycle()
{
      Snapshot firstsnap(unemployed, firmindex);
      return firstsnap;
}

Snapshot BusinessCycle::cycleout()
{
      Snapshot cycledsnap(unemployed, firmindex);
      return cycledsnap;
}

void BusinessCycle::cyclein(Snapshot previous_cycle)
{

}

void BusinessCycle::setConfigurator(Configurator* c)
{
     config = c;     
}

void BusinessCycle::Cycle()
{
     /*
        firms trade
            each firm looks for raw product
            firms purchase raw product to maximum capacity
        firms bid
            if there is a conflict of interest on individual products then firms enter a bidding war
            sort the interested firms by capital value
            richest firms buy first
            if there is additional product, secondary firms can purchase raw product at the same price the richest firm paid
            continue until the list of firms is empty or product is all gone
        firms produce
            firms use raw product to create new product
            there exists a function based on net productivity that determines the amount of new product produced
        firms create 
            If a firm realizes there is no product within a suitable modicum of acceptance, they may invest a certain % of their capital to create a new firm
            The mother firm may take starting individuals from the unemployment pool to seed the child firm’s ranks
        */
                        
        //individuals mentor
        for(int i = 0; i < firmindex.size();i++){
                Individual p1;
                Individual p2;
                std::vector<Individual*> empls = firmindex.at(i)->getemployees();
                empls.size()*(double)config->get_modicum_of_acceptance()/100.0;
                for(int j = 0; j < empls.size(); j++){
                        //a certain percentage of individuals within the firm whose skill sets match the product type most closely must mentor new individuals who start at an initial age
                        //They may do this via random skill (bit) selection or via crossover
                }
                
        }
            
     /*
        firms manage
            firms may hire individuals
            firms may fire individuals
            individuals above retirement age must disappear from the economy
        print simulation state to file
            print everything to file in GraphML format
     */

}



