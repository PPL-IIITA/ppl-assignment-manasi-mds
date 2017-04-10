#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "couple.h"
/**@detail
 * Program to assign gifts to couples and print the k happiest and k most compatible couples
*/

void fun1(gift g[],couple c[]);
void fun2(gift g[],couple c[],int m, int n);
void fun3(gift g[],couple c[],int m, int n);
using namespace std;
int main() 
{
	FILE *fc,*fg,*fcpl;
	
	fg = fopen("giftdetails.txt","r");
	fc = fopen("coupledetailsq2.txt","r");
	int i,n,m,j;
		
	fscanf(fg,"%d",&n);
	gift g[n];
	fscanf(fc,"%d",&m);
	couple c[m];
	gift cpg[m][n];
	gift couple_gift[m][n];

	fun1(g,c);
	fun2(g,c,m,n);						
        fun3(g,c,m,n);
			
return 0;


}
