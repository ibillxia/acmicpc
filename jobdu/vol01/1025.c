/**************************************************************
	Problem: 1025  第142612号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
#define PRE 0.000001
int main()
{
	char tp;
	int i,j,n,m,cnt,flag;
	double t,q,sum[30],max,sumij[30][30];
	while(scanf("%lf %d",&q,&n)&&n!=0){
		max=cnt=0;
		for(i=0;i<n;i++){
			sum[cnt]=flag=0;
			scanf("%d",&m);
			while(m--){
				scanf(" %c:%lf",&tp,&t);
				if(flag)continue;
				tp=tp-'A';
				if(tp>=0&&tp<3){
					sum[cnt]+=t;
					if((t-600.0)>PRE || (sum[cnt]-1000.0)>PRE)flag=1;
				}else flag=1;
			}
			if(flag||sum[cnt]>q)continue;
			cnt++;
		}
		max=0;
		for(i=0;i<cnt;i++){
			if(sum[i]>q)continue;
			sumij[i][i]=sum[i];
			for(j=i+1;j<cnt;j++)
				if(sumij[i][j-1]+sum[j]<=q)sumij[i][j]=sumij[i][j-1]+sum[j];
				else sumij[i][j]=sumij[i][j-1];
			if(sumij[i][j-1]>max)max=sumij[i][j-1];
		}
		printf("%.2f\n",max);
	}
	return 0;
}
