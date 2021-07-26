#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

ll b, e, p, n, m;
vector<vi> graph;

vl solve(int mid) {
	priority_queue<pii, vpii, greater<>> pq;
	vl dist(n + 1, 1e9);
	dist[mid] = 0;
	pq.push({0, mid});
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		if (top.first > dist[top.second]) continue;
		for (const auto &nxt : graph[top.second]) {
			int v = top.first + 1;
			if (dist[nxt] > v) {
				dist[nxt] = v;
				pq.push({v, nxt});
			}
		}
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> b >> e >> p >> n >> m;
	graph.resize(n + 1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	auto A = solve(1), B = solve(2), C = solve(n);
	ll ans = 1e18;
	for (ll i = 1; i <= n; i++) ans = min(ans, A[i] * b + B[i] * e + C[i] * p);
	cout << ans;
}
