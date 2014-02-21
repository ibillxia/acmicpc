/**************************************************************
	Problem: 1346  第148179号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:160 ms
	Memory:912 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int id,s;
}user;

user u[1000];

int cmp(const void*a,const void*b){
	user ta,tb;
	ta=*(user*)a;tb=*(user*)b;
	if(ta.s==tb.s)return ta.id-tb.id;
	else return tb.s-ta.s;
}

int main()
{
	int i,m,n;
	while(scanf("%d %d",&n,&m)!=EOF){
		i=0;
		while(i<n){
			scanf("%d %d",&(u[i].id),&(u[i].s));
			i++;
		}
		qsort(u,n,sizeof(user),cmp);
		if(m>n)m=n;
		for(i=0;i<m;i++)printf("%d\n",u[i].id);
	}
	return 0;
}
