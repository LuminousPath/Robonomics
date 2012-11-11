#pragma once
#include "Individual.h"
#include "Firm.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstring>

class Snapshot{
    private:
        std::vector<Individual*> unemployed;
        std::vector<Firm*> Firmlist;
    public:
        Snapshot(std::vector<Individual*> unemployed, std::vector<Firm*> Firmlist);
        void print_toscreen();
        void print_toXML(const char*);

};
