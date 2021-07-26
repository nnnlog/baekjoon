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

	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<vpll> graph(n + 1), rev_graph(n + 1);
	while (m--) {
		ll a, b, w;
		cin >> a >> b >> w;
		graph[a].emplace_back(b, w);
		rev_graph[b].emplace_back(a, w);
	}

	vi is_hub;
	unordered_map<int, vl> dist, rev_dist;
	while (k--) {
		int a;
		cin >> a;
		is_hub.emplace_back(a);

		dist[a].assign(n + 1, 1e18);
		rev_dist[a].assign(n + 1, 1e18);
	}

	auto dijkstra = [&](auto &graph, auto &dist) {
		for (const auto &hub_id : is_hub) {
			priority_queue<pll, vpll, greater<>> pq;
			pq.push({0, hub_id});
			auto &curr_dist = dist[hub_id];
			curr_dist[hub_id] = 0;
			while (!pq.empty()) {
				auto top = pq.top();
				pq.pop();
				auto cost = top.first, u = top.second;
				if (cost > curr_dist[u]) continue;
				for (const auto &[v, w] : graph[u]) {
					//if (is_hub.find(u) != is_hub.end() || is_hub.find(v) != is_hub.end()) {
						ll nxt = cost + w;
						if (curr_dist[v] > nxt) {
							curr_dist[v] = nxt;
							pq.push({nxt, v});
						}
					//}
				}
			}
		}
	};
	dijkstra(graph, dist);
	dijkstra(rev_graph, rev_dist);

	ll ans = 0, cnt = 0;
	while (q--) {
		int a, b;
		cin >> a >> b;

		ll curr = 1e18;
		if (!dist[a].empty()) {
			curr = min(curr, dist[a][b]);
		}

		for (const auto &hub_id : is_hub) curr = min(curr, rev_dist[hub_id][a] + dist[hub_id][b]);

		if (curr != 1e18) ++cnt, ans += curr;
	}

	cout << cnt << "\n" << ans << "\n";
}
