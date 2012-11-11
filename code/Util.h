#pragma once

#include "Types.h"
#include <time.h>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <bitset>
#include <iostream>
#include <exception>
#include <time.h>

int getHammingDistance(gType v1, gType v2);

gType getRandomChild(gType p1, gType p2);

gType crossOver(gType p1, gType p2);

gType mutate(gType c1);

int getRandomInt(int l, int h);

double getDelta(double, double);
