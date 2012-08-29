#pragma once

#include "Util.h"
#include "Individual.h"
#include "Firm.h"
#include <vector>
#include <iostream>
#include <string>

class Simulation{
      private:
              std::vector<Individual*> workForce;
              std::vector<Firm*> allFirms;
      public:
             Simulation(int populationSize, int economySize, double delta, int maxBusinessCycles);
             ~Simulation();
      };
