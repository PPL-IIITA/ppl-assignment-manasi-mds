#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "couple.h"
using namespace std;

void readfile(gift **g,couple c[]);
int breakup(gift **g, couple c[], couple br[],int m);
void re_pair(gift **g,couple c[],couple br[],int m,int brindex);

int main() 
{
	FILE *fc;
	gift **g;
	int m;

	fc = fopen("coupledetailsq2.txt","r");
	fscanf(fc,"%d",&m);

	g = (gift **)malloc(m*sizeof(gift *));
	couple c[m],br[m];
	int j;	
	readfile(g,c);

	int brindex = breakup(g,c,br,m);
	re_pair(g,c,br,m,brindex);	
	return 0;
}







