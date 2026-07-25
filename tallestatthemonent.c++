#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        int h, l;
        cin >> h >> l;
        a[i] = {l, h};
    }
    sort(a.begin(), a.end());
    vector<int> leave(n);
    vector<int> mx(n);

    for (int i = 0; i < n; i++) {
        leave[i] = a[i].first;
        mx[i] = a[i].second;
    }
    for (int i = n - 2; i >= 0; i--) {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        int pos = upper_bound(leave.begin(), leave.end(), t)- leave.begin();
        cout << mx[pos] << '\n';
    }
    return 0;
}