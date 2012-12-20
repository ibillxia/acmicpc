#include <stdio.h>
#include <memory.h>

int main(){
    int d[32],n,m,t;
    char s[64],*p;
    while(scanf("%d",&n)){
        if(!n)break;
        getchar();
        gets(s);
        memset(d,0,sizeof(d));
        p = s;
        m=t=0;
        while(*p){
            if(!d[*p-'A']){
                d[*p-'A'] = 1;
                t++;
                if(t>n) m++;
            } else {
                d[*p-'A'] = 0;
                t--;
            }
            p++;
        }
        if(m>0) printf("%d customer(s) walked away.\n",m);
        else printf("All customers tanned successfully.\n");
    }
    return 0;
}
