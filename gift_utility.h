#ifndef GIFT_UTILITY_H
#define GIFT_UTILITY_H
#include "gift.h"
using namespace std;
/*! \brief GIFT CLASS		 
		 *  Contains all attributes and functions of utility gifts
		 */


class utility:public gift{
	int utilvalue;//!<Utility value (Only for utility gifts)
	int utilclass;//!<Utility class (Only for utility gifts)
};
#endif
