#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vi cost(n + 1);
    for (int &i: cost | views::drop(1)) cin >> i;
    vector<vpii> graph(n + 1);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    vector<vl> dist(n + 1, vl(2501, 1e18));
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<>> pq;
    pq.push({dist[1][cost[1]] = 0, {1, cost[1]}});
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int u = top.second.first, curr_cost = top.second.second;
        if (dist[u][curr_cost] < top.first) continue;
        int nxt_cost = min(curr_cost, cost[u]);
        for (const auto &[v, w] : graph[u]) {
            ll nxt = top.first + nxt_cost * ll(w);
            if (dist[v][nxt_cost] > nxt) pq.push({dist[v][nxt_cost] = top.first + nxt_cost * ll(w), {v, nxt_cost}});
        }
    }

    cout << *min_element(all(dist[n]));
}
