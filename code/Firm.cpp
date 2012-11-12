#include "Firm.h"

Firm::Firm(int avg_starting_capital, int starting_individuals)
{    
     id = GenerateID();
     //bitset of all 0s
     gType p1 = 0;
     //bitset of all 1s: (2^64)-1
     gType p2;
     p2.set();
     //get random bits from each parent to create the child
     companyProduct = getRandomChild(p1,p2);
     rawProduct = getRandomChild(p1,p2);
     capital = getRandomInt(1, 2 * avg_starting_capital);
     unitsLeft = 100;
     timeUntraded = 0;
     for(int i = 0 ; i < starting_individuals; i++){
             employees.push_back(new Individual::Individual());
     }
}
int Firm::GenerateID()
{
    static int s_nID = 0;
    return s_nID++;
}
Firm::~Firm(){
    delete(buysFrom);
}

Firm::Firm(int initialcapital, std::vector<Individual*> startingemployees)
{
     id = GenerateID();
     //bitset of all 0s
     gType p1 = 0;
     //bitset of all 1s: (2^64)-1
     gType p2;
     p2.set();
     capital = initialcapital;
	 unitsLeft = 100;
     timeUntraded = 0;
     employees = startingemployees;
     companyProduct = getRandomChild(p1,p2);
     rawProduct = getRandomChild(p1,p2);
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



