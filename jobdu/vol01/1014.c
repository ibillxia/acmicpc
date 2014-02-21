/**************************************************************
	Problem: 1014  第93450号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:100 ms
	Memory:936 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
	char name[21];
	int score;
}stu;
int m,n,g,fz[10];
stu st[1000];
int cmp(const void * a,const void * b){
	int t=(*(stu*)b).score-(*(stu*)a).score;
	if(t!=0)return t;
	else return strcmp((*(stu*)a).name,(*(stu*)b).name);
}
int main()
{
	int i,j,t,ts,ss;
	while(1){
		scanf("%d",&n);
		if(0==n)break;
		scanf("%d %d",&m,&g);
		for(i=0;i<m;i++)
			scanf("%d",&fz[i]);
		for(i=0;i<n;i++){
			scanf("%s",&(st[i].name));
			scanf("%d",&t);
			ss=0;
			for(j=0;j<t;j++){
				scanf("%d",&ts);
				ss+=fz[ts-1];
			}
			if(ss<g){
				n--;i--;
			}else st[i].score=ss;
		}
		qsort(st,n,sizeof(stu),cmp);
		printf("%d\n",n);
		for(i=0;i<n;i++)
			printf("%s %d\n",st[i].name,st[i].score);
	}
	return 0;
}
