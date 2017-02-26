#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "q2part1.h"
/**@detail
 * Program to assign gifts to couples and print the k happiest and k most compatible couples
*/
using namespace std;
int main() 
{
	FILE *fc,*fg,*fcpl;
	
	fg = fopen("giftdetails.txt","r");
	fc = fopen("coupledetailsq2.txt","r");
	int i,n,m,j;
	nec mm;	
	fscanf(fg,"%d",&n);
	gift g[n];
	fscanf(fc,"%d",&m);
	couple c[m];
	gift cpg[m][n];
	gift couple_gift[m][n];

	mm.fun1(g,c);
	mm.fun2(g,c,m,n);						
        mm.fun3(g,c,m,n);
			
return 0;


}

