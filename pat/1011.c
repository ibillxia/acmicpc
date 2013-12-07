//file: 1011.c
//author: ibillxia
//ac: 2012年3月17日 星期六 11:33:38 HKT

#include <stdio.h>
#define N 10
char wtl[]="WTL",c[N];
//double d[N][3],m[3],mp;
float d[N][3],m[3],mp;
int main()
{
	int i,j;
	//double t,tm;
	float t,tm;
	//freopen("in.txt","r",stdin);
	i=j=0;
	while(scanf("%f",&t)!=EOF){
		if(j<3)d[i][j++]=t;
		else d[++i][0]=t,j=1;
	}

	for(;i>=0;i--){
		c[i]='W';tm=d[i][0];
		for(j=1;j<3;j++)
			if(tm<d[i][j]){c[i]=wtl[j];tm=d[i][j];}
		if(tm>m[0]){
			m[2]=m[1];m[1]=m[0];m[0]=tm;
		}else if(tm>m[1]){
			m[2]=m[1];m[1]=tm;
		}else if(tm>m[2])m[2]=tm;
	}
	mp=(m[0]*m[1]*m[2]*0.65-1)*2;
	//mp=(mp*100+0.5)/100;  //四舍五入提交后wa，不用四舍五入就ac了

	printf("%c %c %c %.2f\n",c[0],c[1],c[2],mp);
	return 0;
}