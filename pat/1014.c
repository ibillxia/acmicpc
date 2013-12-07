#include <stdio.h>

int m,n,k,q;
int que[22][14],t[1010],st[1010];

int main()
{
	int i,j,tt;
	scanf("%d %d %d %d",&n,&m,&k,&q);
	for(i=1;i<=k;i++)scanf("%d",t+i);
	
	for(i=0;i<n;i++)
	
	for(i=0;i<m;i++){
		scanf("%d",&tt);
		if(st[tt]<540)printf("%2d:%2d\n",8+st[tt]/60,st[tt]%60);
		else printf("Sorry\n");
	}
	return 0;
}
