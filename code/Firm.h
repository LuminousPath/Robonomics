#pragma once

#include <bitset>
#include "Types.h"
#include "Individual.h"
#include <vector>




class Firm{
      private:
              gType companyProduct;
              double capital;
              std::vector<Individual*> employees;
              
      public:
             Firm(int, int);
             Firm(int, std::vector<Individual*>); 
             double getcapital();
             double getproductivity();
             gType getcompanyProduct();
             std::vector<Individual*> getemployees();         
      };

