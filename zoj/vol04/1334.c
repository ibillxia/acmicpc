//3025494	2012-08-18 21:26:09	 Accepted
#include <stdio.h>
char base[] = "0123456789ABCDEF";
char s[1000],t[40],r[8];
int a,b,l;
void convert()
{
    int i,j,k;
    i=l-1;
    j=1;
    k=0;
    while(i>=0) {
        if(t[i]<='9')k+=(t[i]-48)*j;
        else k+=(t[i]-55)*j;
        j*=a;
        i--;
    }
    if(b==10) {
        if(k<10000000)printf("%7d\n",k);
        else printf("  ERROR\n");
        return;
    }
    i=6;
    while(k>0) {
        r[i]=base[k%b];
        k/=b;
        if(i==0 && k!=0) {
            printf("  ERROR\n");
            return;
        }
        i--;
    }
    printf("%s\n",r);
}
int main()
{
    int i;
    char *p;
    //freopen("in.txt","r",stdin);
    while(gets(s)) {
        p=s;
        while(*p==' ')p++;
        i=0;
        while(*p!=' ')t[i++]=*p++;
        t[i]='\0';
        l=i;
        while(*p==' ')p++;
        if(*(p+1)==' ')a=*p-48;
        else {
            a=(*p-48)*10;
            p++;
            a+=(*p-48);
        }
        p++;
        while(*p==' ')p++;
        if(*(p+1)==' '||*(p+1)=='\0')b=*p-48;
        else {
            b=(*p-48)*10;
            p++;
            b+=(*p-48);
        }
        for(i=0; i<7; i++)r[i]=' ';
        r[7]='\0';
        convert();
    }
    return 0;
}
