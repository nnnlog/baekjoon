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

int idx;
vi vis, depth;
vector<vi> graph;

void dfs(int u) {
    vis[u] = ++idx;
    for (int v : graph[u]) {
        if (!depth[v]) depth[v] = depth[u] + 1, dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r; cin >> n >> m >> r;
    vis.resize(n + 1), depth.resize(n + 1), graph.resize(n + 1);
    while (m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (auto &v : graph) sort(all(v), greater<>());
    depth[r] = 1;
    dfs(r);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += ll(depth[i] - 1) * vis[i];
    cout << ans;
}
