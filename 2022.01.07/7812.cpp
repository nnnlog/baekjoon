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

vector<vpii> graph;
vi sz;
ll n, sum, ans;

void dfs1(int u, int prv = 0) {
    sz[u] = 1;
    for (const auto &[v, w] : graph[u]) {
        if (v == prv) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        sum += w * sz[v];
    }
}

void dfs2(int u, int prv = 0) {
    ans = min(ans, sum);
    for (const auto &[v, w] : graph[u]) {
        if (v == prv) continue;
        sum += w * (n - 2 * sz[v]);
        dfs2(v, u);
        sum -= w * (n - 2 * sz[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1) {
        cin >> n;
        if (!n) return 0;
        graph.assign(n, {}), sz.resize(n, 0);
        sum = 0;
        ans = 1e18;
        for (int i = 1; i < n; i++) {
            int u, v, w; cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        dfs1(0);
        dfs2(0);
        cout << ans << "\n";
    }
}
