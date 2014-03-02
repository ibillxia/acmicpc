/**************************************************************
    Problem: 1493  第742034号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:20 ms
    Memory:928 kb
****************************************************************/
#include <stdio.h>
#include <math.h>

long long m,n;
long long gcd(long long,long long);

int main()
{
    int cnt,i,k;
    long long t;
    while(~scanf("%lld%lld",&m,&n)){
        t=gcd(m,n);
        if(t>1){
            k=(int)sqrt(t);
            cnt=2;
            for(i=2;i<=k;i++){
                if(t%i==0)cnt+=2;
            }
            if(k*k==t)cnt--;
        } else cnt=1;
        printf("%d\n",cnt);
    }
}

long long gcd(long long m,long long n){
    long long t;
    while(n>0){
        t=m%n;
        m=n;
        n=t;
    }
    return m;
}
