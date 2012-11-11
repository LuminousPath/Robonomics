#include "Individual.h"

Individual::Individual(){
	//bitset of all 0s
	gType p1 = 0;
	//bitset of all 1s: (2^64)-1
	gType p2;
	p2.set();
	//get random bits from each parent to create the child
	skillSet = getRandomChild(p1,p2);
	age = 16;
	lifespan = 65;
}

Individual::~Individual(){

}

Individual::Individual(gType p1, gType p2,bool crossoverFlag){
	if(crossoverFlag) skillSet = crossOver(p1,p2);
	else skillSet = getRandomChild(p1,p2);
	age = 16;
	lifespan = 65;
}

double Individual::getproductivity(gType ProductID)
{
       if(ProductID != NULL) return 1 - ((double)getHammingDistance(ProductID, skillSet) / (double)ProductID.size()); 
       else return 0;
}

double Individual::getproductivity(){
       getproductivity(prod);
}

int Individual::getage()
{
    return age;
}

int Individual::getlifespan()
{
    return lifespan;
}

void Individual::setProd(gType p){
     prod=p;
}

bool Individual::isRetired(){
     return age >= lifespan;
}
