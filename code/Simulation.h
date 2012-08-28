#include "Individual.h"
#include "Firm.h"
#include "Util.h"
#include <vector>
#include <iostream>
#include <string>

class Simulation{
      private:
              std::vector<Individual*> WorkForce;
              std::vector<Firm*> AllFirms;
      public:
             Simulation(int x);
             ~Simulation();
      };
