#include<iostream>
#include "girl.h"
#include "boy.h"
#include "girl_desperate.h"

/**@detail
 * Function to calculate happiness of desperate girl
*/

void desperate::calc_happiness(int cost, int value)
{
	happ = exp((int)((cost-maint)%10));
}
