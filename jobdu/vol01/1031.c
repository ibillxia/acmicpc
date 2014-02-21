/**************************************************************
	Problem: 1031  第150229号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:904 kb
****************************************************************/
#include <stdio.h>
int main()
{
	int n,cnt;
	while(scanf("%d",&n)&&n!=0){
		if(n==1){printf("0\n");continue;}
		cnt=0;
		while(n!=1){
			if(n%2)n=(3*n+1)>>1;
			else n=n>>1;
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
