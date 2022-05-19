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

    int n, m; cin >> n >> m;
    vector<vi> graph(n + 1);
    while (m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    mpii mp;
    int s; cin >> s;
    while (s--) {
        int a; cin >> a;
        mp[a] = 1;
    }

    function<int(int)> dfs = [&](int u) {
        if (graph[u].empty()) return 1;
        int ret = 0;
        for (int v : graph[u]) ret |= dfs(v) && !mp.count(v);
        return ret;
    };
    cout << (dfs(1) && !mp.count(1) ? "yes" : "Yes");
}
