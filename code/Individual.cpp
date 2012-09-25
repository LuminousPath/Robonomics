#include "Individual.h"
#include <iostream>

Individual::Individual(){
	//bitset of all 0s
	gType p1 = 0;
	//bitset of all 1s: (2^64)-1
	gType p2;
	p2.set();
	//get random bits from each parent to create the child
	skillSet = getRandomChild(p1,p2);
	age = getRandomInt(1, 100);
	lifespan = getRandomInt(50, 99);
}

Individual::Individual(gType p1, gType p2,bool crossoverFlag){
	if(crossoverFlag) skillSet = crossOver(p1,p2);
	else skillSet = getRandomChild(p1,p2);
}

double Individual::getproductivity(gType ProductID)
{
       unsigned long test;
       test = getHammingDistance(ProductID, skillSet);
       std::cout << test << std::endl;
       if(ProductID != NULL)
       {
            return 1 - (getHammingDistance(ProductID, skillSet) / sizeof(gType));
       }
       else
          return 0;
}

int Individual::getage()
{
    return age;
}

int Individual::getlifespan()
{
    return lifespan;
}


