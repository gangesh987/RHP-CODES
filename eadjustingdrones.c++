#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> cnt(3 * n + 5, 0);

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }

        int ans = 0;

        vector<int> extra(cnt.size(), 0);

        for (int x = 1; x < (int)cnt.size() - 1; ++x) {
            int c = cnt[x];

            if (c <= k)
                continue;

            int need = c - k;
            int operations = 1;
            int current = c;

            while (current > k) {
                current = 1 + (current - 1);
                operations++;
                break;
            }
        }

        fill(extra.begin(), extra.end(), 0);

        int mx = 0;

        for (int x = 1; x < (int)cnt.size() - 1; ++x) {
            extra[x] += cnt[x];

            if (extra[x] <= k)
                continue;

            int excess = extra[x] - k;
            extra[x + 1] += excess;
            mx = max(mx, 1);
        }

        vector<int> v;
        v.reserve(n);

        for (int x = 1; x < (int)cnt.size(); ++x) {
            for (int j = 0; j < cnt[x]; ++j)
                v.push_back(x);
        }

        unordered_map<int, int> used;
        used.reserve(n * 2);

        for (int x : v)
            used[x]++;

        map<int, int> freq;

        for (int x : v)
            freq[x]++;

        ans = 0;

        while (true) {
            vector<pair<int, int>> moves;

            for (auto [x, c] : freq) {
                if (c > k)
                    moves.push_back({x, c - 1});
            }

            if (moves.empty())
                break;

            for (auto [x, amount] : moves) {
                freq[x] -= amount;
                freq[x + 1] += amount;
            }

            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}