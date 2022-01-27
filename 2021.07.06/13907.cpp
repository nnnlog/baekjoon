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

	int n, m, k; cin >> n >> m >> k;
	int s, d; cin >> s >> d;
	vector<vpii> graph(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	vector<vi> dist(n + 1, vi(n, 1e9));
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
	pq.emplace(dist[s][0] = 0, pii(s, 0));
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		int curr = top.first, u = top.second.first, mv = top.second.second;
		if (dist[u][mv] < curr) continue;
		++mv;
		if (mv >= n) continue;
		for (const auto &[v, w] : graph[u]) {
			int nxt = curr + w;
			if (dist[v][mv] > nxt) {
				dist[v][mv] = nxt;
				pq.emplace(nxt, pii(v, mv));
			}
		}
	}
	auto solve = [&](int a) {
		int ret = 1e9;
		for (int mv = 0; mv < n; mv++) ret = min(ret, mv * a + dist[d][mv]);
		return ret;
	};
	int sum = 0;
	cout << solve(sum) << "\n";
	while (k--) {
		int a; cin >> a;
		cout << solve(sum += a) << "\n";
	}
}
