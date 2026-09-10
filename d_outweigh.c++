#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define ll long long

void solve() {
    int n; cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    ll am=0,bm=0;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]) am+=(a[i]-b[i]);
        else if(a[i]<b[i]) bm+=(b[i]-a[i]);
    }
    if(am==0){
        cout<<"No"<<endl;
        return;
    }
    ll awt=(bm/am)+2;
    vector<ll> ans;
    for(int i=0;i<n;i++){
        if(a[i]<=b[i]) ans.push_back(1);
        else ans.push_back(awt);
    }
    cout<<"Yes"<<endl;
    for(ll w:ans) cout<<w<<" ";
    cout<<endl;
    
}

int main() {
    solve();
    return 0;
}