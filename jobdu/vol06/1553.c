/**************************************************************
    Problem: 1553  第821593号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:912 kb
****************************************************************/
#include <stdio.h>
int h,m;
float a;
int main()
{
    while(~scanf("%d:%d",&h,&m)){
        a=((h%12)*30.0+m/2.0)-m*6.0;
        if(a<0.0)a=-a;
        if(a>180.0)a=360.0-a;
        printf("%.2f\n",a);
    }
    return 0;
}
 
