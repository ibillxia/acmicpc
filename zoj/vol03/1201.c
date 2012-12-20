//run id 2985083	2012-07-29 21:09:05	 Accepted
#include <stdio.h>
#define M 50

char tp;
int t,P[M],I[M];

int main()
{
    int i,j,k;

    while(1) {
        scanf("%d",&t);
        if(t==0)break;
        scanf("%c",&tp);
        switch(tp) {
        case 'P':
            for(i=0; i<t; i++)scanf("%d",P+i);
            for(i=1; i<=t; i++) {
                k=0;
                for(j=0; j<t; j++)
                    if(P[j]<i)k++;
                    else if(P[j]==i)break;
                if(i<t)printf("%d ",j-k);
                else printf("%d\n",j-k);
            }
            break;
        case 'I':
            for(i=0; i<t; i++) {
                scanf("%d",I+i);
                P[i]=t;
            }
            for(i=1; i<t; i++) {
                k=0;
                for(j=0; k<I[i-1]; j++)
                    if(P[j]==t)k++;
                while(P[j]<i)j++;
                P[j]=i;
            }
            for(i=0; i<t-1; i++)
                printf("%d ",P[i]);
            printf("%d\n",P[i]);
            break;
        }
    }
    return 0;
}
