#include "Firm.h"

Firm::Firm(int avg_starting_capital, int starting_individuals)
{
     //bitset of all 0s
     gType p1 = 0;
     //bitset of all 1s: (2^64)-1
     gType p2;
     p2.set();
     //get random bits from each parent to create the child
     companyProduct = getRandomChild(p1,p2);
     std::cout << companyProduct;
     capital = getRandomInt(1, 2 * avg_starting_capital);
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

void Firm::employeeProductUpdate(){
     for(int i = 0; i < employees.size();i++){
             employees.at(i)->setProd(getcompanyProduct());
     }
}
bool individualComparator(Individual* first, Individual* second)
{
     return  first->getproductivity(first->prod) > second->getproductivity(second->prod);
}

void Firm::sortEmployees(){
     std::sort(employees.begin(), employees.end(), individualComparator);
}



