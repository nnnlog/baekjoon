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

    int n, m; cin >> n >> m;
    vector<vpii> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].emplace_back(b, i);
        graph[b].emplace_back(a, i);
    }

    vl dist(n + 1, 1e18);
    priority_queue<pll, vpll, greater<>> pq;
    pq.emplace(dist[1] = 0, 1);

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        ll curr = top.first, u = top.second;
        for (const auto &[v, open] : graph[u]) {
            ll nxt = open - (curr % m);
            if (nxt < 0) nxt += m;
            nxt += curr + 1;
            if (dist[v] > nxt) pq.emplace(dist[v] = nxt, v);
        }
    }

    cout << dist[n];
}
