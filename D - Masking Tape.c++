#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s(n, 'a');
    vector<bool> tile(n, false);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            x--;

            tile[x] = !tile[x];
        } else {
            char c;
            cin >> c;

            for (int i = 0; i < n; i++) {
                if (!tile[i])
                    s[i] = c;
            }
        }
    }

    cout << s << '\n';

    return 0;
}