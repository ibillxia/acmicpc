/**************************************************************
	Problem: 1020  第109931号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:904 kb
****************************************************************/
#include <stdio.h>
int main()
{
    int lx,ly,rx,ry,tx,ty;
    while(1){
        scanf("%d %d",&tx,&ty);
        if(tx==0&&ty==0)break;
        lx=rx=tx;
        ly=ry=ty;
        while(1){
            scanf("%d %d",&tx,&ty);
            if(tx==0&&ty==0)break;
            if(tx<lx)lx=tx;
            if(ty<ly)ly=ty;
            if(tx>rx)rx=tx;
            if(ty>ry)ry=ty;
        }
        printf("%d %d %d %d\n",lx,ly,rx,ry);
    }
    return 0;
}
