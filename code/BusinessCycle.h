#pragma once

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
            Firm* tempFirm;
            BusinessCycle(std::vector<Firm*>, std::vector<Individual*>, std::vector<Individual*>);
            Snapshot firstcycle();
            Snapshot cycleout();  
            void setConfigurator(Configurator*);
            void cyclein(Snapshot);
            void cycle();
};
