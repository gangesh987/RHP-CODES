#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> zi;
    for(int i=0;i<n;i++){
        int cur; cin>>cur;
        if(cur==0) zi.push_back(i);
    }
    if(zi.size()==1){
        cout<<"NO"<<endl;
        return;
    }
    string s(n,'C');
    if(zi.size()>0){
        int fzi=zi[0];
        s[fzi]='B';
        for(unsigned int i=1;i<zi.size();i++){
            s[zi[i]]='A';
        }
    }
    cout<<"YES"<<endl<<s<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}