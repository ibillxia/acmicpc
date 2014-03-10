/**************************************************************
    Problem: 1552  第787881号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:920 kb
****************************************************************/
#include <stdio.h>
#define M 1000000007
void cal(int);
long d[1001];
int main()
{
    int n;
    cal(1000);
    while(~scanf("%d",&n)){
        printf("%ld\n",d[n]);
    }
    return 0;
}

void cal(int n)
{
    int i;
    d[1]=1;d[2]=2;d[3]=4;d[4]=7;
    for(i=5;i<=n;i++)
        d[i]=(d[i-1]+d[i-2]+d[i-4])%M;
}
