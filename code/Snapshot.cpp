#include "Snapshot.h"
#include <iostream>
#include <vector>

Snapshot::Snapshot()
{

}

void Snapshot::print_toscreen()
{
     int counter = 0;
     int counter2 = 0;
     std::vector<Firm*>::iterator it = Firmlist.begin();
     Firm* firmpointer;
     std::vector<Individual*>::iterator it2 = unemployed.begin();
     std::vector<Individual*>::iterator it3;
     Individual* personpointer;
     
     for(; it < Firmlist.end(); it++)
     {
           
           firmpointer = *it;
           std::cout << "Firm: " << counter + 1 << std::endl << "Productivity: " << firmpointer->getproductivity() << std::endl << "capital: " << firmpointer->getcapital() << std::endl;
           for(it3 = firmpointer->getemployees().begin(); it3 < firmpointer->getemployees().end(); it3++)
           {
                   personpointer = *it3;
                   std::cout << "Person: " << counter2 + 1 << std::endl << "Productivity: " << personpointer->getproductivity(firmpointer->getcompanyProduct()) << std::endl << "Age: " << personpointer->getage() << std::endl << "lifespan: " << personpointer->getlifespan() << std::endl;
                   counter2++;
           }
           counter++;
     }
     for(; it2 < unemployed.end(); it2++)
     {
           personpointer = *it2;
           std::cout << "Person: " << counter2 + 1 << std::endl << "Productivity: " << personpointer->getproductivity(NULL) << std::endl << "Age: " << personpointer->getage() << std::endl << "lifespan: " << personpointer->getlifespan() << std::endl;
           counter2++;
     }
}

void Snapshot::print_toXML()
{

}
