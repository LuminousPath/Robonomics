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

void BusinessCycle::cycle()
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
                        
        for(int i = 0; i < firmindex.size();i++){
                //individuals mentor
                //declare the product for each employee so we can sort based on productivity
                firmindex.at(i)->employeeProductUpdate();
                //get a list of employees with which to work
                std::vector<Individual*> empls = firmindex.at(i)->getemployees();
                std::vector<Individual*> mentors;
                // get the number of people who will be mentoring
                int numMentors = (int)(empls.size()*(double)config->get_modicum_of_acceptance()/100.0); 
                //std::cout << firmindex.at(i)->getemployees().size()<<"\n";
                firmindex.at(i)->sortEmployees();
                //std::cout <<numMentors << "\n";
                for(int j = 0; j < numMentors;j++){
                        //a certain percentage of individuals within the firm whose skill sets match the product type most closely must mentor new individuals who start at an initial age
                        //They may do this via random skill (bit) selection or via crossover
                        if(!empls.at(j)->isRetired()){
                             mentors.push_back(empls.at(j));
                        }
                }
                for(int j = 1; j < mentors.size();j++){  
                        Individual x = Individual::Individual(mentors.at(j)->skillSet, mentors.at(j-1)->skillSet, false);
                        firmindex.at(i)->employees.push_back(&x);
                        x = Individual::Individual(mentors.at(j)->skillSet, mentors.at(j-1)->skillSet, true);
                        firmindex.at(i)->employees.push_back(&x);                        
                        x = Individual::Individual(mentors.at(j)->skillSet, mentors.at(j-1)->skillSet, false);
                        x.skillSet = mutate(x.skillSet);
                        firmindex.at(i)->employees.push_back(&x);                        
                        x = Individual::Individual(mentors.at(j)->skillSet, mentors.at(j-1)->skillSet, true);
                        x.skillSet = mutate(x.skillSet);
                        firmindex.at(i)->employees.push_back(&x);
                }
                
                for(int j = 0; j < firmindex.at(i)->employees.size();j++){
                        firmindex.at(i)->employees.at(j)->age++;
                        if(firmindex.at(i)->employees.at(j)->isRetired()){
                        }                
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




