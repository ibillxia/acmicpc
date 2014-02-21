/**************************************************************
	Problem: 1011  第87699号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:20 ms
	Memory:908 kb
****************************************************************/
#include<stdio.h>
int main()
{
	int k,d[10000];
	int i,j,sum,max,st,end,cnt;
	while(1){
		scanf("%d",&k);
		if(k==0)break;
		for(i=0;i<k;i++,getchar())
			scanf("%d",d+i);
		cnt=0;
		for(i=0;i<k;i++)
			if(d[i]<0) cnt++;
			else break;
		if(cnt==k){
			printf("%d %d %d\n",0,d[0],d[k-1]);
			continue;
		}
		st=end=j=sum=0;
		max=d[0];
		for(i=0;i<k;i++){
			j=sum>0 ? j:i;
			sum = sum>0 ? sum : 0;
			sum+=d[i];
			if(sum>max){
				max=sum;
				st=j;
				end=i;
			}	
		}
		printf("%d %d %d\n",max,d[st],d[end]);
	}
	return 0;
}
