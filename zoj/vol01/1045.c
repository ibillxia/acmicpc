//2984409	2012-07-29 19:14:23	 Accepted
#include <stdio.h>
int n;
double t,s;
int main()
{
    while(scanf("%lf",&t)) {
        if(t<1e-3)break;
        s=0.0;
        n=2;
        while(s<t) {
            s+=1.0/n;
            n++;
        }
        printf("%d card(s)\n",n-2);
    }
    return 0;
}
