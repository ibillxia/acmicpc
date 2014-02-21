/**************************************************************
	Problem: 1019  第93923号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:912 kb
****************************************************************/
#include <stdio.h>
#include <string.h>
char in[202],cstk[80];
int ct,dt;
double dstk[80];
int cmp(char c1,char c2){
	int i,a[2];
	char c[2];
	c[0]=c1;
	c[1]=c2;
	for(i=0;i<2;i++){
		switch(c[i]){
			case '+':
			case '-':
				a[i]=1;
				break;
			case '*':
			case '/':
				a[i]=2;
				break;
		}
	}
	return a[0]-a[1];
}
double cal(double da,double db,char ch){
	switch(ch){
		case '+':return db+da;
		case '-':return db-da;
		case '*':return db*da;
		case '/':return db/da;  
	}
}
int main()
{
	char c1,c2;
	int len,i,a;
	double da,db,dc;
	while(1){
		gets(in);
		len = strlen(in);
		if(1==len && in[0]=='0')break;
		ct=dt=0;
		for(i=0;i<len;i++){ 
			a=0;
			while(in[i]>='0'&&in[i]<='9')
				a=a*10+(in[i++]-'0');
			dstk[dt++]=(double)a;
			i++;
			if(i<len)cstk[ct++]=in[i];
			i++;
		}
		for(i=0;i<dt/2;i++){
			da=dstk[i];
			dstk[i]=dstk[dt-i-1];
			dstk[dt-i-1]=da;
		}
		for(i=0;i<ct/2;i++){
			c1=cstk[i];
			cstk[i]=cstk[ct-i-1];
			cstk[ct-i-1]=c1;
		}
		while(ct){
			da=dstk[--dt];
			db=dstk[--dt];
			c1=cstk[--ct];
			if(ct>0){
				c2=cstk[ct-1];
				if(cmp(c1,c2)>=0){
					dstk[dt++]=cal(db,da,c1);
				}else{
					dc=dstk[--dt];
					c2=cstk[--ct];
					dstk[dt++]=cal(dc,db,c2);
					dstk[dt++]=da;
					cstk[ct++]=c1;
				}
			}else{
				dstk[dt++]=cal(db,da,c1);
			}
		}
		printf("%.2f\n",dstk[0]);
	}
	return 0;
}
