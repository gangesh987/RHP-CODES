#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &ldr, int x) {
    if (ldr[x] == x) return x;
    return ldr[x] = find(ldr, ldr[x]);
}
void join(vector<int> &ldr, int lt, int rt) {
    ldr[find(ldr, lt)] = find(ldr, rt);
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), ldr(n + 1);
    map<int, int> vlm, lvm;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (vlm.find(a[i]) == vlm.end()) {
            vlm[a[i]] = i;
            lvm[i] = a[i];
        }
        ldr[i] = vlm[a[i]];
    }
    while (q--) {
        int qt;
        cin >> qt;
        if (qt == 1) {
            int x, y;
            cin >> x >> y;
            if (x == y) continue;
            if (vlm.find(x) == vlm.end()) continue;
            if (vlm.find(y) != vlm.end()) {
                int lx = find(ldr, vlm[x]);
                int ly = find(ldr, vlm[y]);
                if (lx == ly) continue;
                join(ldr, lx, ly);
                lvm.erase(lx);
                vlm.erase(x);
            }
            else {
                int lx = find(ldr, vlm[x]);
                lvm[lx] = y;
                vlm.erase(x);
                vlm[y] = lx;
            }
        }
        else {
            int idx;
            cin >> idx;
            cout << lvm[find(ldr, ldr[idx])] << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout << "Case " << tc << ":\n";
        solve();
    }
    return 0;
}
