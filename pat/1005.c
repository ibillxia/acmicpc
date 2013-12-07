//file: 1005.c
//author: ibillxia
//ac: 2012年3月16日 星期五 11:31:34 HKT

#include <stdio.h>

char n[102],num[][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int sum;

int main(){
	int i;
	while(gets(n)){
		sum=0;
		for(i=0;n[i]!='\0';i++)sum+=n[i]-'0';
		if(sum>99)printf("%s %s %s\n",num[sum/100],num[sum%100/10],num[sum%10]);
		else if(sum>9)printf("%s %s\n",num[sum/10],num[sum%10]);
		else printf("%s\n",num[sum]);
	}
}