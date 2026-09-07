#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(m + 2);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<int> pref(m + 2);
        for (int i = 1; i <= m; i++) {
            pref[i] = pref[i - 1] + cnt[i];
        }
        int ans = 0;
        for (int x = 1; x <= m; x++) {
            int cur = n - pref[x - 1];
            if (2 * x <= m)
                cur += cnt[2 * x];
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}