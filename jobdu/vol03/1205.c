/**************************************************************
	Problem: 1205  第151765号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:904 kb
****************************************************************/
#include <stdio.h>
int main()
{
	int step;
	long long t1,t2,t;
	
	while(scanf("%d",&step)!=EOF){
		t1=1;t2=2;
		if(step==1){printf("1\n");continue;}
		if(step==2){printf("2\n");continue;}
		while(step>2){
			t=t1+t2;
			t1=t2;
			t2=t;
			step--;
		}
		printf("%lld\n",t);
	}
	return 0;
}

