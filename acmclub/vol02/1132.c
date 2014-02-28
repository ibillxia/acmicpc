/**************************************************************
** Problem: 1132 动态规划 - 最长公共子序列
** 算法导论15.4节
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
#include <string.h>
#define M 101
#define MAX(a,b) ((a)>(b)?(a):(b))
int _d[M][M];
char a[M],b[M];
int lcs(char*,char*);

int main()
{
    while(~scanf("%s%s",a,b))
        printf("%d\n",lcs(a,b));
    return 0;
}

int lcs(char* a,char* b){
    char *p,*q;
    memset(_d,0,sizeof(_d));
    if(*a==*b)_d[0][0]=1;
    p=a+1;
    while(*p){
        if(*p==*b)_d[p-a][0]=1;
        else _d[p-a][0]=_d[p-a-1][0];
        p++;
    }
    q=b+1;
    while(*q){
        if(*q==*a)_d[0][q-b]=1;
        else _d[0][q-b]=_d[0][q-b-1];
        q++;
    }

    p=a+1;
    while(*p){
        q=b+1;
        while(*q){
            if(*p==*q)_d[p-a][q-b]=_d[p-a-1][q-b-1]+1;
            else _d[p-a][q-b]=MAX(_d[p-a][q-b-1],_d[p-a-1][q-b]);
            q++;
        }
        p++;
    }
    return _d[p-1-a][q-1-b];
}
