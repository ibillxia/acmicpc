/**************************************************************
	Problem: 1029  第148849号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:60 ms
	Memory:11260 kb
****************************************************************/
#include <stdio.h>
#include <string.h>
typedef struct node{
	char name[24];
	char func[82];
}record;
char s[108];
record dict[100000];
int main()
{
	int i,j,m,n,t;
	char *p;
	i=0;
	while(gets(s) && strcmp(s,"@END@")){
		p=strchr(s,']');
		strncpy(dict[i].name,s,p-s+1);
		strcpy(dict[i].func,p+2);
		i++;
	}
	m=i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		gets(s);
		if(s[0]=='['){
			for(j=0;j<m;j++)
				if(!strcmp(s,dict[j].name)){printf("%s\n",dict[j].func);break;}
		}else{
			for(j=0;j<m;j++)
				if(!strcmp(s,dict[j].func)){
					t=strlen(dict[j].name);
					strcpy(s,dict[j].name+1);
					s[t-2]=0;
					printf("%s\n",s);break;
				}
		}
		if(j==m)printf("what?\n");
	}
	return 0;
}
