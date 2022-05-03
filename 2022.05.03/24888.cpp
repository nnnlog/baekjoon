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
		int a, b, w; cin >> a >> b >> w;
		graph[a].emplace_back(b, w);
		graph[b].emplace_back(a, w);
	}

	vi ok(n + 1);
	for (int &i : ok | views::drop(1)) cin >> i;

	vector<pair<ll, pii>> dist(n + 1, pair<ll, pii>(1e18, pii(0, 0)));
	priority_queue<pair<pair<ll, pii>, int>, vector<pair<pair<ll, pii>, int>>, greater<>> pq;
	pq.push({dist[1] = {0, {-ok[1], 0}}, 1});
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		int u = top.second, curr_cnt = top.first.second.first;
		ll curr = top.first.first;

		if (dist[u] < top.first) continue;

		for (const auto &[v, w] : graph[u]) {
			auto nxt = make_pair(curr + w, pii(curr_cnt - ok[v], u));
			if (dist[v] > nxt) pq.push({dist[v] = nxt, v});
		}
	}

	if (reduce(all(ok)) != -dist[n].second.first) cout << -1;
	else {
		vi ans;
		for (int i = n; i; i = dist[i].second.second) ans.push_back(i);
		reverse(all(ans));
		cout << ans.size() << "\n";
		for (int i : ans) cout << i << " ";
	}
}
