//file: 1035.c
//author: ibillxia
//ac: 2012年8月25日 星期六 01:26:45 HKT
//run id: 63884

#include <stdio.h>
#include <string.h>
#define N 1010
int n,t,i,f;
char arr[N][2][12],na[12],pw[12];

int main()
{
    char *p;
    scanf("%d",&n);
    t=n;
    while(n--){
        scanf("%s %s",na,pw);
        p=pw;f=0;
        while(*p){
            if(*p=='1'){*p='@';f=1;}
            else if(*p=='l'){*p='L';f=1;}
            else if(*p=='0'){*p='%';f=1;}
            else if(*p=='O'){*p='o';f=1;}
            p++;
        }
        if(f){
            strcpy(arr[i][0],na);
            strcpy(arr[i][1],pw);
            i++;
        }
    }
    if(!i){
        printf("There ");
        if(t==1)printf("is 1 account");
        else printf("are %d accounts",t);
        printf(" and no account is modified\n");
    } else {
        printf("%d\n",i);
        for(t=0;t<i;t++)
            printf("%s %s\n",arr[t][0],arr[t][1]);
    }
    return 0;
}
