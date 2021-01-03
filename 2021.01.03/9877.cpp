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

const int UF_MX = 251000;

int mp[500][500], UF[UF_MX], unc[UF_MX];
unordered_map<int, vpii> edge_mp;
vector<pair<int, vpii>> edge;
vpii mv = {
		{-1, 0},
		{0,  -1}
};

int get_id(int x, int y) {
	return x * 501 + y;
}

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		UF[a] = b;
		unc[b] += unc[a];
		unc[a] = 0;
	}
}

vpii section;
vi query;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n, t;
	cin >> m >> n >> t;
	vi ndx;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];

			for (const auto &[dx, dy] : mv) {
				int x = i + dx, y = j + dy;
				if (x < 0 || y < 0) continue;
				edge_mp[abs(mp[x][y] - mp[i][j])].emplace_back(get_id(i, j), get_id(x, y));
				ndx.push_back(abs(mp[x][y] - mp[i][j]));
			}
		}

	sort(all(ndx));
	ndx.erase(unique(all(ndx)), ndx.end());
	for (const auto &[diff, info] : edge_mp) {
		edge.emplace_back(lower_bound(all(ndx), diff) - ndx.begin(), info);
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a) {
				query.push_back(get_id(i, j));
				section.emplace_back(0, ndx.size());
			}
		}

	sort(all(edge));

	while (1) {
		int f = 0;
		vector<vi> mid(ndx.size() + 1);
		for (int i = 0; i < query.size(); i++) {
			if (section[i].first >= section[i].second) continue;
			mid[(section[i].first + section[i].second) >> 1].emplace_back(i);
			f = 1;
		}
		if (!f) break;

		for (int i = 0; i < UF_MX; i++) UF[i] = i, unc[i] = 1;

		for (int i = 0; i < edge.size(); i++) {
			auto info = edge[i].second;
			for (const auto &[a, b] : info)
				merge(a, b);

			for (const auto &q_id : mid[i]) {
				int sz = unc[find(query[q_id])];
				if (sz >= t) section[q_id].second = i;
				else section[q_id].first = i + 1;
			}
		}
	}
	ll sum = 0;
	for (const auto &[l, r] : section) sum += ndx[((l + r) >> 1)];
	cout << sum;
}
