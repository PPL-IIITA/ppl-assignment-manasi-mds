#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include "couple.h"

void fun1(gift g[],couple c[]);
void fun2(gift g[],couple c[],int m, int n);
void fun3(gift g[],couple c[],int m, int n);
/**@detail
 * Function to read couples and gifts
*/
void fun1(gift g[],couple c[])
{
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


/**@detail
 * Function to assign gifts to couples
*/

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


}

/**@detail
 * Function to print k happiest and k most compatible couples
*/
void fun3(gift g[],couple c[],int m, int n)
{
	int tval = 0,tcost = 0;
	int i,j;
	gift cpg[m][n];
	for(i=0;i<m;i++) {
		for(j=0;j<=c[i].gif[j].price;j++) {
			cpg[i][j] = c[i].gif[j];
		}
	}

	


	for(i=0;i<m;i++) {
		tval = 0;
		tcost = 0;
		for(j=1;j<=cpg[i][0].price;j++) {
			tcost += cpg[i][j].price;
			tval += cpg[i][j].value;
		}

		c[i].ga.calc_happiness(tcost,tval);
		c[i].ba.calc_happiness(tcost,c[i].ga);
		c[i].calc_happiness();
		c[i].calc_comp();
                

	}
	
	int kno,max_happ=0,happ_lim=999999,maxi=0;
	cout<<"\nEnter the value of k: ";
	cin>>kno;

	

	freopen("gifttransfer.txt", "w", stdout);
	time_t now;
	char *ct;
	for(i=0;i<m;i++) {
		printf("Girl: %s Boy: %s \n",c[i].ga.name,c[i].ba.name);
		for(j=1;j<=cpg[i][0].price;j++) {
			switch(cpg[i][j].type_gift) {
				case 0 :	now = time(0);
						ct = ctime(&now);
						cout<<"Time: "<<ct<<"\t";
						printf("      Essential gift Price:%d Value:%d\n",cpg[i][j].price,cpg[i][j].value);
						break;

				case 1 :	now = time(0);
						ct = ctime(&now);
						cout<<"Time: "<<ct<<"\t";
						printf("      Luxury gift Price:%d Value:%d\n",cpg[i][j].price,cpg[i][j].value);
						break;

				case 2 :	now = time(0);
						ct = ctime(&now);
						cout<<"Time: "<<ct<<"\t";
						printf("      Utility gift Price:%d Value:%d\n",cpg[i][j].price,cpg[i][j].value);
                                                break;
			}
		}
		printf("\n\n");
	}

	cout<<"\n\nThe list of kth happiest couples \n";
	for(i=0;i<kno;i++) {
		max_happ = 0;
		maxi = 0;
		for(j=0;j<m;j++) {
			if(c[j].happ>maxi && c[j].happ<happ_lim) {
				max_happ = j;
				maxi = c[j].happ;
			}
		}
	
		cout<<c[max_happ].ba.name<<" "<<c[max_happ].ga.name<<" "<<c[max_happ].happ<<"\n";
		happ_lim = c[max_happ].happ;
	}

	cout<<"\n\nThe list of kth most compatible couples \n";
	happ_lim = 999999;
        for(i=0;i<kno;i++) {
                max_happ = 0;
		maxi =0;
                for(j=0;j<m;j++) {
                        if(c[j].comp>maxi && c[j].comp<happ_lim) {
                                max_happ = j;
				maxi = c[j].comp;
                        }
                }

                cout<<c[max_happ].ba.name<<" "<<c[max_happ].ga.name<<" "<<c[max_happ].comp<<"\n";
                happ_lim = c[max_happ].comp;
        }
	

}

