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

	int v, e; cin >> v >> e;
	vector<vector<pair<int, pii>>> graph(v + 1);
	while (e--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		graph[a].push_back({b, {c, d}});
		graph[b].push_back({a, {c, d}});
	}
	vector<vi> dist(v + 1, vi(2 , 2 * 1e9));
	priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<>> pq;
	dist[0][1] = 0;
	pq.push({{0, 0}, 1});
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		if (top.first.first > dist[top.second][top.first.second]) continue;
		for (const auto &[nxt, info] : graph[top.second]) {
			int ok = top.first.first + info.first;
			if (dist[nxt][top.first.second] > ok) {
				dist[nxt][top.first.second] = ok;
				pq.push({{ok, top.first.second}, nxt});
			}
			ok -= info.second;
			if (!top.first.second && dist[nxt][1] > ok) dist[nxt][1] = ok, pq.push({{ok, 1}, nxt});
		}
	}
	for (int i = 2; i <= v; i++) cout << dist[i][1] << "\n";
}
