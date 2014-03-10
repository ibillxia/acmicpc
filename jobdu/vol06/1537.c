/**************************************************************
    Problem: 1537  第787580号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:80 ms
    Memory:4832 kb
****************************************************************/
#include <stdio.h>
#include <string.h>
#define N 1001
#define MAX(a,b) ((a)>(b) ? (a):(b))
int d[N];
int dp[N][N];
int max_gain(int*,int,int);

int main()
{
    int i,n,k;
    while(~scanf("%d %d",&n,&k)){
        for(i=0;i<n;i++)scanf("%d",d+i);
        printf("%d\n",max_gain(d,n,k));
    }
    return 0;
}


int max_gain(int* d,int n,int k)
{
    int i,j,t,m;
    if(n<2)return 0;
    memset(dp,0,sizeof(dp));
    t=0x7fffffff;m=0;
    for(i=0;i<k;i++){
        t=dp[i][0]-d[0];
        for(j=1;j<n;j++){
            dp[i+1][j]=MAX(dp[i+1][j-1],t+d[j]);
            t=MAX(t,dp[i][j]-d[j]);
            m=MAX(m,dp[i+1][j]);
        }
    }
    return m;
}
