//2012-07-10 20:05:59	 Accepted
//PE 2 times
#include <stdio.h>
int t,m,n;
float s;
int main()
{
    int i;
    scanf("%d",&t);
    i=0;
    while(i<t) {
        scanf("%d%d",&m,&n);
        i++;
        printf("Scenario #%d:\n",i);
        s=m=m*n;
        if(m%2)printf("%0.2f\n\n",s+0.41);
        else printf("%0.2f\n\n",s);
    }
    return 0;
}
