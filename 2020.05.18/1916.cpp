#include <bits/stdc++.h>

using namespace std;

const long long INF = 100000LL * 10000000;

vector<long long> dist;
vector<pair<long long, long long>> graph[1001];
priority_queue<pair<long long, long long>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long n, m;
	cin >> n >> m;

	dist.assign(n + 1, INF);

	for (int i = 0; i < m; i++) {
		long long u, v, w; cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
	}

	int start, end; cin >> start >> end;

	dist[start] = 0;
	pq.push({0, start});

	for (int i = 1; i <= n; i++) {
		pq.push({INF, i});
	}

	while (!pq.empty()) {
		long long cost = -pq.top().first, i = pq.top().second;
		pq.pop();
		if (dist[i] < cost) continue;
		for (auto p : graph[i]) {
			long long t = min(dist[p.first], dist[i] + p.second);
			if (t < dist[p.first]) {
				dist[p.first] = t;
				pq.push({-t, p.first});
			}
		}
	}

	cout << dist[end];
}
 
