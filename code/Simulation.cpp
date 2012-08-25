#include "Simulation.h"
#include "time.h"

Simulation::Simulation(int x){
     srand ( time(NULL) );
     int k = 0;
     
     //LOL ARE YOU KIDDING ME THIS IS THE GREATEST PROTOTYPE EVER
     for(int i = 0; i < x; i++) printCrap(k++,7);
}

void Simulation::printCrap(int n,int k){
     
     int i = rand() % 127 + 8;
     std::cout << std::string(n%10, ' ');
     std::cout << std::string(1, i);
}
