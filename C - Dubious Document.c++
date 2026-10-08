#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> mn(26, 1e9);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        for (int j = 0; j < 26; j++)
            mn[j] = min(mn[j], cnt[j]);
    }

    for (int i = 0; i < 26; i++) {
        while (mn[i]--)
            cout << char('a' + i);
    }

    cout << '\n';

    return 0;
}