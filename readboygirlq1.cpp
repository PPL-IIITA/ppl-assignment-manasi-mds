#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

#include "readboygirlq1.h"

/** @detail
 * Function to read the values of boy and girl
*/

void pairing::readboygirl(girl g[], boy b[])
{
	FILE *fg,*fb;
	fg = fopen("girldetails.txt","r");
	fb = fopen("boydetails.txt","r");
	int i,j,m,n,k,l;
	fscanf(fg,"%d",&n);
	//girl g[n];
	for(i=0;i<n;i++) {
		fscanf(fg,"%s %d %d %d %d %d %d",g[i].name,&g[i].attr,&g[i].intel,&g[i].crit,&g[i].maint,&g[i].single,&g[i].status);
	}
	fscanf(fb,"%d",&m);
	//boy b[m];
	for(i=0;i<m;i++) {
		fscanf(fb,"%s %d %d %d %d %d %d",b[i].name,&b[i].attr,&b[i].intel,&b[i].bud,&b[i].min_attr,&b[i].single,&b[i].status);
	}


}

/** @detail
 * Function to pair boys and girls
*/
void pairing::pair(girl g[],boy b[],int m,int n) 
{
	int i,j,k,l;
	int max,maxlimit;
	couple c[m];
	l=0;
	for(i=0;i<n;i++) {
		maxlimit = 6001;
		for(j=0;j<m;j++) {
			max = 0;
			if(g[i].crit == 0) {
				for(k=0;k<m;k++) {
					if((b[max].attr<b[k].attr)&&b[k].attr<maxlimit) {
						max = k;
					}
				}
				maxlimit = b[max].attr;
			}
			else if(g[i].crit == 1) {
				for(k=0;k<m;k++) {
					if((b[max].bud<b[k].bud)&&(b[k].bud<maxlimit)) {
						max = k;
					}
				}

				maxlimit = b[max].bud;

			}

			else if(g[i].crit == 2) {


				for(k=0;k<m;k++) {
					if((b[max].intel<b[k].intel)&&(b[k].intel<maxlimit)) {
						max = k;
					}
				}


				//cout<<"IN 3 with max = "<<b[max].name<<" For i = "<<i<<" and max limit "<<maxlimit<<"\n";
				maxlimit = b[max].intel;

			}

			if((b[max].bud>=g[i].maint)&&(g[i].attr>=b[max].min_attr)&&(b[max].single==0)) {
				//cout<<"Pairing "<<g[i].name<<" with "<<b[max].name<<"\n";
				c[l].ga = g[i];
				c[l].ba = b[max];
				l++;
				g[i].single = 1;
				b[max].single = 1;
				maxlimit = 6001;
				break;
			}
		}
	}
	for(i=0;i<l;i++) {
                printf("Name of girl: %s Name of boy: %s\n",c[i].ga.name,c[i].ba.name);
}

	freopen("coupledetails.txt", "w", stdout);
	printf("%d\n",l);

	for(i=0;i<l;i++) {
		printf("Name of girl: %s Name of boy: %s\n",c[i].ga.name,c[i].ba.name);
	}
}

