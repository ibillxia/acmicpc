//file: 1024.c
//author: ibillxia
//ac: 2012年3月18日 星期日 20:54:07 HKT

#include <stdio.h>
#include <string.h>
#include <memory.h>
#define N 100
char st[N],rv[N],sum[N];

int main()
{
	int i,j,k,t,len,cnt;
	scanf("%s %d",st,&k);
	cnt=0;
	while(cnt<k){
		len=strlen(st);
		for(i=0,j=len-1;i<j;i++,j--)
			if(st[i]!=st[j])break;
		if(i>=j)break;
		for(i=0;i<len;i++) rv[i]=st[len-1-i];
		memset(sum,0,sizeof(sum));
		for(i=len-1;i>=0;i--){
			t=sum[i+1]+st[i]+rv[i]-96;
			sum[i]=t/10;
			sum[i+1]=t%10+'0';
		}
		if(sum[0]){sum[0]+='0';strcpy(st,sum);}
		else for(i=1;i<=len;i++)st[i-1]=sum[i];
		cnt++;
	}
	printf("%s\n%d\n",st,cnt);
	return 0;
}