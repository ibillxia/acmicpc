/**************************************************************
	Problem: 1415  第137070号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:160 ms
	Memory:1300 kb
****************************************************************/
#include <stdio.h>
#include <string.h>
int n,m,que[100100],hd,tl;
int main()
{
	int i,j,t;
	char s[10];
	while(scanf("%d %d",&n,&m)!=EOF){
		m=m+1;
		hd=tl=0;
		for(i=0;i<n;i++){
			scanf("%s",s);
			if(!strcmp(s,"Push")){
				scanf("%d",&t);
				if((tl+1)%m==hd){printf("failed\n");continue;}
				que[tl]=t;
				tl=(tl+1)%m;
			}else if(!strcmp(s,"Pop")){
				if(hd==tl){printf("failed\n");continue;}
				hd=(hd+1)%m;
			}else if(!strcmp(s,"Query")){
				scanf("%d",&t);
				j=(hd+t-1)%m;
				if((j>=hd&&j<tl)||(tl<hd&&j>=hd&&j<tl+m))printf("%d\n",que[j]);
				else printf("failed\n");
			}else if(!strcmp(s,"Isempty")){
				if(hd==tl)printf("yes\n");
				else printf("no\n");
			}else{
				if((tl+1)%m==hd)printf("yes\n");
				else printf("no\n");
			}
		}
	}
	return 0;
}
