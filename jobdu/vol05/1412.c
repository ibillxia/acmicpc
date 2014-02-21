/**************************************************************
	Problem: 1412  第190084号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:920 kb
****************************************************************/
#include <stdio.h>
#define N 41
long long c[N][N];

void combination(){
	int i,j;
	for(i=0;i<N;i++)c[i][i]=c[i][0]=1;
	for(i=1;i<N;i++)
		for(j=0;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
}

int main()
{
	int n;
	combination();
	while(~scanf("%d",&n))
		printf("%lld\n",c[n][n/2]/(n/2+1));
	return 0;
}
