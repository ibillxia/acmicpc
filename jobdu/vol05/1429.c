/**************************************************************
    Problem: 1429  第266126号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:10 ms
    Memory:908 kb
****************************************************************/
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
//            printf("DBG: ");
//            for(tt=0;tt<n;tt++)
//                printf("%d ",da[tt]);
//            printf("\n");
                }
            }
 
        }
        if(i>2)printf("no\n");
        else if(da[0]==db[0]&&da[1]==db[1]&&da[2]==db[2])printf("yes\n");
        else if(db[0]==da[0]+da[1]&&db[1]==-da[1]&&db[2]==da[2]+da[1])printf("yes\n");
        else printf("no\n");
    }
    return 0;
}