#pragma once

#include "Firm.h"
#include "Individual.h"
#include <vector>

class BusinessCycle{
      private:
              std::vector<Firm*> firmindex;
              std::vector<Individual*> unemployed;

      public:
             BusinessCycle();
             void Cycle();
};
