#include<iostream>
#include<string>
#include<cmath>

#ifndef BOY_H
#define BOY_H
using namespace std;
/*! \brief BOY CLASS
		 *	Contains attributes of boys
		 *  Attributes like: Name,Intelligence Level,Status(Preference),Attractiveness,budget,Minimum Attraction for girl, Happiness, Relationship status(single/committed)
		 */
class boy	
{
	public:
		char name[20]; //!<Name of boy
		int intel; //!<Intelligence of boy out of 20
		int status;//!<Type of boy (0)Miser (1)Generous (2)Geeky
		int attr;//!<Attractiveness of boy out of 20
		int bud;//!<Budget of boy range 4000 - 6000
		int min_attr;//!<Minimum attractiveness requirement in girl
		int happ;//!<Happiness of boy
		int single;//!<Relationship status of boy (0-single)
		void calc_happiness(int total,girl g);//!<Function to calculate happiness
		
};

#endif



