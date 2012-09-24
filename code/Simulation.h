#include "Util.h"
#include "Individual.h"
#include "Firm.h"
#include "Configurator.h"
#include <vector>
#include <iostream>
#include <string>

class Simulation{
              std::vector<Individual*> workForce;
              std::vector<Firm*> allFirms;
              std::vector<gType> productlist;
      public:
             Simulation(Configurator*);
             ~Simulation();
             void setup(Configurator*);
             void run();
      };
