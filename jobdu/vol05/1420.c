/**************************************************************
	Problem: 1420  第190458号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:1110 ms
	Memory:5788 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
int wt[110];
char dp[5000100];
int main()
{
	int i,j,n,sum,max,min;
	//freopen("ind.txt","r",stdin);
	//freopen("outd.txt","w",stdout);
	while(scanf("%d",&n)!=EOF){
		sum=0;memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++){
			scanf("%d",wt+i);
			sum+=wt[i];
			//dp[wt[i]]=1;
		}
		max=sum/2;dp[0]=1;
		for(i=0;i<n;i++)
			for(j=max;j>=wt[i];j--)
				if(dp[j-wt[i]])dp[j]=1;
		for(i=max;i>0;i--)
			if(dp[i])break;
		min=sum-2*i;
		printf("%d\n",min);
	}
	return 0;
}
