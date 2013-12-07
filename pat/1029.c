//file: 1029.c
//author: ibillxia
//ac: 2012年3月19日 星期一 18:12:27 HKT

#include <stdio.h>
#define N 1000100
long m,n,a[N],b[N];
int main()
{
    long i,j,k,t,mid;
    scanf("%ld",&m);
    for(i=0;i<m;i++)scanf("%ld",a+i);
    scanf("%ld",&n);
    for(i=0;i<n;i++)scanf("%ld",b+i);

	if(m==0&&n==0)return 0;
	if(m==0){printf("%ld\n",b[(n-1)/2]);return 0;}
	if(n==0){printf("%ld\n",a[(m-1)/2]);return 0;}

    i=j=k=0;t=(m+n+1)/2;
    while(i<m&&j<n&&k<t){
        if(a[i]>b[j]){mid=b[j];j++;}
        else {mid=a[i];i++;}
        k++;
    }
    if(i==m&&k<t){
        while(k<t){j++;k++;}
        mid=b[j-1];
    }else if(j==n&&k<t){
        while(k<t){i++;k++;}
        mid=a[i-1];
    }
    printf("%ld\n",mid);
    return 0;
}
