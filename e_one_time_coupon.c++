#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    int mini = 2e9;
    ll base = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;

        mini = min(mini, arr[i].first);
        base += arr[i].first;
    }

    sort(arr.begin(), arr.end(), [](const pair<int, int>& a,
                                    const pair<int, int>& b) {
        return a.first - a.second > b.first - b.second;
    });

    ll ans = base;

    for (int i = 1; i <= N; i++) {
        base -= arr[i - 1].first;
        base += arr[i - 1].second;
        ll curr = base + ((N - i) >= i ? 0 : 1LL * mini * (i - (N - i)));

        ans = min(ans, curr);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}