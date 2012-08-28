#include "Types.h"
#include <time.h>
#include <vector>


unsigned long getHammingDistance(gType v1, gType v2);

gType getRandomChild(gType p1, gType p2);

gType crossOver(gType p1, gType p2);

gType mutate(gType c1);

int getRandomInt(int l, int h);
