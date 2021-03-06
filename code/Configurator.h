#pragma once

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

class Configurator{
      private:
              int startfirms;
              int start_individuals;
              int avg_starting_capital;
              int hire_fire_threshold;
              int modicum_of_acceptance;
              int inactivity_rate;
              int cycles;
              std::string graphml_path;
              std::string csv_path;
      public:
             bool initialized;
             Configurator(char*);
             int get_startfirms();
             int get_inactivity_rate();
             int get_start_individuals();
             int get_avg_starting_capital();
             int get_hire_fire_threshold();
             int get_modicum_of_acceptance();
             int get_cycles();
             std::string get_graphml_path();
             std::string get_csv_path();
};
