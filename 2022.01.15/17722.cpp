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
vi par, sz, depth, chain, seg_idx, seg, lazy;
vector<vi> graph;

void prop(int node, int start, int end) {
    if (lazy[node]) {
        seg[node] += (end - start + 1) * min(2, lazy[node]);
        seg[node] = min(seg[node], (end - start + 1) * 2);
        if (start != end) lazy[node * 2] += lazy[node], lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }
}

int upd(int node, int start, int end, int l, int r) {
    prop(node, start, end);
    if (end < l || r < start) return seg[node];
    if (l <= start && end <= r) {
        lazy[node] = 1;
        prop(node, start, end);
        return seg[node];
    }
    int mid = (start + end) >> 1;
    return seg[node] = upd(node * 2, start, mid, l, r) + upd(node * 2 + 1, mid + 1, end, l, r);
}

int qry(int node, int start, int end, int l, int r) {
    if (end < l || r < start) return 0;
    prop(node, start, end);
    if (l <= start && end <= r) return seg[node];
    int mid = (start + end) >> 1;
    return qry(node * 2, start, mid, l, r) + qry(node * 2 + 1, mid + 1, end, l, r);
}

void dfs(int u, int prv) {
    sz[u] = 1;
    for (int &v : graph[u]) {
        if (v == prv) continue;
        depth[v] = depth[u] + 1;
        par[v] = u;

        dfs(v, u);

        sz[u] += sz[v];
        if (sz[graph[u][0]] < sz[v]) swap(graph[u][0], v);
    }
}

void dfs2(int u, int prv) {
    for (int v : graph[u]) {
        if (v == prv) continue;
        chain[v] = graph[u][0] == v ? chain[u] : v;
        seg_idx[v] = ++idx;

        dfs2(v, u);
    }
}

vi UF;
int find(int a) {
    return UF[a] = a == UF[a] ? a : find(UF[a]);
}
int merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) return UF[a] = b, 1;
    return 0;
}

vector<pair<pii, pii>> Q;

int solve(int u, int v, int f) {
    int ret = 0, dist = 0;
    while (chain[u] != chain[v]) {
        if (depth[chain[u]] < depth[chain[v]]) swap(u, v);
        int nxt = chain[u];
        if (f) upd(1, 1, n, seg_idx[nxt], seg_idx[u]);
        else ret += qry(1, 1, n, seg_idx[nxt], seg_idx[u]), dist += depth[u] - depth[nxt] + 1;
        u = par[nxt];
    }
    if (u != v) {
        if (depth[u] > depth[v]) swap(u, v);
        if (f) upd(1, 1, n, seg_idx[u] + 1, seg_idx[v]);
        else ret += qry(1, 1, n, seg_idx[u] + 1, seg_idx[v]), dist += depth[v] - depth[u];
    }
    return 2 * dist - ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m; cin >> n >> m;
    UF.resize(n + 1);
    iota(all(UF), 0);

    par.resize(n + 1), sz.resize(n + 1), depth.resize(n + 1), chain.resize(n + 1), seg_idx.resize(n + 1);
    seg.resize(n * 4), lazy.resize(n * 4);
    graph.resize(n + 1);

    Q.reserve(m);
    for (int i = 0; i < m; i++) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            if (merge(a, b)) {
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
            Q.push_back({{t, 1}, {a, b}});
        } else {
            if (find(a) != find(b)) Q.push_back({{t, 0}, {a, b}});
            else Q.push_back({{t, 1}, {a, b}});
        }
    }

    vi vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[find(i)]) continue;
        vis[find(i)] = 1;

        dfs(i, i);
        seg_idx[i] = idx;
        dfs2(i, i);
    }

    for (const auto &[A, B] : Q) {
        if (A.first == 1) solve(B.first, B.second, 1);
        else if (!A.second) cout << "-1\n";
        else cout << solve(B.first, B.second, 0) << "\n";
    }
}
