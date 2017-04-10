#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "couple.h"


void fun1(gift g[],couple c[]);
void fun2(gift g[],couple c[],int m, int n);

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
			
return 0;


}


void fun1(gift g[],couple c[]){
	FILE *fc,*fg;
	fg = fopen("giftdetails.txt","r");
	fc = fopen("coupledetailsq2.txt","r");
	int i,n,m,j;
	fscanf(fg,"%d",&n);
	fscanf(fc,"%d",&m);


	for(i=0;i<n;i++) {
		fscanf(fg,"%d %d %d %d %d %d %d %d",&g[i].type_gift,&g[i].used,&g[i].price,&g[i].value,&g[i].lux_rating,&g[i].lux_diff,&g[i].util_value,&g[i].util_class);

	}

	for(i=0;i<m;i++) {
		fscanf(fc,"%s %d %d %d %d %d %d %s %d %d %d %d %d %d",c[i].ga.name,&c[i].ga.attr,&c[i].ga.intel,&c[i].ga.crit,&c[i].ga.maint,&c[i].ga.single,&c[i].ga.status,c[i].ba.name,&c[i].ba.attr,&c[i].ba.intel,&c[i].ba.bud,&c[i].ba.min_attr,&c[i].ba.single,&c[i].ba.status);
	}

}


void fun2(gift g[],couple c[],int m, int n)
{
	gift cpg[m][n];
	int l =1;
	int i,j;
	int expend;
	int gift_price;
	int max,k;

	for(i=0;i<m;i++) {	
		cpg[i][0] = g[i];
		cpg[i][0].price = 0;
		l = 1;
		switch(c[i].ba.status) {
		
	
			case 0 :	expend = c[i].ga.maint + (c[i].ba.bud-c[i].ga.maint)/4;
					gift_price = 0;
					max = 0;
					for(k=0;k<n;k++) {
						max = 0;
						for(j=0;j<n;j++) {
							if((g[j].price<g[max].price)&&g[j].used == 0) {
								max = j;
							}
						
						}
						if((g[max].price + gift_price <= expend) || gift_price<c[i].ga.maint) {
							gift_price += g[max].price;					
							g[max].used = 1;			
							
							cpg[i][l] = g[max];
							cpg[i][0].price +=1;
							if(gift_price>c[i].ba.bud) {
								c[i].ba.bud = gift_price;
							}
							l++;
						
						}
					}
					break;

			case 1 :	expend = c[i].ba.bud;
					gift_price = 0;
					max = 0;
					for(k=0;k<n;k++) {
						max=0;
						for(j=0;j<n;j++) {
							if((g[j].price>g[max].price)&&g[j].used==0) {
								max = j;
							}
						}
						if(g[max].price + gift_price <= expend || gift_price<c[i].ga.maint) {
							gift_price+=g[max].price;
							g[max].used = 1;
							
							cpg[i][l] = g[max];
                                                        cpg[i][0].price +=1;
                                                        l++;

						}
					}
					break;

			case 2 :	expend = c[i].ga.maint + (c[i].ba.bud-c[i].ga.maint)/8;
                                        gift_price = 0;
                                        max = 0;
                                        for(k=0;k<n;k++) {
						max = 0;
                                                for(j=0;j<n;j++) {
							 if((g[j].price<g[max].price)&&g[j].used == 0) {
                                                                max = j;
                                                        }
                                                }
						if(g[max].price + gift_price <= expend || gift_price<c[i].ga.maint) {
                                                        
							gift_price += g[max].price;
                                                        g[max].used = 1;
                                                        
							cpg[i][l] = g[max];
                                                        cpg[i][0].price +=1;
                                                        l++;

                                                }
					}

					for(j=0;j<n;j++) {
						if((g[j].lux_rating!=-1)&&(c[i].ba.bud-gift_price>=g[j].price)) {
							gift_price += g[max].price;
                                                        g[max].used = 1;
                                                        cpg[i][l] = g[max];
                                                        cpg[i][0].price +=1;
                                                        l++;

                                        		break;
					        }
					}							
					break;
			}
			for(j=0;j<n;j++)
				g[j].used = 0;

	}


	for(i=0;i<m;i++) {
		for(j=0;j<=cpg[i][0].price;j++) {
			c[i].gif[j] = cpg[i][j];
		}
	}
	
	freopen("gifttransferq3.txt", "w", stdout);
	for(i=0;i<m;i++) {
		printf("%d\n",cpg[i][0].price);
		for(j=1;j<=cpg[i][0].price;j++) {
			printf("%d %d %d %d %d %d %d %d\n",cpg[i][j].type_gift,cpg[i][j].used,cpg[i][j].price,cpg[i][j].value,cpg[i][j].lux_rating,cpg[i][j].lux_diff,cpg[i][j].util_value,cpg[i][j].util_class);
		}
	}





}
