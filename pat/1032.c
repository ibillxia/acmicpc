//file: 1032.c
//author: ibillxia
//ac: 2012年8月23日 星期四 22:41:00 HKT
//run id:63481

#include <stdio.h>
#define N 100010

int list[N],n,ha,hb,h;

int main()
{
	int a,b,la,lb;
	char ch;
	scanf("%d %d %d",&ha,&hb,&n);
    if(ha==-1||hb==-1){printf("-1\n");return 0;}
    while(n--){
        scanf("%d %c %d",&a,&ch,&b);
        list[a]=b;
    }
    la=lb=0;
    a=ha;b=hb;
    while(a!=-1){a=list[a];la++;}
    while(b!=-1){b=list[b];lb++;}
    a=ha;b=hb;
    while(la>lb){a=list[a];la--;}
    while(la<lb){b=list[b];lb--;}
    while(a!=b&&la){a=list[a];b=list[b];la--;}
    if(a==-1)printf("-1\n");
    else printf("%05d\n",a);
	return 0;
}
