/**************************************************************
    Problem: 1554  第822799号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:850 ms
    Memory:952 kb
****************************************************************/
#include <stdio.h>
#define M 10000
int n,k,s,e;
int d[M];
int find(int*,int,int);
int main()
{
    int i,r;
    int t1,t2,max,min;
    while(~scanf("%d",&n)){
        t1=t2=max=min=0;
        for(i=0;i<n;i++){
            scanf("%d",d+i);
            if(t1>0)t1+=d[i];
            else t1=d[i];
            if(t1>max)max=t1;
 
            if(t2<0)t2+=d[i];
            else t2=d[i];
            if(t2<min)min=t2;
        }
        scanf("%d",&k);
        if(k>max||k<min){puts("No");continue;}
        r = find(d,n,k);
        if(!r)puts("No");
        else printf("%d %d\n",s,e);
    }
    return 0;
}
 
int find(int* d,int n,int k){
    int i,j,t;
 
    for(i=0;i<n;i++){
        t=0;
        for(j=i;j<n;j++){
            t+=d[j];
            if(t==k){
                s=i+1;
                e=j+1;
                return 1;
            }
        }
    }
    return 0;
}
