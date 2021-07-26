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

int n, v, e;
vector<vpii> graph;

vi dijkstra(int s) {
	vi dist(v + 1, 1e9);
	priority_queue<pii, vpii, greater<>> pq;
	pq.emplace(dist[s] = 0, s);
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		if (dist[top.second] < top.first) continue;
		for (const auto &[v, w] : graph[top.second]) {
			int nxt = top.first + w;
			if (dist[v] > nxt) pq.emplace(dist[v] = nxt, v);
		}
	}
	for (int &i : dist) if (i == 1e9) i = -1;
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	 cin >> n >> v >> e;
	int A, B; cin >> A >> B;
	vi vec(n);
	for (auto &i : vec) cin >> i;
	graph.resize(v + 1);
	while (e--) {
		int a, b, w; cin >> a >> b >> w;
		graph[a].emplace_back(b, w);
		graph[b].emplace_back(a, w);
	}
	auto x = dijkstra(A), y = dijkstra(B);
	int ans = 0;
	for (const auto &i : vec) ans += x[i] + y[i];
	cout << ans;
}
