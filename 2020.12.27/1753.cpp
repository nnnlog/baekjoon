#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e9;
ll n, e;
vector<pair<ll, ll>> graph[20001];
vector<ll> dist;
priority_queue<pair<ll, ll>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> e;
	dist.assign(n + 1, INF);

	ll start;
	cin >> start;

	while (e--) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
	}

	pq.push({0, start});
	dist[start] = 0;

	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		ll cost = -p.first, u = p.second;
		if (cost > dist[u]) continue;
		for (auto v : graph[u]) {
			ll t = cost + v.second;
			if (t < dist[v.first]) {
				dist[v.first] = t;
				pq.push({-dist[v.first], v.first});
			}
		}
	}

	for (int i = 1; i <= n; i++) if (dist[i] < 1e9) cout << dist[i] << "\n"; else cout << "INF\n";
}
