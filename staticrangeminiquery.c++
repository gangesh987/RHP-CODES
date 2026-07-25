#include <bits/stdc++.h>
using namespace std;
vector<int> arr, seg;
void build(int node, int left, int right) {
    if (left == right) {
        if (left < arr.size())
            seg[node] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2 * node + 1, left, mid);
    build(2 * node + 2, mid + 1, right);
    seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
}
int query(int node, int left, int right, int ql, int qr) {
    if (right < ql || left > qr)
        return INT_MAX;
    if (ql <= left && right <= qr)
        return seg[node];
    int mid = (left + right) / 2;
    return min(query(2 * node + 1, left, mid, ql, qr),
               query(2 * node + 2, mid + 1, right, ql, qr));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int size = 1;
    while (size < n)
        size *= 2;
    seg.assign(2 * size - 1, INT_MAX);
    build(0, 0, size - 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, size - 1, l - 1, r - 1) << "\n";
    }
}
