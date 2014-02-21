/**************************************************************
	Problem: 1016  第93907号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include<stdio.h>
int d[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int main()
{
    int a[25],b[25],c[26],al,bl,t;
    while(1){
        al=bl=0;
        while(scanf("%d",a+al++)&&getchar()!=' ');
        while(scanf("%d",b+bl++)&&getchar()==',');    
        if(a[0]==0&&b[0]==0)break;
        else{
            t=0;c[0]=0;
            while(al>0&&bl>0){
                c[t+1]=(a[al-1]+b[bl-1]+c[t])/d[t];
                c[t]=(a[al-1]+b[bl-1]+c[t])%d[t];
                al--;bl--;t++;
            } 
            while(al>0){
                c[t+1]=(a[al-1]+c[t])/d[t];
                c[t]=(a[al-1]+c[t])%d[t];
                al--;t++;
            }
            while(bl>0){
                c[t+1]=(b[bl-1]+c[t])/d[t];
                c[t]=(b[bl-1]+c[t])%d[t];
                bl--;t++;
            }
            if(c[t]==0) t--;
            while(t>0)
                printf("%d,",c[t--]);
            printf("%d\n",c[t]);
        }
    }
    return 0;
}
