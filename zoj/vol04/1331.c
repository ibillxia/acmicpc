//3025466	2012-08-18 20:39:41	 Accepted
#include <stdio.h>

int main()
{
    int i,j,k,t;
    int a,b,c,d;
    for(i=6; i<=200; i++) {
        a=i*i*i;
        for(j=2; j<i-2; j++) {
            b=j*j*j;
            if(b>a/3)break;
            for(k=j+1; k<i-1; k++) {
                c=k*k*k;
                if(b+c>a*2/3)break;
                d=a-b-c;
                for(t=k+1; t*t*t<d; t++);
                d=t*t*t;
                if(a==b+c+d)
                    printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,t);
            }
        }
    }
    return 0;
}
