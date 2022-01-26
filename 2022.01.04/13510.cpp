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

vi depth, par, sz, chain_top, seg_idx;
int n, idx;
vi seg;
vector<vpii> graph;

int upd(int node, int start, int end, int k, int v) {
    if (!(start <= k && k <= end)) return seg[node];
    if (start == end) return seg[node] = v;
    int mid = (start + end) >> 1;
    return seg[node] = max(upd(node * 2, start, mid, k, v), upd(node * 2 + 1, mid + 1, end, k, v));
}

int qry(int node, int start, int end, int l, int r) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return seg[node];
    int mid = (start + end) >> 1;
    return max(qry(node * 2, start, mid, l, r), qry(node * 2 + 1, mid + 1, end, l, r));
}

void dfs(int u, int prv) {
    sz[u] = 1;
    pii mx = {0, 0};
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        if (prv == v) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        par[v] = u;
        sz[u] += sz[v];

        mx = max(mx, {sz[v], i});
    }

    if (mx.second) swap(graph[u][0], graph[u][mx.second]);
}

void dfs2(int u, int prv) {
    for (const auto &[v, w] : graph[u]) {
        if (v == prv) continue;
        seg_idx[v] = ++idx;
        upd(1, 1, n, idx, w);
        chain_top[v] = graph[u][0].first == v ? chain_top[u] : v;
        dfs2(v, u);
    }
}

int solve(int u, int v) {
    int ret = 0;
    while (chain_top[u] != chain_top[v]) {
        if (depth[chain_top[u]] < depth[chain_top[v]]) swap(u, v);
        int top = chain_top[u];
        ret = max(ret, qry(1, 1, n, seg_idx[top], seg_idx[u]));
        u = par[top];
    }
    if (depth[u] > depth[v]) swap(u, v);
    if (u != v) ret = max(ret, qry(1, 1, n, seg_idx[u] + 1, seg_idx[v]));
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    depth.resize(n + 1), sz.resize(n + 1), par.resize(n + 1), chain_top.resize(n + 1);
    graph.resize(n + 1), seg_idx.resize(n + 1);
    seg.resize(n * 4);

    vpii edge;

    for (int i = 1; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);

        edge.emplace_back(a, b);
    }

    dfs(1, 1);

    dfs2(1, 1);

    int m; cin >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            --b;
            if (depth[edge[b].first] < depth[edge[b].second]) swap(edge[b].first, edge[b].second);
            upd(1, 1, n, seg_idx[edge[b].first], c);
        } else {
            cout << solve(b, c) << "\n";
        }
    }
}
