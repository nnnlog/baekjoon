#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<pair<ll, ll>, pair<ll, ll>> ppll;

ll dist[21][500], graph[21][21][2];
vector<ll> _node[21];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int t = 0; t <= 1; t++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				char c;
				cin >> c;
				if (c != '.') {
					graph[i][j][t] = c - '0';

					if (t) continue;
					_node[i].push_back(j);
					_node[j].push_back(i);
				}
			}


	for (int i = 1; i < n; i++)
		for (int j = 0; j < 500; j++)
			dist[i][j] = 1e9;

	priority_queue<ppll> pq;
	pq.push({{0, 0},
	         {0, 0}});

	while (!pq.empty()) {
		ppll top = pq.top();
		pq.pop();

		ll cost = -top.first.first;
		ll curr = top.first.second;

		//cout << cost << " " << curr << "\n";

		ll a = top.second.first, b = top.second.second;
		if (b > dist[curr][a]) continue;
		for (const auto &i : _node[curr]) {
			ll na = graph[i][curr][0], nb = graph[i][curr][1];

			ll ta = a + na, tb = b + nb;
			if (ta < 500 && tb < dist[i][ta]) {
				dist[i][ta] = tb;
				pq.push({{-(ta * tb), i},
				         {ta,          tb}});

				//cout << curr << "->" << i << " " << na + a << " " << t << "\n";
			}
		}
	}

	ll ans = 1e9;
	for (ll i = 1; i < 500; i++) {
		ans = min(ans, dist[1][i] * i);
		//if (ans == dist[1][i] * i) cout << i << " " << ans << " " << dist[1][i] << "\n";
	}

	cout << (ans == 1e9 ? -1 : ans);
}
