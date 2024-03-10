#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 3e5 + 10;

int pf[N], pd[N], ps[N];

void init(int m)
{
        for (int i = 1; i <= m; i++) {
                pf[i] = i;
                ps[i] = 1;
        }
}

int find(int x)
{
        if (x != pf[x]) {
                int root = find(pf[x]);
                pd[x] += pd[pf[x]];
                pf[x] = root;
        }
        return pf[x];
}

void merge(int x, int y)
{
        int prntx = find(x), prnty = find(y);
        pd[prntx] = ps[prnty];
        ps[prnty] += ps[prntx];
        pf[prntx] = prnty;
}

int main()
{
        // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int n;
        cin >> n;
        init(N);

        while (n--) {
                char flag;
                int i, j;
                cin >> flag;
                cin >> i >> j;
                if (flag == 'M') {
                        merge(i, j);
                } else {
                        cout << ((find(i)==find(j))?(abs(pd[i]-pd[j])-1):(-1)) << endl;
                }
        }
        return 0;
}