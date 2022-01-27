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
vi vec, seg_idx, seg_init;
vector<vpll> seg;

void init(int node, int start, int end) {
    if (start == end) return void(seg[node] = {{seg_init[start], seg_init[start]}});
    int mid = (start + end) >> 1;
    init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end);
    auto A = seg[node * 2], B = seg[node * 2 + 1];
    seg[node].resize(end - start + 1);
    merge(all(A), all(B), seg[node].begin());
    ll sum = 0;
    for (int i = 0; i < seg[node].size(); i++) sum += seg[node][i].first, seg[node][i].second = sum;
}

ll qry(int node, int start, int end, int l, int r, int x, int y) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) {
        ll left = 0, right = 0;
        auto it = lower_bound(all(seg[node]), pll(x, 0));
        if (it > seg[node].begin()) left = (--it)->second;
        it = upper_bound(all(seg[node]), pll(y + 1, 0));
        if (it > seg[node].begin()) right = (--it)->second;
        return right - left;
    }
    int mid = (start + end) >> 1;
    return qry(node * 2, start, mid, l, r, x, y) + qry(node * 2 + 1, mid + 1, end, l, r, x, y);
}

vi par, sz, depth, chain_top;
vector<vi> graph;

void dfs1(int u, int prv) {
    sz[u] = 1;
    pii mx = {0, 0};
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v == prv) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs1(v, u);
        sz[u] += sz[v];
        mx = max(mx, {sz[v], i});
    }
    if (mx.second) swap(graph[u][mx.second], graph[u][0]);
}

void dfs2(int u, int prv) {
    seg_idx[u] = ++idx;
    seg_init[idx] = vec[u];
    for (int v : graph[u]) {
        if (v == prv) continue;
        chain_top[v] = graph[u][0] == v ? chain_top[u] : v;

        dfs2(v, u);
    }
}

ll solve(int u, int v, int x, int y) {
    ll ret = 0;
    while (chain_top[u] != chain_top[v]) {
        if (depth[chain_top[u]] < depth[chain_top[v]]) swap(u, v);
        int nxt = chain_top[u];
        ret += qry(1, 1, n, seg_idx[nxt], seg_idx[u], x, y);
        u = par[nxt];
    }
    if (depth[u] > depth[v]) swap(u, v);
    ret += qry(1, 1, n, seg_idx[u], seg_idx[v], x, y);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q; cin >> n >> q;
    vec.resize(n + 1), seg_idx.resize(n + 1), seg_init.resize(n + 1);
    seg.resize(n * 4);
    par.resize(n + 1), sz.resize(n + 1), depth.resize(n + 1), chain_top.resize(n + 1);
    graph.resize(n + 1);

    for (int &i : vec | views::drop(1)) cin >> i;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0);
    init(1, 1, n);

    while (q--) {
        int u, v, x, y; cin >> u >> v >> x >> y;
        cout << solve(u, v, x, y) << "\n";
    }
}
