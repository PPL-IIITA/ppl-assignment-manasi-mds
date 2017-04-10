#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "couple.h"
/**@detail
 * Program to assign gifts to couples and print the k happiest and k most compatible couples
*/
void fun2(gift *g[],couple [],int, int ,int);
void fun1(gift *g[],couple [],int []);
using namespace std;
int main() 
{
	FILE *fc,*fg,*fcpl;
	
	fg = fopen("giftdetails.txt","r");
	fc = fopen("coupledetailsq2.txt","r");
	int i,n,m,j;
		
	fscanf(fg,"%d",&n);
	gift *g[n];
	int glist[n];
	fscanf(fc,"%d",&m);
	
	couple c[m]; //m
	gift **cpg; //m,n
	gift **couple_gift; //m,n

	fun1(g,c,glist);
	fun2(g,c,m,n,glist);						
        //fun3(g,c,m,n);
			
return 0;

}

void fun1(gift *g[],couple c[],int glist[])
{
	FILE *fc,*fg;
	fg = fopen("giftdetails.txt","r");
	fc = fopen("coupledetailsq2.txt","r");
	int i,n,m,j;
	fscanf(fg,"%d",&n);
	fscanf(fc,"%d",&m);
	int gtemp;


	for(i=0;i<n;i++) {
		fscanf(fg,"%d", &gtemp);
		if(gtemp == 0) {
			g[i] = new essential();
			fscanf(fg,"%d %d %d ",&g[i]->used,&g[i]->price,&g[i]->value);
			glist[i] = 0;
		}
		if(gtemp == 1) {
			g[i] = new luxury();
			fscanf(fg,"%d %d %d %d %d",&g[i]->used,&g[i]->price,&g[i]->value,&g[i]->lux_rating, &gtemp.lux_diff);
			glist[i] = 1;		
		}
		if(gtemp == 2) {
			g[i] = new utility();
			fscanf(fg,"%d %d %d %d %d",&g[i]->used,&g[i]->price,&g[i]->value,&g[i]->util_value,&g[i]->util_class);
			glist[i] = 2;		
		}

	}

	for(i=0;i<m;i++) {
		fscanf(fc,"%s %d %d %d %d %d %d %s %d %d %d %d %d %d",c[i].ga.name,&c[i].ga.attr,&c[i].ga.intel,&c[i].ga.crit,&c[i].ga.maint,&c[i].ga.single,&c[i].ga.status,c[i].ba.name,&c[i].ba.attr,&c[i].ba.intel,&c[i].ba.bud,&c[i].ba.min_attr,&c[i].ba.single,&c[i].ba.status);
	}

}


void fun2(gift *g[],couple c[],int m, int n,int glist[])
{
	gift *cpg[m][n];
	int l =1;
	int i,j;
	int expend;
	int gift_price;
	int max,k;

	for(i=0;i<m;i++) {
		cpg[i][0] = new gift();	
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
							
							if(g[max].type_gift == 0) {
								cpg[i][l] = new essential();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
							}
							else if(g[max].type_gift == 1){
								cpg[i][l] = new luxury();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
								cpg[i][l].lux_rating = g[max].lux_rating;
								cpg[i][l].lux_diff = g[max].lux_diff;
							}
							else if(g[max].type_gift == 2) {
								cpg[i][l] = new utility();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
								cpg[i][l].util_value = g[max].util_value;
								cpg[i][l].util_clas = g[max].util_class;
							}
							
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
							
							if(g[max].type_gift == 0) {
								cpg[i][l] = new essential();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
							}
							else if(g[max].type_gift == 1){
								cpg[i][l] = new luxury();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
								cpg[i][l].lux_rating = g[max].lux_rating;
								cpg[i][l].lux_diff = g[max].lux_diff;
							}
							else if(g[max].type_gift == 2) {
								cpg[i][l] = new utility();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
								cpg[i][l].util_value = g[max].util_value;
								cpg[i][l].util_clas = g[max].util_class;
							}
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
                                                        
							if(g[max].type_gift == 0) {
								cpg[i][l] = new essential();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
							}
							else if(g[max].type_gift == 1){
								cpg[i][l] = new luxury();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
								cpg[i][l].lux_rating = g[max].lux_rating;
								cpg[i][l].lux_diff = g[max].lux_diff;
							}
							else if(g[max].type_gift == 2) {
								cpg[i][l] = new utility();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
								cpg[i][l].util_value = g[max].util_value;
								cpg[i][l].util_clas = g[max].util_class;
							}
                                                        cpg[i][0].price +=1;
                                                        l++;

                                                }
					}

					for(j=0;j<n;j++) {
						if((g[j].lux_rating!=-1)&&(c[i].ba.bud-gift_price>=g[j].price)) {
							gift_price += g[max].price;
                                                        g[max].used = 1;
                                                        if(g[max].type_gift == 0) {
								cpg[i][l] = new essential();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
							}
							else if(g[max].type_gift == 1){
								cpg[i][l] = new luxury();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
								cpg[i][l].lux_rating = g[max].lux_rating;
								cpg[i][l].lux_diff = g[max].lux_diff;
							}
							else if(g[max].type_gift == 2) {
								cpg[i][l] = new utility();
								cpg[i][l].type_gift = g[max].type_gift;
								cpg[i][l].used = g[max].used;
								cpg[i][l].price = g[max].price;
								cpg[i][l].value = g[max].value;
								cpg[i][l].util_value = g[max].util_value;
								cpg[i][l].util_clas = g[max].util_class;
							}
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


}

