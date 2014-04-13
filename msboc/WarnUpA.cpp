//source here
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define MAXLEN 100001
char c[MAXLEN],cc[MAXLEN];
map<string,string> mp;
string str[MAXLEN];
int main()
{
    int i,j,k,ii,T,M,N;
    string a,b;

    cin>>T;
    i=1;
    while(i<=T){
        cin>>N>>M;
        for(j=0;j<M;j++){
            cin>>a>>b;
            mp[a]=b;
        }
        cin.get();
        cin.getline(c,MAXLEN);
        int clen=strlen(c);
        for(j=k=ii=0;j<clen;j++){
            if(c[j]==' '){
                strncpy(cc,c+k,j-k);
                cc[j-k]='\0';
                str[ii++]=cc;
                k=j+1;
            }
        }
        strncpy(cc,c+k,j-k);
        cc[j-k]=0;
        str[ii++]=cc;

        for(j=0;j<N-1;j++){
            for(k=0;k<ii;k++){
                if(mp.find(str[k])!= mp.end()){
                    str[k]=mp[str[k]];
                }
            }
        }
        cout<<"Case #"<<i<<":";
        for(j=0;j<ii;j++)cout<<" "<<str[j];
        cout<<endl;
        i++;
        mp.clear();
    }
    return 0;
}
