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
vi par, sz, depth, chain, seg, seg_idx;
vector<vi> graph, path;

void upd(int node, int start, int end, int l, int r) {
    if (end < l || r < start) return;
    if (l <= start && end <= r) return void(seg[node] += 1);
    int mid = (start + end) >> 1;
    upd(node * 2, start, mid, l, r);
    upd(node * 2 + 1, mid + 1, end, l, r);
}

int qry(int node, int start, int end, int k) {
    if (!(start <= k && k <= end)) return 0;
    if (start == end) return seg[node];
    int mid = (start + end) >> 1;
    return seg[node] + qry(node * 2, start, mid, k) + qry(node * 2 + 1, mid + 1, end, k);
}

void dfs(int u) {
    sz[u] = 1;
    for (int &v: graph[u]) {
        depth[v] = depth[u] + 1;
        dfs(v);
        sz[u] += sz[v];
        if (sz[graph[u][0]] < sz[v]) swap(graph[u][0], v);
    }
}

void dfs2(int u) {
    seg_idx[u] = ++idx;
    for (int v: graph[u]) {
        chain[v] = graph[u][0] == v ? chain[u] : v;
        path[chain[v]].push_back(v);
        dfs2(v);
    }
}

void add(int u, int v) {
    while (chain[u] != chain[v]) {
        if (depth[chain[u]] < depth[chain[v]]) swap(u, v);
        int nxt = chain[u];
        upd(1, 1, n, seg_idx[nxt], seg_idx[u]);
        u = par[nxt];
    }
    if (depth[u] > depth[v]) swap(u, v);
    upd(1, 1, n, seg_idx[u], seg_idx[v]);
}

// new node -> v(centroid)
int start(int u, int v) {
    int last = 0;
    while (chain[u] != chain[v]) {
        if (depth[chain[u]] < depth[chain[v]]) return par[v];
        last = chain[u];
        u = par[last];
    }
    if (depth[u] < depth[v]) return par[v];
    if (u == v) return last;
    return *upper_bound(all(path[chain[v]]), v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    graph.resize(n + 1);
    par.resize(n + 1), sz.resize(n + 1), depth.resize(n + 1), chain.resize(n + 1);
    seg.resize(n * 4), seg_idx.resize(n + 1), path.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        par[i] = p;
        graph[p].push_back(i);
    }

    dfs(1);
    dfs2(1);
    upd(1, 1, n, seg_idx[1], seg_idx[1]);

    int ans = 1;
    cout << ans << " ";
    for (int i = 2; i <= n; i++) {
        add(1, i);
        int v = start(i, ans);
        if (par[ans] == v) {
            if (qry(1, 1, n, seg_idx[ans]) * 2 <= i) ans = v;
        } else {
            if (qry(1, 1, n, seg_idx[v]) * 2 > i) ans = v;
        }
        cout << ans << " ";
    }
}
