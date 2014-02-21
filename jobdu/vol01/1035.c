/**************************************************************
	Problem: 1035  第150336号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
int m,n;
char tree[27];
int dfs(char a,char b){
	int dp;
	char t;
	dp=0;
	t=a;
	while(t){
		dp++;
		t=tree[t];
		if(t==b)return dp;
	}
	return 0;
}
int main()
{
	int i,d;
	char s[4];
	while(scanf("%d %d",&n,&m)){
		if(m==0&&n==0)break;
		memset(tree,0,sizeof(tree));
		for(i=0;i<n;i++){
			scanf("%s",s);
			if(s[1]!='-')tree[s[1]-64]=s[0]-64;
			if(s[2]!='-')tree[s[2]-64]=s[0]-64;
		}
		for(i=0;i<m;i++){
			scanf("%s",s);
			d=dfs(s[0]-64,s[1]-64);
			if(!d)d=-dfs(s[1]-64,s[0]-64);
			if(!d){printf("-\n");continue;}
			while(d>2||d<-2){
				printf("great-");
				if(d>0)d--;
				else d++;
			}
			switch(d){
				case 2:printf("grandparent\n");break;
				case 1:printf("parent\n");break;
				case -1:printf("child\n");break;
				case -2:printf("grandchild\n");break;
			}
		}
	}
	return 0;
}
