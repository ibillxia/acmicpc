//run id 2991363	2012-07-31 21:29:14	 Accepted
#include <stdio.h>
#include <string.h>

static char s[22]="0123456789abcdefghij";
char a[102],b[102],c[102];

int main()
{
    int i,j,k,t;
    //freopen("in.txt","r",stdin);
    while(~scanf("%s%s",a,b)) {
        memset(c,0,sizeof(c));
        i=strlen(a);
        j=strlen(b);
        if(i>j)k=i+1;
        else k=j+1;
        while(i&&j) {
            i--;
            j--;
            k--;
            if(c[k]>s[9])t=c[k]-87;
            else if(c[k]>0)t=c[k]-48;
            else t=0;
            if(a[i]>s[9])t+=a[i]-87;
            else t+=a[i]-48;
            if(b[j]>s[9])t+=b[j]-87;
            else t+=b[j]-48;
            c[k-1]=s[t/20];
            c[k]=s[t%20];
        }
        while(i--) {
            k--;
            if(c[k]>s[9])t=c[k]-87;
            else if(c[k]>0)t=c[k]-48;
            else t=0;
            if(a[i]>s[9])t+=a[i]-87;
            else t+=a[i]-48;
            c[k-1]=s[t/20];
            c[k]=s[t%20];
        }
        while(j--) {
            k--;
            if(c[k]>s[9])t=c[k]-87;
            else if(c[k]>0)t=c[k]-48;
            else t=0;
            if(b[j]>s[9])t+=b[j]-87;
            else t+=b[j]-48;
            c[k-1]=s[t/20];
            c[k]=s[t%20];
        }
        if(c[0]&&c[0]!=s[0])puts(c);
        else puts(c+1);
    }
    return 0;
}
