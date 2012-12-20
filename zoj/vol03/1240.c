//run id 3005164	2012-08-06 22:04:45	 Accepted
#include <stdio.h>
int t;
char s[52];
int main()
{
    int i,j;
    scanf("%d",&t);
    getchar();
    i=1;
    while(i<=t) {
        gets(s);
        printf("String #%d\n",i);
        for(j=0; s[j]!='\0'; j++)
            if(s[j]<'Z')printf("%c",s[j]+1);
            else printf("A");
        printf("\n\n");
        i++;
    }
    return 0;
}
