//file: 1004.c
//author: ibillxia
//ac: 2012年3月17日 星期六 11:27:36 HKT

#include <stdio.h>
#include <memory.h>

int n,m,pt[110],que[110],cnt;

void BFS(){
	int i,id,tt,hd,tl,flag,blank;
	cnt=blank=0;hd=tl=1;tt=2;
	que[tl++]=1;
	while(hd<tl){
		id=que[hd++];flag=0;
		for(i=2;i<=n;i++)
			if(pt[i]==id){que[tl++]=i;flag=1;}
		if(!flag) cnt++;
		if(hd==tt){
			tt=tl;
			if(blank)printf(" ");
			printf("%d",cnt);
			cnt=0;
			blank=1;
		}
	}
}

int main()
{
	int i,k,idp,idc;
	//freopen("in-1004.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(pt,0,sizeof(pt));
		memset(que,0,sizeof(que));
		for(i=0;i<m;i++){
			scanf("%d %d",&idp,&k);
			while(k--){
				scanf("%d",&idc);
				pt[idc]=idp;
			}
		}
		BFS();
		printf("\n");
	}
	return 0;
}