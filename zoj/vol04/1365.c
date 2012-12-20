//run id 3049922	2012-09-08 19:18:29
#include <stdio.h>
char s[200],*p,c;
int m,t;
int main()
{
    t = 0;
    while(gets(s)) {
        if(s[0]=='#')break;
        if(s[0]=='0') {
            printf("%d\n",t);
            t = 0;
            continue;
        }
        p=s;
        while(*p!=' ')p++;
        p++;
        while(*p!=' ')p++;
        m=0;
        p++;
        while(*p!=' ') {
            m=m*10+*p-'0';
            p++;
        }
        p++;
        c=*p;
        switch(c) {
            case 'F':
                t += m*2;
                break;
            case 'B':
                t += m+(m+1)/2;
                break;
            case 'Y':
                if(m<500)t += 500;
                else t += m;
                break;
        }
    }
    return 0;
}
