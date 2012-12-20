//run id:3054588	2012-09-14 23:01:58
#include <stdio.h>
int t,n,p;
int main()
{
    int i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        p=i=0;
        while(n)
        {
            if(n%2)
            {
                if(!i)
                {
                    printf("%d",p);
                    i=1;
                }
                else printf(" %d",p);
            }
            n=n>>1;
            p++;
        }
        printf("\n");
    }
    return 0;
}
