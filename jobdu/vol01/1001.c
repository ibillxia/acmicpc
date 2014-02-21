/**************************************************************
	Problem: 1001  第122451号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:80 ms
	Memory:912 kb
****************************************************************/
#include <stdio.h>
int m,n,a[10][10],b[10][10];
int main()
{
	int i,j,cnt;
	while(scanf("%d",&m)&&m>0){
		scanf("%d",&n);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",a[i]+j);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++){
				scanf("%d",b[i]+j);
				a[i][j]+=b[i][j];
			}
		cnt=0;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				if(a[i][j])break;
			if(j==n)cnt++;
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				if(a[j][i])break;
			if(j==m)cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
