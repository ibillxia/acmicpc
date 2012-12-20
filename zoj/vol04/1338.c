//run id:3030632	2012-08-24 10:11:38	 Accepted
#include <stdio.h>
int d[30],n,uc,un,dc,dn;
double up,dw;
int main()
{
    int i,k,t,tt;
    while(1) {
        scanf("%d",&t);
        if(!t)return 0;
        d[0]=t;
        i=1;
        while(1) {
            scanf("%d",&t);
            if(!t)break;
            d[i++]=t;
        }
        n=i;
        if(n==1) {
            up=dw=0.0;
            printf("Nr values = %d:  %.6lf %.6lf\n",n,up,dw);
            continue;
        }
        uc=dc=un=dn=k=t=tt=0;
        for(i=1; i<n; i++) {
            if(d[i-1]<d[i]) {
                if(t==3) {
                    if(tt==2) {
                        dc+=k;
                        dn++;
                    } else uc+=k;
                } else if(t==2)dn++;
                uc++;
                t=1;
                k=0;
                tt=1;
            } else if(d[i-1]>d[i]) {
                if(t==3) {
                    if(tt==1) {
                        uc+=k;
                        un++;
                    } else dc+=k;
                } else if(t==1)un++;
                dc++;
                t=2;
                k=0;
                tt=2;
            } else {
                k++;
                t=3;
            }
        }
        if(t==1)un++;
        if(t==2)dn++;
        if(t==3) {
            if(tt==1) {
                uc+=k;
                un++;
            }
            if(tt==2) {
                dc+=k;
                dn++;
            }
        }
        if(!un)un=1;
        if(!dn)dn=1;
        up = uc*1.0/un;
        dw = dc*1.0/dn;
        printf("Nr values = %d:  %.6lf %.6lf\n",n,up,dw);
    }
    return 0;
}
