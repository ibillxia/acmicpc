/**************************************************************
	Problem: 1411  第189502号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:130 ms
	Memory:1896 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
#define INF 0x1fffffff
int m,n,mt[502][502],vd[502];
int dijkstra(int st){
	int i,k,min;
	int *low=mt[st];
	memset(vd,0,sizeof(vd));
	while(1){
		k=-1;min=INF;
		for(i=1;i<=n;i++)
			if(!vd[i]&&min>low[i]){k=i;min=low[i];}
		if(k==-1)return -1;
		vd[k]=1;
		if(k==st)return low[st];
		for(i=1;i<=n;i++)
			if(!vd[i]&&low[i]>low[k]+mt[k][i])
				low[i]=low[k]+mt[k][i];
		
	}
}
int main()
{
	int i,j,a,b,c,s;
	while(~scanf("%d %d %d",&n,&m,&s)){
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mt[i][j]=INF;
		for(i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			if(c<mt[a][b])mt[a][b]=c;
		}
		a=dijkstra(s);
		if(a==-1)printf("help!\n");
		else printf("%d\n",a);
	}
	return 0;
}
