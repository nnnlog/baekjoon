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

	int n, m, k; cin >> n >> m >> k;
	vector<vpll> graph(m + 1);
	vector<vl> dist(n + 1, vl(k + 1, 1e18));
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<>> pq;
	for (auto &i : dist[0]) i = 0;
	pq.push({0, {1, 0}});
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		ll cost = top.first, u = top.second.first, x = top.second.second;
		if (cost > dist[u][x]) continue;
		for (const auto &[nxt, w] : graph[u]) {
			ll z = cost + w;
			if (dist[nxt][x] > z) {
				dist[nxt][x] = z;
				pq.push({z, {nxt, x}});
			}
			if (x < k && dist[nxt][x + 1] > cost) {
				dist[nxt][x + 1] = cost;
				pq.push({cost, {nxt, x + 1}});
			}
		}
	}

	cout << *min_element(all(dist.back()));
}
