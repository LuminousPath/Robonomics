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
                Firm* firm = firmindex.at(i);
                //individuals mentor
                //declare the product for each employee so we can sort based on productivity
                firm->employeeProductUpdate();
                //get a list of employees with which to work
                std::vector<Individual*> empls = firm->getemployees();
                std::vector<Individual*> mentors;
                // get the number of people who will be mentoring
                int numMentors = (int)(empls.size()*(double)config->get_modicum_of_acceptance()/100.0); 
                //std::cout << firmindex.at(i)->getemployees().size()<<"\n";
                firm->sortEmployees();
                for(int j = 0; j < numMentors;j++){
                        //a certain percentage of individuals within the firm whose skill sets match the product type most closely 
                        //must mentor new individuals who start at an initial age
                        
                        if(!empls.at(j)->isRetired()){
                             mentors.push_back(empls.at(j));
                        }
                }
                for(int j = 1; j < mentors.size();j++){
                        Individual* x;  
                        //They may do this via random skill (bit) selection or via crossover
                        if(getRandomInt(0,2)) x = new Individual::Individual(mentors.at(j)->skillSet, mentors.at(j-1)->skillSet, false);
                        else{
                              x = new Individual::Individual(mentors.at(j)->skillSet, mentors.at(j-1)->skillSet, true);
                            }
                        empls.at(empls.size()-1)->skillSet = mutate(empls.at(empls.size()-1)->skillSet);
                        firm->employees.push_back(x);                  
                }                
                //get all employees
                for(int j = 0; j < empls.size();j++){
                        //iterate their ages
                        empls.at(j)->age++;          
                }
                Individual* tempEmp;
                //if they are retired, turn them into soylent green.  
                for(int c = 0;c < firm->employees.size();){  
                      if(firm->employees.at(c)->isRetired()){
                          firm->employees.erase(firm->employees.begin()+c);
                      }
                      else c++;
                }
                //firms may fire individuals
                double hft = (double)config->get_hire_fire_threshold()/100.0;
                for(int c = 0;c < firm->employees.size();){
                      if((double)(firm->employees.at(c)->getproductivity(firm->companyProduct)) <= hft){
                          tempEmp = firm->employees.at(c);
                          firm->employees.erase(firm->employees.begin()+c);
                          unemployed.push_back(tempEmp);
                      }                          
                      else c++;
                }
                //firms may hire individuals
                for(int c = 0; c < unemployed.size();){
                      if((double)unemployed.at(c)->getproductivity(firm->companyProduct) > hft){
                          tempEmp = unemployed.at(c);
                          firm->employees.push_back(tempEmp);
                          unemployed.erase(unemployed.begin() + c);
                      }
                      else c++;
                }     
        }
            
     /*
        print simulation state to file
            print everything to file in GraphML format
     */

}




