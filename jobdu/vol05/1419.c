/**************************************************************
	Problem: 1419  第171224号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:50 ms
	Memory:948 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char paper[202][202];

int cmp(const void*a,const void*b){
	char sa[202],sb[202],t1,t2;
	int i=0,j=0;
	strcpy(sa,(char*)a);
	strcpy(sb,(char*)b);
	while(sa[i]&&sb[j]){
		t1=sa[i];t2=sb[j];
		if(t1>='A'&&t1<='Z')t1=t1|32;
		if(t2>='A'&&t2<='Z')t2=t2|32;
		if(t1!=t2)return t1-t2;
		i++;j++;
	}
	if(!sa[i]&&!sb[i])return 0;
	else if(!sa[i])return -1;
	return 1;
}

int main()
{
	int i,n;
	//freopen("ina.txt","r",stdin);
	//freopen("outa.txt","w",stdout);
	while(scanf("%d",&n)!=EOF){
		getchar();
		for(i=0;i<n;i++)
			gets(paper[i]);
		qsort(paper,n,sizeof(char)*202,cmp);
		for(i=0;i<n;i++)
			puts(paper[i]);
	}
	return 0;
}
