//file: 1002.c
//author: ibillxia
//ac: 2012年3月12日 星期一 15:47:31 HKT

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node{
	int exp;
	int coef;
	struct node *next;
}node,*ploy;

void merge(ploy *a,ploy *b){
	ploy p,q,pp,qn;
	pp=*a;qn=*b;
	p=pp->next;q=qn->next;
	while(p&&q){
		if(p->exp>q->exp){
			pp=p;
			p=p->next;
		}else if(p->exp<q->exp){
			qn=q->next;
			pp->next=q;
			q->next=p;
			pp=q;
			q=qn;
		}else{
			p->coef+=q->coef;
			if(!p->coef){
				pp->next=p->next;
				free(p);
			}else pp=p;
			p=pp->next;
			qn=q->next;
			free(q);
			q=qn;
		}
	}
	if(!p&&q){
		pp->next=q;
	}
}

int main()
{
	int k,ei;
	float ci;
	ploy a,b,t,tp;
	a=(ploy)malloc(sizeof(node));
	b=(ploy)malloc(sizeof(node));
	a->next=b->next=NULL;
	while(scanf("%d",&k)!=EOF){
		tp=a;
		while(k--){
			scanf(" %d %f",&ei,&ci);
			t=(ploy)malloc(sizeof(node));
			t->exp=ei;
			t->coef=(int)(ci*100);
			t->next=NULL;
			tp->next=t;
			tp=t;
		}
		scanf("%d",&k);
		tp=b;
		while(k--){
			scanf(" %d %f",&ei,&ci);
			t=(ploy)malloc(sizeof(node));
			t->exp=ei;
			t->coef=(int)(ci*100);
			t->next=NULL;
			tp->next=t;
			tp=t;
		}
		merge(&a,&b);
		tp=a->next;k=0;
		while(tp){tp=tp->next;k++;}
		printf("%d",k);
		tp=a->next;
		while(tp){
			printf(" %d %.1lf",tp->exp,tp->coef/100.0);
			tp=tp->next;
		}
		printf("\n");
	}
	return 0;
}