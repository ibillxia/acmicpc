//file: 1007.c
//author: ibillxia
//ac: 2012年3月16日 星期五 12:21:02 HKT

#include <stdio.h>
#define N 10000

int k,d[N];

int main()
{
	int i,ts,s,e,sum,max,nc;
	scanf("%d",&k);
	nc=0;
	for(i=0;i<k;i++){
		scanf("%d",d+i);
		if(d[i]<0)nc++;
	}
	if(nc==k){
		printf("0 %d %d",d[0],d[k-1]);
		return 0;
	}

	s=e=ts=sum=0;max=d[0];
	for(i=0;i<k;i++){
		if(sum<=0){ts=i;sum=0;}
		sum+=d[i];
		if(sum>max){
			max=sum;
			s=ts;
			e=i;
		}
	}
	printf("%d %d %d\n",max,d[s],d[e]);
	return 0;
}