/**************************************************************
	Problem: 1021  第109939号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:908 kb
****************************************************************/
#include <stdio.h>
#include <string.h>
#include <memory.h>
int main()
{
    char s[6],str[82];
    int i,j,cnt[5],len;
    while(1){
        gets(s);
        len=strlen(s);
        if(len==1&&s[0]=='#')break;
        gets(str);
        memset(cnt,0,sizeof(cnt));
        for(j=0;str[j];j++){
            for(i=0;i<len;i++)
                if(str[j]==s[i])cnt[i]++;
        }
        for(i=0;i<len;i++)
            printf("%c %d\n",s[i],cnt[i]);
    }
    return 0;
}
