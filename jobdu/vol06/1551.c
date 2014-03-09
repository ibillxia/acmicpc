/**************************************************************
    Problem: 1551  第780526号提交
    User: 天勤
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1100 kb
****************************************************************/
#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int R;
double r;

int main()
{
    double a,b,c,t;
    while(~scanf("%d %lf",&R,&r)){
        c=0.0;b=2.0*R;
        r=r/(1+r)*PI*R*R;
        while(b-c>0.00001){
            a=(b+c)/2.0;
            t=asin(a/2.0/R)*R*R-a/2*sqrt(R*R-a*a/4.0);
            if(t-r>0.00001)b=a;
            else c=a;
        }
        printf("%.2lf\n",a);
    }
}
