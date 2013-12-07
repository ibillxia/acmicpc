//file: 1023.c
//author: ibillxia
//ac: 2012年3月18日 星期日 15:02:18 HKT

#include <stdio.h>
#include <memory.h>

char sg[22],db[22],sc[12],dc[12];

int main()
{
	int i,j,k,len;
	memset(sc,0,sizeof(sc));
	memset(dc,0,sizeof(dc));
	gets(sg);
	for(i=0;sg[i];i++)
		sc[sg[i]-'0']++;
	len=i;
	for(i=len-1,j=len;i>=0;i--,j--){
		k=(sg[i]-'0')*2;
		db[j-1]=(db[j]+k)/10;
		db[j]=(db[j]+k)%10;
		dc[db[j]]++;
	}
	if(!memcmp(sc,dc,sizeof(sc)))printf("Yes\n");
	else printf("No\n");
	if(db[0]!=0)printf("%d",db[0]);
	for(j=1;j<=len;j++)printf("%d",db[j]);
	printf("\n");
	return 0;
}
