//file: 1027.c
//author: ibillxia
//ac: 2012年3月18日 星期日 21:03:35 HKT

#include <stdio.h>

int main()
{
	int i,col[3],t1,t2;
	scanf("%d %d %d",col,col+1,col+2);
	printf("#");
	for(i=0;i<3;i++){
		t1=col[i]/13;t2=col[i]%13;
		if(t1<10)printf("%d",t1);
		else printf("%c",t1-10+'A');
		if(t2<10)printf("%d",t2);
		else printf("%c",t2-10+'A');
	}
	printf("\n");
	return 0;
}