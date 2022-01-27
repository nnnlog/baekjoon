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

vi UF;
int find(int a) {
    return UF[a] = UF[a] == a ? a : find(UF[a]);
}
int merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) return UF[a] = b, 1;
    return 0;
}

int n, idx1, idx2;
vi vec, par, sz, depth, chain;
vector<vi> graph;

vi bridge_idx, seg_bridge, pen_idx, seg_pen;

int upd(vi &seg, int node, int start, int end, int k, int v) {
    if (!(start <= k && k <= end)) return seg[node];
    if (start == end) return seg[node] = v;
    int mid = (start + end) >> 1;
    return seg[node] = upd(seg, node * 2, start, mid, k, v) + upd(seg, node * 2 + 1, mid + 1, end, k, v);
}

int qry(vi &seg, int node, int start, int end, int l, int r) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return seg[node];
    int mid = (start + end) >> 1;
    return qry(seg, node * 2, start, mid, l, r) + qry(seg, node * 2 + 1, mid + 1, end, l, r);
}

void dfs(int u, int prv) {
    sz[u] = 1;
    pii mx = {0, 0};
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v == prv) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        mx = max(mx, {sz[v], i});
    }
    if (mx.second) swap(graph[u][0], graph[u][mx.second]);
}

void dfs2(int u, int prv) {
    pen_idx[u] = ++idx1;
    upd(seg_pen, 1, 1, n, idx1, vec[u]);

    for (int v : graph[u]) {
        if (v == prv) continue;
        bridge_idx[v] = ++idx2;
        chain[v] = graph[u][0] == v ? chain[u] : v;

        dfs2(v, u);
    }
}

int solve(int u, int v) {
    int ret = 0;
    while (chain[u] != chain[v]) {
        if (depth[chain[u]] < depth[chain[v]]) swap(u, v);
        int top = chain[u];
        if (qry(seg_bridge, 1, 1, n, bridge_idx[top], bridge_idx[u]) != depth[u] - depth[top] + 1) return -1;
        ret += qry(seg_pen, 1, 1, n, pen_idx[top], pen_idx[u]);
        u = par[top];
    }
    if (depth[u] > depth[v]) swap(u, v);
    if (u != v) {
        if (qry(seg_bridge, 1, 1, n, bridge_idx[u] + 1, bridge_idx[v]) != depth[v] - depth[u]) return -1;
    }
    ret += qry(seg_pen, 1, 1, n, pen_idx[u], pen_idx[v]);
    return ret;
}

vector<pair<pii, pii>> Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    UF.resize(n + 1), vec.resize(n + 1), graph.resize(n + 1);
    for (int &i : vec | views::drop(1)) cin >> i;

    iota(all(UF), 0);

    int q; cin >> q;
    Q.reserve(n + 1);
    while (q--) {
        string a;
        int b, c;
        cin >> a >> b >> c;
        Q.push_back({{0, 0}, {b, c}});
        if (a[0] == 'b') {
            if (merge(b, c)) {
                Q.back().first.second = 1;

                graph[b].push_back(c);
                graph[c].push_back(b);
            }
        }
        if (a[0] == 'p') {
            Q.back().first = {1, 1};
        }
        if (a[0] == 'e') {
            Q.back().first = {2, 1};
        }
    }

    par.resize(n + 1), sz.resize(n + 1), depth.resize(n + 1), chain.resize(n + 1);
    bridge_idx.resize(n + 1), seg_bridge.resize(n * 4), pen_idx.resize(n + 1), seg_pen.resize(n * 4);

    vi vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[find(i)]) continue;
        vis[find(i)] = 1;
        bridge_idx[i] = idx2;
        dfs(i, i);
        dfs2(i, i);
    }

    for (const auto &[A, B] : Q) {
        if (A.first == 0) {
            if (A.second) {
                int u = B.first, v = B.second;
                if (depth[u] < depth[v]) swap(u, v);
                upd(seg_bridge, 1, 1, n, bridge_idx[u], 1);
                cout << "yes\n";
            } else cout << "no\n";
        }
        if (A.first == 1) {
            upd(seg_pen, 1, 1, n, pen_idx[B.first], B.second);
        }
        if (A.first == 2) {
            if (find(B.first) != find(B.second)) cout << "impossible\n";
            else {
                int ans = solve(B.first, B.second);
                if (ans == -1) cout << "impossible\n";
                else cout << ans << "\n";
            }
        }
    }
}
