/**************************************************************
	Problem: 1034  第150322号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:30 ms
	Memory:1300 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
int m,n,a[100002],b[10];
int main()
{
	int i,j,k;
	while(scanf("%d %d",&n,&m)){
		if(m==0&&n==0)break;
		for(i=0;i<n;i++)scanf("%d",a+i);
		memset(b,0,sizeof(b));
		if(m>n)m=n;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				if(a[i]>=b[j]){
					for(k=m-1;k>j;k--)b[k]=b[k-1];
					b[j]=a[i];
					break;
				}
		}
		for(i=0;i<m-1;i++)
			printf("%d ",b[i]);
		printf("%d\n",b[i]);
	}
	return 0;
}
