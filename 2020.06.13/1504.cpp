#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e9;
ll n, e;
vector<pair<ll, ll>> graph[801];

ll getDistance(ll start, ll goal) {
	vector<ll> dist(n + 1, INF);
	priority_queue<pair<ll, ll>> pq;
	pq.push({0, start});
	dist[start] = 0;

	for (int i = 1; i <= n; i++) pq.push({-INF, i});

	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		ll cost = -p.first, u = p.second;
		if (cost > dist[u]) continue;
		for (auto v : graph[u]) {
			ll t = min(dist[v.first], cost + v.second);
			if (t < dist[v.first]) {
				dist[v.first] = t;
				pq.push({-dist[v.first], v.first});
			}
		}
	}

	return dist[goal] == INF ? -1 : dist[goal];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> e;

	while (e--) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	ll v1, v2;
	cin >> v1 >> v2;

	int a = getDistance(1, v1), b = getDistance(v1, v2), c = getDistance(v2, n), d = getDistance(1, v2), f = getDistance(v1, n);
	if (b == -1) cout << -1;
	else if ((a == -1 || c == -1) && (d == -1 || f == -1)) cout << -1;
	else cout << min(a + b + c, b + d + f);
}
