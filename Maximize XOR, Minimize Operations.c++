#include <bits/stdc++.h>
using namespace std;

long long a, b;
long long INF = 4e18;

long long solve() {
    long long dp[2][2][2], ndp[2][2][2];

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                dp[i][j][k]=INF;

    dp[0][0][0]=0;

    for(int bit=0;bit<62;bit++) {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    ndp[i][j][k]=INF;

        int x=(a>>bit)&1;
        int y=(b>>bit)&1;

        for(int br=0;br<2;br++) {
            for(int ca=0;ca<2;ca++) {
                for(int less=0;less<2;less++) {
                    if(dp[br][ca][less]==INF) continue;

                    for(int k=0;k<2;k++) {
                        int nl=less;

                        if(!less) {
                            if(k>x) continue;
                            if(k<x) nl=1;
                        }

                        int p=x-br-k;
                        int A=(p+2)%2;
                        int nbr=(p<0);

                        int q=y+ca+k;
                        int B=q%2;
                        int nca=q/2;

                        if(A&B) continue;

                        long long val=dp[br][ca][less];
                        if(k) val+=(1LL<<bit);

                        ndp[nbr][nca][nl]=min(ndp[nbr][nca][nl],val);
                    }
                }
            }
        }

        memcpy(dp,ndp,sizeof(dp));
    }

    long long ans=INF;

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                ans=min(ans,dp[i][j][k]);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--) {
        cin>>a>>b;
        cout<<a+b<<" "<<solve()<<'\n';
    }

    return 0;
}