#pragma once

#include "Util.h"
#include "Individual.h"
#include "Types.h"
#include <limits.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

class Firm{
      private:
              
      public:
             Firm(int, int);
             Firm(int, std::vector<Individual*>);
             double capital; 
             unsigned long long unitsLeft;
             gType companyProduct;
             gType rawProduct;
             double productCost;
             std::vector<Individual*> employees;
             double getcapital();
             double getproductivity();
             gType getcompanyProduct();
             std::vector<Individual*> getemployees();
             void employeeProductUpdate();
             void sortEmployees();             
      };

