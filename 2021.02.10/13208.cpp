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

int n, UF[250001];

void init() {
	for (int i = 1; i <= n * n; i++) UF[i] = i;
}

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) UF[a] = b;
}

inline int get_id(int a, int b) {
	return n * (a - 1) + b;
}

vi graph[501];
vi C(501), cost;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> C[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cost.emplace_back(C[i] * C[j]);
	sort(all(cost));
	cost.erase(unique(all(cost)), cost.end());
	vector<vpii> edge(cost.size());

	while (m--) {
		int a, b; cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);

		for (int i = 1; i <= n; i++)
			edge[lower_bound(all(cost), max(C[a] * C[i], C[b] * C[i])) - cost.begin()].emplace_back(get_id(a, i),
			                                                                                        get_id(b, i)),
					edge[lower_bound(all(cost), max(C[i] * C[a], C[i] * C[b])) - cost.begin()].emplace_back(get_id(i, a),
					                                                                                        get_id(i, b));
	}

	int q; cin >> q;
	vpii sect, query(q);
	for (auto &[a, b] : query) cin >> a >> b, sect.emplace_back(0, cost.size() - 1);
	vector<vi> mid(cost.size());
	while (1) {
		for (auto &v : mid) v.clear();
		int f = 0;
		for (int i = 0; i < q; i++)
			if (sect[i].first != sect[i].second) f = 1, mid[(sect[i].first + sect[i].second) >> 1].emplace_back(i);

		if (!f) break;
		init();
		for (int i = 0; i < cost.size(); i++) {
			for (const auto &[a, b] : edge[i]) merge(a, b);
			for (const auto &k : mid[i])
				if (find(get_id(query[k].first, query[k].second)) == find(get_id(query[k].second, query[k].first)))
					sect[k].second = i;
				else sect[k].first = i + 1;
		}
	}

	for (const auto &[l, r] : sect) cout << cost[(l + r) >> 1] << "\n";
}
