/**************************************************************
** Problem: 1130 动态规划 - 拔河
** 算法导论第15章
** User： ibillxia(ibillxia@gmail.com)
**************************************************************/
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool w[101][45010];

int main()
{
    int n, i, j, k, x, y, t, maxi;
    int a[101], b[101];
    while (scanf("%d", &n) != EOF) {
        b[0] = 0;
        memset(w, 0, sizeof(w));
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = b[i - 1] + a[i];
        }
        maxi = b[n];
        w[0][0] = true;
        for (i = 1; i <= n; i++) {
            k = n / 2;
            if (k >= i)
                k = i - 1;
            for (; k >= 0; k--) {
                for (j = a[i]; j <= b[i]; j++)
                    if (w[k][j - a[i]])
                        w[k + 1][j] = true;
            }
        }
        k = n / 2;
        if(n&1) {
            for (j = 0; j <= b[n]/2; j++) {
                if ((w[k][j]||w[k+1][j]) && maxi > fabs(b[n] - 2 * j)) {
                    maxi = fabs(b[n] - 2 * j);
                    x = j;
                    y = b[n] - j;
                }
            }
        } else {
            for (j = 0; j <= b[n]/2; j++) {
                if (w[k][j] && maxi > fabs(b[n] - 2 * j)) {
                    maxi = fabs(b[n] - 2 * j);
                    x = j;
                    y = b[n] - j;
                }
            }
        }

        printf("%d %d\n", x, y);
    }
    return 0;
}
