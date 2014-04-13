#include<iostream>
using namespace std;
#define M 1000000007
#define FOR(i,a,b) for(i=a;i<=b;i++)
int main()
{
    int ii,t,n,a,b,c;
    long long cnt;
    cin>>t;
    FOR(ii,1,t){
        cin>>n;
        cnt=0;
        FOR(a,1,n)FOR(b,1,n)FOR(c,1,n)
        if((a==b && b==c)||(a!=b&&b!=c&&c!=a))
            cnt=(cnt+(n-a+1)*(n-b+1)*(n-c+1))%M;
        cout<<"Case "<<ii<<": "<<cnt<<endl;
    }
    return 0;
}
