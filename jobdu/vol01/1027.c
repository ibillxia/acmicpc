/**************************************************************
	Problem: 1027  第146750号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:80 ms
	Memory:4820 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
int m,n,v[1000],g[1000][1000];
int main()
{
	int i,j,a,b;
	while(scanf("%d",&n)&&n!=0){
		scanf("%d",&m);
		memset(v,0,sizeof(v));
		memset(g,0,sizeof(g));
		for(i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			a--;b--;
			g[a][b]=g[b][a]=1;
			v[a]++;v[b]++;
		}
		if(m<n){printf("0\n");continue;}
		for(i=0;i<n;i++)if(v[i]%2)break;
		if(i<n)printf("0\n");
		else{
			memset(v,0,sizeof(v));
			v[0]=1;j=0;
			for(i=0;i<n;i++){  //DFS
				if(!v[i] && g[j][i]){
					v[i]=1;j=i;i=0;
				}
			}
			for(i=0;i<n;i++)
				if(!v[i]){printf("0\n");break;}
			if(i==n)printf("1\n");
		}
	}
	return 0;
}
