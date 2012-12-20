//run id 2980963	2012-07-27 22:06:56	 Accepted
#include <stdio.h>
#include <string.h>

char s[1000000];
int m,n;

int main()
{
    int i;
    while(1) {
        scanf("%s",s);
        n=strlen(s);
        m=0;
        for(i=0; i<n; i++)m+=s[i]-'0';
        if(m==0)break;
        while(m>9) {
            n=0;
            while(m) {
                n+=m%10;
                m/=10;
            }
            m=n;
        }
        printf("%d\n",m);
    }
    return 0;
}
