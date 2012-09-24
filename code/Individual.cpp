#include "Individual.h"

Individual::Individual(){
	//bitset of all 0s
	gType p1 = 0;
	//bitset of all 1s: (2^64)-1
	unsigned long long m = (unsigned long long)pow(2.0,64);
	gType p2(m);
	//get random bits from each parent to create the child
	skillSet = getRandomChild(p1,p2);
}

Individual::Individual(gType p1, gType p2,bool crossoverFlag){
	if(crossoverFlag) skillSet = crossOver(p1,p2);
	else skillSet = getRandomChild(p1,p2);
}

double Individual::getproductivity(gType ProductID)
{
     return 1 - (getHammingDistance(ProductID, skillSet) / sizeof(gType));
}


