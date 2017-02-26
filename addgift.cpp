#include<iostream>
#include<stdio.h>
#include "gift.h"
#include<stdlib.h>
using namespace std;
/** @detail
 *  Program to randomly generate gifts
*/
int main() {
	freopen("giftdetails.txt", "w", stdout);
	srand(time(NULL));
	int type[50];
	int used[50];
	int price[50];
	int value[50];
	int lux_rating[50];
	int lux_diff[50];
	int util_value[50];
	int util_class[50];
	int i;
	for(i=0;i<50;i++) {
		type[i] = rand()%3;
		used[i] = 0; 
		if(type[i] == 0) {
			price[i] = rand()%900 + 100;
			value[i] = rand()%50;
			lux_rating[i] = -1;
			lux_diff[i] = -1;
			util_value[i] = -1;
			util_class[i] = -1;
		}

		else if(type[i] == 1) {
			price[i] = rand()%1000 + 2000;
			value[i] = rand()%50;
			lux_rating[i] = rand()%10;
			lux_diff[i] = rand()%10;
			util_value[i] = -1;
                        util_class[i] = -1;
		}

		else if(type[i] == 2) {
                        price[i] = rand()%1000 + 100;
                        value[i] = rand()%50;
                        lux_rating[i] = -1;
                        lux_diff[i] = -1;
                        util_value[i] = rand()%10;
                        util_class[i] = rand()%10;
		}
	}

	printf("%d\n",50);
        for(i=0;i<50;i++) {
                printf("%d %d %d %d %d %d %d %d\n",type[i],used[i],price[i],value[i],lux_rating[i],lux_diff[i],util_value[i],util_class[i]);
        }
	return 0;
}


		
