/**************************************************************
	Problem: 1004  第123342号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:16536 kb
****************************************************************/
#include <stdio.h>
long m,n,a[1000000],b[1000000];
int main()
{
	int i,j,k,t,mid;
	while(scanf("%d",&m)!=EOF){
		for(i=0;i<m;i++)scanf("%d",a+i);
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",b+i);
		i=j=k=0;t=(m+n+1)/2;
		while(i<m&&j<n&&k<t){
			if(a[i]>b[j]){mid=b[j];j++;}
			else {mid=a[i];i++;}
			k++;
		}
		if(i==m&&k<t){
			while(k<t){j++;k++;}
			mid=b[j-1];
		}else if(j==n&&k<t){
			while(k<t){i++;k++;}
			mid=a[i-1];
		}
		printf("%d\n",mid);
	}
	return 0;
}
