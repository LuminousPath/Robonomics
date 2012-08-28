#include "Util.h"

unsigned long getHammingDistance(gType v1, gType v2){
	/*
	//vector<bool> implementation
	if(p1.size() != p2.size()) return -1;
	int distance = 0;
	for(int i = 0; i < p1.size(); i++){
		if(p1.at(i) ^ p2.at(i)) distance++;
	}
	return distance;*/

	return (v1 ^ v2).to_ulong();
}
