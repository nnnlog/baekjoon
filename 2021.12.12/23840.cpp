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

int k, s, e;
vi idx2num;
vector<vl> dist;

ll dp[1 << 21][20];
ll solve(int f, int u) {
	ll &ret = dp[f][u];
	if (ret != -1) return ret;
	if (f + 1 == (1 << k)) return ret = dist[u][e];
	ret = 1e18;
	for (int i = 0; i < k; i++) {
		if (f & (1 << i)) continue;
		ret = min(ret, solve(f | (1 << i), i) + dist[u][idx2num[i]]);
	}
	return ret;
}

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

	cin >> s >> e >> k;
	idx2num.resize(k);
	for (int &i : idx2num) cin >> i;

	dist.assign(k, vl(n + 1, 1e18));
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

	for (auto &v : dp)
		for (auto &a : v) a = -1;

	ll ans = 1e18;
	for (int i = 0; i < k; i++) ans = min(ans, solve(1 << i, i) + dist[i][s]);
	cout << (ans == 1e18 ? -1 : ans);
}
