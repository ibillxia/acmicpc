/**************************************************************
** Problem: 1778 简单选择排序(O(nlgn))
** User£º ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
long long d[1000];

int _select_min(long long*,int,int);
void select_sort(long long*,int);

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lld",d+i);
	select_sort(d,n);
	for(i=0;i<n;i++)
        printf("%lld ",d[i]);
    printf("\n");
	return 0;
}

int _select_min(long long* d,int n,int s){
    int i,mi;
    long long m;
    m = d[s];
    mi = s;
    for(i=s+1;i<n;i++){
        if(d[i]<m){
            m = d[i];
            mi = i;
        }
    }
    return mi;
}

void select_sort(long long* d,int len){
    int i,j;
    for(i=0;i<len-1;i++){
        j = _select_min(d,len,i);
        if(j!=i){
            d[i] = d[i] + d[j];
            d[j] = d[i] - d[j];
            d[i] = d[i] - d[j];
        }
    }
}
