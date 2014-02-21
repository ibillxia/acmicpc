/**************************************************************
	Problem: 1008  第155671号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:20 ms
	Memory:8732 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>

#define INF 0x1fffffff
#define N 1000

int m,n,s,t,g[N][N][2],lp[N],lc[N],v[N];

void dijkstra(){
	int i,j,k,md,mp;
	memset(v,0,sizeof(v));
	memset(lp,0,sizeof(lp));
	memset(lc,0,sizeof(lc));
	for(i=0;i<n;i++)lp[i]=g[s][i][0];
	for(i=0;i<n;i++)lc[i]=g[s][i][1];
	v[s]=1;
	for(i=0;i<n;i++){
		k=-1;md=INF;mp=INF;
		for(j=0;j<n;j++)
			if(!v[j]){
				if(lp[j]<md){k=j;md=lp[j];mp=lc[j];}
				else if(lp[j]==md&&lc[j]<mp){k=j;mp=lc[j];}
			}
		if(k==t)return;
		v[k]=1;
		for(j=0;j<n;j++)
			if(lp[j]>lp[k]+g[k][j][0]){
				lp[j]=lp[k]+g[k][j][0];
				lc[j]=lc[k]+g[k][j][1];
			}else if(lp[j]==lp[k]+g[k][j][0]&&lc[j]>lc[k]+g[j][k][1]){
				lp[j]=lp[k]+g[k][j][0];
				lc[j]=lc[k]+g[k][j][1];
			}
	}
}

int main()
{
	int i,j,a,b,d,p;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(m==0&&n==0)break;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				g[i][j][0]=g[i][j][1]=INF;
		
		for(i=0;i<m;i++){
			scanf("%d %d %d %d",&a,&b,&d,&p);
			a--;b--;
			if(g[a][b][0]>d){
				g[a][b][0]=g[b][a][0]=d;
				g[a][b][1]=g[b][a][1]=p;
			}else if(g[a][b][0]==d&&g[a][b][1]>p) g[a][b][1]=g[b][a][1]=p;
		}
		scanf("%d %d",&s,&t);
		s--;t--;
		dijkstra();
		printf("%d %d\n",lp[t],lc[t]);
	}
	return 0;
}
