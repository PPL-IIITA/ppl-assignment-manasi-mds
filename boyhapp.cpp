#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "girl.h"
#include "boy.h"

/** @detail
 * Function to calculate happiness of boy
*/

void boy::calc_happiness(int total, girl g) {

	switch(status) {

		case 0 :	happ = bud - total;
				break;

		case 1 :	happ = g.happ;
				break;

		case 2 :	happ = g.intel;
				break;
	}
}
