#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int UF[100001];
int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) UF[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k, q; cin >> n >> m >> k >> q;

	vector<vpii> graph(n + 1);
	vi dist(n + 1, 1e9), vec;

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	priority_queue<pii> pq;

	while (k--) {
		int a; cin >> a;
		vec.push_back(a);
		graph[0].emplace_back(a, 0);
	}

	dist[0] = 0;
	pq.push({0, 0});

	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		int cost = -top.first, curr = top.second;
		if (dist[curr] < cost) continue;
		for (const auto &[nxt, w] : graph[curr]) {
			int v = w + cost;
			if (dist[nxt] > v) {
				dist[nxt] = v;
				pq.push({-v, nxt});
			}
		}
	}

	vpii mp;
	vi comp;
	for (int i = 1; i <= n; i++) {
		mp.emplace_back(dist[i], i);
		comp.push_back(dist[i]);
	}

	sort(all(comp), greater<>());
	comp.erase(unique(all(comp)), comp.end());

	vector<vi> nations(comp.size()), mid(comp.size());
	for (const auto &[d, i] : mp) {
		nations[lower_bound(all(comp), d, greater<>()) - comp.begin()].push_back(i);
	}

	for (auto &i : dist) i = lower_bound(all(comp), i, greater<>()) - comp.begin();

	vpii query, range;

	while (q--) {
		int a, b; cin >> a >> b;
		query.emplace_back(a, b);
		range.emplace_back(0, comp.size());
	}

	while (1) {
		int f = 0;
		for (auto &v : mid) v.clear();
		for (int i = 0; i < query.size(); i++) {
			if (range[i].first >= range[i].second) continue;
			f = 1;
			mid[(range[i].first + range[i].second) >> 1].push_back(i);
		}
		if (!f) break;
		for (int i = 1; i <= n; i++) UF[i] = i;

		for (int i = 0; i < nations.size(); i++) {
			for (const auto &u : nations[i]) {
				for (const auto &[v, w] : graph[u]) {
					if (dist[v] <= i) merge(u, v);
				}
			}

			for (const auto &j : mid[i]) {
				if (find(query[j].first) == find(query[j].second)) {
					range[j].second = i;
					//cout << i << " " << j << "solve\n";
				} else {
					range[j].first = i + 1;
				}
			}
		}
	}

	for (const auto &[l, r] : range) /*cout << l << " " << r << "\n",*/ cout << comp[(l + r) >> 1] << "\n";
}
