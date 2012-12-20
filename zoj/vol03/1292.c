//run id 3013751	2012-08-11 08:55:25	 Accepted
#include <stdio.h>
#include <string.h>
int n;
char z[110];
char* add(char x[],char y[])
{
    int i,j,k,lx,ly,t[110];
    lx=strlen(x);
    ly=strlen(y);
    if(lx==0)return y;
    if(ly==0)return x;
    i=lx;
    j=ly;
    if(lx>ly)k=lx+1;
    else k=ly+1;
    memset(t,0,sizeof(t));
    memset(z,0,sizeof(z));
    while(i>0&&j>0) {
        i--;
        j--;
        k--;
        t[k-1]=(x[i]+y[j]+t[k]-96)/10;
        t[k]=(x[i]+y[j]+t[k]-96)%10;
        z[k]=(char)(t[k]+48);
    }
    while(i>0) {
        i--;
        k--;
        t[k-1]=(x[i]+t[k]-48)/10;
        t[k]=(x[i]+t[k]-48)%10;
        z[k]=(char)(t[k]+48);
    }
    while(j>0) {
        j--;
        k--;
        t[k-1]=(y[j]+t[k]-48)/10;
        t[k]=(y[j]+t[k]-48)%10;
        z[k]=(char)(t[k]+48);
    }
    z[0]=(char)(t[0]+48);
    if(z[0]&&z[0]!='0')return z;
    else return z+1;
}
int main()
{
    char a[102],s[110],*p;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    getchar();
    while(n--) {
        getchar();
        memset(s,0,sizeof(s));
        while(gets(a)) {
            if(strlen(a)==1&&a[0]=='0')break;
            p=add(a,s);
            strcpy(s,p);
        }
        puts(s);
        if(n>0)printf("\n");
    }
    return 0;
}
