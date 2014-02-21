/**************************************************************
	Problem: 1196  第147209号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:50 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int id;
	int score;
}student;

student stu[100];

int cmp(const void*a,const void*b){
	int t;
	t=(*(student*)a).score-(*(student*)b).score;
	if(t)return t;
	return (*(student*)a).id-(*(student*)b).id;
}

int main()
{
	int i,n;
	while(scanf("%d",&n)!=EOF){
		i=0;
		while(i<n){scanf("%d %d",&(stu[i].id),&(stu[i].score));i++;}
		qsort(stu,n,sizeof(student),cmp);
		i=0;
		while(i<n){printf("%d %d\n",stu[i].id,stu[i].score);i++;}
	}
	return 0;
}

