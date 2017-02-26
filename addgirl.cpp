#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;
/** @detail
 *  Program to randomly generate girls
*/
int main()
{
	freopen("girldetails.txt", "w", stdout);
	srand(time(NULL));	
	char name[30][10];
	int i,j;
	for(i=0;i<30;i++) {
		for(j=0;j<9;j++) {
			name[i][j] = (rand()%26)+65;
		}
		name[i][9] = '\0';
	}

	int attr[30];
	int intel[30];
	int crit[30];
	int maint[30];
	int single[30] = {0};
	int status[30];

	for(i=0;i<30;i++) {
		attr[i] = rand()%20;
		intel[i] = rand()%20;
		crit[i] = rand()%3;
		maint[i] = (rand()%2000) +3000;
		status[i] = rand()%3;
	}
	printf("%d\n",30);
	for(i=0;i<30;i++) {
		printf("%s %d %d %d %d %d %d\n",name[i],attr[i],intel[i],crit[i],maint[i],single[i],status[i]);
	}
	return 0;
}
	
