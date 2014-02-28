/**************************************************************
** Problem: 1774 直接插入排序(O(n^2))
** 算法导论2.1节
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
long long d[1000];

void insert_sort(long long*,int);

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lld",d+i);
	insert_sort(d,n);
	for(i=0;i<n;i++)
        printf("%lld ",d[i]);
    printf("\n");
	return 0;
}

void insert_sort(long long* d, int len){
	int i,j;
	long long t;
	for(i=1;i<len;i++){
		t = d[i];
		for(j=i-1;j>=0;j--){
			if(d[j]>=t)d[j+1] = d[j];
			else break;
		}
		d[j+1] = t;
	}
}
