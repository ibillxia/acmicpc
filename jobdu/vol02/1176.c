/**************************************************************
	Problem: 1176  第159114号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>

int d[1010];

int main()
{
	int i,k,n,fm,to;
	while(scanf("%d",&n)!=EOF){
		for(i=1;i<=n;i++)scanf("%d",d+i);
		scanf("%d",&k);
		fm=1<<(k-1);to=(1<<k)-1;
		if(fm>n){printf("EMPTY");continue;}
		for(i=fm;i<to&&i<n;i++)printf("%d ",d[i]);
		printf("%d\n",d[i]);
	}
	return 0;
}
