/**************************************************************
	Problem: 1015  第93892号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:904 kb
****************************************************************/
#include <stdio.h>
#include <string.h>
int main()
{
    int a,b,k,t;
    while(1){
        scanf("%d %d %d",&a,&b,&k);
        if(a==0&&b==0) return 0;
        t=1;
        while(k--)t*=10;
        if(a%t==b%t)printf("%d\n",-1);
        else printf("%d\n",a+b);
    }
}
