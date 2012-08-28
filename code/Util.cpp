#include "Util.h"

int getHammingDistance(gType v1, gType v2){
	return (v1 ^ v2).to_ulong();
}

//randomly pick a parent to fulfill genetic requirements at each increment in the genome
gType getRandomChild(gType p1, gType p2){
	gType child = 0;
	std::vector<gType> genePool;
	genePool.push_back(p1);
	genePool.push_back(p2);

	for(int i = 0; i < p1.size(); i++){
		int n = getRandomInt(0,2);
		child.at(i) = genePool.at(n).at(i);
	}
	return child;
}

//pick a cross-over point to choose parental gene sequences to insert into child genome
gType crossOver(gType p1, gType p2){
	gType child = 0;
	int split = getRandomInt(0,p1.size());

	std::vector<gType> genePool;
	genePool.push_back(p1);
	genePool.push_back(p2);

	//randomly pick the first parent sequence
	int n = getRandomInt(0,2);
	for(int i = 0; i < p1.size()-split; i++){
		child.at(i) = genePool.at(n).at(i);
	}
	n+=1;
	n%=2;
	for(int i = split; i < p1.size(); i++){
		child.at(i) = genePool.at(n).at(i);
	}
	return child;
}

//mutate a gType randomly using exclusive or
gType mutate(gType c1){
	for(int i = 0; i < c1.size(); i++){
		bool t = c1.at(i);
		t ^= getRandomInt(0,2);
		c1.at(i) = t;
	}
	return c1;
}

//get a random positive integer between l and h (non-inclusive)
int getRandomInt(int l, int h){
	h = abs(h);
	l = abs(l);
	//size check
	if(l > h){
		int t = l;
		l = h;
		h = t;
	}
  return (rand() % h + l);
}

double getDelta(double x1, double x2){
	return abs(x1-x2);
}

bool aboveThresh(double x1, double x2, double thresh){
	return (getDelta(x1,x2)>=thresh);
}