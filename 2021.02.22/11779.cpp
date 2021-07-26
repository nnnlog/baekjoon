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
	vector<vpll> graph(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		//graph[b].emplace_back(a, c);
	}

	int s, e; cin >> s >> e;

	vl dist(n + 1, 1e18), ans(n + 1, 0);
	priority_queue<pll, vpll, greater<>> pq;
	pq.push({0, s});
	dist[s] = 0;
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		ll cost = top.first, curr = top.second;
		if (cost > dist[curr]) continue;
		for (const auto &[nxt, w] : graph[curr]) {
			ll v = cost + w;
			if (dist[nxt] > v) {
				dist[nxt] = v;
				pq.push({v, nxt});
				ans[nxt] = curr;
			}
		}
	}

	vi res;
	for (int curr = e; ; curr = ans[curr]) {
		assert(curr);
		res.emplace_back(curr);
		if (curr == s) break;
	}

	cout << dist[e] << "\n" << res.size() << "\n";
	reverse(all(res));
	for (const auto &i : res) cout << i << " ";
}
