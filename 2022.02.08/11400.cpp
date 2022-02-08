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
vpii ans;
vector<vi> graph;
vi order;

int dfs(int u, int prv) {
    if (order[u]) return order[u];
    int ret = order[u] = ++idx;
    for (const auto &v : graph[u]) {
        if (v == prv) continue;
        if (order[v]) {
            ret = min(ret, order[v]);
        } else {
            int tmp = dfs(v, u);
            if (order[u] < tmp) ans.emplace_back(u, v);
            ret = min(ret, tmp);
            //cout << u << " " << v << " " << tmp << "\n";
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    graph.resize(n + 1), order.resize(n + 1);
    while (m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 1);
    for (auto &[a, b] : ans) if (a > b) swap(a, b);
    sort(all(ans));
    cout << ans.size() << "\n";
    for (const auto &[a, b] : ans) cout << a << " " << b << "\n";
}
