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

	int n, m; cin >> n >> m;
	vector<vpii> graph(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	int k, s, e;
	cin >> s >> e >> k;
	
	vi idx2num(k);
	for (int &i : idx2num) cin >> i;

	vector<vl> dist(k, vl(n + 1, 1e18));
	for (int i = 0; i < k; i++) {
		auto &dis = dist[i];
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
		pq.emplace(dis[idx2num[i]] = 0, idx2num[i]);
		while (!pq.empty()) {
			auto top = pq.top(); pq.pop();
			if (dis[top.second] < top.first) continue;
			for (const auto &[v, w] : graph[top.second]) {
				ll nxt = top.first + w;
				if (dis[v] > nxt) pq.emplace(dis[v] = nxt, v);
			}
		}
	}

	ll ans = 1e18;
	for (int x = 0; x < k; x++)
		for (int y = 0; y < k; y++)
			for (int z = 0; z < k; z++) {
				if (x == y || y == z || x == z) continue;
				ans = min(ans, dist[x][s] + dist[x][idx2num[y]] + dist[y][idx2num[z]] + dist[z][e]);
			}

	cout << (ans == 1e18 ? -1 : ans);
}
