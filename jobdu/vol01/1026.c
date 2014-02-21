/**************************************************************
	Problem: 1026  第144054号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:904 kb
****************************************************************/
#include <stdio.h>
char out[34];
unsigned int m,a,b;
int main()
{
    int i;
    while(scanf("%d",&m)&&m!=0){
        scanf("%d %d",&a,&b);
        a+=b;
        if(a==0){printf("0\n");continue;}
        i=0;
        while(a){
            out[i++]=a%m;
            a/=m;
        }
        while(i)
            printf("%d",out[--i]);
        printf("\n");
    }
    return 0;
}
