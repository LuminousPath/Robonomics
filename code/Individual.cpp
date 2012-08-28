#include "Individual.h"

Individual::Individual(){
	gType p1 = 0;
	gType p2 = 18446744073709551615;
	gType c1 = getRandomChild(p1,p2);	
	skillset = c1;
}

Individual::Individual(gType p1, gType p2,bool crossoverFlag){
	if(crossoverFlag) skillset = crossOver(p1,p2);
	else skillset = getRandomChild(p1,p2);
}


