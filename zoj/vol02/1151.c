//run id 2982750	2012-07-28 22:00:09	 Accepted
#include <stdio.h>

char s[1000000],t[10000];
int m,n;

int main()
{
    char *p,*q,*r;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&m);
    while(m--) {
        scanf("%d",&n);
        getchar();
        while(n--) {
            gets(s);
            p=q=s;
            while(*q) {
                if(*q==' ') {
                    if(p!=q) {
                        for(r=q-1; r>=p; r--)printf("%c",*r);
                        p=q+1;
                    }
                    putchar(' ');
                }
                q++;
            }
            if(p!=q) {
                for(r=q-1; r>=p; r--)printf("%c",*r);
            }
            putchar('\n');
        }
        if(m>0)putchar('\n');
    }
    return 0;
}
