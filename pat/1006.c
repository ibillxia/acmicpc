//file: 1006.c
//author: ibillxia
//ac: 2012年3月16日 星期五 11:45:13 HKT

#include <stdio.h>
#include <string.h>

int main()
{
	int i,n,ft,lt,h,m,s,t;
	char tp[16],fp[16],lp[16];
	while(scanf("%d",&n)!=EOF){
		ft=86400;lt=0;
		for(i=0;i<n;i++){
			scanf("%s %d:%d:%d",tp,&h,&m,&s);
			t=h*3600+m*60+s;
			if(t<ft){ft=t;strcpy(fp,tp);}
			scanf(" %d:%d:%d",&h,&m,&s);
			t=h*3600+m*60+s;
			if(t>lt){lt=t;strcpy(lp,tp);}
		}
		printf("%s %s\n",fp,lp);
	}
	return 0;
}