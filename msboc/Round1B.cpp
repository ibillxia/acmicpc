/* 跟树相关的算法，树链剖分、树形dp、欧拉序列，都没用上。
** 该题只需要dfs，然后再用树状数组统计下当前节点的祖先的影响就可以了
** 原文链接：http://www.cnblogs.com/dango/p/3675259.html
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int first[maxn];
struct Arc
{
    int v, next;
}arc[maxn];
int first2[maxn];
struct Arc2
{
    int l, delta, next;
}query[maxn * 2];
int cnt;
int n;
ll answer[maxn], sum[maxn];

void addQuery(int u, int l, int delta)
{
    query[cnt].l = l;
    query[cnt].delta = delta;
    query[cnt].next = first2[u];
    first2[u] = cnt++;
}

void add(int i, int delta)
{
    for(; i <= n; i += i & (-i))
        sum[i] += delta;
}

ll ask(int i)
{
    ll ans = 0;
    for(; i > 0; i-= i & (-i))
        ans += sum[i];

    return ans;
}

void dfs(int u, int deep)
{
   // printf("(%d %d)\n", u, deep);
    for(int i = first2[u]; i + 1; i = query[i].next)
    {
        int l = query[i].l, delta = query[i].delta;
        add(l, delta);
    }

    answer[u] = ask(deep);
    for(int i = first[u]; i + 1; i = arc[i].next)
    {
        int v = arc[i].v;
        dfs(v, deep + 1);
    }

    for(int i = first2[u]; i + 1; i = query[i].next)
    {
        int l = query[i].l, delta = query[i].delta;
        add(l, -delta);
    }
}
int solve()
{
    ll MOD =1000000007; // 10^9 + 7
    ll MAGIC= 12347;
    ll Hash =0;
    for(int i= 1; i <= n; i++)
       Hash = (Hash * MAGIC + answer[i]) % MOD;

    return (int)Hash;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            first[i] = first2[i] = -1;

        cnt = 0;
        for(int i = 2; i <= n; i++)
        {
            int fa;
            scanf("%d", &fa);
            arc[cnt].v = i;
            arc[cnt].next = first[fa];
            first[fa] = cnt++;
        }

        int Q;
        scanf("%d", &Q);
        cnt = 0;
        for(int i = 1; i <= Q; i++)
        {
            int u, l, r, delta;
            scanf("%d%d%d%d", &u, &l, &r, &delta);

            addQuery(u, l, delta);
            addQuery(u, r + 1, -delta);
        }

        dfs(1, 1);
        printf("Case %d: %d\n", cas, solve());
    }
    return 0;
}
