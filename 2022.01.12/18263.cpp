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

int n, idx;
vi vec, par, sz, depth, chain, seg_idx;
vector<vi> graph;
vector<mpii> seg;

void upd(int node, int start, int end, int k, int v) {
    if (!(start <= k && k <= end)) return;
    seg[node][v] = 1;
    if (start == end) return;
    int mid = (start + end) >> 1;
    upd(node * 2, start, mid, k, v);
    upd(node * 2 + 1, mid + 1, end, k, v);
}

int qry(int node, int start, int end, int l, int r, int v) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return seg[node].count(v);
    int mid = (start + end) >> 1;
    return qry(node * 2, start, mid, l, r, v) || qry(node * 2 + 1, mid + 1, end, l, r, v);
}

void dfs(int u, int prv) {
    sz[u] = 1;
    pii mx = {0, 0};
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v == prv) continue;
        depth[v] = depth[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
        mx = max(mx, {sz[v], i});
    }
    if (mx.second) swap(graph[u][0], graph[u][mx.second]);
}

void dfs2(int u, int prv) {
    seg_idx[u] = ++idx;
    upd(1, 1, n, idx, vec[u]);
    for (int v: graph[u]) {
        if (v == prv) continue;
        chain[v] = graph[u][0] == v ? chain[u] : v;
        dfs2(v, u);
    }
}

int solve(int u, int v, int a) {
    while (chain[u] != chain[v]) {
        if (depth[chain[u]] < depth[chain[v]]) swap(u, v);
        int nxt = chain[u];
        if (qry(1, 1, n, seg_idx[nxt], seg_idx[u], a)) return 1;
        u = par[nxt];
    }
    if (depth[u] > depth[v]) swap(u, v);
    return qry(1, 1, n, seg_idx[u], seg_idx[v], a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> n >> q;
    graph.resize(n + 1), vec.resize(n + 1), par.resize(n + 1), sz.resize(n + 1), depth.resize(n + 1);
    chain.resize(n + 1), seg_idx.resize(n + 1), seg.resize(n * 4);
    for (int &i : vec | views::drop(1)) cin >> i;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 1);
    dfs2(1, 1);
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        cout << solve(a, b, c);
    }
}
