#pragma once

#include "Util.h"
#include "Individual.h"
#include "Types.h"
#include <limits.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <bitset>

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

