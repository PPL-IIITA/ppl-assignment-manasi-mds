#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "couple.h"

#ifndef Q2PART1_H
#define Q2PART1_H

/*! \brief NEC CLASS		 
		 * To asign gifts to couples and print k happiest and compatible couples 
		 */

class nec{
	public:
	void fun1(gift g[],couple c[]);//!<Function to read value of gifts and couples
	void fun2(gift g[],couple c[],int m, int n);//!<Function to assign gifts to couples
	void fun3(gift g[],couple c[],int m, int n);//!<Function to print k most compatible and happy couples

};

#endif
