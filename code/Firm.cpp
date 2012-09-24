#include "Firm.h"
#include "Util.h"
#include "Individual.h"
#include <vector>

Firm::Firm(int avg_starting_capital, int starting_individuals)
{
     capital = getRandomInt(1, 2 * avg_starting_capital);
     for(int counter = 0; counter < starting_individuals; counter++)
     {
             //ployees.push_back();
     }
}

Firm::Firm(int initialcapital, std::vector<Individual*> startingemployees)
{
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
            productivity += temp->getproductivity();
       }
       return productivity / employees.size();
       
}
