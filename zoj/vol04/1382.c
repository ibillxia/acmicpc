//run id:3054578	2012-09-14 22:50:14
#include <stdio.h>
int t,n,p;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        p=0;
        while(!(n%2))
        {
            n=n>>1;
            p++;
        }
        printf("%d %d\n",n,p);
    }
    return 0;
}
