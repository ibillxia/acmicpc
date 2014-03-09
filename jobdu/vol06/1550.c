/**************************************************************
    Problem: 1550  第744198号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:70 ms
    Memory:1696 kb
****************************************************************/
#include <stdio.h>
#define M 100000
int n,s[M],t[M];
long long m;
void cal(int*,int,int*);
int main()
{
    int i;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)scanf("%d",s+i);
        cal(s,n,t);
        m=0;
        for(i=0;i<n;i++) m+=t[i];
        printf("%lld\n",m);
    }
    return 0;
}

void cal(int* s,int n,int* t){
    int i,j,l,r;

    for(i=0;i<n;i++){
        l=r=1;
        //left
        if(i&&s[i]>s[i-1])l=t[i-1]+1;
        //right
        for(j=1;j<n-i;j++){
            if(s[i+j-1]>s[i+j])r++;
            else break;
        }
        t[i]=l>r?l:r;
    }
}
