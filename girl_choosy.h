#include<string>
#include<iostream>
#include<cmath>
#include "girl.h"
#ifndef GIRL_CHOOSY_H
#define GIRL_CHOOSY_H

using namespace std;

class choosy:public girl{
	void calc_happiness(int cost,int value);
};
#endif
