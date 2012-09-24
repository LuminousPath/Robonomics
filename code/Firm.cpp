#include "Firm.h"
#include "Util.h"
#include "Individual.h"
#include <iostream>
#include <limits.h>
#include <vector>

Firm::Firm(int avg_starting_capital, int starting_individuals)
{
     capital = getRandomInt(1, 2 * avg_starting_capital);
     companyProduct = getRandomChild(0, ULLONG_MAX);
     std::cout << companyProduct;
     for(int counter = 0; counter < starting_individuals; counter++)
     {
             //don't uncomment this, thar be dragons here
             //employees.push_back();
     }
}

Firm::Firm(int initialcapital, std::vector<Individual*> startingemployees)
{
    capital = initialcapital;
    employees = startingemployees;
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
       }
       return productivity / employees.size();

}
