/**************************************************************
	Problem: 1032  第150235号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:904 kb
****************************************************************/
#include <stdio.h>
char s[102];
int main()
{
	int i,z,o,j;
	while(scanf("%s",s)){
		if(s[0]=='E')break;
		z=o=j=0;
		for(i=0;s[i]!=0;i++){
			switch(s[i]){
				case 'Z':z++;break;
				case 'O':o++;break;
				case 'J':j++;break;
			}
		}
		while(i){
			if(z){printf("Z");z--;}
			if(o){printf("O");o--;}
			if(j){printf("J");j--;}
			i--;
		}
		printf("\n");
	}
	return 0;
}
