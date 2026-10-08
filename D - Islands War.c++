#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int last = -1;

    for (auto p : v) {
        int r = p.first - 1;
        int l = p.second;

        if (last < l) {
            last = r;
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}