/**************************************************************
	Problem: 1028  第148832号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:20 ms
	Memory:948 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
#define INF 0x1fffffff
int n,g[100][100];
int main()
{
	int i,j,a,b,c,d;
	int low[100],v[100],t,min,sum;
	while(scanf("%d",&n)&&n!=0){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)g[i][j]=g[j][i]=INF;
		for(i=0;i<n;i++)g[i][i]=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++){
				scanf("%d %d %d %d",&a,&b,&c,&d);
				a--;b--;
				if(d==1)g[a][b]=g[b][a]=0;
				else if(g[a][b]>c)g[a][b]=g[b][a]=c;
			}
		memset(v,0,sizeof(v));
		for(i=1;i<n;i++)low[i]=g[0][i];
		v[0]=1;
		sum=0;
		for(i=1;i<n;i++){
			t=-1;min=INF;
			for(j=0;j<n;j++)
				if(!v[j]&&min>low[j]){min=low[j];t=j;}
			sum+=min;
			v[t]=1;
			for(j=0;j<n;j++)
				if(!v[j]&&low[j]>g[t][j])low[j]=g[t][j];
		}
		printf("%d\n",sum);
	}
	return 0;
}
