//file: 1003.c
//author: ibillxia
//ac: 2012年3月15日 星期四 21:55:31 HKT

#include <stdio.h>

#define INF 0x1fffffff
#define N 500

int n,m,c1,c2;
int dist[N][N],teams[N],low[N],vd[N],maxt[N],cnt[N];

void dijkstra(){
	int j,dmin,tj;
	low[c1]=0;maxt[c1]=teams[c1];cnt[c1]=1;

	while(1){
		dmin=INF;tj=-1;
		for(j=0;j<n;j++)
			if(!vd[j]&&low[j]<dmin){tj=j;dmin=low[j];}

		if(tj==-1||tj==c2)return;
		vd[tj]=1;

		for(j=0;j<n;j++)
			if(!vd[j]){
				if(low[j]>low[tj]+dist[tj][j]){
					low[j]=low[tj]+dist[tj][j];
					maxt[j]=maxt[tj]+teams[j];
					cnt[j]=cnt[tj];
				}else if(low[j]==low[tj]+dist[tj][j]){
					cnt[j]+=cnt[tj];
					if(maxt[j]<maxt[tj]+teams[j]) 
						maxt[j]=maxt[tj]+teams[j];
				}
			}
	}
}

int main()
{
	int i,j,a,b,dab;
	while(scanf("%d %d %d %d",&n,&m,&c1,&c2)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",teams+i);
			low[i]=INF;vd[i]=maxt[i]=cnt[i]=0;
			for(j=0;j<n;j++)
				dist[i][j]=INF;
		}
		for(i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&dab);
			if(dab<dist[a][b])
				dist[a][b]=dist[b][a]=dab;
		}

		dijkstra();

		printf("%d %d\n",cnt[c2],maxt[c2]);
	}
	return 0;
}