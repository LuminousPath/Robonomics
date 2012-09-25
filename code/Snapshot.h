//#include <libxml/encoding.h>
//#include <libxml/xmlwriter.h>
#include <vector>
#include "Individual.h"
#include "Firm.h"

#pragma once

class Snapshot{
    private:
        std::vector<Individual*> unemployed;
        std::vector<Firm*> Firmlist;
    public:
        Snapshot(std::vector<Individual*> unemployed, std::vector<Firm*> Firmlist);
        void print_toscreen();
        void print_toXML();

};
