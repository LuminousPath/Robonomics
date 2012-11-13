#include "Util.h"

int getHammingDistance(gType v1, gType v2)
{
	return (v1^v2).count();
}

//randomly pick a parent to fulfill genetic requirements at each increment in the genome
gType getRandomChild(gType p1, gType p2){
	gType child;
	child.set();
	std::vector<gType> genePool;
	genePool.push_back(p1);
	genePool.push_back(p2);

	for(int i = 0; i < p1.size(); i++){
		int n = getRandomInt(0,2);
		child.set(i, genePool[n][i]);
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
		child.set(i, genePool[n][i]);
	}
	n+=1;
	n%=2;
	for(int i = split; i < p1.size(); i++){
		child.set(i, genePool[n][i]);
	}
	return child;
}

//mutate a gType randomly using exclusive or
gType mutate(gType c1){
	for(int i = 0; i < c1.size(); i++){
		bool t = c1[i];
		t ^= getRandomInt(0,2);
		c1.set(i,t);
	}
	return c1;
}

//get a random positive integer between l and h (non-inclusive)
int getRandomInt(int l, int h){
	h = (int)std::abs((double)h);
	l = (int)std::abs((double)l);
	//size check
	if(l > h){
		int t = l;
		l = h;
		h = t;
	}
    int x = 0;
	while((x =(rand() % h)) < l);
  return x;
}

double getDelta(double x1, double x2){
	return fabs(x1-x2);
}

bool aboveThresh(double x1, double x2, double thresh){
	return (getDelta(x1,x2)>=thresh);
}

void find_replace(std::string &s, std::string find, std::string replace)
{
    s = s.replace(s.find(find), find.length(), replace);
}

std::string intToStr(int i){
    std::stringstream ss;
    ss << i;
    return ss.str();
}

std::string intToStr(double i){
    std::stringstream ss;
    ss << i;
    return ss.str();
}
