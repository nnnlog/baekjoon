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

    int n, m;
    cin >> n >> m;
    vector<vi> graph(n + 1);
    vi cnt(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        cnt[u]++;
    }
    int ans = 0;
    queue<int> Q;
    for (int i = 1; i <= n; i++) if (!cnt[i]) Q.push(i), ans++;
    while (!Q.empty()) {
        int f = Q.front();
        Q.pop();

        for (int v : graph[f])
            if (!--cnt[v]) Q.push(v), ans++;
    }
    cout << ans;
}
