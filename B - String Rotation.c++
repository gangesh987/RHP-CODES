#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() == b.size() && (a + a).find(b) != string::npos)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}