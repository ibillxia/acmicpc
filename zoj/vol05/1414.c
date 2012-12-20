#include <stdio.h>

int main(){
    int x,y,n;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&x,&y);
        if(x==y && x>=0){
            if(x%2) printf("%d\n",2*x-1);
            else printf("%d\n",2*x);
        }else if(x==y+2 && y>=0){
            if(x%2) printf("%d\n",2*x-3);
            else printf("%d\n",2*x-2);
        }else{
            printf("No Number\n");
        }
    }
    return 0;
}
