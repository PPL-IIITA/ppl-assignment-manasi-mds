#ifndef GIFT_LUXURY_H
#define GIFT_LUXURY_H
#include "gift.h"
using namespace std;
/*! \brief GIFT CLASS		 
		 *  Contains all attributes and functions of luxury gifts
		 */


class luxury:public gift{
	int luxrating;//!<Luxury rating (Only for luxury gifts)
	int luxdiff;//!<Difficulty to find (Only for luxury gifts)
};
#endif
