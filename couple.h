#include<iostream>
#include "girl.h"
#include "boy.h"
#include "girl_desperate.h"
#include "girl_normal.h"
#include "girl_choosy.h"
#include"boy_miser.h"
#include"boy_geeky.h"
#include"boy_generous.h"
#include "gift.h"
#include "gift_essential.h"
#include "gift_luxury.h"
#include "gift_utility.h"
#include<stdio.h>
#include<stdlib.h>


using namespace std;

	/*! \brief
	*CLASS COUPLE
	*Contains all attributes and functions of couple
	*/

class couple{
	public:
		int happ; //!<Total happiness of couple
		int comp;//!<Total compatibility of couple
		girl ga;//!<Object of girl in the relationship
		boy ba;//!<Object of boy in the relationship
		gift gif[100];//!<Array of gift objects (To hold all the gift transfers between a couple)
		
		void calc_happiness();//!<Function to calculate happiness of couple
		
		void calc_comp();//!<Function to calculate compatibility of couple
		
};




