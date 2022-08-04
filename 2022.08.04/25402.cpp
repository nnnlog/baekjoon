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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<vi> graph(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vi parent(n + 1);
    function<void(int, int)> dfs = [&](int u, int prv) {
        for (int v : graph[u]) {
            if (v != prv) dfs(v, u), parent[v] = u;
        }
    };
    dfs(1, 1);

    stack<pii> rollback;
    vi UF(n + 1), sz(n + 1, 1);
    iota(all(UF), 0);

    function<int(int)> find = [&](int i) {
        return UF[i] == i ? i : find(UF[i]);
    };
    function<void(int, int)> merge = [&](int a, int b) {
        a = find(a), b = find(b);
        assert(a != b);
        if (sz[a] > sz[b]) swap(a, b);
        rollback.emplace(a, sz[a]);
        sz[b] += sz[a];
        sz[a] = 0;
        UF[a] = b;
    };

    int q; cin >> q;
    while (q--) {
        int m; cin >> m;
        map<int, int> ok;
        vi vec(m);
        for (int &i : vec) cin >> i, ok[i] = 1;
        for (int i : vec) if (ok.count(parent[i])) merge(i, parent[i]);

        map<int, int> chk;
        for (int i : vec) chk[find(i)] = sz[find(i)];

        ll ans = 0;
        for (const auto &[_, v] : chk) ans += ll(v - 1) * v / 2;

        cout << ans << "\n";

        while (!rollback.empty()) {
            auto [a, b] = rollback.top(); rollback.pop();
            int k = UF[a];
            sz[k] -= b;
            sz[a] = b;
            UF[a] = a;
        }
    }
}
