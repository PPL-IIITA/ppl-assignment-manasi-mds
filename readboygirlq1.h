#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include "couple.h"
#ifndef READBOYGIRLQ1_H
#define READBOYGIRLQ1_H
using namespace std;
/*! \brief
*CLASS PAIRING
*To Pair boys and girls as couples
*/
class pairing {

	public:
	void readboygirl(girl g[], boy b[]);//!<Function to read data of girls and boys from file
	void pair(girl g[],boy b[],int m,int n); //!<Function to pair girls and boys together


};
#endif
