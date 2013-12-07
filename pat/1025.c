//file: 1025.c
//author: ibillxia
//ac: 2012年3月19日 星期一 17:51:15 HKT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct node{
	char id[20];   //id用long long第4个测试点wa好几次了，改成char[]一次ac
	int area,score,rank,arank;
}testee;

testee tt[30010];
int n,an,num,ark[110][3];

int cmp(const void*a,const void*b){
	testee t1,t2;
	t1=*(testee*)a;t2=*(testee*)b;
	if(t1.score!=t2.score)return t2.score-t1.score;
	return strcmp(t1.id,t2.id);
}

int main()
{
	int i,j,k,ta;
	memset(ark,0,sizeof(ark));
	//freopen("in-1025.txt","r",stdin);
	scanf("%d",&n);
	num=k=0;
	for(i=0;i<n;i++){
		scanf("%d",&an);
		num+=an;ta=i+1;
		for(j=0;j<an;j++){
			scanf("%s %d",tt[k].id,&tt[k].score);
			tt[k].area=ta; k++;
		}
	}

	qsort(tt,num,sizeof(testee),cmp);
	if(num>0){
		ta=tt[0].area;
		tt[0].rank=tt[0].arank=ark[ta][0]=ark[ta][1]=1;
		ark[ta][2]=tt[0].score;
	}
	for(i=1;i<num;i++){
		if(tt[i].score==tt[i-1].score)tt[i].rank=tt[i-1].rank;
		else tt[i].rank=i+1;
		ta=tt[i].area; ark[ta][0]++;
		if(ark[ta][1]==0){tt[i].arank=ark[ta][0]=ark[ta][1]=1;ark[ta][2]=tt[i].score;}
		else if(tt[i].score==ark[ta][2])tt[i].arank=ark[ta][1];
		else {tt[i].arank=ark[ta][1]=ark[ta][0];ark[ta][2]=tt[i].score;}
	}
	
	printf("%d\n",num);
	for(i=0;i<num;i++)
		printf("%s %d %d %d\n",tt[i].id,tt[i].rank,tt[i].area,tt[i].arank);
	return 0;
}
