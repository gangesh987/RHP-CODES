#include <bits/stdc++.h>
using namespace std;

struct Bus {
    long long s, t, val;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long l, x, y;
    cin >> n >> m >> l >> x >> y;

    vector<Bus> bus(n);

    for (int i = 0; i < n; i++) {
        cin >> bus[i].s >> bus[i].t;
        bus[i].val = bus[i].s * y + bus[i].t * (x - y);
    }

    sort(bus.begin(), bus.end(), [](Bus a, Bus b) {
        return a.s < b.s;
    });

    vector<pair<long long,int>> people(m);

    for (int i = 0; i < m; i++) {
        cin >> people[i].first;
        people[i].second = i;
    }

    sort(people.begin(), people.end());

    priority_queue<pair<long long,long long>> pq;

    vector<double> ans(m);

    int j = 0;

    for (auto [p, id] : people) {
        while (j < n && bus[j].s <= p) {
            pq.push({bus[j].val, bus[j].t});
            j++;
        }

        while (!pq.empty() && pq.top().second < p)
            pq.pop();

        double best = (double)(l - p) / y;

        if (!pq.empty()) {
            double busTime =
                (double)(l * x - pq.top().first) / (x * y);
            best = min(best, busTime);
        }

        ans[id] = best;
    }

    cout << fixed << setprecision(10);

    for (double v : ans)
        cout << v << '\n';

    return 0;
}