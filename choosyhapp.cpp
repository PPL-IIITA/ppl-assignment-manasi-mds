#include<iostream>
#include "girl.h"
#include "boy.h"
#include "girl_choosy.h"

/**@detail
 * Function to calculate happiness of choosy girl
*/

void choosy::calc_happiness(int cost, int value)
{	
	happ = log(1+((int)((cost-maint)%10)));
}
