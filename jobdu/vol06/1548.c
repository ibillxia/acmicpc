/**************************************************************
    Problem: 1548  第722607号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:30 ms
    Memory:912 kb
****************************************************************/
#include <stdio.h>
#include <math.h>
#define M 1.0e-8
typedef struct p2d{
    double x,y;
    int n;
}p2,*P2;

int max_points(P2,int);

int main()
{
    int i,n;
    p2 pts[110];
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            scanf("%lf %lf",&pts[i].x,&pts[i].y);
            pts[i].n=1;
        }
        printf("%d\n",max_points(pts,n));
    }
    return 0;
}

int max_points(P2 p,int n){
    int i,j,k,t,max;
    if(n<=2) return n;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(fabs(p[i].x-p[j].x)<M && fabs(p[i].y-p[j].y)<M){ //检查重复的点
                p[j].x=p[n-1].x;
                p[j].y=p[n-1].y;
                p[i].n++;
                j--;n--;
            }
    if(n==1)return p[0].n;
    if(n==2)return p[0].n+p[1].n;
    max = 2;
    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++){
            t=p[i].n+p[j].n;
            for(k=j+1;k<n;k++)
                if(fabs((p[j].y-p[i].y)*(p[k].x-p[i].x)-(p[k].y-p[i].y)*(p[j].x-p[i].x))<M)t+=p[k].n;
            if(t>max) max=t;
        }
    return max;
}
