#include "BusinessCycle.h"
#include "Snapshot.h"

BusinessCycle::BusinessCycle(std::vector<Firm*> i_hate_chet, std::vector<Individual*> i_also_hate_chet, std::vector<Individual*> homelesspeople)
{
     firmindex = i_hate_chet;
     all_the_peoples = i_also_hate_chet;
     unemployed=homelesspeople;

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



