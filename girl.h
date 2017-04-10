#include<string>
#include<iostream>
#include<cmath>

#ifndef GIRL_H
#define GIRL_H


using namespace std;

/*! \brief GIRL CLASS
		 *	Contains attributes of girls
		 *  Attributes like: Name,Intelligence,Attractiveness,maintenance budget,criteria to choose boy, Happiness, Type of girl, Relationship status(single/committed)
		 */


class girl {
	public:
		char name[20]; //!<Name of girl
		int attr; //!<Attractiveness of girl out of 20
		int maint;//!<Maintenance cost of girl (Range 3000-5000)
		int intel;//!<Intelligence of girl out of 20
		int crit;//!<Criteria of girl to choose a boy (0)Most attractive (1)Most Rich (2)Most Intelligent
		int status;//!<Type of girl (0)Choosy (1)Normal (2)Desperate
		int happ;//!<Happiness of girl 
		int single;//!<Relationship status of girl (0 if single)
		void calc_happiness(int cost, int value);//!<happiness of girl calculator
		
};
#endif
		
