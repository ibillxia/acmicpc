/**************************************************************
    Problem: 1547  第719602号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:50 ms
    Memory:916 kb
****************************************************************/
#include <stdio.h>
#define MOD 1000000007
long long _dc[510];
void cantalan();

int main()
{
    int n;
    cantalan();
    while(~scanf("%d",&n)){
        if(n&1) printf("0\n");
        else printf("%lld\n",_dc[n/2]);
    }
    return 0;
}

void cantalan(){
    int i,j;
    long long k;
    _dc[0]=_dc[1]=1;
    for(i=2;i<=500;i++){
        _dc[i]=0;
        for(j=0;j<i;j++){
            _dc[i] += _dc[j]*_dc[i-j-1]%MOD;
            _dc[i] %= MOD;
        }
    }
}
