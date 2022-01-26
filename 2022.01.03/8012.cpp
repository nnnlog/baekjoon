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

vector<vi> graph;
vi par, depth;

void dfs(int u, int prv) {
    for (int v: graph[u]) if (v != prv) par[v] = u, depth[v] = depth[u] + 1, dfs(v, u);
}

pii table[16][30001];

int lca(int u, int v) {
    int ret = 0;
    if (depth[u] > depth[v]) swap(u, v);
    for (int i = 15; i >= 0; i--)
        if ((depth[v] - depth[u]) & (1 << i))
            ret += table[i][v].second, v = table[i][v].first;
    if (u == v) return ret;
    for (int i = 15; i >= 0; i--)
        if (table[i][u].first != table[i][v].first)
            ret += table[i][u].second + table[i][v].second, u = table[i][u].first, v = table[i][v].first;
    ret += 2;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    graph.resize(n + 1), par.resize(n + 1), depth.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 1);

    for (int i = 1; i <= n; i++) table[0][i] = {par[i], 1};
    for (int i = 1; i <= 15; i++)
        for (int j = 1; j <= n; j++)
            table[i][j] = {table[i - 1][table[i - 1][j].first].first,
                           table[i - 1][table[i - 1][j].first].second + table[i - 1][j].second};

    ll ans = 0;
    int prv = 1, m;
    cin >> m;
    while (m--) {
        int a;
        cin >> a;

        ans += lca(a, prv);
        prv = a;
    }

    cout << ans;
}
