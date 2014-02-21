/**************************************************************
	Problem: 1003  第150388号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
long a,b;
int main()
{
	int i,f;
	char s[30];
	while(scanf("%s",s)!=EOF){
		a=b=0;
		if(s[0]=='-'){f=-1;i=1;}
		else {f=1;i=0;}
		while(s[i]){
			if(s[i]!=',')a=a*10+s[i]-'0';
			i++;
		}
		a=a*f;
		scanf("%s",s);
		if(s[0]=='-'){f=-1;i=1;}
		else {f=1;i=0;}
		while(s[i]){
			if(s[i]!=',')b=b*10+s[i]-'0';
			i++;
		}
		b=b*f;
		printf("%d\n",a+b);
	}
	return 0;
}
