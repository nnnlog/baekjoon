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
vi vis, ans;
vector<vi> graph;

int dfs(int u, int prv, int root = 0) {
    int ret = vis[u];
    if (ret) return ret;
    vis[u] = ret = ++idx;
    int cnt = 0;
    for (int v : graph[u]) {
        //if (v == prv) continue;
        int ok = vis[v];
        if (!ok) {
            cnt++;
            ok = dfs(v, u);
            if (ok >= vis[u]) ans[u] = 1;
        }
        ret = min(ret, ok);
    }
    if (root) ans[u] = cnt >= 2;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vis.resize(n + 1), graph.resize(n + 1);
    ans.resize(n + 1);

    while (m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, i, 1);

    vi final;
    for (int i = 1; i <= n; i++) if (ans[i]) final.push_back(i);
    cout << final.size() << "\n";
    for (int i : final) cout << i << " ";
}
