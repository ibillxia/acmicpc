//file: 1022.c
//author: ibillxia
//ac: 2012年3月19日 星期一 21:35:47 HKT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define N 10000

typedef struct node{
	char id[10],title[82],author[82],keywords[5][12],publisher[82],pubyear[6];
}book;

book bks[N];

int cmp(const void*a,const void*b){return strcmp((*(book*)a).id,(*(book*)b).id);}

int main()
{
	int i,j,jj,k,n,m;
	char keys[60],tp[100],*p,*q;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","r",stdout);
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		gets(bks[i].id);
		gets(bks[i].title);
		gets(bks[i].author);
		gets(keys);
		j=0;q=keys;
		while(1){
			p=strchr(q,' ');
			if(!p)break;
			strncpy(bks[i].keywords[j],q,p-q);
			q=p+1;j++;
		}
		strcpy(bks[i].keywords[j],q);
		gets(bks[i].publisher);
		gets(bks[i].pubyear);
	}
	qsort(bks,n,sizeof(book),cmp);
	scanf("%d",&m);getchar();
	for(i=0;i<m;i++){
		gets(tp);puts(tp);k=0;p=tp+3;
		switch(tp[0]){
			case '1':
				for(j=0;j<n;j++)
					if(!strcmp(p,bks[j].title)){puts(bks[j].id);k=1;}
				break;
			case '2':
				for(j=0;j<n;j++)
					if(!strcmp(p,bks[j].author)){puts(bks[j].id);k=1;}
				break;
			case '3':
				for(j=0;j<n;j++)
					for(jj=0;bks[j].keywords[jj][0];jj++)
						if(!strcmp(p,bks[j].keywords[jj])){puts(bks[j].id);k=1;break;}
				break;
			case '4':
				for(j=0;j<n;j++)
					if(!strcmp(p,bks[j].publisher)){puts(bks[j].id);k=1;}
				break;
			case '5':
				for(j=0;j<n;j++)
					if(!strcmp(p,bks[j].pubyear)){puts(bks[j].id);k=1;}
				break;
		}
		if(!k)printf("Not Found\n");
	}
	return 0;
}