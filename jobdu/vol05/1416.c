/**************************************************************
	Problem: 1416  第171945号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:100 ms
	Memory:2004 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char name[102];
	int strong,food;
}monkey;

monkey mk[10010];
int m,n;

int cmp(const void*a,const void*b){
	int ta,tb;
	tb=(*(monkey*)b).strong;
	ta=(*(monkey*)a).strong;
	if(tb-ta)return tb-ta;
	return strcmp((*(monkey*)a).name,(*(monkey*)b).name);
}

int main()
{
	int i,j,cnt;
	char mky[102];
	//freopen("inb.txt","r",stdin);
	//freopen("outb.txt","w",stdout);
	while(scanf("%d %d",&n,&m)!=EOF){
		for(i=0;i<n;i++)
			scanf("%s %d %d",mk[i].name,&mk[i].strong,&mk[i].food);
		
		qsort(mk,n,sizeof(monkey),cmp);
		
		for(i=0;i<m;i++){
			scanf("%s",mky);
			cnt=0;
			for(j=0;j<n;j++)
				if(strcmp(mk[j].name,mky))cnt+=mk[j].food;
				else break;
			cnt++;
			printf("%d\n",cnt);
		}
	}
	return 0;
}
