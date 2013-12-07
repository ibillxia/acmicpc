//file: 1008.c
//author: ibillxia
//ac: 2012年3月16日 星期五 14:41:45 HKT

#include <stdio.h>

int main()
{
	int i,n,a,b,sum;
	scanf("%d",&n);
	sum=a=0;
	for(i=0;i<n;i++){
		scanf("%d",&b);
		if(b-a>0)sum+=6*(b-a)+5;
		else sum+=4*(a-b)+5;
		a=b;
	}
	printf("%d\n",sum);
	return 0;
}