#include "couple.h"
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

void readfile(gift **g,couple c[])
{
	FILE *fc,*fg;
	fg = fopen("gifttransferq3.txt","r");
	fc = fopen("coupledetailsq2.txt","r");
	int i,n,m,j;
	fscanf(fc,"%d",&m);
	int t;

	for(i=0;i<m;i++)
		g[i] = (gift *)malloc(100*sizeof(gift));

	for(i=0;i<m;i++) {
		fscanf(fg,"%d",&t);
		g[i][0].price = t;
		for(j=1;j<=g[i][0].price;j++) {
			fscanf(fg,"%d %d %d %d %d %d %d %d",&g[i][j].type_gift,&g[i][j].used,&g[i][j].price,&g[i][j].value,&g[i][j].lux_rating,&g[i][j].lux_diff,&g[i][j].util_value,&g[i][j].util_class);

		}
	}

	for(i=0;i<m;i++) {
		fscanf(fc,"%s %d %d %d %d %d %d %s %d %d %d %d %d %d",c[i].ga.name,&c[i].ga.attr,&c[i].ga.intel,&c[i].ga.crit,&c[i].ga.maint,&c[i].ga.single,&c[i].ga.status,c[i].ba.name,&c[i].ba.attr,&c[i].ba.intel,&c[i].ba.bud,&c[i].ba.min_attr,&c[i].ba.single,&c[i].ba.status);
	}

}



int breakup(gift **g, couple c[], couple br[],int m)
{
	int min_happ,mini,j,i,happ_lim,k;
	printf("\nEnter the value of k: ");
	scanf("%d",&k);
	int tval,tcost;
	int brindex;

	for(i=0;i<m;i++) {
		tval = 0;
		tcost = 0;
		for(j=1;j<=g[i][0].price;j++) {
			tcost += g[i][j].price;
			tval += g[i][j].value;
		}

		c[i].ga.calc_happiness(tcost,tval);
		c[i].ba.calc_happiness(tcost,c[i].ga);
		c[i].calc_happiness();
		c[i].calc_comp();
	}

	/*printf("\nHappiness of couples: \n");
		  for(i=0;i<m;i++) {
		  printf("%s %s %d\n",c[i].ga.name,c[i].ba.name,c[i].happ);
	  }*/

	int count=0;
	happ_lim = -1;

	for(i=0;i<k;i++) {

		min_happ = -1;
		mini = 9999999;

		for(j=0;j<m;j++) {
			if(c[j].happ<mini && c[j].happ>happ_lim) {

				min_happ = j;
				mini = c[j].happ;
			}
		}


		if(min_happ == -1)
			break;

		br[count] = c[min_happ];

		//strcpy(c[mini].ba.name,"NULL");
		count++;
		happ_lim = mini;
	}
	printf("\nThe following couples broke up\n");
	for(i=0;i<k;i++) {
		printf("%s %s\n",br[i].ga.name,br[i].ba.name);
	}
	return k;
}	


void re_pair(gift **g, couple c[], couple br[],int m,int brindex) 
{
	int nb,i,j,maxlimit,k,io,jo,max;
	
	FILE *fb;
	fb = fopen("boydetails.txt","r");
	fscanf(fb,"%d",&nb);
	boy b[nb];
	for(i=0;i<nb;i++) {
		fscanf(fb,"%s %d %d %d %d %d %d",b[i].name,&b[i].attr,&b[i].intel,&b[i].bud,&b[i].min_attr,&b[i].single,&b[i].status);
	}
	
	
	for(io=0;io<m;io++) {
		
		for(jo=0;jo<brindex;jo++) {
			if(strcmp(c[io].ba.name,br[jo].ba.name)==0) {
					max = 0;
					if(c[io].ga.crit == 0) {
						for(k=0;k<nb;k++) {
							if((b[max].attr<b[k].attr)&& b[k].attr<maxlimit &&(strcmp(c[io].ba.name,b[k].name)!=0)) {
								max = k;
							}
							
						}
						maxlimit = b[max].attr;
					}
					else if(c[io].ga.crit == 1) {
						for(k=0;k<nb;k++) {
							if((b[max].bud<b[k].bud)&&(b[k].bud<maxlimit)&&(strcmp(c[io].ba.name,b[k].name)!=0)) {
								max = k;
							}
						}
						
						maxlimit = b[max].bud;

					}

					else if(c[io].ga.crit == 2) {


						for(k=0;k<nb;k++) {
							if((b[max].intel<b[k].intel)&&(b[k].intel<maxlimit)&&(strcmp(c[io].ba.name,b[k].name)!=0)) {
								max = k;
							}
						
						}

						
						//cout<<"IN 3 with max = "<<b[max].name<<" For i = "<<i<<" and max limit "<<maxlimit<<"\n";
						maxlimit = b[max].intel;

					}

					if((b[max].bud>=c[io].ga.maint)&&(c[io].ga.attr>=b[max].min_attr)&&(b[max].single==0)&&(strcmp(c[io].ba.name,b[max].name)!=0)) {
							//cout<<"Pairing "<<g[i].name<<" with "<<b[max].name<<"\n";
						c[io].ba = b[max];
						b[max].single = 1;
						maxlimit = 6001;
						break;
					}
				
			}

		}

	}
	printf("\n\nAfter pairing\n");
	for(i=0;i<m;i++) {
		  printf("%s %s\n",c[i].ga.name,c[i].ba.name);
	}
}



