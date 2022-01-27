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

	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<vpii> graph(n + 1);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
	}
	vector<tuple<ll, ll, ll>> dist(n + 1, {1e18, 0, 1});
	priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;
	pq.emplace(0, 0, x);
	get<0>(dist[x]) = 0;
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		ll u = get<2>(top), tm = get<0>(top), cnt = get<1>(top);
		if (dist[u] < tuple<ll, ll, ll>{tm, cnt, get<2>(dist[u])}) continue;
		for (const auto &[v, t]: graph[u]) {
			ll nxt_t = t + tm, nxt_cnt = cnt + 1;
			if (dist[v] > tuple<ll, ll, ll>{nxt_t, nxt_cnt, get<2>(dist[v])}) {
				dist[v] = {nxt_t, nxt_cnt, get<2>(dist[u])};
				pq.emplace(nxt_t, nxt_cnt, v);
			} else if (dist[v] == tuple<ll, ll, ll>{nxt_t, nxt_cnt, get<2>(dist[v])}) {
				get<2>(dist[v]) = (get<2>(dist[v]) + get<2>(dist[u])) % int(1e9 + 9);
			}
		}
	}

	auto ans = dist[y];
	ll t = get<0>(ans), c = get<1>(ans), w = get<2>(ans);
	if (t == ll(1e18)) cout << -1;
	else cout << t << "\n" << c << "\n" << w;
}
