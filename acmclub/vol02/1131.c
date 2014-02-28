/**************************************************************
** Problem: 1131 动态规划 - 分梨
** 算法导论第15章
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
#define M 1000
int dp(int,int);

int main()
{
    int t,m,n;
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%d%d",&m,&n);
            printf("%d\n",dp(m,n));
        }
    }
    return 0;
}

int dp(int m,int n){
    if(!m||!n||m==1||n==1)return 1;
    if(m<n)return dp(m,m);
    return dp(m,n-1)+dp(m-n,n);
}

