#pragma once

#include "Individual.h"
#include "Firm.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include "Graph.h"

class Snapshot{
    private:
        std::vector<Individual*> unemployed;
        std::vector<Firm*> Firmlist;
    public:
        Snapshot(std::vector<Individual*> unemployed, std::vector<Firm*> Firmlist);
        void print_toscreen();
        void print_toCSV(int, std::string);
        void appendToGraph(int);
        void print_toGraphML(std::string);
        //void print_toXML(const char*);

};

static Graph outGraph;
