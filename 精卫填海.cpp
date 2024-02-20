#include<bits/stdc++.h>


using namespace std;

int v, n, c, dp[10500], a[10050], b[10050];

int main() {

    cin >> v >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> b[i] >> a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = c; j >= a[i]; j--)

            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
    }

    for (int i = 1; i <= c; i++) {

        if (dp[i] >= v) {
            cout << c - i;
            return 0;
        }
    }

    puts("Impossible");

}