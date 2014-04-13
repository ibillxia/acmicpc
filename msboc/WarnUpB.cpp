// Reference:http://www.huangwenchao.com.cn/2014/04/ms2014-warmup.html
#include <iostream>
using namespace std;

long long get_max(int,int,int);
int main()
{
    int i,t,m,n,k;
    cin>>t;
    i=0;
    while(i++<t){
        cin>>n>>m>>k;
        cout<<"Case #"<<i<<": "<<get_max(n,m,k)<<endl;
    }
    return 0;
}

long long get_max(int n,int m,int k)
{
    if(n<2||m<2||k<4)return 0;
    int i,j,t;
    long long maxn=0,tmax=0;
    for(i=1;i<=n;i++){
        j=k/i;
        t=k-i*j;
        if((!t&&j>m)||(t&&j+1>m))continue;
        tmax=i*(i-1)/2*j*(j-1)/2+j*t*(t-1)/2;
        maxn=max(maxn,tmax);
    }
    return maxn;
}
