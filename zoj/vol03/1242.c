//run id 3007148	2012-08-07 20:11:48	 Accepted
#include <stdio.h>
#include <math.h>
int w,d,y;
double t;
int main()
{
    int i=1;
    while(scanf("%d%d",&w,&d)) {
        if(w==0&&d==0)break;
        t=log(810.0*w/d)/log(2)*5730;
        printf("Sample #%d\n",i);
        if(t<10000)printf("The approximate age is %d years.\n\n",((int)(t/100.0+0.5))*100);
        else printf("The approximate age is %d years.\n\n",((int)(t/1000.0+0.5))*1000);
        i++;
    }
    return 0;
}
