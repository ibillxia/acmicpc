/**************************************************************
	Problem: 1033  第150285号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:912 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
int n,a[510];
char b[1002];
int main()
{
	int i,t;
	while(scanf("%d",&n)!=EOF){
		if(n==0)continue;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)scanf("%d",a+i);
		for(i=0;i<n;i++){
			t=a[i];
			if(t==1||b[t])continue;
			while(t!=1){
				if(t%2)t=(3*t+1)>>1;
				else t=t>>1;
				if(t<1002)b[t]=1;
			}
		}
		i--;t=0;
		while(i>=0){
			if(t && !b[a[i]])printf(" ");
			if(!b[a[i]]){printf("%d",a[i]);t=1;}
			i--;
		}
		if(t)printf("\n");
	}
	return 0;
}
