/**************************************************************
	Problem: 1088  第101256号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:40 ms
	Memory:920 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>

char f[10002];

int main()
{
	int i,m,l,s,t,cnt;
	while(scanf("%d %d",&l,&m)!=EOF){
		memset(f,1,l+1);
		for(i=0;i<m;i++){
			scanf("%d %d",&s,&t);
			memset(f+s,0,t-s+1);
		}
		cnt=0;
		for(i=0;i<=l;i++)
			if(f[i])cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
