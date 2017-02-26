#include<iostream>
#include<stdio.h>
#include "readboygirlq1.h"
using namespace std;

/**@detail
 * Program to pair boys and girls together to form couples
*/
int main()
{
	pairing p;
	FILE *fg,*fb;
	fg = fopen("girldetails.txt","r");
	fb = fopen("boydetails.txt","r");
	int i,j,m,n,k,l;
	fscanf(fg,"%d",&n);
	girl g[n];
	fscanf(fb,"%d",&m);
	boy b[m];
	p.readboygirl(g,b);	
	p.pair(g,b,m,n);
	return 0;
}

