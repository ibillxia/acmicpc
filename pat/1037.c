//file: 1037.c
//author: ibillxia
//ac: 2012年9月07日 星期五 00:47:52 HKT
//run id: 63878

#include <stdio.h>
#include <stdlib.h>
int nc,np,dc[100010],dp[100010];
long long max;
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int i,j;
    scanf("%d",&nc);
    for(i=0; i<nc; i++)scanf("%d",dc+i);
    scanf("%d",&np);
    for(i=0; i<np; i++)scanf("%d",dp+i);
    qsort(dc,nc,sizeof(int),cmp);
    qsort(dp,np,sizeof(int),cmp);
    max=i=0;
    while(i<nc&&i<np&&dc[i]<0&&dp[i]<0)
    {
        max+=dc[i]*dp[i];
        i++;
    }
    i=nc-1;
    j=np-1;
    while(i>=0&&j>=0&&dc[i]>0&&dp[j]>0)
    {
        max+=dc[i]*dp[j];
        i--;
        j--;
    }
    printf("%lld\n",max);
    return 0;
}
