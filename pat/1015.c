//file: 1015.c
//author: ibillxia
//ac: 2012年3月18日 星期日 19:18:39 HKT

#include <stdio.h>

int n,r,d[20];

int isprime(int num){
	int i;
	if(num==1)return 0; //注意这两句不能少，
	if(num==2)return 1; //否则部分测试通不过
	if(!(num%2))return 0;
	for(i=3;i*i<=num;i+=2)
		if(!(num%i))return 0;
	return 1;
}

int main()
{
	int i,k;
	while(scanf("%d",&n)&&n>=0){
		scanf(" %d",&r);
		if(!isprime(n)){printf("No\n");continue;}
		i=0;
		while(n){d[i++]=n%r;n/=r;}
		k=i;n=i=0;
		while(i<k)n=n*r+d[i++];
		if(!isprime(n))printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}