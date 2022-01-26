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

int idx, n;
vector<vi> graph;
vi par, sz, depth, chain, seg_idx, seg;

int upd(int node, int start, int end, int k) {
    if (!(start <= k && k <= end)) return seg[node];
    if (start == end) return seg[node] = 1;
    int mid = (start + end) >> 1;
    return seg[node] = upd(node * 2, start, mid, k) + upd(node * 2 + 1, mid + 1, end, k);
}

int qry(int node, int start, int end, int l, int r) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return seg[node];
    int mid = (start + end) >> 1;
    return qry(node * 2, start, mid, l, r) + qry(node * 2 + 1, mid + 1, end, l, r);
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
    if (mx.second) swap(graph[u][mx.second], graph[u][0]);
}

void dfs2(int u, int prv) {
    for (int v: graph[u]) {
        if (v == prv) continue;
        chain[v] = graph[u][0] == v ? chain[u] : v;
        seg_idx[v] = ++idx;

        dfs2(v, u);
    }
}

int solve(int u, int v) {
    while (chain[u] != chain[v]) {
        if (depth[chain[u]] < depth[chain[v]]) swap(u, v);
        int nxt = chain[u];
        if (qry(1, 1, n, seg_idx[nxt], seg_idx[u])) return 0;
        u = par[nxt];
    }
    if (depth[u] > depth[v]) swap(u, v);
    if (u != v && qry(1, 1, n, seg_idx[u] + 1, seg_idx[v])) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> n >> q;

    graph.resize(n + 1), par.resize(n + 1), sz.resize(n + 1), depth.resize(n + 1);
    seg_idx.resize(n + 1), chain.resize(n + 1), seg.resize(n * 4);

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        graph[i].push_back(p);
        graph[p].push_back(i);
    }

    dfs(1, 0);
    ++idx;
    dfs2(1, 0);

    while (q--) {
        int b, c, d;
        cin >> b >> c >> d;
        int ans = solve(b, c);
        cout << (ans ? "YES" : "NO") << "\n";
        if (d) upd(1, 1, n, seg_idx[ans ? b : c]);
    }
}
