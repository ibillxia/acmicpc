/**************************************************************
** Problem: 1781 基数排序(O(d(n+k)))
** 算法导论8.3节
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <stdio.h>
long long d[100000];

long long _bin[10][100001];
void _distribute(long long*,int,int);
void _collect(long long*,int);
void radix_sort(long long*,int);

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lld",d+i);
	radix_sort(d,n);
	for(i=0;i<n;i++)
        printf("%lld ",d[i]);
    printf("\n");
	return 0;
}

void _distribute(long long* d,int len,int n){
    int i,j;
    for(i=0;i<10;i++) _bin[i][0] = 0;
    for(i=0;i<len;i++){
        j = (d[i]%n)/(n/10);
        _bin[j][0]++;
        _bin[j][_bin[j][0]]=d[i];
    }
}

void _collect(long long* d,int len){
    int i,j,k;
    k=0;
    for(i=0;i<10;i++){
        for(j=1;j<=_bin[i][0];j++)d[k++]=_bin[i][j];
    }
}

void radix_sort(long long* d,int len){
    int i,n;
    long long m;
    for(i=1,m=d[0];i<len;i++){  // find max
        if(d[i]>m) m = d[i];
    }
    n=10;
    while(m){
        m /= 10;
        _distribute(d,len,n);
        _collect(d,len);
        n = n*10;
    }
}
