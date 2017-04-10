#include<iostream>
#include "girl.h"
#include "boy.h"
#include "girl_normal.h"

/**@detail
 * Function to calculate happiness of normal girl
*/

void normal::calc_happiness(int cost, int value){
       happ = cost+value-maint;
}

