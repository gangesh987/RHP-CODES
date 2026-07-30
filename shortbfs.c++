#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(int N, int E, vector<vector<int>> edges, int s) {
    vector<vector<int>> g(N + 1);
    for (int i = 0; i < E; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(N + 1, -1);
    vector<bool> vis(N + 1, false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    vector<int> res;
    for (int i = 1; i <= N; i++) {
        if (i == s) continue;
        if (dist[i] == -1)
            res.emplace_back(-1);
        else
            res.emplace_back(dist[i] * 6);
    }
    return res;
}