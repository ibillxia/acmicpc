/**************************************************************
** Problem: 1776 希尔插入排序(O(n^2))
** 算法导论2.1节
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
long long d[1000];

void shell_sort(long long*,int);

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lld",d+i);
	shell_sort(d,n);
	for(i=0;i<n;i++)
        printf("%lld ",d[i]);
    printf("\n");
	return 0;
}

void shell_sort(long long* d, int len){
    int i,j,step;
    long long temp;
    step=len/2;
    while(step>0){
        for(i=step;i<len;i++){
            j = i - step;
            temp = d[i];
            while(j>=0 && d[j]>temp){
                d[j+step] = d[j];
                j -= step;
            }
            d[j+step] = temp;
        }
        step = step/2;
    }
}
