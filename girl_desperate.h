#include<string>
#include<iostream>
#include<cmath>
#include "girl.h"
#ifndef GIRL_DESPARATE_H
#define GIRL_DESPERATE_H

using namespace std;


class desperate:public girl{
	void calc_happiness(int cost,int value);
};
#endif
