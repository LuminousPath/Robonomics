#pragma once

#include "Types.h"
#include "Util.h"


class Individual{
      private:
              double productivity;
              int lifespan;
              int age;
			  gType skillSet;
      public:
             Individual();    
             Individual(gType p1, gType p2, bool crossoverFlag);             
      };
