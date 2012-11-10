#include "BusinessCycle.h"
#include "Snapshot.h"

BusinessCycle::BusinessCycle(std::vector<Firm*> fi, std::vector<Individual*> ii, std::vector<Individual*> transients)
{
     firmindex = fi;
     all_the_peoples = ii;
     unemployed=transients;

}

Snapshot BusinessCycle::firstcycle()
{
      Snapshot firstsnap(unemployed, firmindex);
      return firstsnap;
}

Snapshot BusinessCycle::cycleout()
{
      Snapshot cycledsnap(unemployed, firmindex);
      return cycledsnap;
}

void BusinessCycle::cyclein(Snapshot previous_cycle)
{

}

void BusinessCycle::Cycle()
{

}



