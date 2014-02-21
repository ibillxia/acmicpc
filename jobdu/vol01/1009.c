/**************************************************************
	Problem: 1009  第123440号提交
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
	int data;
	struct node *lchild,*rchild;
}btnode,*btree;
int n;
btree ta,tb;
void creat(char s[],btree *t){
	int i,k;
	btree p,q;
	if(s[0]=='\0'){t=NULL;return;}
	*t=(btree)malloc(sizeof(btnode));
	(*t)->data=s[0]-'0';
	(*t)->lchild=(*t)->rchild=NULL;
	i=1;
	while(s[i]){
		k=s[i]-'0';
		p=*t;
		while(p){
			q=p;
			if(k<p->data) p=p->lchild;
			else p=p->rchild;
		}
		p=(btree)malloc(sizeof(btnode));
		p->data=k;
		p->lchild=p->rchild=NULL;
		if(k<q->data)q->lchild=p;
		else q->rchild=p;
		i++;
	}
}
int cmp(btree ta,btree tb){
	btree p,q;
	p=ta;q=tb;
	if((p&&!q)||(q&&!p)||(p&&q&&p->data!=q->data))return 0;
	if(p&&q&&p->data==q->data)
		if(!cmp(p->lchild,q->lchild)||!cmp(p->rchild,q->rchild))
			return 0;
	return 1; 
}
int main()
{
	char str[12];
	int i,la,lb;
	while(scanf("%d",&n)&&n!=0){
		scanf("%s",str);
		la=strlen(str);
		creat(str,&ta);
		for(i=0;i<n;i++){
			scanf("%s",str);
			lb=strlen(str);
			if(lb!=la){printf("NO\n");continue;}
			creat(str,&tb);
			if(cmp(ta,tb))printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
