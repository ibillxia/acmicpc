/**************************************************************
    Problem: 1549  第740960号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:20 ms
    Memory:912 kb
****************************************************************/
#include <stdio.h>
long long n;
int main(){
    int cnt;
    while(~scanf("%lld",&n)){
        cnt=0;
        if(n>=100){cnt+=n/100;n=n%100;}
        if(n>=50){cnt+=n/50;n=n%50;}
        if(n>=20){cnt+=n/20;n=n%20;}
        if(n>=10){cnt+=n/10;n=n%10;}
        if(n>=5){cnt+=n/5;n=n%5;}
        if(n>=2){cnt+=n/2;n=n%2;}
        cnt+=n;
        printf("%d\n",cnt);
    }
}
