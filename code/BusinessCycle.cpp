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
        firms create 
            If a firm realizes there is no product within a suitable modicum of acceptance, they may invest a certain % of their capital to create a new firm
            The mother firm may take starting individuals from the unemployment pool to seed the child firm’s ranks
        */
                        
        for(int i = 0; i < firmindex.size();i++){
                
                //this firm
                Firm* firm = firmindex.at(i);
                //get a list of employees with which to work
                std::vector<Individual*> empls = firm->getemployees();
                //hire fire threshold
                double hft = (double)config->get_hire_fire_threshold()/100.0;
                //hire fire rate
                int hfr = (int)((double)empls.size() * hft);
                if(hfr = 0) hfr = 2;
                //best product for this firm
                Firm* hasBestProduct = firmindex.at(0);
                //how close the product is to what is required
                double bestDist = 1.0;
                //find the best product for this firm
                for(int j = 0; j < firmindex.size();j++){
                        if(firmindex.at(j)->unitsLeft > 0){
                            gType tempProd = firmindex.at(j)->companyProduct;
                            double dist = (double)getHammingDistance(tempProd, firm->rawProduct)/(double)tempProd.size();
                            if(dist < bestDist){
                                    bestDist = dist;
                                    hasBestProduct = firmindex.at(j);
                            }   
                        }                    
                }
                double q = (double)(100 - config->get_modicum_of_acceptance())/100.0;
                if(config->get_avg_starting_capital()/2 < firm->capital && bestDist < q){
                     double starting = firm->capital / 2;
                     firm->capital -= starting;
                     gType prod = firm->rawProduct;
                     std::vector<Individual*> startingPpl;
                     Individual* tempEmp;
                     for(int c = 0; c < unemployed.size();c++){
                          if((double)unemployed.at(c)->getproductivity(prod) > 1.0-hft/2){
                              tempEmp = unemployed.at(c);
                              startingPpl.push_back(tempEmp);
                              unemployed.erase(unemployed.begin() + c);
                          }
                          else c++;
                      }   
                     Firm* newFirm = new Firm(0,config->get_start_individuals());
                     newFirm->unitsLeft = 100;
                     newFirm->companyProduct = prod;
                     newFirm->capital = starting;
                     firmindex.push_back(newFirm); 
                }                
                //how much does the product cost?: (quality of raw)
                firm->productCost = 1.0-bestDist;
                //while there is product left and the firm has enough money to purchase it
                int raw = 0;
                std::cout << "Raw goods available: " << hasBestProduct->unitsLeft << "\n";
                double before = firm->capital;
                while(hasBestProduct->unitsLeft > 0 && firm->capital >= hasBestProduct->productCost){
                    //make it so
                    hasBestProduct->unitsLeft--;
                    hasBestProduct->capital += hasBestProduct->productCost;
                    firm->capital -= hasBestProduct->productCost;  
                    raw++;                 
                }
                double after = firm->capital;
                std::cout << "Raw Goods Acquired: " << raw << "\n";
                //how much product is produced?: (int)(productivity)(qty of raw purchased)*(#employees)
                firm->unitsLeft += (double)((double)firm->getproductivity()*(double)raw);
                std::cout << "We created: " << firm->unitsLeft << " items that will sell for " << firm->productCost <<" each.\n";
                std::cout << "Our cost was: " << getDelta(before,after) << ". \n";
                              
                    //money += qtypurchased*(quality of raw)
                
                //individuals mentor
                //declare the product for each employee so we can sort based on productivity
                firm->employeeProductUpdate();
                std::vector<Individual*> mentors;
                // get the number of people who will be mentoring
                int numMentors = (int)(empls.size()*(double)config->get_modicum_of_acceptance()/100.0); 
                //std::cout << firmindex.at(i)->getemployees().size()<<"\n";
                firm->sortEmployees();
                //get the mentors
                for(int j = 0; j < numMentors;j++){
                        //a certain percentage of individuals within the firm whose skill sets match the product type most closely 
                        //must mentor new individuals who start at an initial age
                        
                        if(!empls.at(j)->isRetired()){
                             mentors.push_back(empls.at(j));
                        }
                }
                // mentor new employee for each mentor pair
                for(int j = 1; j < mentors.size();j++){
                        Individual* x;  
                        //They may do this via random skill (bit) selection or via crossover
                        if(getRandomInt(0,2)) x = new Individual::Individual(mentors.at(j)->skillSet, mentors.at(j-1)->skillSet, false);
                        else{
                              x = new Individual::Individual(mentors.at(j)->skillSet, mentors.at(j-1)->skillSet, true);
                            }
                        //"retrain" the least effective employee
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
                
                for(int c = 0, q = hfr; q > 0;q--){
                      if((double)(firm->employees.at(c)->getproductivity(firm->companyProduct)) <= 1.0-hft){
                          tempEmp = firm->employees.at(c);
                          firm->employees.erase(firm->employees.begin()+c);
                          unemployed.push_back(tempEmp);
                      }                          
                      else c++;
                }
                
                //firms may hire individuals                
                for(int c = 0, q = hfr; c < unemployed.size() && q > 0;q--){
                      if((double)unemployed.at(c)->getproductivity(firm->companyProduct) > 1.0-hft){
                          tempEmp = unemployed.at(c);
                          firm->employees.push_back(tempEmp);
                          unemployed.erase(unemployed.begin() + c);
                      }
                      else c++;
                }   
                if(empls.size() ==0){
                    firmindex.erase(firmindex.begin()+i);
                } 
        }
            
     /*
        print simulation state to file
            print everything to file in GraphML format
     */

}




