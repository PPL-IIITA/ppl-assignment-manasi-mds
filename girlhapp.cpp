#include<iostream>
#include "girl.h"
#include "boy.h"

/**@detail
 * Function to calculate happiness of girl
*/

void girl::calc_happiness(int cost, int value)
{
	int t;
	switch(status) {

		case 0 :        happ = log(1+((int)((cost-maint)%10)));

				break;

		case 1 :        happ = cost+value-maint;
				break;

		case 2 :        happ = exp((int)((cost-maint)%10));
	}
}

