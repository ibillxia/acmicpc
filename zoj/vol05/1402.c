#include <stdio.h>

int n,d[32];

int main(){
    int t,i;
    while(scanf("%d",&n)){
        if(!n)break;
        t = 0;
        for(i=0;i<n;i++){
            scanf("%d",d+i);
            t += d[i];
        }
        if(t%2){
            printf("No equal partitioning.\n");
            continue;
        }
        t = t>>1;
        for(i=0;i<n;i++){
            t -= d[i];
            if(!t){
                printf("Sam stops at position %d and Ella stops at position %d.\n",i+1,i+2);
                break;
            }else if(t<0){
                printf("No equal partitioning.\n");
                break;
            }
        }
    }
    return 0;
}
