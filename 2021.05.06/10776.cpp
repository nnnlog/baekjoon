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

	int k, n, m; cin >> k >> n >> m;
	vector<vector<tuple<int, int, int>>> graph(n + 1);
	while (m--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		graph[a].emplace_back(b, c, d);
		graph[b].emplace_back(a, c, d);
	}
	int a, b; cin >> a >> b;
	vector<vi> dist(n + 1, vi(k, 1e9));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
	dist[a][0] = 0;
	pq.push({a, 0, 0});
	while (!pq.empty()) {
		int u, h, t;
		tie(u, h, t) = pq.top(); pq.pop();
		if (dist[u][h] < t) continue;
		for (const auto &[v, T, H] : graph[u]) {
			int nxt_t = t + T, nxt_h = h + H;
			if (nxt_h < k && dist[v][nxt_h] > nxt_t) {
				dist[v][nxt_h] = nxt_t;
				pq.push({v, nxt_h, nxt_t});
			}
		}
	}

	int ans = 1e9;
	for (const auto &i : dist[b]) ans = min(ans, i);
	cout << (ans == 1e9 ? -1 : ans);
}
