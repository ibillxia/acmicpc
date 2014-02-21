/**************************************************************
	Problem: 1078  第157694号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char ch;
	struct node *lch,*rch;
}node,*tree;

char sa[28],sb[28];

void creat(char a[],char b[],tree *t){
	char ta[28],tb[28];
	int i,md,len;
	len=strlen(a);
	if(len){
		*t=(tree)malloc(sizeof(node));
		(*t)->ch=a[0];
		md=0;
		while(b[md]!=a[0])md++;
		for(i=1;i<md+1;i++)ta[i-1]=a[i];
		ta[i-1]='\0';
		for(i=0;i<md;i++)tb[i]=b[i];
		tb[i]='\0';
		creat(ta,tb,&((*t)->lch));
		for(i=md+1;i<=len;i++)ta[i-md-1]=a[i],tb[i-md-1]=b[i];
		creat(ta,tb,&((*t)->rch));
	}else *t=NULL;
}

void postorder(tree t){
	if(t){
		postorder(t->lch);
		postorder(t->rch);
		printf("%c",t->ch);
	}
}

int main()
{
	tree bt;
	while(gets(sa)){
		gets(sb);
		creat(sa,sb,&bt);
		postorder(bt);
		printf("\n");
	}
	return 0;
}
