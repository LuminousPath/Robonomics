#pragma once

#include "Simulation.h"
#include "Snapshot.h"
#include "Firm.h"
#include "Individual.h"
#include "Configurator.h"

#include <vector>
#include <iostream>
#include <algorithm>

class BusinessCycle{
      private:
            std::vector<Firm*> firmindex;
            std::vector<gType> productindex;
            std::vector<Individual*> all_the_peoples;
            std::vector<Individual*> unemployed;
            Configurator* config;
      public:
            BusinessCycle(std::vector<Firm*> &fi, std::vector<Individual*> &ii, std::vector<Individual*> &transients);
            Snapshot firstcycle();
            Snapshot cycleout();  
            void setConfigurator(Configurator*);
            void cyclein(Snapshot);
            void cycle();
};
