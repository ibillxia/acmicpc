//run id 2996049	2012-08-02 21:47:17	 Accepted
#include <stdio.h>
#include <math.h>

int t;
double vs,r,c,w,vr;

int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%lf%lf%lf%d",&vs,&r,&c,&t)) {
        while(t--) {
            scanf("%lf",&w);
            printf("%.3f\n",r*vs*w*c/sqrt(w*w*c*c*r*r+1.0));
        }
    }
    return 0;
}
