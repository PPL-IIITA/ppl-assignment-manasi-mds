#include<string>
#include<iostream>
#include<cmath>
#include "girl.h"
#ifndef GIRL_NORMAL_H
#define GIRL_NORMAL_H

using namespace std;

class normal:public girl{
	void calc_happiness(int cost,int value);
};
#endif
