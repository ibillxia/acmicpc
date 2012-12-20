//run id:3049815	2012-09-08 16:31:20
#include <stdio.h>
#include <string.h>
int t,n,d[104];
int main()
{
    int i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(d,0,sizeof(d));
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j+=i){
                d[j] = ~d[j];
            }
        }
        j=0;
        for(i=1;i<=n;i++){
            if(d[i])j++;
        }
        printf("%d\n",j);
    }
    return 0;
}
