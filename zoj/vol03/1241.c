//run id 3007037	2012-08-07 19:13:47	 Accepted
#include <stdio.h>
#include <math.h>
int a,b,c;
int main()
{
    int i;
    i=1;
    while(scanf("%d%d%d",&a,&b,&c)) {
        if(a==0&&b==0&&c==0)break;
        printf("Triangle #%d\n",i);
        if(a==-1&&c*c-b*b>0)
            printf("a = %.3lf",sqrt((c*c-b*b)*1.0));
        else if(b==-1&&c*c-a*a>0)
            printf("b = %.3lf",sqrt((c*c-a*a)*1.0));
        else if(c==-1)
            printf("c = %.3lf",sqrt((a*a+b*b)*1.0));
        else printf("Impossible.");
        printf("\n\n");
        i++;
    }
    return 0;
}
