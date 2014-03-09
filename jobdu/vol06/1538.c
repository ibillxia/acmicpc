/**************************************************************
    Problem: 1538  第715635号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:50 ms
    Memory:924 kb
****************************************************************/
#include <stdio.h>
char in[10000];
int main()
{
    char *p;
    while(~scanf("%s",&in)){
        p = in;
        while(*p){
            if(*p>='a' && *p<='c') printf("2");
            else if(*p>='d' && *p<='f') printf("3");
            else if(*p>='g' && *p<='i') printf("4");
            else if(*p>='j' && *p<='l') printf("5");
            else if(*p>='m' && *p<='o') printf("6");
            else if(*p>='p' && *p<='s') printf("7");
            else if(*p>='t' && *p<='v') printf("8");
            else if(*p>='w' && *p<='z') printf("9");
            p++;
        }
        printf("\n");
    }
    return 0;
}
