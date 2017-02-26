#include<iostream>
//#include "q2_1.h"
#include "couple.h"
#include<stdio.h>
using namespace std;

/**@detail
 * Program to pair boys and girls together to form couples
*/
int main()
{
	FILE *fg,*fb;
	fg = fopen("girldetails.txt","r");
	fb = fopen("boydetails.txt","r");
	int i,j,m,n,k,l;
	fscanf(fg,"%d",&n);
	girl g[n];
	for(i=0;i<n;i++) {
                fscanf(fg,"%s %d %d %d %d %d %d",g[i].name,&g[i].attr,&g[i].intel,&g[i].crit,&g[i].maint,&g[i].single,&g[i].status);
	}
	fscanf(fb,"%d",&m);
	boy b[m];
	for(i=0;i<m;i++) {
		fscanf(fb,"%s %d %d %d %d %d %d",b[i].name,&b[i].attr,&b[i].intel,&b[i].bud,&b[i].min_attr,&b[i].single,&b[i].status);
	}
//	for(i=0;i<m;i++) {
  //              cout<<b[i].name<<"\n";
    //    }

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
				//cout<<"IN 1 with max = "<<b[max].name<<" For i = "<<i<<" and max limit "<<maxlimit<<"\n";			
				maxlimit = b[max].attr;
			}	
			else if(g[i].crit == 1)	{
					for(k=0;k<m;k++) {
						if((b[max].bud<b[k].bud)&&(b[k].bud<maxlimit)) {
							max = k;
						}
					}
					
				
				//cout<<"IN 2 with max = "<<b[max].name<<" For i = "<<i<<" and max limit "<<maxlimit<<"\n";
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
	freopen("coupledetailsq2.txt", "w", stdout);		
	printf("%d\n",l);
	
	for(i=0;i<l;i++) {
		printf("%s %d %d %d %d %d %d %s %d %d %d %d %d %d\n",c[i].ga.name,c[i].ga.attr,c[i].ga.intel,c[i].ga.crit,c[i].ga.maint,c[i].ga.single,c[i].ga.status,c[i].ba.name,c[i].ba.attr,c[i].ba.intel,c[i].ba.bud,c[i].ba.min_attr,c[i].ba.single,c[i].ba.status);	 
//	printf("%s %d %d %d %d",c[i].ga.name,c[i].ga.attr,c[i].ga.intel,c[i].ga.crit,c[i].ga.maint,c[i].ga.single,c[i].ga);
	
	}
	//fclose(stdout);
	return 0;
}

