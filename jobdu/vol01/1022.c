/**************************************************************
	Problem: 1022  第109943号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:912 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
int d[101],f[101];
int main()
{
    char ch;
    int n,t1,t2,cnt,sum;
    cnt=sum=0;
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    while(scanf("%d",&n) && n!=-1){
        if(n==0){
            scanf(" %c %d:%d",&ch,&t1,&t2);
            if(cnt==0)printf("0 0\n");
            else printf("%d %d\n",cnt,(int)(sum*1.0/cnt+0.5));
            cnt=sum=0;
            memset(d,0,sizeof(d));
            memset(f,0,sizeof(f));
        }else{
            scanf(" %c %d:%d",&ch,&t1,&t2);
            if(ch=='S'){d[n]=t1*60+t2;f[n]=1;}
            else if(f[n]){
                sum+=t1*60+t2-d[n];
                cnt++;
                f[n]=0;
            }
        }
    }
    return 0;
}
