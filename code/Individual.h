#pragma once

#include "Types.h"
#include "Util.h"
#include <iostream>
#include <limits.h>

class Individual{
      private:
      public:
             Individual();
             ~Individual();
             Individual(gType p1, gType p2, bool crossoverFlag);
             int lifespan;
             int age;
             int timeUnemployed;
             bool isRetired();
             double getproductivity(gType);
             double getproductivity();
             int getlifespan();
             int getage();
             void setProd(gType);
             gType prod;
             gType skillSet;
      };
