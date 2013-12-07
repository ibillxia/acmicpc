//file: 1028.c
//author: ibillxia
//ac: 2012年3月18日 星期日 21:29:15 HKT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100100
typedef struct node{
	int id,score;
	char name[10];
}student;

student stu[N];

int cmp1(const void*a,const void*b){
	student sa,sb;
	sa=*(student*)a;sb=*(student*)b;
	return sa.id-sb.id;
}

int cmp2(const void*a,const void*b){
	int t;
	student sa,sb;
	sa=*(student*)a;sb=*(student*)b;
	t=strcmp(sa.name,sb.name);
	if(t)return t;
	return sa.id-sb.id;
}

int cmp3(const void*a,const void*b){
	int t;
	student sa,sb;
	sa=*(student*)a;sb=*(student*)b;
	t=sa.score-sb.score;
	if(t)return t;
	return sa.id-sb.id;
}

int main()
{
	int i,n,c;
	scanf("%d %d",&n,&c);
	for(i=0;i<n;i++)
		scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].score);
	if(c==1)qsort(stu,n,sizeof(student),cmp1);
	else if(c==2)qsort(stu,n,sizeof(student),cmp2);
	else qsort(stu,n,sizeof(student),cmp3);
	for(i=0;i<n;i++)
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].score);
	return 0;
}

