/**************************************************************
	Problem: 1030  第150116号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:1160 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX(a,b) (a)>(b) ? (a) : (b)
int n,d[32][3],m[32][2000];
int cmp(const void *a,const void *b){
	return ((int*)a)[2]-((int*)b)[2];
}
int main()
{
	int i,j,tm,mh;
	while(scanf("%d",&n) && n>=0){
		if(n==0)continue;
		tm=0;
		for(i=0;i<n;i++){
			scanf("%d %d %d",d[i],d[i]+1,d[i]+2);
			if(tm<d[i][2])tm=d[i][2];
		}

		qsort(d,n,sizeof(d[0]),cmp);
		memset(m,0,sizeof(m));
		mh=-1;
		for(i=1;i<=n;i++)
			for(j=0;j<=tm;j++){
				if(j<=d[i-1][2]&&j>=d[i-1][1])
					m[i][j]=MAX(m[i-1][j],m[i-1][j-d[i-1][1]]+d[i-1][0]);
				else
					m[i][j]=m[i-1][j];
				if(m[i][j]>mh)mh=m[i][j];
			}
		printf("%d\n",mh);
	}
	return 0;
}
