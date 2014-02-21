/**************************************************************
	Problem: 1061  第147154号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:100 ms
	Memory:1020 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char name[102];
	int age;
	int score;
}student;

student stu[1000];

int cmp(const void *a,const void *b){
	int t;
	student sa,sb;
	sa=*(student*)a;sb=*(student*)b;
	if(sa.score!=sb.score)return sa.score-sb.score;
	t=strcmp(sa.name,sb.name);
	if(t)return t;
	return sa.age-sb.age;
}

int main()
{
	int i,n;
	while(scanf("%d",&n)!=EOF){
		i=0;
		while(i<n){
			scanf("%s %d %d",&(stu[i].name),&(stu[i].age),&(stu[i].score));
			i++;
		}
		qsort(stu,n,sizeof(student),cmp);
		for(i=0;i<n;i++)
			printf("%s %d %d\n",stu[i].name,stu[i].age,stu[i].score);
	}

	return 0;
}
