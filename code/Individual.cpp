#include "Individual.h"

Individual::Individual(){
	gType p1 = 0;
	gType p2 = 18446744073709551615;
	gType c1 = getRandomChild(p1,p2);	
	skillSet = c1;
}

Individual::Individual(gType p1, gType p2,bool crossoverFlag){
	if(crossoverFlag) skillSet = crossOver(p1,p2);
	else skillSet = getRandomChild(p1,p2);
}


