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

vi val;
vector<vi> graph;
vector<vpii> sz;

int init(int u, int prv) {
    int ret = 0;
    for (int v : graph[u]) {
        if (prv == v) continue;
        int t = init(v, u);
        ret = max(ret, t);
        sz[u].emplace_back(t, v);
    }
    return ret + val[u];
}

pii ans = {-1, 0};
void dfs(int u, int prv, int prv_sz) {
    sz[u].emplace_back(prv_sz, prv);
    sort(all(sz[u]), greater<>());
    ans = max(ans, {sz[u][0].first + val[u], -u});
    for (int v : graph[u]) {
        if (v == prv) continue;
        if (sz[u][0].second == v) dfs(v, u, sz[u][1].first + val[u]);
        else dfs(v, u, sz[u][0].first + val[u]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    val.resize(n + 1), graph.resize(n + 1), sz.resize(n + 1);
    for (int &i : val | views::drop(1)) cin >> i;
    while (--n) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    init(1, 1);
    dfs(1, 1, 0);
    cout << ans.first << " " << -ans.second;
}
