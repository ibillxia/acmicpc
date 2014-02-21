/**************************************************************
	Problem: 1023  第109951号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:130 ms
	Memory:3400 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
    char num[7];
    char name[9];
    int score;
}student;
int n;
student stu[100000];
int cmp1(const void *a,const void *b){
    return strcmp((*(student*)a).num,(*(student*)b).num);
}
int cmp2(const void *a,const void *b){
    int t=strcmp((*(student*)a).name,(*(student*)b).name);
    if(t!=0)return t;
    else return strcmp((*(student*)a).num,(*(student*)b).num);
}
int cmp3(const void *a,const void *b){
    int t=(*(student*)a).score-(*(student*)b).score;
    if(t!=0)return t;
    else return strcmp((*(student*)a).num,(*(student*)b).num);
}
int main()
{
    int i,c,cnt;
    cnt=0;
    while(scanf("%d %d",&n,&c)){
        if(n==0)break;
        cnt++;
        for(i=0;i<n;i++)
            scanf("%s %s %d",stu[i].num,stu[i].name,&stu[i].score);
        switch(c){
            case 1: qsort(stu,n,sizeof(stu[0]),cmp1);break;
            case 2: qsort(stu,n,sizeof(stu[0]),cmp2);break;
            case 3: qsort(stu,n,sizeof(stu[0]),cmp3);break;
        }
        printf("Case %d:\n",cnt);
        for(i=0;i<n;i++)
            printf("%s %s %d\n",stu[i].num,stu[i].name,stu[i].score);
    }
    return 0;
}
