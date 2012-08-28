#include <vector>
#include "Firm.h"
#include "Individual.h"

class BusinessCycle{
      private:
              std::vector<Firm*> firmindex;
              std::vector<Individual*> unemployed;

      public:
             BusinessCycle();
             void Cycle();
};
