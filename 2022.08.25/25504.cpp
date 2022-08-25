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

#define map unordered_map

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vpii> graph(n + 1);
    vector<map<int, int>> graph_map(n + 1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);

        graph_map[a][b] = c;
        graph_map[b][a] = c;
    }

    int k = 40;
    vector<vector<map<int, int>>> dp(n + 1, vector<map<int, int>>(3));
    for (int s = 1; s <= n; s++) {
        if (graph[s].size() <= k) continue;
        dp[s][0][s] = 0;
        for (int i = 0; i <= 1; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[s][i].count(j)) {
                    for (const auto &[v, w] : graph[j]) {
                        if (!dp[s][i + 1].count(v)) dp[s][i + 1][v] = dp[s][i][j] + w;
                        else dp[s][i + 1][v] = min(dp[s][i + 1][v], dp[s][i][j] + w);
                    }
                }
            }
        }
    }

    map<int, map<int, int>> cache;
    while (q--) {
        int a, b;
        cin >> a >> b;

        // 항상 b가 많도록
        if (graph[a].size() > graph[b].size()) swap(a, b);

        if (cache[a].count(b)) {
            cout << cache[a][b] << "\n";
            continue;
        }

        int ans = 1e9;

        // 간선 1개
        if (graph_map[a].count(b)) ans = min(ans, graph_map[a][b]);

        // 간선 3개
        if (graph[b].size() > k) {
            if (dp[b][2].count(a)) ans = min(ans, dp[b][2][a]);
            for (const auto &[v, w] : graph[a]) {
                if (dp[b][2].count(v)) ans = min(ans, dp[b][2][v] + w);
//                if (dp[b][1].count(v)) ans = min(ans, dp[b][1][v] + w);
            }
        } else {
            for (const auto &[v1, w1] : graph[a]) {
                if (graph_map[v1].count(b)) ans = min(ans, w1 + graph_map[v1][b]);
                for (const auto &[v2, w2] : graph[b]) {
                    if (graph_map[v1].count(v2)) ans = min(ans, graph_map[v1][v2] + w1 + w2);
                }
            }
        }

        if (ans == 1e9) ans = -1;
        cout << (cache[a][b] = ans) << "\n";
    }
}
