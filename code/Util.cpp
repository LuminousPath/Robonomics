#include "Util.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <bitset>
#include <iostream>
#include <exception>
#include <time.h>

unsigned long long getHammingDistance(gType v1, gType v2)
{
    unsigned long long derp;
    std::string temp;
    try{
           temp = (v1^v2).to_string<char,std::char_traits<char>,std::allocator<char> >();
           //std::cout << temp << std::endl;
           derp = strtoull(temp.c_str(), (char**)NULL, 2);
           //std::cout << "gethammingdistancevalue" << derp << std::endl;
           //derp = strtoull((v1 ^ v2).to_string<char,std::char_traits<char>,std::allocator<char> >().c_str(), (char**)NULL, 10);
           //printf("value: %llu \n", derp);
    }
    catch(std::exception& e){
           std::cout << "Exception: "<< e.what() << std::endl;
    }
	return derp;
}

//randomly pick a parent to fulfill genetic requirements at each increment in the genome
gType getRandomChild(gType p1, gType p2){
	gType child = 0;
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

	h = std::abs((double)h);
	l = std::abs((double)l);
	//size check
	if(l > h){
		int t = l;
		l = h;
		h = t;
	}
  return (rand() % h + l);
}

double getDelta(double x1, double x2){
	return fabs((double)(x1-x2));
}

bool aboveThresh(double x1, double x2, double thresh){
	return (getDelta(x1,x2)>=thresh);
}
