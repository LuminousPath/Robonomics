#include <vector>
#include "Firm.h"
#include "Individual.h"

class BusinessCycle{
      private:
              vector<Firm*> firmindex;
              vector<Individual*> unemployed;
              product productID;
      public:
             BusinessCycle();
             void Cycle();
};
