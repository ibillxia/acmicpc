/**************************************************************
	Problem: 1087  第189119号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:50 ms
	Memory:936 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
long long n,d,t,cnt,p[3410]={2,3,5,7,11,13,17,19,23,29};
void prime(){
	long long i,j,k;
	k=10;
	for(i=31;i<=31623;i+=2){
		for(j=0;p[j]*p[j]<=i;j++)
			if(!(i%p[j]))break;
		if(p[j]*p[j]>i)p[k++]=i;
	}
}
int main()
{
	long long i,k;
	prime();
	while(scanf("%lld",&n)!=EOF){
		if(n==0)break;
		while(n--){
			scanf("%lld",&d);
			cnt=1;
			for(i=0;d!=1&&p[i]*p[i]<=d;i++){
				k=1;
				while(!(d%p[i])){k++;d/=p[i];}
				cnt*=k;
			}
			if(d!=1)cnt*=2;
			printf("%lld\n",cnt);
		}
	}
	return 0;
}
