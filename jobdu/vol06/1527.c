/**************************************************************
    Problem: 1527  第780708号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:70 ms
    Memory:1304 kb
****************************************************************/
#include <stdio.h>
#define N 100000
int d[N];
int max_sum(int*,int);
int main()
{
    int i,n;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)
            scanf("%d",d+i);
        printf("%d\n",max_sum(d,n));
    }
    return 0;
}

int max_sum(int* d,int n)
{
    int i,t,t1,t2,max,min;
    t=t1=t2=max=min=0;
    for(i=0;i<n;i++){
        t+=d[i];
        if(t1>0)t1+=d[i];
        else t1=d[i];
        if(t1>max)max=t1;

        if(t2<0)t2+=d[i];
        else t2=d[i];
        if(t2<min)min=t2;
    }

    return max>(t-min) ? max : (t-min);
}


