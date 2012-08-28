#include "Individual.h"
#include "Firm.h"
#include "Util.h"
#include <vector>
#include <iostream>
#include <string>

class Simulation{
      private:
              std::vector<Individual*> workForce;
			  std::vector<Individual*> unemployed;
              std::vector<Firm*> allFirms;
      public:
             Simulation(int populationSize, int economySize, double delta);
             ~Simulation();
      };
