#ifndef COUPLE_H
#define COUPLE_H

using namespace std;
/*! \brief GIFT CLASS		 
		 *  Contains all attributes and functions of gifts
		 */

class gift {
	public:
		int type_gift;//!<Type of gift (0)Essential (1)Luxury (2)Utility 
		int used;//!<To denote if the gift has been gifted or not 1-Used
		int price;//!<Price of the gift
		int value;//!<Value of the fift
		int lux_rating;//!<Luxury rating (Only for luxury gifts)
		int lux_diff;//!<Difficulty to find (Only for luxury gifts)
		int util_value;//!<Utility value (Only for utility gifts)
		int util_class;//!<Utility class (Only for utility gifts)
};


#endif
