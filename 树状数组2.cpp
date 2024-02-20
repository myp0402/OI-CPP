#include<bits/stdc++.h>
using namespace std;
const int N = 1e8 + 10;
int s[N], t[N], n, m, num, x, y, k, cf[N];

int lowbit(int a) {
    return a & -a;
}

void add(int a, int b) {
    for (int i = a; i <= n; i += lowbit(i)) t[i] += b;
}

int sum(int a) {
    int ans = 0;
    for (int i = a; i; i -= lowbit(i))
        ans += t[i];
    return ans;
}

int main() {
    scanf("%d%d", & n, & m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", & s[i]);
        cf[i] = s[i] - s[i - 1];
    }
    for (int i = 1; i <= n; i++) add(i, cf[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d", & num);
        if (num == 1) {
            scanf("%d%d%d", & x, & y, & k);
            add(x, k);
            add(y + 1, -k);
        } else {
            scanf("%d", & x);
            printf("%d\n", sum(x));
        }
    }
}