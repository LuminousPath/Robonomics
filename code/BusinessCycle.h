#include <vector>
#include "firm.h"

class BusinessCycle{
      private:
              vector<firm*> firmindex;
              vector<individual*> unemployed;
              product productID;
      public:
             BusinessCycle();
             void Cycle();
};
