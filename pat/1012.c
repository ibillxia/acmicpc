//file: 1012.c
//author: ibillxia
//ac: 2012年3月16日 星期五 16:28:47 HKT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char id[8];
	int sa,sc,sm,se,rk,br; 
	char brt;
}student;

student stu[2000];
char sstu[2000][8];

int cmpa(const void*a,const void*b){return (*(student*)b).sa-(*(student*)a).sa;}
int cmpc(const void*a,const void*b){return (*(student*)b).sc-(*(student*)a).sc;}
int cmpm(const void*a,const void*b){return (*(student*)b).sm-(*(student*)a).sm;}
int cmpe(const void*a,const void*b){return (*(student*)b).se-(*(student*)a).se;}

int main()
{
	int i,j,m,n,tsc,tsm,tse;
	scanf("%d %d",&n,&m);
	i=0;
	while(i<n){
		scanf("%s %d %d %d",stu[i].id,&tsc,&tsm,&tse);
		stu[i].sa=(int)((tsc+tsm+tse)/3.0+0.5);
		stu[i].sc=tsc;stu[i].sm=tsm;stu[i].se=tse;
		i++;
	}
	i=0;
	while(i<m){scanf("%s",sstu[i]);i++;}
	
	qsort(stu,n,sizeof(student),cmpa);
	if(n>0){stu[0].br=0;stu[0].brt='A';}
	for(i=1;i<n;i++){
		if(stu[i].sa==stu[i-1].sa)stu[i].br=stu[i-1].br;
		else stu[i].br=i;
		stu[i].brt='A';
	}
	
	qsort(stu,n,sizeof(student),cmpc);
	if(n>0&&stu[0].br){stu[0].br=0;stu[0].brt='C';}
	if(n>0)stu[0].rk=0;
	for(i=1;i<n;i++){
		if(stu[i].sc==stu[i-1].sc)stu[i].rk=stu[i-1].rk;
		else stu[i].rk=i;
		if(stu[i].rk<stu[i].br){stu[i].br=stu[i].rk;stu[i].brt='C';}
	}
	
	qsort(stu,n,sizeof(student),cmpm);
	if(n>0&&stu[0].br){stu[0].br=0;stu[0].brt='M';}
	if(n>0)stu[0].rk=0;
	for(i=1;i<n;i++){
		if(stu[i].sm==stu[i-1].sm)stu[i].rk=stu[i-1].rk;
		else stu[i].rk=i;
		if(stu[i].rk<stu[i].br){stu[i].br=stu[i].rk;stu[i].brt='M';}
	}
	
	qsort(stu,n,sizeof(student),cmpe);
	if(n>0&&stu[0].br){stu[0].br=0;stu[0].brt='E';}
	if(n>0)stu[0].rk=0;
	for(i=1;i<n;i++){
		if(stu[i].se==stu[i-1].se)stu[i].rk=stu[i-1].rk;
		else stu[i].rk=i;
		if(stu[i].rk<stu[i].br){stu[i].br=stu[i].rk;stu[i].brt='E';}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			if(!strcmp(stu[j].id,sstu[i])){printf("%d %c\n",stu[j].br+1,stu[j].brt);break;}
			if(j==n)printf("N/A\n");
	}
	return 0;
}