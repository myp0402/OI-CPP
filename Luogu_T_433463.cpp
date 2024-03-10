#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5 + 10;

int a[N], disa[N], backup[N];

int main()
{
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int T=0;
        cin >> T;

        while (T--) {
                int n, cnt = 0;
                cin >> n;
                for (int i = 0; i < n; i++) {
                        cin >> a[i];
                }
                for (int i = 0; i < n; i++) {
                        backup[cnt++] = a[i];
                }
                sort(backup, backup + n);
                int len = unique(backup, backup + n) - backup;

                for (int i = 0; i < n; i++) {
                        disa[i] = lower_bound(backup, backup + len, a[i]) - backup + 1;
                }
                for (int i = 0; i < n; i++) {
                        cout << disa[i] << ' ';
                }
                cout << endl;
        }
        return 0;
}