/**************************************************************
** Problem: 1775 折半插入排序(O(n^2))
** 算法导论2.1节
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
long long d[1000];

void bin_insert_sort(long long*,int);

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lld",d+i);
	bin_insert_sort(d,n);
	for(i=0;i<n;i++)
        printf("%lld ",d[i]);
    printf("\n");
	return 0;
}

void bin_insert_sort(long long* d, int len){
	int i,j,low,mid,high;
	long long t;
	for(i=1;i<len;i++){
        low = 0;
        high = i;
        t = d[i];
        while(low<=high){
            mid=(low+high)>>1;
            if(d[mid]<t) low=mid+1;
            else high=mid-1;
        }
        for(j=i;j>high+1;j--)d[j]=d[j-1];
        d[high+1] = t;
	}
}

