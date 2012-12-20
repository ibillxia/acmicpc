//3026281	2012-08-19 22:19:53	 Accepted
#include <stdio.h>
#include <math.h>
int n,m,d[50];
int p[3600]= {2,3,5,7};
double pi;
void table()
{
    int i,j,k=4;
    for(i=11; i<=16384; i+=2)
    {
        for(j=0; p[j]<=i/2; j++)
            if(i%p[j]==0)break;
        if(p[j]>i/2)p[k++]=i;
    }
    m=k;
}
int main()
{
    int i,j,k,s,t;
    table();
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        i=t=0;
        s=n*(n-1)/2;
        while(i<n)
            scanf("%d",&d[i++]);
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(d[i]%d[j]==0||d[j]%d[i]==0)continue;
                for(k=0; k<m&&p[k]<d[i]&&p[k]<d[j]; k++)
                    if(d[i]%p[k]==0&&d[j]%p[k]==0)break;
                if(k>=m||!(d[i]%p[k]==0&&d[j]%p[k]==0))t++;
            }
        }
        if(!t)
            printf("No estimate for this data set.\n");
        else
            printf("%.6lf\n",sqrt(6.0*s/t));
    }
    return 0;
}
