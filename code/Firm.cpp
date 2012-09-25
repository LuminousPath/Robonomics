#include "Firm.h"
#include "Util.h"
#include "Individual.h"
#include <iostream>
#include <bitset>
#include <limits.h>
#include <vector>

Firm::Firm(int avg_starting_capital, int starting_individuals)
{
     gType p2;
     p2.set();
     capital = getRandomInt(1, 2 * avg_starting_capital);
     companyProduct = getRandomChild(0, p2);
     std::cout << companyProduct << std::endl;
     for(int counter = 0; counter < starting_individuals; counter++)
     {
             //don't uncomment this, thar be dragons here
             //employees.push_back();
     }
}

Firm::Firm(int initialcapital, std::vector<Individual*> startingemployees)
{
    gType p2 = 0;
    p2.set();
    capital = initialcapital;
    employees = startingemployees;
    companyProduct = p2;
}

double Firm::getcapital()
{
       return capital;
}

double Firm::getproductivity()
{
       double productivity = 0;
       Individual* temp;
       std::vector<Individual*>::iterator it = employees.begin();
       for(it=employees.begin(); it<employees.end(); it++)
       {
            temp = *it;
            productivity += temp->getproductivity(companyProduct);
            std::cout << ULLONG_MAX << std::endl << temp->getproductivity(companyProduct) << std::endl;
       }
       return productivity / employees.size();

}

std::vector<Individual*> Firm::getemployees()
{
     return employees;
}

gType Firm::getcompanyProduct()
{
      return companyProduct;
}
