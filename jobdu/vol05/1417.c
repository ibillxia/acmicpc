/**************************************************************
	Problem: 1417  第172765号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:120 ms
	Memory:960 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
#include <string.h>
#define INF 0x1fffffff
#define N 102

int n,m,cost[N][N],vd[N],low[N];
char base[N][N];

int find(char bs[]){
	int i=0;
	while(base[i][0]){
		if(!strcmp(base[i],bs))return i;
		i++;
	}
	strcpy(base[i],bs);
	return i;
}

int prim(){
	int i,j,tj,min,max;
	memset(vd,0,sizeof(vd));
	for(i=0;i<n;i++)low[i]=cost[0][i];
	vd[0]=1;max=0;
	for(i=1;i<n;i++){
		tj=-1;min=INF;
		for(j=0;j<n;j++)
			if(!vd[j]&&low[j]<min){tj=j;min=low[j];}
		if(tj==-1)return 0;
		vd[tj]=1;
		if(min>max)max=min;
		for(j=0;j<n;j++)
			if(!vd[j]&&low[j]>cost[tj][j])
				low[j]=cost[tj][j];
	}
	return max;
}

int main()
{
	int i,j,k,d;
	char ba[102],bb[102];
	//freopen("inc.txt","r",stdin);
	//freopen("outc.txt","w",stdout);
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(base,0,sizeof(base));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cost[i][j]=INF;

		for(i=0;i<m;i++){
			scanf("%s %s %d",ba,bb,&d);
			j=find(ba);k=find(bb);
			if(cost[j][k]>d)cost[j][k]=cost[k][j]=d;
		}
		m=prim();
		if(!m)printf("My God\n");
		else printf("%d\n",m);
	}
	return 0;
}
