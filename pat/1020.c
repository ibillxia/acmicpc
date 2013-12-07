//file: 1020.c
//author: ibillxia
//ac: 2012年3月18日 星期日 11:29:29 HKT

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int id;
	struct node *lch,*rch;
}node,*tree;


int n,it[32],pt[32];
tree lt[32];

void creat(tree *t,int pl,int pr,int il,int ir){
	int i,tt;
	tt=pr-pl;
	if(tt==0&&pl>0){
		*t=(tree)malloc(sizeof(node));
		(*t)->id=pt[pl];
		(*t)->lch=(*t)->rch=NULL;
	}else if(tt>0&&pl>0){
		*t=(tree)malloc(sizeof(node));
		(*t)->id=pt[pr];
		for(i=il;i<=ir;i++)if(it[i]==pt[pr])break;
		creat(&(*t)->lch,pl,pl+i-1-il,il,i-1);
		creat(&(*t)->rch,pr+i-ir,pr-1,i+1,ir);
	}else (*t)=NULL;
}

int main()
{
	int i,hd,tl,blank;
	tree bt,tt;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",pt+i);
	for(i=1;i<=n;i++)
		scanf("%d",it+i);
	creat(&bt,1,n,1,n);

	hd=tl=1;blank=0;
	lt[tl++]=bt;
	while(hd<tl){
		tt=lt[hd++];
		if(blank)printf(" ");
		printf("%d",tt->id);
		blank=1;
		if(tt->lch)lt[tl++]=tt->lch;
		if(tt->rch)lt[tl++]=tt->rch;
	}
	printf("\n");
	return 0;
}