#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &ldr,int i){
    if(ldr[i]!=i){
        ldr[i]=find(ldr,ldr[i]);
    }
    return ldr[i];
}
void join(vector<int> &ldr,int l,int r){
    int x=find(ldr,l);
    int y=find(ldr,r);
    ldr[y]=x;
}
int main(){
    int n,m; cin>>n>>m;
    vector<int> ldr(n+1);
    for(int i=1;i<=n;i++) ldr[i]=i;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
        join(ldr,u,v);
    }
    vector<long long> gc(n+1,0), ec(n+1,0);
    for(int i=1;i<=n;i++)
        gc[find(ldr,i)]++;

    for(auto e:edges){
        int u=e.first;
        ec[find(ldr,u)]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans += gc[i]*(gc[i]-1)/2 - ec[i];
    }

    cout<<ans;
    return 0;
}
