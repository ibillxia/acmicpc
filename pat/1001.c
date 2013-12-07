//file: 1001.c
//author: ibillxia
//ac: 2012年3月09日 星期五 21:34:21 HKT

#include <stdio.h>
#include <memory.h>
int main()
{
	int a,b,c[4],f,i;
  	while(scanf("%d %d",&a,&b)!=EOF){
  		memset(c,0,sizeof(c));
		a=a+b;
        if(a==0){printf("0\n");continue;}
        f=1;
		if(a<0){f=-1;a=-a;}
        i=-1;
        while(a){
          	c[++i]=a%1000;
            a/=1000;
        }
        if(f<0)printf("-");
		if(c[2]>0)printf("%d,",c[2]);
		if(c[2]>0&&c[1]<1000)printf("%03d,",c[1]);
		else if(c[1]>0)printf("%d,",c[1]);
        if(c[2]>0||c[1]>0 && c[0]<1000)printf("%03d\n",c[0]);
		else printf("%d\n",c[0]);
    }
	return 0;
}
