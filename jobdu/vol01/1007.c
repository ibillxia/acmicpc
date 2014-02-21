/**************************************************************
	Problem: 1007  第116121号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:960 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct nation{
	int gold;
	int medals;
	double people;
	double gpp;
	double mpp;
	int rank[4];
}nation;
nation nt[1000];
int m,n,d[1000];
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main()
{
	int i,j,k,t,min,mini,flag;
	flag=0;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(flag)printf("\n");
		for(i=0;i<n;i++){
			scanf("%d %d %lf",&nt[i].gold,&nt[i].medals,&nt[i].people);
			nt[i].gpp=(double)nt[i].gold/nt[i].people;
			nt[i].mpp=(double)nt[i].medals/nt[i].people;
		}
		for(i=0;i<m;i++)scanf("%d",d+i);
		qsort(d,m,sizeof(d[0]),cmp);
		for(i=0;i<m;i++){
			k=d[i];
			for(j=0;j<4;j++)nt[k].rank[j]=m;
			for(t=0;t<m;t++){
				j=d[t];
				if(j!=k){
					if(nt[k].gold>=nt[j].gold) nt[k].rank[0]--;
					if(nt[k].medals>=nt[j].medals) nt[k].rank[1]--;
					if(nt[k].gpp>=nt[j].gpp)nt[k].rank[2]--;
					if(nt[k].mpp>=nt[j].mpp)nt[k].rank[3]--;
				}
			}
			min=nt[k].rank[mini=0];
			if(min>nt[k].rank[1])min=nt[k].rank[mini=1];
			if(min>nt[k].rank[2])min=nt[k].rank[mini=2];
			if(min>nt[k].rank[3])min=nt[k].rank[mini=3];
			printf("%d:%d\n",min,mini+1);
		}
		flag=1;
	}
	return 0;
}
