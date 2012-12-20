//runid 2974935	2012-07-24 20:40:57	 Accepted
#include <stdio.h>
#define PI 3.1415926

int t;
double x,y;

int main()
{

    int i,n;
    double area;
    scanf("%d",&t);
    i=1;
    while(i<=t) {
        scanf("%lf%lf",&x,&y);
        area = (x*x+y*y)*PI/2;
        n = (int)((area+49.999999)/50.0);
        printf("Property %d: This property will begin eroding in year %d.\n",i,n);
        i++;
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
