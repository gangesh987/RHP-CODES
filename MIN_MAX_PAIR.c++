#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == i)
            s++;
    }
    long long ans = s * (s - 1) / 2;
    for (int i = 1; i <= n; i++) {
        if (a[i] > i && a[a[i]] == i)
            ans++;
    }
    cout << ans;
}