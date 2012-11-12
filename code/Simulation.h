#pragma once

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <vector>
#include <iostream>
#include <string>

#include "Snapshot.h"
#include "BusinessCycle.h"
#include "Util.h"
#include "Individual.h"
#include "Configurator.h"
#include "Firm.h"

class Simulation{
            std::vector<Individual*> workForce;
            std::vector<Firm*> allFirms;
            std::vector<gType> productlist;
            std::vector<Individual*> unemployedpeeps;
            Configurator* config;
            int numcycles;
      public:
             Simulation(Configurator*);
             ~Simulation();
             void run();
             bool setup(Configurator*);
      };
