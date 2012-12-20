//run id 3009495	2012-08-08 21:16:54	 Accepted
#include <stdio.h>
int n,d[52];
int main()
{
    int i,j,s,a,m;
    i=1;
    while(scanf("%d",&n)) {
        if(n==0)break;
        s=m=0;
        for(j=0; j<n; j++) {
            scanf("%d",d+j);
            s+=d[j];
        }
        a=s/n;
        for(j=0; j<n; j++)
            if(d[j]>a)m+=d[j]-a;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",i,m);
        i++;
    }
    return 0;
}
