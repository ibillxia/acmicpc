/**************************************************************
** Problem: 1777 快速排序(O(nlgn))
** 算法导论第7章
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
long long d[100000];

int _partition(long long*,int,int);
void _quick_sort(long long*,int,int);
void quick_sort(long long*,int);

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lld",d+i);
	quick_sort(d,n);
	for(i=0;i<n;i++)
        printf("%lld ",d[i]);
    printf("\n");
	return 0;
}

int _partition(long long* d,int l,int r){
    int i,j;
    long long t;
    t = d[r];
    i=l;
    j=r;
    while(i<j){
        while(d[i]<t&&i<j)i++;
        d[j] = d[i];
        while(d[j]>=t&&i<j)j--;
        d[i] = d[j];
    }
    d[i] = t;
    return i;
}

void _quick_sort(long long* d,int l,int r){
    int m;
    if(l<r){
        m = _partition(d,l,r);
        _quick_sort(d,l,m-1);
        _quick_sort(d,m+1,r);
    }
}

void quick_sort(long long* d,int len){
    _quick_sort(d,0,len-1);
}
