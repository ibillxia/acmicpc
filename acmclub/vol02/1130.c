/**************************************************************
** Problem: 1130 动态规划 - 拔河
** 算法导论第15章
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
#include <string.h>
#define M 22510
char _dp[M][51];
void bahe(int*,int,int*,int*);

int main(){
    int i,n,w[100],a,b;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++) scanf("%d",w+i);
        bahe(w,n,&a,&b);
        printf("%d %d\n",a,b);
    }
    return 0;
}

void bahe(int* w,int len,int* a,int* b){
    int i,j,k,sum;
    if(len==2){
        if(w[0]<w[1]){*a=w[0];*b=w[1];}
        else {*a=w[1];*b=w[0];}
        return;
    }

    for(i=sum=0;i<len;i++) sum += w[i];
    *a = sum/2;
    memset(_dp,0,sizeof(_dp));
    _dp[0][0]=1;
    for(i=0;i<len;i++)
        for(j=*a;j>=w[i];j--)
            for(k=0;k<=len/2;k++)
                if(_dp[j-w[i]][k])_dp[j][k+1]=1;//DP
    k=len>>1;
    if(len&1){
        for(i=*a;i>0;i--)
            if(_dp[i][k+1]||_dp[i][k])break;
    }else{
        for(i=*a;i>0;i--)
            if(_dp[i][k])break;
    }
    *a=i;
    *b=sum-i;
    return;
}
