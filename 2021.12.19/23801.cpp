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

	int s, e, k;
	cin >> s >> e >> k;
	
	mpii mid;
	while (k--) {
		int a; cin >> a;
		mid[a] = 1;
	}

	vector<vl> dist(n + 1, vl(2, 1e18));
	priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<>> pq;
	pq.emplace(dist[s][0] = 0, pii(s, 0));
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		if (dist[top.second.first][top.second.second] < top.first) continue;
		for (const auto &[v, w] : graph[top.second.first]) {
			ll nxt = top.first + w;
			int f = min(1, top.second.second + int(mid.count(v)));
			if (dist[v][f] > nxt) pq.emplace(dist[v][f] = nxt, pii(v, f));
		}
	}

	cout << (dist[e][1] == 1e18 ? -1 : dist[e][1]);
}
