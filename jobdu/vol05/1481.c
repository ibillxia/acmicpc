/**************************************************************
    Problem: 1481  第725517号提交
    User: 天勤
    Language: C
    Result: Accepted
    Time:30 ms
    Memory:992 kb
****************************************************************/
#include <stdio.h>
#include <string.h>
#define N 10000
int t[N][2];
int is_tree();
int M;
int main()
{
    int a,b,m,n,ans;
    m=1;
    while(scanf("%d %d",&a,&b)){
        if(a<0&&b<0)break;
        memset(t,0,2*N*sizeof(int));
        ans=-1;M=n=0;
        do{
            if(!a&&!b)break;
            if(!ans)continue;
            if(a==b){ans=0;continue;}
            if(!t[b][0]){
                t[b][0]=a;
                t[a][1]=t[b][1]=1;
            }else if(t[b][0]!=a)ans=0; // 2+ parents, not a tree
            n++;
            if(a>M)M=a;
            if(b>M)M=b;
        }while(scanf("%d %d",&a,&b));
        if(!n||!ans) goto OUT; //n=0 => null tree
        ans = is_tree();
    OUT:
        if(!ans)printf("Case %d is not a tree.\n",m++);
        else printf("Case %d is a tree.\n",m++);
    }
    return 0;
}

int is_tree()
{
    int i,j,k,n,r;
    j=n=0;
    for(i=1;i<M;i++){
        if(t[i][1]){
            if(!t[i][0]){
                j++;
                if(j>1)return 0; // 2+ roots, not a tree
                r=i; // root of a tree
            }
            n++; // number of nodes
        }
    }
    for(i=1;i<=M;i++){ // dfs
        if(t[i][1]&&i!=r){
            j=i;k=n;
            while(t[j][0]&&t[j][0]!=r&&k){
                j=t[j][0];k--;
            }
            if(!k||!t[j][0]) return 0;
        }
    }
    return 1;
}
