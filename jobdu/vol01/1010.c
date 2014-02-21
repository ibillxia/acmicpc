/**************************************************************
	Problem: 1010  第87616号提交
	User: 天勤
	Language: C++
	Result: Accepted
	Time:10 ms
	Memory:1012 kb
****************************************************************/
#include<stdio.h>
#include<string.h>
char m[][8] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int cmp(char s[])
{
	int i=0;
	for(;i<10;i++)
		if(strcmp(s,m[i])==0) return i;
	return -1;
}
int main()
{
	char s[8];
	int a,b;
	while(1)
	{
		a=b=0;
		while(scanf("%s",s) && strcmp(s,"+")!=0) 
			a=a*10+cmp(s);
		while(scanf("%s",s) && strcmp(s,"=")!=0) 
			b=b*10+cmp(s);
		if(a!=0&&b!=0) printf("%d\n",a+b);
		else return 1;
	}
}

