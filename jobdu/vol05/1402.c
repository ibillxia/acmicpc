/**************************************************************
	Problem: 1402  第148687号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:1850 ms
	Memory:1884 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
char d[1000000];
int main()
{
	int i,j,n,t;
	while(scanf("%d",&n)!=EOF){
		memset(d,0,sizeof(d));
		for(i=0;i<n;i++){
			scanf("%d",&t);
			if(d[t-1]<3)d[t-1]++;
		}
		j=0;
		for(i=0;i<1000000;i++)
			if(d[i]==1)j++;
		printf("%d\n",j);
		n=j;
		for(i=0;i<1000000,j>0;i++)
			if(d[i]==1){
				printf("%d",i+1);j--;
				if(j>0)printf(" ");
			}
		if(n>0)printf("\n");
	}
	return 0;
}
