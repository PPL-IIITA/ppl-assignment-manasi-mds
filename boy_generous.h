#include<iostream>
#include<string>
#include<cmath>
#include "boy.h"
#ifndef BOY_GENEROUS_H
#define BOY_GENEROUS_H
using namespace std;


class generous:public boy{
	void calc_happiness(int total,girl g);
};

#endif	
