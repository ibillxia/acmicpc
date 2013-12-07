//file: 1009.c
//author: ibillxia
//ac: 2012年3月16日 星期五 15:15:57 HKT

#include <stdio.h>
#include <stdlib.h>
#define PRE 0.001

typedef struct node{
	int exp;
	float coef;
}ploy;

ploy a[12],b[12];
int ka,kb,kc;
float c[2010];

int main()
{
	int i,j,e;
	scanf("%d",&ka);
	for(i=0;i<ka;i++)
		scanf(" %d %f",&a[i].exp,&a[i].coef);
	scanf("%d",&kb);
	for(i=0;i<kb;i++)
		scanf(" %d %f",&b[i].exp,&b[i].coef);

	for(i=0;i<ka;i++){
		for(j=0;j<kb;j++){
			e=a[i].exp+b[j].exp;
			c[e]+=a[i].coef*b[j].coef;
		}
	}
	kc=0;
	for(i=0;i<2001;i++)
		if(c[i]>PRE||c[i]<-PRE)
			kc++;
	printf("%d",kc);
	for(i=2001;i>=0;i--)
		if(c[i]>PRE||c[i]<-PRE)
			printf(" %d %.1f",i,c[i]);
	printf("\n");
	return 0;
}