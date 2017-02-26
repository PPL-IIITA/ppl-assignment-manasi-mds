#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>

using namespace std;
/** @detail
 *  Program to randomly generate boys
*/
int main()
{
        freopen("boydetails.txt", "w", stdout);
        srand(time(NULL));
        char name[40][10];
        int i,j;
        for(i=0;i<40;i++) {
                for(j=0;j<9;j++) { 
                        name[i][j] = (rand()%26)+65;
                }
                name[i][9] = '\0';
        }

        int attr[40];
        int intel[40];
        int bud[40];
        int min_attr[40]; 
        int single[40] = {0};
        int status[40];

        for(i=0;i<40;i++) {
                attr[i] = rand()%20;
                intel[i] = rand()%20;
                min_attr[i] = rand()%10;
                bud[i] = (rand()%2000) +4000;
                status[i] = rand()%3;
        }
	printf("%d\n",40);
        for(i=0;i<40;i++) {
                printf("%s %d %d %d %d %d %d\n",name[i],attr[i],intel[i],bud[i],min_attr[i],single[i],status[i]);
        }
        return 0;
}


