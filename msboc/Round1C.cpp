/* ����Ǿ���ֵ֮����С��ֻ��Ҫ��λ���Ϳ����ˣ������ʹ��������С��ֻ��Ҫ����+�߶θ���ͳ�ƣ�
** ��������ÿ���㶼�и��������㣬����x��仯������֮��Ӧ���Ǹ������������뵽���֣�
** ������Ҫע�����ƴ�������Ȼ���׳�ʱ
** ���ӣ�http://www.cnblogs.com/dango/p/3675259.html
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

double eps = 1e-10;

int sgn(double x)
{
    return x < -eps ? -1 : x > eps;
}

int n;
struct Point
{
    double x, y;
    void input()
    {
        scanf("%lf%lf", &x, &y);
        y *= y;
    }

    double cal(double xx)
    {
        return sqrt(y + (xx - x) * (xx - x));
    }
}p[100010];

double cal(double x)
{
    double ans = 0;
    for(int i = 0; i < n; i++)
        ans += p[i].cal(x);

    return ans;
}
double solve()
{
    double l = 1e100, r = -1e100;
    for(int i = 0; i < n; i++)
    {
        double  x = p[i].x;
        l = min(l, x);
        r = max(r, x);
    }

    double x1 = l,x2, x3, x4 = r, ans;
    for(int i = 0; i <= 100 && sgn(x4 - x1) > 0; i++)
    {
        x2 = x1 + (x4 - x1) / 3;
        x3 = x2 + (x4 - x1) / 3;

        double f2 = cal(x2), f3 = cal(x3);
        ans = x2;
        if(sgn(f2 - f3) > 0)
            x1 = x2;
        else
            x4 = x3;
    }

    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <=T; cas++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            p[i].input();

        printf("Case %d: %.10lf\n", cas, solve());
    }
    return 0;
}
