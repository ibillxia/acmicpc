//file: 1030.c
//author: ibillxia
//ac: 2012年3月19日 星期一 17:41:29 HKT

#include <stdio.h>
#include <memory.h>
#define N 510
#define INF 10000

int m,n,s,d,md,mc;
int dist[N][N],cost[N][N],route[N],used[N],path[N];

void dijkstra(){
	int i,j,k,td,tc;
	int *ld=dist[s];
	int *lc=cost[s];

	for(i=0;i<n;i++)
		if(ld[i]==INF)route[i]=-1;
		else route[i]=s;
	used[s]=1;
	for(i=1;i<n;i++){
		k=-1;td=tc=INF;
		for(j=0;j<n;j++)
			if(!used[j]){
				if(td>ld[j]){k=j;td=ld[j];tc=lc[j];}
				else if(td==ld[j]&&tc<lc[j]){k=j;tc=lc[j];}
			}
		used[k]=1;
		for(j=0;j<n;j++)
			if(!used[j]){
				if(ld[j]>ld[k]+dist[k][j]){
					ld[j]=ld[k]+dist[k][j];
					lc[j]=lc[k]+cost[k][j];
					route[j]=k;
				}else if(ld[j]==ld[k]+dist[k][j]&&lc[j]>lc[k]+cost[k][j]){
					lc[j]=lc[k]+cost[k][j];
					route[j]=k;
				}
			}
		md=ld[k];mc=lc[k];
		if(k==d)return;
	}
}

int main()
{
	int i,j,c1,c2,dd,c;
	scanf("%d %d %d %d",&n,&m,&s,&d);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dist[i][j]=cost[i][j]=INF;

	for(i=0;i<m;i++){
		scanf("%d %d %d %d",&c1,&c2,&dd,&c);
		if(dist[c1][c2]>dd){
			dist[c1][c2]=dist[c2][c1]=dd;
			cost[c1][c2]=cost[c2][c1]=c;
		}else if(dist[c1][c2]==dd&&cost[c1][c2]==c)
			cost[c1][c2]=cost[c2][c1]=c;
	}
	dijkstra();
	for(i=d,j=0;i!=-1;i=route[i],j++)
		path[j]=i;
	for(i=j-1;i>=0;i--)
		printf("%d ",path[i]);
	printf("%d %d\n",md,mc);
	return 0;
}