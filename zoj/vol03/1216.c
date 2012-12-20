//run id 3005087	2012-08-06 21:25:15	 Accepted
#include <stdio.h>

int main()
{
    int i,n;
    double s;
    printf("# Cards  Overhang\n");
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        s=0;
        for(i=1; i<=n; i++)
            s+=1.0/(2*i);
        printf("%5d     %.3f\n",n,s);
    }
    return 0;
}
