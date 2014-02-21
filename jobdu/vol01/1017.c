/**************************************************************
	Problem: 1017  第93916号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:20 ms
	Memory:948 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
#define INF 0x7fffffff
int n,d[100][100];
int prim(){
	int i,j,t,sum,min,vis[100],low[100];
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	sum=0;
	low[0]=INF;
	for(i=1;i<n;i++) low[i]=d[0][i];
	for(i=1;i<n;i++){
		t=-1;min=INF;
		for(j=0;j<n;j++)
			if(!vis[j] && min>low[j]){
				t=j;min=low[j];
			}
		vis[t]=1;
		sum+=min;
		for(j=0;j<n;j++)
			if(!vis[j] && d[t][j]<low[j]){
				low[j] = d[t][j];
			}
	}
	return sum;
}
int main()
{
	int i,j,from,to,dis,min;
	while(1){
		scanf("%d",&n);
		if(0==n)break;
		for(i=0;i<n;i++)d[i][i]=INF;
		j=(n*(n-1))>>1;
		for(i=0;i<j;i++){
			scanf("%d %d %d",&from,&to,&dis);
			d[from-1][to-1]=d[to-1][from-1]=dis;
		}
		min = prim();
		printf("%d\n",min);
	}
	return 0;
}
