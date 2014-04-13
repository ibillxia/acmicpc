// Reference:http://www.huangwenchao.com.cn/2014/04/ms2014-warmup.html
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge {
    int x, y, d;
    Edge(int x=0, int y=0, int d=0) :
        x(x), y(y), d(d) {}
};

bool operator < (const Edge& lhs, const Edge& rhs)
{
    return lhs.x<rhs.x || lhs.x==rhs.x && lhs.y<rhs.y;
}

int T, N, M, K;
Edge ee[200000], *ptr;
int _lca[20][100000], hgt[100000], len[100000], *pre = _lca[0];
int mxh, mxb;
int stk[100], sz;

void dfs(const int& k)
{
    for(Edge *p = lower_bound(ee, ee+N+N-2, Edge(k));
            p->x == k; ++p) {
        if(pre[p->y] == -1) {
            pre[p->y] = k;
            hgt[p->y] = hgt[k]+1;
            len[p->y] = p->d;
            dfs(p->y);
            mxh = max(mxh, hgt[p->y]);
        }
    }
}

int lca(int v, int w)
{
    if(hgt[v] < hgt[w]) swap(v, w);
    for(int b = mxb; hgt[v] > hgt[w] && b >= 0; --b)
        if(hgt[v] - (1<<b) >= hgt[w]) v = _lca[b][v];
    for(int b = mxb; v != w && b >= 0; --b)
        if(_lca[b][v] != -1 && _lca[b][v] != _lca[b][w])
            v = _lca[b][v], w = _lca[b][w];
    return v==w ? v : pre[v];
}

int main()
{
    scanf("%d", &T);
    for(int t = 0; t < T; ++t) {
        printf("Case #%d:\n", t+1);
        scanf("%d", &N);
        ptr = ee;
        for(int i = 1, x, y, d; i < N; ++i) {
            scanf("%d%d%d", &x, &y, &d);
            ptr->x = x-1;
            ptr->y = y-1;
            ptr->d = d;
            ++ptr;
            ptr->y = x-1;
            ptr->x = y-1;
            ptr->d = d;
            ++ptr;
        }
        sort(ee, ee+N+N-2);
        // init_tree
        memset(pre, -1, sizeof(int)*N);
        pre[0] = hgt[0] = len[0] = mxh = 0;
        dfs(0);
        // init_lca
        pre[0] = 0;
        for(int b = 1; (1<<b)<=mxh; ++b) {
            mxb = b;
            for(int i = 0, p; i < N; ++i) {
                p = _lca[b-1][i];
                _lca[b][i] = p==-1 ? -1 : _lca[b-1][p];
            }
        }
        // do query
        for(scanf("%d", &M); M--;) {
            int x, y;
            scanf("%d%d", &x, &y);
            int z = lca(--x, --y);
            if(hgt[x]+hgt[y]-hgt[z]-hgt[z] > 45) {
                puts("Yes");
                continue;
            }
            sz = 0;
            while(x != z) {
                stk[sz++] = len[x];
                x = pre[x];
            }
            while(y != z) {
                stk[sz++] = len[y];
                y = pre[y];
            }
            sort(stk, stk+sz);
            bool yes = false;
            for(int i = 2; !yes && i < sz; ++i)
                if(stk[i-2]+stk[i-1] > stk[i])
                    yes = true;
            puts(yes ? "Yes" : "No");
        }
    }
    return 0;
}
