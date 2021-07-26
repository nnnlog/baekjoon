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

int n, m, x;
vpii go[1001];
vpii inv[1001];

vi solve(vpii graph[]) {
	priority_queue<pii, vpii, greater<>> pq;
	vi dist(n + 1, 1e9);
	dist[x] = 0;
	pq.push({0, x});
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		int cost = top.first, curr = top.second;
		if (cost > dist[curr]) continue;
		for (const auto &[nxt, w] : graph[curr]) {
			int nxt_cost = cost + w;
			if (dist[nxt] > nxt_cost) {
				dist[nxt] = nxt_cost;
				pq.push({nxt_cost, nxt});
			}
		}
	}

	vi ret(n + 1);
	for (int i = 1; i <= n; i++) ret[i] = dist[i];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> x;

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		go[a].emplace_back(b, c);
		inv[b].emplace_back(a, c);
	}

	int ans = 0;
	auto one = solve(go), sec = solve(inv);
	for (int i = 1; i <= n; i++) ans = max(ans, one[i] + sec[i]);
	cout << ans;
}
