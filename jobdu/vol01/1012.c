/**************************************************************
	Problem: 1012  第109882号提交
	User: 天勤
	Language: C
	Result: Accepted
	Time:10 ms
	Memory:912 kb
****************************************************************/
#include <stdio.h>
#include <memory.h>
int m,n,min,set[1002];
int Find(int x){
    while(x!=set[x])x=set[x];
    return x;
}
void Union(int a,int b){
    int t1,t2;
    t1=Find(a);
    t2=Find(b);
    if(t1!=t2){
        set[t2]=t1;
        min--;
    }
}
int main()
{
    int i,a,b;
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        for(i=0;i<=n;i++)set[i]=i;
        min=n-1;
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            Union(a,b);
        }
        if(min>0)printf("%d\n",min);
        else printf("0\n");
    }
    return 0;
}
