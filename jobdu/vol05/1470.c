/**************************************************************
    Problem: 1470  第740847号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:912 kb
****************************************************************/
#include <stdio.h>
int n,d[11][11];
int main()
{
    int i,j,k;
    int max,maxj;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&d[i][j]);
        for(i=0;i<n;i++){
            max=d[i][i];maxj=i;
            for(j=i+1;j<n;j++){
                if(d[j][i]>max){max=d[j][i];maxj=j;}
            }
            if(maxj!=i){
                for(k=0;k<n;k++){
                    d[i][k]=d[i][k]+d[maxj][k];
                    d[maxj][k]=d[i][k]-d[maxj][k];
                    d[i][k]=d[i][k]-d[maxj][k];
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++)
                printf("%d ",d[i][j]);
            printf("%d\n",d[i][j]);
        }
    }
    return 0;
}
