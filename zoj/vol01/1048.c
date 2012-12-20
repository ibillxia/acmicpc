//2012-07-10 20:37:15	 Accepted
//WA 1 time,becuase I forget to print $ before the data
#include <stdio.h>
float d,a;
int main()
{
    int i;
    while(~scanf("%f",&d)) {
        a=d;
        for(i=0; i<11; i++) {
            scanf("%f",&d);
            a+=d;
        }
        printf("$%.2f\n",a/12);
    }
    return 0;
}
