//run id 2980940	2012-07-27 21:51:09	 Accepted
//注意：ZOJ的C不能用//来注释
//另外多次提交错误，主要是题目的输入输出要求没看清，⊙﹏⊙b汗
#include <stdio.h>

int d[16],m[20][20],n[20][20];
char s[]=".!X#";

int main()
{
    int i,j,k,t,a,c;
    //freopen("in.txt","r",stdin);
    scanf("%d",&c);
    while(c--) {
        scanf("%d",&t);
        for(i=0; i<16; i++)
            scanf("%d",d+i);
        for(i=0; i<20; i++)
            for(j=0; j<20; j++)
                scanf("%d",m[i]+j);
        for(i=0; i<t; i++) {
            for(j=0; j<20; j++) {
                for(k=0; k<20; k++) {
                    a=m[j][k];
                    if(j>0)a+=m[j-1][k];
                    if(j<19)a+=m[j+1][k];
                    if(k>0)a+=m[j][k-1];
                    if(k<19)a+=m[j][k+1];
                    n[j][k]=m[j][k]+d[a];
                    if(n[j][k]>3)n[j][k]=3;
                    if(n[j][k]<0)n[j][k]=0;
                }
            }
            for(j=0; j<20; j++)
                for(k=0; k<20; k++)
                    m[j][k]=n[j][k];
        }
        for(i=0; i<20; i++) {
            for(j=0; j<19; j++)
                printf("%c",s[m[i][j]]);
            printf("%c\n",s[m[i][j]]);
        }
        if(c)printf("\n");
    }
    return 0;
}
