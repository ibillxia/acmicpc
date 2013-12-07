//file: 1019.c
//author: ibillxia
//ac: 2012年3月17日 星期六 21:35:53 HKT

#include <stdio.h>

int d[50];

int main()
{
	int i,j,k,n,p;
	scanf("%d %d",&n,&p);
	i=0;
	while(n){d[i]=n%p;n/=p;i++;}
	k=i-1;
	for(i=0,j=k;i<j;i++,j--)
		if(d[i]!=d[j]){printf("No\n");break;}
	if(i>=j)printf("Yes\n");
	printf("%d",d[k]);
	for(i=k-1;i>=0;i--)
		printf(" %d",d[i]);
	printf("\n");
	return 0;
}