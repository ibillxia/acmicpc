#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int T;
    char c1,c2;
    double f1,f2,f3;
    cin>>T;
    for(int i=1;i<=T;i++){
        scanf("%lf%c%c",&f1,&c1,&c2);
        switch(c1){
        case 'm':
            if(c2==' ')f1*=1000.0;
            break;
        case 'd':
            f1*=100.0;
            break;
        case 'c':
            f1*=10.0;
            break;
        case 'u':
            f1*=1e-3;
            break;
        case 'n':
            f1*=1e-6;
            break;
        }
        scanf("%lf%c%c",&f2,&c1,&c2);
        switch(c1){
        case 'm':
            if(c2==' ')f2*=1000.0;
            break;
        case 'd':
            f2*=100.0;
            break;
        case 'c':
            f2*=10.0;
            break;
        case 'u':
            f2*=1e-3;
            break;
        case 'n':
            f2*=1e-6;
            break;
        }
        scanf("%lfpx",&f3);
        printf("Case %d: %.2lfpx\n",i,(f3*f1/f2));  //+0.005
    }
    return 0;
}
