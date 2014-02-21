/**************************************************************
	Problem: 1410  第190060号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:1150 ms
	Memory:8960 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
#define N 101
int n,blocks[N][N][N],dp[N][N][N];
int main()
{
	int i,j,k,l,w,h,minl,minw,minh,maxl,maxw,maxh,max;
	while(scanf("%d",&n)!=EOF){
		memset(blocks,0,sizeof(blocks));
		memset(dp,0,sizeof(dp));
		minl=minw=minh=100;maxl=maxw=maxh=0;
		for(i=0;i<n;i++){
			scanf("%d %d %d",&l,&w,&h);
			blocks[l][w][h]++;
			if(l>maxl)maxl=l;
			if(l<minl)minl=l;
			if(w>maxw)maxw=w;
			if(w<minw)minw=w;
			if(h>maxh)maxh=h;
			if(h<minh)minh=h;
		}
		for(i=minl;i<=maxl;i++)
			for(j=minw;j<=maxw;j++)
				for(k=minh;k<=maxh;k++){
					max=0;
					if(i>minl&&dp[i-1][j][k]>max)max=dp[i-1][j][k];
					if(j>minw&&dp[i][j-1][k]>max)max=dp[i][j-1][k];
					if(k>minh&&dp[i][j][k-1]>max)max=dp[i][j][k-1];
					dp[i][j][k]=max+blocks[i][j][k];
				}
		printf("%d\n",dp[maxl][maxw][maxh]);
	}
	return 0;
}
