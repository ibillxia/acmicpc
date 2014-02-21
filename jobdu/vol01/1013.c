/**************************************************************
	Problem: 1013  第93405号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
int m,n;
char temp[16],first[16],last[16];
int time[3],min,max;
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		min=86400;
		max=-1;
		for(j=0;j<m;j++){
			scanf("%s",temp);
			scanf("%d:%d:%d",time,time+1,time+2);
			time[0]=time[0]*3600+time[1]*60+time[2];
			if(time[0]<min){
				min=time[0];
				memcpy(first,temp,sizeof(temp));
			}
			scanf("%d:%d:%d",time,time+1,time+2);
			time[0]=time[0]*3600+time[1]*60+time[2];
			if(time[0]>max){
				max=time[0];
				memcpy(last,temp,sizeof(temp));
			}
		}
		printf("%s %s\n",first,last);
	}
	return 0;
}

