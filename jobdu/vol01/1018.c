/**************************************************************
	Problem: 1018  第93918号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
int n,d[1001],t,cnt;
int main()
{
	int i;
	while(1){
		scanf("%d",&n);
		if(0==n)break;
		for(i=0;i<n;i++)
			scanf("%d",d+i);
		scanf("%d",&t);
		cnt=0;
		for(i=0;i<n;i++)
			if(d[i]==t)cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
