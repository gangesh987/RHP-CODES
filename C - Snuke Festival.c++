#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    long long ans = 0;

    for (int x : b) {
        long long upper = lower_bound(a.begin(), a.end(), x) - a.begin();
        long long lower = c.end() - upper_bound(c.begin(), c.end(), x);

        ans += upper * lower;
    }

    cout << ans << '\n';

    return 0;
}