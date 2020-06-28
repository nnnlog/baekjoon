#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, m;
		vector<int> dist(21, 1e9), prev(21, -1);
		vector<pair<int, int>> graph[21] = {{},};
		cin >> n >> m;
		priority_queue<pii> pq;

		while (n--) {
			int x, y, z;
			cin >> x >> y >> z;

			graph[x].emplace_back(y, z);
			graph[y].emplace_back(x, z);
		}

		pq.push({0, 0});
		for (int u = 1; u < m; u++) pq.push({-(int) 1e9, u});

		while (!pq.empty()) {
			pii a = pq.top();
			pq.pop();
			int cost = -a.first, u = a.second;

			if (cost > dist[u]) continue;
			for (const auto &next : graph[u]) {
				//cout << u << " -> " << next.first << endl;
				if (dist[next.first] > next.second + cost) {
					prev[next.first] = u;
					pq.push({-(dist[next.first] = next.second + cost), next.first});
				}
			}
		}

		stack<int> ans;
		for (int k = m - 1; k > 0;) {
			ans.push(k = prev[k]);
		}

		cout << "Case #" << i << ": ";
		if (ans.top()) {
			cout << "-1\n";
		} else {
			while (!ans.empty()) {
				cout << ans.top() << " ";
				ans.pop();
			}
			cout << m - 1 << " \n";
		}
	}
}