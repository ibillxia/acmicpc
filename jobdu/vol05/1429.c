//            printf("DBG: ");
//            for(tt=0;tt<n;tt++)  第266126号提交
//                printf("%d ",da[tt]);
//            printf("\n");
                }
            }

        }
#include <stdio.h>
int t,n,s1,s2,da[25],db[25];

int main()
{
    int i,j,k;
    //int tt;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        s1=s2=0;
        for(i=0;i<n;i++){
            scanf("%d",da+i);
            s1+=da[i];
        }
        for(i=0;i<n;i++){
            scanf("%d",db+i);
            s2+=db[i];
        }

        if(s1!=s2){
            printf("no\n");
            continue;
        }
        j=n-1;
        for(i=n-1;i>2;i--){

            if(da[i]==db[i])continue;
            else {
                s1=db[i];
                for(j=i;j>0&&s1;j--){
                    s1-=da[j];
                    //printf("%d ",s1);
                }
                //printf("\nDBG: %d %d\n",i,j);
                if(s1)break;
                for(k=j+1;k<i;k++){
                    da[k-1]+=da[k];
                    da[k+1]+=da[k];
                    da[k]=-da[k];
