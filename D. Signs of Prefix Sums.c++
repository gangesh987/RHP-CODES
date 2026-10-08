#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qrTNum;
    cin >> qrTNum;

    while (qrTNum--) {
        int n;
        string s;
        cin >> n >> s;

        const int INF = 1e9;
        int dp[7], ndp[7];

        for (int i = 0; i < 7; i++)
            dp[i] = INF;

        dp[3] = 0;

        for (char c : s) {
            for (int i = 0; i < 7; i++)
                ndp[i] = INF;

            int l, r;

            if (c == '-') {
                l = 0;
                r = 2;
            } else if (c == '0') {
                l = r = 3;
            } else {
                l = 4;
                r = 6;
            }

            for (int i = 0; i < 7; i++) {
                if (dp[i] == INF)
                    continue;

                for (int j = l; j <= r; j++) {
                    if (i == j)
                        continue;

                    ndp[j] = min(ndp[j],
                                 max(dp[i], abs(i - j)));
                }
            }

            for (int i = 0; i < 7; i++)
                dp[i] = ndp[i];
        }

        int ans = *min_element(dp, dp + 7);

        if (ans == INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}