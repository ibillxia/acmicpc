/**************************************************************
	Problem: 1066  第147166号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:160 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b){return *(char*)a-*(char*)b;}

int main()
{
	char str[22];
	while(gets(str)){
		qsort(str,strlen(str),sizeof(char),cmp);
		puts(str);
	}
	return 0;
}
