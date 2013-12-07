//file: 1021.c
//author: ibillxia
//ac: 2012年3月20日 星期二 10:40:30 HKT

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define N 10100

int n,d[N],set[N],v[N],deep[N],cps,rts;

int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}

int Find(int x){
	while(x!=set[x])x=set[x];
	return x;
}

void Union(int a,int b){
	int t1,t2;
	t1=Find(a);
	t2=Find(b);
	if(t1!=t2){
		set[t2]=t1;
		cps--;
	}
}

int BFS(int st,int times){
	int i,t,hd,tl,tt,dp;
	memset(v,0,sizeof(v));
	memset(set,0,sizeof(set));
	hd=tl=dp=0;
	set[tl++]=st;tt=tl;
	while(hd<tl){
		t=set[hd++];v[t]=1;
		if(d[t]&&!v[d[t]])set[tl++]=d[t];
		for(i=1;i<=n;i++)
			if(d[i]==t&&!v[i])set[tl++]=i;
		if(hd==tt){
			if(hd!=tl){
				rts=0;
				for(i=hd;i<tl;i++)deep[rts++]=set[i];
			}
			tt=tl;dp++;
		}
	}
	if(!times)return t;
	return dp;
}

int main()
{
	int i,a,b;
	scanf("%d",&n);
	for(i=0;i<=n;i++)set[i]=i;
	cps=n;
	for(i=1;i<n;i++){
		scanf("%d %d",&a,&b);
		Union(a,b);
		if(!d[b])d[b]=a;
		else d[a]=b;
	}
	if(cps!=1){
		printf("Error: %d components\n",cps);
		return 0;
	}
	a=BFS(1,0);
	b=BFS(a,1);
	deep[rts++]=a;
	qsort(deep,rts,sizeof(int),cmp);
	for(i=0;i<rts;i++)
		printf("%d\n",deep[i]);
	return 0;
}