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


vector<vpii> graph;

void dijkstra(auto &dist, int s) {
	priority_queue<pii, vpii, greater<>> pq;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		if (dist[top.second] < top.first) continue;
		for (const auto &[u, w] : graph[top.second]) {
			int nxt = w + top.first;
			if (nxt < dist[u]) {
				dist[u] = nxt;
				pq.push({nxt, u});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, sum = 0; cin >> n >> m;
	graph.resize(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
		sum += c;
	}
	int s, e; cin >> s >> e;
	vi A(n + 1, 1e9), B(n + 1, 1e9);
	dijkstra(A, s);
	dijkstra(B, e);

	int ans = 1e9;
	for (int i = 1; i <= n; i++) for (const auto &[b, c] : graph[i]) ans = min(ans, A[i] + B[b]);
	cout << sum - ans;
}
