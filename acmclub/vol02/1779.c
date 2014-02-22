/**************************************************************
** Problem: 1779 堆排序(O(nlgn))
** 算法导论第6章
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)

long long data[100000];
void _max_heapify(long long*,int,int);
void _build_max_heap(long long*,int);
void heap_sort(long long*,int);

int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",data+i);
    }
    heap_sort(data,n);
    for(i=0;i<n;i++){
        printf("%lld ",data[i]);
    }
    printf("\n");
    return 0;
}

void _max_heapify(long long* d,int i,int len){
    int l,r,m;
    l = LEFT(i);
    r = RIGHT(i);
    if(l<len && d[l]>d[i]) m = l;
    else m = i;
    if(r<len && d[r]>d[m]) m =r;
    if(m != i){
        d[i] = d[i]+d[m];
        d[m] = d[i]-d[m];
        d[i] = d[i]-d[m];
        _max_heapify(d,m,len);
    }
}

void _build_max_heap(long long* d,int len){
    int i;
    for(i=(len-1)/2;i>=0;i--){
        _max_heapify(d,i,len);
    }
}

void heap_sort(long long* d,int len){
    int i;
    _build_max_heap(d,len);
    for(i=len-1;i>0;i--){
        d[i] = d[i]+d[0];
        d[0] = d[i]-d[0];
        d[i] = d[i]-d[0];
        _max_heapify(d,0,i);
    }
}
