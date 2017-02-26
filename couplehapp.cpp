#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include "couple.h"

/** 
 * Function to calculate happiness of couple
*/
void couple::calc_happiness()
{
	happ = ga.happ+ba.happ;
}

/** 
 * Function to calculate compatibility of couple
*/
void couple::calc_comp()
{
	comp = (ba.bud - ga.maint) + abs(ga.intel-ba.intel) + abs(ga.attr - ba.attr);
}
