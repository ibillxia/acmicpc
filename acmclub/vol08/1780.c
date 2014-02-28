/**************************************************************
** Problem: 1780 归并排序(O(nlgn))
** 算法导论2.3.1节
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
#define MAX_SIZE 100000

long long data[MAX_SIZE];

long long __tmp_arr[MAX_SIZE];
void _merge(long long*,int,int,int);
void _merge_sort(long long*,int,int);
void merge_sort(long long*,int);

int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",data+i);
    }
    merge_sort(data,n);
    for(i=0;i<n;i++){
        printf("%lld ",data[i]);
    }
    printf("\n");
    return 0;
    return 0;
}

void _merge(long long* d,int l,int m,int r){
    int i,j,k;
    for(i=l;i<=r;i++) __tmp_arr[i] = d[i];
    for(i=k=l,j=m+1;i<=m&&j<=r;k++){
        if(__tmp_arr[i]<__tmp_arr[j]) d[k] = __tmp_arr[i++];
        else d[k] = __tmp_arr[j++];
    }
    if(i<=m){
        for(;i<=m;i++,k++) d[k] = __tmp_arr[i];
    }else if(j<=r){
        for(;j<=r;j++,k++) d[k] = __tmp_arr[j];
    }
}

void _merge_sort(long long* d,int l,int r){
    int m;
    if(l<r){
        m=(l+r)>>1;
        _merge_sort(d,l,m);
        _merge_sort(d,m+1,r);
        _merge(d,l,m,r);
    }
}

void merge_sort(long long* d,int len){
    _merge_sort(d,0,len-1);
}
