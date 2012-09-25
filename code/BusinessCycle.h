#include "Firm.h"
#include "Individual.h"
#include "Snapshot.h"
#include <vector>

class BusinessCycle{
      private:
              std::vector<Firm*> firmindex;
              std::vector<gType> productindex;
              std::vector<Individual*> all_the_peoples;
              std::vector<Individual*> unemployed;

      public:
             BusinessCycle(std::vector<Firm*>, std::vector<Individual*>, std::vector<Individual*>);
             Snapshot firstcycle();
             Snapshot cycleout();
             void cyclein(Snapshot);
             void Cycle();
};
