#include <stdio.h>

int main(){
    int n,u,d,t;
    while(scanf("%d%d%d",&n,&u,&d)){
        if(!n) break;
        t=0;
        while(1){
            n -= u;
            t++;
            if(n>0){
                n+= d;
                t++;
            }else break;
        }
        printf("%d\n",t);
    }
    return 0;
}
