/**************************************************************
	Problem: 1002  第122686号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
int main()
{
	int p,t,g1,g2,g3,gj,t1,t2;
	while(scanf("%d %d %d %d %d %d",&p,&t,&g1,&g2,&g3,&gj)!=EOF){
		if(g1-g2<=t&&g2-g1<=t){printf("%.1f\n",(g1+g2)/2.0);continue;}
		t1=g3>g1 ? g3-g1 : g1-g3;
		t2=g3>g2 ? g3-g2 : g2-g3;
		if(t1>t&&t2>t){printf("%.1f\n",(float)gj);continue;}
		if(t1<=t&&t2<=t) {
			if(g1<g2)g1=g2;
			if(g1<g3)g1=g3;
			printf("%.1f\n",(float)g1);
			continue;
		}
		if(t1>t2)printf("%.1f\n",(g2+g3)/2.0);
		else printf("%.1f\n",(g1+g3)/2.0);
	}
	return 0;
}
