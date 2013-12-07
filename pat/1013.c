//file: 1013.c
//author: ibillxia
//ac: 2012年3月17日 星期六 20:27:35 HKT

#include <stdio.h>
#include <memory.h>
#define INF 0x1fffffff
#define N 1000
int n,m,k,nr;
int mat[N][N],bak[N][N],set[N];

int Find(int x){
	while(set[x]!=x) x=set[x];
	return x;
}

void Union(int a,int b){
	int t1,t2;
	t1=Find(a);
	t2=Find(b);
	if(t1!=t2){
		set[t2]=t1;
		nr--;
	}
}

int count(int chk){
	int i,j;
	for(i=0;i<=n;i++)set[i]=i;
	nr=n-1;
	memcpy(bak,mat,sizeof(mat));
	for(i=1;i<=n;i++)
		bak[i][chk]=bak[chk][i]=0;
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(bak[i][j]) Union(i,j);
	return nr-1;
}

int main()
{
	int i,c1,c2,chk;
	scanf("%d %d %d",&n,&m,&k);
	memset(mat,0,sizeof(mat));
	for(i=0;i<m;i++){
		scanf("%d %d",&c1,&c2);
		mat[c1][c2]=mat[c2][c1]=1;
	}

	for(i=0;i<k;i++){
		scanf("%d",&chk);
		printf("%d\n",count(chk));
	}
	return 0;
}
