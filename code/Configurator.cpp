#include "Configurator.h"


Configurator::Configurator(char* filename){
      initialized = false;
      startfirms = 0;
      start_individuals = 0;
      avg_starting_capital = 0;
      hire_fire_threshold = 0;
      modicum_of_acceptance = 0;
      cycles = 0;
      inactivity_rate = 0;
      csv_path = "derp";
      graphml_path = "derp";

      std::ifstream infile;
      std::string line;
      infile.open(filename, std::ifstream::in);
      if(infile.good())
      {
          while(infile.good())
          {
               getline (infile, line, '=');
               if(line == "start_firms")
               {
                       getline(infile, line, '\n');
                       startfirms = atoi(line.c_str());
               }
               if(line == "start_individuals")
               {
                       getline(infile, line, '\n');
                       start_individuals = atoi(line.c_str());
               }
               if(line == "avg_starting_capital")
               {
                       getline(infile, line, '\n');
                       avg_starting_capital = atoi(line.c_str());
               }
               if(line == "hire_fire_threshold")
               {
                       getline(infile, line, '\n');
                       hire_fire_threshold = atoi(line.c_str());
               }
               if(line == "modicum_of_acceptance")
               {
                       getline(infile, line, '\n');
                       modicum_of_acceptance = atoi(line.c_str());
               }
               if(line == "cycles")
               {
                       getline(infile, line, '\n');
                       cycles = atoi(line.c_str());
               }
               
               if(line == "inactivity_rate")
               {
                       getline(infile, line, '\n');
                       inactivity_rate = atoi(line.c_str());
               }
               if(line == "csv_path")
               {
                       getline(infile, line, '\n');
                       csv_path = line.c_str();
               }
               if(line == "graphml_path")
               {
                       getline(infile, line, '\n');
                       graphml_path = line.c_str();
               }
          }
          initialized = true;
      }
}

int Configurator::get_startfirms()
{
    return startfirms;
}

int Configurator::get_avg_starting_capital()
{
    return avg_starting_capital;
}

int Configurator::get_start_individuals()
{
    return start_individuals;
}

int Configurator::get_hire_fire_threshold()
{
    return hire_fire_threshold;
}

int Configurator::get_modicum_of_acceptance()
{
    return modicum_of_acceptance;
}

int Configurator::get_inactivity_rate()
{
    return inactivity_rate;
}

int  Configurator::get_cycles()
{
     return cycles;
}

std::string  Configurator::get_graphml_path()
{
     return graphml_path;
}

std::string  Configurator::get_csv_path()
{
     return csv_path;
}
