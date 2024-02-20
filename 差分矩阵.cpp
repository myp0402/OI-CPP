#include<bits/stdc++.h>
using namespace std;
int n, m, q, a[1010][1010], d[1010][1010], x1, yi, x2, y2, v;
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d",a[i][j]);
            d[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d%d%d%d%d",&x1,&yi,&x2,&y2,&v);
        d[x1][yi] += v;
        d[x2 + 1][yi] -= v;
        d[x1][y2 + 1] -= v;
        d[x2 + 1][y2 + 1] += v;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1] + d[i][j];
            printf("%d ",d[i][j]);
        }
    }
}